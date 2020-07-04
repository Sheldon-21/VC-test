
// test4.27.1View.cpp : Ctest4271View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test4.27.1.h"
#endif

#include "test4.27.1Doc.h"
#include "test4.27.1View.h"

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctest4271View

IMPLEMENT_DYNCREATE(Ctest4271View, CView)

BEGIN_MESSAGE_MAP(Ctest4271View, CView)
	ON_COMMAND(ID_File, &Ctest4271View::OnFile)
END_MESSAGE_MAP()

// Ctest4271View 构造/析构

Ctest4271View::Ctest4271View()
{
	// TODO: 在此处添加构造代码

}

Ctest4271View::~Ctest4271View()
{
}

BOOL Ctest4271View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctest4271View 绘制

void Ctest4271View::OnDraw(CDC* pDC)
{
	Ctest4271Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(200, 300, pDoc->s);
	CString ss;
	ss.Format(_T("%d yes!"), 100 + pDoc->a);
	pDC->TextOutW(300, 300, ss);
	// TODO: 在此处为本机数据添加绘制代码
}


// Ctest4271View 诊断

#ifdef _DEBUG
void Ctest4271View::AssertValid() const
{
	CView::AssertValid();
}

void Ctest4271View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctest4271Doc* Ctest4271View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctest4271Doc)));
	return (Ctest4271Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctest4271View 消息处理程序


void Ctest4271View::OnFile()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		CString filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		CClientDC dc(this);
		int x = 20, y = 10;
		while (ifs>>s)
		{
			dc.TextOutW(x, y, filename);
			y = y + 30;
			CFileDialog cfd1(false);
			int r1 = cfd1.DoModal();
			if (r1 == IDOK) {
				ofstream ofs(cfd1.GetPathName());
				CString str = filename;
				ofs << CT2A(str) << endl;
			}

		}
	}
	
	// TODO: 在此添加命令处理程序代码
}
