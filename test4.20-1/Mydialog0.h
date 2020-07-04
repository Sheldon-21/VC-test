#pragma once


// Mydialog0 对话框

class Mydialog0 : public CDialogEx
{
	DECLARE_DYNAMIC(Mydialog0)

public:
	Mydialog0(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Mydialog0();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	static Mydialog0 *dlg;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton6();
	double x;
	double y;
	double sum;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	virtual BOOL OnInitDialog();
	double n;
};
