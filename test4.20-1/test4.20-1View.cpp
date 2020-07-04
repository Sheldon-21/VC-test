
// test4.20-1View.cpp : Ctest4201View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test4.20-1.h"
#endif

#include "test4.20-1Doc.h"
#include "test4.20-1View.h"
#include"Mydialog0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest4201View

IMPLEMENT_DYNCREATE(Ctest4201View, CView)

BEGIN_MESSAGE_MAP(Ctest4201View, CView)
	ON_COMMAND(ID_jisuan, &Ctest4201View::Onjisuan)
END_MESSAGE_MAP()

// Ctest4201View 构造/析构

Ctest4201View::Ctest4201View()
{
	// TODO: 在此处添加构造代码

}

Ctest4201View::~Ctest4201View()
{
}

BOOL Ctest4201View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest4201View 绘制

void Ctest4201View::OnDraw(CDC* /*pDC*/)
{
	Ctest4201Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctest4201View 诊断

#ifdef _DEBUG
void Ctest4201View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest4201View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest4201Doc* Ctest4201View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest4201Doc)));
	return (Ctest4201Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest4201View 消息处理程序


void Ctest4201View::Onjisuan()
{
	Mydialog0 md0;
	md0.DoModal();
	// TODO: 在此添加命令处理程序代码
}
