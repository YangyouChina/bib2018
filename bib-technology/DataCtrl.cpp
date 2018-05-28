// DataCtrl.cpp : 实现文件
//
#pragma comment( lib,"winmm.lib" )

#include "stdafx.h"
#include "bib-technology.h"
#include "DataCtrl.h"
#include "afxdialogex.h"
#include "GLOBAL.h"
#include "TempControl.h"
#include "SpeedControl.h"
#include "Md5A.h"
#include "ChooseHeater.h"
#include "IntgCtrl.h"
#include <Mmsystem.h>

//用于绘制曲线的头文件
#include <math.h>
#include "Plot.h"
#include <windows.h>
#include <atlimage.h>
#include "bib-technologyDlg.h"
#include "XYSetting.h"
using namespace RealtimeCurve;

extern CXYSetting* pXYSettingDlg;
extern CbibtechnologyDlg* pMainDlg;
extern CIntgCtrl* pIntgCtrlDlg;

CDataCtrl* pDtaCtrlDlg;
// CDataCtrl 对话框

IMPLEMENT_DYNAMIC(CDataCtrl, CDialogEx)

BOOL CDataCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	pDtaCtrlDlg = this;
	//执行程序前先记录当前系统时间
	SYSTEMTIME st;
	GetLocalTime(&st);
	GetLocalTime(&stbegin);
	sprintf(BeginTime, "D:\\BibTechnology\\BibData\\%d%d%d_%d%d%d.txt", stbegin.wYear, stbegin.wMonth, stbegin.wDay, stbegin.wHour, stbegin.wMinute, st.wSecond);
	
	//曲线图初始化
	((CButton*)GetDlgItem(IDC_DISP_LINE1))->SetCheck(TRUE);//温度
	((CButton*)GetDlgItem(IDC_DISP_LINE2))->SetCheck(TRUE);//风压1
	((CButton*)GetDlgItem(IDC_WIND_LINE1))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WIND_LINE2))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WIND_LINE3))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WINDPRESS_LINE2))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WINDPRESS_LINE3))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WINDPRESS_LINE4))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WINDPRESS_LINE5))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WINDPRESS_LINE6))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WINDPRESS_LINE7))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WINDPRESS_LINE8))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WINDPRESS_LINE9))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_WINDPRESS_LINE10))->SetCheck(TRUE);
	//remember initial position
	GetWindowRect(&m_rectOldWindow);
	m_plot.GetWindowRect(&m_rectOldPlotWindow);
	TRACE("m_rectOldPlotWindow.left=%d,m_rectOldPlotWindow.width=%d\n", m_rectOldPlotWindow.left, m_rectOldPlotWindow.Width());
	ScreenToClient(&m_rectOldPlotWindow);
	TRACE("m_rectOldPlotWindow.left=%d,m_rectOldPlotWindow.width=%d\n", m_rectOldPlotWindow.left, m_rectOldPlotWindow.Width());
	m_plot.AddNewLine(_T("温度"), PS_SOLID, RGB(255, 0, 0));
	m_plot.AddNewLine(_T("风速"), PS_SOLID, RGB(0, 128, 255));
	m_plot.AddNewLine(_T("风速2"), PS_SOLID, RGB(255, 255, 128));
	m_plot.AddNewLine(_T("风速3"), PS_SOLID, RGB(64, 0, 128));
	m_plot.AddNewLine(_T("风压1"), PS_SOLID, RGB(128, 255, 255));

	m_plot.AddNewLine(_T("风压2"), PS_SOLID, RGB(255, 128, 128));
	m_plot.AddNewLine(_T("风压3"), PS_SOLID, RGB(0, 128, 192));
	m_plot.AddNewLine(_T("风压4"), PS_SOLID, RGB(128, 128, 192));
	m_plot.AddNewLine(_T("风压5"), PS_SOLID, RGB(128, 64, 64));
	m_plot.AddNewLine(_T("风压6"), PS_SOLID, RGB(0, 240, 61));
	m_plot.AddNewLine(_T("风压7"), PS_SOLID, RGB(0, 128, 128));
	m_plot.AddNewLine(_T("风速8"), PS_SOLID, RGB(0, 0, 255));
	m_plot.AddNewLine(_T("风速9"), PS_SOLID, RGB(255,0, 128));
	m_plot.AddNewLine(_T("风压10"), PS_SOLID, RGB(0, 128, 0));

	m_plot.GetAxisX().AxisColor = RGB(0, 0, 0);
	m_plot.GetAxisY().AxisColor = RGB(0, 0, 0);
	//风机定时器
	SetTimer(2, 50, NULL);
	m_plot.SetRate(10);//
	m_plot.Start();

	//关联图片ID   
	HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE1);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE2);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE3);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic4 = (CStatic *)GetDlgItem(IDC_PICTURE4);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	CStatic *pStatic5 = (CStatic *)GetDlgItem(IDC_PICTURE5);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic6 = (CStatic *)GetDlgItem(IDC_PICTURE6);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic7 = (CStatic *)GetDlgItem(IDC_PICTURE7);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	CStatic *pStatic8 = (CStatic *)GetDlgItem(IDC_PICTURE8);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic9 = (CStatic *)GetDlgItem(IDC_PICTURE9);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	//设置指示图片
	pStatic1->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic2->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic3->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic4->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic5->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic6->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic7->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic8->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic9->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic1->SetBitmap(hBitmap3);
	pStatic2->SetBitmap(hBitmap3);
	pStatic3->SetBitmap(hBitmap3);
	pStatic4->SetBitmap(hBitmap3);
	pStatic5->SetBitmap(hBitmap3);
	pStatic6->SetBitmap(hBitmap3);
	pStatic7->SetBitmap(hBitmap3);
	pStatic8->SetBitmap(hBitmap3);
	pStatic9->SetBitmap(hBitmap3);

	//字体设置
	m_font1.CreatePointFont(90, _T(TEXT_FONT));
	m_static1.SetFont(&m_font1);
	m_static2.SetFont(&m_font1);
	m_static3.SetFont(&m_font1);
	m_static4.SetFont(&m_font1);
	m_static5.SetFont(&m_font1);
	m_static6.SetFont(&m_font1);
	m_static7.SetFont(&m_font1);
	m_static8.SetFont(&m_font1);
	m_static9.SetFont(&m_font1);
	m_static10.SetFont(&m_font1);
	m_static11.SetFont(&m_font1);
	m_static13.SetFont(&m_font1);
	m_static_11.SetFont(&m_font1);
	m_static_12.SetFont(&m_font1);
	m_static_13.SetFont(&m_font1);
	m_button_cnfs.SetFont(&m_font1);
	m_button_cnwd.SetFont(&m_font1);
	m_button_fjpl.SetFont(&m_font1);
	m_button_fjtz.SetFont(&m_font1);
	m_button_fshd.SetFont(&m_font1);
	m_button_fjyx.SetFont(&m_font1);
	m_button_jrhd.SetFont(&m_font1);
	m_button_jrtz.SetFont(&m_font1);
	m_button_jryx.SetFont(&m_font1);
	m_button_jwyx.SetFont(&m_font1);
	m_button_jwtz.SetFont(&m_font1);
	m_button_jwhd.SetFont(&m_font1);
	m_font2.CreatePointFont(120, _T(TEXT_FONT));
	CEdit *m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TIME);
	m_Edit->SetFont(&m_font2, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES);
	m_Edit->SetFont(&m_font2, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED);
	m_Edit->SetFont(&m_font2, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP);
	m_Edit->SetFont(&m_font2, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_REALTIME);
	m_Edit->SetFont(&m_font2, FALSE);

	m_strStatic11 = _T("30°C");
	m_strStatic12 = _T("3.00m/s");
	m_strStatic13 = _T("50Hz");

	m_button_fjpl.EnableWindow(FALSE);
	m_static_13.EnableWindow(FALSE);

	m_button_fshd.EnableWindow(FALSE);
	//显示日期
	tm = CTime::GetCurrentTime();
	m_strRealTime = tm.Format("%Y年%m月%d日\r\n%X");

	UpdateData(FALSE);
	SetTimer(3, 50, 0);
	SetTimer(4, 60, NULL);
	SetTimer(5, INVERTER_TX_INTERVAL, 0);
	return 1;
}

