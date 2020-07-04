
// test4.27-2View.cpp : Ctest4272View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test4.27-2.h"
#endif

#include "test4.27-2Doc.h"
#include "test4.27-2View.h"
#include<string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest4272View

IMPLEMENT_DYNCREATE(Ctest4272View, CView)

BEGIN_MESSAGE_MAP(Ctest4272View, CView)
	ON_COMMAND(ID_LookFile, &Ctest4272View::OnLookfile)
END_MESSAGE_MAP()

// Ctest4272View 构造/析构

Ctest4272View::Ctest4272View()
{
	// TODO: 在此处添加构造代码

}

Ctest4272View::~Ctest4272View()
{
}

BOOL Ctest4272View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest4272View 绘制

void Ctest4272View::OnDraw(CDC* /*pDC*/)
{
	Ctest4272Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctest4272View 诊断

#ifdef _DEBUG
void Ctest4272View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest4272View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest4272Doc* Ctest4272View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest4272Doc)));
	return (Ctest4272Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest4272View 消息处理程序


void Ctest4272View::OnLookfile()
{
	// TODO: 在此添加命令处理程序代码
	CString str;
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		CString path = cfd.GetPathName();
		CStdioFile file;
		if(!file.Open(path, CFile::modeRead))return;
		
		while (file.ReadString(str)) {
			CClientDC dc(this);
			dc.TextOutW(400, 300, _T("s"));
		}
		file.Close();
		UpdateData(false);
		
	}
	CClientDC dc(this);
	dc.TextOutW(200, 400, str);
}
