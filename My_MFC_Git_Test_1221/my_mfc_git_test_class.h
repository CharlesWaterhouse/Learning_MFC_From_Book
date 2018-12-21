#pragma once

#include <afxwin.h>
#include "resource.h"

class MyFrame;
class MyApp;


class MyFrame : public CFrameWnd {
private:
	CMenu *p_f_menu;
	
public:
	MyFrame() {
		Create(NULL, _T("Hellow"));
		p_f_menu = new CMenu;
		p_f_menu->LoadMenu(IDR_MENU1);
		SetMenu(p_f_menu);
	}
	~MyFrame() { delete p_f_menu; }

	DECLARE_MESSAGE_MAP();
	afx_msg void OnExit();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

};


class MyApp : public CWinApp {
public:
	BOOL InitInstance() {
		CFrameWnd* p_frame = new MyFrame();
		m_pMainWnd = p_frame;

		p_frame->ShowWindow(SW_SHOW);

		return true;
	}
};