CDataCtrl::CDataCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DATA_DISPLAYCONTROL, pParent)
	, m_strRecvData(_T(""))
	, m_strTemp(_T(""))
	, m_strSpeed(_T(""))
	, m_strTime(_T(""))
	, m_strPressure(_T(""))
	, m_strRealTime(_T(""))
	, m_strStatic11(_T(""))
	, m_strStatic12(_T(""))
	, m_strStatic13(_T(""))
{
	m_time = 0.0f;
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	m_iBtnExitFromRight = 4;
	m_iBtnExitFromBottom = 50;
}

CDataCtrl::~CDataCtrl()
{
}

void CDataCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_STATIC3, m_static3);
	DDX_Control(pDX, IDC_STATIC4, m_static4);
	DDX_Control(pDX, IDC_STATIC5, m_static5);
	DDX_Control(pDX, IDC_STATIC6, m_static6);
	DDX_Control(pDX, IDC_STATIC7, m_static7);
	DDX_Control(pDX, IDC_STATIC8, m_static8);
	DDX_Control(pDX, IDC_STATIC9, m_static9);
	DDX_Control(pDX, IDC_STATIC10, m_static10);
	DDX_Control(pDX, IDC_MSCOMM1, m_cComm);
	DDX_Text(pDX, IDC_EDIT_RECV, m_strRecvData);
	DDX_Control(pDX, IDC_BUTTON_CNWD, m_button_cnwd);
	DDX_Control(pDX, IDC_BUTTON_CNFS, m_button_cnfs);
	DDX_Control(pDX, IDC_BUTTON_FJYX, m_button_fjyx);
	DDX_Control(pDX, IDC_BUTTON_FSHD, m_button_fshd);
	DDX_Control(pDX, IDC_BUTTON_FJTZ, m_button_fjtz);
	DDX_Control(pDX, IDC_BUTTON_JRYX, m_button_jryx);
	DDX_Control(pDX, IDC_BUTTON_JRHD, m_button_jrhd);
	DDX_Control(pDX, IDC_BUTTON_JRTZ, m_button_jrtz);
	DDX_Control(pDX, IDC_BUTTON_JWYX, m_button_jwyx);
	DDX_Control(pDX, IDC_BUTTON_JWHD, m_button_jwhd);
	DDX_Control(pDX, IDC_BUTTON_JWTZ, m_button_jwtz);
	DDX_Control(pDX, IDC_MSCOMM2, m_cComm2);
	DDX_Text(pDX, IDC_EDIT_TEMP, m_strTemp);
	DDX_Text(pDX, IDC_EDIT_SPEED, m_strSpeed);
	DDX_Text(pDX, IDC_EDIT_TIME, m_strTime);
	DDX_Control(pDX, IDC_STATIC11, m_static11);
	DDX_Control(pDX, IDC_STATIC13, m_static13);
	DDX_Text(pDX, IDC_EDIT_PRES, m_strPressure);
	DDX_Text(pDX, IDC_EDIT_REALTIME, m_strRealTime);

	//曲线关联控件
	DDX_Control(pDX, IDC_PLOT, m_plot);
	DDX_Text(pDX, IDC_STATIC_11, m_strStatic11);
	DDX_Control(pDX, IDC_STATIC_11, m_static_11);
	DDX_Control(pDX, IDC_STATIC_12, m_static_12);
	DDX_Text(pDX, IDC_STATIC_12, m_strStatic12);
	DDX_Control(pDX, IDC_BUTTON_CNFS2, m_button_fjpl);
	DDX_Text(pDX, IDC_STATIC_13, m_strStatic13);
	DDX_Control(pDX, IDC_STATIC_13, m_static_13);
}


