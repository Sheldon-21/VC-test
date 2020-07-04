
// test4.20-2.3View.h : Ctest42023View 类的接口
//

#pragma once


class Ctest42023View : public CView
{
protected: // 仅从序列化创建
	Ctest42023View();
	DECLARE_DYNCREATE(Ctest42023View)

// 特性
public:
	Ctest42023Doc* GetDocument() const;

// 操作
public:CRect rect;
	   

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctest42023View();
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
};

#ifndef _DEBUG  // test4.20-2.3View.cpp 中的调试版本
inline Ctest42023Doc* Ctest42023View::GetDocument() const
   { return reinterpret_cast<Ctest42023Doc*>(m_pDocument); }
#endif

