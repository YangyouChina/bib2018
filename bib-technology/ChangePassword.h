#pragma once


// CChangePassword �Ի���

class CChangePassword : public CDialogEx
{
	DECLARE_DYNAMIC(CChangePassword)

public:
	CChangePassword(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangePassword();

	virtual void OnFinalRelease();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGEPASSWORD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	CString m_strOldPassword;
	CString m_strNewPassword;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
