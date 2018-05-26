#pragma once
#include "afxwin.h"
// CIntgCtrl 对话框

class CIntgCtrl : public CDialogEx
{
	//DECLARE_EASYSIZE
	DECLARE_DYNAMIC(CIntgCtrl)

public:
	CIntgCtrl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CIntgCtrl();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INTEGRATE_DISPLAYCONTROL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonFjyx();
	afx_msg void OnBnClickedButtonFshd();
	afx_msg void OnBnClickedButtonFjtz();
	afx_msg void OnBnClickedButtonJryx();
	afx_msg void OnBnClickedButtonJrhd();
	afx_msg void OnBnClickedButtonJrtz();
	afx_msg void OnBnClickedButtonJwyx();
	afx_msg void OnBnClickedButtonJwhd();
	afx_msg void OnBnClickedButtonJwtz();
	afx_msg void OnBnClickedButtonCnwd();
	afx_msg void OnBnClickedButtonCnfs();
	void OnTimer(UINT nIDEvent);
	CFont m_font1;
	CFont m_font2;
	CFont m_font3;
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CStatic m_static4;
	CStatic m_static5;
	CStatic m_static6;
	CStatic m_static0;
	CButton m_button_cnwd;
	CButton m_button_cnfs;
	CButton m_button_fjyx;
	CButton m_button_fshd;
	CButton m_button_fjtz;
	CButton m_button_jryx;
	CButton m_button_jrhd;
	CButton m_button_jrtz;
	CButton m_button_jwyx;
	CButton m_button_jwhd;
	CButton m_button_jwtz;
	CStatic m_static7;
	CStatic m_static8;
	CStatic m_static9;
	CStatic m_static10;
	CString m_strRecvData;
	CString m_strTemp;
	CString m_strSpeed;
	CString m_strTime;
	CString m_strPressure;
	CStatic m_static11;
	CStatic m_static12;
	
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CStatic m_static_11;
	CStatic m_static_12;
	CString m_strStatic11;
	CString m_strStatic12;
	CButton m_button_fjpl;
	CButton m_button_mode;
	CStatic m_static_13;
	CString m_strStatic13;
	afx_msg void OnBnClickedButtonMode();
	afx_msg void OnBnClickedButtonFjpl();
	CStatic m_static_14;
	CString m_strStatic14;
	afx_msg void OnBnClickedButtonTimeStart();
	afx_msg void OnBnClickedButtonTimePause();
	afx_msg void OnBnClickedButtonTimeClear();
	afx_msg void OnBnClickedStatic8();
	afx_msg void OnStnClickedPicture8();
	afx_msg void OnEnChangeEditRecv();
	CStatic m_static15;
	CStatic m_static17;
	CStatic m_static16;
	CStatic m_static18;
	CStatic m_static19;
	CStatic m_static20;
	CStatic m_static21;
	CStatic m_static98;
	CStatic m_static99;
	CStatic m_static100;
	CStatic m_static23;
	CStatic m_static24;
	CStatic m_static26;
	CStatic m_static27;
	CStatic m_static22;
	CStatic m_static29;
	CStatic m_static30;
	CStatic m_static25;
	CStatic m_static31;
	CStatic m_static32;
	CStatic m_static28;
	CStatic m_static35;
	CStatic m_static36;
	CStatic m_static33;
	CStatic m_static37;
	CStatic m_static38;
	CStatic m_static34;
	CStatic m_static41;
	CStatic m_static42;
	CStatic m_static39;
	CStatic m_static43;
	CStatic m_static44;
	CStatic m_static40;
	CStatic m_static47;
	CStatic m_static48;
	CStatic m_static45;
	CStatic m_static49;
	CStatic m_static50;
	CStatic m_static46;
	CStatic m_static53;
	CStatic m_static54;
	CStatic m_static51;
	CStatic m_static55;
	CStatic m_static56;
	CStatic m_static52;
	CStatic m_static59;
	CStatic m_static60;
	CStatic m_static57;
	CStatic m_static61;
	CStatic m_static62;
	CStatic m_static58;
	CStatic m_static65;
	CStatic m_static66;
	CStatic m_static63;
	CStatic m_static67;
	CStatic m_static68;
	CStatic m_static64;
	CStatic m_static71;
	CStatic m_static72;
	CStatic m_static69;
	CStatic m_static73;
	CStatic m_static74;
	CStatic m_static70;
	CStatic m_static97;
	CStatic m_static96;
	CStatic m_static95;
	CStatic m_static94;
	CStatic m_static93;
	CStatic m_static92;
	CStatic m_static91;
	CStatic m_static90;
	CStatic m_static89;
	CStatic m_static88;
	afx_msg void OnBnClickedButtonRec4();
	afx_msg void OnBnClickedButtonRec1();
	afx_msg void OnBnClickedButtonRec2();
	afx_msg void OnBnClickedButtonRec3();
	afx_msg void OnBnClickedButtonRec5();
	afx_msg void OnBnClickedButtonRec6();
	CButton m_button_rec1;
	CButton m_button_rec2;
	CButton m_button_rec3;
	CButton m_button_rec4;
	CButton m_button_rec5;
	CButton m_button_rec6;
	CStatic m_static77;
	CStatic m_static78;
	CStatic m_static75;
	CStatic m_static79;
	CStatic m_static80;
	CStatic m_static76;
	CStatic m_static81;
	CButton m_button_arun;
	CButton m_button_astop;
	CButton m_button_brun;
	CButton m_button_bstop;
	CButton m_button_crun;
	CButton m_button_cstop;
	afx_msg void OnBnClickedButtonArun();
	afx_msg void OnBnClickedButtonAstop();
	afx_msg void OnBnClickedButtonBrun();
	afx_msg void OnBnClickedButtonBstop();
	afx_msg void OnBnClickedButtonCrun();
	afx_msg void OnBnClickedButtonCstop();
};