BEGIN_MESSAGE_MAP(CDataCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_FJYX, &CDataCtrl::OnBnClickedButtonFjyx)
	ON_BN_CLICKED(IDC_BUTTON_FSHD, &CDataCtrl::OnBnClickedButtonFshd)
	ON_BN_CLICKED(IDC_BUTTON_FJTZ, &CDataCtrl::OnBnClickedButtonFjtz)
	ON_BN_CLICKED(IDC_BUTTON_JRYX, &CDataCtrl::OnBnClickedButtonJryx)
	ON_BN_CLICKED(IDC_BUTTON_JRHD, &CDataCtrl::OnBnClickedButtonJrhd)
	ON_BN_CLICKED(IDC_BUTTON_JRTZ, &CDataCtrl::OnBnClickedButtonJrtz)
	ON_BN_CLICKED(IDC_BUTTON_JWYX, &CDataCtrl::OnBnClickedButtonJwyx)
	ON_BN_CLICKED(IDC_BUTTON_JWHD, &CDataCtrl::OnBnClickedButtonJwhd)
	ON_BN_CLICKED(IDC_BUTTON_JWTZ, &CDataCtrl::OnBnClickedButtonJwtz)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_CNWD, &CDataCtrl::OnBnClickedButtonCnwd)
	ON_BN_CLICKED(IDC_BUTTON_CNFS, &CDataCtrl::OnBnClickedButtonCnfs)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_DISP_LINE2, &CDataCtrl::OnBnClickedDispLine2)
	ON_BN_CLICKED(IDC_DISP_LINE1, &CDataCtrl::OnBnClickedDispLine1)
	ON_STN_CLICKED(IDC_PLOT, &CDataCtrl::OnStnClickedPlot)
	ON_BN_CLICKED(IDC_Saveimage, &CDataCtrl::OnBnClickedSaveimage)
	ON_EN_CHANGE(IDC_EDIT_RECV, &CDataCtrl::OnEnChangeEditRecv)
	ON_BN_CLICKED(IDC_BUTTON1, &CDataCtrl::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_CNFS2, &CDataCtrl::OnBnClickedButtonCnfs2)
	ON_BN_CLICKED(IDC_BUTTON_TIME_START, &CDataCtrl::OnBnClickedButtonTimeStart)
	ON_BN_CLICKED(IDC_BUTTON_TIME_PAUSE, &CDataCtrl::OnBnClickedButtonTimePause)
	ON_BN_CLICKED(IDC_BUTTON_TIME_CLEAR, &CDataCtrl::OnBnClickedButtonTimeClear)
	ON_BN_CLICKED(IDC_WIND_LINE2, &CDataCtrl::OnBnClickedWindpLine2)
	ON_BN_CLICKED(IDC_WINDPRESS_LINE10, &CDataCtrl::OnBnClickedWindLine10)
	ON_BN_CLICKED(IDC_WIND_LINE1, &CDataCtrl::OnBnClickedWindpLine1)
	ON_BN_CLICKED(IDC_WIND_LINE3, &CDataCtrl::OnBnClickedWindpLine3)
	ON_BN_CLICKED(IDC_WINDPRESS_LINE2, &CDataCtrl::OnBnClickedWindLine2)
	ON_BN_CLICKED(IDC_WINDPRESS_LINE3, &CDataCtrl::OnBnClickedWindLine3)
	ON_BN_CLICKED(IDC_WINDPRESS_LINE4, &CDataCtrl::OnBnClickedWindLine4)
	ON_BN_CLICKED(IDC_WINDPRESS_LINE5, &CDataCtrl::OnBnClickedWindLine5)
	ON_BN_CLICKED(IDC_WINDPRESS_LINE6, &CDataCtrl::OnBnClickedWindLine6)
	ON_BN_CLICKED(IDC_WINDPRESS_LINE7, &CDataCtrl::OnBnClickedWindLine7)
	ON_BN_CLICKED(IDC_WINDPRESS_LINE8, &CDataCtrl::OnBnClickedWindLine8)
	ON_BN_CLICKED(IDC_WINDPRESS_LINE9, &CDataCtrl::OnBnClickedWindLine9)
END_MESSAGE_MAP()

// CDataCtrl 消息处理程序

void CDataCtrl::OnBnClickedButtonFjyx()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE1);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE2);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE3);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中

	if (MessageBox(_T("你确定要开启风机?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		pStatic1->SetBitmap(hBitmap4);
		pStatic2->SetBitmap(hBitmap3);
		pStatic3->SetBitmap(hBitmap3);
		pIntgCtrlDlg->m_button_mode.EnableWindow(FALSE);
		bButtonFlag[0] = 1;
		//ForceMPLC(ADDRESSM_START, TRUE);
	}
}


void CDataCtrl::OnBnClickedButtonFshd()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE1);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE2);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE3);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中


	if (MessageBox(_T("你确定要开启风速恒定?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		pStatic1->SetBitmap(hBitmap3);
		pStatic2->SetBitmap(hBitmap4);
		pStatic3->SetBitmap(hBitmap3);
		pIntgCtrlDlg->m_button_mode.EnableWindow(FALSE);
		bButtonFlag[0] = 2;
		//ForceMPLC(ADDRESSM_START, TRUE);
	}
}


void CDataCtrl::OnBnClickedButtonFjtz()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE1);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE2);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE3);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中


	if (MessageBox(_T("你确定要关闭风机?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		pStatic1->SetBitmap(hBitmap3);
		pStatic2->SetBitmap(hBitmap3);
		pStatic3->SetBitmap(hBitmap4);
		pIntgCtrlDlg->m_button_mode.EnableWindow(TRUE);
		bButtonFlag[0] = 3;
		//ForceMPLC(ADDRESSM_START, FALSE);
	}
}


void CDataCtrl::OnBnClickedButtonJryx()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE4);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE5);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE6);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
																   //pStatic->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE); 

	if (MessageBox(_T("你确定要打开加热模式?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = 0;
		pStatic1->SetBitmap(hBitmap4);
		pStatic2->SetBitmap(hBitmap3);
		pStatic3->SetBitmap(hBitmap3);
		bButtonFlag[1] = 1;
		SendMessageToController(OPEN_HEATER);
	}
}


void CDataCtrl::OnBnClickedButtonJrhd()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE4);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE5);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE6);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
																   //pStatic->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE); 

	if (MessageBox(_T("你确定要恒温加热?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = DTRZMODE_HEATING;
		pStatic1->SetBitmap(hBitmap3);
		pStatic2->SetBitmap(hBitmap4);
		pStatic3->SetBitmap(hBitmap3);
		bButtonFlag[1] = 2;
		SendMessageToController(CONSTANT_HEATING, g_nTempCon);
	}
}


void CDataCtrl::OnBnClickedButtonJrtz()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE4);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE5);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE6);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
																   //pStatic->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE); 

	if (MessageBox(_T("你确定要停止加热?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = 0;
		pStatic1->SetBitmap(hBitmap3);
		pStatic2->SetBitmap(hBitmap3);
		pStatic3->SetBitmap(hBitmap4);
		bButtonFlag[1] = 3;
		SendMessageToController(CLOSE_HEATER);
	}
}


void CDataCtrl::OnBnClickedButtonJwyx()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE7);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE8);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE9);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
																   //pStatic->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE); 

	if (MessageBox(_T("你确定要降温运行?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = 0;
		pStatic1->SetBitmap(hBitmap4);
		pStatic2->SetBitmap(hBitmap3);
		pStatic3->SetBitmap(hBitmap3);
		bButtonFlag[2] = 1;
		SendMessageToController(OPEN_REFRIGERATION);
	}
}


void CDataCtrl::OnBnClickedButtonJwhd()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE7);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE8);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE9);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
																   //pStatic->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE); 

	if (MessageBox(_T("你确定要恒定降温运行?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = DTRZMODE_REFRIGING;
		pStatic1->SetBitmap(hBitmap3);
		pStatic2->SetBitmap(hBitmap4);
		pStatic3->SetBitmap(hBitmap3);
		bButtonFlag[2] = 2;
		SendMessageToController(CONSTANT_REFRIGING, g_nTempCon);
	}
}


void CDataCtrl::OnBnClickedButtonJwtz()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP3),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP4),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE7);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE8);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE9);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
																   //pStatic->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE); 

	if (MessageBox(_T("你确定要停止降温运行?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = 0;
		pStatic1->SetBitmap(hBitmap3);
		pStatic2->SetBitmap(hBitmap3);
		pStatic3->SetBitmap(hBitmap4);
		bButtonFlag[2] = 3;
		SendMessageToController(CLOSE_REFRIGERATION);
	}
}


void CDataCtrl::OnBnClickedButtonCnwd()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nFlagTemp = CNWD;
	CTempControl TempControlDLG;
	TempControlDLG.DoModal();
}


