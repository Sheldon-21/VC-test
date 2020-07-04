
// test4.13-1.h : test4.13-1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// Ctest4131App:
// 有关此类的实现，请参阅 test4.13-1.cpp
//

class Ctest4131App : public CWinApp
{
public:
	Ctest4131App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctest4131App theApp;
