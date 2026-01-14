#include "ncbind.hpp"
#include "XP3Archive.h"
#include "SystemIntf.h"
#include "tjsNative.h"
#include <assert.h>
#include <list>
#include "tjsDebug.h"
#include "SysInitIntf.h"
#include "TextStream.h"
#include "ThreadIntf.h"
#include <memory>
#include "cxdec.h"

#define NCB_MODULE_NAME TJS_W("cxdecoder.dll")

class CxdecCipher
{
public:
	CxdecCipher(cxdec_information in_information)
	{
		memcpy(&information, &in_information, sizeof(in_information));
		memset(&state, 0, sizeof(state));
		cxdec_init(&state, &information);
	}

	virtual ~CxdecCipher()
	{
		cxdec_release(&state);
	}

	virtual void TJS_INTF_METHOD Filter(tTVPXP3ExtractionFilterInfo *info)
	{
		cxdec_decode(&state, &information, info->FileHash, (uint32_t)(info->Offset), (uint8_t *)(info->Buffer), (uint32_t)(info->BufferSize));
	}

private:
	cxdec_information information;
	cxdec_state state;
};

struct CxdecDecoder {
	tTJS * ScriptEngine = new tTJS();
    CxdecCipher * Cipher;
	CxdecDecoder() : Cipher(nullptr) { }
	~CxdecDecoder() {
		if (ScriptEngine) ScriptEngine->Release();
	}
};

static CxdecDecoder *decoder = new CxdecDecoder();
static bool decoderInited = false;
static ttstr cxdecInfoScript;

static void InitDecoder() {
    cxdec_information information;
    iTJSDispatch2 *global = decoder->ScriptEngine->GetGlobalNoAddRef();
	decoder->ScriptEngine->ExecScript(cxdecInfoScript);
    tTJSVariant tmp_var;
    global->PropGet(TJS_MEMBERMUSTEXIST, TJS_W("xcode_building_first_stage_order"), NULL, &tmp_var, global);
    ncbPropAccessor tmp_accessor(tmp_var);
    for (tjs_uint i = 0; i < 3; i += 1)
        information.xcode_building_first_stage_order[i] = (tjs_uint8)tmp_accessor.getIntValue(i);
    global->PropGet(TJS_MEMBERMUSTEXIST, TJS_W("xcode_building_stage_0_order"), NULL, &tmp_var, global);
    tmp_accessor = ncbPropAccessor(tmp_var);
    for (tjs_uint i = 0; i < 8; i += 1)
        information.xcode_building_stage_0_order[i] = (tjs_uint8)tmp_accessor.getIntValue(i);
    global->PropGet(TJS_MEMBERMUSTEXIST, TJS_W("xcode_building_stage_1_order"), NULL, &tmp_var, global);
    tmp_accessor = ncbPropAccessor(tmp_var);
    for (tjs_uint i = 0; i < 6; i += 1)
        information.xcode_building_stage_1_order[i] = (tjs_uint8)tmp_accessor.getIntValue(i);
    global->PropGet(TJS_MEMBERMUSTEXIST, TJS_W("boundary_mask"), NULL, &tmp_var, global);
    information.boundary_mask = tmp_var.AsInteger();
    global->PropGet(TJS_MEMBERMUSTEXIST, TJS_W("boundary_offset"), NULL, &tmp_var, global);
    information.boundary_offset = tmp_var.AsInteger();
    global->PropGet(TJS_MEMBERMUSTEXIST, TJS_W("encryption_control_block"), NULL, &tmp_var, global);
    const tTJSVariantOctet *oct = tmp_var.AsOctetNoAddRef();
    assert((tjs_uint)(oct->GetLength()) == sizeof(information.encryption_control_block));
    memcpy(information.encryption_control_block, oct->GetData(), sizeof(information.encryption_control_block));
    decoder->Cipher = new CxdecCipher(information);
    decoderInited = true;
}

void TVP_tTVPXP3ArchiveExtractionFilter_CONVENTION
    TVPXP3ArchiveExtractionFilterWrapper(tTVPXP3ExtractionFilterInfo *info)
{
    if (info->SizeOfSelf != sizeof(tTVPXP3ExtractionFilterInfo))
        TVPThrowExceptionMessage(TJS_W("Incompatible tTVPXP3ExtractionFilterInfo size"));
    assert(decoderInited);
    assert(decoder->Cipher);
    decoder->Cipher->Filter(info);
}

static void PostRegistCallback()
{
    ttstr path = TVPGetAppPath() + TJS_W("cxdecinfo.tjs");
    if (TVPIsExistentStorageNoSearch(path)) {
        iTJSTextReadStream * stream = TVPCreateTextStreamForRead(path, "");
        try
        {
            stream->Read(cxdecInfoScript, 0);
        }
        catch(...)
        {
            stream->Destruct();
            throw;
        }
        stream->Destruct();
        InitDecoder();
		TVPSetXP3ArchiveExtractionFilter(TVPXP3ArchiveExtractionFilterWrapper);
    }
}

NCB_POST_REGIST_CALLBACK(PostRegistCallback);
