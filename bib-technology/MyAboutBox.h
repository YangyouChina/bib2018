#pragma once


// CMyAboutBox �Ի���

class CMyAboutBox : public CDialogEx
{
	DECLARE_DYNAMIC(CMyAboutBox)

public:
	CMyAboutBox(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyAboutBox();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
