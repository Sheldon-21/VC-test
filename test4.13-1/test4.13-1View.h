
// test4.13-1View.h : Ctest4131View 类的接口
//

#pragma once


class Ctest4131View : public CView
{
protected: // 仅从序列化创建
	Ctest4131View();
	DECLARE_DYNCREATE(Ctest4131View)

// 特性
public:
	
	Ctest4131Doc* GetDocument() const;
	

// 操作
public:
	
       #define trans(p1,rect) CPoint(long((p1.x+0.5)/1)-rect.Width()/2,long((p1.y+0.5)/1)-rect.Height()/2)

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	
	virtual ~Ctest4131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	bool Index;
	CPoint p1;
	CPen *Cpen;
	CPoint points[4];
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void Ctest4131View::DrawObject(CDC *pDC, const CRect& rect);
};

#ifndef _DEBUG  // test4.13-1View.cpp 中的调试版本
inline Ctest4131Doc* Ctest4131View::GetDocument() const
   { return reinterpret_cast<Ctest4131Doc*>(m_pDocument); }
#endif