void CDataCtrl::OnBnClickedButtonCnfs()
{
	// TODO: 在此添加控件通知处理程序代码
	CSpeedControl SpeedControlDlg;
	SpeedControlDlg.DoModal();
}

void CDataCtrl::OnBnClickedButtonCnfs2()
{
	// TODO: 在此添加控件通知处理程序代码
	CSpeedControl SpeedControlDlg;
	SpeedControlDlg.DoModal();
}

BEGIN_EVENTSINK_MAP(CDataCtrl, CDialogEx)
	ON_EVENT(CDataCtrl, IDC_MSCOMM1, 1, CDataCtrl::OnComm, VTS_NONE)
	ON_EVENT(CDataCtrl, IDC_MSCOMM2, 1, CDataCtrl::OnComm2, VTS_NONE)
END_EVENTSINK_MAP()

//控制器串口
void CDataCtrl::OnComm()
{
	// TODO: 在此处添加消息处理程序代码
	//从串口接收数据并显示在编辑框中
	CByteArray array;
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len, k;
	BYTE rxdata[1024]; //设置BYTE数组 An 8-bit integerthat is not signed.
	if (m_cComm.get_CommEvent() == 2) //事件值为2表示接收缓冲区内有字符
	{
		variant_inp = m_cComm.get_Input(); //读缓冲区
		safearray_inp = variant_inp; //VARIANT型变量转换为ColeSafeArray型变量
		len = safearray_inp.GetOneDimSize(); //得到有效数据长度
		for (k = 0; k < len; k++)
			safearray_inp.GetElement(&k, rxdata + k);//转换为BYTE型数组
		for (k = 0; k < len; k++) //将数组转换为Cstring型变量
		{
			BYTE bt = *(char*)(rxdata + k); //字符型
			array.Add(bt);
			//strtemp.Format("%02X ", bt); //将字符以十六进制方式送入临时变量strtemp存放，注意这里加入一个空隔
			//m_strRecvData += strtemp; //加入接收编辑框对应字符串 
		}
	}
	//g_strRecvData = m_strRecvData;
	//CString strMessage = m_strRecvData.Right\
	//						(m_strRecvData.GetLength() - m_strRecvDataTemp.GetLength());
	//m_strRecvDataTemp = m_strRecvData;
	if (!OnMessageDisplay(array))
	{
		SendMessageToController(CRC_ERROR);
	}
	CEdit* pedit = (CEdit*)GetDlgItem(IDC_EDIT_RECV);
	pedit->LineScroll(pedit->GetLineCount());
	UpdateData(FALSE); //更新编辑框内容
}

//PLC串口
void CDataCtrl::OnComm2()
{
	// TODO: 在此处添加消息处理程序代码
	CByteArray array;
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len, k;
	BYTE rxdata[1024]; //设置BYTE数组 An 8-bit integerthat is not signed.
	CString strtemp;
	if (m_cComm2.get_CommEvent() == 2) //事件值为2表示接收缓冲区内有字符
	{
		variant_inp = m_cComm2.get_Input(); //读缓冲区
		safearray_inp = variant_inp; //VARIANT型变量转换为ColeSafeArray型变量
		len = safearray_inp.GetOneDimSize(); //得到有效数据长度
		for (k = 0; k < len; k++)
			safearray_inp.GetElement(&k, rxdata + k);//转换为BYTE型数组
		for (k = 0; k < len; k++) //将数组转换为Cstring型变量
		{
			BYTE bt = *(char*)(rxdata + k); //字符型
			array.Add(bt);
		}
	}
	if (g_nFlagReadPlcCmd == 1)
	{
		//g_nFlagReadPlcCmd = 0;
		//if (array[0] != 0x02)
		//{
		//	return;
		//}
		//int Len = array.GetSize();
		//byte Sum = 0x00;
		//for (int i = 1; i != Len - 2; i++)
		//	Sum += array[i];
		//CString str;
		//str.Format(_T("%X"), Sum);
		//WORD* sum = (WORD*)str.GetBuffer();
		//if ((array[Len - 2] != sum[0]) || (array[Len - 1] != sum[1]))
		//{
		//	//MessageBox(_T("校验错误"));
		//	return;
		//}
		//int nvalue = (AscToValue(array[1]) << 12 | AscToValue(array[2]) << 8 |
		//	          AscToValue(array[3]) << 4  | AscToValue(array[4]));
		//float value = (float)nvalue / 100;
	}
}

