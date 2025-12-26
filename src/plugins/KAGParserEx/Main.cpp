#include "KAGParserEx.hpp"

#include "ncbind.hpp"

#define NCB_MODULE_NAME TJS_W("KAGParserEx.dll")
// #define NCB_MODULE_NAME TJS_W("KAGParser.dll")

static iTJSDispatch2 *origKAGParser = NULL;

void kagparserex_init()
{
	tTJSNI_KAGParser::initMethod();
	
	iTJSDispatch2 * global = TVPGetScriptDispatch();
	if (global) {
		tTJSVariant val;
		if (TJS_SUCCEEDED(global->PropGet(0, TVP_KAGPARSER_EX_CLASSNAME, NULL, &val, global))) {
			origKAGParser = val.AsObject();
			val.Clear();
		}
		iTJSDispatch2 * tjsclass = tTJSNC_KAGParser::CreateNativeClass();
		val = tTJSVariant(tjsclass);
		tjsclass->Release();
		global->PropSet(TJS_MEMBERENSURE, TVP_KAGPARSER_EX_CLASSNAME, NULL, &val, global);
		global->Release();
	}
}

void kagparserex_uninit()
{
	iTJSDispatch2 * global = TVPGetScriptDispatch();
	if (global)	{
		global->DeleteMember(0, TVP_KAGPARSER_EX_CLASSNAME, NULL, global);
		if (origKAGParser) {
			tTJSVariant val(origKAGParser);
			origKAGParser->Release();
			origKAGParser = NULL;
			global->PropSet(TJS_MEMBERENSURE, TVP_KAGPARSER_EX_CLASSNAME, NULL, &val, global);
		}
		global->Release();
	}

	tTJSNI_KAGParser::doneMethod();
}

NCB_PRE_REGIST_CALLBACK(kagparserex_init);
NCB_PRE_UNREGIST_CALLBACK(kagparserex_uninit);
