#include <afxwin.h>

class MyApp : public CWinApp {
public:
	BOOL InitInstance() {
		CFrameWnd* Frame = new CFrameWnd();
		m_pMainWnd = Frame;

		Frame->Create(NULL, _T("Hello MFC"));
		Frame->ShowWindow(SW_SHOW);

		return true;
	}
};

MyApp a_app;