//显示工作时间
void CDataCtrl::OnTimer(UINT nIDEvent)
{
	//数据框同步
	if (nIDEvent == 3) {
		DWORD timeNow=0;
		DWORD time=0;
		CString hour,min, sec;
		if(g_bTimeCountEnable)
			timeNow= timeGetTime();
		if (timeNow - g_TimeStartCount < 0)
			time = (timeNow - g_TimeStartCount + DWORD_MAX + g_TimePauseMs) / 1000;
		else
			time = (timeNow - g_TimeStartCount + g_TimePauseMs) / 1000;   //sec

		if (time > 3600 * 99)
			g_TimeStartCount = timeGetTime();
		
		hour.Format(_T("%d"), (int)time / 3600);
		min.Format(_T("%d"), (int)time % 3600 / 60);
		sec.Format(_T("%d"), (int)time % 60);
		if (g_bTimeCountEnable)
		{
			Time = time;
			m_strTime = hour + _T(":") + min + _T(":") + sec;
			g_strTime = m_strTime;
		}

		//显示时间
		tm = CTime::GetCurrentTime();
		m_strRealTime = tm.Format(_T("%Y年%m月%d日\r\n%X"));
		UpdateData(FALSE);
	}
	else if (nIDEvent == 5)  //定时向PLC发送数据
	{
		/*if (g_bComOpen2 && SYS_OK)
			WriteDToPLC(ADDRESSD_SPEED_FEEDBACK, _tstof(g_strSpeed));*/
	}
	//曲线绘图定时器服务
	if (nIDEvent == 2) {
		//添加温度（1）
		m_plot.AddNewPoint(m_time, 55, 0);
		//添加风速（1-3）
		m_plot.AddNewPoint(m_time, 2.1, 1);
		m_plot.AddNewPoint(m_time, 3.7, 2);
		m_plot.AddNewPoint(m_time, 4.3, 3);
		//添加风压（4-13）
		m_plot.AddNewPoint(m_time, 6.5, 4);
		m_plot.AddNewPoint(m_time, 11.3, 5);
		m_plot.AddNewPoint(m_time, 7.8, 6);
		m_plot.AddNewPoint(m_time, 23.6, 7);
		m_plot.AddNewPoint(m_time, 7.2, 8);
		m_plot.AddNewPoint(m_time, 7.6, 9);
		m_plot.AddNewPoint(m_time, 7.3,10);
		m_plot.AddNewPoint(m_time, 5.2, 11);
		m_plot.AddNewPoint(m_time, 1.1, 12);
		m_plot.AddNewPoint(m_time, 9.3, 13);
		//曲线移动速度    
		m_time += 0.0625f;
		/*CString look;
		look.Format(_T("%.3f"), Speed_Line);
		MessageBox(look);*/
	}
	
	//数据存储操作
	if (nIDEvent == 4&& flag_in == 1)
	{
		char speed_in[100];
		char speedPress_in[10];
		char temp_in[10];
		int i = 0;
		static int flag_title=0;
		FILE *pfile = fopen(BeginTime, "a+");
		//MessageBox(BeginTime);
		if (flag_title == 0)
		{
		 fprintf(pfile, "%s\t\t%s\t%s\t%s\t\r\n", "系统时间", "风速", "风压", "温度");
		 flag_title = 1;
		}
		
		for (i = 1; i < number; i++) {

			sprintf(speed_in, "%.2f", Speed_in[i]);
			sprintf(speedPress_in, "%.2f", SpeedPress_in[i]);
			sprintf(temp_in, "%.2f", Temp_in[i]);

			fprintf(pfile, "%d-%d-%d %d:%d:%d\t%s\t%s\t%s\t", Year[i], Month[i], Day[i], Hour[i], Min[i], Sec[i],
			speed_in, speedPress_in, temp_in);

			fprintf(pfile, "\r\n");
		}
		
		flag_in = 0;
		fclose(pfile);
	}

}

//返回1:接受成功  返回0:校验失败
BOOL CDataCtrl::OnMessageDisplay(CByteArray& Message)  
{
	SYSTEMTIME st;
	static int count_in = 0;
	if (Message.GetSize() < DTRZ_TX_LEN)
		return 0;

	//校验
	CString str_temp;
	WORD CRC_Value = CRC16(Message, DTRZ_TX_LEN-2);
	if (CRC_Value != ((Message[DTRZ_TX_LEN-1] << 8) | Message[DTRZ_TX_LEN-2]))
		return 0;
	if (Message[0] != 0x23)
		return 0;
	if (Message[1] >= 0x01 && Message[1] <= 0x09)
	{
		return 1;
	}
	
	//解析数据
	if (Message[1] == 0xA0)  
	{
		//从byte转换至float
		static int dtemp[10], dspeed_hotwire[10], dspeed_pitot[10], dpress_ms5611[10], dpress_pitot[10], dwindamt_pitot[10];
		static float ftemp[10], fspeed_hotwire[10], fspeed_pitot[10], fpress_ms5611[10], fpress_pitot[10], fwindamt_pitot[10];
		for (int i = 0; i != 10; ++i)
		{
			dpress_ms5611[i] = (Message[4 * i + 5] << 24) | (Message[4 * i + 4] << 16) | (Message[4 * i + 3] << 8) | Message[4 * i + 2];
			fpress_ms5611[i] = *(float*)(&dpress_ms5611[i]);
			g_strPressMS5611[i].Format(_T("%.2f"), fpress_ms5611[i]);
		}
		for (int i = 0; i != 3; ++i)
		{
			dspeed_hotwire[i] = (Message[4 * i + 45] << 24) | (Message[4 * i + 44] << 16) | (Message[4 * i + 43] << 8) | Message[4 * i + 42];
			fspeed_hotwire[i] = *(float*)(&dspeed_hotwire[i]);
			g_strSpeedHotWire[i].Format(_T("%.2f"), fspeed_hotwire[i]);
		}
		for (int i = 0; i != 3; ++i)
		{
			dspeed_pitot[i] = (Message[4 * i + 57] << 24) | (Message[4 * i + 56] << 16) | (Message[4 * i + 55] << 8) | Message[4 * i + 54];
			fspeed_pitot[i] = *(float*)(&dspeed_pitot[i]);
			g_strSpeedPitot[i].Format(_T("%.2f"), fspeed_pitot[i]);
		}
		for (int i = 0; i != 3; ++i)
		{
			dpress_pitot[i] = (Message[4 * i + 69] << 24) | (Message[4 * i + 68] << 16) | (Message[4 * i + 67] << 8) | Message[4 * i + 66];
			fpress_pitot[i] = *(float*)(&dpress_pitot[i]);
			g_strPressPitot[i].Format(_T("%.2f"), fpress_pitot[i]);
		}
		for (int i = 0; i != 3; ++i)
		{
			dwindamt_pitot[i] = (Message[4 * i + 81] << 24) | (Message[4 * i + 80] << 16) | (Message[4 * i + 79] << 8) | Message[4 * i + 78];
			fwindamt_pitot[i] = *(float*)(&dwindamt_pitot[i]);
			g_strWindAmtPitot[i].Format(_T("%.2f"), fwindamt_pitot[i]);
		}

		for (int i = 0; i != 3; ++i)
		{
			g_strPressDiff[i].Format(_T("%.2f"), fpress_pitot[i]- fpress_ms5611[i]);
		}

		//ftemp = *(float*)(&dtemp);
		//if (g_FlagLineOk)
		//	fspeed = *(float*)(&dspeed);
		//fpressure = *(float*)(&dpressure);

		/*if (g_nFlagMode == MODE_MANU_SPEED && g_bComOpen2 && bButtonFlag[0] == 0)
		{
			if ((fspeed > g_fSpeedCon - 0.02) && (fspeed < g_fSpeedCon + 0.02))
			{
				ForceMPLC(24, FALSE);
			}
		}*/

		//数据显示
		//m_strTemp.Format(_T("%.2f"), ftemp);
		//m_strSpeed.Format(_T("%.2f"), fspeed);
		//m_strPressure.Format(_T("%.2f"), fpressure);

		//str_temp.Format(_T("温度:%.2f\t风速:%.2f\t风压%.2f\r\n"), ftemp,fspeed,fpressure);
		//m_strRecvData += str_temp;
		//m_strRecvData = m_strRecvData.Right(200);

		//数据同步
		/*g_strTemp = m_strTemp;
		g_strSpeed = m_strSpeed;
		g_strPressure = m_strPressure;
		g_strRecvData = m_strRecvData;*/

		//将值在曲线中更新
		g_line_strTemp = ftemp[0];
		if (g_FlagLineOk)
		{
			g_line_strSpeed = fspeed_hotwire[0];
		}
		//将值保存在txt的变量
		Speed_in[count_in] = fspeed_hotwire[0];
		SpeedPress_in[count_in] = fpress_ms5611[0];
		Temp_in[count_in] = ftemp[0];

		//得到某点的时间
		GetLocalTime(&st);
		Year[count_in] = st.wYear;
		Month[count_in] = st.wMonth;
		Day[count_in] = st.wDay;
		Hour[count_in] = st.wHour;
		Min[count_in] = st.wMinute;
		Sec[count_in] = st.wSecond;


		if (count_in == number)
		{
			count_in = 0;
			flag_in = 1;
		}
		count_in++;
		return 1;
	}
	else
		return 0;
}

