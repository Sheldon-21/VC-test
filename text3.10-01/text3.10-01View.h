
// text3.10-01View.h : Ctext31001View 类的接口
//

#pragma once


class Ctext31001View : public CView
{
protected: // 仅从序列化创建
	Ctext31001View();
	DECLARE_DYNCREATE(Ctext31001View)

// 特性
public:
	Ctext31001Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext31001View();
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
};

#ifndef _DEBUG  // text3.10-01View.cpp 中的调试版本
inline Ctext31001Doc* Ctext31001View::GetDocument() const
   { return reinterpret_cast<Ctext31001Doc*>(m_pDocument); }
#endif

