// ChooseHeater.cpp : 实现文件
//

#include "stdafx.h"
#include "bib-technology.h"
#include "ChooseHeater.h"
#include "afxdialogex.h"
#include "DataCtrl.h"
#include "GLOBAL.h"

extern CDataCtrl*  pDtaCtrlDlg;
// CChooseHeater 对话框

IMPLEMENT_DYNAMIC(CChooseHeater, CDialogEx)

BOOL CChooseHeater::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_font1.CreatePointFont(100, _T(TEXT_FONT));
	m_Heater1.SetFont(&m_font1);
	m_Heater2.SetFont(&m_font1);
	CButton *pButtonOk = (CButton *)GetDlgItem(IDOK);
	CButton *pButtonCancel = (CButton *)GetDlgItem(IDCANCEL);
	pButtonOk->SetFont(&m_font1);
	pButtonCancel->SetFont(&m_font1);
	return 1;
}

CChooseHeater::CChooseHeater(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHOOSEHEATER, pParent)
{

	EnableAutomation();

}

CChooseHeater::~CChooseHeater()
{
}

void CChooseHeater::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CChooseHeater::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_HEATER1, m_Heater1);
	DDX_Control(pDX, IDC_CHECK_HEATER2, m_Heater2);
}


BEGIN_MESSAGE_MAP(CChooseHeater, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChooseHeater::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CChooseHeater::OnBnClickedCancel)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CChooseHeater, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IChooseHeater 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {5D68FE0F-CE36-478D-9EFD-D90B7AC23EB4}
static const IID IID_IChooseHeater =
{ 0x5D68FE0F, 0xCE36, 0x478D, { 0x9E, 0xFD, 0xD9, 0xB, 0x7A, 0xC2, 0x3E, 0xB4 } };

BEGIN_INTERFACE_MAP(CChooseHeater, CDialogEx)
	INTERFACE_PART(CChooseHeater, IID_IChooseHeater, Dispatch)
END_INTERFACE_MAP()


// CChooseHeater 消息处理程序


void CChooseHeater::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_Heater1.GetCheck() == BST_UNCHECKED  && m_Heater2.GetCheck() == BST_UNCHECKED)
	{
		MessageBox(_T("请至少选择一个加热器!"));
		return;
	}
	if (m_Heater1.GetCheck() == BST_CHECKED && m_Heater2.GetCheck() == BST_CHECKED)
	{
		pDtaCtrlDlg->SendMessageToController(CHOOSE_HEATER12);
	}
	else if (m_Heater1.GetCheck() == BST_CHECKED)
	{
		pDtaCtrlDlg->SendMessageToController(CHOOSE_HEATER2);
	}
	else
	{
		pDtaCtrlDlg->SendMessageToController(CHOOSE_HEATER1);
	}
	CDialogEx::OnOK();
}


void CChooseHeater::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
