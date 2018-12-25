#pragma once

#include <afxwin.h>
#include <afxext.h>
#include "resource.h"

class MyFrame;
class MyApp;

class MyFrame : public CFrameWnd {
	DECLARE_MESSAGE_MAP();
private:
	COLORREF color;
	CToolBar tool_bar;
	CStatusBar status_bar;
public:
	MyFrame();

	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnUpdateRed(CCmdUI* a_cmd_ui);
	afx_msg void OnUpdateGreen(CCmdUI* a_cmd_ui);
	afx_msg void OnUpdateBlue(CCmdUI* a_cmd_ui);
	afx_msg void OnLButtonDown(UINT n_flags, CPoint point);
	afx_msg void OnLButtonUp(UINT n_flags, CPoint point);
	afx_msg void OnMouseMove(UINT n_flags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lp_create_struct);
};



class MyApp : public CWinApp {
public:
	BOOL InitInstance();
};
