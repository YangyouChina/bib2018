#pragma once
#include "afxwin.h"


// CInstruction 对话框



class CInstruction : public CDialogEx
{
	DECLARE_DYNAMIC(CInstruction)

public:
	BOOL OnInitDialog();
	CInstruction(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInstruction();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedInstruct();
	CStatic m_Instruct;
};
