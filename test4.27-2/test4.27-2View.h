
// test4.27-2View.h : Ctest4272View 类的接口
//

#pragma once


class Ctest4272View : public CView
{
protected: // 仅从序列化创建
	Ctest4272View();
	DECLARE_DYNCREATE(Ctest4272View)

// 特性
public:
	Ctest4272Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctest4272View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLookfile();
};

#ifndef _DEBUG  // test4.27-2View.cpp 中的调试版本
inline Ctest4272Doc* Ctest4272View::GetDocument() const
   { return reinterpret_cast<Ctest4272Doc*>(m_pDocument); }
#endif

