#pragma once

#include <afxwin.h>
#include <afxtempl.h>
#include "resource.h"

class MyDocument;
class MyView;
class MyFrame;
class MyApp;

class MyDocument : public CDocument {
	DECLARE_DYNCREATE(MyDocument)                        //declares it's run-time class
	DECLARE_MESSAGE_MAP()
public:
	void AddPoint(CPoint p) { array_cpoint.Add(p); }     // adds a point mouse has went 
	CPoint GetPoint(int i) { return array_cpoint[i]; }   // gets a point from array_cpoint
	int GetSize() { return array_cpoint.GetSize(); }     // get the amount of recorded points
private:
	CArray<CPoint, CPoint&> array_cpoint;                //records the points that mouse has went through.
};


class MyView : public CView {
	DECLARE_DYNCREATE(MyView)                            //declares it's run-time class
	DECLARE_MESSAGE_MAP()
public:
	void OnDraw(CDC* p_dc);                              // for override
	afx_msg void OnLButtonDown(UINT, CPoint point);
	afx_msg void OnMouseMove(UINT, CPoint point);
	afx_msg void OnLButtonUp(UINT, CPoint point);
};
         

class MyFrame : public CFrameWnd {
	DECLARE_DYNCREATE(MyFrame)                           //declares it's run-time class
	DECLARE_MESSAGE_MAP();
};


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
