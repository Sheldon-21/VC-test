// Mydialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test4-14-1.h"
#include "Mydialog.h"
#include "afxdialogex.h"


// Mydialog 对话框

IMPLEMENT_DYNAMIC(Mydialog, CDialogEx)

Mydialog::Mydialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, str(_T(""))
{

}

Mydialog::~Mydialog()
{
}

void Mydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox1);
	DDX_Text(pDX, IDC_EDIT1, str);
}


BEGIN_MESSAGE_MAP(Mydialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Mydialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Mydialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// Mydialog 消息处理程序


BOOL Mydialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Lbox1.AddString(_T("a文件"));
	Lbox1.AddString(_T("b文件"));
	Lbox1.AddString(_T("c文件"));
	// TODO:  在此添加额外的初始化
	s = "";
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Mydialog::OnBnClickedButton1()
{
	int n=Lbox1.GetCurSel();
	Lbox1.GetText(n, s);
	// TODO: 在此添加控件通知处理程序代码
}


void Mydialog::OnBnClickedButton2()
{
	this->UpdateData(true);
	str = s;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}