//发送信息到控制器
void CDataCtrl::SendMessageToController(byte b1, byte b2)
{
	CByteArray Message;
	Message.Add(0x24);
	Message.Add(b1);
	Message.Add(b2);
	WORD CRC_Value = CRC16(Message, 3);
	Message.Add((byte)CRC_Value);
	Message.Add((byte)(CRC_Value>>8));
	m_cComm.put_Output(COleVariant(Message));
}

//发送信息到控制器
void CDataCtrl::SendMessageToController(WORD w1)
{
	CByteArray Message;
	Message.Add(0x24);
	Message.Add(w1>>8);
	Message.Add(w1);
	WORD CRC_Value = CRC16(Message, 3);
	Message.Add((byte)CRC_Value);
	Message.Add((byte)(CRC_Value >> 8));
	m_cComm.put_Output(COleVariant(Message));
}

//读PLC D寄存器数据
void CDataCtrl::ReadDFromPLC(int Address)
{
	CByteArray Message;
	Message.Add(0x02);
	Message.Add(0x30);
	CString str;
	str.Format(_T("%04X"), Address * 2 + 0x1000);
	WORD* pw = (WORD*)str.GetBuffer();
	Message.Add(pw[0]);
	Message.Add(pw[1]);
	Message.Add(pw[2]);
	Message.Add(pw[3]);
	Message.Add(0x30);
	Message.Add(0x32);
	Message.Add(0x03);
	WORD Sum = CheckSum(Message);
	Message.Add(Sum >> 8);
	Message.Add(Sum);
	g_nFlagReadPlcCmd = 1;
	m_cComm2.put_Output((COleVariant)Message);
}

//写PLC D寄存器数据
void CDataCtrl::WriteDToPLC(int Address, float Data)
{
	CByteArray Message;
	Message.Add(0x02);
	Message.Add(0x31);
	CString str;
	str.Format(_T("%04X"), Address * 2 + 0x1000);
	WORD* pw = (WORD*)str.GetBuffer();
	Message.Add(pw[0]);
	Message.Add(pw[1]);
	Message.Add(pw[2]);
	Message.Add(pw[3]);
	Message.Add(0x30);
	Message.Add(0x32);
	short value = Data * 100;
	Message.Add(ValueToAsc((value & 0x00f0) >> 4));
	Message.Add(ValueToAsc( value & 0x000f));
	Message.Add(ValueToAsc((value & 0xf000) >> 12));
	Message.Add(ValueToAsc((value & 0x0f00) >> 8));
	Message.Add(0x03);
	WORD Sum = CheckSum(Message);
	Message.Add(Sum >> 8);
	Message.Add(Sum);
	m_cComm2.put_Output((COleVariant)Message);
}

//读PLC M寄存器 (!!!)
void CDataCtrl::ReadMFromPLC(int Address)
{
	CByteArray Message;
	Message.Add(0x02);
	Message.Add(0x30);
	CString str;
	str.Format(_T("%04X"), Address + 0x800);
	WORD* pw = (WORD*)str.GetBuffer();
	Message.Add(pw[0]);
	Message.Add(pw[1]);
	Message.Add(pw[2]);
	Message.Add(pw[3]);
	Message.Add(0x30);
	Message.Add(0x31);
	Message.Add(0x03);
	WORD Sum = CheckSum(Message);
	Message.Add(Sum >> 8);
	Message.Add(Sum);
	g_nFlagReadPlcCmd = 2;
	m_cComm2.put_Output((COleVariant)Message);
}

