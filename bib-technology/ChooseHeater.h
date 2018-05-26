#pragma once
#include "afxwin.h"


// CChooseHeater 对话框

class CChooseHeater : public CDialogEx
{
	DECLARE_DYNAMIC(CChooseHeater)

public:
	CChooseHeater(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChooseHeater();

	virtual void OnFinalRelease();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHOOSEHEATER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	CButton m_Heater1;
	CButton m_Heater2;
	CFont m_font1;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
