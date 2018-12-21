#include <afxwin.h>

#include "resource.h"
#include "my_mfc_git_test_class.h"


//class MyDocument : public CDocument
IMPLEMENT_DYNCREATE(MyDocument, CDocument)
BEGIN_MESSAGE_MAP(MyDocument, CDocument)
END_MESSAGE_MAP()

//class MyView : public CView 
IMPLEMENT_DYNCREATE(MyView, CView)
BEGIN_MESSAGE_MAP(MyView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()
void MyView::OnDraw(CDC* p_dc) {
	MyDocument* p_doc = (MyDocument*)GetDocument();
	int num = p_doc->GetSize();
	for (int i = 0; i < num; ++i) {
		CPoint point = p_doc->GetPoint(i);
		p_dc->SetPixel(point, RGB(255, 0, 0));
	}
}
afx_msg void MyView::OnLButtonDown(UINT, CPoint point) { SetCapture(); }
afx_msg void MyView::OnLButtonUp(UINT, CPoint point) { ReleaseCapture(); }
afx_msg void MyView::OnMouseMove(UINT, CPoint point) { 
	if (this == GetCapture()) {
		CClientDC aDC(this);
		aDC.SetPixel(point, RGB(255, 0, 0));
		MyDocument* p_doc = (MyDocument*)GetDocument();
		p_doc->AddPoint(point);
	}
}

//class MyFrame : public CFrameWnd 
IMPLEMENT_DYNCREATE(MyFrame, CFrameWnd)
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
END_MESSAGE_MAP()

//class MyApp : public CWinApp 

