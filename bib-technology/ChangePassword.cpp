// ChangePassword.cpp : 实现文件
//

#include "stdafx.h"
#include "bib-technology.h"
#include "ChangePassword.h"
#include "afxdialogex.h"
#include "Md5A.h"


// CChangePassword 对话框

IMPLEMENT_DYNAMIC(CChangePassword, CDialogEx)

BOOL CChangePassword::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	((CEdit*)GetDlgItem(IDC_EDIT_OLDPASSWORD))->SetLimitText(20);
	((CEdit*)GetDlgItem(IDC_EDIT_NEWPASSWORD))->SetLimitText(20);
	return 1;
}

CChangePassword::CChangePassword(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHANGEPASSWORD, pParent)
	, m_strOldPassword(_T(""))
	, m_strNewPassword(_T(""))
{

	EnableAutomation();

}

CChangePassword::~CChangePassword()
{
}

void CChangePassword::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CChangePassword::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OLDPASSWORD, m_strOldPassword);
	DDX_Text(pDX, IDC_EDIT_NEWPASSWORD, m_strNewPassword);
}


BEGIN_MESSAGE_MAP(CChangePassword, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChangePassword::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CChangePassword::OnBnClickedCancel)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CChangePassword, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IChangePassword 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {445EE986-6BE4-4226-8884-37F3DEFD3513}
static const IID IID_IChangePassword =
{ 0x445EE986, 0x6BE4, 0x4226, { 0x88, 0x84, 0x37, 0xF3, 0xDE, 0xFD, 0x35, 0x13 } };

BEGIN_INTERFACE_MAP(CChangePassword, CDialogEx)
	INTERFACE_PART(CChangePassword, IID_IChangePassword, Dispatch)
END_INTERFACE_MAP()


// CChangePassword 消息处理程序


void CChangePassword::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CStdioFile  fFile(_T("pass.ini"), CFile::modeRead);
	CString strPassword;
	fFile.ReadString(strPassword);
	fFile.Close();
	CMd5A md5;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, m_strOldPassword, -1, NULL, NULL, 0, NULL);
	char *c = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, m_strOldPassword, -1, c, dwNum, 0, NULL);
	if (md5.MDString(c) == strPassword)
	{
		fFile.Open(_T("pass.ini"), CFile::modeCreate | CFile::modeWrite);
		dwNum = WideCharToMultiByte(CP_OEMCP, NULL, m_strNewPassword, -1, NULL, NULL, 0, NULL);
		delete(c);
		char* c = new char[dwNum];
		WideCharToMultiByte(CP_OEMCP, NULL, m_strNewPassword, -1, c, dwNum, 0, NULL);
		USES_CONVERSION;
		CString str = A2W(md5.MDString(c));
		fFile.WriteString(str);
		fFile.Close();
		MessageBox(_T("修改成功!"));
		CDialogEx::OnOK();
	}
	else
	{
		AfxMessageBox(_T("原密码错误!"));
	}
}


void CChangePassword::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
