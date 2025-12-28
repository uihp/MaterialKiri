#include "ncbind.hpp"

// CreateDialogIndirect のテーブル書き出し用クラス
#include "dialog.hpp"

#include "simplethread.hpp"

// MessageBoxでダイアログをオーナーセンター表示にする独自フラグ
#define MB_OWNER_CENTER 0x40000000L

#define NCB_MODULE_NAME TJS_W("win32dialog.dll")

#include "PluginImpl.h"

static bool TJS_USERENTRY _CatchFuncCall(void *data, const tTVPExceptionDesc & desc)
{
	throw desc;
}
struct t_iTJSDispatch2_FuncCall
{
	tjs_error _ret;
	iTJSDispatch2 * _this;
	tjs_uint32 flag;
	const tjs_char * membername;
	tjs_uint32 *hint;
	tTJSVariant *result;
	tjs_int numparams;
	tTJSVariant **param;
	iTJSDispatch2 *objthis;
	t_iTJSDispatch2_FuncCall(
			iTJSDispatch2 * _this_,
			tjs_uint32 flag_,
			const tjs_char * membername_,
			tjs_uint32 *hint_,
			tTJSVariant *result_,
			tjs_int numparams_,
			tTJSVariant **param_,
			iTJSDispatch2 *objthis_
			) :
		_this(_this_),
		flag(flag_),
		membername(membername_),
		hint(hint_),
		result(result_),
		numparams(numparams_),
		param(param_),
		objthis(objthis_)	{;}

};
static void TJS_USERENTRY _Try_iTJSDispatch2_FuncCall(void *data)
{
	t_iTJSDispatch2_FuncCall * arg = (t_iTJSDispatch2_FuncCall *)data;
	arg->_ret = 
	arg->_this->FuncCall(
		arg->flag,
		arg->membername,
		arg->hint,
		arg->result,
		arg->numparams,
		arg->param,
		arg->objthis
		);
}
tjs_error Try_iTJSDispatch2_FuncCall(iTJSDispatch2 * _this, tjs_uint32 flag, const tjs_char * membername, tjs_uint32 *hint, tTJSVariant *result, tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *objthis)
{
	t_iTJSDispatch2_FuncCall arg(
		_this,
		flag,
		membername,
		hint,
		result,
		numparams,
		param,
		objthis
	);
	TVPDoTryBlock(_Try_iTJSDispatch2_FuncCall, _CatchFuncCall, NULL, &arg);
	return arg._ret;
}

struct Header;
struct Items;
class Progress;

// BITMAPラッパ
struct Bitmap {
	typedef unsigned char PIX;
	iTJSDispatch2 *lay;
	HBITMAP bitmap;
	HICON icon;
	Bitmap(iTJSDispatch2 *layer) : lay(layer), bitmap(0), icon(0) { }
	~Bitmap() { }
	void removeBitmap() { }
	HBITMAP createBitmap(HWND hwnd, tjs_int *pBmpW=0, tjs_int *pBmpH=0, bool withAlpha=false) { }
	HICON createIcon(HWND hwnd) { }
};

// HBRUSHラッパ
struct SolidBrush {
	HBRUSH brush;
	SolidBrush(DWORD rgb) : brush(NULL) { }
	~SolidBrush() { }
};

// DRAWITEMアクセス用クラス
struct DrawItem {
	DrawItem() : ref(0) { }
	DrawItem(DRAWITEMSTRUCT const *p) : ref(p) { }
	UINT      GetCtlType()    const { }
	UINT      GetCtlID()      const { }
	UINT      GetItemID()     const { }
	UINT      GetItemAction() { }
	UINT      GetItemState()  const { }
	DWORD     GetItemData()   const { }
	tjs_int64 GetHWndItem()   const { }
	tTJSVariant GetItemRect() { }
	void draw(Bitmap *bmp, tjs_int x, tjs_int y) { }
private:
	DRAWITEMSTRUCT const *ref;
};

// NMHDR アクセス用クラス
struct NotifyAccessor {
	NotifyAccessor() : ptr(0), ref(0) { }
	NotifyAccessor(NMHDR const *p) : ptr((BYTE const *)p), ref(p) { }
	tjs_int64 GetHWndFrom() { }
	UINT      GetIdFrom()   const { }
	UINT      GetCode()     const { }
	inline BYTE  GetByte( int ofs) { }
	inline WORD  GetWord( int ofs) { }
	inline DWORD GetDWord(int ofs) { }
private:
	BYTE const *ptr;
	NMHDR const* ref;
};

// 汎用バイナリオ操作ブジェクト
struct Blob {
	Blob(DWORD size) : ptr(0), size(size) { }
	Blob(BYTE  *ptr) : ptr(ptr), size(0) { }
	~Blob() { }
	tjs_int64 GetPointer() { }
	inline BYTE  GetByte( int ofs) { }
	inline WORD  GetWord( int ofs) { }
	inline DWORD GetDWord(int ofs) { }
	inline tjs_int64 GetDWordLong(int ofs) { }
	inline void  SetByte( int ofs, BYTE  v) { }
	inline void  SetWord( int ofs, WORD  v) { }
	inline void  SetDWord(int ofs, DWORD v) { }
	inline void  SetDWordLong(int ofs, tjs_int64 v) { }
	ttstr GetText(int ofs) { }
	void  SetText(int ofs, tjs_char const *text) { }
	static Blob* ReferPointer(tjs_int64 ptr) { }
private:
	BYTE *ptr;
	DWORD size;
};

class WIN32Dialog {
public:
	// 型のalias
	typedef ncbPropAccessor PropT;
	typedef ncbDictionaryAccessor DictT;

	typedef tTJSVariant     VarT;
	typedef iTJSDispatch2   DspT;

	typedef float ProgressValueT;

	typedef DialogConfig::SizeT   SizeT;
	typedef DialogConfig::NameT   NameT;
	typedef DialogConfig::StringT StringT;
private:
	typedef ncbInstanceAdaptor<WIN32Dialog> SelfAdaptorT;
	typedef ncbInstanceAdaptor<Header>      HeadAdaptorT;
	typedef ncbInstanceAdaptor<Items>       ItemAdaptorT;
	typedef ncbInstanceAdaptor<Bitmap>      BitmapAdaptorT;
	typedef ncbInstanceAdaptor<SolidBrush>  SolidBrushAdaptorT;

	HWND dialogHWnd;
	HICON icon;
	HMODULE resource;
	HPROPSHEETPAGE propsheet;
	Progress *progress;
	DspT *owner, *objthis;
	bool modeless;
	BYTE *buf;
	BYTE *ref;
	VarT resid, iconBitmap;
	HHOOK hHook;
public:
	// constructor
	WIN32Dialog(DspT *_owner = 0)
		:	dialogHWnd(0),
			icon(0),
			resource(0),
			propsheet(0),
			progress(0),
			owner(_owner),
			objthis(0),
			modeless(false),
			buf(0),
			hHook(0) { }

	// destructor
	virtual ~WIN32Dialog() { }
	BYTE* CreateBuffer(SizeT sz) { }

	// コールバック呼び出し
	DspT *_hasCallback(NameT event, tTJSVariant &rslt) {
		DspT *obj = owner ? owner : objthis;
		if (!obj) return NULL;

		// コールバックが存在するか
		tjs_uint32 hint = 0;
		if (TJS_FAILED(obj->PropGet(TJS_MEMBERMUSTEXIST, event, &hint, &rslt, obj))) return NULL;

		rslt.Clear();
		return obj;
	}
	LRESULT callback(NameT event, tjs_int numparams, tTJSVariant **params) {
		tTJSVariant rslt;
		DspT *obj = _hasCallback(event, rslt);
		if (!obj) return FALSE;

		// 引数を渡してコールバックを呼ぶ
		Try_iTJSDispatch2_FuncCall(obj, 0, event, 0, &rslt, numparams, params, obj);
		return (rslt.AsInteger() != 0) ? TRUE : FALSE;
	}
	// 通常コールバック
	LRESULT callback(NameT event, UINT msg, WPARAM wparam, LPARAM lparam) { };
	// WM_NOTIFY用コールバック
	LRESULT callback(NameT event, WPARAM wparam, NMHDR const *nmhdr) { };
	// WM_DRAWITEM用コールバック
	LRESULT callback(NameT event, WPARAM wparam, DRAWITEMSTRUCT const *drawitem) { };
	// WM_CTLCOLOR*用コールバック
	LRESULT callback(NameT event, int id, HDC hdc) { };

	// リソース読み込み
	static tjs_error TJS_INTF_METHOD loadResource(VarT *result, tjs_int numparams, VarT **param, WIN32Dialog *self) { }
protected:
	// DLLのリソースを読み込む
	void _loadResource(NameT module) { }
	void _setResource(VarT *id) { }
	LPCWSTR getResourceName() { }

public:
	// テンプレート作成
	static tjs_error TJS_INTF_METHOD makeTemplate(VarT *result, tjs_int numparams, VarT **param, WIN32Dialog *self);

	bool IsValid() { }
	void checkDialogValid() { }

	// -------------------------------------------------------------
	// 各種 Item 操作関数
	HWND GetItemHWND(int id) { }
	int GetDlgCtrlItem(HWND hwnd) { }
	VarT GetItemClassName(int id) { }

	// for tjs
	tjs_int64 GetItem(int id) { }
	int GetItemID(tjs_int64 hwnd) { }
	bool IsExistentItem(int id) { }
	long GetItemLong(int id, int index) { }
	long SetItemLong(int id, int index, long newlong) { }
	bool   LockItemUpdate(int id) { }
	bool UnlockItemUpdate()       const { }

	int GetItemInt(int id) { }
	void SetItemInt(int id, int value) { }
	StringT GetItemText(int id) { }
	void SetItemText(int id, NameT string) { }

	void SetItemEnabled(int id, bool en) { }
	bool GetItemEnabled(int id) { }
	void SetItemFocus(int id) { }

	long GetItemLeft(int id)   const { return 1; }
	long GetItemTop(int id)    const { return 1; }
	long GetItemWidth(int id)  const { return 1; }
	long GetItemHeight(int id) { return 1; }
	void SetItemPos(int id, int x, int y) { }
	void SetItemSize(int id, int w, int h) { }

	static tjs_error TJS_INTF_METHOD SetItemBitmap(VarT *result, tjs_int numparams, VarT **param, WIN32Dialog *self) { }

	void SetPos(int x,  int y) { }
	void SetSize(int w, int h) { }
	void SetActive() { }

	long GetLeft  () { return 1; }
	long GetTop   () { return 1; }
	long GetWidth () { return 1; }
	long GetHeight() { return 1; }
	VarT GetWindowRect() { }
	VarT GetClientRect() { }

	static tjs_error TJS_INTF_METHOD sendItemMessage(VarT *result, tjs_int numparams, VarT **param, WIN32Dialog *self) { }
protected:
	LRESULT _sendItemMessage(int id, UINT msg, WPARAM wparam, LPARAM lparam, bool isstr = false) { }

	// TJS辞書⇒RECTへ値をコピー
	static inline bool _getRect(RECT &rect, PropT &prop) { }
	// RECT⇒TJS辞書へ値をコピー
	static inline bool _setRect(RECT &rect, PropT &prop) { }

public:
	VarT GetBaseUnits() {
		VarT var;
		DictT dict;
		if (dict.IsValid()) {
			dict.SetValue(TJS_W("h"), 1);
			dict.SetValue(TJS_W("v"), 1);
			var = dict;
		}
		return var;
	}
	VarT MapRect(VarT in) { }
	bool InvalidateAll(bool erase) { }
	bool InvalidateRect(VarT vrect, bool erase) { }

