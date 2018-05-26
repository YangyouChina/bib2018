#pragma once
#include "afxcmn.h"
#include "GLOBAL.h"

// CXYSetting 对话框

class CXYSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CXYSetting)

public:
	CXYSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CXYSetting();

	virtual void OnFinalRelease();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dialog1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	CSliderCtrl m_Speedmin;
	CSliderCtrl m_Ymin;
	CSliderCtrl m_Speedmax;
	CSliderCtrl m_Ymax;
	afx_msg void OnNMCustomdrawXmin(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnNMCustomdrawXmax(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawYmin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawYmax(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedSminset();
	afx_msg void OnBnClickedSmaxset();
	afx_msg void OnBnClickedTminset();
	afx_msg void OnBnClickedTmaxset();
};
