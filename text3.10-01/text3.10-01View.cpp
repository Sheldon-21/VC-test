
// text3.10-01View.cpp : Ctext31001View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text3.10-01.h"
#endif

#include "text3.10-01Doc.h"
#include "text3.10-01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext31001View

IMPLEMENT_DYNCREATE(Ctext31001View, CView)

BEGIN_MESSAGE_MAP(Ctext31001View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Ctext31001View 构造/析构

Ctext31001View::Ctext31001View()
{
	// TODO: 在此处添加构造代码

}

Ctext31001View::~Ctext31001View()
{
}

BOOL Ctext31001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext31001View 绘制

void Ctext31001View::OnDraw(CDC* /*pDC*/)
{
	Ctext31001Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext31001View 诊断

#ifdef _DEBUG
void Ctext31001View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext31001View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext31001Doc* Ctext31001View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext31001Doc)));
	return (Ctext31001Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext31001View 消息处理程序


void Ctext31001View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s ;
	s.Format(_T("左键正在被按下"));
	CClientDC dc(this);
	dc.TextOutW(200,300,s);
	CView::OnLButtonDown(nFlags, point);
}


void Ctext31001View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("左键正在被松开"));
	CClientDC dc(this);
	dc.TextOutW(200, 400, s);
	CView::OnLButtonUp(nFlags, point);
}
