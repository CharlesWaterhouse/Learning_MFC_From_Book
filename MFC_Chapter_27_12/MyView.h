
// MyView.h: MyView 類別的介面
//

#pragma once


class MyView : public CFormView
{
protected: // 僅從序列化建立
	MyView() noexcept;
	DECLARE_DYNCREATE(MyView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_CHAPTER_27_12_FORM };
#endif

// 屬性
public:
	MyDoc* GetDocument() const;

// 作業
public:

// 覆寫
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援
	virtual void OnInitialUpdate(); // 建構後第一次呼叫

// 程式碼實作
public:
	virtual ~MyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
private:
	int m_sleep1;
public:
	afx_msg void OnBnClickedStartButton();
};

#ifndef _DEBUG  // 對 MyView.cpp 中的版本進行偵錯
inline MyDoc* MyView::GetDocument() const
   { return reinterpret_cast<MyDoc*>(m_pDocument); }
#endif

