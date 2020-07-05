
// text3.10-03View.cpp : Ctext31003View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text3.10-03.h"
#endif

#include "text3.10-03Doc.h"
#include "text3.10-03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext31003View

IMPLEMENT_DYNCREATE(Ctext31003View, CView)

BEGIN_MESSAGE_MAP(Ctext31003View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctext31003View 构造/析构

Ctext31003View::Ctext31003View()
{
	// TODO: 在此处添加构造代码

}

Ctext31003View::~Ctext31003View()
{
}

BOOL Ctext31003View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext31003View 绘制

void Ctext31003View::OnDraw(CDC* /*pDC*/)
{
	Ctext31003Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
	{
		CClientDC dc(this);
        
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// Ctext31003View 诊断

#ifdef _DEBUG
void Ctext31003View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext31003View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext31003Doc* Ctext31003View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext31003Doc)));
	return (Ctext31003Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext31003View 消息处理程序


void Ctext31003View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 50 + 5;
	CString s;
	s.Format(_T("%d"), r);
	CClientDC dc(this);
	CRect cr1(100,300,500,400);
	CRect cr2(600, 300, 500, 500);
	CRect cr3(500, 500, 700, 600);
	dc.Rectangle(cr1);
	dc.Rectangle(cr2);
	dc.Rectangle(cr3);
	Ctext31003Doc *pDoc = GetDocument();
	pDoc->ca.Add(r);
	if (point.x > 100 && point.x < 500 && point.y>300 && point.y < 400)
		dc.TextOutW(200, 300, s);
	CView::OnLButtonDown(nFlags, point);
}
