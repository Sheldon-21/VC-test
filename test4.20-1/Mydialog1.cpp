// Mydialog1.cpp : 实现文件
//

#include "stdafx.h"
#include "test4.20-1.h"
#include "Mydialog1.h"
#include "afxdialogex.h"
#include"Mydialog0.h"

// Mydialog1 对话框

IMPLEMENT_DYNAMIC(Mydialog1, CDialogEx)

Mydialog1::Mydialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, z(0)
{

}

Mydialog1::~Mydialog1()
{
}

void Mydialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, z);
}


BEGIN_MESSAGE_MAP(Mydialog1, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Mydialog1::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Mydialog1 消息处理程序



void Mydialog1::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	this->UpdateData(true);
	Mydialog0 *pdlg = Mydialog0::dlg;
	UpdateData(false);
}


BOOL Mydialog1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	this->UpdateData(true);
	Mydialog0 *pdlg = Mydialog0::dlg;
	z = pdlg->sum;
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