	// -------------------------------------------------------------
	// open (tjs raw callback)
	static tjs_error TJS_INTF_METHOD open(VarT *result, tjs_int numparams, VarT **param, DspT *objthis) {
		WIN32Dialog *self = SelfAdaptorT::GetNativeInstance(objthis); 
		if (!self) return TJS_E_NATIVECLASSCRASH;
		self->objthis = objthis;
		*result = (tjs_int32)self->_open(numparams > 0 ? *(param[0]) : VarT());
		return TJS_S_OK;
	}

	void close(DWORD id) { }

	tjs_int64 getHWND() { }

	bool getModeless() { }
	void setModeless(bool b) { }
	void show(int nCmdShow) { }

	// -------------------------------------------------------------
	// stubs
	virtual bool onInit(   long msg, long wp, long lp) { return false; }
	virtual bool onCommand(long msg, long wp, long lp) { }
	virtual bool onNotify( long wp, NotifyAccessor *acc) { }
	virtual bool onHScroll(long msg, long wp, long lp) { }
	virtual bool onVScroll(long msg, long wp, long lp) { }
	virtual bool onSize(   long msg, long wp, long lp) { }

protected:
	// -------------------------------------------------------------
	// ダイアログを開く
	int _open(VarT win) {
		tTJSVariant zv = tTJSVariant(0);
		tTJSVariant *params[] = {&zv,&zv,&zv};
		return callback(TJS_W("onInit"), 3, params);
	}
	static HWND _getOpenParent(VarT const &win) { }
	static HWND _getOpenParent(iTJSDispatch2 *obj) { }

	// GetLastErrorのエラーメッセージを取得して投げる
	static inline void ThrowLastError() { }

public:
	// ダイアログプロシージャ
	static LRESULT DlgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) { }
	static LRESULT NormalCallback(NameT cbn, HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) { }
	static LRESULT GetMsgProc(int ncode, WPARAM wparam, LPARAM lparam) { }

	// -------------------------------------------------------------
	// プロパティシート用

	bool isPropertySheet() { }

	HPROPSHEETPAGE setupPropSheet(iTJSDispatch2 *objthis, LPCWSTR titleov = 0) { }

	static LRESULT PropSheetProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) { }

	LRESULT propSheetMessage(int msg, VarT wp, VarT lp) { }

	void setMessageResult(LONG_PTR result) { }

	static tjs_int64  OpenPropertySheet(VarT win, VarT vpages, VarT velm) { }

	// -------------------------------------------------------------
	// タブコントロール用

	//	タブ挿入
	tjs_int64 InsertTabItem(int tabid, VarT pos, VarT title) { }

	//	タブ削除
	tjs_int64 DeleteTabItem(int tabid, VarT pos) { }

	//	すべてのタブを削除
	tjs_int64 DeleteAllTabItem(int tabid) { }

	//	選択されているタブ
	tjs_int GetCurSelTab(int tabid) { }

	//	タブを選択
	tjs_int SetCurSelTab(int tabid, VarT pos) { }

	//	タブ内にダイアログを表示する
	tjs_int64 SelectTab(int tabid, VarT dlg) { }

	// -------------------------------------------------------------
	// プログレスダイアログ用インターフェース

	ProgressValueT getProgressValue() const;
	void           setProgressValue(ProgressValueT);
	bool           getProgressCanceled() const;
	void           setProgressCanceled(bool);
	static tjs_error TJS_INTF_METHOD openProgress(VarT *result, tjs_int num, VarT **param, iTJSDispatch2 *objthis);
	bool _openProgress(iTJSDispatch2*, VarT const&, int, bool, bool, bool);
	void closeProgress();
	bool isProgress() { }
	void checkProgress() { }

	// -------------------------------------------------------------
	// スクロールバー用インターフェース

	static tjs_error TJS_INTF_METHOD setScrollInfo(VarT *result, tjs_int num, VarT **param, iTJSDispatch2 *objthis) { }
	VarT	getScrollInfo(int id) { }

	// -------------------------------------------------------------
	// アイコン書き換え

#ifndef IDI_TVPWIN32
#define IDI_TVPWIN32 107 // [XXX]
#endif
	static HICON getIconHandle(HWND hwnd, VarT const &bmp) { }
	void setDialogIcon(VarT bmp) { }
	VarT getDialogIcon() { }

	// -------------------------------------------------------------
	// テンプレート値書き出し用
	template <typename T>
	static void SetValue(PropT *prop, NameT name, T *out) { }
	static void SetSzOrd(PropT *prop, NameT name, DialogTemplate::sz_Or_Ord *out) { }
	static void SetString(PropT *prop, NameT name, StringT *out) { }

	// -------------------------------------------------------------
	// メッセージボックス表示
	static int MessageBox(iTJSDispatch2* obj, NameT text, NameT caption, UINT type) { }
	static HHOOK MessageBoxHook;
	static HWND  MessageBoxOwnerHWND;
	static LRESULT MessageBoxHookProc(int nCode, WPARAM wParam, LPARAM lParam) { }

	// -------------------------------------------------------------
	// HookEx系APIをオンデマンドで読み込み
	static bool HookExAPILoaded, HookExAPIFailed;
	// typedef HHOOK   (WINAPI    *SetWindowsHookExT)(int idHook, HOOKPROC lpfn, HINSTANCE hMod, DWORD dwThreadId);
	// typedef BOOL    (WINAPI *UnhookWindowsHookExT)(HHOOK hhk);
	// typedef LRESULT (WINAPI      *CallNextHookExT)(HHOOK hhk, int nCode, WPARAM wParam, LPARAM lParam);
	// static    SetWindowsHookExT    _SetWindowsHookEx;
	// static UnhookWindowsHookExT _UnhookWindowsHookEx;
	// static      CallNextHookExT      _CallNextHookEx;
	// static bool LoadHookExAPI() { }
	// static HHOOK SetWindowsHookEx(int idHook, HOOKPROC lpfn, HINSTANCE hMod, DWORD dwThreadId) { }
	// static BOOL UnhookWindowsHookEx(HHOOK hhk) { }
	static LRESULT CallNextHookEx(HHOOK hhk, int nCode, WPARAM wParam, LPARAM lParam) { }
	static char *GetHookAPIName(char const *name, bool win, bool wide) { }

	// -------------------------------------------------------------
	// コモンコントロール初期化
	static void InitCommonControls() { }
	static bool InitCommonControlsEx(DWORD icc) { return false; }

	// -------------------------------------------------------------
	// 色選択ダイアログ
	static inline COLORREF ConvertRGBtoColorRef(DWORD rgb) { }
	static inline DWORD ConvertColorRefToRGB(COLORREF ref) { }
	static tjs_error TJS_INTF_METHOD chooseColor(VarT *result, tjs_int num, VarT **param, iTJSDispatch2 *obj) { }

	// -------------------------------------------------------------
	// その他
	static tjs_int64 GetOctetAddress(tTJSVariant oct) { }
	static tjs_int64 GetStringAddress(tTJSVariant str) { }

	// -------------------------------------------------------------
	// ウィンドウ位置など
	void BringToFront(void) { }

};
HHOOK WIN32Dialog::MessageBoxHook = 0;
HWND  WIN32Dialog::MessageBoxOwnerHWND = 0;

bool  WIN32Dialog::HookExAPILoaded = false;
bool  WIN32Dialog::HookExAPIFailed = false;


// ダイアログヘッダ設定クラス
struct Header : public DialogHeader {
	Header() : DialogHeader() { }

	void store(tTJSVariant elmobj) { }

	void set_dlgItems(WORD n) { }
	WORD get_dlgItems() { }
};

struct Items : public DialogItems {
	Items() : DialogItems() { }

	void store(tTJSVariant elmobj) { }
};

// テンプレート作成
tjs_error TJS_INTF_METHOD WIN32Dialog::makeTemplate(VarT *result, tjs_int numparams, VarT **param, WIN32Dialog *self) { return TJS_S_OK; }

// -------------------------------------------------------------
// プログレス用

struct ProgressParam {
	bool   isResource;
	HWND   parent;
	HINSTANCE handle;
	HICON  icon;
	void   *data;
};
class Progress : public SimpleThreadBase<ProgressParam const*> {
public:
	typedef SimpleThreadBase BaseClass;
	typedef WIN32Dialog::ProgressValueT PrgValueT;
	enum { ProgressMax = 10000, TimeOut = INFINITE }; //5000 };

	virtual ~Progress() { }
	Progress(int prgid, bool dsapp, bool breathe)
		:   BaseClass(TimeOut),
			prgid(prgid),
			dsapp(dsapp), breathe(breathe), setmax(false), cancel(false),
			progress(0.0), target(0) { }

	HWND open(HWND parent, bool isResource, HINSTANCE handle, void *data, HICON icon) { };

	void setProgress(PrgValueT value) { }
	PrgValueT getProgress() { }
	void close() { }

	bool isCanceled() { }
	void resetCancel() { }
	void onCancel() { }
	void setCancelState(bool c) { }

	void onInit(HWND hwnd) { }

protected:

	virtual unsigned threadMain(HANDLE prepare, HANDLE stop, ProgressParam const *param) { };

private:
	static LRESULT ProgressProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) { }
	HWND createDialog(ProgressParam const *p) { }

	void _close(bool isDestruct) { }

	void setEnableAppWindow(bool en) { }
	HWND getDlgItem(int id) { }

	int prgid;
	bool dsapp, breathe, setmax, cancel;
	PrgValueT progress;
	HWND target;
	HANDLE doneInit;
};

tjs_error TJS_INTF_METHOD
WIN32Dialog::openProgress(VarT *result, tjs_int numparams, VarT **param, iTJSDispatch2 *objthis) { }
bool WIN32Dialog::_openProgress(iTJSDispatch2 *objthis, VarT const &win, int prgid, bool appDisable, bool breathe, bool activate) { }
void WIN32Dialog::closeProgress() { }

WIN32Dialog::ProgressValueT
/**/ WIN32Dialog::getProgressValue() const           { }
void WIN32Dialog::setProgressValue(ProgressValueT v) { }
bool WIN32Dialog::getProgressCanceled() const        { }
void WIN32Dialog::setProgressCanceled(bool b)        { }

// -------------------------------------------------------------

#define ENUM(n) Variant(#n, (tTVInteger)n, 0)

NCB_REGISTER_SUBCLASS(Header) {
	Constructor();
	Method(TJS_W("store"), &Class::store);
	Property(TJS_W("dlgItems"), &Class::get_dlgItems, &Class::set_dlgItems);
}
NCB_REGISTER_SUBCLASS(Items) {
	Constructor();
	Method(TJS_W("store"), &Class::store);
}
NCB_REGISTER_SUBCLASS(Bitmap) {
	Constructor<iTJSDispatch2*>(0);
}
NCB_REGISTER_SUBCLASS(SolidBrush) {
	Constructor<DWORD>(0);
}

