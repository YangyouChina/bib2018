#pragma once


// CChoosingModeDlg �Ի���

class CChoosingModeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChoosingModeDlg)

public:
	CChoosingModeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChoosingModeDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton10();
};
