#pragma once
#include "afxwin.h"


// CInstruction �Ի���



class CInstruction : public CDialogEx
{
	DECLARE_DYNAMIC(CInstruction)

public:
	BOOL OnInitDialog();
	CInstruction(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInstruction();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedInstruct();
	CStatic m_Instruct;
};
