
// test4.13-1View.cpp : Ctest4131View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test4.13-1.h"
#endif

#include "test4.13-1Doc.h"
#include "test4.13-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CPen blackpen(BS_SOLID, 1, RGB(0, 0, 0));
CPen balckpen1(BS_SOLID, 1, RGB(255, 255, 255));
// Ctest4131View

IMPLEMENT_DYNCREATE(Ctest4131View, CView)

BEGIN_MESSAGE_MAP(Ctest4131View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Ctest4131View 构造/析构

Ctest4131View::Ctest4131View()

	: Index(false)
	, p1(0)
{
	// TODO: 在此处添加构造代码
	

	points[0] = CPoint(121, 100);
	points[1] = CPoint(367, 100);
	points[2] = CPoint(367, 245);
	points[3] = CPoint(121, 245);
	Cpen = &blackpen;
}

Ctest4131View::~Ctest4131View()
{
	
	Index = false;
	p1 = 0;
	
}

BOOL Ctest4131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest4131View 绘制

void Ctest4131View::OnDraw(CDC* pDC)
{
	Ctest4131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(&rect);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);

	CDC memDC;
	CBitmap NewBitmap, *pOldBitmap;
	memDC.CreateCompatibleDC(pDC); // 创建一个与显示DC兼容的内存DC
	NewBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height()); // 创建兼容内存位图 
	pOldBitmap = memDC.SelectObject(&NewBitmap); // 将兼容位图选入内存DC
	memDC.FillSolidRect(rect, pDC->GetBkColor()); // 按原来背景色填充客户区，否则是黑色 
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2); 
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height()); 
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2); 
	memDC.SetROP2(R2_COPYPEN); // 设置绘图方式 
	DrawObject(&memDC, rect); // 画矩形的代码在这一个函数里
	
    // 将内存DC中的位图拷贝到设备DC 
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);
	memDC.SelectObject(pOldBitmap);

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctest4131View 诊断

#ifdef _DEBUG
void Ctest4131View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest4131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest4131Doc* Ctest4131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest4131Doc)));
	return (Ctest4131Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest4131View 消息处理程序


void Ctest4131View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	Index = false; // 初始标记一下不能移动
	if (points[0].x <= point.x && point.x <= points[2].x &&
		points[0].y <= point.y && point.y <= points[2].y) 
	{
		p1 = point;
	   Index = true; // 标记一下可以移动了 
	   Cpen = &balckpen1;
	   SetCapture(); // 设置鼠标捕获 
	   SetCursor(LoadCursor(NULL, IDC_SIZEALL)); // 设置光标为八个方向
	} // 触发OnDraw函数，动态效果 
	Invalidate(FALSE);

	CView::OnLButtonDown(nFlags, point);
}


void Ctest4131View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (true == Index) {
		Cpen = &blackpen; // 修改画笔颜色为黑色
		p1 = NULL; // 清空移动信息 
	}
	ReleaseCapture(); // 释放鼠标捕获 
	Index = false; // 标记一下此时不可以移动了 
	// 触发OnDraw函数，动态效果 
	Invalidate(FALSE);

	CView::OnLButtonUp(nFlags, point);
}


void Ctest4131View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (true == Index) {
		SetCursor(LoadCursor(NULL, IDC_SIZEALL)); // 设置光标为八个方向 
												  // 利用当前鼠标位置和初始记录的位置来修改矩形的每个顶点，做到图随鼠标动的效果 
		for (int i = 0; i < 4; i++) { points[i] += point - p1; } p1 = point;
	} // 触发OnDraw函数，动态效果 
	Invalidate(FALSE);

	CView::OnMouseMove(nFlags, point);
}

void Ctest4131View::DrawObject(CDC * pDC, const CRect & rect)
{
	int i = 0;
	CPen *oldPen = pDC->SelectObject(Cpen);
	pDC->Rectangle(CRect(trans(points[0], rect), trans(points[2], rect)));
	pDC->SelectObject(oldPen);
}
