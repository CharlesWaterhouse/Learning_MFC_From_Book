#include <afxwin.h>

#include "resource.h"
#include "my_mfc_git_test_class.h"

//class MyFrame : public CFrameWnd 
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_COMMAND(ID_FILE_EXIT1, OnExit)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()
afx_msg void MyFrame::OnExit() {
	MessageBox(_T("Exit1"));
	DestroyWindow();
}
afx_msg void MyFrame::OnLButtonDown(UINT nFlags, CPoint point) {
	SetCapture();
}
afx_msg void MyFrame::OnLButtonUp(UINT nFlags, CPoint point){
	ReleaseCapture();
}
afx_msg void MyFrame::OnMouseMove(UINT nFlags, CPoint point) {
	if (this == GetCapture()) {
		CClientDC aDC(this);
		aDC.SetPixel(point, RGB(255, 0, 0));
	}
}

//class MyApp : public CWinApp 

