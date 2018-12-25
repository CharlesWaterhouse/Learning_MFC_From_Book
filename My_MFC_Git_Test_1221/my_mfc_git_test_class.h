#pragma once

#include <afxwin.h>
#include "resource.h"

class MyFrame;
class MyApp;
 

class MyFrame : public CFrameWnd {
	DECLARE_MESSAGE_MAP();
private:
	CMenu* p_menu;
	COLORREF color;
	HCURSOR h_cursor;
	CBitmap bmp;
public:
	MyFrame();

	afx_msg void OnBmpItem();
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnUpdateRed(CCmdUI* a_cmd_ui);
	afx_msg void OnUpdateGreen(CCmdUI* a_cmd_ui);
	afx_msg void OnUpdateBlue(CCmdUI* a_cmd_ui);
	afx_msg void OnLButtonDown(UINT n_flags, CPoint point);
	afx_msg void OnLButtonUp(UINT n_flags, CPoint point);
	afx_msg void OnMouseMove(UINT n_flags, CPoint point);
};



class MyApp : public CWinApp {
public:
	BOOL InitInstance();
};
