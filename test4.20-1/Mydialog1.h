#pragma once


// Mydialog1 对话框

class Mydialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(Mydialog1)

public:
	Mydialog1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Mydialog1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit1();
	double z;
	virtual BOOL OnInitDialog();
};
