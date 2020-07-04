
// test4-14-1View.h : Ctest4141View 类的接口
//

#pragma once


class Ctest4141View : public CView
{
protected: // 仅从序列化创建
	Ctest4141View();
	DECLARE_DYNCREATE(Ctest4141View)

// 特性
public:
	Ctest4141Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctest4141View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void Ondialog();
};

#ifndef _DEBUG  // test4-14-1View.cpp 中的调试版本
inline Ctest4141Doc* Ctest4141View::GetDocument() const
   { return reinterpret_cast<Ctest4141Doc*>(m_pDocument); }
#endif

