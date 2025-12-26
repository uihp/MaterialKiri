#ifndef _simplethread_hpp_
#define _simplethread_hpp_

#include "win_defs.h"

#include <vector>
#include <algorithm>

template <class T>
class SimpleThreadBase {
public:
	typedef std::vector<HANDLE> EventArray;

	struct ThreadStartParam {
		SimpleThreadBase *self;
		HANDLE prepare, stop;
		T param;
	};

	SimpleThreadBase(DWORD tout)
		: threadHandle(0), prepareEvent(0), stopEvent(0), threadTimeout(tout) { }

	void threadStart(T t) { }

protected:
	HANDLE threadHandle, prepareEvent, stopEvent;
	DWORD threadTimeout;
	EventArray events;

	virtual unsigned threadMain(HANDLE prepare, HANDLE stop, T param) = 0;

	HANDLE createEvent(bool b = false) { }


private:
	static unsigned __stdcall threadFunc(void *vparam) { }
};

template <class T>
class SimpleThreadWithMessageWindow : public SimpleThreadBase<T> {
public:
	typedef SimpleThreadBase<T> InheritedClass;
	
	SimpleThreadWithMessageWindow(ttstr const &cname, ttstr const &wname, DWORD tout)
		: InheritedClass(tout), messageWindow(0) { }

	virtual ~SimpleThreadWithMessageWindow() { }

	static void UnregisterMessageWindowClass() { }

protected:
	HWND messageWindow;

	virtual LRESULT onMessage(UINT msg, WPARAM wp, LPARAM lp) = 0;

	void postMessage(UINT msg, WPARAM wp, LPARAM lp) { }
	void sendMessage(UINT msg, WPARAM wp, LPARAM lp) { }

private:
	static ATOM MessageWindowClass(ATOM set = 0, bool force = false) { }

	static LRESULT MsgWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) { }

	HWND createMessageWindow(LPCWSTR className, LPCWSTR windowName) { };

	HWND destroyMessageWindow(HWND hwnd) { }
};

#endif
