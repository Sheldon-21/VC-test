
// test4.27.1View.h : Ctest4271View 类的接口
//

#pragma once


class Ctest4271View : public CView
{
protected: // 仅从序列化创建
	Ctest4271View();
	DECLARE_DYNCREATE(Ctest4271View)

// 特性
public:
	Ctest4271Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctest4271View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFile();
};

#ifndef _DEBUG  // test4.27.1View.cpp 中的调试版本
inline Ctest4271Doc* Ctest4271View::GetDocument() const
   { return reinterpret_cast<Ctest4271Doc*>(m_pDocument); }
#endif