NCB_REGISTER_SUBCLASS(DrawItem) {
	Constructor();
	Property(TJS_W("ctrlType"),   &Class::GetCtlType,    (int)0);
	Property(TJS_W("ctrlID"),     &Class::GetCtlID,      (int)0);
	Property(TJS_W("itemID"),     &Class::GetItemID,     (int)0);
	Property(TJS_W("itemAction"), &Class::GetItemAction, (int)0);
	Property(TJS_W("itemState"),  &Class::GetItemState,  (int)0);
	Property(TJS_W("itemData"),   &Class::GetItemData,   (int)0);
	Property(TJS_W("itemRect"),   &Class::GetItemRect,   (int)0);
	Property(TJS_W("hwndItem"),   &Class::GetHWndItem,   (int)0);
	Method(  TJS_W("draw"),       &Class::draw);
}

NCB_REGISTER_SUBCLASS(NotifyAccessor) {
	Constructor();
	Property(TJS_W("hwndFrom"), &Class::GetHWndFrom, (int)0);
	Property(TJS_W("idFrom"),   &Class::GetIdFrom,   (int)0);
	Property(TJS_W("code"),     &Class::GetCode,     (int)0);
	Method(TJS_W("getByte"),  &Class::GetByte);
	Method(TJS_W("getWord"),  &Class::GetWord);
	Method(TJS_W("getDWord"), &Class::GetDWord);
}

NCB_REGISTER_SUBCLASS(Blob) {
	Constructor<DWORD>(0);
	Property(TJS_W("pointer"), &Class::GetPointer, (int)0);
	Method(TJS_W("getByte"),   &Class::GetByte);
	Method(TJS_W("getWord"),   &Class::GetWord);
	Method(TJS_W("getDWord"),  &Class::GetDWord);
	Method(TJS_W("getDWordLong"),  &Class::GetDWordLong);
	Method(TJS_W("getText"),   &Class::GetText);
	Method(TJS_W("setByte"),   &Class::SetByte);
	Method(TJS_W("setWord"),   &Class::SetWord);
	Method(TJS_W("setDWord"),  &Class::SetDWord);
	Method(TJS_W("setDWordLong"),  &Class::SetDWordLong);
	Method(TJS_W("setText"),   &Class::SetText);

	Method(TJS_W("ReferPointer"), &Class::ReferPointer);
}

