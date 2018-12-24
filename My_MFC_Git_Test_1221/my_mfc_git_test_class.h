#pragma once

#include <afxwin.h>
#include <assert.h>
#include "resource.h"

class MyFrame;
class MyApp;


class MyFrame : public CFrameWnd {
	DECLARE_MESSAGE_MAP();
private:
	CMenu main_menu, *system_menu, *pop_menu, *sub_menu;
	COLORREF color;
public:
	MyFrame();

	void SetCheck();
	void SetUnCheck();
	afx_msg void OnSwitchMenu();
	afx_msg void OnCreateItem();
	afx_msg void OnDeleteItem();
	afx_msg void OnContextMenu(CWnd* p_wnd, CPoint point);
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnLButtonDown(UINT n_flags, CPoint point);
	afx_msg void OnLButtonUp(UINT n_flags, CPoint point);
	afx_msg void OnMouseMove(UINT n_flags, CPoint point);


};



class MyApp : public CWinApp {
public:
	BOOL InitInstance();
};
