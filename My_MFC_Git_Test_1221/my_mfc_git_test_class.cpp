#include <afxwin.h>

#include "resource.h"
#include "my_mfc_git_test_class.h"

//class MyDocument :public CDocument
IMPLEMENT_DYNCREATE(MyDocument,CDocument)
BEGIN_MESSAGE_MAP(MyDocument, CDocument)
END_MESSAGE_MAP()

//class MyFrame : public CFrameWnd 
IMPLEMENT_DYNCREATE(MyFrame, CFrameWnd)
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()
MyFrame::MyFrame() {}
MyFrame::~MyFrame() {}
afx_msg int MyFrame::OnCreate(LPCREATESTRUCT lp_create_struct) {
	if (CFrameWnd::OnCreate(lp_create_struct)) { return 1; }
	toolbar.Create(this);

}

//class MyView :public CView
IMPLEMENT_DYNCREATE(MyView, CView)
BEGIN_MESSAGE_MAP(MyView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_COLORMENU_RED, OnRed)
	ON_COMMAND(ID_COLORMENU_GREEN, OnGreen)
	ON_COMMAND(ID_COLORMENU_BLUE, OnBlue)
	ON_UPDATE_COMMAND_UI(ID_COLORMENU_RED, OnUpdateRed)
	ON_UPDATE_COMMAND_UI(ID_COLORMENU_GREEN, OnUpdateGreen)
	ON_UPDATE_COMMAND_UI(ID_COLORMENU_BLUE, OnUpdateBlue)
	ON_COMMAND(IDM_Line, OnLine)
	ON_COMMAND(IDM_Rect, OnRect)
	ON_COMMAND(IDM_ELLipse, OnEllipse)
	ON_UPDATE_COMMAND_UI(IDM_Line, OnUpdatUpdateLine)
	ON_UPDATE_COMMAND_UI(IDM_Rect, OnUpdatRect)
	ON_UPDATE_COMMAND_UI(IDM_ELLipse, OnUpdatEllipse)
END_MESSAGE_MAP()


//class MyApp : public CWinApp 
BOOL MyApp::InitInstance() {
	CFrameWnd* p_frame = new MyFrame;
	m_pMainWnd = p_frame;
	p_frame->SetIcon(LoadIcon(IDI_ICON1), TRUE);
	p_frame->ShowWindow(SW_SHOW);
	return true;
}

