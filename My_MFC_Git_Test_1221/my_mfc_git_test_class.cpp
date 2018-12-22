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
	ON_COMMAND(ID_SWITCHMENU, OnSwitchMenu)
	ON_COMMAND(ID_DYNAMICMENU_CREATEITEM, OnCreateItem)
	ON_COMMAND(IDM_DeleteItem, OnDeleteItem)
	ON_COMMAND(ID_RED, OnRed)
	ON_COMMAND(ID_GREEN, OnGreen)
	ON_COMMAND(ID_BLUE, OnBlue)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()
MyFrame::MyFrame() {
	Create(NULL,                                   //create a standard window
			   _T("Menu"),                             //window title
				 WS_OVERLAPPEDWINDOW | WS_VISIBLE,       //window style
				 rectDefault,                            //window size
				 NULL,                                   //the pointer of parent window
				 MAKEINTRESOURCE(IDR_MENU4));            //the ID of menu
	system_menu = GetSystemMenu(FALSE);            //gets the system menu
	system_menu->AppendMenu(MF_SEPARATOR);        //inserts the separator line
	system_menu->AppendMenu(MF_STRING, IDM_INSERT, _T("Insert by me!"));          //inserts the option
	color = RGB(255, 0, 0);                        //sets the point color to red
}
void MyFrame::SetCheck() {
	switch (color) {
	  case RGB(255, 0, 0): {
		main_menu.CheckMenuItem(ID_RED, MF_BYCOMMAND | MF_CHECKED);
		break;
	  }
	  case RGB(0, 255, 0): {
		main_menu.CheckMenuItem(ID_GREEN, MF_BYCOMMAND | MF_CHECKED);
		break;
	  }
	  case RGB(0, 0, 255): {
		main_menu.CheckMenuItem(ID_BLUE, MF_BYCOMMAND | MF_CHECKED);
		break;
	  }
	  default: {
		assert(false);
	  }
	}
}
void MyFrame::SetUnCheck() {
	switch (color) {
		case RGB(255, 0, 0): {
			main_menu.CheckMenuItem(ID_RED, MF_BYCOMMAND | MF_UNCHECKED);
			break;
		}
		case RGB(0, 255, 0): {
			main_menu.CheckMenuItem(ID_GREEN, MF_BYCOMMAND | MF_UNCHECKED);
			break;
		}
		case RGB(0, 0, 255): {
			main_menu.CheckMenuItem(ID_BLUE, MF_BYCOMMAND | MF_UNCHECKED);
			break;
		}
		default: {
			assert(false);
		}
	}
}
afx_msg void MyFrame::OnSwitchMenu() {
	CMenu insert_menu;                                  //create a menu object
	insert_menu.LoadMenu(IDR_MENU5);                    //load the menu source
	main_menu.LoadMenu(IDR_MENU3);
	main_menu.AppendMenu(MF_POPUP, (UINT)insert_menu.m_hMenu, _T("Color Menu"));
	sub_menu = main_menu.GetSubMenu(1);
	sub_menu->AppendMenuW(MF_SEPARATOR);
	sub_menu->InsertMenu(ID_DYNAMICMENU_CREATEITEM, MF_BYCOMMAND | MF_STRING, IDM_InsertItem, _T("Insert a Item"));
	sub_menu->InsertMenu(ID_DYNAMICMENU_CREATEITEM, MF_BYCOMMAND | MF_POPUP, (UINT) insert_menu.m_hMenu, _T("Insert a Item"));
	SetCheck();
	sub_menu->InsertMenu(ID_DYNAMICMENU_CREATEITEM, MF_BYCOMMAND | MF_SEPARATOR);
	insert_menu.Detach();
	SetMenu(&main_menu);
}
afx_msg void MyFrame::OnCreateItem() {
	main_menu.ModifyMenu(ID_DYNAMICMENU_CREATEITEM, MF_BYCOMMAND, IDM_DeleteItem, _T("Delete Item"));
	sub_menu->AppendMenu(MF_STRING, IDM_NewItem, _T("New Item"));
}
afx_msg void MyFrame::OnDeleteItem() {
	main_menu.ModifyMenu(IDM_DeleteItem, MF_BYCOMMAND, ID_DYNAMICMENU_CREATEITEM, _T("Create Item"));
	sub_menu->DeleteMenu(IDM_NewItem, MF_BYCOMMAND);
}
afx_msg void MyFrame::OnContextMenu(CWnd* p_wnd, CPoint point) {
	CMenu menu;
	menu.LoadMenu(IDR_MENU2);
	pop_menu = menu.GetSubMenu(0);
	pop_menu->TrackPopupMenu(TPM_CENTERALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	menu.Detach();
}
afx_msg void MyFrame::OnRed() {
	SetUnCheck();
	color = RGB(255, 0, 0);
	SetCheck();
}
afx_msg void MyFrame::OnGreen() {
	SetUnCheck();
	color = RGB(0, 255, 0);
	SetCheck();
}
afx_msg void MyFrame::OnBlue() {
	SetUnCheck();
	color = RGB(0, 0, 255);
	SetCheck();
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