//置位/复位 PLC M寄存器数据
void CDataCtrl::ForceMPLC(int Address, BOOL Value)
{
	CByteArray Message;
	Message.Add(0x02);
	if (Value)
		Message.Add(0x37);
	else
		Message.Add(0x38);
	CString str;
	str.Format(_T("%04X"), Address + 0x800);
	WORD* pw = (WORD*)str.GetBuffer();
	Message.Add(pw[2]);
	Message.Add(pw[3]);
	Message.Add(pw[0]);
	Message.Add(pw[1]);
	Message.Add(0x03);
	WORD Sum = CheckSum(Message);
	Message.Add(Sum >> 8);
	Message.Add(Sum);
	m_cComm2.put_Output((COleVariant)Message);
}

void CDataCtrl::WriteToInverter(int command, int data, int datasize)
{
	CByteArray Message;
	Message.Add(INVERTER_ENQ);
	Message.Add(0x31);
	CString str;
	str.Format(_T("%02X"), INVERTER_UNIT);
	WORD* pw = (WORD*)str.GetBuffer();
	Message.Add(pw[0]);
	Message.Add(pw[1]);
	str.Format(_T("%02X"), command);
	pw = (WORD*)str.GetBuffer();
	Message.Add(pw[0]);
	Message.Add(pw[1]);
	switch (datasize)
	{
		case 2:str.Format(_T("%02X"), data);break;
		case 4:str.Format(_T("%04X"), data); break;
		default:
			return;
	}
	pw = (WORD*)str.GetBuffer();
	for (int i = 0; i != datasize; i++)
		Message.Add(pw[i]);
	WORD Sum = CheckSum(Message);
	Message.Add(Sum >> 8);
	Message.Add(Sum);
	m_cComm2.put_Output((COleVariant)Message);
}

//和校验
WORD CDataCtrl::CheckSum(CByteArray& Data)
{
	int Sum = 0;
	int len = Data.GetSize();
	for (len -= 1; len != 0; len--)
		Sum += Data[len];
	CString str;
	str.Format(_T("%02X"), Sum);
	WORD* sum = (WORD*)str.GetBuffer();
	return (sum[0] << 8) + sum[1];
}

void CDataCtrl::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	float fsp[2];
	POINT Newp; //获取现在对话框的大小  
	CRect recta;
	pMainDlg->m_tab.GetClientRect(&recta); //取客户区大小    
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / g_OldSizeTab2.x;
	fsp[1] = (float)Newp.y / g_OldSizeTab2.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //左上角  
	CPoint OldBRPoint, BRPoint; //右下角  
	HWND hwndChild = ::GetWindow(m_hWnd, GW_CHILD); //列出所有控件    
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//取得ID  
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		OldTLPoint = Rect.TopLeft();
		TLPoint.x = long(OldTLPoint.x*fsp[0]);
		TLPoint.y = long(OldTLPoint.y*fsp[1]);
		OldBRPoint = Rect.BottomRight();
		BRPoint.x = long(OldBRPoint.x *fsp[0]);
		BRPoint.y = long(OldBRPoint.y *fsp[1]);
		Rect.SetRect(TLPoint, BRPoint);
		if (GetDlgItem(woc) == &m_plot)
		{
			CString ss;
			int X_value;
			int Y_value;
			int old_X;
			int old_Y;
			X_value=BRPoint.x - TLPoint.x-87-2;
			old_X = X_value;

			Y_value = BRPoint.y - TLPoint.y-51-1;
			old_Y = Y_value;

			for (x_gridsize = 2; x_gridsize < 100; x_gridsize++)
			{
				if (35* x_gridsize ==X_value)
					break;
				if (x_gridsize == 99)
				{
					x_gridsize = 2;
					X_value--;
				}
			}
		

			for (y_gridsize = 20; y_gridsize < 100; y_gridsize++)
			{
				if (20 * y_gridsize == Y_value)
					break;
				if (y_gridsize == 99)
				{
					y_gridsize = 2;
					Y_value--;
				}
			}
			x_subtract = X_value - old_X;
			y_subtract = Y_value - old_Y;

			flag_changeSize = true;
			ss.Format(_T("%d,%d,%d,%d,y_subtract=%d"), y_gridsize,old_Y,Y_value,Y_value-old_Y, y_subtract);
			//MessageBox(ss);
		}

		GetDlgItem(woc)->MoveWindow(Rect, TRUE);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);

		//

	}
	g_OldSizeTab2 = Newp;
}


void CDataCtrl::OnBnClickedDispLine2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(4)->IsShow = ((CButton*)GetDlgItem(IDC_DISP_LINE2))->GetCheck();
}


void CDataCtrl::OnBnClickedDispLine1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(0)->IsShow = ((CButton*)GetDlgItem(IDC_DISP_LINE1))->GetCheck();
}


void CDataCtrl::OnStnClickedPlot()
{
	// TODO: 在此添加控件通知处理程序代码
}

