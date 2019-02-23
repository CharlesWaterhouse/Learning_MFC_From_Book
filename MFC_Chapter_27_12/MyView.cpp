
// MyView.cpp: MyView 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "MFC_Chapter_27_12.h"
#endif

#include "MyDoc.h"
#include "MyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// MyView

IMPLEMENT_DYNCREATE(MyView, CFormView)

BEGIN_MESSAGE_MAP(MyView, CFormView)
	ON_BN_CLICKED(IDC_START_BUTTON, &MyView::OnBnClickedStartButton)
END_MESSAGE_MAP()

// MyView 建構/解構

MyView::MyView() noexcept
	: CFormView(IDD_MFC_CHAPTER_27_12_FORM)
{
	// TODO: 在此加入建構程式碼

}

MyView::~MyView()
{
}

void MyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL MyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CFormView::PreCreateWindow(cs);
}

void MyView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// MyView 診斷

#ifdef _DEBUG
void MyView::AssertValid() const
{
	CFormView::AssertValid();
}

void MyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

MyDoc* MyView::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(MyDoc)));
	return (MyDoc*)m_pDocument;
}
#endif //_DEBUG


// MyView 訊息處理常式


void MyView::OnBnClickedStartButton()
{
	// TODO: 在此加入控制項告知處理常式程式碼
}
