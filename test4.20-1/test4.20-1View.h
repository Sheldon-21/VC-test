
// test4.20-1View.h : Ctest4201View 类的接口
//

#pragma once


class Ctest4201View : public CView
{
protected: // 仅从序列化创建
	Ctest4201View();
	DECLARE_DYNCREATE(Ctest4201View)

// 特性
public:
	Ctest4201Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctest4201View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onjisuan();
};

#ifndef _DEBUG  // test4.20-1View.cpp 中的调试版本
inline Ctest4201Doc* Ctest4201View::GetDocument() const
   { return reinterpret_cast<Ctest4201Doc*>(m_pDocument); }
#endif

