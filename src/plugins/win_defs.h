#pragma once

#include "win32_dt.h"

#define TRUE    1
#define FALSE   0
#define INFINITE            0xFFFFFFFF  // Infinite timeout

#define WPARAM unsigned int
#define LONG_PTR long
#define LPARAM long
#define LRESULT LONG_PTR
#define ULONG_PTR unsigned long
#define ATOM WORD

#ifndef _WIN32
typedef /* [wire_marshal] */ void *HWND;
typedef /* [wire_marshal] */ void *HBRUSH;
typedef /* [wire_marshal] */ void *HDC;
typedef /* [wire_marshal] */ void *HMONITOR;
typedef struct RECT__ *RECT;
typedef struct DRAWITEMSTRUCT__ *DRAWITEMSTRUCT;
typedef struct NMHDR__ *NMHDR;
#endif

typedef struct HHOOK__ *HHOOK;
typedef struct HINSTANCE__ *HINSTANCE;
typedef HINSTANCE HMODULE;
typedef struct _PSP * HPROPSHEETPAGE;
typedef const wchar_t *LPCWSTR;
typedef DWORD COLORREF;

// win32dialog
#define WHITE_BRUSH 0
#define GRAY_BRUSH 2
#define BLACK_BRUSH 4
#define NULL_BRUSH 5
#define HOLLOW_BRUSH NULL_BRUSH
#define GWL_STYLE (-16)
#define GWL_EXSTYLE (-20)
#define GWL_ID (-12)
#define GWLP_WNDPROC (-4)
#define GWLP_HINSTANCE (-6)
#define GWLP_HWNDPARENT (-8)
#define GWLP_USERDATA (-21)
#define DWLP_MSGRESULT 0
#define DWLP_DLGPROC DWLP_MSGRESULT + sizeof(LRESULT)
#define DWLP_USER DWLP_DLGPROC + sizeof(DLGPROC)
#define WS_OVERLAPPED 0x00000000L
#define WS_POPUP 0x80000000L
#define WS_CHILD 0x40000000L
#define WS_MINIMIZE 0x20000000L
#define WS_VISIBLE 0x10000000L
#define WS_DISABLED 0x08000000L
#define WS_CLIPSIBLINGS 0x04000000L
#define WS_CLIPCHILDREN 0x02000000L
#define WS_MAXIMIZE 0x01000000L
#define WS_CAPTION 0x00C00000L
#define WS_BORDER 0x00800000L
#define WS_DLGFRAME 0x00400000L
#define WS_VSCROLL 0x00200000L
#define WS_HSCROLL 0x00100000L
#define WS_SYSMENU 0x00080000L
#define WS_THICKFRAME 0x00040000L
#define WS_GROUP 0x00020000L
#define WS_TABSTOP 0x00010000L
#define WS_MINIMIZEBOX 0x00020000L
#define WS_MAXIMIZEBOX 0x00010000L
#define WS_TILED WS_OVERLAPPED
#define WS_ICONIC WS_MINIMIZE
#define WS_SIZEBOX WS_THICKFRAME
#define WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#define WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#define WS_CHILDWINDOW (WS_CHILD)
#define WS_EX_DLGMODALFRAME 0x00000001L
#define WS_EX_NOPARENTNOTIFY 0x00000004L
#define WS_EX_TOPMOST 0x00000008L
#define WS_EX_ACCEPTFILES 0x00000010L
#define WS_EX_TRANSPARENT 0x00000020L
#define WS_EX_MDICHILD 0x00000040L
#define WS_EX_TOOLWINDOW 0x00000080L
#define WS_EX_WINDOWEDGE 0x00000100L
#define WS_EX_CLIENTEDGE 0x00000200L
#define WS_EX_CONTEXTHELP 0x00000400L
#define WS_EX_RIGHT 0x00001000L
#define WS_EX_LEFT 0x00000000L
#define WS_EX_RTLREADING 0x00002000L
#define WS_EX_LTRREADING 0x00000000L
#define WS_EX_LEFTSCROLLBAR 0x00004000L
#define WS_EX_RIGHTSCROLLBAR 0x00000000L
#define WS_EX_CONTROLPARENT 0x00010000L
#define WS_EX_STATICEDGE 0x00020000L
#define WS_EX_APPWINDOW 0x00040000L
#define WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#define WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#define WS_EX_LAYERED 0x00080000
#define WS_EX_NOINHERITLAYOUT 0x00100000L
#define WS_EX_LAYOUTRTL 0x00400000L
#define WS_EX_COMPOSITED 0x02000000L
#define WS_EX_NOACTIVATE 0x08000000L
#define CF_TEXT 1
#define CF_DIB 8
#define CF_MAX 18
#define CF_MAX 17
#define CF_MAX 15
#define MF_SEPARATOR 0x00000800L
#define MF_ENABLED 0x00000000L
#define MF_UNCHECKED 0x00000000L
#define MF_CHECKED 0x00000008L
#define MF_STRING 0x00000000L
#define MF_BITMAP 0x00000004L
#define MF_OWNERDRAW 0x00000100L
#define MF_MENUBARBREAK 0x00000020L
#define MF_MENUBREAK 0x00000040L
#define MF_UNHILITE 0x00000000L
#define MF_HILITE 0x00000080L
#define MF_DEFAULT 0x00001000L
#define MF_RIGHTJUSTIFY 0x00004000L
#define MFS_GRAYED 0x00000003L
#define SC_SIZE 0xF000
#define SC_MINIMIZE 0xF020
#define SC_MAXIMIZE 0xF030
#define OBM_UPARROW 32753
#define OBM_DNARROW 32752
#define OBM_RGARROW 32751
#define OBM_LFARROW 32750
#define OBM_REDUCE 32749
#define OBM_ZOOM 32748
#define OBM_RESTORE 32747
#define OBM_CHECK 32760
#define OCR_SIZE 32640
#define OCR_NO 32648
#define OIC_HAND 32513
#define OIC_BANG 32515
#define OIC_NOTE 32516
#define IDI_APPLICATION 32512
#define IDI_HAND 32513
#define IDI_QUESTION 32514
#define IDI_EXCLAMATION 32515
#define IDI_ASTERISK 32516
#define IDI_WINLOGO 32517
#define IDI_SHIELD 32518
#define IDI_APPLICATION MAKEINTRESOURCE(32512)
#define IDI_HAND MAKEINTRESOURCE(32513)
#define IDI_QUESTION MAKEINTRESOURCE(32514)
#define IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#define IDI_ASTERISK MAKEINTRESOURCE(32516)
#define IDI_WINLOGO MAKEINTRESOURCE(32517)
#define IDI_SHIELD MAKEINTRESOURCE(32518)
#define IDOK 1
#define IDCANCEL 2
#define IDABORT 3
#define IDRETRY 4
#define IDIGNORE 5
#define IDYES 6
#define IDNO 7
#define IDCLOSE 8
#define IDHELP 9
#define IDTRYAGAIN 10
#define IDCONTINUE 11
#define IDTIMEOUT 32000
#define ES_LEFT 0x0000L
#define ES_CENTER 0x0001L
#define ES_RIGHT 0x0002L
#define ES_MULTILINE 0x0004L
#define ES_UPPERCASE 0x0008L
#define ES_LOWERCASE 0x0010L
#define ES_PASSWORD 0x0020L
#define ES_AUTOVSCROLL 0x0040L
#define ES_AUTOHSCROLL 0x0080L
#define ES_NOHIDESEL 0x0100L
#define ES_OEMCONVERT 0x0400L
#define ES_READONLY 0x0800L
#define ES_WANTRETURN 0x1000L
#define ES_NUMBER 0x2000L
#define EM_GETSEL 0x00B0
#define EM_SETSEL 0x00B1
#define EM_GETRECT 0x00B2
#define EM_SETRECT 0x00B3
#define EM_SETRECTNP 0x00B4
#define EM_SCROLL 0x00B5
#define EM_LINESCROLL 0x00B6
#define EM_SCROLLCARET 0x00B7
#define EM_GETMODIFY 0x00B8
#define EM_SETMODIFY 0x00B9
#define EM_GETLINECOUNT 0x00BA
#define EM_LINEINDEX 0x00BB
#define EM_SETHANDLE 0x00BC
#define EM_GETHANDLE 0x00BD
#define EM_GETTHUMB 0x00BE
#define EM_LINELENGTH 0x00C1
#define EM_REPLACESEL 0x00C2
#define EM_GETLINE 0x00C4
#define EM_LIMITTEXT 0x00C5
#define EM_CANUNDO 0x00C6
#define EM_UNDO 0x00C7
#define EM_FMTLINES 0x00C8
#define EM_LINEFROMCHAR 0x00C9
#define EM_SETTABSTOPS 0x00CB
#define EM_SETPASSWORDCHAR 0x00CC
#define EM_EMPTYUNDOBUFFER 0x00CD
#define EM_GETFIRSTVISIBLELINE 0x00CE
#define EM_SETREADONLY 0x00CF
#define EM_SETWORDBREAKPROC 0x00D0
#define EM_GETWORDBREAKPROC 0x00D1
#define EM_GETPASSWORDCHAR 0x00D2
#define EM_SETMARGINS 0x00D3
#define EM_GETMARGINS 0x00D4
#define EM_SETLIMITTEXT EM_LIMITTEXT
#define EM_GETLIMITTEXT 0x00D5
#define EM_POSFROMCHAR 0x00D6
#define EM_CHARFROMPOS 0x00D7
#define EM_SETIMESTATUS 0x00D8
#define EM_GETIMESTATUS 0x00D9
#define BS_PUSHBUTTON 0x00000000L
#define BS_DEFPUSHBUTTON 0x00000001L
#define BS_CHECKBOX 0x00000002L
#define BS_AUTOCHECKBOX 0x00000003L
#define BS_RADIOBUTTON 0x00000004L
#define BS_3STATE 0x00000005L
#define BS_AUTO3STATE 0x00000006L
#define BS_GROUPBOX 0x00000007L
#define BS_USERBUTTON 0x00000008L
#define BS_AUTORADIOBUTTON 0x00000009L
#define BS_PUSHBOX 0x0000000AL
#define BS_OWNERDRAW 0x0000000BL
#define BS_TYPEMASK 0x0000000FL
#define BS_LEFTTEXT 0x00000020L
#define BS_TEXT 0x00000000L
#define BS_ICON 0x00000040L
#define BS_BITMAP 0x00000080L
#define BS_LEFT 0x00000100L
#define BS_RIGHT 0x00000200L
#define BS_CENTER 0x00000300L
#define BS_TOP 0x00000400L
#define BS_BOTTOM 0x00000800L
#define BS_VCENTER 0x00000C00L
#define BS_PUSHLIKE 0x00001000L
#define BS_MULTILINE 0x00002000L
#define BS_NOTIFY 0x00004000L
#define BS_FLAT 0x00008000L
#define BS_RIGHTBUTTON BS_LEFTTEXT
#define BN_CLICKED 0
#define BN_PAINT 1
#define BN_HILITE 2
#define BN_UNHILITE 3
#define BN_DISABLE 4
#define BN_DOUBLECLICKED 5
#define BN_PUSHED BN_HILITE
#define BN_UNPUSHED BN_UNHILITE
#define BN_DBLCLK BN_DOUBLECLICKED
#define BN_SETFOCUS 6
#define BN_KILLFOCUS 7
#define BM_GETCHECK 0x00F0
#define BM_SETCHECK 0x00F1
#define BM_GETSTATE 0x00F2
#define BM_SETSTATE 0x00F3
#define BM_SETSTYLE 0x00F4
#define BM_CLICK 0x00F5
#define BM_GETIMAGE 0x00F6
#define BM_SETIMAGE 0x00F7
#define BM_SETDONTCLICK 0x00F8
#define BST_UNCHECKED 0x0000
#define BST_CHECKED 0x0001
#define BST_INDETERMINATE 0x0002
#define BST_PUSHED 0x0004
#define BST_FOCUS 0x0008
#define SS_LEFT 0x00000000L
#define SS_CENTER 0x00000001L
#define SS_RIGHT 0x00000002L
#define SS_ICON 0x00000003L
#define SS_BLACKRECT 0x00000004L
#define SS_GRAYRECT 0x00000005L
#define SS_WHITERECT 0x00000006L
#define SS_BLACKFRAME 0x00000007L
#define SS_GRAYFRAME 0x00000008L
#define SS_WHITEFRAME 0x00000009L
#define SS_USERITEM 0x0000000AL
#define SS_SIMPLE 0x0000000BL
#define SS_LEFTNOWORDWRAP 0x0000000CL
#define SS_OWNERDRAW 0x0000000DL
#define SS_BITMAP 0x0000000EL
#define SS_ENHMETAFILE 0x0000000FL
#define SS_ETCHEDHORZ 0x00000010L
#define SS_ETCHEDVERT 0x00000011L
#define SS_ETCHEDFRAME 0x00000012L
#define SS_TYPEMASK 0x0000001FL
#define SS_REALSIZECONTROL 0x00000040L
#define SS_NOPREFIX 0x00000080L
#define SS_NOTIFY 0x00000100L
#define SS_CENTERIMAGE 0x00000200L
#define SS_RIGHTJUST 0x00000400L
#define SS_REALSIZEIMAGE 0x00000800L
#define SS_SUNKEN 0x00001000L
#define SS_EDITCONTROL 0x00002000L
#define SS_ENDELLIPSIS 0x00004000L
#define SS_PATHELLIPSIS 0x00008000L
#define SS_WORDELLIPSIS 0x0000C000L
#define SS_ELLIPSISMASK 0x0000C000L
#define DS_ABSALIGN 0x01L
#define DS_SYSMODAL 0x02L
#define DS_LOCALEDIT 0x20L
#define DS_SETFONT 0x40L
#define DS_MODALFRAME 0x80L
#define DS_NOIDLEMSG 0x100L
#define DS_SETFOREGROUND 0x200L
#define DS_3DLOOK 0x0004L
#define DS_FIXEDSYS 0x0008L
#define DS_NOFAILCREATE 0x0010L
#define DS_CONTROL 0x0400L
#define DS_CENTER 0x0800L
#define DS_CENTERMOUSE 0x1000L
#define DS_CONTEXTHELP 0x2000L
#define DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)
#define DS_USEPIXELS 0x8000L
#define LBS_NOTIFY 0x0001L
#define LBS_SORT 0x0002L
#define LBS_NOREDRAW 0x0004L
#define LBS_MULTIPLESEL 0x0008L
#define LBS_OWNERDRAWFIXED 0x0010L
#define LBS_OWNERDRAWVARIABLE 0x0020L
#define LBS_HASSTRINGS 0x0040L
#define LBS_USETABSTOPS 0x0080L
#define LBS_NOINTEGRALHEIGHT 0x0100L
#define LBS_MULTICOLUMN 0x0200L
#define LBS_WANTKEYBOARDINPUT 0x0400L
#define LBS_EXTENDEDSEL 0x0800L
#define LBS_DISABLENOSCROLL 0x1000L
#define LBS_NODATA 0x2000L
#define LBS_NOSEL 0x4000L
#define LBS_COMBOBOX 0x8000L
#define LBS_STANDARD (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)
#define CBS_SIMPLE 0x0001L
#define CBS_DROPDOWN 0x0002L
#define CBS_DROPDOWNLIST 0x0003L
#define CBS_OWNERDRAWFIXED 0x0010L
#define CBS_OWNERDRAWVARIABLE 0x0020L
#define CBS_AUTOHSCROLL 0x0040L
#define CBS_OEMCONVERT 0x0080L
#define CBS_SORT 0x0100L
#define CBS_HASSTRINGS 0x0200L
#define CBS_NOINTEGRALHEIGHT 0x0400L
#define CBS_DISABLENOSCROLL 0x0800L
#define CBS_UPPERCASE 0x2000L
#define CBS_LOWERCASE 0x4000L
#define SBS_HORZ 0x0000L
#define SBS_VERT 0x0001L
#define SBS_TOPALIGN 0x0002L
#define SBS_LEFTALIGN 0x0002L
#define SBS_BOTTOMALIGN 0x0004L
#define SBS_RIGHTALIGN 0x0004L
#define SBS_SIZEBOXTOPLEFTALIGN 0x0002L
#define SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#define SBS_SIZEBOX 0x0008L
#define SBS_SIZEGRIP 0x0010L
#define HELP_CONTEXT 0x0001L
#define HELP_TCARD 0x8000
#define MAKEINTRESOURCE MAKEINTRESOURCEW
#define MAKEINTRESOURCE MAKEINTRESOURCEA
#define RT_CURSOR MAKEINTRESOURCE(1)
#define RT_ICON MAKEINTRESOURCE(3)
#define RT_MENU MAKEINTRESOURCE(4)
#define RT_FONT MAKEINTRESOURCE(8)
#define DIFFERENCE 11
#define RT_MANIFEST 24
#define CREATEPROCESS_MANIFEST_RESOURCE_ID 1
#define ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
#define ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#define ISOLATIONPOLICY_MANIFEST_RESOURCE_ID 4
#define ISOLATIONPOLICY_BROWSER_MANIFEST_RESOURCE_ID 5
#define MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1
#define MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID 16
#define RT_MANIFEST MAKEINTRESOURCE(24)
#define CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE( 1)
#define ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#define ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#define ISOLATIONPOLICY_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(4)
#define ISOLATIONPOLICY_BROWSER_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(5)
#define MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE( 1
#define MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16
#define wvsprintf wvsprintfW
#define wvsprintf wvsprintfA
#define wsprintf wsprintfW
#define wsprintf wsprintfA
#define SB_LINEUP 0
#define SB_LINELEFT 0
#define SB_LINEDOWN 1
#define SB_LINERIGHT 1
#define SB_PAGEUP 2
#define SB_PAGELEFT 2
#define SB_PAGEDOWN 3
#define SB_PAGERIGHT 3
#define SB_THUMBPOSITION 4
#define SB_THUMBTRACK 5
#define SB_TOP 6
#define SB_LEFT 6
#define SB_BOTTOM 7
#define SB_RIGHT 7
#define SB_ENDSCROLL 8
#define SW_HIDE 0
#define SW_SHOWNORMAL 1
#define SW_NORMAL 1
#define SW_SHOWMINIMIZED 2
#define SW_SHOWMAXIMIZED 3
#define SW_MAXIMIZE 3
#define SW_SHOWNOACTIVATE 4
#define SW_SHOW 5
#define SW_MINIMIZE 6
#define SW_SHOWMINNOACTIVE 7
#define SW_SHOWNA 8
#define SW_RESTORE 9
#define SW_SHOWDEFAULT 10
#define SW_FORCEMINIMIZE 11
#define SW_MAX 11
#define KF_EXTENDED 0x0100
#define KF_ALTDOWN 0x2000
#define KF_UP 0x8000
#define VK_F1 0x70
#define VK_F2 0x71
#define VK_OEM_1 0xBA
#define WH_MIN (-1)
#define WH_KEYBOARD 2
#define WH_CALLWNDPROC 4
#define WH_MOUSE 7
#define WH_MAX 14
#define WH_MAX 12
#define WH_MAX 11
#define HC_NOREMOVE 3
#define HC_NOREM HC_NOREMOVE
#define HSHELL_WINDOWACTIVATED 4
#define HSHELL_REDRAW 6
#define HSHELL_HIGHBIT 0x8000
#define APPCOMMAND_MEDIA_PLAY 46
#define LoadKeyboardLayout LoadKeyboardLayoutW
#define LoadKeyboardLayout LoadKeyboardLayoutA
#define GetKeyboardLayoutName GetKeyboardLayoutNameW
#define GetKeyboardLayoutName GetKeyboardLayoutNameA
#define CreateDesktop CreateDesktopW
#define CreateDesktop CreateDesktopA
#define CreateDesktopEx CreateDesktopExW
#define CreateDesktopEx CreateDesktopExA
#define OpenDesktop OpenDesktopW
#define OpenDesktop OpenDesktopA
#define EnumDesktops EnumDesktopsW
#define EnumDesktops EnumDesktopsA
#define WINSTA_ENUMDESKTOPS 0x0001L
#define WINSTA_READATTRIBUTES 0x0002L
#define WINSTA_ACCESSCLIPBOARD 0x0004L
#define CreateWindowStation CreateWindowStationW
#define CreateWindowStation CreateWindowStationA
#define OpenWindowStation OpenWindowStationW
#define OpenWindowStation OpenWindowStationA
#define EnumWindowStations EnumWindowStationsW
#define EnumWindowStations EnumWindowStationsA
#define GetUserObjectInformation GetUserObjectInformationW
#define GetUserObjectInformation GetUserObjectInformationA
#define SetUserObjectInformation SetUserObjectInformationW
#define SetUserObjectInformation SetUserObjectInformationA
#define GCL_HICON (-14)
#define GCLP_HICON (-14)
#define WM_DESTROY 0x0002
#define WM_SIZE 0x0005
#define WM_ACTIVATE 0x0006
#define WM_GETTEXT 0x000D
#define WM_PAINT 0x000F
#define WM_WININICHANGE 0x001A
#define WM_DRAWITEM 0x002B
#define WM_POWER 0x0048
#define WM_NOTIFY 0x004E
#define WM_INPUTLANGCHANGE 0x0051
#define WM_HELP 0x0053
#define WM_INPUT 0x00FF
#define WM_CHAR 0x0102
#define WM_KEYLAST 0x0109
#define WM_KEYLAST 0x0108
#define WM_IME_COMPOSITION 0x010F
#define WM_HSCROLL 0x0114
#define WM_VSCROLL 0x0115
#define WM_INITMENU 0x0116
#define WM_GESTURE 0x0119
#define WM_MOUSELAST 0x020E
#define WM_MOUSELAST 0x020D
#define WM_MOUSELAST 0x020A
#define WM_MOUSELAST 0x0209
#define XBUTTON1 0x0001
#define XBUTTON2 0x0002
#define PBT_APMQUERYSUSPEND 0x0000
#define PBT_APMQUERYSTANDBY 0x0001
#define WM_TOUCH 0x0240
#define WM_NCPOINTERUP 0x0243
#define WM_POINTERUP 0x0247
#define WM_DPICHANGED 0x02E0
#define WM_COPY 0x0301
#define WM_PRINT 0x0317
#define WM_APP 0x8000
#define WM_USER 0x0400
#define WMSZ_TOP 3
#define WMSZ_BOTTOM 6
#define HTGROWBOX 4
#define HTSIZE HTGROWBOX
#define HTMINBUTTON 8
#define HTMAXBUTTON 9
#define HTLEFT 10
#define HTTOP 12
#define HTBOTTOM 15
#define HTBOTTOMRIGHT 17
#define MA_ACTIVATE 1
#define MA_NOACTIVATE 3
#define ICON_SMALL 0
#define RegisterWindowMessage RegisterWindowMessageW
#define RegisterWindowMessage RegisterWindowMessageA
#define SIZE_RESTORED 0
#define SIZE_MINIMIZED 1
#define SIZE_MAXIMIZED 2
#define SIZE_MAXSHOW 3
#define SIZE_MAXHIDE 4
#define WVR_HREDRAW 0x0100
#define BDR_RAISEDOUTER 0x0001
#define BDR_SUNKENOUTER 0x0002
#define BDR_RAISEDINNER 0x0004
#define BDR_SUNKENINNER 0x0008
#define BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#define BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#define BF_LEFT 0x0001
#define BF_TOP 0x0002
#define BF_RIGHT 0x0004
#define BF_BOTTOM 0x0008
#define BF_DIAGONAL 0x0010
#define DFCS_MENUARROW 0x0000
#define DFCS_SCROLLSIZEGRIP 0x0008
#define DFCS_BUTTONRADIO 0x0004
#define DC_ICON 0x0004
#define ODT_MENU 1
#define ODT_LISTBOX 2
#define ODT_COMBOBOX 3
#define ODT_BUTTON 4
#define ODT_STATIC 5
#define ODA_DRAWENTIRE 0x0001
#define ODA_SELECT 0x0002
#define ODA_FOCUS 0x0004
#define ODS_SELECTED 0x0001
#define ODS_GRAYED 0x0002
#define ODS_DISABLED 0x0004
#define ODS_CHECKED 0x0008
#define ODS_FOCUS 0x0010
#define ODS_DEFAULT 0x0020
#define ODS_COMBOBOXEDIT 0x1000
#define GetMessage GetMessageW
#define GetMessage GetMessageA
#define DispatchMessage DispatchMessageW
#define DispatchMessage DispatchMessageA
#define PeekMessage PeekMessageW
#define PeekMessage PeekMessageA
#define MOD_SHIFT 0x0004
#define EWX_FORCE 0x00000004
#define SendMessage SendMessageW
#define SendMessage SendMessageA
#define SendMessageTimeout SendMessageTimeoutW
#define SendMessageTimeout SendMessageTimeoutA
#define SendNotifyMessage SendNotifyMessageW
#define SendNotifyMessage SendNotifyMessageA
#define SendMessageCallback SendMessageCallbackW
#define SendMessageCallback SendMessageCallbackA
#define BroadcastSystemMessageEx BroadcastSystemMessageExW
#define BroadcastSystemMessageEx BroadcastSystemMessageExA
#define BroadcastSystemMessage BroadcastSystemMessageW
#define BroadcastSystemMessage BroadcastSystemMessageA
#define RegisterDeviceNotification RegisterDeviceNotificationW
#define RegisterDeviceNotification RegisterDeviceNotificationA
#define PostMessage PostMessageW
#define PostMessage PostMessageA
#define PostThreadMessage PostThreadMessageW
#define PostThreadMessage PostThreadMessageA
#define PostAppMessage PostAppMessageW
#define PostAppMessage PostAppMessageA
#define DefWindowProc DefWindowProcW
#define DefWindowProc DefWindowProcA
#define CallWindowProc CallWindowProcW
#define CallWindowProc CallWindowProcA
#define RegisterClass RegisterClassW
#define RegisterClass RegisterClassA
#define UnregisterClass UnregisterClassW
#define UnregisterClass UnregisterClassA
#define GetClassInfo GetClassInfoW
#define GetClassInfo GetClassInfoA
#define RegisterClassEx RegisterClassExW
#define RegisterClassEx RegisterClassExA
#define GetClassInfoEx GetClassInfoExW
#define GetClassInfoEx GetClassInfoExA
#define CreateWindowEx CreateWindowExW
#define CreateWindowEx CreateWindowExA
#define CreateWindow CreateWindowW
#define CreateWindow CreateWindowA
#define FLASHW_CAPTION 0x00000001
#define FLASHW_TRAY 0x00000002
#define FLASHW_TIMER 0x00000004
#define SWP_FRAMECHANGED 0x0020
#define SWP_NOOWNERZORDER 0x0200
#define HWND_TOP ((HWND)0)
#define CreateDialogParam CreateDialogParamW
#define CreateDialogParam CreateDialogParamA
#define CreateDialogIndirectParam CreateDialogIndirectParamW
#define CreateDialogIndirectParam CreateDialogIndirectParamA
#define CreateDialog CreateDialogW
#define CreateDialog CreateDialogA
#define CreateDialogIndirect CreateDialogIndirectW
#define CreateDialogIndirect CreateDialogIndirectA
#define DialogBoxParam DialogBoxParamW
#define DialogBoxParam DialogBoxParamA
#define DialogBoxIndirectParam DialogBoxIndirectParamW
#define DialogBoxIndirectParam DialogBoxIndirectParamA
#define DialogBox DialogBoxW
#define DialogBox DialogBoxA
#define DialogBoxIndirect DialogBoxIndirectW
#define DialogBoxIndirect DialogBoxIndirectA
#define SetDlgItemText SetDlgItemTextW
#define SetDlgItemText SetDlgItemTextA
#define GetDlgItemText GetDlgItemTextW
#define GetDlgItemText GetDlgItemTextA
#define SendDlgItemMessage SendDlgItemMessageW
#define SendDlgItemMessage SendDlgItemMessageA
#define DefDlgProc DefDlgProcW
#define DefDlgProc DefDlgProcA
#define DLGWINDOWEXTRA 30
#define DLGWINDOWEXTRA 48
#define CallMsgFilter CallMsgFilterW
#define CallMsgFilter CallMsgFilterA
#define RegisterClipboardFormat RegisterClipboardFormatW
#define RegisterClipboardFormat RegisterClipboardFormatA
#define GetClipboardFormatName GetClipboardFormatNameW
#define GetClipboardFormatName GetClipboardFormatNameA
#define CharToOem CharToOemW
#define CharToOem CharToOemA
#define OemToChar OemToCharW
#define OemToChar OemToCharA
#define CharToOemBuff CharToOemBuffW
#define CharToOemBuff CharToOemBuffA
#define OemToCharBuff OemToCharBuffW
#define OemToCharBuff OemToCharBuffA
#define CharUpper CharUpperW
#define CharUpper CharUpperA
#define CharUpperBuff CharUpperBuffW
#define CharUpperBuff CharUpperBuffA
#define CharLower CharLowerW
#define CharLower CharLowerA
#define CharLowerBuff CharLowerBuffW
#define CharLowerBuff CharLowerBuffA
#define CharNext CharNextW
#define CharNext CharNextA
#define CharPrev CharPrevW
#define CharPrev CharPrevA
#define AnsiToOem CharToOemA
#define OemToAnsi OemToCharA
#define AnsiUpper CharUpperA
#define AnsiLower CharLowerA
#define IsCharAlpha IsCharAlphaW
#define IsCharAlpha IsCharAlphaA
#define IsCharAlphaNumeric IsCharAlphaNumericW
#define IsCharAlphaNumeric IsCharAlphaNumericA
#define IsCharUpper IsCharUpperW
#define IsCharUpper IsCharUpperA
#define IsCharLower IsCharLowerW
#define IsCharLower IsCharLowerA
#define GetKeyNameText GetKeyNameTextW
#define GetKeyNameText GetKeyNameTextA
#define VkKeyScan VkKeyScanW
#define VkKeyScan VkKeyScanA
#define VkKeyScanEx VkKeyScanExW
#define VkKeyScanEx VkKeyScanExA
#define MOUSEEVENTF_MOVE 0x0001
#define POINTER_FLAG_UP 0x00040000
#define MapVirtualKey MapVirtualKeyW
#define MapVirtualKey MapVirtualKeyA
#define MapVirtualKeyEx MapVirtualKeyExW
#define MapVirtualKeyEx MapVirtualKeyExA
#define MAPVK_VK_TO_VSC (0)
#define MAPVK_VSC_TO_VK (1)
#define QS_MOUSEMOVE 0x0002
#define QS_POSTMESSAGE 0x0008
#define QS_TIMER 0x0010
#define QS_PAINT 0x0020
#define QS_SENDMESSAGE 0x0040
#define QS_HOTKEY 0x0080
#define QS_MOUSE (QS_MOUSEMOVE | \
#define QS_INPUT (QS_MOUSE | \
#define LoadAccelerators LoadAcceleratorsW
#define LoadAccelerators LoadAcceleratorsA
#define CreateAcceleratorTable CreateAcceleratorTableW
#define CreateAcceleratorTable CreateAcceleratorTableA
#define CopyAcceleratorTable CopyAcceleratorTableW
#define CopyAcceleratorTable CopyAcceleratorTableA
#define TranslateAccelerator TranslateAcceleratorW
#define TranslateAccelerator TranslateAcceleratorA
#define SM_CXDLGFRAME 7
#define SM_CYDLGFRAME 8
#define SM_CXICON 11
#define SM_CYICON 12
#define SM_CYMENU 15
#define SM_CXMIN 28
#define SM_CYMIN 29
#define SM_CXSIZE 30
#define SM_CYSIZE 31
#define SM_CXFRAME 32
#define SM_CYFRAME 33
#define SM_CMETRICS 76
#define SM_CMETRICS 83
#define SM_CMETRICS 91
#define SM_CMETRICS 93
#define SM_CMETRICS 97
#define MENU_READ_ACCESS (STANDARD_RIGHTS_READ |\
#define MENU_WRITE_ACCESS (STANDARD_RIGHTS_WRITE |\
#define MENU_EXECUTE_ACCESS (STANDARD_RIGHTS_EXECUTE)
#define LoadMenu LoadMenuW
#define LoadMenu LoadMenuA
#define LoadMenuIndirect LoadMenuIndirectW
#define LoadMenuIndirect LoadMenuIndirectA
#define ChangeMenu ChangeMenuW
#define ChangeMenu ChangeMenuA
#define GetMenuString GetMenuStringW
#define GetMenuString GetMenuStringA
#define InsertMenu InsertMenuW
#define InsertMenu InsertMenuA
#define AppendMenu AppendMenuW
#define AppendMenu AppendMenuA
#define ModifyMenu ModifyMenuW
#define ModifyMenu ModifyMenuA
#define HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#define HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#define InsertMenuItem InsertMenuItemW
#define InsertMenuItem InsertMenuItemA
#define GetMenuItemInfo GetMenuItemInfoW
#define GetMenuItemInfo GetMenuItemInfoA
#define SetMenuItemInfo SetMenuItemInfoW
#define SetMenuItemInfo SetMenuItemInfoA
#define DrawText DrawTextW
#define DrawText DrawTextA
#define DrawTextEx DrawTextExW
#define DrawTextEx DrawTextExA
#define GrayString GrayStringW
#define GrayString GrayStringA
#define DrawState DrawStateW
#define DrawState DrawStateA
#define TabbedTextOut TabbedTextOutW
#define TabbedTextOut TabbedTextOutA
#define GetTabbedTextExtent GetTabbedTextExtentW
#define GetTabbedTextExtent GetTabbedTextExtentA
#define RDW_ERASE 0x0004
#define ESB_DISABLE_LEFT 0x0001
#define ESB_DISABLE_RIGHT 0x0002
#define SetProp SetPropW
#define SetProp SetPropA
#define GetProp GetPropW
#define GetProp GetPropA
#define RemoveProp RemovePropW
#define RemoveProp RemovePropA
#define EnumPropsEx EnumPropsExW
#define EnumPropsEx EnumPropsExA
#define EnumProps EnumPropsW
#define EnumProps EnumPropsA
#define SetWindowText SetWindowTextW
#define SetWindowText SetWindowTextA
#define GetWindowText GetWindowTextW
#define GetWindowText GetWindowTextA
#define GetWindowTextLength GetWindowTextLengthW
#define GetWindowTextLength GetWindowTextLengthA
#define MB_OK 0x00000000L
#define MB_OKCANCEL 0x00000001L
#define MB_ABORTRETRYIGNORE 0x00000002L
#define MB_YESNOCANCEL 0x00000003L
#define MB_YESNO 0x00000004L
#define MB_RETRYCANCEL 0x00000005L
#define MB_CANCELTRYCONTINUE 0x00000006L
#define MB_ICONHAND 0x00000010L
#define MB_ICONQUESTION 0x00000020L
#define MB_ICONEXCLAMATION 0x00000030L
#define MB_ICONASTERISK 0x00000040L
#define MB_ICONWARNING MB_ICONEXCLAMATION
#define MB_ICONERROR MB_ICONHAND
#define MB_ICONINFORMATION MB_ICONASTERISK
#define MB_ICONSTOP MB_ICONHAND
#define MB_DEFBUTTON1 0x00000000L
#define MB_DEFBUTTON2 0x00000100L
#define MB_DEFBUTTON3 0x00000200L
#define MB_DEFBUTTON4 0x00000300L
#define MB_APPLMODAL 0x00000000L
#define MB_SYSTEMMODAL 0x00001000L
#define MB_TASKMODAL 0x00002000L
#define MB_HELP 0x00004000L
#define MB_SETFOREGROUND 0x00010000L
#define MB_DEFAULT_DESKTOP_ONLY 0x00020000L
#define MB_TOPMOST 0x00040000L
#define MB_RIGHT 0x00080000L
#define MB_RTLREADING 0x00100000L
#define MB_SERVICE_NOTIFICATION 0x00200000L
#define MB_SERVICE_NOTIFICATION 0x00040000L
#define MB_SERVICE_NOTIFICATION_NT3X 0x00040000L
#define MessageBox MessageBoxW
#define MessageBox MessageBoxA
#define MessageBoxEx MessageBoxExW
#define MessageBoxEx MessageBoxExA
#define MessageBoxIndirect MessageBoxIndirectW
#define MessageBoxIndirect MessageBoxIndirectA
#define COLOR_SCROLLBAR 0
#define COLOR_BACKGROUND 1
#define COLOR_INACTIVECAPTION 3
#define COLOR_MENU 4
#define COLOR_WINDOW 5
#define COLOR_HIGHLIGHT 13
#define COLOR_BTNFACE 15
#define COLOR_BTNSHADOW 16
#define COLOR_BTNHIGHLIGHT 20
#define GetWindowLong GetWindowLongW
#define GetWindowLong GetWindowLongA
#define SetWindowLong SetWindowLongW
#define SetWindowLong SetWindowLongA
#define GetWindowLongPtr GetWindowLongPtrW
#define GetWindowLongPtr GetWindowLongPtrA
#define SetWindowLongPtr SetWindowLongPtrW
#define SetWindowLongPtr SetWindowLongPtrA
#define GetWindowLongPtrA GetWindowLongA
#define GetWindowLongPtrW GetWindowLongW
#define SetWindowLongPtrA SetWindowLongA
#define SetWindowLongPtrW SetWindowLongW
#define GetClassLong GetClassLongW
#define GetClassLong GetClassLongA
#define SetClassLong SetClassLongW
#define SetClassLong SetClassLongA
#define GetClassLongPtr GetClassLongPtrW
#define GetClassLongPtr GetClassLongPtrA
#define SetClassLongPtr SetClassLongPtrW
#define SetClassLongPtr SetClassLongPtrA
#define GetClassLongPtrA GetClassLongA
#define GetClassLongPtrW GetClassLongW
#define SetClassLongPtrA SetClassLongA
#define SetClassLongPtrW SetClassLongW
#define FindWindow FindWindowW
#define FindWindow FindWindowA
#define FindWindowEx FindWindowExW
#define FindWindowEx FindWindowExA
#define GetClassName GetClassNameW
#define GetClassName GetClassNameA
#define GW_MAX 5
#define GW_MAX 6
#define SetWindowsHook SetWindowsHookW
#define SetWindowsHook SetWindowsHookA
#define SetWindowsHookEx SetWindowsHookExW
#define SetWindowsHookEx SetWindowsHookExA
#define LoadBitmap LoadBitmapW
#define LoadBitmap LoadBitmapA
#define LoadCursor LoadCursorW
#define LoadCursor LoadCursorA
#define LoadCursorFromFile LoadCursorFromFileW
#define LoadCursorFromFile LoadCursorFromFileA
#define IDC_SIZE MAKEINTRESOURCE(32640)
#define LoadIcon LoadIconW
#define LoadIcon LoadIconA
#define PrivateExtractIcons PrivateExtractIconsW
#define PrivateExtractIcons PrivateExtractIconsA
#define IMAGE_BITMAP 0
#define LoadImage LoadImageW
#define LoadImage LoadImageA
#define DI_IMAGE 0x0002
#define GetIconInfoEx GetIconInfoExW
#define GetIconInfoEx GetIconInfoExA
#define LoadString LoadStringW
#define LoadString LoadStringA
#define EN_SETFOCUS 0x0100
#define EN_KILLFOCUS 0x0200
#define EN_CHANGE 0x0300
#define EN_UPDATE 0x0400
#define EN_ERRSPACE 0x0500
#define EN_MAXTEXT 0x0501
#define EN_HSCROLL 0x0601
#define EN_VSCROLL 0x0602
#define EN_ALIGN_LTR_EC 0x0700
#define EN_ALIGN_RTL_EC 0x0701
#define EC_LEFTMARGIN 0x0001
#define EC_RIGHTMARGIN 0x0002
#define EC_USEFONTINFO 0xffff
#define EMSIS_COMPOSITIONSTRING 0x0001
#define EIMES_GETCOMPSTRATONCE 0x0001
#define EIMES_CANCELCOMPSTRINFOCUS 0x0002
#define EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004
#define WB_LEFT 0
#define WB_RIGHT 1
#define WB_ISDELIMITER 2
#define STM_SETICON 0x0170
#define STM_GETICON 0x0171
#define STM_SETIMAGE 0x0172
#define STM_GETIMAGE 0x0173
#define STN_CLICKED 0
#define STN_DBLCLK 1
#define STN_ENABLE 2
#define STN_DISABLE 3
#define STM_MSGMAX 0x0174
#define IsDialogMessage IsDialogMessageW
#define IsDialogMessage IsDialogMessageA
#define DlgDirList DlgDirListW
#define DlgDirList DlgDirListA
#define DlgDirSelectEx DlgDirSelectExW
#define DlgDirSelectEx DlgDirSelectExA
#define DlgDirListComboBox DlgDirListComboBoxW
#define DlgDirListComboBox DlgDirListComboBoxA
#define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#define DM_GETDEFID (WM_USER+0)
#define DM_SETDEFID (WM_USER+1)
#define DM_REPOSITION (WM_USER+2)
#define DC_HASDEFID 0x534B
#define DLGC_WANTARROWS 0x0001
#define DLGC_WANTTAB 0x0002
#define DLGC_WANTALLKEYS 0x0004
#define DLGC_WANTMESSAGE 0x0004
#define DLGC_HASSETSEL 0x0008
#define DLGC_DEFPUSHBUTTON 0x0010
#define DLGC_UNDEFPUSHBUTTON 0x0020
#define DLGC_RADIOBUTTON 0x0040
#define DLGC_WANTCHARS 0x0080
#define DLGC_STATIC 0x0100
#define DLGC_BUTTON 0x2000
#define LB_CTLCODE 0L
#define LB_OKAY 0
#define LB_ERR (-1)
#define LB_ERRSPACE (-2)
#define LBN_ERRSPACE (-2)
#define LBN_SELCHANGE 1
#define LBN_DBLCLK 2
#define LBN_SELCANCEL 3
#define LBN_SETFOCUS 4
#define LBN_KILLFOCUS 5
#define LB_ADDSTRING 0x0180
#define LB_INSERTSTRING 0x0181
#define LB_DELETESTRING 0x0182
#define LB_SELITEMRANGEEX 0x0183
#define LB_RESETCONTENT 0x0184
#define LB_SETSEL 0x0185
#define LB_SETCURSEL 0x0186
#define LB_GETSEL 0x0187
#define LB_GETCURSEL 0x0188
#define LB_GETTEXT 0x0189
#define LB_GETTEXTLEN 0x018A
#define LB_GETCOUNT 0x018B
#define LB_SELECTSTRING 0x018C
#define LB_DIR 0x018D
#define LB_GETTOPINDEX 0x018E
#define LB_FINDSTRING 0x018F
#define LB_GETSELCOUNT 0x0190
#define LB_GETSELITEMS 0x0191
#define LB_SETTABSTOPS 0x0192
#define LB_GETHORIZONTALEXTENT 0x0193
#define LB_SETHORIZONTALEXTENT 0x0194
#define LB_SETCOLUMNWIDTH 0x0195
#define LB_ADDFILE 0x0196
#define LB_SETTOPINDEX 0x0197
#define LB_GETITEMRECT 0x0198
#define LB_GETITEMDATA 0x0199
#define LB_SETITEMDATA 0x019A
#define LB_SELITEMRANGE 0x019B
#define LB_SETANCHORINDEX 0x019C
#define LB_GETANCHORINDEX 0x019D
#define LB_SETCARETINDEX 0x019E
#define LB_GETCARETINDEX 0x019F
#define LB_SETITEMHEIGHT 0x01A0
#define LB_GETITEMHEIGHT 0x01A1
#define LB_FINDSTRINGEXACT 0x01A2
#define LB_SETLOCALE 0x01A5
#define LB_GETLOCALE 0x01A6
#define LB_SETCOUNT 0x01A7
#define LB_INITSTORAGE 0x01A8
#define LB_ITEMFROMPOINT 0x01A9
#define LB_MULTIPLEADDSTRING 0x01B1
#define LB_GETLISTBOXINFO 0x01B2
#define LB_MSGMAX 0x01B3
#define LB_MSGMAX 0x01B1
#define LB_MSGMAX 0x01B0
#define LB_MSGMAX 0x01A8
#define CB_OKAY 0
#define CB_ERR (-1)
#define CB_ERRSPACE (-2)
#define CBN_ERRSPACE (-1)
#define CBN_SELCHANGE 1
#define CBN_DBLCLK 2
#define CBN_SETFOCUS 3
#define CBN_KILLFOCUS 4
#define CBN_EDITCHANGE 5
#define CBN_EDITUPDATE 6
#define CBN_DROPDOWN 7
#define CBN_CLOSEUP 8
#define CBN_SELENDOK 9
#define CBN_SELENDCANCEL 10
#define CB_GETEDITSEL 0x0140
#define CB_LIMITTEXT 0x0141
#define CB_SETEDITSEL 0x0142
#define CB_ADDSTRING 0x0143
#define CB_DELETESTRING 0x0144
#define CB_DIR 0x0145
#define CB_GETCOUNT 0x0146
#define CB_GETCURSEL 0x0147
#define CB_GETLBTEXT 0x0148
#define CB_GETLBTEXTLEN 0x0149
#define CB_INSERTSTRING 0x014A
#define CB_RESETCONTENT 0x014B
#define CB_FINDSTRING 0x014C
#define CB_SELECTSTRING 0x014D
#define CB_SETCURSEL 0x014E
#define CB_SHOWDROPDOWN 0x014F
#define CB_GETITEMDATA 0x0150
#define CB_SETITEMDATA 0x0151
#define CB_GETDROPPEDCONTROLRECT 0x0152
#define CB_SETITEMHEIGHT 0x0153
#define CB_GETITEMHEIGHT 0x0154
#define CB_SETEXTENDEDUI 0x0155
#define CB_GETEXTENDEDUI 0x0156
#define CB_GETDROPPEDSTATE 0x0157
#define CB_FINDSTRINGEXACT 0x0158
#define CB_SETLOCALE 0x0159
#define CB_GETLOCALE 0x015A
#define CB_GETTOPINDEX 0x015b
#define CB_SETTOPINDEX 0x015c
#define CB_GETHORIZONTALEXTENT 0x015d
#define CB_SETHORIZONTALEXTENT 0x015e
#define CB_GETDROPPEDWIDTH 0x015f
#define CB_SETDROPPEDWIDTH 0x0160
#define CB_INITSTORAGE 0x0161
#define CB_MULTIPLEADDSTRING 0x0163
#define CB_GETCOMBOBOXINFO 0x0164
#define CB_MSGMAX 0x0165
#define CB_MSGMAX 0x0163
#define CB_MSGMAX 0x0162
#define CB_MSGMAX 0x015B
#define SBM_SETPOS 0x00E0
#define SBM_GETPOS 0x00E1
#define SBM_SETRANGE 0x00E2
#define SBM_SETRANGEREDRAW 0x00E6
#define SBM_GETRANGE 0x00E3
#define SBM_ENABLE_ARROWS 0x00E4
#define SBM_SETSCROLLINFO 0x00E9
#define SBM_GETSCROLLINFO 0x00EA
#define SBM_GETSCROLLBARINFO 0x00EB
#define SIF_RANGE 0x0001
#define SIF_PAGE 0x0002
#define SIF_POS 0x0004
#define SIF_DISABLENOSCROLL 0x0008
#define SIF_TRACKPOS 0x0010
#define SIF_ALL (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)
#define DefFrameProc DefFrameProcW
#define DefFrameProc DefFrameProcA
#define DefMDIChildProc DefMDIChildProcW
#define DefMDIChildProc DefMDIChildProcA
#define CreateMDIWindow CreateMDIWindowW
#define CreateMDIWindow CreateMDIWindowA
#define WinHelp WinHelpW
#define WinHelp WinHelpA
#define GR_GDIOBJECTS 0
#define GR_USEROBJECTS 1
#define SPI_GETMOUSE 0x0003
#define SPI_SETMOUSE 0x0004
#define SPI_GETFONTSMOOTHING 0x004A
#define SPI_SETFONTSMOOTHING 0x004B
#define SPI_SETCURSORS 0x0057
#define SPI_SETSCREENSAVERRUNNING 0x0061
#define SPI_GETKEYBOARDCUES 0x100A
#define SPI_SETKEYBOARDCUES 0x100B
#define SPI_GETMOUSECLICKLOCK 0x101E
#define SPI_SETMOUSECLICKLOCK 0x101F
#define SPIF_SENDWININICHANGE 0x0002
#define CDS_RESET 0x40000000
#define ChangeDisplaySettings ChangeDisplaySettingsW
#define ChangeDisplaySettings ChangeDisplaySettingsA
#define ChangeDisplaySettingsEx ChangeDisplaySettingsExW
#define ChangeDisplaySettingsEx ChangeDisplaySettingsExA
#define EnumDisplaySettings EnumDisplaySettingsW
#define EnumDisplaySettings EnumDisplaySettingsA
#define EnumDisplaySettingsEx EnumDisplaySettingsExW
#define EnumDisplaySettingsEx EnumDisplaySettingsExA
#define EnumDisplayDevices EnumDisplayDevicesW
#define EnumDisplayDevices EnumDisplayDevicesA
#define SystemParametersInfo SystemParametersInfoW
#define SystemParametersInfo SystemParametersInfoA
#define GetMonitorInfo GetMonitorInfoW
#define GetMonitorInfo GetMonitorInfoA
#define CONSOLE_APPLICATION_16BIT 0x0000
#define CONSOLE_APPLICATION_16BIT 0x0001
#define EVENT_CONSOLE_END 0x40FF
#define EVENT_OBJECT_SELECTION 0x8006
#define GUI_16BITTASK 0x00000000
#define GUI_16BITTASK 0x00000020
#define GetWindowModuleFileName GetWindowModuleFileNameW
#define GetWindowModuleFileName GetWindowModuleFileNameA
#define STATE_SYSTEM_MIXED 0x00000020
#define GA_ROOT 2
#define RealGetWindowClass RealGetWindowClassW
#define RealGetWindowClass RealGetWindowClassA
#define GetAltTabInfo GetAltTabInfoW
#define GetAltTabInfo GetAltTabInfoA
#define RIM_INPUT 0
#define RI_MOUSE_LEFT_BUTTON_DOWN 0x0001
#define RI_MOUSE_LEFT_BUTTON_UP 0x0002
#define RI_MOUSE_RIGHT_BUTTON_DOWN 0x0004
#define RI_MOUSE_RIGHT_BUTTON_UP 0x0008
#define RI_MOUSE_MIDDLE_BUTTON_DOWN 0x0010
#define RI_MOUSE_MIDDLE_BUTTON_UP 0x0020
#define GetRawInputDeviceInfo GetRawInputDeviceInfoW
#define GetRawInputDeviceInfo GetRawInputDeviceInfoA
#define GID_PRESSANDTAP 7
#define GC_PAN 0x00000001
#define GC_PRESSANDTAP 0x00000001
#define WINCOMMCTRLAPI DECLSPEC_IMPORT
#define WINCOMMCTRLAPI
#define DUMMYUNIONNAME u
#define DUMMYUNIONNAME2 u2
#define DUMMYUNIONNAME3 u3
#define DUMMYUNIONNAME4 u4
#define DUMMYUNIONNAME5 u5
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#define SNDMSG ::SendMessage
#define SNDMSG ::AfxSendMessage
#define SNDMSG SendMessage
#define SNDMSG AfxSendMessage
#define ICC_LISTVIEW_CLASSES 0x00000001
#define ICC_TREEVIEW_CLASSES 0x00000002
#define ICC_BAR_CLASSES 0x00000004
#define ICC_TAB_CLASSES 0x00000008
#define ICC_UPDOWN_CLASS 0x00000010
#define ICC_PROGRESS_CLASS 0x00000020
#define ICC_HOTKEY_CLASS 0x00000040
#define ICC_ANIMATE_CLASS 0x00000080
#define ICC_WIN95_CLASSES 0x000000FF
#define ICC_DATE_CLASSES 0x00000100
#define ICC_USEREX_CLASSES 0x00000200
#define ICC_COOL_CLASSES 0x00000400
#define ICC_INTERNET_CLASSES 0x00000800
#define ICC_PAGESCROLLER_CLASS 0x00001000
#define ICC_NATIVEFNTCTL_CLASS 0x00002000
#define ICC_STANDARD_CLASSES 0x00004000
#define ICC_LINK_CLASS 0x00008000
#define ODT_TAB 101
#define ODT_LISTVIEW 102
#define LVM_FIRST 0x1000
#define TV_FIRST 0x1100
#define HDM_FIRST 0x1200
#define TCM_FIRST 0x1300
#define PGM_FIRST 0x1400
#define ECM_FIRST 0x1500
#define BCM_FIRST 0x1600
#define CBM_FIRST 0x1700
#define CCM_FIRST 0x2000
#define CCM_SETBKCOLOR (CCM_FIRST + 1)
#define CCM_SETCOLORSCHEME (CCM_FIRST + 2)
#define CCM_GETCOLORSCHEME (CCM_FIRST + 3)
#define CCM_GETDROPTARGET (CCM_FIRST + 4)
#define CCM_SETUNICODEFORMAT (CCM_FIRST + 5)
#define CCM_GETUNICODEFORMAT (CCM_FIRST + 6)
#define COMCTL32_VERSION 6
#define COMCTL32_VERSION 5
#define CCM_SETWINDOWTHEME (CCM_FIRST + 0xb)
#define NM_FIRST (0U- 0U)
#define LVN_FIRST (0U-100U)
#define HDN_FIRST (0U-300U)
#define TVN_FIRST (0U-400U)
#define TTN_FIRST (0U-520U)
#define TCN_FIRST (0U-550U)
#define TBN_FIRST (0U-700U)
#define UDN_FIRST (0U-721U)
#define DTN_FIRST (0U-740U)
#define DTN_LAST (0U-745U)
#define MCN_FIRST (0U-746U)
#define DTN_FIRST2 (0U-753U)
#define CBEN_FIRST (0U-800U)
#define RBN_FIRST (0U-831U)
#define RBN_LAST (0U-859U)
#define IPN_FIRST (0U-860U)
#define SBN_FIRST (0U-880U)
#define PGN_FIRST (0U-900U)
#define BCN_FIRST (0U-1250U)
#define TRBN_FIRST (0U-1501U)
#define EN_FIRST (0U-1520U)
#define EN_LAST (0U-1540U)
#define CDDS_PREPAINT 0x00000001
#define CDDS_POSTPAINT 0x00000002
#define CDDS_PREERASE 0x00000003
#define CDDS_POSTERASE 0x00000004
#define CDDS_ITEM 0x00010000
#define CLR_DEFAULT 0xFF000000L
#define ILC_COLOR 0x00000000
#define ILD_BLEND25 0x00000002
#define ILD_BLEND50 0x00000004
#define ILD_BLEND ILD_BLEND50
#define ImageList_LoadImage ImageList_LoadImageW
#define ImageList_LoadImage ImageList_LoadImageA
#define WC_HEADERA "SysHeader32"
#define WC_HEADERW L"SysHeader32"
#define WC_HEADER WC_HEADERW
#define WC_HEADER WC_HEADERA
#define WC_HEADER "SysHeader"
#define HD_TEXTFILTER HD_TEXTFILTERW
#define HDTEXTFILTER HD_TEXTFILTERW
#define LPHD_TEXTFILTER LPHD_TEXTFILTERW
#define LPHDTEXTFILTER LPHD_TEXTFILTERW
#define HD_TEXTFILTER HD_TEXTFILTERA
#define HDTEXTFILTER HD_TEXTFILTERA
#define LPHD_TEXTFILTER LPHD_TEXTFILTERA
#define LPHDTEXTFILTER LPHD_TEXTFILTERA
#define HD_ITEM HDITEM
#define HDITEMA_V1_SIZE CCSIZEOF_STRUCT(HDITEMA, lParam)
#define HDITEMW_V1_SIZE CCSIZEOF_STRUCT(HDITEMW, lParam)
#define HDITEM HDITEMW
#define LPHDITEM LPHDITEMW
#define HDITEM_V1_SIZE HDITEMW_V1_SIZE
#define HDITEM HDITEMA
#define LPHDITEM LPHDITEMA
#define HDITEM_V1_SIZE HDITEMA_V1_SIZE
#define HDI_WIDTH 0x0001
#define HDF_BITMAP 0x2000
#define HDM_INSERTITEMA (HDM_FIRST + 1)
#define HDM_INSERTITEMW (HDM_FIRST + 10)
#define HDM_INSERTITEM HDM_INSERTITEMW
#define HDM_INSERTITEM HDM_INSERTITEMA
#define HDM_GETITEMA (HDM_FIRST + 3)
#define HDM_GETITEMW (HDM_FIRST + 11)
#define HDM_GETITEM HDM_GETITEMW
#define HDM_GETITEM HDM_GETITEMA
#define HDM_SETITEMA (HDM_FIRST + 4)
#define HDM_SETITEMW (HDM_FIRST + 12)
#define HDM_SETITEM HDM_SETITEMW
#define HDM_SETITEM HDM_SETITEMA
#define HHT_ONFILTER 0x0010
#define HDN_ITEMCHANGINGA (HDN_FIRST-0)
#define HDN_ITEMCHANGINGW (HDN_FIRST-20)
#define HDN_ITEMCHANGEDA (HDN_FIRST-1)
#define HDN_ITEMCHANGEDW (HDN_FIRST-21)
#define HDN_ITEMCLICKA (HDN_FIRST-2)
#define HDN_ITEMCLICKW (HDN_FIRST-22)
#define HDN_ITEMDBLCLICKA (HDN_FIRST-3)
#define HDN_ITEMDBLCLICKW (HDN_FIRST-23)
#define HDN_DIVIDERDBLCLICKA (HDN_FIRST-5)
#define HDN_DIVIDERDBLCLICKW (HDN_FIRST-25)
#define HDN_BEGINTRACKA (HDN_FIRST-6)
#define HDN_BEGINTRACKW (HDN_FIRST-26)
#define HDN_ENDTRACKA (HDN_FIRST-7)
#define HDN_ENDTRACKW (HDN_FIRST-27)
#define HDN_TRACKA (HDN_FIRST-8)
#define HDN_TRACKW (HDN_FIRST-28)
#define HDN_GETDISPINFOA (HDN_FIRST-9)
#define HDN_GETDISPINFOW (HDN_FIRST-29)
#define HDN_ITEMCHANGING HDN_ITEMCHANGINGW
#define HDN_ITEMCHANGED HDN_ITEMCHANGEDW
#define HDN_ITEMCLICK HDN_ITEMCLICKW
#define HDN_ITEMDBLCLICK HDN_ITEMDBLCLICKW
#define HDN_DIVIDERDBLCLICK HDN_DIVIDERDBLCLICKW
#define HDN_BEGINTRACK HDN_BEGINTRACKW
#define HDN_ENDTRACK HDN_ENDTRACKW
#define HDN_TRACK HDN_TRACKW
#define HDN_GETDISPINFO HDN_GETDISPINFOW
#define HDN_ITEMCHANGING HDN_ITEMCHANGINGA
#define HDN_ITEMCHANGED HDN_ITEMCHANGEDA
#define HDN_ITEMCLICK HDN_ITEMCLICKA
#define HDN_ITEMDBLCLICK HDN_ITEMDBLCLICKA
#define HDN_DIVIDERDBLCLICK HDN_DIVIDERDBLCLICKA
#define HDN_BEGINTRACK HDN_BEGINTRACKA
#define HDN_ENDTRACK HDN_ENDTRACKA
#define HDN_TRACK HDN_TRACKA
#define HDN_GETDISPINFO HDN_GETDISPINFOA
#define HD_NOTIFY NMHEADER
#define NMHEADER NMHEADERW
#define LPNMHEADER LPNMHEADERW
#define NMHEADER NMHEADERA
#define LPNMHEADER LPNMHEADERA
#define NMHDDISPINFO NMHDDISPINFOW
#define LPNMHDDISPINFO LPNMHDDISPINFOW
#define NMHDDISPINFO NMHDDISPINFOA
#define LPNMHDDISPINFO LPNMHDDISPINFOA
#define TOOLBARCLASSNAMEW L"ToolbarWindow32"
#define TOOLBARCLASSNAMEA "ToolbarWindow32"
#define TOOLBARCLASSNAME TOOLBARCLASSNAMEW
#define TOOLBARCLASSNAME TOOLBARCLASSNAMEA
#define TOOLBARCLASSNAME "ToolbarWindow"
#define TBSTYLE_BUTTON 0x0000
#define TBSTYLE_SEP 0x0001
#define TBSTYLE_CHECK 0x0002
#define TBSTYLE_GROUP 0x0004
#define TBSTYLE_CHECKGROUP (TBSTYLE_GROUP | TBSTYLE_CHECK)
#define TBSTYLE_DROPDOWN 0x0008
#define TBSTYLE_AUTOSIZE 0x0010
#define TBSTYLE_NOPREFIX 0x0020
#define BTNS_CHECK TBSTYLE_CHECK
#define STD_PRINT 14
#define VIEW_LIST 2
#define VIEW_DETAILS 3
#define TB_ADDBUTTONSA (WM_USER + 20)
#define TB_INSERTBUTTONA (WM_USER + 21)
#define TB_GETBUTTON (WM_USER + 23)
#define TBSAVEPARAMS TBSAVEPARAMSW
#define LPTBSAVEPARAMS LPTBSAVEPARAMSW
#define TBSAVEPARAMS TBSAVEPARAMSA
#define LPTBSAVEPARAMS LPTBSAVEPARAMSA
#define TB_SAVERESTOREA (WM_USER + 26)
#define TB_SAVERESTOREW (WM_USER + 76)
#define TB_ADDSTRINGA (WM_USER + 28)
#define TB_ADDSTRINGW (WM_USER + 77)
#define TB_GETBITMAP (WM_USER + 44)
#define TB_GETBUTTONTEXTA (WM_USER + 45)
#define TB_GETBUTTONTEXTW (WM_USER + 75)
#define TB_GETIMAGELIST (WM_USER + 49)
#define TB_GETBUTTONTEXT TB_GETBUTTONTEXTW
#define TB_SAVERESTORE TB_SAVERESTOREW
#define TB_ADDSTRING TB_ADDSTRINGW
#define TB_GETBUTTONTEXT TB_GETBUTTONTEXTA
#define TB_SAVERESTORE TB_SAVERESTOREA
#define TB_ADDSTRING TB_ADDSTRINGA
#define TB_SETHOTITEM (WM_USER + 72)
#define TB_MAPACCELERATORA (WM_USER + 78)
#define TB_GETINSERTMARK (WM_USER + 79)
#define TB_SETINSERTMARK (WM_USER + 80)
#define TB_MAPACCELERATORW (WM_USER + 90)
#define TB_MAPACCELERATOR TB_MAPACCELERATORW
#define TB_MAPACCELERATOR TB_MAPACCELERATORA
#define TBBUTTONINFO TBBUTTONINFOW
#define LPTBBUTTONINFO LPTBBUTTONINFOW
#define TBBUTTONINFO TBBUTTONINFOA
#define LPTBBUTTONINFO LPTBBUTTONINFOA
#define TB_GETBUTTONINFOW (WM_USER + 63)
#define TB_SETBUTTONINFOW (WM_USER + 64)
#define TB_GETBUTTONINFOA (WM_USER + 65)
#define TB_SETBUTTONINFOA (WM_USER + 66)
#define TB_GETBUTTONINFO TB_GETBUTTONINFOW
#define TB_SETBUTTONINFO TB_SETBUTTONINFOW
#define TB_GETBUTTONINFO TB_GETBUTTONINFOA
#define TB_SETBUTTONINFO TB_SETBUTTONINFOA
#define TB_INSERTBUTTONW (WM_USER + 67)
#define TB_ADDBUTTONSW (WM_USER + 68)
#define TB_INSERTBUTTON TB_INSERTBUTTONW
#define TB_ADDBUTTONS TB_ADDBUTTONSW
#define TB_INSERTBUTTON TB_INSERTBUTTONA
#define TB_ADDBUTTONS TB_ADDBUTTONSA
#define TB_GETSTRINGW (WM_USER + 91)
#define TB_GETSTRINGA (WM_USER + 92)
#define TB_GETSTRING TB_GETSTRINGW
#define TB_GETSTRING TB_GETSTRINGA
#define TBN_GETBUTTONINFOA (TBN_FIRST-0)
#define TBN_GETDISPINFOA (TBN_FIRST - 16)
#define TBN_GETDISPINFOW (TBN_FIRST - 17)
#define TBN_GETINFOTIPA (TBN_FIRST - 18)
#define TBN_GETINFOTIPW (TBN_FIRST - 19)
#define TBN_GETBUTTONINFOW (TBN_FIRST - 20)
#define TBN_GETINFOTIP TBN_GETINFOTIPW
#define NMTBGETINFOTIP NMTBGETINFOTIPW
#define LPNMTBGETINFOTIP LPNMTBGETINFOTIPW
#define TBN_GETINFOTIP TBN_GETINFOTIPA
#define NMTBGETINFOTIP NMTBGETINFOTIPA
#define LPNMTBGETINFOTIP LPNMTBGETINFOTIPA
#define TBN_GETDISPINFO TBN_GETDISPINFOW
#define NMTBDISPINFO NMTBDISPINFOW
#define LPNMTBDISPINFO LPNMTBDISPINFOW
#define TBN_GETDISPINFO TBN_GETDISPINFOA
#define NMTBDISPINFO NMTBDISPINFOA
#define LPNMTBDISPINFO LPNMTBDISPINFOA
#define TBN_GETBUTTONINFO TBN_GETBUTTONINFOW
#define TBN_GETBUTTONINFO TBN_GETBUTTONINFOA
#define TBNOTIFYA NMTOOLBARA
#define TBNOTIFYW NMTOOLBARW
#define TBNOTIFY NMTOOLBAR
#define LPTBNOTIFY LPNMTOOLBAR
#define NMTOOLBAR NMTOOLBARW
#define LPNMTOOLBAR LPNMTOOLBARW
#define NMTOOLBAR NMTOOLBARA
#define LPNMTOOLBAR LPNMTOOLBARA
#define REBARCLASSNAMEW L"ReBarWindow32"
#define REBARCLASSNAMEA "ReBarWindow32"
#define REBARCLASSNAME REBARCLASSNAMEW
#define REBARCLASSNAME REBARCLASSNAMEA
#define REBARCLASSNAME "ReBarWindow"
#define RBBIM_CHILD 0x00000010
#define RBBIM_ID 0x00000100
#define REBARBANDINFOA_V3_SIZE CCSIZEOF_STRUCT(REBARBANDINFOA, wID)
#define REBARBANDINFOW_V3_SIZE CCSIZEOF_STRUCT(REBARBANDINFOW, wID)
#define REBARBANDINFOA_V6_SIZE CCSIZEOF_STRUCT(REBARBANDINFOA, cxHeader)
#define REBARBANDINFOW_V6_SIZE CCSIZEOF_STRUCT(REBARBANDINFOW, cxHeader)
#define REBARBANDINFO REBARBANDINFOW
#define LPREBARBANDINFO LPREBARBANDINFOW
#define LPCREBARBANDINFO LPCREBARBANDINFOW
#define REBARBANDINFO_V3_SIZE REBARBANDINFOW_V3_SIZE
#define REBARBANDINFO_V6_SIZE REBARBANDINFOW_V6_SIZE
#define REBARBANDINFO REBARBANDINFOA
#define LPREBARBANDINFO LPREBARBANDINFOA
#define LPCREBARBANDINFO LPCREBARBANDINFOA
#define REBARBANDINFO_V3_SIZE REBARBANDINFOA_V3_SIZE
#define REBARBANDINFO_V6_SIZE REBARBANDINFOA_V6_SIZE
#define RB_INSERTBANDA (WM_USER + 1)
#define RB_SETBANDINFOA (WM_USER + 6)
#define RB_INSERTBANDW (WM_USER + 10)
#define RB_SETBANDINFOW (WM_USER + 11)
#define RB_INSERTBAND RB_INSERTBANDW
#define RB_SETBANDINFO RB_SETBANDINFOW
#define RB_INSERTBAND RB_INSERTBANDA
#define RB_SETBANDINFO RB_SETBANDINFOA
#define RB_GETBANDINFOW (WM_USER + 28)
#define RB_GETBANDINFOA (WM_USER + 29)
#define RB_GETBANDINFO RB_GETBANDINFOW
#define RB_GETBANDINFO RB_GETBANDINFOA
#define TOOLTIPS_CLASSW L"tooltips_class32"
#define TOOLTIPS_CLASSA "tooltips_class32"
#define TOOLTIPS_CLASS TOOLTIPS_CLASSW
#define TOOLTIPS_CLASS TOOLTIPS_CLASSA
#define TOOLTIPS_CLASS "tooltips_class"
#define TOOLINFOA TTTOOLINFOA
#define TOOLINFOW TTTOOLINFOW
#define LPTOOLINFO LPTTTOOLINFO
#define TOOLINFO TTTOOLINFO
#define TTTOOLINFOA_V1_SIZE CCSIZEOF_STRUCT(TTTOOLINFOA, lpszText)
#define TTTOOLINFOW_V1_SIZE CCSIZEOF_STRUCT(TTTOOLINFOW, lpszText)
#define TTTOOLINFO TTTOOLINFOW
#define PTOOLINFO PTOOLINFOW
#define LPTTTOOLINFO LPTTTOOLINFOW
#define TTTOOLINFO_V1_SIZE TTTOOLINFOW_V1_SIZE
#define PTOOLINFO PTOOLINFOA
#define TTTOOLINFO TTTOOLINFOA
#define LPTTTOOLINFO LPTTTOOLINFOA
#define TTTOOLINFO_V1_SIZE TTTOOLINFOA_V1_SIZE
#define TTI_INFO 1
#define TTI_WARNING 2
#define TTI_ERROR 3
#define TTM_ADDTOOLA (WM_USER + 4)
#define TTM_ADDTOOLW (WM_USER + 50)
#define TTM_DELTOOLA (WM_USER + 5)
#define TTM_DELTOOLW (WM_USER + 51)
#define TTM_NEWTOOLRECTA (WM_USER + 6)
#define TTM_NEWTOOLRECTW (WM_USER + 52)
#define TTM_GETTOOLINFOA (WM_USER + 8)
#define TTM_GETTOOLINFOW (WM_USER + 53)
#define TTM_SETTOOLINFOA (WM_USER + 9)
#define TTM_SETTOOLINFOW (WM_USER + 54)
#define TTM_HITTESTA (WM_USER +10)
#define TTM_HITTESTW (WM_USER +55)
#define TTM_GETTEXTA (WM_USER +11)
#define TTM_GETTEXTW (WM_USER +56)
#define TTM_UPDATETIPTEXTA (WM_USER +12)
#define TTM_UPDATETIPTEXTW (WM_USER +57)
#define TTM_ENUMTOOLSA (WM_USER +14)
#define TTM_ENUMTOOLSW (WM_USER +58)
#define TTM_GETCURRENTTOOLA (WM_USER + 15)
#define TTM_GETCURRENTTOOLW (WM_USER + 59)
#define TTM_POP (WM_USER + 28)
#define TTM_UPDATE (WM_USER + 29)
#define TTM_SETTITLEA (WM_USER + 32)
#define TTM_SETTITLEW (WM_USER + 33)
#define TTM_ADDTOOL TTM_ADDTOOLW
#define TTM_DELTOOL TTM_DELTOOLW
#define TTM_NEWTOOLRECT TTM_NEWTOOLRECTW
#define TTM_GETTOOLINFO TTM_GETTOOLINFOW
#define TTM_SETTOOLINFO TTM_SETTOOLINFOW
#define TTM_HITTEST TTM_HITTESTW
#define TTM_GETTEXT TTM_GETTEXTW
#define TTM_UPDATETIPTEXT TTM_UPDATETIPTEXTW
#define TTM_ENUMTOOLS TTM_ENUMTOOLSW
#define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLW
#define TTM_SETTITLE TTM_SETTITLEW
#define TTM_ADDTOOL TTM_ADDTOOLA
#define TTM_DELTOOL TTM_DELTOOLA
#define TTM_NEWTOOLRECT TTM_NEWTOOLRECTA
#define TTM_GETTOOLINFO TTM_GETTOOLINFOA
#define TTM_SETTOOLINFO TTM_SETTOOLINFOA
#define TTM_HITTEST TTM_HITTESTA
#define TTM_GETTEXT TTM_GETTEXTA
#define TTM_UPDATETIPTEXT TTM_UPDATETIPTEXTA
#define TTM_ENUMTOOLS TTM_ENUMTOOLSA
#define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLA
#define TTM_SETTITLE TTM_SETTITLEA
#define LPHITTESTINFO LPTTHITTESTINFO
#define TTHITTESTINFO TTHITTESTINFOW
#define LPTTHITTESTINFO LPTTHITTESTINFOW
#define TTHITTESTINFO TTHITTESTINFOA
#define LPTTHITTESTINFO LPTTHITTESTINFOA
#define TTN_GETDISPINFOA (TTN_FIRST - 0)
#define TTN_GETDISPINFOW (TTN_FIRST - 10)
#define TTN_GETDISPINFO TTN_GETDISPINFOW
#define TTN_GETDISPINFO TTN_GETDISPINFOA
#define TTN_NEEDTEXT TTN_GETDISPINFO
#define TOOLTIPTEXTW NMTTDISPINFOW
#define TOOLTIPTEXTA NMTTDISPINFOA
#define TOOLTIPTEXT NMTTDISPINFO
#define LPTOOLTIPTEXT LPNMTTDISPINFO
#define NMTTDISPINFOA_V1_SIZE CCSIZEOF_STRUCT(NMTTDISPINFOA, uFlags)
#define NMTTDISPINFOW_V1_SIZE CCSIZEOF_STRUCT(NMTTDISPINFOW, uFlags)
#define NMTTDISPINFO NMTTDISPINFOW
#define LPNMTTDISPINFO LPNMTTDISPINFOW
#define NMTTDISPINFO_V1_SIZE NMTTDISPINFOW_V1_SIZE
#define NMTTDISPINFO NMTTDISPINFOA
#define LPNMTTDISPINFO LPNMTTDISPINFOA
#define NMTTDISPINFO_V1_SIZE NMTTDISPINFOA_V1_SIZE
#define CreateStatusWindow CreateStatusWindowW
#define DrawStatusText DrawStatusTextW
#define CreateStatusWindow CreateStatusWindowA
#define DrawStatusText DrawStatusTextA
#define STATUSCLASSNAMEW L"msctls_statusbar32"
#define STATUSCLASSNAMEA "msctls_statusbar32"
#define STATUSCLASSNAME STATUSCLASSNAMEW
#define STATUSCLASSNAME STATUSCLASSNAMEA
#define STATUSCLASSNAME "msctls_statusbar"
#define SB_SETTEXTA (WM_USER+1)
#define SB_SETTEXTW (WM_USER+11)
#define SB_GETTEXTA (WM_USER+2)
#define SB_GETTEXTW (WM_USER+13)
#define SB_GETTEXTLENGTHA (WM_USER+3)
#define SB_GETTEXTLENGTHW (WM_USER+12)
#define SB_GETTEXT SB_GETTEXTW
#define SB_SETTEXT SB_SETTEXTW
#define SB_GETTEXTLENGTH SB_GETTEXTLENGTHW
#define SB_SETTIPTEXT SB_SETTIPTEXTW
#define SB_GETTIPTEXT SB_GETTIPTEXTW
#define SB_GETTEXT SB_GETTEXTA
#define SB_SETTEXT SB_SETTEXTA
#define SB_GETTEXTLENGTH SB_GETTEXTLENGTHA
#define SB_SETTIPTEXT SB_SETTIPTEXTA
#define SB_GETTIPTEXT SB_GETTIPTEXTA
#define SB_SIMPLE (WM_USER+9)
#define SB_SETTIPTEXTA (WM_USER+16)
#define SB_SETTIPTEXTW (WM_USER+17)
#define SB_GETTIPTEXTA (WM_USER+18)
#define SB_GETTIPTEXTW (WM_USER+19)
#define TRACKBAR_CLASSA "msctls_trackbar32"
#define TRACKBAR_CLASSW L"msctls_trackbar32"
#define TRACKBAR_CLASS TRACKBAR_CLASSW
#define TRACKBAR_CLASS TRACKBAR_CLASSA
#define TRACKBAR_CLASS "msctls_trackbar"
#define TBS_AUTOTICKS 0x0001
#define TBS_VERT 0x0002
#define TBS_HORZ 0x0000
#define TBS_TOP 0x0004
#define TBS_BOTTOM 0x0000
#define TBS_LEFT 0x0004
#define TBS_RIGHT 0x0000
#define TBS_BOTH 0x0008
#define TBS_NOTICKS 0x0010
#define TBS_ENABLESELRANGE 0x0020
#define TBS_FIXEDLENGTH 0x0040
#define TBS_NOTHUMB 0x0080
#define TBS_TOOLTIPS 0x0100
#define TBS_REVERSED 0x0200
#define TBS_DOWNISLEFT 0x0400
#define TBS_NOTIFYBEFOREMOVE 0x0800
#define TBS_TRANSPARENTBKGND 0x1000
#define TBM_GETPOS (WM_USER)
#define TBM_GETRANGEMIN (WM_USER+1)
#define TBM_GETRANGEMAX (WM_USER+2)
#define TBM_GETTIC (WM_USER+3)
#define TBM_SETTIC (WM_USER+4)
#define TBM_SETPOS (WM_USER+5)
#define TBM_SETRANGE (WM_USER+6)
#define TBM_SETRANGEMIN (WM_USER+7)
#define TBM_SETRANGEMAX (WM_USER+8)
#define TBM_CLEARTICS (WM_USER+9)
#define TBM_SETSEL (WM_USER+10)
#define TBM_SETSELSTART (WM_USER+11)
#define TBM_SETSELEND (WM_USER+12)
#define TBM_GETPTICS (WM_USER+14)
#define TBM_GETTICPOS (WM_USER+15)
#define TBM_GETNUMTICS (WM_USER+16)
#define TBM_GETSELSTART (WM_USER+17)
#define TBM_GETSELEND (WM_USER+18)
#define TBM_CLEARSEL (WM_USER+19)
#define TBM_SETTICFREQ (WM_USER+20)
#define TBM_SETPAGESIZE (WM_USER+21)
#define TBM_GETPAGESIZE (WM_USER+22)
#define TBM_SETLINESIZE (WM_USER+23)
#define TBM_GETLINESIZE (WM_USER+24)
#define TBM_GETTHUMBRECT (WM_USER+25)
#define TBM_GETCHANNELRECT (WM_USER+26)
#define TBM_SETTHUMBLENGTH (WM_USER+27)
#define TBM_GETTHUMBLENGTH (WM_USER+28)
#define TBM_SETTOOLTIPS (WM_USER+29)
#define TBM_GETTOOLTIPS (WM_USER+30)
#define TBM_SETTIPSIDE (WM_USER+31)
#define TBTS_TOP 0
#define TBTS_LEFT 1
#define TBTS_BOTTOM 2
#define TBTS_RIGHT 3
#define TBM_SETBUDDY (WM_USER+32)
#define TBM_GETBUDDY (WM_USER+33)
#define TBM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define TBM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define TB_LINEUP 0
#define TB_LINEDOWN 1
#define TB_PAGEUP 2
#define TB_PAGEDOWN 3
#define TB_THUMBPOSITION 4
#define TB_THUMBTRACK 5
#define TB_TOP 6
#define TB_BOTTOM 7
#define TB_ENDTRACK 8
#define TBCD_TICS 0x0001
#define TBCD_THUMB 0x0002
#define TBCD_CHANNEL 0x0003
#define TRBN_THUMBPOSCHANGING (TRBN_FIRST-1)
#define UPDOWN_CLASSA "msctls_updown32"
#define UPDOWN_CLASSW L"msctls_updown32"
#define UPDOWN_CLASS UPDOWN_CLASSW
#define UPDOWN_CLASS UPDOWN_CLASSA
#define UPDOWN_CLASS "msctls_updown"
#define UD_MAXVAL 0x7fff
#define UDM_SETRANGE (WM_USER+101)
#define UDM_GETRANGE (WM_USER+102)
#define UDM_SETPOS (WM_USER+103)
#define UDM_GETPOS (WM_USER+104)
#define NM_UPDOWN NMUPDOWN
#define PROGRESS_CLASSA "msctls_progress32"
#define PROGRESS_CLASSW L"msctls_progress32"
#define PROGRESS_CLASS PROGRESS_CLASSW
#define PROGRESS_CLASS PROGRESS_CLASSA
#define PROGRESS_CLASS "msctls_progress"
#define PBS_SMOOTH 0x01
#define PBS_VERTICAL 0x04
#define PBM_SETRANGE (WM_USER+1)
#define PBM_SETPOS (WM_USER+2)
#define PBM_DELTAPOS (WM_USER+3)
#define PBM_SETSTEP (WM_USER+4)
#define PBM_STEPIT (WM_USER+5)
#define PBM_SETRANGE32 (WM_USER+6)
#define PBM_GETRANGE (WM_USER+7)
#define PBM_GETPOS (WM_USER+8)
#define PBM_SETBARCOLOR (WM_USER+9)
#define PBM_SETBKCOLOR CCM_SETBKCOLOR
#define PBS_MARQUEE 0x08
#define PBM_SETMARQUEE (WM_USER+10)
#define PBS_SMOOTHREVERSE 0x10
#define PBM_GETSTEP (WM_USER+13)
#define PBM_GETBKCOLOR (WM_USER+14)
#define PBM_GETBARCOLOR (WM_USER+15)
#define PBM_SETSTATE (WM_USER+16)
#define PBM_GETSTATE (WM_USER+17)
#define PBST_NORMAL 0x0001
#define PBST_ERROR 0x0002
#define PBST_PAUSED 0x0003
#define HOTKEYF_EXT 0x80
#define HOTKEYF_EXT 0x08
#define HKCOMB_S 0x0002
#define HKCOMB_C 0x0004
#define HKCOMB_SC 0x0010
#define HOTKEY_CLASSA "msctls_hotkey32"
#define HOTKEY_CLASSW L"msctls_hotkey32"
#define HOTKEY_CLASS HOTKEY_CLASSW
#define HOTKEY_CLASS HOTKEY_CLASSA
#define HOTKEY_CLASS "msctls_hotkey"
#define CCS_TOP 0x00000001L
#define CCS_NOMOVEY 0x00000002L
#define CCS_BOTTOM 0x00000003L
#define CCS_VERT 0x00000080L
// #define WC_LINK L"SysLink"
#define WC_LINK "SysLink"
#define LM_GETIDEALHEIGHT (WM_USER+0x301)
#define WC_LISTVIEWA "SysListView32"
#define WC_LISTVIEWW L"SysListView32"
#define WC_LISTVIEW WC_LISTVIEWW
#define WC_LISTVIEW WC_LISTVIEWA
#define WC_LISTVIEW "SysListView"
#define LVS_ICON 0x0000
#define LVS_REPORT 0x0001
#define LVS_SMALLICON 0x0002
#define LVS_LIST 0x0003
#define LVS_TYPEMASK 0x0003
#define LVS_SINGLESEL 0x0004
#define LVS_SHOWSELALWAYS 0x0008
#define LVS_SORTASCENDING 0x0010
#define LVS_SORTDESCENDING 0x0020
#define LVS_SHAREIMAGELISTS 0x0040
#define LVS_NOLABELWRAP 0x0080
#define LVS_AUTOARRANGE 0x0100
#define LVS_EDITLABELS 0x0200
#define LVS_OWNERDATA 0x1000
#define LVS_NOSCROLL 0x2000
#define LVS_TYPESTYLEMASK 0xfc00
#define LVS_ALIGNTOP 0x0000
#define LVS_ALIGNLEFT 0x0800
#define LVS_ALIGNMASK 0x0c00
#define LVS_OWNERDRAWFIXED 0x0400
#define LVS_NOCOLUMNHEADER 0x4000
#define LVS_NOSORTHEADER 0x8000
#define LVM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define LVM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define LVM_GETBKCOLOR (LVM_FIRST + 0)
#define LVM_SETBKCOLOR (LVM_FIRST + 1)
#define LVM_GETIMAGELIST (LVM_FIRST + 2)
#define LVM_SETIMAGELIST (LVM_FIRST + 3)
#define LVM_GETITEMCOUNT (LVM_FIRST + 4)
#define LV_ITEM LVITEM
#define LVITEMA_V1_SIZE CCSIZEOF_STRUCT(LVITEMA, lParam)
#define LVITEMW_V1_SIZE CCSIZEOF_STRUCT(LVITEMW, lParam)
#define LVITEMA_V5_SIZE CCSIZEOF_STRUCT(LVITEMA, puColumns)
#define LVITEMW_V5_SIZE CCSIZEOF_STRUCT(LVITEMW, puColumns)
#define LVITEM_V5_SIZE LVITEMW_V5_SIZE
#define LVITEM_V5_SIZE LVITEMA_V5_SIZE
#define LVITEM LVITEMW
#define LPLVITEM LPLVITEMW
#define LVITEM_V1_SIZE LVITEMW_V1_SIZE
#define LVITEM LVITEMA
#define LPLVITEM LPLVITEMA
#define LVITEM_V1_SIZE LVITEMA_V1_SIZE
#define LPSTR_TEXTCALLBACKW ((LPWSTR)-1L)
#define LPSTR_TEXTCALLBACKA ((LPSTR)-1L)
#define LPSTR_TEXTCALLBACK LPSTR_TEXTCALLBACKW
#define LPSTR_TEXTCALLBACK LPSTR_TEXTCALLBACKA
#define LVM_GETITEMA (LVM_FIRST + 5)
#define LVM_GETITEMW (LVM_FIRST + 75)
#define LVM_GETITEM LVM_GETITEMW
#define LVM_GETITEM LVM_GETITEMA
#define LVM_SETITEMA (LVM_FIRST + 6)
#define LVM_SETITEMW (LVM_FIRST + 76)
#define LVM_SETITEM LVM_SETITEMW
#define LVM_SETITEM LVM_SETITEMA
#define LVM_INSERTITEMA (LVM_FIRST + 7)
#define LVM_INSERTITEMW (LVM_FIRST + 77)
#define LVM_INSERTITEM LVM_INSERTITEMW
#define LVM_INSERTITEM LVM_INSERTITEMA
#define LVM_DELETEITEM (LVM_FIRST + 8)
#define LVM_DELETEALLITEMS (LVM_FIRST + 9)
#define LVM_GETCALLBACKMASK (LVM_FIRST + 10)
#define LVM_SETCALLBACKMASK (LVM_FIRST + 11)
#define LVNI_ALL 0x0000
#define LVNI_FOCUSED 0x0001
#define LVNI_SELECTED 0x0002
#define LVNI_CUT 0x0004
#define LVNI_DROPHILITED 0x0008
#define LVNI_STATEMASK (LVNI_FOCUSED | LVNI_SELECTED | LVNI_CUT | LVNI_DROPHILITED)
#define LVNI_VISIBLEORDER 0x0010
#define LVNI_PREVIOUS 0x0020
#define LVNI_VISIBLEONLY 0x0040
#define LVNI_SAMEGROUPONLY 0x0080
#define LVNI_ABOVE 0x0100
#define LVNI_BELOW 0x0200
#define LVNI_TOLEFT 0x0400
#define LVNI_TORIGHT 0x0800
#define LVNI_DIRECTIONMASK (LVNI_ABOVE | LVNI_BELOW | LVNI_TOLEFT | LVNI_TORIGHT)
#define LVM_GETNEXTITEM (LVM_FIRST + 12)
#define LV_FINDINFO LVFINDINFO
#define LVFINDINFO LVFINDINFOW
#define LVFINDINFO LVFINDINFOA
#define LVM_FINDITEMA (LVM_FIRST + 13)
#define LVM_FINDITEMW (LVM_FIRST + 83)
#define LVM_FINDITEM LVM_FINDITEMW
#define LVM_FINDITEM LVM_FINDITEMA
#define LVM_GETITEMRECT (LVM_FIRST + 14)
#define LVM_SETITEMPOSITION (LVM_FIRST + 15)
#define LVM_GETITEMPOSITION (LVM_FIRST + 16)
#define LVM_GETSTRINGWIDTHA (LVM_FIRST + 17)
#define LVM_GETSTRINGWIDTHW (LVM_FIRST + 87)
#define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHW
#define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHA
#define LVHT_ONITEMICON 0x00000002
#define LVHT_ONITEMLABEL 0x00000004
#define LVHT_ONITEMSTATEICON 0x00000008
#define LVHT_ONITEM (LVHT_ONITEMICON | LVHT_ONITEMLABEL | LVHT_ONITEMSTATEICON)
#define LVHT_EX_GROUP_HEADER 0x10000000
#define LVHT_EX_GROUP_FOOTER 0x20000000
#define LVHT_EX_GROUP_COLLAPSE 0x40000000
#define LVHT_EX_GROUP_BACKGROUND 0x80000000
#define LVHT_EX_GROUP_STATEICON 0x01000000
#define LVHT_EX_GROUP_SUBSETLINK 0x02000000
#define LVHT_EX_GROUP (LVHT_EX_GROUP_BACKGROUND | LVHT_EX_GROUP_COLLAPSE | LVHT_EX_GROUP_FOOTER | LVHT_EX_GROUP_HEADER | LVHT_EX_GROUP_STATEICON | LVHT_EX_GROUP_SUBSETLINK)
#define LVM_HITTEST (LVM_FIRST + 18)
#define LVM_ENSUREVISIBLE (LVM_FIRST + 19)
#define LVM_SCROLL (LVM_FIRST + 20)
#define LVM_REDRAWITEMS (LVM_FIRST + 21)
#define LVM_ARRANGE (LVM_FIRST + 22)
#define LVM_EDITLABELA (LVM_FIRST + 23)
#define LVM_EDITLABELW (LVM_FIRST + 118)
#define LVM_EDITLABEL LVM_EDITLABELW
#define LVM_EDITLABEL LVM_EDITLABELA
#define LVM_GETEDITCONTROL (LVM_FIRST + 24)
#define LV_COLUMN LVCOLUMN
#define LVCOLUMNA_V1_SIZE CCSIZEOF_STRUCT(LVCOLUMNA, iSubItem)
#define LVCOLUMNW_V1_SIZE CCSIZEOF_STRUCT(LVCOLUMNW, iSubItem)
#define LVCOLUMN LVCOLUMNW
#define LPLVCOLUMN LPLVCOLUMNW
#define LVCOLUMN_V1_SIZE LVCOLUMNW_V1_SIZE
#define LVCOLUMN LVCOLUMNA
#define LPLVCOLUMN LPLVCOLUMNA
#define LVCOLUMN_V1_SIZE LVCOLUMNA_V1_SIZE
#define LVCFMT_LINE_BREAK 0x100000
#define LVCFMT_FILL 0x200000
#define LVM_GETCOLUMNA (LVM_FIRST + 25)
#define LVM_GETCOLUMNW (LVM_FIRST + 95)
#define LVM_GETCOLUMN LVM_GETCOLUMNW
#define LVM_GETCOLUMN LVM_GETCOLUMNA
#define LVM_SETCOLUMNA (LVM_FIRST + 26)
#define LVM_SETCOLUMNW (LVM_FIRST + 96)
#define LVM_SETCOLUMN LVM_SETCOLUMNW
#define LVM_SETCOLUMN LVM_SETCOLUMNA
#define LVM_INSERTCOLUMNA (LVM_FIRST + 27)
#define LVM_INSERTCOLUMNW (LVM_FIRST + 97)
#define LVM_DELETECOLUMN (LVM_FIRST + 28)
#define LVM_GETCOLUMNWIDTH (LVM_FIRST + 29)
#define LVSCW_AUTOSIZE -1
#define LVM_SETCOLUMNWIDTH (LVM_FIRST + 30)
#define LVM_GETHEADER (LVM_FIRST + 31)
#define LVM_CREATEDRAGIMAGE (LVM_FIRST + 33)
#define LVM_GETVIEWRECT (LVM_FIRST + 34)
#define LVM_GETTEXTCOLOR (LVM_FIRST + 35)
#define LVM_SETTEXTCOLOR (LVM_FIRST + 36)
#define LVM_GETTEXTBKCOLOR (LVM_FIRST + 37)
#define LVM_SETTEXTBKCOLOR (LVM_FIRST + 38)
#define LVM_GETTOPINDEX (LVM_FIRST + 39)
#define LVM_GETCOUNTPERPAGE (LVM_FIRST + 40)
#define LVM_GETORIGIN (LVM_FIRST + 41)
#define LVM_UPDATE (LVM_FIRST + 42)
#define LVM_SETITEMSTATE (LVM_FIRST + 43)
#define LVM_GETITEMSTATE (LVM_FIRST + 44)
#define LVM_GETITEMTEXTA (LVM_FIRST + 45)
#define LVM_GETITEMTEXTW (LVM_FIRST + 115)
#define LVM_GETITEMTEXT LVM_GETITEMTEXTW
#define LVM_GETITEMTEXT LVM_GETITEMTEXTA
#define LVM_SETITEMTEXTA (LVM_FIRST + 46)
#define LVM_SETITEMTEXTW (LVM_FIRST + 116)
#define LVM_SETITEMTEXT LVM_SETITEMTEXTW
#define LVM_SETITEMTEXT LVM_SETITEMTEXTA
#define LVM_SETITEMCOUNT (LVM_FIRST + 47)
#define LVM_SORTITEMS (LVM_FIRST + 48)
#define LVM_SETITEMPOSITION32 (LVM_FIRST + 49)
#define LVM_GETSELECTEDCOUNT (LVM_FIRST + 50)
#define LVM_GETITEMSPACING (LVM_FIRST + 51)
#define LVM_GETISEARCHSTRINGA (LVM_FIRST + 52)
#define LVM_GETISEARCHSTRINGW (LVM_FIRST + 117)
#define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGW
#define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGA
#define LVM_SETICONSPACING (LVM_FIRST + 53)
#define LVM_SETEXTENDEDLISTVIEWSTYLE (LVM_FIRST + 54)
#define LVM_GETEXTENDEDLISTVIEWSTYLE (LVM_FIRST + 55)
#define LVS_EX_GRIDLINES 0x00000001
#define LVS_EX_SUBITEMIMAGES 0x00000002
#define LVS_EX_CHECKBOXES 0x00000004
#define LVS_EX_TRACKSELECT 0x00000008
#define LVS_EX_HEADERDRAGDROP 0x00000010
#define LVS_EX_FULLROWSELECT 0x00000020
#define LVS_EX_ONECLICKACTIVATE 0x00000040
#define LVS_EX_TWOCLICKACTIVATE 0x00000080
#define LVS_EX_FLATSB 0x00000100
#define LVS_EX_REGIONAL 0x00000200
#define LVS_EX_INFOTIP 0x00000400
#define LVS_EX_UNDERLINEHOT 0x00000800
#define LVS_EX_UNDERLINECOLD 0x00001000
#define LVS_EX_MULTIWORKAREAS 0x00002000
#define LVS_EX_LABELTIP 0x00004000
#define LVS_EX_BORDERSELECT 0x00008000
#define LVS_EX_DOUBLEBUFFER 0x00010000
#define LVS_EX_HIDELABELS 0x00020000
#define LVS_EX_SINGLEROW 0x00040000
#define LVS_EX_SNAPTOGRID 0x00080000
#define LVS_EX_SIMPLESELECT 0x00100000
#define LVS_EX_JUSTIFYCOLUMNS 0x00200000
#define LVS_EX_TRANSPARENTBKGND 0x00400000
#define LVS_EX_TRANSPARENTSHADOWTEXT 0x00800000
#define LVS_EX_AUTOAUTOARRANGE 0x01000000
#define LVS_EX_HEADERINALLVIEWS 0x02000000
#define LVS_EX_AUTOCHECKSELECT 0x08000000
#define LVS_EX_AUTOSIZECOLUMNS 0x10000000
#define LVS_EX_COLUMNSNAPPOINTS 0x40000000
#define LVS_EX_COLUMNOVERFLOW 0x80000000
#define LVM_GETSUBITEMRECT (LVM_FIRST + 56)
#define LVM_SUBITEMHITTEST (LVM_FIRST + 57)
#define LVM_SETCOLUMNORDERARRAY (LVM_FIRST + 58)
#define LVM_GETCOLUMNORDERARRAY (LVM_FIRST + 59)
#define LVM_SETHOTITEM (LVM_FIRST + 60)
#define LVM_GETHOTITEM (LVM_FIRST + 61)
#define LVM_SETHOTCURSOR (LVM_FIRST + 62)
#define LVM_GETHOTCURSOR (LVM_FIRST + 63)
#define LVM_APPROXIMATEVIEWRECT (LVM_FIRST + 64)
#define LVM_SETWORKAREAS (LVM_FIRST + 65)
#define LVM_GETWORKAREAS (LVM_FIRST + 70)
#define LVM_GETNUMBEROFWORKAREAS (LVM_FIRST + 73)
#define LVM_GETSELECTIONMARK (LVM_FIRST + 66)
#define LVM_SETSELECTIONMARK (LVM_FIRST + 67)
#define LVM_SETHOVERTIME (LVM_FIRST + 71)
#define LVM_GETHOVERTIME (LVM_FIRST + 72)
#define LVM_SETTOOLTIPS (LVM_FIRST + 74)
#define LVM_GETTOOLTIPS (LVM_FIRST + 78)
#define LVM_SORTITEMSEX (LVM_FIRST + 81)
#define LVM_SETBKIMAGEA (LVM_FIRST + 68)
#define LVM_SETBKIMAGEW (LVM_FIRST + 138)
#define LVM_GETBKIMAGEA (LVM_FIRST + 69)
#define LVM_GETBKIMAGEW (LVM_FIRST + 139)
#define LVM_SETSELECTEDCOLUMN (LVM_FIRST + 140)
#define LVM_SETVIEW (LVM_FIRST + 142)
#define LVM_GETVIEW (LVM_FIRST + 143)
#define LVGF_SUBSET 0x00008000
#define LVM_INSERTGROUP (LVM_FIRST + 145)
#define LVM_SETGROUPINFO (LVM_FIRST + 147)
#define LVM_GETGROUPINFO (LVM_FIRST + 149)
#define LVM_REMOVEGROUP (LVM_FIRST + 150)
#define LVM_MOVEGROUP (LVM_FIRST + 151)
#define LVM_GETGROUPCOUNT (LVM_FIRST + 152)
#define LVM_GETGROUPINFOBYINDEX (LVM_FIRST + 153)
#define LVM_MOVEITEMTOGROUP (LVM_FIRST + 154)
#define LVM_GETGROUPRECT (LVM_FIRST + 98)
#define LVM_SETGROUPMETRICS (LVM_FIRST + 155)
#define LVM_GETGROUPMETRICS (LVM_FIRST + 156)
#define LVM_ENABLEGROUPVIEW (LVM_FIRST + 157)
#define LVM_SORTGROUPS (LVM_FIRST + 158)
#define LVM_INSERTGROUPSORTED (LVM_FIRST + 159)
#define LVM_REMOVEALLGROUPS (LVM_FIRST + 160)
#define LVM_HASGROUP (LVM_FIRST + 161)
#define LVM_GETGROUPSTATE (LVM_FIRST + 92)
#define LVM_GETFOCUSEDGROUP (LVM_FIRST + 93)
#define LVM_SETTILEVIEWINFO (LVM_FIRST + 162)
#define LVM_GETTILEVIEWINFO (LVM_FIRST + 163)
#define LVM_SETTILEINFO (LVM_FIRST + 164)
#define LVM_GETTILEINFO (LVM_FIRST + 165)
#define LVM_SETINSERTMARK (LVM_FIRST + 166)
#define LVM_GETINSERTMARK (LVM_FIRST + 167)
#define LVM_INSERTMARKHITTEST (LVM_FIRST + 168)
#define LVM_GETINSERTMARKRECT (LVM_FIRST + 169)
#define LVM_SETINSERTMARKCOLOR (LVM_FIRST + 170)
#define LVM_GETINSERTMARKCOLOR (LVM_FIRST + 171)
#define LVM_GETSELECTEDCOLUMN (LVM_FIRST + 174)
#define LVM_ISGROUPVIEWENABLED (LVM_FIRST + 175)
#define LVM_GETOUTLINECOLOR (LVM_FIRST + 176)
#define LVM_SETOUTLINECOLOR (LVM_FIRST + 177)
#define LVM_CANCELEDITLABEL (LVM_FIRST + 179)
#define LVM_MAPINDEXTOID (LVM_FIRST + 180)
#define LVM_MAPIDTOINDEX (LVM_FIRST + 181)
#define LVM_ISITEMVISIBLE (LVM_FIRST + 182)
#define LVM_GETEMPTYTEXT (LVM_FIRST + 204)
#define LVM_GETFOOTERRECT (LVM_FIRST + 205)
#define LVM_GETFOOTERINFO (LVM_FIRST + 206)
#define LVM_GETFOOTERITEMRECT (LVM_FIRST + 207)
#define LVM_GETFOOTERITEM (LVM_FIRST + 208)
#define LVM_GETITEMINDEXRECT (LVM_FIRST + 209)
#define LVM_SETITEMINDEXSTATE (LVM_FIRST + 210)
#define LVM_GETNEXTITEMINDEX (LVM_FIRST + 211)
#define LVBKIMAGE LVBKIMAGEW
#define LPLVBKIMAGE LPLVBKIMAGEW
#define LVM_SETBKIMAGE LVM_SETBKIMAGEW
#define LVM_GETBKIMAGE LVM_GETBKIMAGEW
#define LVBKIMAGE LVBKIMAGEA
#define LPLVBKIMAGE LPLVBKIMAGEA
#define LVM_SETBKIMAGE LVM_SETBKIMAGEA
#define LVM_GETBKIMAGE LVM_GETBKIMAGEA
#define NM_LISTVIEW NMLISTVIEW
#define LVCDI_ITEM 0x00000000
#define PNM_CACHEHINT LPNMLVCACHEHINT
#define NM_CACHEHINT NMLVCACHEHINT
#define PNM_FINDITEMA LPNMLVFINDITEMA
#define LPNM_FINDITEMA LPNMLVFINDITEMA
#define NM_FINDITEMA NMLVFINDITEMA
#define PNM_FINDITEMW LPNMLVFINDITEMW
#define LPNM_FINDITEMW LPNMLVFINDITEMW
#define NM_FINDITEMW NMLVFINDITEMW
#define PNM_FINDITEM PNM_FINDITEMW
#define LPNM_FINDITEM LPNM_FINDITEMW
#define NM_FINDITEM NM_FINDITEMW
#define NMLVFINDITEM NMLVFINDITEMW
#define LPNMLVFINDITEM LPNMLVFINDITEMW
#define PNM_FINDITEM PNM_FINDITEMA
#define LPNM_FINDITEM LPNM_FINDITEMA
#define NM_FINDITEM NM_FINDITEMA
#define NMLVFINDITEM NMLVFINDITEMA
#define LPNMLVFINDITEM LPNMLVFINDITEMA
#define PNM_ODSTATECHANGE LPNMLVODSTATECHANGE
#define NM_ODSTATECHANGE NMLVODSTATECHANGE
#define LVN_ITEMCHANGING (LVN_FIRST-0)
#define LVN_ITEMCHANGED (LVN_FIRST-1)
#define LVN_INSERTITEM (LVN_FIRST-2)
#define LVN_DELETEITEM (LVN_FIRST-3)
#define LVN_DELETEALLITEMS (LVN_FIRST-4)
#define LVN_BEGINLABELEDITA (LVN_FIRST-5)
#define LVN_BEGINLABELEDITW (LVN_FIRST-75)
#define LVN_ENDLABELEDITA (LVN_FIRST-6)
#define LVN_ENDLABELEDITW (LVN_FIRST-76)
#define LVN_COLUMNCLICK (LVN_FIRST-8)
#define LVN_BEGINDRAG (LVN_FIRST-9)
#define LVN_BEGINRDRAG (LVN_FIRST-11)
#define LVN_ODCACHEHINT (LVN_FIRST-13)
#define LVN_ODFINDITEMA (LVN_FIRST-52)
#define LVN_ODFINDITEMW (LVN_FIRST-79)
#define LVN_ITEMACTIVATE (LVN_FIRST-14)
#define LVN_ODSTATECHANGED (LVN_FIRST-15)
#define LVN_ODFINDITEM LVN_ODFINDITEMW
#define LVN_ODFINDITEM LVN_ODFINDITEMA
#define LVN_HOTTRACK (LVN_FIRST-21)
#define LVN_GETDISPINFOA (LVN_FIRST-50)
#define LVN_GETDISPINFOW (LVN_FIRST-77)
#define LVN_SETDISPINFOA (LVN_FIRST-51)
#define LVN_SETDISPINFOW (LVN_FIRST-78)
#define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITW
#define LVN_ENDLABELEDIT LVN_ENDLABELEDITW
#define LVN_GETDISPINFO LVN_GETDISPINFOW
#define LVN_SETDISPINFO LVN_SETDISPINFOW
#define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITA
#define LVN_ENDLABELEDIT LVN_ENDLABELEDITA
#define LVN_GETDISPINFO LVN_GETDISPINFOA
#define LVN_SETDISPINFO LVN_SETDISPINFOA
#define LV_DISPINFO NMLVDISPINFO
#define NMLVDISPINFO NMLVDISPINFOW
#define NMLVDISPINFO NMLVDISPINFOA
#define LVN_KEYDOWN (LVN_FIRST-55)
#define LVN_MARQUEEBEGIN (LVN_FIRST-56)
#define LVN_GETINFOTIPA (LVN_FIRST-57)
#define LVN_GETINFOTIPW (LVN_FIRST-58)
#define LVN_GETINFOTIP LVN_GETINFOTIPW
#define NMLVGETINFOTIP NMLVGETINFOTIPW
#define LPNMLVGETINFOTIP LPNMLVGETINFOTIPW
#define LVN_GETINFOTIP LVN_GETINFOTIPA
#define NMLVGETINFOTIP NMLVGETINFOTIPA
#define LPNMLVGETINFOTIP LPNMLVGETINFOTIPA
#define LVN_INCREMENTALSEARCHA (LVN_FIRST-62)
#define LVN_INCREMENTALSEARCHW (LVN_FIRST-63)
#define LVN_INCREMENTALSEARCH LVN_INCREMENTALSEARCHW
#define LVN_INCREMENTALSEARCH LVN_INCREMENTALSEARCHA
#define LVN_COLUMNDROPDOWN (LVN_FIRST-64)
#define LVN_COLUMNOVERFLOWCLICK (LVN_FIRST-66)
#define LVN_BEGINSCROLL (LVN_FIRST-80)
#define LVN_ENDSCROLL (LVN_FIRST-81)
#define LVN_LINKCLICK (LVN_FIRST-84)
#define LVN_GETEMPTYMARKUP (LVN_FIRST-87)
#define WC_TREEVIEWA "SysTreeView32"
#define WC_TREEVIEWW L"SysTreeView32"
#define WC_TREEVIEW WC_TREEVIEWW
#define WC_TREEVIEW WC_TREEVIEWA
#define WC_TREEVIEW "SysTreeView"
#define TVIF_STATE 0x0008
#define TVIS_EXPANDED 0x0020
#define TV_ITEMW TVITEMW
#define TV_ITEMA TVITEMA
#define LPTV_ITEM LPTVITEM
#define TV_ITEM TVITEM
#define TVITEM TVITEMW
#define LPTVITEM LPTVITEMW
#define TVITEM TVITEMA
#define LPTVITEM LPTVITEMA
#define TV_INSERTSTRUCTA TVINSERTSTRUCTA
#define TV_INSERTSTRUCTW TVINSERTSTRUCTW
#define TV_INSERTSTRUCT TVINSERTSTRUCT
#define LPTV_INSERTSTRUCT LPTVINSERTSTRUCT
#define TVINSERTSTRUCTA_V1_SIZE CCSIZEOF_STRUCT(TVINSERTSTRUCTA, item)
#define TVINSERTSTRUCTW_V1_SIZE CCSIZEOF_STRUCT(TVINSERTSTRUCTW, item)
#define TVINSERTSTRUCT TVINSERTSTRUCTW
#define LPTVINSERTSTRUCT LPTVINSERTSTRUCTW
#define TVINSERTSTRUCT_V1_SIZE TVINSERTSTRUCTW_V1_SIZE
#define TVINSERTSTRUCT TVINSERTSTRUCTA
#define LPTVINSERTSTRUCT LPTVINSERTSTRUCTA
#define TVINSERTSTRUCT_V1_SIZE TVINSERTSTRUCTA_V1_SIZE
#define TVM_INSERTITEMA (TV_FIRST + 0)
#define TVM_INSERTITEMW (TV_FIRST + 50)
#define TVM_INSERTITEM TVM_INSERTITEMW
#define TVM_INSERTITEM TVM_INSERTITEMA
#define TVE_COLLAPSE 0x0001
#define TVE_EXPAND 0x0002
#define TVGN_NEXT 0x0001
#define TVGN_PREVIOUS 0x0002
#define TVM_GETITEMA (TV_FIRST + 12)
#define TVM_GETITEMW (TV_FIRST + 62)
#define TVM_GETITEM TVM_GETITEMW
#define TVM_GETITEM TVM_GETITEMA
#define TVM_SETITEMA (TV_FIRST + 13)
#define TVM_SETITEMW (TV_FIRST + 63)
#define TVM_SETITEM TVM_SETITEMW
#define TVM_SETITEM TVM_SETITEMA
#define TVM_EDITLABELA (TV_FIRST + 14)
#define TVM_EDITLABELW (TV_FIRST + 65)
#define TVM_EDITLABEL TVM_EDITLABELW
#define TVM_EDITLABEL TVM_EDITLABELA
#define TV_HITTESTINFO TVHITTESTINFO
#define TVHT_ONITEMICON 0x0002
#define TVHT_ONITEMLABEL 0x0004
#define TVHT_ONITEM (TVHT_ONITEMICON | TVHT_ONITEMLABEL | TVHT_ONITEMSTATEICON)
#define TVHT_ONITEMSTATEICON 0x0040
#define TVM_SORTCHILDREN (TV_FIRST + 19)
#define TVM_GETISEARCHSTRINGA (TV_FIRST + 23)
#define TVM_GETISEARCHSTRINGW (TV_FIRST + 64)
#define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGW
#define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGA
#define TVM_SETINSERTMARK (TV_FIRST + 26)
#define TV_SORTCB TVSORTCB
#define NM_TREEVIEWW NMTREEVIEWW
#define NM_TREEVIEWA NMTREEVIEWA
#define LPNM_TREEVIEW LPNMTREEVIEW
#define NM_TREEVIEW NMTREEVIEW
#define NMTREEVIEW NMTREEVIEWW
#define LPNMTREEVIEW LPNMTREEVIEWW
#define NMTREEVIEW NMTREEVIEWA
#define LPNMTREEVIEW LPNMTREEVIEWA
#define TVN_SELCHANGINGA (TVN_FIRST-1)
#define TVN_SELCHANGINGW (TVN_FIRST-50)
#define TVN_SELCHANGEDA (TVN_FIRST-2)
#define TVN_SELCHANGEDW (TVN_FIRST-51)
#define TVN_GETDISPINFOA (TVN_FIRST-3)
#define TVN_GETDISPINFOW (TVN_FIRST-52)
#define TVN_SETDISPINFOA (TVN_FIRST-4)
#define TVN_SETDISPINFOW (TVN_FIRST-53)
#define TV_DISPINFO NMTVDISPINFO
#define NMTVDISPINFO NMTVDISPINFOW
#define LPNMTVDISPINFO LPNMTVDISPINFOW
#define NMTVDISPINFO NMTVDISPINFOA
#define LPNMTVDISPINFO LPNMTVDISPINFOA
#define NMTVDISPINFOEX NMTVDISPINFOEXW
#define LPNMTVDISPINFOEX LPNMTVDISPINFOEXW
#define NMTVDISPINFOEX NMTVDISPINFOEXA
#define LPNMTVDISPINFOEX LPNMTVDISPINFOEXA
#define TV_DISPINFOEX NMTVDISPINFOEX
#define TVN_ITEMEXPANDINGA (TVN_FIRST-5)
#define TVN_ITEMEXPANDINGW (TVN_FIRST-54)
#define TVN_ITEMEXPANDEDA (TVN_FIRST-6)
#define TVN_ITEMEXPANDEDW (TVN_FIRST-55)
#define TVN_BEGINDRAGA (TVN_FIRST-7)
#define TVN_BEGINDRAGW (TVN_FIRST-56)
#define TVN_BEGINRDRAGA (TVN_FIRST-8)
#define TVN_BEGINRDRAGW (TVN_FIRST-57)
#define TVN_DELETEITEMA (TVN_FIRST-9)
#define TVN_DELETEITEMW (TVN_FIRST-58)
#define TVN_BEGINLABELEDITA (TVN_FIRST-10)
#define TVN_BEGINLABELEDITW (TVN_FIRST-59)
#define TVN_ENDLABELEDITA (TVN_FIRST-11)
#define TVN_ENDLABELEDITW (TVN_FIRST-60)
#define TVN_GETINFOTIPA (TVN_FIRST-13)
#define TVN_GETINFOTIPW (TVN_FIRST-14)
#define TVN_ITEMCHANGINGA (TVN_FIRST-16)
#define TVN_ITEMCHANGINGW (TVN_FIRST-17)
#define TVN_ITEMCHANGEDA (TVN_FIRST-18)
#define TVN_ITEMCHANGEDW (TVN_FIRST-19)
#define TVN_SELCHANGING TVN_SELCHANGINGW
#define TVN_SELCHANGED TVN_SELCHANGEDW
#define TVN_GETDISPINFO TVN_GETDISPINFOW
#define TVN_SETDISPINFO TVN_SETDISPINFOW
#define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGW
#define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDW
#define TVN_BEGINDRAG TVN_BEGINDRAGW
#define TVN_BEGINRDRAG TVN_BEGINRDRAGW
#define TVN_DELETEITEM TVN_DELETEITEMW
#define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITW
#define TVN_ENDLABELEDIT TVN_ENDLABELEDITW
#define TVN_SELCHANGING TVN_SELCHANGINGA
#define TVN_SELCHANGED TVN_SELCHANGEDA
#define TVN_GETDISPINFO TVN_GETDISPINFOA
#define TVN_SETDISPINFO TVN_SETDISPINFOA
#define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGA
#define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDA
#define TVN_BEGINDRAG TVN_BEGINDRAGA
#define TVN_BEGINRDRAG TVN_BEGINRDRAGA
#define TVN_DELETEITEM TVN_DELETEITEMA
#define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITA
#define TVN_ENDLABELEDIT TVN_ENDLABELEDITA
#define TVN_GETINFOTIP TVN_GETINFOTIPW
#define NMTVGETINFOTIP NMTVGETINFOTIPW
#define LPNMTVGETINFOTIP LPNMTVGETINFOTIPW
#define TVN_GETINFOTIP TVN_GETINFOTIPA
#define NMTVGETINFOTIP NMTVGETINFOTIPA
#define LPNMTVGETINFOTIP LPNMTVGETINFOTIPA
#define TVN_ITEMCHANGING TVN_ITEMCHANGINGW
#define TVN_ITEMCHANGED TVN_ITEMCHANGEDW
#define TVN_ITEMCHANGING TVN_ITEMCHANGINGA
#define TVN_ITEMCHANGED TVN_ITEMCHANGEDA
#define WC_COMBOBOXEXW L"ComboBoxEx32"
#define WC_COMBOBOXEXA "ComboBoxEx32"
#define WC_COMBOBOXEX WC_COMBOBOXEXW
#define WC_COMBOBOXEX WC_COMBOBOXEXA
#define COMBOBOXEXITEM COMBOBOXEXITEMW
#define PCOMBOBOXEXITEM PCOMBOBOXEXITEMW
#define PCCOMBOBOXEXITEM PCCOMBOBOXEXITEMW
#define COMBOBOXEXITEM COMBOBOXEXITEMA
#define PCOMBOBOXEXITEM PCOMBOBOXEXITEMA
#define PCCOMBOBOXEXITEM PCCOMBOBOXEXITEMA
#define CBEM_INSERTITEMA (WM_USER + 1)
#define CBEM_GETITEMA (WM_USER + 4)
#define CBEM_SETITEMA (WM_USER + 5)
#define CBEM_INSERTITEMW (WM_USER + 11)
#define CBEM_SETITEMW (WM_USER + 12)
#define CBEM_GETITEMW (WM_USER + 13)
#define CBEM_INSERTITEM CBEM_INSERTITEMW
#define CBEM_SETITEM CBEM_SETITEMW
#define CBEM_GETITEM CBEM_GETITEMW
#define CBEM_INSERTITEM CBEM_INSERTITEMA
#define CBEM_SETITEM CBEM_SETITEMA
#define CBEM_GETITEM CBEM_GETITEMA
#define CBES_EX_NOEDITIMAGE 0x00000001
#define NMCOMBOBOXEX NMCOMBOBOXEXW
#define PNMCOMBOBOXEX PNMCOMBOBOXEXW
#define CBEN_GETDISPINFO CBEN_GETDISPINFOW
#define NMCOMBOBOXEX NMCOMBOBOXEXA
#define PNMCOMBOBOXEX PNMCOMBOBOXEXA
#define CBEN_GETDISPINFO CBEN_GETDISPINFOA
#define CBEN_GETDISPINFOA (CBEN_FIRST - 0)
#define CBEN_ENDEDITA (CBEN_FIRST - 5)
#define CBEN_ENDEDITW (CBEN_FIRST - 6)
#define CBEN_GETDISPINFOW (CBEN_FIRST - 7)
#define CBEN_DRAGBEGINA (CBEN_FIRST - 8)
#define CBEN_DRAGBEGINW (CBEN_FIRST - 9)
#define CBEN_DRAGBEGIN CBEN_DRAGBEGINW
#define CBEN_DRAGBEGIN CBEN_DRAGBEGINA
#define CBEN_ENDEDIT CBEN_ENDEDITW
#define CBEN_ENDEDIT CBEN_ENDEDITA
#define NMCBEDRAGBEGIN NMCBEDRAGBEGINW
#define LPNMCBEDRAGBEGIN LPNMCBEDRAGBEGINW
#define PNMCBEDRAGBEGIN PNMCBEDRAGBEGINW
#define NMCBEDRAGBEGIN NMCBEDRAGBEGINA
#define LPNMCBEDRAGBEGIN LPNMCBEDRAGBEGINA
#define PNMCBEDRAGBEGIN PNMCBEDRAGBEGINA
#define NMCBEENDEDIT NMCBEENDEDITW
#define LPNMCBEENDEDIT LPNMCBEENDEDITW
#define PNMCBEENDEDIT PNMCBEENDEDITW
#define NMCBEENDEDIT NMCBEENDEDITA
#define LPNMCBEENDEDIT LPNMCBEENDEDITA
#define PNMCBEENDEDIT PNMCBEENDEDITA
#define WC_TABCONTROLA "SysTabControl32"
#define WC_TABCONTROLW L"SysTabControl32"
#define WC_TABCONTROL WC_TABCONTROLW
#define WC_TABCONTROL WC_TABCONTROLA
#define WC_TABCONTROL "SysTabControl"
#define TCS_SCROLLOPPOSITE 0x0001
#define TCS_BOTTOM 0x0002
#define TCS_RIGHT 0x0002
#define TCS_MULTISELECT 0x0004
#define TCS_FLATBUTTONS 0x0008
#define TCS_FORCEICONLEFT 0x0010
#define TCS_FORCELABELLEFT 0x0020
#define TCS_HOTTRACK 0x0040
#define TCS_VERTICAL 0x0080
#define TCS_TABS 0x0000
#define TCS_BUTTONS 0x0100
#define TCS_SINGLELINE 0x0000
#define TCS_MULTILINE 0x0200
#define TCS_RIGHTJUSTIFY 0x0000
#define TCS_FIXEDWIDTH 0x0400
#define TCS_RAGGEDRIGHT 0x0800
#define TCS_FOCUSONBUTTONDOWN 0x1000
#define TCS_OWNERDRAWFIXED 0x2000
#define TCS_TOOLTIPS 0x4000
#define TCS_FOCUSNEVER 0x8000
#define TCS_EX_FLATSEPARATORS 0x00000001
#define TCS_EX_REGISTERDROP 0x00000002
#define TCM_GETIMAGELIST (TCM_FIRST + 2)
#define TCM_SETIMAGELIST (TCM_FIRST + 3)
#define TCM_GETITEMCOUNT (TCM_FIRST + 4)
#define TCIF_TEXT 0x0001
#define TCIF_IMAGE 0x0002
#define TCIF_RTLREADING 0x0004
#define TCIF_PARAM 0x0008
#define TCIF_STATE 0x0010
#define TCIS_BUTTONPRESSED 0x0001
#define TCIS_HIGHLIGHTED 0x0002
#define TC_ITEMHEADERW TCITEMHEADERW
#define TC_ITEMHEADER TCITEMHEADER
#define TCITEMHEADER TCITEMHEADERW
#define LPTCITEMHEADER LPTCITEMHEADERW
#define TCITEMHEADER TCITEMHEADERA
#define LPTCITEMHEADER LPTCITEMHEADERA
#define TC_ITEMW TCITEMW
#define TC_ITEM TCITEM
#define TCITEM TCITEMW
#define LPTCITEM LPTCITEMW
#define TCITEM TCITEMA
#define LPTCITEM LPTCITEMA
#define TCM_GETITEMA (TCM_FIRST + 5)
#define TCM_GETITEMW (TCM_FIRST + 60)
#define TCM_GETITEM TCM_GETITEMW
#define TCM_GETITEM TCM_GETITEMA
#define TCM_SETITEMA (TCM_FIRST + 6)
#define TCM_SETITEMW (TCM_FIRST + 61)
#define TCM_SETITEM TCM_SETITEMW
#define TCM_SETITEM TCM_SETITEMA
#define TCM_INSERTITEMA (TCM_FIRST + 7)
#define TCM_INSERTITEMW (TCM_FIRST + 62)
#define TCM_INSERTITEM TCM_INSERTITEMW
#define TCM_INSERTITEM TCM_INSERTITEMA
#define TCM_DELETEITEM (TCM_FIRST + 8)
#define TCM_DELETEALLITEMS (TCM_FIRST + 9)
#define TCM_GETITEMRECT (TCM_FIRST + 10)
#define TCM_GETCURSEL (TCM_FIRST + 11)
#define TCM_SETCURSEL (TCM_FIRST + 12)
#define TCHT_NOWHERE 0x0001
#define TCHT_ONITEMICON 0x0002
#define TCHT_ONITEMLABEL 0x0004
#define TCHT_ONITEM (TCHT_ONITEMICON | TCHT_ONITEMLABEL)
#define TC_HITTESTINFO TCHITTESTINFO
#define TCM_HITTEST (TCM_FIRST + 13)
#define TCM_SETITEMEXTRA (TCM_FIRST + 14)
#define TCM_ADJUSTRECT (TCM_FIRST + 40)
#define TCM_SETITEMSIZE (TCM_FIRST + 41)
#define TCM_REMOVEIMAGE (TCM_FIRST + 42)
#define TCM_SETPADDING (TCM_FIRST + 43)
#define TCM_GETROWCOUNT (TCM_FIRST + 44)
#define TCM_GETTOOLTIPS (TCM_FIRST + 45)
#define TCM_SETTOOLTIPS (TCM_FIRST + 46)
#define TCM_GETCURFOCUS (TCM_FIRST + 47)
#define TCM_SETCURFOCUS (TCM_FIRST + 48)
#define TCM_SETMINTABWIDTH (TCM_FIRST + 49)
#define TCM_DESELECTALL (TCM_FIRST + 50)
#define TCM_HIGHLIGHTITEM (TCM_FIRST + 51)
#define TCM_SETEXTENDEDSTYLE (TCM_FIRST + 52)
#define TCM_GETEXTENDEDSTYLE (TCM_FIRST + 53)
#define TCM_SETUNICODEFORMAT CCM_SETUNICODEFORMAT
#define TCM_GETUNICODEFORMAT CCM_GETUNICODEFORMAT
#define TCN_KEYDOWN (TCN_FIRST - 0)
#define TCN_SELCHANGE (TCN_FIRST - 1)
#define TCN_SELCHANGING (TCN_FIRST - 2)
#define TCN_GETOBJECT (TCN_FIRST - 3)
#define TCN_FOCUSCHANGE (TCN_FIRST - 4)
#define ANIMATE_CLASSW L"SysAnimate32"
#define ANIMATE_CLASSA "SysAnimate32"
#define ANIMATE_CLASS ANIMATE_CLASSW
#define ANIMATE_CLASS ANIMATE_CLASSA
#define ACM_OPENA (WM_USER+100)
#define ACM_OPENW (WM_USER+103)
#define ACM_OPEN ACM_OPENW
#define ACM_OPEN ACM_OPENA
#define MONTHCAL_CLASSW L"SysMonthCal32"
#define MONTHCAL_CLASSA "SysMonthCal32"
#define MONTHCAL_CLASS MONTHCAL_CLASSW
#define MONTHCAL_CLASS MONTHCAL_CLASSA
#define MCM_FIRST 0x1000
#define MCHT_TITLE 0x00010000
#define MCHT_CALENDAR 0x00020000
#define MCHT_NEXT 0x01000000
#define MCHT_PREV 0x02000000
#define MCHT_CALENDARDATE (MCHT_CALENDAR | 0x0001)
#define MCMV_CENTURY 3
#define MCGIP_CALENDAR 4
#define MCS_NOTODAY 0x0010
#define DATETIMEPICK_CLASSW L"SysDateTimePick32"
#define DATETIMEPICK_CLASSA "SysDateTimePick32"
#define DATETIMEPICK_CLASS DATETIMEPICK_CLASSW
#define DATETIMEPICK_CLASS DATETIMEPICK_CLASSA
#define DTM_FIRST 0x1000
#define DTM_SETFORMATA (DTM_FIRST + 5)
#define DTM_SETFORMATW (DTM_FIRST + 50)
#define DTM_SETFORMAT DTM_SETFORMATW
#define DTM_SETFORMAT DTM_SETFORMATA
#define DTN_USERSTRINGA (DTN_FIRST2 - 5)
#define DTN_USERSTRINGW (DTN_FIRST - 5)
#define DTN_USERSTRING DTN_USERSTRINGW
#define NMDATETIMESTRING NMDATETIMESTRINGW
#define LPNMDATETIMESTRING LPNMDATETIMESTRINGW
#define DTN_USERSTRING DTN_USERSTRINGA
#define NMDATETIMESTRING NMDATETIMESTRINGA
#define LPNMDATETIMESTRING LPNMDATETIMESTRINGA
#define DTN_WMKEYDOWNA (DTN_FIRST2 - 4)
#define DTN_WMKEYDOWNW (DTN_FIRST - 4)
#define DTN_WMKEYDOWN DTN_WMKEYDOWNW
#define NMDATETIMEWMKEYDOWN NMDATETIMEWMKEYDOWNW
#define LPNMDATETIMEWMKEYDOWN LPNMDATETIMEWMKEYDOWNW
#define DTN_WMKEYDOWN DTN_WMKEYDOWNA
#define NMDATETIMEWMKEYDOWN NMDATETIMEWMKEYDOWNA
#define LPNMDATETIMEWMKEYDOWN LPNMDATETIMEWMKEYDOWNA
#define DTN_FORMATA (DTN_FIRST2 - 3)
#define DTN_FORMATW (DTN_FIRST - 3)
#define DTN_FORMAT DTN_FORMATW
#define NMDATETIMEFORMAT NMDATETIMEFORMATW
#define LPNMDATETIMEFORMAT LPNMDATETIMEFORMATW
#define DTN_FORMAT DTN_FORMATA
#define NMDATETIMEFORMAT NMDATETIMEFORMATA
#define LPNMDATETIMEFORMAT LPNMDATETIMEFORMATA
#define DTN_FORMATQUERYA (DTN_FIRST2 - 2)
#define DTN_FORMATQUERYW (DTN_FIRST - 2)
#define DTN_FORMATQUERY DTN_FORMATQUERYW
#define NMDATETIMEFORMATQUERY NMDATETIMEFORMATQUERYW
#define LPNMDATETIMEFORMATQUERY LPNMDATETIMEFORMATQUERYW
#define DTN_FORMATQUERY DTN_FORMATQUERYA
#define NMDATETIMEFORMATQUERY NMDATETIMEFORMATQUERYA
#define LPNMDATETIMEFORMATQUERY LPNMDATETIMEFORMATQUERYA
#define WC_IPADDRESSW L"SysIPAddress32"
#define WC_IPADDRESSA "SysIPAddress32"
#define WC_IPADDRESS WC_IPADDRESSW
#define WC_IPADDRESS WC_IPADDRESSA
#define WC_PAGESCROLLERW L"SysPager"
#define WC_PAGESCROLLERA "SysPager"
#define WC_PAGESCROLLER WC_PAGESCROLLERW
#define WC_PAGESCROLLER WC_PAGESCROLLERA
#define WC_NATIVEFONTCTLW L"NativeFontCtl"
#define WC_NATIVEFONTCTLA "NativeFontCtl"
#define WC_NATIVEFONTCTL WC_NATIVEFONTCTLW
#define WC_NATIVEFONTCTL WC_NATIVEFONTCTLA
#define WC_BUTTONA "Button"
#define WC_BUTTONW L"Button"
#define WC_BUTTON WC_BUTTONW
#define WC_BUTTON WC_BUTTONA
#define WC_BUTTON "Button"
#define BCM_GETNOTE (BCM_FIRST + 0x000A)
#define WC_STATICA "Static"
#define WC_STATICW L"Static"
#define WC_STATIC WC_STATICW
#define WC_STATIC WC_STATICA
#define WC_STATIC "Static"
#define WC_EDITA "Edit"
#define WC_EDITW L"Edit"
#define WC_EDIT WC_EDITW
#define WC_EDIT WC_EDITA
#define WC_EDIT "Edit"
#define ES_EX_ALLOWEOL_CR 0x0001L
#define ES_EX_ALLOWEOL_LF 0x0002L
#define EM_SETEXTENDEDSTYLE (ECM_FIRST + 10)
#define EM_GETEXTENDEDSTYLE (ECM_FIRST + 11)
#define EM_GETFILELINE (ECM_FIRST + 22)
#define WC_LISTBOXA "ListBox"
#define WC_LISTBOXW L"ListBox"
#define WC_LISTBOX WC_LISTBOXW
#define WC_LISTBOX WC_LISTBOXA
#define WC_LISTBOX "ListBox"
#define WC_COMBOBOXA "ComboBox"
#define WC_COMBOBOXW L"ComboBox"
#define WC_COMBOBOX WC_COMBOBOXW
#define WC_COMBOBOX WC_COMBOBOXA
#define WC_COMBOBOX "ComboBox"
#define WC_SCROLLBARA "ScrollBar"
#define WC_SCROLLBARW L"ScrollBar"
#define WC_SCROLLBAR WC_SCROLLBARW
#define WC_SCROLLBAR WC_SCROLLBARA
#define WC_SCROLLBAR "ScrollBar"
#define PSTMSG ::PostMessage
#define PSTMSG PostMessage
#define LPFNPSPCALLBACK LPFNPSPCALLBACKW
#define LPFNPSPCALLBACK LPFNPSPCALLBACKA
#define PROPSHEETPAGEA_V1_SIZE sizeof(PROPSHEETPAGEA_V1)
#define PROPSHEETPAGEW_V1_SIZE sizeof(PROPSHEETPAGEW_V1)
#define PROPSHEETPAGEA_V2_SIZE sizeof(PROPSHEETPAGEA_V2)
#define PROPSHEETPAGEW_V2_SIZE sizeof(PROPSHEETPAGEW_V2)
#define PROPSHEETPAGE PROPSHEETPAGEW
#define LPPROPSHEETPAGE LPPROPSHEETPAGEW
#define LPCPROPSHEETPAGE LPCPROPSHEETPAGEW
#define PROPSHEETPAGE_V1_SIZE PROPSHEETPAGEW_V1_SIZE
#define PROPSHEETPAGE_V2_SIZE PROPSHEETPAGEW_V2_SIZE
#define PROPSHEETPAGE_V1 PROPSHEETPAGEW_V1
#define LPPROPSHEETPAGE_V1 LPPROPSHEETPAGEW_V1
#define LPCPROPSHEETPAGE_V1 LPCPROPSHEETPAGEW_V1
#define PROPSHEETPAGE_V2 PROPSHEETPAGEW_V2
#define LPPROPSHEETPAGE_V2 LPPROPSHEETPAGEW_V2
#define LPCPROPSHEETPAGE_V2 LPCPROPSHEETPAGEW_V2
#define PROPSHEETPAGE_V3 PROPSHEETPAGEW_V3
#define LPPROPSHEETPAGE_V3 LPPROPSHEETPAGEW_V3
#define LPCPROPSHEETPAGE_V3 LPCPROPSHEETPAGEW_V3
#define PROPSHEETPAGE_V4 PROPSHEETPAGEW_V4
#define LPPROPSHEETPAGE_V4 LPPROPSHEETPAGEW_V4
#define LPCPROPSHEETPAGE_V4 LPCPROPSHEETPAGEW_V4
#define PROPSHEETPAGE_LATEST PROPSHEETPAGEW_LATEST
#define LPPROPSHEETPAGE_LATEST LPPROPSHEETPAGEW_LATEST
#define LPCPROPSHEETPAGE_LATEST LPCPROPSHEETPAGEW_LATEST
#define PROPSHEETPAGE PROPSHEETPAGEA
#define LPPROPSHEETPAGE LPPROPSHEETPAGEA
#define LPCPROPSHEETPAGE LPCPROPSHEETPAGEA
#define PROPSHEETPAGE_V1_SIZE PROPSHEETPAGEA_V1_SIZE
#define PROPSHEETPAGE_V2_SIZE PROPSHEETPAGEA_V2_SIZE
#define PROPSHEETPAGE_V1 PROPSHEETPAGEA_V1
#define LPPROPSHEETPAGE_V1 LPPROPSHEETPAGEA_V1
#define LPCPROPSHEETPAGE_V1 LPCPROPSHEETPAGEA_V1
#define PROPSHEETPAGE_V2 PROPSHEETPAGEA_V2
#define LPPROPSHEETPAGE_V2 LPPROPSHEETPAGEA_V2
#define LPCPROPSHEETPAGE_V2 LPCPROPSHEETPAGEA_V2
#define PROPSHEETPAGE_V3 PROPSHEETPAGEA_V3
#define LPPROPSHEETPAGE_V3 LPPROPSHEETPAGEA_V3
#define LPCPROPSHEETPAGE_V3 LPCPROPSHEETPAGEA_V3
#define PROPSHEETPAGE_V4 PROPSHEETPAGEA_V4
#define LPPROPSHEETPAGE_V4 LPPROPSHEETPAGEA_V4
#define LPCPROPSHEETPAGE_V4 LPCPROPSHEETPAGEA_V4
#define PROPSHEETPAGE_LATEST PROPSHEETPAGEA_LATEST
#define LPPROPSHEETPAGE_LATEST LPPROPSHEETPAGEA_LATEST
#define LPCPROPSHEETPAGE_LATEST LPCPROPSHEETPAGEA_LATEST
#define PSH_WIZARD 0x00000020
#define PSH_WIZARD97 0x00002000
#define PSH_WIZARD97 0x01000000
#define PSH_HEADER 0x00080000
#define PROPSHEETHEADERA_V1_SIZE sizeof(PROPSHEETHEADERA_V1)
#define PROPSHEETHEADERW_V1_SIZE sizeof(PROPSHEETHEADERW_V1)
#define PROPSHEETHEADERA_V2_SIZE sizeof(PROPSHEETHEADERA_V2)
#define PROPSHEETHEADERW_V2_SIZE sizeof(PROPSHEETHEADERW_V2)
#define PROPSHEETHEADER PROPSHEETHEADERW
#define LPPROPSHEETHEADER LPPROPSHEETHEADERW
#define LPCPROPSHEETHEADER LPCPROPSHEETHEADERW
#define PROPSHEETHEADER_V1_SIZE PROPSHEETHEADERW_V1_SIZE
#define PROPSHEETHEADER_V2_SIZE PROPSHEETHEADERW_V2_SIZE
#define PROPSHEETHEADER PROPSHEETHEADERA
#define LPPROPSHEETHEADER LPPROPSHEETHEADERA
#define LPCPROPSHEETHEADER LPCPROPSHEETHEADERA
#define PROPSHEETHEADER_V1_SIZE PROPSHEETHEADERA_V1_SIZE
#define PROPSHEETHEADER_V2_SIZE PROPSHEETHEADERA_V2_SIZE
#define CreatePropertySheetPage CreatePropertySheetPageW
#define PropertySheet PropertySheetW
#define CreatePropertySheetPage CreatePropertySheetPageA
#define PropertySheet PropertySheetA
#define PSN_FIRST (0U-200U)
#define PSN_SETACTIVE (PSN_FIRST-0)
#define PSN_KILLACTIVE (PSN_FIRST-1)
#define PSN_APPLY (PSN_FIRST-2)
#define PSN_RESET (PSN_FIRST-3)
#define PSN_HELP (PSN_FIRST-5)
#define PSN_WIZBACK (PSN_FIRST-6)
#define PSN_WIZNEXT (PSN_FIRST-7)
#define PSN_WIZFINISH (PSN_FIRST-8)
#define PSN_QUERYCANCEL (PSN_FIRST-9)
#define PSN_GETOBJECT (PSN_FIRST-10)
#define PSN_TRANSLATEACCELERATOR (PSN_FIRST-12)
#define PSN_QUERYINITIALFOCUS (PSN_FIRST-13)
#define PSNRET_NOERROR 0
#define PSNRET_INVALID 1
#define PSNRET_INVALID_NOCHANGEPAGE 2
#define PSNRET_MESSAGEHANDLED 3
#define PSM_SETCURSEL (WM_USER + 101)
#define PSM_REMOVEPAGE (WM_USER + 102)
#define PSM_ADDPAGE (WM_USER + 103)
#define PSM_CHANGED (WM_USER + 104)
#define PSM_RESTARTWINDOWS (WM_USER + 105)
#define PSM_REBOOTSYSTEM (WM_USER + 106)
#define PSM_CANCELTOCLOSE (WM_USER + 107)
#define PSM_QUERYSIBLINGS (WM_USER + 108)
#define PSM_UNCHANGED (WM_USER + 109)
#define PSM_APPLY (WM_USER + 110)
#define PSM_SETTITLEA (WM_USER + 111)
#define PSM_SETTITLEW (WM_USER + 120)
#define PSM_SETTITLE PSM_SETTITLEW
#define PSM_SETTITLE PSM_SETTITLEA
#define PSM_SETWIZBUTTONS (WM_USER + 112)
#define PSWIZB_BACK 0x00000001
#define PSWIZB_NEXT 0x00000002
#define PSWIZB_FINISH 0x00000004
#define PSWIZB_DISABLEDFINISH 0x00000008
#define PSWIZBF_ELEVATIONREQUIRED 0x00000001
#define PSWIZB_CANCEL 0x00000010
#define PSM_PRESSBUTTON (WM_USER + 113)
#define PSBTN_BACK 0
#define PSBTN_NEXT 1
#define PSBTN_FINISH 2
#define PSBTN_OK 3
#define PSBTN_APPLYNOW 4
#define PSBTN_CANCEL 5
#define PSBTN_HELP 6
#define PSBTN_MAX 6
#define PSM_SETCURSELID (WM_USER + 114)
#define PSM_SETFINISHTEXTA (WM_USER + 115)
#define PSM_SETFINISHTEXTW (WM_USER + 121)
#define PSM_SETFINISHTEXT PSM_SETFINISHTEXTW
#define PSM_SETFINISHTEXT PSM_SETFINISHTEXTA
#define PSM_GETTABCONTROL (WM_USER + 116)
#define PSM_ISDIALOGMESSAGE (WM_USER + 117)
#define PSM_GETCURRENTPAGEHWND (WM_USER + 118)
#define PSM_INSERTPAGE (WM_USER + 119)
#define PSWIZF_SETCOLOR ((UINT)(-1))
#define PSM_SETHEADERTITLEA (WM_USER + 125)
#define PSM_SETHEADERTITLEW (WM_USER + 126)
#define PSM_SETHEADERTITLE PSM_SETHEADERTITLEW
#define PSM_SETHEADERTITLE PSM_SETHEADERTITLEA
#define PSM_SETHEADERSUBTITLEA (WM_USER + 127)
#define PSM_SETHEADERSUBTITLEW (WM_USER + 128)
#define PSM_SETHEADERSUBTITLE PSM_SETHEADERSUBTITLEW
#define PSM_SETHEADERSUBTITLE PSM_SETHEADERSUBTITLEA
#define PSM_HWNDTOINDEX (WM_USER + 129)
#define PSM_INDEXTOHWND (WM_USER + 130)
#define PSM_PAGETOINDEX (WM_USER + 131)
#define PSM_INDEXTOPAGE (WM_USER + 132)
#define PSM_IDTOINDEX (WM_USER + 133)
#define PSM_INDEXTOID (WM_USER + 134)
#define PSM_GETRESULT (WM_USER + 135)
#define PSM_RECALCPAGESIZES (WM_USER + 136)
#define PSM_SETNEXTTEXTW (WM_USER + 137)
#define PSM_SETNEXTTEXT PSM_SETNEXTTEXTW
#define PSWIZB_SHOW 0
#define PSWIZB_RESTORE 1
#define PSM_SHOWWIZBUTTONS (WM_USER + 138)
#define PSM_ENABLEWIZBUTTONS (WM_USER + 139)
#define PSM_SETBUTTONTEXTW (WM_USER + 140)
#define PSM_SETBUTTONTEXT PSM_SETBUTTONTEXTW
#define ID_PSRESTARTWINDOWS 0x2
#define ID_PSREBOOTSYSTEM (ID_PSRESTARTWINDOWS | 0x1)
#define WIZ_CXDLG 276
#define WIZ_CYDLG 140
#define WIZ_CXBMP 80
#define WIZ_BODYX 92
#define WIZ_BODYCX 184
#define PROP_SM_CXDLG 212
#define PROP_SM_CYDLG 188
#define PROP_MED_CXDLG 227
#define PROP_MED_CYDLG 215
#define PROP_LG_CXDLG 252
#define PROP_LG_CYDLG 218
#define WINGDIAPI DECLSPEC_IMPORT
#define WINGDIAPI
#define WINSPOOLAPI DECLSPEC_IMPORT
#define WINSPOOLAPI
#define R2_NOT 6
#define R2_MASKPEN 9
#define R2_MERGEPEN 15
#define SRCCOPY (DWORD)0x00CC0020
#define SRCERASE (DWORD)0x00440328
#define GDI_ERROR (0xFFFFFFFFL)
#define HGDI_ERROR (LongToHandle(0xFFFFFFFFL))
#define HGDI_ERROR ((HANDLE)-1)
#define ERROR 0
#define RGN_AND 1
#define RGN_COPY 5
#define BLACKONWHITE 1
#define WHITEONBLACK 2
#define COLORONCOLOR 3
#define HALFTONE 4
#define ALTERNATE 1
#define LAYOUT_RTL 0x00000001
#define LAYOUT_BTT 0x00000002
#define LAYOUT_VBH 0x00000004
#define TA_UPDATECP 1
#define TA_LEFT 0
#define TA_RIGHT 2
#define TA_CENTER 6
#define TA_TOP 0
#define TA_BOTTOM 8
#define TA_BASELINE 24
#define TA_RTLREADING 256
#define TA_MASK (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)
#define TA_MASK (TA_BASELINE+TA_CENTER+TA_UPDATECP)
#define DCB_RESET 0x0001
#define DCB_ACCUMULATE 0x0002
#define PASSTHROUGH 19
#define SETMITERLIMIT 23
#define BANDINFO 24
#define MOUSETRAILS 39
#define EXTTEXTOUT 512
#define STRETCHBLT 2048
#define PSINJECT_PAGES 4
#define PSINJECT_DOCUMENTPROCESSCOLORS 10
#define OBJ_PEN 1
#define OBJ_COLORSPACE 14
#define GDI_OBJ_LAST OBJ_COLORSPACE
#define MWT_IDENTITY 1
#define MWT_RIGHTMULTIPLY 3
#define ANTIALIASED_QUALITY 4
#define FIXED_PITCH 1
#define FW_DONTCARE 0
#define FW_THIN 100
#define FW_EXTRALIGHT 200
#define FW_LIGHT 300
#define FW_NORMAL 400
#define FW_MEDIUM 500
#define FW_SEMIBOLD 600
#define FW_BOLD 700
#define FW_EXTRABOLD 800
#define FW_HEAVY 900
#define PAN_SERIF_SQUARE 6
#define PAN_CONTRAST_MEDIUM 6
#define TRANSPARENT 1
#define OPAQUE 2
#define MM_TEXT 1
#define MM_TWIPS 6
#define MM_ANISOTROPIC 8
#define MM_MAX MM_ANISOTROPIC
#define ABSOLUTE 1
#define RELATIVE 2
#define STOCK_LAST 19
#define STOCK_LAST 17
#define STOCK_LAST 16
#define BS_NULL 1
#define BS_PATTERN 3
#define BS_DIBPATTERN 5
#define PS_DASH 1
#define PS_DASHDOT 3
#define TECHNOLOGY 2
#define HORZRES 8
#define VERTRES 10
#define ASPECTX 40
#define SIZEPALETTE 104
#define CC_WIDE 16
#define LC_WIDE 16
#define PC_WIDE 16
#define SYSPAL_NOSTATIC 2
#define DM_SPECVERSION 0x0401
#define DM_SPECVERSION 0x0400
#define DM_SPECVERSION 0x0320
#define DMPAPER_LETTER 1
#define DMPAPER_TABLOID 3
#define DMPAPER_LEGAL 5
#define DMPAPER_A3 8
#define DMPAPER_A4 9
#define DMPAPER_A5 11
#define DMPAPER_B4 12
#define DMPAPER_B5 13
#define DMPAPER_ENV_C6 31
#define DMPAPER_FANFOLD_LGL_GERMAN 41
#define DMPAPER_JAPANESE_POSTCARD 43
#define DMPAPER_LETTER_EXTRA 50
#define DMPAPER_A3_EXTRA 63
#define DMPAPER_A3_EXTRA_TRANSVERSE 68
#define DMPAPER_DBL_JAPANESE_POSTCARD 69
#define DMPAPER_A6 70
#define DMPAPER_JENV_KAKU2 71
#define DMPAPER_JENV_KAKU3 72
#define DMPAPER_JENV_CHOU3 73
#define DMPAPER_JENV_CHOU4 74
#define DMPAPER_B6_JIS 88
#define DMPAPER_JENV_YOU4 91
#define DMPAPER_P16K 93
#define DMPAPER_P32K 94
#define DMPAPER_P32KBIG 95
#define DMPAPER_PENV_1 96
#define DMPAPER_PENV_2 97
#define DMPAPER_PENV_3 98
#define DMPAPER_PENV_4 99
#define DMPAPER_PENV_5 100
#define DMPAPER_PENV_6 101
#define DMPAPER_PENV_7 102
#define DMPAPER_PENV_8 103
#define DMPAPER_PENV_9 104
#define DMPAPER_PENV_10 105
#define DMPAPER_PENV_10_ROTATED 118
#define DMPAPER_LAST DMPAPER_PENV_10_ROTATED
#define DMPAPER_LAST DMPAPER_A3_EXTRA_TRANSVERSE
#define DMPAPER_LAST DMPAPER_FANFOLD_LGL_GERMAN
#define DMBIN_UPPER 1
#define DMBIN_FORMSOURCE 15
#define DMTT_DOWNLOAD 2
#define DISPLAY_DEVICE_ATTACHED 0x00000002
#define SDC_TOPOLOGY_INTERNAL 0x00000001
#define SDC_TOPOLOGY_CLONE 0x00000002
#define SDC_TOPOLOGY_EXTEND 0x00000004
#define SDC_TOPOLOGY_EXTERNAL 0x00000008
#define GCP_JUSTIFY 0x00010000L
#define GCPCLASS_LATIN 1
#define PFD_DOUBLEBUFFER 0x00000001
#define PFD_STEREO 0x00000002
#define OLDFONTENUMPROC OLDFONTENUMPROCW
#define OLDFONTENUMPROC OLDFONTENUMPROCA
#define AddFontResource AddFontResourceW
#define AddFontResource AddFontResourceA
#define CopyMetaFile CopyMetaFileW
#define CopyMetaFile CopyMetaFileA
#define CreateDC CreateDCW
#define CreateDC CreateDCA
#define CreateFontIndirect CreateFontIndirectW
#define CreateFontIndirect CreateFontIndirectA
#define CreateFont CreateFontW
#define CreateFont CreateFontA
#define CreateIC CreateICW
#define CreateIC CreateICA
#define CreateMetaFile CreateMetaFileW
#define CreateMetaFile CreateMetaFileA
#define CreateScalableFontResource CreateScalableFontResourceW
#define CreateScalableFontResource CreateScalableFontResourceA
#define DM_UPDATE 1
#define DM_COPY 2
#define DM_PROMPT 4
#define DM_MODIFY 8
#define DC_PAPERS 2
#define DC_SIZE 8
#define DC_ORIENTATION 17
#define DC_PRINTRATE 26
#define DCTT_DOWNLOAD 0x0000002L
#define DeviceCapabilities DeviceCapabilitiesW
#define DeviceCapabilities DeviceCapabilitiesA
#define EnumFontFamiliesEx EnumFontFamiliesExW
#define EnumFontFamiliesEx EnumFontFamiliesExA
#define EnumFontFamilies EnumFontFamiliesW
#define EnumFontFamilies EnumFontFamiliesA
#define EnumFonts EnumFontsW
#define EnumFonts EnumFontsA
#define GetCharWidth GetCharWidthW
#define GetCharWidth GetCharWidthA
#define GetCharWidth32 GetCharWidth32W
#define GetCharWidth32 GetCharWidth32A
#define GetCharWidthFloat GetCharWidthFloatW
#define GetCharWidthFloat GetCharWidthFloatA
#define GetCharABCWidths GetCharABCWidthsW
#define GetCharABCWidths GetCharABCWidthsA
#define GetCharABCWidthsFloat GetCharABCWidthsFloatW
#define GetCharABCWidthsFloat GetCharABCWidthsFloatA
#define GetGlyphOutline GetGlyphOutlineW
#define GetGlyphOutline GetGlyphOutlineA
#define GetMetaFile GetMetaFileW
#define GetMetaFile GetMetaFileA
#define GetOutlineTextMetrics GetOutlineTextMetricsW
#define GetOutlineTextMetrics GetOutlineTextMetricsA
#define GetTextExtentPoint GetTextExtentPointW
#define GetTextExtentPoint GetTextExtentPointA
#define GetTextExtentPoint32 GetTextExtentPoint32W
#define GetTextExtentPoint32 GetTextExtentPoint32A
#define GetTextExtentExPoint GetTextExtentExPointW
#define GetTextExtentExPoint GetTextExtentExPointA
#define GetCharacterPlacement GetCharacterPlacementW
#define GetCharacterPlacement GetCharacterPlacementA
#define GetGlyphIndices GetGlyphIndicesW
#define GetGlyphIndices GetGlyphIndicesA
#define AddFontResourceEx AddFontResourceExW
#define AddFontResourceEx AddFontResourceExA
#define RemoveFontResourceEx RemoveFontResourceExW
#define RemoveFontResourceEx RemoveFontResourceExA
#define CreateFontIndirectEx CreateFontIndirectExW
#define CreateFontIndirectEx CreateFontIndirectExA
#define ResetDC ResetDCW
#define ResetDC ResetDCA
#define RemoveFontResource RemoveFontResourceW
#define RemoveFontResource RemoveFontResourceA
#define CopyEnhMetaFile CopyEnhMetaFileW
#define CopyEnhMetaFile CopyEnhMetaFileA
#define CreateEnhMetaFile CreateEnhMetaFileW
#define CreateEnhMetaFile CreateEnhMetaFileA
#define GetEnhMetaFile GetEnhMetaFileW
#define GetEnhMetaFile GetEnhMetaFileA
#define GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
#define GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
#define GetTextMetrics GetTextMetricsW
#define GetTextMetrics GetTextMetricsA
#define ILLUMINANT_A 1
#define ILLUMINANT_C 3
#define ILLUMINANT_F2 8
#define StartDoc StartDocW
#define StartDoc StartDocA
#define GetObject GetObjectW
#define GetObject GetObjectA
#define TextOut TextOutW
#define TextOut TextOutA
#define ExtTextOut ExtTextOutW
#define ExtTextOut ExtTextOutA
#define PolyTextOut PolyTextOutW
#define PolyTextOut PolyTextOutA
#define GetTextFace GetTextFaceW
#define GetTextFace GetTextFaceA
#define GetKerningPairs GetKerningPairsW
#define GetKerningPairs GetKerningPairsA
#define ICM_QUERY 3
#define ICMENUMPROC ICMENUMPROCW
#define ICMENUMPROC ICMENUMPROCA
#define GetLogColorSpace GetLogColorSpaceW
#define GetLogColorSpace GetLogColorSpaceA
#define CreateColorSpace CreateColorSpaceW
#define CreateColorSpace CreateColorSpaceA
#define GetICMProfile GetICMProfileW
#define GetICMProfile GetICMProfileA
#define SetICMProfile SetICMProfileW
#define SetICMProfile SetICMProfileA
#define EnumICMProfiles EnumICMProfilesW
#define EnumICMProfiles EnumICMProfilesA
#define UpdateICMRegKey UpdateICMRegKeyW
#define UpdateICMRegKey UpdateICMRegKeyA
#define ENHMETA_SIGNATURE 0x464D4520
#define ENHMETA_SIGNATURE 0x20454D46
#define EMR_POLYBEZIER 2
#define EMR_POLYGON 3
#define EMR_POLYLINE 4
#define EMR_POLYBEZIERTO 5
#define EMR_POLYLINETO 6
#define EMR_POLYPOLYLINE 7
#define EMR_POLYPOLYGON 8
#define EMR_ARC 45
#define EMR_POLYDRAW 56
#define EMR_CREATECOLORSPACE 99
#define EMR_MAX 122
#define EMR_MAX 104
#define EMR_MAX 97
#define wglUseFontBitmaps wglUseFontBitmapsW
#define wglUseFontBitmaps wglUseFontBitmapsA
#define wglUseFontOutlines wglUseFontOutlinesW
#define wglUseFontOutlines wglUseFontOutlinesA
#define WGL_SWAP_OVERLAY1 0x00000002
#define WGL_SWAP_UNDERLAY1 0x00010000
