
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


ThreadInfo g_thread_info[5];

// MyView
IMPLEMENT_DYNCREATE(MyView, CFormView)
BEGIN_MESSAGE_MAP(MyView, CFormView)
	ON_BN_CLICKED(IDC_MAINSTART_BUTTON, &MyView::OnBnClickedMainstartButton)
	ON_BN_CLICKED(IDC_START_BUTTON, &MyView::OnBnClickedStartButton)
	ON_BN_CLICKED(IDC_SUSPEND_BUTTON, &MyView::OnBnClickedSuspendButton)
	ON_BN_CLICKED(IDC_RESET_BUTTON, &MyView::OnBnClickedResumeButton)
	ON_BN_CLICKED(IDC_RESUME_BUTTON, &MyView::OnBnClickedResetButton)
	ON_MESSAGE(WMU_THREAD_EXIT, &MyView::OnThreadExit)

END_MESSAGE_MAP()

// MyView 建構/解構
MyView::MyView() noexcept
	: CFormView(IDD_MFC_CHAPTER_27_12_FORM)
	, sleep1_(0)
	, sleep2_(0)
	, sleep3_(0)
	, sleep4_(0)
	, sleep5_(0)
	, priority_check_(FALSE)
{
	for (int i = 0; i < 5; ++i) { thread_[i] = nullptr; }
}

MyView::~MyView() {
	for (int i = 0; i < 5; ++i) {
		if (thread_[i] != nullptr && ::WaitForSingleObject(thread_[i]->m_hThread, 0) == WAIT_TIMEOUT) {
			TerminateThread(thread_[i]->m_hThread, 0);
		}
	}
}

void MyView::DoDataExchange(CDataExchange* pDX) {
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sleep1_);
	DDX_Text(pDX, IDC_EDIT2, sleep1_);
	DDX_Text(pDX, IDC_EDIT3, sleep1_);
	DDX_Text(pDX, IDC_EDIT4, sleep1_);
	DDX_Text(pDX, IDC_EDIT5, sleep1_);
	DDX_Check(pDX, IDC_PRIORITY_CHECK, priority_check_);
	DDX_Control(pDX, IDC_START_BUTTON, start_button_);
	DDX_Control(pDX, IDC_SUSPEND_BUTTON, suspend_button_);
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
void MyView::OnBnClickedMainstartButton() {
	CSliderCtrl* slider = (CSliderCtrl*)GetDlgItem(IDC_MAIN_SLIDER);
	slider->SetRange(0, 100);
	for (int i = 0; i < 100; ++i) {
		slider->SetPos(i);
		Sleep(100);
	}
	slider->SetPos(0);
}

void MyView::OnBnClickedStartButton() {
	for (int i = 0; i < 5; ++i) { continue_[i] = true; }
	UpdateData();
	
	g_thread_info[0].h_wnd_ = m_hWnd;
	g_thread_info[0].ctrl_id_ = IDC_SLIDER1;
	g_thread_info[0].continue_ = &continue_[0];
	g_thread_info[0].sleep_time_ = sleep1_;
	thread_[0] = AfxBeginThread(ThreadFun, (LPVOID)&g_thread_info[0]);
	g_thread_info[1].h_wnd_ = m_hWnd;
	g_thread_info[1].ctrl_id_ = IDC_SLIDER2;
	g_thread_info[1].continue_ = &continue_[1];
	g_thread_info[1].sleep_time_ = sleep2_;
	thread_[1] = AfxBeginThread(ThreadFun, (LPVOID)&g_thread_info[1]);
	g_thread_info[2].h_wnd_ = m_hWnd;
	g_thread_info[2].ctrl_id_ = IDC_SLIDER3;
	g_thread_info[2].continue_ = &continue_[2];
	g_thread_info[2].sleep_time_ = sleep3_;
	thread_[2] = AfxBeginThread(ThreadFun, (LPVOID)&g_thread_info[2]);
	g_thread_info[3].h_wnd_ = m_hWnd;
	g_thread_info[3].ctrl_id_ = IDC_SLIDER4;
	g_thread_info[3].continue_ = &continue_[3];
	g_thread_info[3].sleep_time_ = sleep4_;
	thread_[3] = AfxBeginThread(ThreadFun, (LPVOID)&g_thread_info[3]);
	g_thread_info[4].h_wnd_ = m_hWnd;
	g_thread_info[4].ctrl_id_ = IDC_SLIDER5;
	g_thread_info[4].continue_ = &continue_[4];
	g_thread_info[4].sleep_time_ = sleep5_;
	thread_[4] = AfxBeginThread(ThreadFun, (LPVOID)&g_thread_info[4]);

	start_button_.SetWindowText("重設");
	start_button_.SetDlgCtrlID(IDC_RESET_BUTTON);
	UpdateData();
	if (priority_check_) {
		thread_[0]->SetThreadPriority(THREAD_PRIORITY_HIGHEST);
		thread_[1]->SetThreadPriority(THREAD_PRIORITY_ABOVE_NORMAL);
		thread_[3]->SetThreadPriority(THREAD_PRIORITY_NORMAL);
		thread_[2]->SetThreadPriority(THREAD_PRIORITY_BELOW_NORMAL);
		thread_[4]->SetThreadPriority(THREAD_PRIORITY_LOWEST);
	}
}


void MyView::OnBnClickedSuspendButton()
{
	// TODO: 在此加入控制項告知處理常式程式碼
}



