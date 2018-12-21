#pragma once

#include <afxwin.h>
#include <afxtempl.h>
#include "resource.h"

class MyDocument;
class MyView;
class MyFrame;
class MyApp;

class MyDocument : public CDocument {
public:
	DECLARE_DYNCREATE(MyDocument)            //declares it's run-time class
	DECLARE_MESSAGE_MAP()
private:
	CArray<CPoint, CPoint&> p_array_cpoint;
};
IMPLEMENT_DYNCREATE(MyDocument, CDocument)

class MyView : public CView {
public:
	void OnDraw(CDC* p_dc) {}                // for override
	DECLARE_DYNCREATE(MyView)                //declares it's run-time class
};
IMPLEMENT_DYNCREATE(MyView, CView)              

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

	DECLARE_DYNCREATE(MyFrame)                //declares it's run-time class
	DECLARE_MESSAGE_MAP();
	afx_msg void OnExit();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

};
IMPLEMENT_DYNCREATE(MyFrame, CFrameWnd)

class MyApp : public CWinApp {
public:
	BOOL InitInstance() {
		
		/*this document class is a object for integrate that includes resources, the document, view, and frame classes.*/
		CSingleDocTemplate* p_c_single_document_template;
		p_c_single_document_template = new CSingleDocTemplate(IDR_MENU1, RUNTIME_CLASS(MyDocument), RUNTIME_CLASS(MyFrame), RUNTIME_CLASS(MyView));
		AddDocTemplate(p_c_single_document_template);            // we set the template object to application object(this MyApp object)
		
		//CFrameWnd* p_frame = new MyFrame();
		//m_pMainWnd = p_frame;
		//p_frame->ShowWindow(SW_SHOW);

		CDocument* p_c_document;
		p_c_document = p_c_single_document_template->CreateNewDocument();                         //create document object by template object
		m_pMainWnd = p_c_single_document_template->CreateNewFrame(p_c_document, NULL);            //create frame object by template object
		p_c_single_document_template->InitialUpdateFrame((CFrameWnd*)m_pMainWnd, p_c_document);   //initializes the frame object and links it to view object
		m_pMainWnd->ShowWindow(SW_SHOW);
		return true;
	}
};
