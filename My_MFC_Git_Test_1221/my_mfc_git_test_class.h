#pragma once

#include <afxwin.h>
//#include <afxtempl.h>
#include <assert.h>
#include "resource.h"

//class MyDocument;
//class MyView;
class MyFrame;
class MyApp;

//class MyDocument : public CDocument {
//	DECLARE_DYNCREATE(MyDocument)                        //declares it's run-time class
//	DECLARE_MESSAGE_MAP()
//public:
//	void AddPoint(CPoint p) { array_cpoint.Add(p); }     // adds a point mouse has went 
//	CPoint GetPoint(int i) { return array_cpoint[i]; }   // gets a point from array_cpoint
//	int GetSize() { return array_cpoint.GetSize(); }     // get the amount of recorded points
//private:
//	CArray<CPoint, CPoint&> array_cpoint;                //records the points that mouse has went through.
//};
//
//class MyView : public CView {
//	DECLARE_DYNCREATE(MyView)                            //declares it's run-time class
//	DECLARE_MESSAGE_MAP()
//public:
//	void OnDraw(CDC* p_dc);                              // for override
//	afx_msg void OnLButtonDown(UINT, CPoint point);
//	afx_msg void OnMouseMove(UINT, CPoint point);
//	afx_msg void OnLButtonUp(UINT, CPoint point);
//};

class MyFrame : public CFrameWnd {
	//IMPLEMENT_DYNCREATE(MyFrame, CFrameWnd)
	DECLARE_DYNCREATE(MyFrame)                           //declares it's run-time class BUTIDONTKNOW!
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