//保存图片按钮
void CDataCtrl::OnBnClickedSaveimage()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hWnd = ::FindWindow(NULL, _T("风洞专用实验型软件  FCL1.1.7.151106_beta"));//此处修改为程序名，用以保存图片
	SYSTEMTIME st;
	CString strDate, strTime;
	CString head= strSavepicpath;
	CString nail(".bmp");
	CString Head("D:\\BibTechnology\\BibPic\\");
	GetLocalTime(&st);
	strDate.Format(_T("%d%d%d"), st.wYear, st.wMonth, st.wDay);
	strTime.Format(_T("_%d%d%d"), st.wHour, st.wMinute, st.wSecond);
	
	CString path = Head +/*_T("\\")*/+ strDate + strTime + nail;
	
	if (hWnd)
	{
		//MessageBox(path);
		SaveHwndToBmpFile(hWnd, path);
	}

	
}
//保存bmp图片函数
void CDataCtrl::SaveHwndToBmpFile(HWND hWnd, CString lpszPath)
{
	HDC hDC = ::GetWindowDC(hWnd);
	ASSERT(hDC);

	HDC hMemDC = ::CreateCompatibleDC(hDC);
	ASSERT(hMemDC);

	RECT rc;
	::GetWindowRect(hWnd, &rc);

	HBITMAP hBitmap = ::CreateCompatibleBitmap(hDC, rc.right - rc.left, rc.bottom - rc.top);
	ASSERT(hBitmap);

	HBITMAP hOldBmp = (HBITMAP)::SelectObject(hMemDC, hBitmap);
	::PrintWindow(hWnd, hMemDC, 0);

	BITMAP bitmap = { 0 };
	::GetObject(hBitmap, sizeof(BITMAP), &bitmap);
	BITMAPINFOHEADER bi = { 0 };
	BITMAPFILEHEADER bf = { 0 };

	CONST int nBitCount = 24;
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = bitmap.bmWidth;
	bi.biHeight = bitmap.bmHeight;
	bi.biPlanes = 1;
	bi.biBitCount = nBitCount;
	bi.biCompression = BI_RGB;
	DWORD dwSize = ((bitmap.bmWidth * nBitCount + 31) / 32) * 4 * bitmap.bmHeight;

	HANDLE hDib = GlobalAlloc(GHND, dwSize + sizeof(BITMAPINFOHEADER));
	LPBITMAPINFOHEADER lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
	*lpbi = bi;

	::GetDIBits(hMemDC, hBitmap, 0, bitmap.bmHeight, (BYTE*)lpbi + sizeof(BITMAPINFOHEADER), (BITMAPINFO*)lpbi, DIB_RGB_COLORS);

	try
	{
		CFile file;
		file.Open(lpszPath, CFile::modeCreate | CFile::modeWrite);
		bf.bfType = 0x4d42;
		dwSize += sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
		bf.bfSize = dwSize;
		bf.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

		file.Write((BYTE*)&bf, sizeof(BITMAPFILEHEADER));
		file.Write((BYTE*)lpbi, dwSize);
		file.Close();
	}
	catch (CFileException* e)
	{
		e->ReportError();
		e->Delete();
	}

	GlobalUnlock(hDib);
	GlobalFree(hDib);

	::SelectObject(hMemDC, hOldBmp);
	::DeleteObject(hBitmap);
	::DeleteObject(hMemDC);
	::ReleaseDC(hWnd, hDC);
}


void CDataCtrl::OnEnChangeEditRecv()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CDataCtrl::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
}

WORD CDataCtrl::AscToValue(byte asc)
{
	switch (asc)
	{
	case '0': return 0; break;
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '4': return 4; break;
	case '5': return 5; break;
	case '6': return 6; break;
	case '7': return 7; break;
	case '8': return 8; break;
	case '9': return 9; break;
	case 'A': return 10; break;
	case 'B': return 11; break;
	case 'C': return 12; break;
	case 'D': return 13; break;
	case 'E': return 14; break;
	case 'F': return 15; break;
	default:
		break;
	}
}

byte CDataCtrl::ValueToAsc(byte value)
{
	switch (value)
	{
	case 0: return '0'; break;
	case 1: return '1'; break;
	case 2: return '2'; break;
	case 3: return '3'; break;
	case 4: return '4'; break;
	case 5: return '5'; break;
	case 6: return '6'; break;
	case 7: return '7'; break;
	case 8: return '8'; break;
	case 9: return '9'; break;
	case 10: return 'A'; break;
	case 11: return 'B'; break;
	case 12: return 'C'; break;
	case 13: return 'D'; break;
	case 14: return 'E'; break;
	case 15: return 'F'; break;
	default:
		break;
	}
}



void CDataCtrl::OnBnClickedButtonTimeStart()
{
	// TODO: 在此添加控件通知处理程序代码
	g_bTimeCountEnable = TRUE;
	g_TimeStartCount = timeGetTime();
}


void CDataCtrl::OnBnClickedButtonTimePause()
{
	// TODO: 在此添加控件通知处理程序代码
	g_bTimeCountEnable = FALSE;
	DWORD timeNow = 0;
	DWORD time = 0;
	timeNow = timeGetTime();
	if (timeNow - g_TimeStartCount < 0)
		time = (timeNow - g_TimeStartCount + DWORD_MAX + g_TimePauseMs) / 1000;
	else
		time = (timeNow - g_TimeStartCount + g_TimePauseMs) / 1000;   //sec

	g_TimePauseMs = time * 1000;

}

void CDataCtrl::OnBnClickedButtonTimeClear()
{
	// TODO: 在此添加控件通知处理程序代码
	g_TimeStartCount = timeGetTime();
	g_TimePauseMs = 0;
	g_strTime = m_strTime=_T("0:0:0");
	UpdateData(FALSE);
}


void CDataCtrl::OnBnClickedWindpLine2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(2)->IsShow = ((CButton*)GetDlgItem(IDC_WIND_LINE2))->GetCheck();
}


void CDataCtrl::OnBnClickedWindLine10()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(13)->IsShow = ((CButton*)GetDlgItem(IDC_WINDPRESS_LINE10))->GetCheck();
}


void CDataCtrl::OnBnClickedWindpLine1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(1)->IsShow = ((CButton*)GetDlgItem(IDC_WIND_LINE1))->GetCheck();
}


void CDataCtrl::OnBnClickedWindpLine3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(3)->IsShow = ((CButton*)GetDlgItem(IDC_WIND_LINE3))->GetCheck();
}


void CDataCtrl::OnBnClickedWindLine2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(5)->IsShow = ((CButton*)GetDlgItem(IDC_WINDPRESS_LINE2))->GetCheck();
}


void CDataCtrl::OnBnClickedWindLine3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(6)->IsShow = ((CButton*)GetDlgItem(IDC_WINDPRESS_LINE3))->GetCheck();
}


void CDataCtrl::OnBnClickedWindLine4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(7)->IsShow = ((CButton*)GetDlgItem(IDC_WINDPRESS_LINE4))->GetCheck();
}


void CDataCtrl::OnBnClickedWindLine5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(8)->IsShow = ((CButton*)GetDlgItem(IDC_WINDPRESS_LINE5))->GetCheck();
}


void CDataCtrl::OnBnClickedWindLine6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(9)->IsShow = ((CButton*)GetDlgItem(IDC_WINDPRESS_LINE6))->GetCheck();
}


void CDataCtrl::OnBnClickedWindLine7()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(10)->IsShow = ((CButton*)GetDlgItem(IDC_WINDPRESS_LINE7))->GetCheck();
}


void CDataCtrl::OnBnClickedWindLine8()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(11)->IsShow = ((CButton*)GetDlgItem(IDC_WINDPRESS_LINE8))->GetCheck();
}


void CDataCtrl::OnBnClickedWindLine9()
{
	// TODO: 在此添加控件通知处理程序代码
	m_plot.GetLineByIndex(12)->IsShow = ((CButton*)GetDlgItem(IDC_WINDPRESS_LINE9))->GetCheck();
}
