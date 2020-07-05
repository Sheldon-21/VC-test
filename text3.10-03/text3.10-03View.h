
// text3.10-03View.h : Ctext31003View 类的接口
//

#pragma once


class Ctext31003View : public CView
{
protected: // 仅从序列化创建
	Ctext31003View();
	DECLARE_DYNCREATE(Ctext31003View)

// 特性
public:
	Ctext31003Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext31003View();
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

#ifndef _DEBUG  // text3.10-03View.cpp 中的调试版本
inline Ctext31003Doc* Ctext31003View::GetDocument() const
   { return reinterpret_cast<Ctext31003Doc*>(m_pDocument); }
#endif

