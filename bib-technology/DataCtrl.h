#pragma once
#include "afxwin.h"
#include "mscomm1.h"

//曲线的头文件
#include "Plot.h"
using namespace RealtimeCurve;
#define  number  15 
// CDataCtrl 对话框

class CDataCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CDataCtrl)
public:
	CDataCtrl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDataCtrl();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATA_DISPLAYCONTROL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	DECLARE_EVENTSINK_MAP()
	//曲线边界
	int m_iBtnExitFromRight;
	int m_iBtnExitFromBottom;
	HICON m_hIcon;

public:
	CFont m_font1;
	CFont m_font2;
	afx_msg void OnBnClickedButtonFjyx();
	afx_msg void OnBnClickedButtonFshd();
	afx_msg void OnBnClickedButtonFjtz();
	afx_msg void OnBnClickedButtonJryx();
	afx_msg void OnBnClickedButtonJrhd();
	afx_msg void OnBnClickedButtonJrtz();
	afx_msg void OnBnClickedButtonJwyx();
	afx_msg void OnBnClickedButtonJwhd();
	afx_msg void OnBnClickedButtonJwtz();
	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CStatic m_static4;
	CStatic m_static5;
	CStatic m_static6;
	CStatic m_static7;
	CStatic m_static8;
	CStatic m_static9;
	CStatic m_static10;
	CStatic m_static11;
	CStatic m_static13;
	CString m_strRecvData;
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
	CTime tm;
	CMscomm1 m_cComm;
	CMscomm1 m_cComm2;
	void OnComm();
	void OnComm2();
	void OnTimer(UINT nIDEvent);
	BOOL OnMessageDisplay(CByteArray& Message);
	void SendMessageToController(byte b1, byte b2);
	void SendMessageToController(WORD W1);
	void ReadDFromPLC(int Address);
	void WriteDToPLC(int Address, float Data);
	void ReadMFromPLC(int Address);
	void ForceMPLC(int Address, BOOL Value);
	void WriteToInverter(int command, int data, int datasize);
	WORD CheckSum(CByteArray&);
	CString m_strTemp;
	CString m_strSpeed; 
	CString m_strTime;
	CString m_strPressure;

	//曲线相关
	CPlot m_plot;
	CRect m_rectBtnExit;
	CRect m_rectOldWindow;
	CRect m_rectOldPlotWindow;

	afx_msg void OnBnClickedButtonCnwd();
	afx_msg void OnBnClickedButtonCnfs();
	CString m_strRealTime;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	WORD AscToValue(byte asc);
	byte ValueToAsc(byte value);

//关于曲线的public
public:

	afx_msg  void OnEnChangeEditRecv();
	
	float Time_in[number];
	float Speed_in[number];
	float SpeedPress_in[number];
	float Temp_in[number];
	bool flag_in = 0;
	afx_msg void OnBnClickedDispLine2();
	afx_msg void OnBnClickedDispLine1();
	afx_msg void OnStnClickedPlot();
	afx_msg void OnBnClickedSaveimage();
	float m_time;
	void SaveHwndToBmpFile(HWND hWnd, CString lpszPath);
	 int Year[number];
	 int Month[number];
	 int Day[number];
	 int Hour[number];
	 int Min[number];
	 int Sec[number];
	 afx_msg void OnBnClickedButton1();
	 SYSTEMTIME stbegin;

	 CString m_strStatic11;
	 CStatic m_static_11;
	 CStatic m_static_12;
	 CString m_strStatic12;
	 CButton m_button_fjpl;
	 CString m_strStatic13;
	 CStatic m_static_13;
	 afx_msg void OnBnClickedButtonCnfs2();
	 afx_msg void OnBnClickedButtonTimeStart();
	 afx_msg void OnBnClickedButtonTimePause();
	 afx_msg void OnBnClickedButtonTimeClear();
	 afx_msg void OnBnClickedWindpLine2();
	 afx_msg void OnBnClickedWindLine10();
	 afx_msg void OnBnClickedWindpLine1();
	 afx_msg void OnBnClickedWindpLine3();
	 afx_msg void OnBnClickedWindLine2();
	 afx_msg void OnBnClickedWindLine3();
	 afx_msg void OnBnClickedWindLine4();
	 afx_msg void OnBnClickedWindLine5();
	 afx_msg void OnBnClickedWindLine6();
	 afx_msg void OnBnClickedWindLine7();
	 afx_msg void OnBnClickedWindLine8();
	 afx_msg void OnBnClickedWindLine9();
};
