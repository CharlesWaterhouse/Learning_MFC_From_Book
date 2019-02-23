
// MFC_Chapter_27_12.h: MFC_Chapter_27_12 應用程式的主要標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"       // 主要符號


// MyApp:
// 查看 MFC_Chapter_27_12.cpp 以了解此類別的實作
//

class MyApp : public CWinApp
{
public:
	MyApp() noexcept;


// 覆寫
public:
	virtual BOOL InitInstance();

// 程式碼實作
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern MyApp theApp;
