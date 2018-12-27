#pragma once

#include <afxwin.h>
#include <afxtempl.h>
#include <afxext.h>
#include "resource.h"

class MyDocument;
class MyFrame;
class MyView;
class MyApp;
 
class MyDocument :public CDocument {
	DECLARE_DYNCREATE(MyDocument)
	DECLARE_MESSAGE_MAP()
};


class MyFrame : public CFrameWnd {
	DECLARE_DYNCREATE(MyFrame)
	DECLARE_MESSAGE_MAP();
private:
	CMenu* p_menu;
	CToolBar tool_bar;
public:
	CStatusBar status_bar;
	MyFrame();                                               //It's empty: do nothing
	~MyFrame();                                              //It's empty: do nothing
	afx_msg int OnCreate(LPCREATESTRUCT lp_create_struct);  

};

class MyView :public CView {
	DECLARE_DYNCREATE(MyView)
	DECLARE_MESSAGE_MAP()
public:
	MyView();                                                //It's empty: do nothing
	~MyView();                                               //It's empty: do nothing

	afx_msg void OnDraw(CDC* p_dc);                          //It's empty: do nothing
	afx_msg void OnLButtonDown(UINT n_flags, CPoint point); 
	afx_msg void OnMouseMove(UINT n_flags, CPoint point);
	afx_msg void OnLButtonUp(UINT n_flags, CPoint point);
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnUpdateRed(CCmdUI* a_cmd_ui);
	afx_msg void OnUpdateGreen(CCmdUI* a_cmd_ui);
	afx_msg void OnUpdateBlue(CCmdUI* a_cmd_ui);
	afx_msg void OnLine();
	afx_msg void OnRect();
	afx_msg void OnEllipse();
	afx_msg void OnUpdatUpdateLine(CCmdUI* p_cmd_ui);
	afx_msg void OnUpdatRect(CCmdUI* p_cmd_ui);
	afx_msg void OnUpdatEllipse(CCmdUI* p_cmd_ui);


};

class MyApp : public CWinApp {
public:
	BOOL InitInstance();             //TODO
};
