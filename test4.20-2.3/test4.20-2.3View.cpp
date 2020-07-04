
// test4.20-2.3View.cpp : Ctest42023View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test4.20-2.3.h"
#endif

#include "test4.20-2.3Doc.h"
#include "test4.20-2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest42023View

IMPLEMENT_DYNCREATE(Ctest42023View, CView)

BEGIN_MESSAGE_MAP(Ctest42023View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Ctest42023View 构造/析构

Ctest42023View::Ctest42023View()
{
	// TODO: 在此处添加构造代码

}

Ctest42023View::~Ctest42023View()
{
}

BOOL Ctest42023View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest42023View 绘制

void Ctest42023View::OnDraw(CDC* /*pDC*/)
{
	Ctest42023Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	rect.left = 400;
	rect.top = 200;
	rect.right = 600;
	rect.bottom = 550;
	GetDC()->Ellipse(rect);
	Invalidate(false);
	// TODO: 在此处为本机数据添加绘制代码
}


// Ctest42023View 诊断

#ifdef _DEBUG
void Ctest42023View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest42023View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest42023Doc* Ctest42023View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest42023Doc)));
	return (Ctest42023Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest42023View 消息处理程序


void Ctest42023View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cr;
	CClientDC dc(this);
	int color = RGB(0, 0, 255);
	CPen *cp = new CPen(PS_DOT, 1, color);
	CPen *poldpen = dc.SelectObject(cp);
	if (point.x<600&&point.x>400&&point.y>200&&point.y<550)
	{
		cr = rect;
		cr.left = rect.left - 10;
		cr.top = rect.top - 10;
		cr.bottom = rect.bottom + 10;
		cr.right = rect.right + 10;
		dc.Rectangle(cr);
	}
	
	CView::OnLButtonDown(nFlags, point);
}
