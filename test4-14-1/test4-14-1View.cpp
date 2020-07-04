
// test4-14-1View.cpp : Ctest4141View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test4-14-1.h"
#endif

#include "test4-14-1Doc.h"
#include "test4-14-1View.h"
#include"Mydialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest4141View

IMPLEMENT_DYNCREATE(Ctest4141View, CView)

BEGIN_MESSAGE_MAP(Ctest4141View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(dialog, &Ctest4141View::Ondialog)
END_MESSAGE_MAP()

// Ctest4141View 构造/析构

Ctest4141View::Ctest4141View()
{
	// TODO: 在此处添加构造代码

}

Ctest4141View::~Ctest4141View()
{
}

BOOL Ctest4141View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest4141View 绘制

void Ctest4141View::OnDraw(CDC* /*pDC*/)
{
	Ctest4141Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctest4141View 诊断

#ifdef _DEBUG
void Ctest4141View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest4141View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest4141Doc* Ctest4141View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest4141Doc)));
	return (Ctest4141Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest4141View 消息处理程序


void Ctest4141View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Mydialog dl;
	int n=dl.DoModal();
	if (n == IDOK) {
		CString s1 = dl.s;
		GetDC()->TextOutW(200, 100, s1);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void Ctest4141View::Ondialog()
{
	Mydialog dl;
    dl.DoModal();
	// TODO: 在此添加命令处理程序代码
}
