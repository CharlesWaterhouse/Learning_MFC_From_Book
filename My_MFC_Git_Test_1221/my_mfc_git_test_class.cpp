#include <afxwin.h>

#include "resource.h"
#include "my_mfc_git_test_class.h"

//class Shape
Shape::Shape() {}
Shape::Shape(const Shape& s) : start_point_(s.start_point_),end_point_(s.end_point_), shape_num_(s.shape_num_){}
Shape::Shape(CPoint start_point, CPoint end_point, int shape_num) : start_point_(start_point), end_point_(end_point), shape_num_(shape_num) {}
Shape& Shape::operator = (const Shape& s) {
	start_point_ = s.start_point_;
	end_point_ = s.end_point_;
	return *this;
}
int Shape::GetShapeNum() {
	return shape_num_;
}
void Shape::SetPoint(CPoint start_point, CPoint end_point) {
	start_point_ = start_point;
	end_point_ = end_point;
}

//class LineShape
LineShape::LineShape() {
	shape_num_ = 0;
}
LineShape::LineShape(CPoint start_point, CPoint end_point) : Shape(start_point, end_point, 0) {}
LineShape::LineShape(const LineShape& l) : Shape(l.start_point_, l.end_point_, 0) {}

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
	tool_bar_.Create(this);
	tool_bar_.LoadToolBar(IDR_MyFrame);
	tool_bar_.EnableDocking(CBRS_ALIGN_ANY);
	tool_bar_.SetBarStyle(tool_bar_.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&tool_bar_);
	static UINT indicators[] = {
		ID_SEPARATOR, IDS_COLOR, IDS_SHAPE
	};
	status_bar_.Create(this);
	status_bar_.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));
	return 0;
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
	ON_COMMAND(ID_SHAPE_LINE, OnLine)
	ON_COMMAND(ID_SHAPE_RECTANGLE, OnRect)
	ON_COMMAND(ID_SHAPE_ELLIPSE, OnEllipse)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_LINE, OnUpdatUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_RECTANGLE, OnUpdatRect)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_ELLIPSE, OnUpdatEllipse)
END_MESSAGE_MAP()
MyView::MyView() {}
MyView::~MyView() {}
afx_msg void MyView::OnDraw(CDC* p_dc) {}
afx_msg void MyView::OnLButtonDown(UINT n_flags, CPoint point) {
	//TODO
}
afx_msg void MyView::OnMouseMove(UINT n_flags, CPoint point) {
	//TODO
}
afx_msg void MyView::OnLButtonUp(UINT n_flags, CPoint point) {
	//TODO
}
afx_msg void MyView::OnRed() {
	((MyFrame*)GetParentFrame())->status_bar_.SetPaneText(1, _T("Red"));
}
afx_msg void MyView::OnGreen() {
	((MyFrame*)GetParentFrame())->status_bar_.SetPaneText(1, _T("Green"));
}
afx_msg void MyView::OnBlue() {
	((MyFrame*)GetParentFrame())->status_bar_.SetPaneText(1, _T("Blue"));
}
afx_msg void MyView::OnUpdateRed(CCmdUI* a_cmd_ui) {
	//TODO
}
afx_msg void MyView::OnUpdateGreen(CCmdUI* a_cmd_ui) {
	//TODO
}
afx_msg void MyView::OnUpdateBlue(CCmdUI* a_cmd_ui) {
	//TODO
}
afx_msg void MyView::OnLine() {
	((MyFrame*)GetParentFrame())->status_bar_.SetPaneText(2, _T("Line"));
}
afx_msg void MyView::OnRect() {
	((MyFrame*)GetParentFrame())->status_bar_.SetPaneText(2, _T("Rect"));
}
afx_msg void MyView::OnEllipse() {
	((MyFrame*)GetParentFrame())->status_bar_.SetPaneText(2, _T("Ellipse"));
}
afx_msg void MyView::OnUpdatUpdateLine(CCmdUI* a_cmd_ui) {
	//TODO
}
afx_msg void MyView::OnUpdatRect(CCmdUI* a_cmd_ui) {
	//TODO
}
afx_msg void MyView::OnUpdatEllipse(CCmdUI* a_cmd_ui) {
	//TODO
}

//class MyApp : public CWinApp 
BOOL MyApp::InitInstance() {
	CSingleDocTemplate* a_doc_template;
	a_doc_template = new CSingleDocTemplate(IDR_MyFrame,
																					RUNTIME_CLASS(MyDocument),
																					RUNTIME_CLASS(MyFrame),
																					RUNTIME_CLASS(MyView));
	AddDocTemplate(a_doc_template);
	CDocument* a_doc = a_doc_template->CreateNewDocument();
	CFrameWnd* Frame = a_doc_template->CreateNewFrame(a_doc, NULL);
	m_pMainWnd = Frame;
	a_doc_template->InitialUpdateFrame(Frame, a_doc);
	Frame->ShowWindow(SW_SHOW);
	return true;
}

