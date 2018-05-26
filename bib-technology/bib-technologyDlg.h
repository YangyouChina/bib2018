
// bib-technologyDlg.h : 头文件
//

#pragma once
#include "DataCtrl.h"
#include "IntgCtrl.h"
#include "afxcmn.h"
#include "Login.h"
#include "COMSETTING.h"

class CbibtechnologyDlgAutoProxy;


// CbibtechnologyDlg 对话框
class CbibtechnologyDlg : public CDialogEx
{

	DECLARE_DYNAMIC(CbibtechnologyDlg);
	friend class CbibtechnologyDlgAutoProxy;

// 构造
public:
	CbibtechnologyDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CbibtechnologyDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BIBTECHNOLOGY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CbibtechnologyDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	CDataCtrl m_data;
	CIntgCtrl m_intg;
	CTabCtrl m_tab;
	CFont m_font1;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnComSet();
	CLogin m_LoginDlg;
	COMSETTING COMDLG;
	void SetImg(byte* bButtonFlag, int nMode);
	void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnAbout();
	afx_msg void OnYvalue();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSavepicPath();
	//用来设置存储路径

	afx_msg void OnSaveData();
	afx_msg void OnInstruct();
	
	afx_msg void OnMainTempSensor();
	afx_msg void OnBackupTempSensor();
	afx_msg void OnExit();
	afx_msg void OnBnClickedButton1();
	afx_msg void On_ChooseHeater();
	afx_msg void On_Lock();
	afx_msg void On_Unlock();
	afx_msg void On_calibration();
};
