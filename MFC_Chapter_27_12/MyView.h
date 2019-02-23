
// MyView.h: MyView 類別的介面
//

#pragma once

class ThreadInfo {
public:
	int sleep_time_ = 0;
	bool* continue_ = nullptr;
	int ctrl_id_ = 0;
	HWND h_wnd_;
};

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

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
private:
	afx_msg void OnBnClickedMainstartButton();
	afx_msg void OnBnClickedStartButton();
	afx_msg void OnBnClickedSuspendButton();
	afx_msg void OnBnClickedResumeButton();
	afx_msg void OnBnClickedResetButton();
	afx_msg void LRESULT OnThreadExit(WPARAM wParam, LPARAM lParam);
private:
	int sleep1_;
	int sleep2_;
	int sleep3_;
	int sleep4_;
	int sleep5_;
	BOOL priority_check_;
	CButton start_button_;
	CButton suspend_button_;
	
	CWinThread* thread_[5];
	bool continue_[5];
	CSliderCtrl* silder;
	static UINT ThreadFun(LPVOID lParam);
};

#ifndef _DEBUG  // 對 MyView.cpp 中的版本進行偵錯
inline MyDoc* MyView::GetDocument() const
   { return reinterpret_cast<MyDoc*>(m_pDocument); }
#endif

