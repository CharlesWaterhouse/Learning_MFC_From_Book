
#include "my_mfc_git_test_class.h"

//class MyFrame : public CFrameWnd 
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_COLORMENU_RED, OnRed)
	ON_COMMAND(ID_COLORMENU_GREEN, OnGreen)
	ON_COMMAND(ID_COLORMENU_BLUE, OnBlue)
	ON_UPDATE_COMMAND_UI(ID_COLORMENU_RED, OnUpdateRed)
	ON_UPDATE_COMMAND_UI(ID_COLORMENU_GREEN, OnUpdateGreen)
	ON_UPDATE_COMMAND_UI(ID_COLORMENU_BLUE, OnUpdateBlue)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()
MyFrame::MyFrame() {
	Create(NULL,                                   //create a standard window
			   _T("controlbar"),                             //window title
				 WS_OVERLAPPEDWINDOW | WS_VISIBLE,       //window style
				 rectDefault,                            //window size
				 NULL,                                   //the pointer of parent window
				 MAKEINTRESOURCE(IDR_MENU6));            //the ID of menu
	color = RGB(255, 0, 0);                        //sets the point color to red
}
afx_msg int MyFrame::OnCreate(LPCREATESTRUCT lp_create_struct) {
	if (CFrameWnd::OnCreate(lp_create_struct)) {
		return -1;
	}
	tool_bar.Create(this);
	tool_bar.LoadToolBar(IDR_TOOLBAR1);
	tool_bar.EnableDocking(CBRS_ALIGN_TOP);
	tool_bar.SetBarStyle(tool_bar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&tool_bar);
	static UINT indicators[] = { 
		IDS_STRING127,
		IDS_STRING128
	};
	status_bar.Create(this);
	status_bar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));
	status_bar.SetPaneStyle(1, SBPS_POPOUT);
	return 0;
}
afx_msg void MyFrame::OnRed() {
	color = RGB(255, 0, 0);
	status_bar.SetPaneText(1, _T("Red"));
}
afx_msg void MyFrame::OnGreen() {
	color = RGB(0, 255, 0);
	status_bar.SetPaneText(1, _T("Green"));
}
afx_msg void MyFrame::OnBlue() {
	color = RGB(0, 0, 255);
	status_bar.SetPaneText(1, _T("Blue"));
}
afx_msg void MyFrame::OnUpdateRed(CCmdUI* a_cmd_ui) {
	a_cmd_ui->SetCheck(color == RGB(255, 0, 0));
}
afx_msg void MyFrame::OnUpdateGreen(CCmdUI* a_cmd_ui) {
	a_cmd_ui->SetCheck(color == RGB(0, 255, 0));
}
afx_msg void MyFrame::OnUpdateBlue(CCmdUI* a_cmd_ui) {
	a_cmd_ui->SetCheck(color == RGB(0, 0, 255));
}
afx_msg void MyFrame::OnLButtonDown(UINT n_flags, CPoint point) {
	SetCapture();
}
afx_msg void MyFrame::OnLButtonUp(UINT n_flags, CPoint point) {
	ReleaseCapture();
}
afx_msg void MyFrame::OnMouseMove(UINT n_flags, CPoint point) {
	if (this == GetCapture()) {
		CClientDC a_dc(this);
		a_dc.SetPixel(point, color);
	}
}

//class MyApp : public CWinApp 
BOOL MyApp::InitInstance() {
	CFrameWnd* p_frame = new MyFrame;
	m_pMainWnd = p_frame;
	p_frame->ShowWindow(SW_SHOW);
	return true;
}