NCB_REGISTER_CLASS(WIN32Dialog) {
	NCB_SUBCLASS(Header, Header);
	NCB_SUBCLASS(Items,  Items);
	NCB_SUBCLASS(Bitmap, Bitmap);
	NCB_SUBCLASS(SolidBrush, SolidBrush);
	NCB_SUBCLASS(DrawItem, DrawItem);
	NCB_SUBCLASS(Notify, NotifyAccessor);
	NCB_SUBCLASS(Blob, Blob);

	Constructor<iTJSDispatch2*>(0);

	RawCallback(TJS_W("loadResource"), &Class::loadResource, 0);
	RawCallback(TJS_W("makeTemplate"), &Class::makeTemplate, 0);
	RawCallback(TJS_W("open"), &Class::open, 0);
	Method(TJS_W("close"),     &Class::close);

	Method(TJS_W("getItem"),         &Class::GetItem);
	Method(TJS_W("getItemID"),       &Class::GetItemID);
	Method(TJS_W("getItemClassName"),&Class::GetItemClassName);
	Method(TJS_W("setItemLong"),     &Class::SetItemLong);
	Method(TJS_W("getItemLong"),     &Class::GetItemLong);
	Method(TJS_W("setItemInt"),      &Class::SetItemInt);
	Method(TJS_W("getItemInt"),      &Class::GetItemInt);
	Method(TJS_W("setItemText"),     &Class::SetItemText);
	Method(TJS_W("getItemText"),     &Class::GetItemText);
	Method(TJS_W("setItemEnabled"),  &Class::SetItemEnabled);
	Method(TJS_W("getItemEnabled"),  &Class::GetItemEnabled);
	Method(TJS_W("setItemFocus"),    &Class::SetItemFocus);
	Method(TJS_W("getItemLeft"),     &Class::GetItemLeft);
	Method(TJS_W("getItemTop"),      &Class::GetItemTop);
	Method(TJS_W("getItemWidth"),    &Class::GetItemWidth);
	Method(TJS_W("getItemHeight"),   &Class::GetItemHeight);
	Method(TJS_W("setItemPos"),      &Class::SetItemPos);
	Method(TJS_W("setItemSize"),     &Class::SetItemSize);
	RawCallback(TJS_W("setItemBitmap"),   &Class::SetItemBitmap, 0);
	Method(TJS_W("isExistentItem"),  &Class::IsExistentItem);
	Method(TJS_W("lockItemUpdate"),  &Class::LockItemUpdate);
	Method(TJS_W("unlockItemUpdate"),  &Class::UnlockItemUpdate);

	RawCallback(TJS_W("sendItemMessage"), &Class::sendItemMessage, 0);

	Method(TJS_W("getBaseUnits"),    &Class::GetBaseUnits);
	Method(TJS_W("mapRect"),         &Class::MapRect);
	Method(TJS_W("invalidateRect"),  &Class::InvalidateRect);
	Method(TJS_W("invalidateAll"),   &Class::InvalidateAll);

	Method(TJS_W("setPos"),          &Class::SetPos);
	Method(TJS_W("setSize"),         &Class::SetSize);
	Method(TJS_W("setActive"),       &Class::SetActive);
	Property(TJS_W("left"),          &Class::GetLeft,   (int)0);
	Property(TJS_W("top"),           &Class::GetTop,    (int)0);
	Property(TJS_W("width"),         &Class::GetWidth,  (int)0);
	Property(TJS_W("height"),        &Class::GetHeight, (int)0);
	Method(TJS_W("getWindowRect"),   &Class::GetWindowRect);
	Method(TJS_W("getClientRect"),   &Class::GetClientRect);

	Method(TJS_W("onInit"),    &Class::onInit);
	Method(TJS_W("onCommand"), &Class::onCommand);
	Method(TJS_W("onNotify"),  &Class::onNotify);
	Method(TJS_W("onHScroll"), &Class::onHScroll);
	Method(TJS_W("onVScroll"), &Class::onVScroll);
	Method(TJS_W("onSize"),    &Class::onSize);

	Method(TJS_W("show"),            &Class::show);
	Property(TJS_W("modeless"),      &Class::getModeless, &Class::setModeless);
	Property(TJS_W("HWND"),          &Class::getHWND, (int)0);

	Property(TJS_W("icon"),          &Class::getDialogIcon, &Class::setDialogIcon);

	Property(TJS_W("isValid"),        &Class::IsValid, (int)0);

	// 定数定義

	// stock object
	ENUM(BLACK_BRUSH);
	ENUM(HOLLOW_BRUSH);
	ENUM(NULL_BRUSH);
	ENUM(WHITE_BRUSH);

	// Window Long index
	ENUM(GWL_STYLE);
	ENUM(GWLP_WNDPROC);
	ENUM(GWLP_HINSTANCE);
	ENUM(GWLP_HWNDPARENT);
	ENUM(GWL_STYLE);
	ENUM(GWL_EXSTYLE);
	ENUM(GWLP_USERDATA);
	ENUM(GWL_ID);

	// Dialog Long index
	//XXX 64bitでエラー。いったんコメントアウト
	//ENUM(DWLP_DLGPROC);
	//ENUM(DWLP_MSGRESULT);
	//ENUM(DWLP_USER);

	// Window Styles
	ENUM(WS_OVERLAPPED);
	ENUM(WS_POPUP);
	ENUM(WS_CHILD);
	ENUM(WS_MINIMIZE);
	ENUM(WS_VISIBLE);
	ENUM(WS_DISABLED);
	ENUM(WS_CLIPSIBLINGS);
	ENUM(WS_CLIPCHILDREN);
	ENUM(WS_MAXIMIZE);
	ENUM(WS_CAPTION);
	ENUM(WS_BORDER);
	ENUM(WS_DLGFRAME);
	ENUM(WS_VSCROLL);
	ENUM(WS_HSCROLL);
	ENUM(WS_SYSMENU);
	ENUM(WS_THICKFRAME);
	ENUM(WS_GROUP);
	ENUM(WS_TABSTOP);

	ENUM(WS_MINIMIZEBOX);
	ENUM(WS_MAXIMIZEBOX);

	ENUM(WS_TILED);
	ENUM(WS_ICONIC);
	ENUM(WS_SIZEBOX);
	ENUM(WS_TILEDWINDOW);

	ENUM(WS_OVERLAPPEDWINDOW);
	ENUM(WS_POPUPWINDOW);
	ENUM(WS_CHILDWINDOW);

	ENUM(WS_EX_DLGMODALFRAME);
	ENUM(WS_EX_NOPARENTNOTIFY);
	ENUM(WS_EX_TOPMOST);
	ENUM(WS_EX_ACCEPTFILES);
	ENUM(WS_EX_TRANSPARENT);
	ENUM(WS_EX_MDICHILD);
	ENUM(WS_EX_TOOLWINDOW);
	ENUM(WS_EX_WINDOWEDGE);
	ENUM(WS_EX_CLIENTEDGE);
	ENUM(WS_EX_CONTEXTHELP);
	ENUM(WS_EX_RIGHT);
	ENUM(WS_EX_LEFT);
	ENUM(WS_EX_RTLREADING);
	ENUM(WS_EX_LTRREADING);
	ENUM(WS_EX_LEFTSCROLLBAR);
	ENUM(WS_EX_RIGHTSCROLLBAR);
	ENUM(WS_EX_CONTROLPARENT);
	ENUM(WS_EX_STATICEDGE);
	ENUM(WS_EX_APPWINDOW);
	ENUM(WS_EX_OVERLAPPEDWINDOW);
	ENUM(WS_EX_PALETTEWINDOW);
#ifdef   WS_EX_LAYERED
	ENUM(WS_EX_LAYERED);
#endif
	ENUM(WS_EX_NOINHERITLAYOUT);
	ENUM(WS_EX_LAYOUTRTL);
#ifdef   WS_EX_COMPOSITED
	ENUM(WS_EX_COMPOSITED);
#endif
#ifdef   WS_EX_NOACTIVATE
	ENUM(WS_EX_NOACTIVATE);
#endif

	// Dialog Box Command IDs
	ENUM(IDOK);
	ENUM(IDCANCEL);
	ENUM(IDABORT);
	ENUM(IDRETRY);
	ENUM(IDIGNORE);
	ENUM(IDYES);
	ENUM(IDNO);
	ENUM(IDCLOSE);
	ENUM(IDHELP);
#ifdef   IDTRYAGAIN
	ENUM(IDTRYAGAIN);
#endif
#ifdef   IDCONTINUE
	ENUM(IDCONTINUE);
#endif
#ifdef   IDTIMEOUT
	ENUM(IDTIMEOUT);
#endif

	// Edit Control Styles
	ENUM(ES_LEFT);
	ENUM(ES_CENTER);
	ENUM(ES_RIGHT);
	ENUM(ES_MULTILINE);
	ENUM(ES_UPPERCASE);
	ENUM(ES_LOWERCASE);
	ENUM(ES_PASSWORD);
	ENUM(ES_AUTOVSCROLL);
	ENUM(ES_AUTOHSCROLL);
	ENUM(ES_NOHIDESEL);
	ENUM(ES_OEMCONVERT);
	ENUM(ES_READONLY);
	ENUM(ES_WANTRETURN);
	ENUM(ES_NUMBER);

	// Edit Control Notification Codes
	ENUM(EN_SETFOCUS);
	ENUM(EN_KILLFOCUS);
	ENUM(EN_CHANGE);
	ENUM(EN_UPDATE);
	ENUM(EN_ERRSPACE);
	ENUM(EN_MAXTEXT);
	ENUM(EN_HSCROLL);
	ENUM(EN_VSCROLL);
#ifdef   EN_ALIGN_LTR_EC
	ENUM(EN_ALIGN_LTR_EC);
#endif
#ifdef   EN_ALIGN_RTL_EC
	ENUM(EN_ALIGN_RTL_EC);
#endif

	// Edit control EM_SETMARGIN parameters
	ENUM(EC_LEFTMARGIN);
	ENUM(EC_RIGHTMARGIN);
	ENUM(EC_USEFONTINFO);
	// wParam of EM_GET/SETIMESTATUS
#ifdef   EMSIS_COMPOSITIONSTRING
	ENUM(EMSIS_COMPOSITIONSTRING);
#endif
	// lParam for EMSIS_COMPOSITIONSTRING
#ifdef   EIMES_GETCOMPSTRATONCE
	ENUM(EIMES_GETCOMPSTRATONCE);
#endif
#ifdef   EIMES_CANCELCOMPSTRINFOCUS
	ENUM(EIMES_CANCELCOMPSTRINFOCUS);
#endif
#ifdef   EIMES_COMPLETECOMPSTRKILLFOCUS
	ENUM(EIMES_COMPLETECOMPSTRKILLFOCUS);
#endif

	// Edit Control Messages
	ENUM(EM_GETSEL);
	ENUM(EM_SETSEL);
	ENUM(EM_GETRECT);
	ENUM(EM_SETRECT);
	ENUM(EM_SETRECTNP);
	ENUM(EM_SCROLL);
	ENUM(EM_LINESCROLL);
	ENUM(EM_SCROLLCARET);
	ENUM(EM_GETMODIFY);
	ENUM(EM_SETMODIFY);
	ENUM(EM_GETLINECOUNT);
	ENUM(EM_LINEINDEX);
	ENUM(EM_SETHANDLE);
	ENUM(EM_GETHANDLE);
	ENUM(EM_GETTHUMB);
	ENUM(EM_LINELENGTH);
	ENUM(EM_REPLACESEL);
	ENUM(EM_GETLINE);
	ENUM(EM_LIMITTEXT);
	ENUM(EM_CANUNDO);
	ENUM(EM_UNDO);
	ENUM(EM_FMTLINES);
	ENUM(EM_LINEFROMCHAR);
	ENUM(EM_SETTABSTOPS);
	ENUM(EM_SETPASSWORDCHAR);
	ENUM(EM_EMPTYUNDOBUFFER);
	ENUM(EM_GETFIRSTVISIBLELINE);
	ENUM(EM_SETREADONLY);
	ENUM(EM_SETWORDBREAKPROC);
	ENUM(EM_GETWORDBREAKPROC);
	ENUM(EM_GETPASSWORDCHAR);
	ENUM(EM_SETMARGINS);
	ENUM(EM_GETMARGINS);
	ENUM(EM_SETLIMITTEXT);
	ENUM(EM_GETLIMITTEXT);
	ENUM(EM_POSFROMCHAR);
	ENUM(EM_CHARFROMPOS);
#ifdef   EM_SETIMESTATUS
	ENUM(EM_SETIMESTATUS);
#endif
#ifdef   EM_GETIMESTATUS
	ENUM(EM_GETIMESTATUS);
#endif

	// EDITWORDBREAKPROC code values
	ENUM(WB_LEFT);
	ENUM(WB_RIGHT);
	ENUM(WB_ISDELIMITER);

	// Button Control Styles
	ENUM(BS_PUSHBUTTON);
	ENUM(BS_DEFPUSHBUTTON);
	ENUM(BS_CHECKBOX);
	ENUM(BS_AUTOCHECKBOX);
	ENUM(BS_RADIOBUTTON);
	ENUM(BS_3STATE);
	ENUM(BS_AUTO3STATE);
	ENUM(BS_GROUPBOX);
	ENUM(BS_USERBUTTON);
	ENUM(BS_AUTORADIOBUTTON);
#ifdef   BS_PUSHBOX
	ENUM(BS_PUSHBOX);
#endif
	ENUM(BS_OWNERDRAW);
#ifdef   BS_TYPEMASK
	ENUM(BS_TYPEMASK);
#endif
	ENUM(BS_LEFTTEXT);
	ENUM(BS_TEXT);
	ENUM(BS_ICON);
	ENUM(BS_BITMAP);
	ENUM(BS_LEFT);
	ENUM(BS_RIGHT);
	ENUM(BS_CENTER);
	ENUM(BS_TOP);
	ENUM(BS_BOTTOM);
	ENUM(BS_VCENTER);
	ENUM(BS_PUSHLIKE);
	ENUM(BS_MULTILINE);
	ENUM(BS_NOTIFY);
	ENUM(BS_FLAT);
	ENUM(BS_RIGHTBUTTON);

	// User Button Notification Codes
	ENUM(BN_CLICKED);
	ENUM(BN_PAINT);
	ENUM(BN_HILITE);
	ENUM(BN_UNHILITE);
	ENUM(BN_DISABLE);
	ENUM(BN_DOUBLECLICKED);
	ENUM(BN_PUSHED);
	ENUM(BN_UNPUSHED);
	ENUM(BN_DBLCLK);
	ENUM(BN_SETFOCUS);
	ENUM(BN_KILLFOCUS);

	// Button Control Messages
	ENUM(BM_GETCHECK);
	ENUM(BM_SETCHECK);
	ENUM(BM_GETSTATE);
	ENUM(BM_SETSTATE);
	ENUM(BM_SETSTYLE);
	ENUM(BM_CLICK);
	ENUM(BM_GETIMAGE);
	ENUM(BM_SETIMAGE);
#ifdef   BM_SETDONTCLICK
	ENUM(BM_SETDONTCLICK);
#endif
	ENUM(BST_UNCHECKED);
	ENUM(BST_CHECKED);
	ENUM(BST_INDETERMINATE);
	ENUM(BST_PUSHED);
	ENUM(BST_FOCUS);

	// Static Control Constants
	ENUM(SS_LEFT);
	ENUM(SS_CENTER);
	ENUM(SS_RIGHT);
	ENUM(SS_ICON);
	ENUM(SS_BLACKRECT);
	ENUM(SS_GRAYRECT);
	ENUM(SS_WHITERECT);
	ENUM(SS_BLACKFRAME);
	ENUM(SS_GRAYFRAME);
	ENUM(SS_WHITEFRAME);
	ENUM(SS_USERITEM);
	ENUM(SS_SIMPLE);
	ENUM(SS_LEFTNOWORDWRAP);
	ENUM(SS_OWNERDRAW);
	ENUM(SS_BITMAP);
	ENUM(SS_ENHMETAFILE);
	ENUM(SS_ETCHEDHORZ);
	ENUM(SS_ETCHEDVERT);
	ENUM(SS_ETCHEDFRAME);
	ENUM(SS_TYPEMASK);
#ifdef   SS_REALSIZECONTROL
	ENUM(SS_REALSIZECONTROL);
#endif
	ENUM(SS_NOPREFIX);
	ENUM(SS_NOTIFY);
	ENUM(SS_CENTERIMAGE);
	ENUM(SS_RIGHTJUST);
	ENUM(SS_REALSIZEIMAGE);
	ENUM(SS_SUNKEN);
#ifdef   SS_EDITCONTROL
	ENUM(SS_EDITCONTROL);
#endif
	ENUM(SS_ENDELLIPSIS);
	ENUM(SS_PATHELLIPSIS);
	ENUM(SS_WORDELLIPSIS);
	ENUM(SS_ELLIPSISMASK);

	// Static Control Mesages
	ENUM(STM_SETICON);
	ENUM(STM_GETICON);
	ENUM(STM_SETIMAGE);
	ENUM(STM_GETIMAGE);
	ENUM(STN_CLICKED);
	ENUM(STN_DBLCLK);
	ENUM(STN_ENABLE);
	ENUM(STN_DISABLE);
#ifdef   STM_MSGMAX
	ENUM(STM_MSGMAX);
#endif

	// Dialog Styles
	ENUM(DS_ABSALIGN);
	ENUM(DS_SYSMODAL);
	ENUM(DS_LOCALEDIT);
	ENUM(DS_SETFONT);
	ENUM(DS_MODALFRAME);
	ENUM(DS_NOIDLEMSG);
	ENUM(DS_SETFOREGROUND);
	ENUM(DS_3DLOOK);
	ENUM(DS_FIXEDSYS);
	ENUM(DS_NOFAILCREATE);
	ENUM(DS_CONTROL);
	ENUM(DS_CENTER);
	ENUM(DS_CENTERMOUSE);
	ENUM(DS_CONTEXTHELP);
	ENUM(DS_SHELLFONT);
#ifdef   DS_USEPIXELS
	ENUM(DS_USEPIXELS);
#endif

	ENUM(DM_GETDEFID);
	ENUM(DM_SETDEFID);
	ENUM(DM_REPOSITION);
	// Returned in HIWORD() of DM_GETDEFID result if msg is supported
	ENUM(DC_HASDEFID);

	// Dialog Codes
	ENUM(DLGC_WANTARROWS);
	ENUM(DLGC_WANTTAB);
	ENUM(DLGC_WANTALLKEYS);
	ENUM(DLGC_WANTMESSAGE);
	ENUM(DLGC_HASSETSEL);
	ENUM(DLGC_DEFPUSHBUTTON);
	ENUM(DLGC_UNDEFPUSHBUTTON);
	ENUM(DLGC_RADIOBUTTON);
	ENUM(DLGC_WANTCHARS);
	ENUM(DLGC_STATIC);
	ENUM(DLGC_BUTTON);

	// Listbox Return Values
	ENUM(LB_CTLCODE);
	ENUM(LB_OKAY);
	ENUM(LB_ERR);
	ENUM(LB_ERRSPACE);

	// Listbox Notification Codes
	ENUM(LBN_ERRSPACE);
	ENUM(LBN_SELCHANGE);
	ENUM(LBN_DBLCLK);
	ENUM(LBN_SELCANCEL);
	ENUM(LBN_SETFOCUS);
	ENUM(LBN_KILLFOCUS);

	ENUM(LB_ADDSTRING);
	ENUM(LB_INSERTSTRING);
	ENUM(LB_DELETESTRING);
	ENUM(LB_SELITEMRANGEEX);
	ENUM(LB_RESETCONTENT);
	ENUM(LB_SETSEL);
	ENUM(LB_SETCURSEL);
	ENUM(LB_GETSEL);
	ENUM(LB_GETCURSEL);
	ENUM(LB_GETTEXT);
	ENUM(LB_GETTEXTLEN);
	ENUM(LB_GETCOUNT);
	ENUM(LB_SELECTSTRING);
	ENUM(LB_DIR);
	ENUM(LB_GETTOPINDEX);
	ENUM(LB_FINDSTRING);
	ENUM(LB_GETSELCOUNT);
	ENUM(LB_GETSELITEMS);
	ENUM(LB_SETTABSTOPS);
	ENUM(LB_GETHORIZONTALEXTENT);
	ENUM(LB_SETHORIZONTALEXTENT);
	ENUM(LB_SETCOLUMNWIDTH);
	ENUM(LB_ADDFILE);
	ENUM(LB_SETTOPINDEX);
	ENUM(LB_GETITEMRECT);
	ENUM(LB_GETITEMDATA);
	ENUM(LB_SETITEMDATA);
	ENUM(LB_SELITEMRANGE);
	ENUM(LB_SETANCHORINDEX);
	ENUM(LB_GETANCHORINDEX);
	ENUM(LB_SETCARETINDEX);
	ENUM(LB_GETCARETINDEX);
	ENUM(LB_SETITEMHEIGHT);
	ENUM(LB_GETITEMHEIGHT);
	ENUM(LB_FINDSTRINGEXACT);
	ENUM(LB_SETLOCALE);
	ENUM(LB_GETLOCALE);
	ENUM(LB_SETCOUNT);
	ENUM(LB_INITSTORAGE);
	ENUM(LB_ITEMFROMPOINT);
#ifdef   LB_MULTIPLEADDSTRING
	ENUM(LB_MULTIPLEADDSTRING);
#endif
#ifdef   LB_GETLISTBOXINFO
	ENUM(LB_GETLISTBOXINFO);
#endif
#ifdef   LB_MSGMAX
	ENUM(LB_MSGMAX);
#endif

	// Listbox Styles
	ENUM(LBS_NOTIFY);
	ENUM(LBS_SORT);
	ENUM(LBS_NOREDRAW);
	ENUM(LBS_MULTIPLESEL);
	ENUM(LBS_OWNERDRAWFIXED);
	ENUM(LBS_OWNERDRAWVARIABLE);
	ENUM(LBS_HASSTRINGS);
	ENUM(LBS_USETABSTOPS);
	ENUM(LBS_NOINTEGRALHEIGHT);
	ENUM(LBS_MULTICOLUMN);
	ENUM(LBS_WANTKEYBOARDINPUT);
	ENUM(LBS_EXTENDEDSEL);
	ENUM(LBS_DISABLENOSCROLL);
	ENUM(LBS_NODATA);
	ENUM(LBS_NOSEL);
#ifdef   LBS_COMBOBOX
	ENUM(LBS_COMBOBOX);
#endif
	ENUM(LBS_STANDARD);

	// Combo Box return Values
	ENUM(CB_OKAY);
	ENUM(CB_ERR);
	ENUM(CB_ERRSPACE);

	// Combo Box Notification Codes
	ENUM(CBN_ERRSPACE);
	ENUM(CBN_SELCHANGE);
	ENUM(CBN_DBLCLK);
	ENUM(CBN_SETFOCUS);
	ENUM(CBN_KILLFOCUS);
	ENUM(CBN_EDITCHANGE);
	ENUM(CBN_EDITUPDATE);
	ENUM(CBN_DROPDOWN);
	ENUM(CBN_CLOSEUP);
	ENUM(CBN_SELENDOK);
	ENUM(CBN_SELENDCANCEL);

	// Combo Box styles
	ENUM(CBS_SIMPLE);
	ENUM(CBS_DROPDOWN);
	ENUM(CBS_DROPDOWNLIST);
	ENUM(CBS_OWNERDRAWFIXED);
	ENUM(CBS_OWNERDRAWVARIABLE);
	ENUM(CBS_AUTOHSCROLL);
	ENUM(CBS_OEMCONVERT);
	ENUM(CBS_SORT);
	ENUM(CBS_HASSTRINGS);
	ENUM(CBS_NOINTEGRALHEIGHT);
	ENUM(CBS_DISABLENOSCROLL);
	ENUM(CBS_UPPERCASE);
	ENUM(CBS_LOWERCASE);

	// Combo Box messages
	ENUM(CB_GETEDITSEL);
	ENUM(CB_LIMITTEXT);
	ENUM(CB_SETEDITSEL);
	ENUM(CB_ADDSTRING);
	ENUM(CB_DELETESTRING);
	ENUM(CB_DIR);
	ENUM(CB_GETCOUNT);
	ENUM(CB_GETCURSEL);
	ENUM(CB_GETLBTEXT);
	ENUM(CB_GETLBTEXTLEN);
	ENUM(CB_INSERTSTRING);
	ENUM(CB_RESETCONTENT);
	ENUM(CB_FINDSTRING);
	ENUM(CB_SELECTSTRING);
	ENUM(CB_SETCURSEL);
	ENUM(CB_SHOWDROPDOWN);
	ENUM(CB_GETITEMDATA);
	ENUM(CB_SETITEMDATA);
	ENUM(CB_GETDROPPEDCONTROLRECT);
	ENUM(CB_SETITEMHEIGHT);
	ENUM(CB_GETITEMHEIGHT);
	ENUM(CB_SETEXTENDEDUI);
	ENUM(CB_GETEXTENDEDUI);
	ENUM(CB_GETDROPPEDSTATE);
	ENUM(CB_FINDSTRINGEXACT);
	ENUM(CB_SETLOCALE);
	ENUM(CB_GETLOCALE);
	ENUM(CB_GETTOPINDEX);
	ENUM(CB_SETTOPINDEX);
	ENUM(CB_GETHORIZONTALEXTENT);
	ENUM(CB_SETHORIZONTALEXTENT);
	ENUM(CB_GETDROPPEDWIDTH);
	ENUM(CB_SETDROPPEDWIDTH);
	ENUM(CB_INITSTORAGE);
#ifdef   CB_MULTIPLEADDSTRING
	ENUM(CB_MULTIPLEADDSTRING);
#endif
#ifdef   CB_GETCOMBOBOXINFO
	ENUM(CB_GETCOMBOBOXINFO);
#endif
#ifdef   CB_MSGMAX
	ENUM(CB_MSGMAX);
#endif

	// Scroll Bar Styles
	ENUM(SBS_HORZ);
	ENUM(SBS_VERT);
	ENUM(SBS_TOPALIGN);
	ENUM(SBS_LEFTALIGN);
	ENUM(SBS_BOTTOMALIGN);
	ENUM(SBS_RIGHTALIGN);
	ENUM(SBS_SIZEBOXTOPLEFTALIGN);
	ENUM(SBS_SIZEBOXBOTTOMRIGHTALIGN);
	ENUM(SBS_SIZEBOX);
	ENUM(SBS_SIZEGRIP);

	// Scroll bar messages
	ENUM(SBM_SETPOS);
	ENUM(SBM_GETPOS);
	ENUM(SBM_SETRANGE);
	ENUM(SBM_SETRANGEREDRAW);
	ENUM(SBM_GETRANGE);
	ENUM(SBM_ENABLE_ARROWS);
	ENUM(SBM_SETSCROLLINFO);
	ENUM(SBM_GETSCROLLINFO);
#ifdef   SBM_GETSCROLLBARINFO
	ENUM(SBM_GETSCROLLBARINFO);
#endif
	ENUM(SIF_RANGE);
	ENUM(SIF_PAGE);
	ENUM(SIF_POS);
	ENUM(SIF_DISABLENOSCROLL);
	ENUM(SIF_TRACKPOS);
	ENUM(SIF_ALL);

	// Scroll bar option
	ENUM(SB_LINEUP);
	ENUM(SB_LINEUP);
	ENUM(SB_LINELEFT);
	ENUM(SB_LINEDOWN);
	ENUM(SB_LINERIGHT);
	ENUM(SB_PAGEUP);
	ENUM(SB_PAGELEFT);
	ENUM(SB_PAGEDOWN);
	ENUM(SB_PAGERIGHT);
	ENUM(SB_THUMBPOSITION);
	ENUM(SB_THUMBTRACK);
	ENUM(SB_TOP);
	ENUM(SB_LEFT);
	ENUM(SB_BOTTOM);
	ENUM(SB_RIGHT);
	ENUM(SB_ENDSCROLL);

	// Font Weights
	ENUM(FW_DONTCARE);
	ENUM(FW_THIN);
	ENUM(FW_EXTRALIGHT);
	ENUM(FW_LIGHT);
	ENUM(FW_NORMAL);
	ENUM(FW_MEDIUM);
	ENUM(FW_SEMIBOLD);
	ENUM(FW_BOLD);
	ENUM(FW_EXTRABOLD);
	ENUM(FW_HEAVY);

	// ShowWindow options
	ENUM(SW_HIDE);
	ENUM(SW_SHOWNORMAL);
	ENUM(SW_NORMAL);
	ENUM(SW_SHOWMINIMIZED);
	ENUM(SW_SHOWMAXIMIZED);
	ENUM(SW_MAXIMIZE);
	ENUM(SW_SHOWNOACTIVATE);
	ENUM(SW_SHOW);
	ENUM(SW_MINIMIZE);
	ENUM(SW_SHOWMINNOACTIVE);
	ENUM(SW_SHOWNA);
	ENUM(SW_RESTORE);
	ENUM(SW_SHOWDEFAULT);
	ENUM(SW_FORCEMINIMIZE);

	// Control classes
	Variant(TJS_W("BUTTON"),    0x0080, 0);
	Variant(TJS_W("EDIT"),      0x0081, 0);
	Variant(TJS_W("STATIC"),    0x0082, 0);
	Variant(TJS_W("LISTBOX"),   0x0083, 0);
	Variant(TJS_W("SCROLLBAR"), 0x0084, 0);
	Variant(TJS_W("COMBOBOX"),  0x0085, 0);

	// for MessageBox
	ENUM(MB_ABORTRETRYIGNORE);
	ENUM(MB_CANCELTRYCONTINUE);
	ENUM(MB_HELP);
	ENUM(MB_OK);
	ENUM(MB_OKCANCEL);
	ENUM(MB_RETRYCANCEL);
	ENUM(MB_YESNO);
	ENUM(MB_YESNOCANCEL);
	ENUM(MB_ICONEXCLAMATION);
	ENUM(MB_ICONWARNING);
	ENUM(MB_ICONINFORMATION);
	ENUM(MB_ICONASTERISK);
	ENUM(MB_ICONQUESTION);
	ENUM(MB_ICONSTOP);
	ENUM(MB_ICONERROR);
	ENUM(MB_ICONHAND);
	ENUM(MB_DEFBUTTON1);
	ENUM(MB_DEFBUTTON2);
	ENUM(MB_DEFBUTTON3);
	ENUM(MB_DEFBUTTON4);
	ENUM(MB_APPLMODAL);
	ENUM(MB_SYSTEMMODAL);
	ENUM(MB_TASKMODAL);
	ENUM(MB_DEFAULT_DESKTOP_ONLY);
	ENUM(MB_RIGHT);
	ENUM(MB_RTLREADING);
	ENUM(MB_SETFOREGROUND);
	ENUM(MB_TOPMOST);
#ifdef   MB_SERVICE_NOTIFICATION
	ENUM(MB_SERVICE_NOTIFICATION);
#endif
#ifdef   MB_SERVICE_NOTIFICATION_NT3X
	ENUM(MB_SERVICE_NOTIFICATION_NT3X);
#endif

	ENUM(MB_OWNER_CENTER);

	Method(TJS_W("messageBox"), &Class::MessageBox);


	// InitCommonControlsEx parameters
	ENUM(ICC_LISTVIEW_CLASSES);
	ENUM(ICC_TREEVIEW_CLASSES);
	ENUM(ICC_BAR_CLASSES);
	ENUM(ICC_TAB_CLASSES);
	ENUM(ICC_UPDOWN_CLASS);
	ENUM(ICC_PROGRESS_CLASS);
	ENUM(ICC_HOTKEY_CLASS);
	ENUM(ICC_ANIMATE_CLASS);
	ENUM(ICC_WIN95_CLASSES);
	ENUM(ICC_DATE_CLASSES);
	ENUM(ICC_USEREX_CLASSES);
	ENUM(ICC_COOL_CLASSES);
#ifdef   ICC_INTERNET_CLASSES
	ENUM(ICC_INTERNET_CLASSES);
	ENUM(ICC_PAGESCROLLER_CLASS);
	ENUM(ICC_NATIVEFNTCTL_CLASS);
#endif
#ifdef   ICC_STANDARD_CLASSES
	ENUM(ICC_STANDARD_CLASSES);
	ENUM(ICC_LINK_CLASS);
#endif

	Variant(TJS_W("HEADER"),         WC_HEADERA, 0);			// "SysHeader32"
#ifdef WC_LINK
	Variant(TJS_W("LINK"),           WC_LINK, 0);				// "SysLink"
#endif
	Variant(TJS_W("LISTVIEW"),       WC_LISTVIEWA, 0);			// "SysListView32"
	Variant(TJS_W("TREEVIEW"),       WC_TREEVIEWA, 0);			// "SysTreeView32"
	Variant(TJS_W("TABCONTROL"),     WC_TABCONTROLA, 0);		// "SysTabControl32"
	Variant(TJS_W("IPADDRESS"),      WC_IPADDRESSA, 0);			// "SysIPAddress32"
	Variant(TJS_W("PAGESCROLLER"),   WC_PAGESCROLLERA, 0);		// "SysPager"
	Variant(TJS_W("ANIMATE"),        ANIMATE_CLASSA, 0);		// "SysAnimate32"
	Variant(TJS_W("MONTHCAL"),       MONTHCAL_CLASSA, 0);		// "SysMonthCal32"
	Variant(TJS_W("DATETIMEPICK"),   DATETIMEPICK_CLASSA, 0);	// "SysDateTimePick32"

	Variant(TJS_W("COMBOBOXEX"),     WC_COMBOBOXEXA, 0);		// "ComboBoxEx32"
	Variant(TJS_W("NATIVEFONTCTL"),  WC_NATIVEFONTCTLA, 0);		// "NativeFontCtl"
	Variant(TJS_W("TOOLBAR"),        TOOLBARCLASSNAMEA, 0);		// "ToolbarWindow32"
	Variant(TJS_W("REBAR"),          REBARCLASSNAMEA, 0);		// "ReBarWindow32"
	Variant(TJS_W("TOOLTIPS"),       TOOLTIPS_CLASSA, 0);		// "tooltips_class32"

	Variant(TJS_W("STATUS"),         STATUSCLASSNAMEA, 0);		// "msctls_statusbar32"
	Variant(TJS_W("TRACKBAR"),       TRACKBAR_CLASSA, 0);		// "msctls_trackbar32"
	Variant(TJS_W("UPDOWN"),         UPDOWN_CLASSA, 0);			// "msctls_updown32"
	Variant(TJS_W("PROGRESS"),       PROGRESS_CLASSA, 0);		// "msctls_progress32"
	Variant(TJS_W("HOTKEY"),         HOTKEY_CLASSA, 0);			// "msctls_hotkey32"

	// [XXX] コモンコントロールのメッセージ用ENUMが必要
	// 取り急ぎトラックバー・プログレス・リストビュー・タブコントロールのみ

	// Trackbar Styles
	ENUM(TBS_AUTOTICKS);
	ENUM(TBS_VERT);
	ENUM(TBS_HORZ);
	ENUM(TBS_TOP);
	ENUM(TBS_BOTTOM);
	ENUM(TBS_LEFT);
	ENUM(TBS_RIGHT);
	ENUM(TBS_BOTH);
	ENUM(TBS_NOTICKS);
	ENUM(TBS_ENABLESELRANGE);
	ENUM(TBS_FIXEDLENGTH);
	ENUM(TBS_NOTHUMB);
#ifdef   TBS_TOOLTIPS
	ENUM(TBS_TOOLTIPS);
#endif
#ifdef   TBS_REVERSED
	ENUM(TBS_REVERSED);
#endif
#ifdef   TBS_DOWNISLEFT
	ENUM(TBS_DOWNISLEFT);
#endif

#ifdef   TBS_NOTIFYBEFOREMOVE
	ENUM(TBS_NOTIFYBEFOREMOVE);
#endif
#ifdef   TBS_TRANSPARENTBKGND
	ENUM(TBS_TRANSPARENTBKGND);
#endif
	// Trackbar Messages
	ENUM(TBM_GETPOS);
	ENUM(TBM_GETRANGEMIN);
	ENUM(TBM_GETRANGEMAX);
	ENUM(TBM_GETTIC);
	ENUM(TBM_SETTIC);
	ENUM(TBM_SETPOS);
	ENUM(TBM_SETRANGE);
	ENUM(TBM_SETRANGEMIN);
	ENUM(TBM_SETRANGEMAX);
	ENUM(TBM_CLEARTICS);
	ENUM(TBM_SETSEL);
	ENUM(TBM_SETSELSTART);
	ENUM(TBM_SETSELEND);
	ENUM(TBM_GETPTICS);
	ENUM(TBM_GETTICPOS);
	ENUM(TBM_GETNUMTICS);
	ENUM(TBM_GETSELSTART);
	ENUM(TBM_GETSELEND);
	ENUM(TBM_CLEARSEL);
	ENUM(TBM_SETTICFREQ);
	ENUM(TBM_SETPAGESIZE);
	ENUM(TBM_GETPAGESIZE);
	ENUM(TBM_SETLINESIZE);
	ENUM(TBM_GETLINESIZE);
	ENUM(TBM_GETTHUMBRECT);
	ENUM(TBM_GETCHANNELRECT);
	ENUM(TBM_SETTHUMBLENGTH);
	ENUM(TBM_GETTHUMBLENGTH);
#ifdef   TBM_SETTOOLTIPS
	ENUM(TBM_SETTOOLTIPS);
	ENUM(TBM_GETTOOLTIPS);
	ENUM(TBM_SETTIPSIDE);
	// TrackBar Tip Side flags
	ENUM(TBTS_TOP);
	ENUM(TBTS_LEFT);
	ENUM(TBTS_BOTTOM);
	ENUM(TBTS_RIGHT);

	ENUM(TBM_SETBUDDY);
	ENUM(TBM_GETBUDDY);
#endif
#ifdef   TBM_SETUNICODEFORMAT
	ENUM(TBM_SETUNICODEFORMAT);
	ENUM(TBM_GETUNICODEFORMAT);
#endif
	ENUM(TB_LINEUP);
	ENUM(TB_LINEDOWN);
	ENUM(TB_PAGEUP);
	ENUM(TB_PAGEDOWN);
	ENUM(TB_THUMBPOSITION);
	ENUM(TB_THUMBTRACK);
	ENUM(TB_TOP);
	ENUM(TB_BOTTOM);
	ENUM(TB_ENDTRACK);
#ifdef   TBCD_TICS
	ENUM(TBCD_TICS);
	ENUM(TBCD_THUMB);
	ENUM(TBCD_CHANNEL);
#endif
#ifdef   TRBN_THUMBPOSCHANGING
	ENUM(TRBN_THUMBPOSCHANGING);
#endif

	// Progress
#ifdef   PBS_SMOOTH
	ENUM(PBS_SMOOTH);
	ENUM(PBS_VERTICAL);
#endif
	ENUM(PBM_SETRANGE);
	ENUM(PBM_SETPOS);
	ENUM(PBM_DELTAPOS);
	ENUM(PBM_SETSTEP);
	ENUM(PBM_STEPIT);
//	ENUM(PBM_SETRANGE32);
	ENUM(PBM_GETRANGE);
	ENUM(PBM_GETPOS);
#ifdef   PBM_SETBARCOLOR
	ENUM(PBM_SETBARCOLOR);
#endif
#ifdef   PBM_SETBKCOLOR
	ENUM(PBM_SETBKCOLOR);
#endif
#ifdef   PBS_MARQUEE
	ENUM(PBS_MARQUEE);
	ENUM(PBM_SETMARQUEE);
#endif
#ifdef   PBS_SMOOTHREVERSE
	ENUM(PBS_SMOOTHREVERSE);
	ENUM(PBM_GETSTEP);
	ENUM(PBM_GETBKCOLOR);
	ENUM(PBM_GETBARCOLOR);
	ENUM(PBM_SETSTATE);
	ENUM(PBM_GETSTATE);
	ENUM(PBST_NORMAL);
	ENUM(PBST_ERROR);
	ENUM(PBST_PAUSED);
#endif

	// ListView
	ENUM(LVS_ICON);
	ENUM(LVS_REPORT);
	ENUM(LVS_SMALLICON);
	ENUM(LVS_LIST);
	ENUM(LVS_TYPEMASK);
	ENUM(LVS_SINGLESEL);
	ENUM(LVS_SHOWSELALWAYS);
	ENUM(LVS_SORTASCENDING);
	ENUM(LVS_SORTDESCENDING);
	ENUM(LVS_SHAREIMAGELISTS);
	ENUM(LVS_NOLABELWRAP);
	ENUM(LVS_AUTOARRANGE);
	ENUM(LVS_EDITLABELS);
	ENUM(LVS_OWNERDATA);
	ENUM(LVS_NOSCROLL);
	ENUM(LVS_TYPESTYLEMASK);
	ENUM(LVS_ALIGNTOP);
	ENUM(LVS_ALIGNLEFT);
	ENUM(LVS_ALIGNMASK);
	ENUM(LVS_OWNERDRAWFIXED);
	ENUM(LVS_NOCOLUMNHEADER);
	ENUM(LVS_NOSORTHEADER);
	ENUM(LVS_EX_GRIDLINES);
	ENUM(LVS_EX_SUBITEMIMAGES);
	ENUM(LVS_EX_CHECKBOXES);
	ENUM(LVS_EX_TRACKSELECT);
	ENUM(LVS_EX_HEADERDRAGDROP);
	ENUM(LVS_EX_FULLROWSELECT);
	ENUM(LVS_EX_ONECLICKACTIVATE);
	ENUM(LVS_EX_TWOCLICKACTIVATE);
	ENUM(LVS_EX_FLATSB);
	ENUM(LVS_EX_REGIONAL);
	ENUM(LVS_EX_INFOTIP);
	ENUM(LVS_EX_UNDERLINEHOT);
	ENUM(LVS_EX_UNDERLINECOLD);
	ENUM(LVS_EX_MULTIWORKAREAS);
	ENUM(LVS_EX_LABELTIP);
	ENUM(LVS_EX_BORDERSELECT);
	ENUM(LVS_EX_DOUBLEBUFFER);
	ENUM(LVS_EX_HIDELABELS);
	ENUM(LVS_EX_SINGLEROW);
	ENUM(LVS_EX_SNAPTOGRID);
	ENUM(LVS_EX_SIMPLESELECT);
	ENUM(LVS_EX_JUSTIFYCOLUMNS);
	ENUM(LVS_EX_TRANSPARENTBKGND);
	ENUM(LVS_EX_TRANSPARENTSHADOWTEXT);
	ENUM(LVS_EX_AUTOAUTOARRANGE);
	ENUM(LVS_EX_HEADERINALLVIEWS);
	ENUM(LVS_EX_AUTOCHECKSELECT);
	ENUM(LVS_EX_AUTOSIZECOLUMNS);
	ENUM(LVS_EX_COLUMNSNAPPOINTS);
	ENUM(LVS_EX_COLUMNOVERFLOW);

	ENUM(LVM_FIRST);
	ENUM(LVM_GETBKCOLOR);
	ENUM(LVM_SETBKCOLOR);
	ENUM(LVM_GETIMAGELIST);
	ENUM(LVM_SETIMAGELIST);
	ENUM(LVM_GETITEMCOUNT);
	ENUM(LVM_GETITEMA);
	ENUM(LVM_GETITEMW);
	ENUM(LVM_SETITEMA);
	ENUM(LVM_SETITEMW);
	ENUM(LVM_INSERTITEMA);
	ENUM(LVM_INSERTITEMW);
	ENUM(LVM_DELETEITEM);
	ENUM(LVM_DELETEALLITEMS);
	ENUM(LVM_GETCALLBACKMASK);
	ENUM(LVM_SETCALLBACKMASK);
	ENUM(LVM_GETNEXTITEM);
	ENUM(LVM_FINDITEMA);
	ENUM(LVM_FINDITEMW);
	ENUM(LVM_GETITEMRECT);
	ENUM(LVM_SETITEMPOSITION);
	ENUM(LVM_GETITEMPOSITION);
	ENUM(LVM_GETSTRINGWIDTHA);
	ENUM(LVM_GETSTRINGWIDTHW);
	ENUM(LVM_HITTEST);
	ENUM(LVM_ENSUREVISIBLE);
	ENUM(LVM_SCROLL);
	ENUM(LVM_REDRAWITEMS);
	ENUM(LVM_ARRANGE);
	ENUM(LVM_EDITLABELA);
	ENUM(LVM_EDITLABELW);
	ENUM(LVM_GETEDITCONTROL);
	ENUM(LVM_GETCOLUMNA);
	ENUM(LVM_GETCOLUMNW);
	ENUM(LVM_SETCOLUMNA);
	ENUM(LVM_SETCOLUMNW);
	ENUM(LVM_INSERTCOLUMNA);
	ENUM(LVM_INSERTCOLUMNW);
	ENUM(LVM_DELETECOLUMN);
	ENUM(LVM_GETCOLUMNWIDTH);
	ENUM(LVM_SETCOLUMNWIDTH);
	ENUM(LVM_GETHEADER);
	ENUM(LVM_CREATEDRAGIMAGE);
	ENUM(LVM_GETVIEWRECT);
	ENUM(LVM_GETTEXTCOLOR);
	ENUM(LVM_SETTEXTCOLOR);
	ENUM(LVM_GETTEXTBKCOLOR);
	ENUM(LVM_SETTEXTBKCOLOR);
	ENUM(LVM_GETTOPINDEX);
	ENUM(LVM_GETCOUNTPERPAGE);
	ENUM(LVM_GETORIGIN);
	ENUM(LVM_UPDATE);
	ENUM(LVM_SETITEMSTATE);
	ENUM(LVM_GETITEMSTATE);
	ENUM(LVM_GETITEMTEXTA);
	ENUM(LVM_GETITEMTEXTW);
	ENUM(LVM_SETITEMTEXTA);
	ENUM(LVM_SETITEMTEXTW);
	ENUM(LVM_SETITEMCOUNT);
	ENUM(LVM_SORTITEMS);
	ENUM(LVM_SETITEMPOSITION32);
	ENUM(LVM_GETSELECTEDCOUNT);
	ENUM(LVM_GETITEMSPACING);
	ENUM(LVM_GETISEARCHSTRINGA);
	ENUM(LVM_GETISEARCHSTRINGW);
	ENUM(LVM_SETICONSPACING);
	ENUM(LVM_SETEXTENDEDLISTVIEWSTYLE);
	ENUM(LVM_GETEXTENDEDLISTVIEWSTYLE);
	ENUM(LVM_GETSUBITEMRECT);
	ENUM(LVM_SUBITEMHITTEST);
	ENUM(LVM_SETCOLUMNORDERARRAY);
	ENUM(LVM_GETCOLUMNORDERARRAY);
	ENUM(LVM_SETHOTITEM);
	ENUM(LVM_GETHOTITEM);
	ENUM(LVM_SETHOTCURSOR);
	ENUM(LVM_GETHOTCURSOR);
	ENUM(LVM_APPROXIMATEVIEWRECT);
	ENUM(LVM_SETWORKAREAS);
	ENUM(LVM_GETWORKAREAS);
	ENUM(LVM_GETNUMBEROFWORKAREAS);
	ENUM(LVM_GETSELECTIONMARK);
	ENUM(LVM_SETSELECTIONMARK);
	ENUM(LVM_SETHOVERTIME);
	ENUM(LVM_GETHOVERTIME);
	ENUM(LVM_SETTOOLTIPS);
	ENUM(LVM_GETTOOLTIPS);
	ENUM(LVM_SORTITEMSEX);
	ENUM(LVM_SETBKIMAGEA);
	ENUM(LVM_SETBKIMAGEW);
	ENUM(LVM_GETBKIMAGEA);
	ENUM(LVM_GETBKIMAGEW);
	ENUM(LVM_SETSELECTEDCOLUMN);
	ENUM(LVM_SETVIEW);
	ENUM(LVM_GETVIEW);
	ENUM(LVM_INSERTGROUP);
	ENUM(LVM_SETGROUPINFO);
	ENUM(LVM_GETGROUPINFO);
	ENUM(LVM_REMOVEGROUP);
	ENUM(LVM_MOVEGROUP);
	ENUM(LVM_GETGROUPCOUNT);
	ENUM(LVM_GETGROUPINFOBYINDEX);
	ENUM(LVM_MOVEITEMTOGROUP);
	ENUM(LVM_GETGROUPRECT);
	ENUM(LVM_SETGROUPMETRICS);
	ENUM(LVM_GETGROUPMETRICS);
	ENUM(LVM_ENABLEGROUPVIEW);
	ENUM(LVM_SORTGROUPS);
	ENUM(LVM_INSERTGROUPSORTED);
	ENUM(LVM_REMOVEALLGROUPS);
	ENUM(LVM_HASGROUP);
	ENUM(LVM_GETGROUPSTATE);
	ENUM(LVM_GETFOCUSEDGROUP);
	ENUM(LVM_SETTILEVIEWINFO);
	ENUM(LVM_GETTILEVIEWINFO);
	ENUM(LVM_SETTILEINFO);
	ENUM(LVM_GETTILEINFO);
	ENUM(LVM_SETINSERTMARK);
	ENUM(LVM_GETINSERTMARK);
	ENUM(LVM_INSERTMARKHITTEST);
	ENUM(LVM_GETINSERTMARKRECT);
	ENUM(LVM_SETINSERTMARKCOLOR);
	ENUM(LVM_GETINSERTMARKCOLOR);
	ENUM(LVM_GETSELECTEDCOLUMN);
	ENUM(LVM_ISGROUPVIEWENABLED);
	ENUM(LVM_GETOUTLINECOLOR);
	ENUM(LVM_SETOUTLINECOLOR);
	ENUM(LVM_CANCELEDITLABEL);
	ENUM(LVM_MAPINDEXTOID);
	ENUM(LVM_MAPIDTOINDEX);
	ENUM(LVM_ISITEMVISIBLE);
	ENUM(LVM_GETEMPTYTEXT);
	ENUM(LVM_GETFOOTERRECT);
	ENUM(LVM_GETFOOTERINFO);
	ENUM(LVM_GETFOOTERITEMRECT);
	ENUM(LVM_GETFOOTERITEM);
	ENUM(LVM_GETITEMINDEXRECT);
	ENUM(LVM_SETITEMINDEXSTATE);
	ENUM(LVM_GETNEXTITEMINDEX);

	ENUM(LVM_SETUNICODEFORMAT);
	ENUM(LVM_GETUNICODEFORMAT);

	// 〜A/W場合分け
	//ENUM(LVM_GETITEM);
	//ENUM(LVM_SETITEM);
	//ENUM(LVM_INSERTITEM);
	//ENUM(LVM_EDITLABEL);
	//ENUM(LVM_GETISEARCHSTRING);
	//ENUM(LVM_SETBKIMAGE);
	//ENUM(LVM_GETBKIMAGE);

	ENUM(LVNI_ALL);
	ENUM(LVNI_FOCUSED);
	ENUM(LVNI_SELECTED);
	ENUM(LVNI_CUT);
	ENUM(LVNI_DROPHILITED);
	ENUM(LVNI_STATEMASK);
	ENUM(LVNI_VISIBLEORDER);
	ENUM(LVNI_PREVIOUS);
	ENUM(LVNI_VISIBLEONLY);
	ENUM(LVNI_SAMEGROUPONLY);
	ENUM(LVNI_ABOVE);
	ENUM(LVNI_BELOW);
	ENUM(LVNI_TOLEFT);
	ENUM(LVNI_TORIGHT);
	ENUM(LVNI_DIRECTIONMASK);

	ENUM(LVN_ITEMCHANGING);
	ENUM(LVN_ITEMCHANGED);
	ENUM(LVN_INSERTITEM);
	ENUM(LVN_DELETEITEM);
	ENUM(LVN_DELETEALLITEMS);
	ENUM(LVN_BEGINLABELEDITA);
	ENUM(LVN_BEGINLABELEDITW);
	ENUM(LVN_ENDLABELEDITA);
	ENUM(LVN_ENDLABELEDITW);
	ENUM(LVN_COLUMNCLICK);
	ENUM(LVN_BEGINDRAG);
	ENUM(LVN_BEGINRDRAG);
	ENUM(LVN_ODCACHEHINT);
	ENUM(LVN_ODFINDITEMA);
	ENUM(LVN_ODFINDITEMW);
	ENUM(LVN_ITEMACTIVATE);
	ENUM(LVN_ODSTATECHANGED);
	ENUM(LVN_HOTTRACK);
	ENUM(LVN_GETDISPINFOA);
	ENUM(LVN_GETDISPINFOW);
	ENUM(LVN_SETDISPINFOA);
	ENUM(LVN_SETDISPINFOW);
	ENUM(LVN_KEYDOWN);
	ENUM(LVN_MARQUEEBEGIN);
	ENUM(LVN_GETINFOTIPA);
	ENUM(LVN_GETINFOTIPW);
	ENUM(LVN_INCREMENTALSEARCHA);
	ENUM(LVN_INCREMENTALSEARCHW);
	ENUM(LVN_COLUMNDROPDOWN);
	ENUM(LVN_COLUMNOVERFLOWCLICK);
	ENUM(LVN_BEGINSCROLL);
	ENUM(LVN_ENDSCROLL);
	ENUM(LVN_LINKCLICK);
	ENUM(LVN_GETEMPTYMARKUP);

	// 〜A/W場合分け
	//ENUM(LVN_ODFINDITEM);
	//ENUM(LVN_BEGINLABELEDIT);
	//ENUM(LVN_ENDLABELEDIT);
	//ENUM(LVN_GETDISPINFO);
	//ENUM(LVN_SETDISPINFO);
	//ENUM(LVN_GETINFOTIP);
	//ENUM(LVN_INCREMENTALSEARCH);

	// TabControl Styles
	ENUM(TCS_SCROLLOPPOSITE);
	ENUM(TCS_BOTTOM);
	ENUM(TCS_RIGHT);
	ENUM(TCS_MULTISELECT);
	ENUM(TCS_FLATBUTTONS);
	ENUM(TCS_FORCEICONLEFT);
	ENUM(TCS_FORCELABELLEFT);
	ENUM(TCS_HOTTRACK);
	ENUM(TCS_VERTICAL);
	ENUM(TCS_TABS);
	ENUM(TCS_BUTTONS);
	ENUM(TCS_SINGLELINE);
	ENUM(TCS_MULTILINE);
	ENUM(TCS_RIGHTJUSTIFY);
	ENUM(TCS_FIXEDWIDTH);
	ENUM(TCS_RAGGEDRIGHT);
	ENUM(TCS_FOCUSONBUTTONDOWN);
	ENUM(TCS_OWNERDRAWFIXED);
	ENUM(TCS_TOOLTIPS);
	ENUM(TCS_FOCUSNEVER);
	ENUM(TCS_EX_FLATSEPARATORS);
	ENUM(TCS_EX_REGISTERDROP);

	// TabControl Messages
	ENUM(TCM_GETIMAGELIST);
	ENUM(TCM_SETIMAGELIST);
	ENUM(TCM_GETITEMCOUNT);
	ENUM(TCIF_TEXT);
	ENUM(TCIF_IMAGE);
	ENUM(TCIF_RTLREADING);
	ENUM(TCIF_PARAM);
	ENUM(TCIF_STATE);
	ENUM(TCIS_BUTTONPRESSED);
	ENUM(TCIS_HIGHLIGHTED);

	// use WideCharVersion Macro
	Variant(TJS_W("TCM_GETITEM"),    TCM_GETITEMW, 0);
	Variant(TJS_W("TCM_SETITEM"),    TCM_SETITEMW, 0);
	Variant(TJS_W("TCM_INSERTITEM"), TCM_INSERTITEMW, 0);

	ENUM(TCM_DELETEITEM);
	ENUM(TCM_DELETEALLITEMS);
	ENUM(TCM_GETITEMRECT);
	ENUM(TCM_GETCURSEL);
	ENUM(TCM_SETCURSEL);
	ENUM(TCHT_NOWHERE);
	ENUM(TCHT_ONITEMICON);
	ENUM(TCHT_ONITEMLABEL);
	ENUM(TCHT_ONITEM);

	ENUM(TCM_HITTEST);
	ENUM(TCM_SETITEMEXTRA);
	ENUM(TCM_ADJUSTRECT);
	ENUM(TCM_SETITEMSIZE);
	ENUM(TCM_REMOVEIMAGE);
	ENUM(TCM_SETPADDING);
	ENUM(TCM_GETROWCOUNT);
	ENUM(TCM_GETTOOLTIPS);
	ENUM(TCM_SETTOOLTIPS);
	ENUM(TCM_GETCURFOCUS);
	ENUM(TCM_SETCURFOCUS);
	ENUM(TCM_SETMINTABWIDTH);
	ENUM(TCM_DESELECTALL);
	ENUM(TCM_HIGHLIGHTITEM);
	ENUM(TCM_SETEXTENDEDSTYLE);
	ENUM(TCM_GETEXTENDEDSTYLE);
	ENUM(TCM_SETUNICODEFORMAT);
	ENUM(TCM_GETUNICODEFORMAT);

	// TabControl Notification
	ENUM(TCN_KEYDOWN);
	ENUM(TCN_SELCHANGE);
	ENUM(TCN_SELCHANGING);
	ENUM(TCN_GETOBJECT);
	ENUM(TCN_FOCUSCHANGE);

	// sizeof item structs
	// XXX 64bitでエラー。いったんコメントアウト
	//Variant(TJS_W("SIZEOF_TC_ITEMHEADER"), (tTVInteger)sizeof(TC_ITEMHEADERW), 0);
	//Variant(TJS_W("SIZEOF_TC_ITEM"),       (tTVInteger)sizeof(TC_ITEMW), 0);


	////////////////
	// OwnerDraw用
	ENUM(ODT_BUTTON);
	ENUM(ODT_COMBOBOX);
	ENUM(ODT_LISTBOX);
	ENUM(ODT_MENU);
	ENUM(ODT_LISTVIEW);
	ENUM(ODT_STATIC);
	ENUM(ODT_TAB);

	ENUM(ODA_DRAWENTIRE);
	ENUM(ODA_FOCUS);
	ENUM(ODA_SELECT);

	ENUM(ODS_CHECKED);
	ENUM(ODS_DISABLED);
	ENUM(ODS_FOCUS);
	ENUM(ODS_GRAYED);
	ENUM(ODS_SELECTED);
	ENUM(ODS_COMBOBOXEDIT);
	ENUM(ODS_DEFAULT);

	Method(TJS_W("initCommonControls"),   &Class::InitCommonControls);
	Method(TJS_W("initCommonControlsEx"), &Class::InitCommonControlsEx);

	Method(TJS_W("getOctetAddress"),      &Class::GetOctetAddress);
	Method(TJS_W("getStringAddress"),     &Class::GetStringAddress);

	RawCallback(TJS_W("chooseColor"), &Class::chooseColor, TJS_STATICMEMBER);


	////////////////
	// PropertySheet用

	ENUM(PSN_SETACTIVE);
	ENUM(PSN_KILLACTIVE);
	ENUM(PSN_APPLY);
	ENUM(PSN_RESET);
	ENUM(PSN_HELP);
	ENUM(PSN_WIZBACK);
	ENUM(PSN_WIZNEXT);
	ENUM(PSN_WIZFINISH);
	ENUM(PSN_QUERYCANCEL);
#ifdef   PSN_GETOBJECT
	ENUM(PSN_GETOBJECT);
#endif
#ifdef   PSN_TRANSLATEACCELERATOR
	ENUM(PSN_TRANSLATEACCELERATOR);
	ENUM(PSN_QUERYINITIALFOCUS);
#endif

	ENUM(PSNRET_NOERROR);
	ENUM(PSNRET_INVALID);
	ENUM(PSNRET_INVALID_NOCHANGEPAGE);
	ENUM(PSNRET_MESSAGEHANDLED);

	ENUM(PSM_SETCURSEL);
	ENUM(PSM_REMOVEPAGE);
	ENUM(PSM_ADDPAGE);
	ENUM(PSM_CHANGED);
	ENUM(PSM_RESTARTWINDOWS);
	ENUM(PSM_REBOOTSYSTEM);
	ENUM(PSM_CANCELTOCLOSE);
	ENUM(PSM_QUERYSIBLINGS);
	ENUM(PSM_UNCHANGED);
	ENUM(PSM_APPLY);
	ENUM(PSM_SETTITLE);
	ENUM(PSM_SETWIZBUTTONS);
	ENUM(PSM_PRESSBUTTON);
	ENUM(PSM_SETCURSELID);
	ENUM(PSM_SETFINISHTEXT);
	ENUM(PSM_GETTABCONTROL);
	ENUM(PSM_ISDIALOGMESSAGE);
	ENUM(PSM_GETCURRENTPAGEHWND);
	ENUM(PSM_INSERTPAGE);
#ifdef   PSM_SETHEADERTITLE
	ENUM(PSM_SETHEADERTITLE);
	ENUM(PSM_SETHEADERSUBTITLE);
	ENUM(PSM_HWNDTOINDEX);
	ENUM(PSM_INDEXTOHWND);
	ENUM(PSM_PAGETOINDEX);
	ENUM(PSM_INDEXTOPAGE);
	ENUM(PSM_IDTOINDEX);
	ENUM(PSM_INDEXTOID);
	ENUM(PSM_GETRESULT);
	ENUM(PSM_RECALCPAGESIZES);
#endif
#ifdef   PSM_SETNEXTTEXT
	ENUM(PSM_SETNEXTTEXT);
	ENUM(PSM_SHOWWIZBUTTONS);
	ENUM(PSM_ENABLEWIZBUTTONS);
	ENUM(PSM_SETBUTTONTEXT);
#endif
#ifdef   PSM_SETHEADERBITMAP
	ENUM(PSM_SETHEADERBITMAP);
	ENUM(PSM_SETHEADERBITMAPRESOURCE);
#endif

	ENUM(PSWIZB_BACK);
	ENUM(PSWIZB_NEXT);
	ENUM(PSWIZB_FINISH);
	ENUM(PSWIZB_DISABLEDFINISH);
	// ENUM(PSWIZBF_ELEVATIONREQUIRED);
#ifdef   PSWIZB_CANCEL
	ENUM(PSWIZB_CANCEL);
	ENUM(PSWIZB_SHOW);
	ENUM(PSWIZB_RESTORE);
#endif
#ifdef   PSWIZF_SETCOLOR
	ENUM(PSWIZF_SETCOLOR);
#endif

	ENUM(PSBTN_BACK);
	ENUM(PSBTN_NEXT);
	ENUM(PSBTN_FINISH);
	ENUM(PSBTN_OK);
	ENUM(PSBTN_APPLYNOW);
	ENUM(PSBTN_CANCEL);
	ENUM(PSBTN_HELP);
	ENUM(PSBTN_MAX);

	ENUM(ID_PSRESTARTWINDOWS);
	ENUM(ID_PSREBOOTSYSTEM);

	ENUM(WIZ_CXDLG);
	ENUM(WIZ_CYDLG);
	ENUM(WIZ_CXBMP);
	ENUM(WIZ_BODYX);
	ENUM(WIZ_BODYCX);

	ENUM(PROP_SM_CXDLG);
	ENUM(PROP_SM_CYDLG);
	ENUM(PROP_MED_CXDLG);
	ENUM(PROP_MED_CYDLG);
	ENUM(PROP_LG_CXDLG);
	ENUM(PROP_LG_CYDLG);

	Method(TJS_W("openPropertySheet"), &Class::OpenPropertySheet);
	Method(TJS_W("propSheetMessage"),  &Class::propSheetMessage);
	Method(TJS_W("setMessageResult"),  &Class::setMessageResult);
	Property(TJS_W("propsheet"),       &Class::isPropertySheet, 0);

	////////////////
	// TabControl用
#define U_ENUM(n) Variant(#n, (unsigned long)n, 0)
	U_ENUM(TCN_SELCHANGE);	//	GetCode で得られる値はUINTだがTCN_SELCHANGE はマイナスのため、ENUM を使うとそのままでは比較できない
	U_ENUM(TCN_SELCHANGING);
#ifdef TCN_GETOBJECT
	U_ENUM(TCN_GETOBJECT);
#endif
#ifdef TCN_FOCUSCHANGE
	U_ENUM(TCN_FOCUSCHANGE);
#endif
	U_ENUM(TCN_KEYDOWN);

	Method(TJS_W("insertTab"),    &Class::InsertTabItem);
	Method(TJS_W("deleteTab"),    &Class::DeleteTabItem);
	Method(TJS_W("deleteAllTab"), &Class::DeleteAllTabItem);
	Method(TJS_W("getCurSel"),    &Class::GetCurSelTab);
	Method(TJS_W("setCurSel"),    &Class::SetCurSelTab);
	Method(TJS_W("selectTab"),    &Class::SelectTab);

	////////////////
	// Progress用

	RawCallback(TJS_W("openProgress"),  &Class::openProgress, 0);
	Property(TJS_W("progress"),         &Class::isProgress, (int)0);
	Property(TJS_W("progressValue"),    &Class::getProgressValue,    &Class::setProgressValue   );
	Property(TJS_W("progressCanceled"), &Class::getProgressCanceled, &Class::setProgressCanceled);
	Method(TJS_W("closeProgress"),      &Class::closeProgress);

	////////////////
	// スクロールバー用

	Method(TJS_W("getScrollInfo"), &Class::getScrollInfo);
	RawCallback(TJS_W("setScrollInfo"), &Class::setScrollInfo, 0);

	////////////////
	// ウィンドウ位置など
	Method(TJS_W("bringToFront"), &Class::BringToFront);
}
