#include "ncbind.hpp"

#define NCB_MODULE_NAME TJS_W("addFont.dll")

#include "LayerBitmapIntf.h"
#include "FontSystem.h"

extern FontSystem* TVPFontSystem;

#include <vector>

struct FontEx
{
	/**
	 * プライベートフォントの追加
	 * @param fontFileName フォントファイル名
	 * @param extract アーカイブからテンポラリ展開する
	 * @return void:ファイルを開くのに失敗 0:フォント登録に失敗 数値:登録したフォントの数
	 */
	static tjs_error TJS_INTF_METHOD addFont(tTJSVariant *result,
											 tjs_int numparams,
											 tTJSVariant **param,
											 iTJSDispatch2 *objthis) {
		if (numparams < 1) return TJS_E_BADPARAMCOUNT;

		ttstr filename = TVPGetPlacedPath(*param[0]);
		TVPAddLog(ttstr("FontEx.addFont: ") + filename);
		if (filename.length()) {
			// 実ファイルが存在した場合
			int ret;
			TVPFontSystem->AddExtraFont( filename.AsStdString(), nullptr );
			if (result) {
				*result = 1;
			}
		}
		return TJS_S_OK;
	}
};

// フックつきアタッチ
NCB_ATTACH_CLASS(FontEx, System) {
	RawCallback("addFont", &FontEx::addFont, TJS_STATICMEMBER);
}
