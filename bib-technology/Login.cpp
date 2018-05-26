// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "bib-technology.h"
#include "Login.h"
#include "afxdialogex.h"
#include "Md5A.h"
#include "bib-technologyDlg.h"
#include "ChangePassword.h"
#include "GLOBAL.h"

extern CbibtechnologyDlg* pMainDlg;

// CLogin 对话框

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

BOOL CLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	((CEdit*)GetDlgItem(IDC_EDIT1))->SetLimitText(20);
	((CEdit*)GetDlgItem(IDC_EDIT2))->SetLimitText(20);
	m_strAccount = _T(ACCOUNT);
	UpdateData(FALSE);
	return 1;
}

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN, pParent)
	, m_strAccount(_T(""))
	, m_strPassword(_T(""))
{

	EnableAutomation();

}

CLogin::~CLogin()
{
}

void CLogin::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strAccount);
	DDX_Text(pDX, IDC_EDIT2, m_strPassword);
}


BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLogin::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLogin::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogin::OnBnClickedButton1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLogin, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_ILogin 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {90FF90C4-4246-4B11-B443-8DA2656C586C}
static const IID IID_ILogin =
{ 0x90FF90C4, 0x4246, 0x4B11, { 0xB4, 0x43, 0x8D, 0xA2, 0x65, 0x6C, 0x58, 0x6C } };

BEGIN_INTERFACE_MAP(CLogin, CDialogEx)
	INTERFACE_PART(CLogin, IID_ILogin, Dispatch)
END_INTERFACE_MAP()


// CLogin 消息处理程序


void CLogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CStdioFile  fFile(_T("pass.ini"), CFile::modeRead);
	CString strPassword;
	fFile.ReadString(strPassword);
	fFile.Close();
	CMd5A md5;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, m_strPassword, -1, NULL, NULL, 0, NULL);
	char *c = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, m_strPassword, -1, c, dwNum, 0, NULL);
	if (m_strAccount == _T(ACCOUNT) && (strPassword == md5.MDString(c)))
	{
		CDialogEx::OnOK();
	}
	else
	{
		AfxMessageBox(_T("用户名或密码错误!"));
	}
}


void CLogin::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CLogin::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CChangePassword ChangePasswordDlg;
	ChangePasswordDlg.DoModal();
}
