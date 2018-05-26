#pragma once
#include "afxwin.h"


// COMSETTING �Ի���

class COMSETTING : public CDialogEx
{
	DECLARE_DYNAMIC(COMSETTING)

public:
	COMSETTING(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COMSETTING();

	virtual void OnFinalRelease();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COM_SET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg BOOL OnDeviceChange(UINT nEventType, DWORD dwData);
	afx_msg void OnBnClickedOk();
	void MYUART_GetComNum(void);
	CComboBox m_combo_com;
	CComboBox m_combo_botelv;
	CComboBox m_combo_data;
	CComboBox m_combo_stop;
	CComboBox m_combo_check;
	afx_msg void OnBnClickedButton1();
	CComboBox m_combo_com2;
	CComboBox m_combo_botelv2;
	CComboBox m_combo_data2;
	CComboBox m_combo_stop2;
	CComboBox m_combo_check2;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnStnClickedStaticCom2();
	void OnTimer(UINT_PTR nIDEvent);
};
