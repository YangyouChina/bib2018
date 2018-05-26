// IntgCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "bib-technology.h"
#include "afxdialogex.h"
#include "GLOBAL.h"
#include "TempControl.h"
#include "SpeedControl.h"
#include "ChooseHeater.h"
#include "IntgCtrl.h"
#include "DataCtrl.h"
#include "ChoosingModeDlg.h"
#include "bib-technologyDlg.h"
#include <Mmsystem.h>

extern CDataCtrl* pDtaCtrlDlg;
extern CbibtechnologyDlg* pMainDlg;
CIntgCtrl* pIntgCtrlDlg;
// CIntgCtrl 对话框

IMPLEMENT_DYNAMIC(CIntgCtrl, CDialogEx)

BOOL CIntgCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	pIntgCtrlDlg = this;
	//关联图片ID    
	HBITMAP hBitmap1 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	HBITMAP hBitmap2 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE1);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE3);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE4);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic4 = (CStatic *)GetDlgItem(IDC_PICTURE6);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	CStatic *pStatic5 = (CStatic *)GetDlgItem(IDC_PICTURE10);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic6 = (CStatic *)GetDlgItem(IDC_PICTURE11);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic7 = (CStatic *)GetDlgItem(IDC_PICTURE14);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	CStatic *pStatic8 = (CStatic *)GetDlgItem(IDC_PICTURE15);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic9 = (CStatic *)GetDlgItem(IDC_PICTURE12);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	CStatic *pStatic10 = (CStatic *)GetDlgItem(IDC_PICTURE13);//控件ID     
															//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	pStatic1->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic2->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic3->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic4->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic5->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic6->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic7->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic8->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic9->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic10->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);
	pStatic1->SetBitmap(hBitmap1);
	pStatic2->SetBitmap(hBitmap2);
	pStatic3->SetBitmap(hBitmap1);
	pStatic4->SetBitmap(hBitmap2);
	pStatic5->SetBitmap(hBitmap1);
	pStatic6->SetBitmap(hBitmap2);
	pStatic7->SetBitmap(hBitmap1);
	pStatic8->SetBitmap(hBitmap2);
	pStatic9->SetBitmap(hBitmap1);
	pStatic10->SetBitmap(hBitmap2);

	//设置字体
	m_font1.CreatePointFont(150, _T(TEXT_FONT));
	m_button_cnfs.SetFont(&m_font1);
	m_button_cnwd.SetFont(&m_font1);
	m_button_fjpl.SetFont(&m_font1);
	m_button_mode.SetFont(&m_font1);
	m_button_rec1.SetFont(&m_font1);
	m_button_rec2.SetFont(&m_font1);
	m_button_rec3.SetFont(&m_font1);
	m_button_rec4.SetFont(&m_font1);
	m_button_rec5.SetFont(&m_font1);
	m_button_rec6.SetFont(&m_font1);
	m_static_11.SetFont(&m_font1);
	m_static_12.SetFont(&m_font1);
	m_static_13.SetFont(&m_font1);
	m_static_14.SetFont(&m_font1);

	m_font2.CreatePointFont(150, _T(TEXT_FONT));
	m_static7.SetFont(&m_font2);
	m_static8.SetFont(&m_font2);
	m_static15.SetFont(&m_font2);
	m_static16.SetFont(&m_font2);
	m_static17.SetFont(&m_font2);

	m_static9.SetFont(&m_font2);
	m_static10.SetFont(&m_font2);
	m_button_fjtz.SetFont(&m_font2);
	m_button_fshd.SetFont(&m_font2);
	m_button_fjyx.SetFont(&m_font2);
	m_button_jrhd.SetFont(&m_font2);
	m_button_jrtz.SetFont(&m_font2);
	m_button_jryx.SetFont(&m_font2);
	m_button_jwyx.SetFont(&m_font2);
	m_button_jwtz.SetFont(&m_font2);
	m_button_jwhd.SetFont(&m_font2);
	m_button_arun.SetFont(&m_font2);
	m_button_astop.SetFont(&m_font2);
	m_button_brun.SetFont(&m_font2);
	m_button_bstop.SetFont(&m_font2);
	m_button_crun.SetFont(&m_font2);
	m_button_cstop.SetFont(&m_font2);
	m_font3.CreatePointFont(180, _T(TEXT_FONT));
	m_static0.SetFont(&m_font3);
	m_static1.SetFont(&m_font3);
	m_static2.SetFont(&m_font3);
	m_static3.SetFont(&m_font3);
	m_static4.SetFont(&m_font3);
	m_static5.SetFont(&m_font3);
	m_static6.SetFont(&m_font3);
	m_static11.SetFont(&m_font3);
	m_static12.SetFont(&m_font3);
	m_static18.SetFont(&m_font3);
	m_static19.SetFont(&m_font3);
	m_static20.SetFont(&m_font3);
	m_static21.SetFont(&m_font3);
	m_static22.SetFont(&m_font3);
	m_static23.SetFont(&m_font3);
	m_static24.SetFont(&m_font3);
	m_static25.SetFont(&m_font3);
	m_static26.SetFont(&m_font3);
	m_static27.SetFont(&m_font3);
	m_static28.SetFont(&m_font3);
	m_static29.SetFont(&m_font3);
	m_static30.SetFont(&m_font3);
	m_static31.SetFont(&m_font3);
	m_static32.SetFont(&m_font3);
	m_static33.SetFont(&m_font3);
	m_static34.SetFont(&m_font3);
	m_static35.SetFont(&m_font3);
	m_static36.SetFont(&m_font3);
	m_static37.SetFont(&m_font3);
	m_static38.SetFont(&m_font3);
	m_static39.SetFont(&m_font3);
	m_static40.SetFont(&m_font3);
	m_static41.SetFont(&m_font3);
	m_static42.SetFont(&m_font3);
	m_static43.SetFont(&m_font3);
	m_static44.SetFont(&m_font3);
	m_static45.SetFont(&m_font3);
	m_static46.SetFont(&m_font3);
	m_static47.SetFont(&m_font3);
	m_static48.SetFont(&m_font3);
	m_static49.SetFont(&m_font3);
	m_static50.SetFont(&m_font3);
	m_static51.SetFont(&m_font3);
	m_static52.SetFont(&m_font3);
	m_static53.SetFont(&m_font3);
	m_static54.SetFont(&m_font3);
	m_static55.SetFont(&m_font3);
	m_static56.SetFont(&m_font3);
	m_static57.SetFont(&m_font3);
	m_static58.SetFont(&m_font3);
	m_static59.SetFont(&m_font3);
	m_static60.SetFont(&m_font3);
	m_static61.SetFont(&m_font3);
	m_static62.SetFont(&m_font3);
	m_static63.SetFont(&m_font3);
	m_static64.SetFont(&m_font3);
	m_static65.SetFont(&m_font3);
	m_static66.SetFont(&m_font3);
	m_static67.SetFont(&m_font3);
	m_static68.SetFont(&m_font3);
	m_static69.SetFont(&m_font3);
	m_static70.SetFont(&m_font3);
	m_static71.SetFont(&m_font3);
	m_static72.SetFont(&m_font3);
	m_static73.SetFont(&m_font3);
	m_static74.SetFont(&m_font3);
	m_static75.SetFont(&m_font3);
	m_static76.SetFont(&m_font3); 
	m_static77.SetFont(&m_font3);
	m_static78.SetFont(&m_font3);
	m_static79.SetFont(&m_font3);
	m_static80.SetFont(&m_font3);
	m_static81.SetFont(&m_font3);
	m_static88.SetFont(&m_font3);
	m_static89.SetFont(&m_font3);
	m_static90.SetFont(&m_font3);
	m_static91.SetFont(&m_font3);
	m_static92.SetFont(&m_font3);
	m_static93.SetFont(&m_font3);
	m_static94.SetFont(&m_font3);
	m_static95.SetFont(&m_font3);
	m_static96.SetFont(&m_font3);
	m_static97.SetFont(&m_font3);
	m_static98.SetFont(&m_font3);
	m_static99.SetFont(&m_font3);
	m_static100.SetFont(&m_font3);
	
	CEdit *m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TIME);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED2);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED3);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED4);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED5);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED6);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED7);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED8);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED9);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED10);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES1);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES2);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES3);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES4);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES5);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES6);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES7);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES8);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES9);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES10);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT1);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT2);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT3);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT4);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT5);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT6);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT7);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT8);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT9);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT10);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP1);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP2);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP3);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP4);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP5);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP6);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP7);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP8);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP9);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP10);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP1);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP2);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP3);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP4);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP5);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP6);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP7);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP8);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP9);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP10);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP2);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP3);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP4);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP5);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP6);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP7);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP8);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP9);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP10);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_SPEED_REC);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_WINDAMT_REC);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_PRES_REC);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_STATICP_REC);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_DYNAMICP_REC);
	m_Edit->SetFont(&m_font3, FALSE);
	m_Edit = (CEdit *)GetDlgItem(IDC_EDIT_TEMP_REC);
	m_Edit->SetFont(&m_font3, FALSE);

	m_strStatic11 = _T("30°C");
	m_strStatic12 = _T("3.00m/s");
	m_strStatic13 = _T("50.00Hz");
	m_strStatic14 = _T("手动模式-风速");
	m_button_fjpl.EnableWindow(FALSE);
	m_button_fshd.EnableWindow(FALSE);
	m_static_13.EnableWindow(FALSE);
	UpdateData(FALSE);

	//设置定时器
	SetTimer(1, 150, 0);
	return 1;
}

CIntgCtrl::CIntgCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INTEGRATE_DISPLAYCONTROL, pParent)
	, m_strRecvData(_T(""))
	, m_strTemp(_T(""))
	, m_strSpeed(_T(""))
	, m_strTime(_T(""))
	, m_strPressure(_T(""))
	, m_strStatic11(_T(""))
	, m_strStatic12(_T(""))
	, m_strStatic13(_T(""))
	, m_strStatic14(_T(""))
{

}

CIntgCtrl::~CIntgCtrl()
{
}

void CIntgCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_STATIC3, m_static3);
	DDX_Control(pDX, IDC_STATIC4, m_static4);
	DDX_Control(pDX, IDC_STATIC5, m_static5);
	DDX_Control(pDX, IDC_STATIC6, m_static6);
	DDX_Control(pDX, IDC_STATIC0, m_static0);
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
	DDX_Control(pDX, IDC_STATIC7, m_static7);
	DDX_Control(pDX, IDC_STATIC8, m_static8);
	DDX_Control(pDX, IDC_STATIC9, m_static9);
	DDX_Control(pDX, IDC_STATIC10, m_static10);
	DDX_Text(pDX, IDC_EDIT_RECV, m_strRecvData);
	DDX_Text(pDX, IDC_EDIT_TEMP, m_strTemp);
	DDX_Text(pDX, IDC_EDIT_TIME, m_strTime);
	DDX_Control(pDX, IDC_STATIC11, m_static11);
	DDX_Control(pDX, IDC_STATIC12, m_static12);
	DDX_Text(pDX, IDC_EDIT_PRES2, m_strPressure);
	DDX_Control(pDX, IDC_STATIC_11, m_static_11);
	DDX_Control(pDX, IDC_STATIC_12, m_static_12);
	DDX_Text(pDX, IDC_STATIC_11, m_strStatic11);
	DDX_Text(pDX, IDC_STATIC_12, m_strStatic12);
	DDX_Control(pDX, IDC_BUTTON_FJPL, m_button_fjpl);
	DDX_Control(pDX, IDC_BUTTON_MODE, m_button_mode);
	DDX_Control(pDX, IDC_STATIC_13, m_static_13);
	DDX_Text(pDX, IDC_STATIC_13, m_strStatic13);
	DDX_Control(pDX, IDC_STATIC_14, m_static_14);
	DDX_Text(pDX, IDC_STATIC_14, m_strStatic14);
	DDX_Control(pDX, IDC_STATIC15, m_static15);
	DDX_Control(pDX, IDC_STATIC17, m_static17);
	DDX_Control(pDX, IDC_STATIC16, m_static16);
	DDX_Control(pDX, IDC_STATIC18, m_static18);
	DDX_Control(pDX, IDC_STATIC19, m_static19);
	DDX_Control(pDX, IDC_STATIC20, m_static20);
	DDX_Control(pDX, IDC_STATIC21, m_static21);
	DDX_Control(pDX, IDC_STATIC98, m_static98);
	DDX_Control(pDX, IDC_STATIC99, m_static99);
	DDX_Control(pDX, IDC_STATIC100, m_static100);
	DDX_Control(pDX, IDC_STATIC23, m_static23);
	DDX_Control(pDX, IDC_STATIC24, m_static24);
	DDX_Control(pDX, IDC_STATIC26, m_static26);
	DDX_Control(pDX, IDC_STATIC27, m_static27);
	DDX_Control(pDX, IDC_STATIC22, m_static22);
	DDX_Control(pDX, IDC_STATIC29, m_static29);
	DDX_Control(pDX, IDC_STATIC30, m_static30);
	DDX_Control(pDX, IDC_STATIC25, m_static25);
	DDX_Control(pDX, IDC_STATIC31, m_static31);
	DDX_Control(pDX, IDC_STATIC32, m_static32);
	DDX_Control(pDX, IDC_STATIC28, m_static28);
	DDX_Control(pDX, IDC_STATIC35, m_static35);
	DDX_Control(pDX, IDC_STATIC36, m_static36);
	DDX_Control(pDX, IDC_STATIC33, m_static33);
	DDX_Control(pDX, IDC_STATIC37, m_static37);
	DDX_Control(pDX, IDC_STATIC38, m_static38);
	DDX_Control(pDX, IDC_STATIC34, m_static34);
	DDX_Control(pDX, IDC_STATIC41, m_static41);
	DDX_Control(pDX, IDC_STATIC42, m_static42);
	DDX_Control(pDX, IDC_STATIC39, m_static39);
	DDX_Control(pDX, IDC_STATIC43, m_static43);
	DDX_Control(pDX, IDC_STATIC44, m_static44);
	DDX_Control(pDX, IDC_STATIC40, m_static40);
	DDX_Control(pDX, IDC_STATIC47, m_static47);
	DDX_Control(pDX, IDC_STATIC48, m_static48);
	DDX_Control(pDX, IDC_STATIC45, m_static45);
	DDX_Control(pDX, IDC_STATIC49, m_static49);
	DDX_Control(pDX, IDC_STATIC50, m_static50);
	DDX_Control(pDX, IDC_STATIC46, m_static46);
	DDX_Control(pDX, IDC_STATIC53, m_static53);
	DDX_Control(pDX, IDC_STATIC54, m_static54);
	DDX_Control(pDX, IDC_STATIC51, m_static51);
	DDX_Control(pDX, IDC_STATIC55, m_static55);
	DDX_Control(pDX, IDC_STATIC56, m_static56);
	DDX_Control(pDX, IDC_STATIC52, m_static52);
	DDX_Control(pDX, IDC_STATIC59, m_static59);
	DDX_Control(pDX, IDC_STATIC60, m_static60);
	DDX_Control(pDX, IDC_STATIC57, m_static57);
	DDX_Control(pDX, IDC_STATIC61, m_static61);
	DDX_Control(pDX, IDC_STATIC62, m_static62);
	DDX_Control(pDX, IDC_STATIC58, m_static58);
	DDX_Control(pDX, IDC_STATIC65, m_static65);
	DDX_Control(pDX, IDC_STATIC66, m_static66);
	DDX_Control(pDX, IDC_STATIC63, m_static63);
	DDX_Control(pDX, IDC_STATIC67, m_static67);
	DDX_Control(pDX, IDC_STATIC68, m_static68);
	DDX_Control(pDX, IDC_STATIC64, m_static64);
	DDX_Control(pDX, IDC_STATIC71, m_static71);
	DDX_Control(pDX, IDC_STATIC72, m_static72);
	DDX_Control(pDX, IDC_STATIC69, m_static69);
	DDX_Control(pDX, IDC_STATIC73, m_static73);
	DDX_Control(pDX, IDC_STATIC74, m_static74);
	DDX_Control(pDX, IDC_STATIC70, m_static70);
	DDX_Control(pDX, IDC_STATIC97, m_static97);
	DDX_Control(pDX, IDC_STATIC96, m_static96);
	DDX_Control(pDX, IDC_STATIC95, m_static95);
	DDX_Control(pDX, IDC_STATIC94, m_static94);
	DDX_Control(pDX, IDC_STATIC93, m_static93);
	DDX_Control(pDX, IDC_STATIC92, m_static92);
	DDX_Control(pDX, IDC_STATIC91, m_static91);
	DDX_Control(pDX, IDC_STATIC90, m_static90);
	DDX_Control(pDX, IDC_STATIC89, m_static89);
	DDX_Control(pDX, IDC_STATIC88, m_static88);
	DDX_Control(pDX, IDC_BUTTON_REC1, m_button_rec1);
	DDX_Control(pDX, IDC_BUTTON_REC2, m_button_rec2);
	DDX_Control(pDX, IDC_BUTTON_REC3, m_button_rec3);
	DDX_Control(pDX, IDC_BUTTON_REC4, m_button_rec4);
	DDX_Control(pDX, IDC_BUTTON_REC5, m_button_rec5);
	DDX_Control(pDX, IDC_BUTTON_REC6, m_button_rec6);
	DDX_Control(pDX, IDC_STATIC77, m_static77);
	DDX_Control(pDX, IDC_STATIC78, m_static78);
	DDX_Control(pDX, IDC_STATIC75, m_static75);
	DDX_Control(pDX, IDC_STATIC79, m_static79);
	DDX_Control(pDX, IDC_STATIC80, m_static80);
	DDX_Control(pDX, IDC_STATIC76, m_static76);
	DDX_Control(pDX, IDC_STATIC81, m_static81);
	DDX_Control(pDX, IDC_BUTTON_ARUN, m_button_arun);
	DDX_Control(pDX, IDC_BUTTON_ASTOP, m_button_astop);
	DDX_Control(pDX, IDC_BUTTON_BRUN, m_button_brun);
	DDX_Control(pDX, IDC_BUTTON_BSTOP, m_button_bstop);
	DDX_Control(pDX, IDC_BUTTON_CRUN, m_button_crun);
	DDX_Control(pDX, IDC_BUTTON_CSTOP, m_button_cstop);
	DDX_Text(pDX, IDC_EDIT_SPEED, g_strSpeedHotWire[0]);
	DDX_Text(pDX, IDC_EDIT_SPEED2, g_strSpeedHotWire[1]);
	DDX_Text(pDX, IDC_EDIT_SPEED3, g_strSpeedHotWire[2]);
	DDX_Text(pDX, IDC_EDIT_SPEED4, g_strSpeedPitot[0]);
	DDX_Text(pDX, IDC_EDIT_SPEED5, g_strSpeedPitot[1]);
	DDX_Text(pDX, IDC_EDIT_SPEED6, g_strSpeedPitot[2]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT1, g_strWindAmtPitot[0]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT2, g_strWindAmtPitot[1]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT3, g_strWindAmtPitot[2]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT4, g_strWindAmtPitot[3]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT5, g_strWindAmtPitot[4]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT6, g_strWindAmtPitot[5]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT7, g_strWindAmtPitot[6]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT8, g_strWindAmtPitot[7]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT9, g_strWindAmtPitot[8]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT10, g_strWindAmtPitot[9]);
	DDX_Text(pDX, IDC_EDIT_PRES1, g_strPressPitot[0]);
	DDX_Text(pDX, IDC_EDIT_PRES2, g_strPressPitot[1]);
	DDX_Text(pDX, IDC_EDIT_PRES3, g_strPressPitot[2]);
	DDX_Text(pDX, IDC_EDIT_PRES4, g_strPressPitot[3]);
	DDX_Text(pDX, IDC_EDIT_PRES5, g_strPressPitot[4]);
	DDX_Text(pDX, IDC_EDIT_PRES6, g_strPressPitot[5]);
	DDX_Text(pDX, IDC_EDIT_PRES7, g_strPressPitot[6]);
	DDX_Text(pDX, IDC_EDIT_PRES8, g_strPressPitot[7]);
	DDX_Text(pDX, IDC_EDIT_PRES9, g_strPressPitot[8]);
	DDX_Text(pDX, IDC_EDIT_PRES10, g_strPressPitot[9]);
	DDX_Text(pDX, IDC_EDIT_STATICP1, g_strPressDiff[0]);
	DDX_Text(pDX, IDC_EDIT_STATICP2, g_strPressDiff[1]);
	DDX_Text(pDX, IDC_EDIT_STATICP3, g_strPressDiff[2]);
	DDX_Text(pDX, IDC_EDIT_STATICP4, g_strPressDiff[3]);
	DDX_Text(pDX, IDC_EDIT_STATICP5, g_strPressDiff[4]);
	DDX_Text(pDX, IDC_EDIT_STATICP6, g_strPressDiff[5]);
	DDX_Text(pDX, IDC_EDIT_STATICP7, g_strPressDiff[6]);
	DDX_Text(pDX, IDC_EDIT_STATICP8, g_strPressDiff[7]);
	DDX_Text(pDX, IDC_EDIT_STATICP9, g_strPressDiff[8]);
	DDX_Text(pDX, IDC_EDIT_STATICP10, g_strPressDiff[9]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP1, g_strPressMS5611[0]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP2, g_strPressMS5611[1]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP3, g_strPressMS5611[2]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP4, g_strPressMS5611[3]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP5, g_strPressMS5611[4]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP6, g_strPressMS5611[5]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP7, g_strPressMS5611[6]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP8, g_strPressMS5611[7]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP9, g_strPressMS5611[8]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP10, g_strPressMS5611[9]);
	DDX_Text(pDX, IDC_EDIT_TEMP, g_strTempNew[0]);
	DDX_Text(pDX, IDC_EDIT_TEMP2, g_strTempNew[1]);
	DDX_Text(pDX, IDC_EDIT_TEMP3, g_strTempNew[2]);
	DDX_Text(pDX, IDC_EDIT_TEMP4, g_strTempNew[3]);
	DDX_Text(pDX, IDC_EDIT_TEMP5, g_strTempNew[4]);
	DDX_Text(pDX, IDC_EDIT_TEMP6, g_strTempNew[5]);
	DDX_Text(pDX, IDC_EDIT_TEMP7, g_strTempNew[6]);
	DDX_Text(pDX, IDC_EDIT_TEMP8, g_strTempNew[7]);
	DDX_Text(pDX, IDC_EDIT_TEMP9, g_strTempNew[8]);
	DDX_Text(pDX, IDC_EDIT_TEMP10, g_strTempNew[9]);


	DDX_Text(pDX, IDC_EDIT_SPEED_REC, g_strRecData[0]);
	DDX_Text(pDX, IDC_EDIT_WINDAMT_REC, g_strRecData[1]);
	DDX_Text(pDX, IDC_EDIT_PRES_REC, g_strRecData[2]);
	DDX_Text(pDX, IDC_EDIT_STATICP_REC, g_strRecData[3]);
	DDX_Text(pDX, IDC_EDIT_DYNAMICP_REC, g_strRecData[4]);
	DDX_Text(pDX, IDC_EDIT_TEMP_REC, g_strRecData[5]);

}

BEGIN_MESSAGE_MAP(CIntgCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_FJYX, &CIntgCtrl::OnBnClickedButtonFjyx)
	ON_BN_CLICKED(IDC_BUTTON_FSHD, &CIntgCtrl::OnBnClickedButtonFshd)
	ON_BN_CLICKED(IDC_BUTTON_FJTZ, &CIntgCtrl::OnBnClickedButtonFjtz)
	ON_BN_CLICKED(IDC_BUTTON_JRYX, &CIntgCtrl::OnBnClickedButtonJryx)
	ON_BN_CLICKED(IDC_BUTTON_JRHD, &CIntgCtrl::OnBnClickedButtonJrhd)
	ON_BN_CLICKED(IDC_BUTTON_JRTZ, &CIntgCtrl::OnBnClickedButtonJrtz)
	ON_BN_CLICKED(IDC_BUTTON_JWYX, &CIntgCtrl::OnBnClickedButtonJwyx)
	ON_BN_CLICKED(IDC_BUTTON_JWHD, &CIntgCtrl::OnBnClickedButtonJwhd)
	ON_BN_CLICKED(IDC_BUTTON_JWTZ, &CIntgCtrl::OnBnClickedButtonJwtz)
	ON_BN_CLICKED(IDC_BUTTON_CNWD, &CIntgCtrl::OnBnClickedButtonCnwd)
	ON_BN_CLICKED(IDC_BUTTON_CNFS, &CIntgCtrl::OnBnClickedButtonCnfs)
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_MODE, &CIntgCtrl::OnBnClickedButtonMode)
	ON_BN_CLICKED(IDC_BUTTON_FJPL, &CIntgCtrl::OnBnClickedButtonFjpl)
	ON_BN_CLICKED(IDC_BUTTON_TIME_START, &CIntgCtrl::OnBnClickedButtonTimeStart)
	ON_BN_CLICKED(IDC_BUTTON_TIME_PAUSE, &CIntgCtrl::OnBnClickedButtonTimePause)
	ON_BN_CLICKED(IDC_BUTTON_TIME_CLEAR, &CIntgCtrl::OnBnClickedButtonTimeClear)
	ON_BN_CLICKED(IDC_STATIC8, &CIntgCtrl::OnBnClickedStatic8)
	ON_STN_CLICKED(IDC_PICTURE8, &CIntgCtrl::OnStnClickedPicture8)
	ON_EN_CHANGE(IDC_EDIT_RECV, &CIntgCtrl::OnEnChangeEditRecv)
	ON_BN_CLICKED(IDC_BUTTON_REC4, &CIntgCtrl::OnBnClickedButtonRec4)
	ON_BN_CLICKED(IDC_BUTTON_REC1, &CIntgCtrl::OnBnClickedButtonRec1)
	ON_BN_CLICKED(IDC_BUTTON_REC2, &CIntgCtrl::OnBnClickedButtonRec2)
	ON_BN_CLICKED(IDC_BUTTON_REC3, &CIntgCtrl::OnBnClickedButtonRec3)
	ON_BN_CLICKED(IDC_BUTTON_REC5, &CIntgCtrl::OnBnClickedButtonRec5)
	ON_BN_CLICKED(IDC_BUTTON_REC6, &CIntgCtrl::OnBnClickedButtonRec6)
	ON_BN_CLICKED(IDC_BUTTON_ARUN, &CIntgCtrl::OnBnClickedButtonArun)
	ON_BN_CLICKED(IDC_BUTTON_ASTOP, &CIntgCtrl::OnBnClickedButtonAstop)
	ON_BN_CLICKED(IDC_BUTTON_BRUN, &CIntgCtrl::OnBnClickedButtonBrun)
	ON_BN_CLICKED(IDC_BUTTON_BSTOP, &CIntgCtrl::OnBnClickedButtonBstop)
	ON_BN_CLICKED(IDC_BUTTON_CRUN, &CIntgCtrl::OnBnClickedButtonCrun)
	ON_BN_CLICKED(IDC_BUTTON_CSTOP, &CIntgCtrl::OnBnClickedButtonCstop)
END_MESSAGE_MAP()


// CIntgCtrl 消息处理程序

void CIntgCtrl::OnBnClickedButtonFjyx()
{
	// TODO: 在此添加控件通知处理程序代码
	//关联图片ID  
	static HBITMAP hBitmap1 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap2 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE1);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE2);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE3);//控件ID     

	if (MessageBox(_T("你确定要开启风机?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		pStatic1->SetBitmap(hBitmap2);
		pStatic2->SetBitmap(hBitmap1);
		pStatic3->SetBitmap(hBitmap1);
		bButtonFlag[0] = 1;
		m_button_mode.EnableWindow(FALSE);
		//pDtaCtrlDlg->ForceMPLC(ADDRESSM_START, TRUE);
		pDtaCtrlDlg->WriteToInverter(INVERTER_RUN_COMMAMD, INVERTER_RUN_DATA_START, 1);
		Sleep(200);
		pDtaCtrlDlg->WriteToInverter(INVERTER_SET_FREQ_COMMAND, (int)(g_fFrequencyCon * 100), 2);
	}
}


void CIntgCtrl::OnBnClickedButtonFshd()
{
	// TODO: 在此添加控件通知处理程序代码
	//关联图片ID  
	static HBITMAP hBitmap1 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap2 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2),
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
		pStatic1->SetBitmap(hBitmap1);
		pStatic2->SetBitmap(hBitmap2);
		pStatic3->SetBitmap(hBitmap1);
		bButtonFlag[0] = 2;
		m_button_mode.EnableWindow(FALSE);
		//pDtaCtrlDlg->ForceMPLC(ADDRESSM_START, TRUE); 
	}
}


void CIntgCtrl::OnBnClickedButtonFjtz()
{
	// TODO: 在此添加控件通知处理程序代码
	//关联图片ID  
	static HBITMAP hBitmap1 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap2 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2),
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
		pStatic1->SetBitmap(hBitmap1);
		pStatic2->SetBitmap(hBitmap1);
		pStatic3->SetBitmap(hBitmap2);
		m_button_mode.EnableWindow(TRUE);
		bButtonFlag[0] = 3;
		//pDtaCtrlDlg->ForceMPLC(ADDRESSM_START, FALSE);
		pDtaCtrlDlg->WriteToInverter(INVERTER_RUN_COMMAMD, INVERTER_RUN_DATA_STOP, 1);
	}
}


void CIntgCtrl::OnBnClickedButtonJryx()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap1 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap2 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE4);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE5);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE6);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	if (MessageBox(_T("你确定要打开加热模式?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = DTRZMODE_HEATING;
		pStatic1->SetBitmap(hBitmap2);
		pStatic2->SetBitmap(hBitmap1);
		pStatic3->SetBitmap(hBitmap1);
		bButtonFlag[1] = 1;
		//pDtaCtrlDlg->SendMessageToController(OPEN_HEATER);
		pDtaCtrlDlg->SendMessageToController(CONSTANT_HEATING, g_nTempCon);
	}
}


void CIntgCtrl::OnBnClickedButtonJrhd()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap1 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap2 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE4);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE5);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE6);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	if (MessageBox(_T("你确定要恒温加热?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = DTRZMODE_HEATING;
		pStatic1->SetBitmap(hBitmap1);
		pStatic2->SetBitmap(hBitmap2);
		pStatic3->SetBitmap(hBitmap1);
		bButtonFlag[1] = 2;
		pDtaCtrlDlg->SendMessageToController(CONSTANT_HEATING, g_nTempCon);
	}
}


void CIntgCtrl::OnBnClickedButtonJrtz()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap1 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap2 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE4);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE5);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE6);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中

	if (MessageBox(_T("你确定要停止加热?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = 0;
		pStatic1->SetBitmap(hBitmap1);
		pStatic2->SetBitmap(hBitmap1);
		pStatic3->SetBitmap(hBitmap2);
		bButtonFlag[1] = 3;
		pDtaCtrlDlg->SendMessageToController(CLOSE_HEATER);
	}
}


void CIntgCtrl::OnBnClickedButtonJwyx()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap1 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap2 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE7);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE8);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE9);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中

	if (MessageBox(_T("你确定要降温运行?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = 0;
		pStatic1->SetBitmap(hBitmap2);
		pStatic2->SetBitmap(hBitmap1);
		pStatic3->SetBitmap(hBitmap1);
		bButtonFlag[2] = 1;
		pDtaCtrlDlg->SendMessageToController(OPEN_REFRIGERATION);
	}
}


void CIntgCtrl::OnBnClickedButtonJwhd()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap1 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap2 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE7);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE8);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE9);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 

	if (MessageBox(_T("你确定要恒定降温运行?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = DTRZMODE_REFRIGING;
		pStatic1->SetBitmap(hBitmap1);
		pStatic2->SetBitmap(hBitmap2);
		pStatic3->SetBitmap(hBitmap1);
		bButtonFlag[2] = 2;
		pDtaCtrlDlg->SendMessageToController(CONSTANT_REFRIGING, g_nTempCon);
	}
}


void CIntgCtrl::OnBnClickedButtonJwtz()
{
	// TODO: 在此添加控件通知处理程序代码
	static HBITMAP hBitmap1 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	static HBITMAP hBitmap2 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2),
		IMAGE_BITMAP, 0, 0,
		LR_LOADMAP3DCOLORS);
	//获得指向静态控件的指针    
	static CStatic *pStatic1 = (CStatic *)GetDlgItem(IDC_PICTURE7);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
	static CStatic *pStatic2 = (CStatic *)GetDlgItem(IDC_PICTURE8);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中
	static CStatic *pStatic3 = (CStatic *)GetDlgItem(IDC_PICTURE9);//控件ID     
																   //设置静态控件的样式，使其可以使用位图，并试位标显示使居中

	if (MessageBox(_T("你确定要停止降温运行?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		g_nFlagDTRZMode = 0;
		pStatic1->SetBitmap(hBitmap1);
		pStatic2->SetBitmap(hBitmap1);
		pStatic3->SetBitmap(hBitmap2);
		bButtonFlag[2] = 3;
		pDtaCtrlDlg->SendMessageToController(CLOSE_REFRIGERATION);
	}
}

void CIntgCtrl::OnBnClickedButtonCnwd()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nFlagTemp = CNWD;
	CTempControl TempControlDLG;
	TempControlDLG.DoModal();
}


void CIntgCtrl::OnBnClickedButtonCnfs()
{
	// TODO: 在此添加控件通知处理程序代码
	CSpeedControl SpeedControlDlg;
	SpeedControlDlg.DoModal();
}

void CIntgCtrl::OnBnClickedButtonFjpl()
{
	// TODO: 在此添加控件通知处理程序代码
	CSpeedControl SpeedControlDlg;
	SpeedControlDlg.DoModal();

}

 void CIntgCtrl::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default  
	switch (nIDEvent) 
	{
	case 1:
		{
			static CString strRecvDataTemp;
			m_strSpeed = g_strSpeed;
			m_strTemp = g_strTemp;
			m_strTime = g_strTime;
			m_strPressure = g_strPressure;
			UpdateData(FALSE);
			if (strRecvDataTemp != g_strRecvData)
			{
				m_strRecvData = g_strRecvData;
				strRecvDataTemp = m_strRecvData;
				UpdateData(FALSE);
				CEdit* pedit = (CEdit*)GetDlgItem(IDC_EDIT_RECV);
				pedit->LineScroll(pedit->GetLineCount());
			}

			//if (g_nFlagMode == MODE_MANU_SPEED)
			//{
			//	SetDlgItemText(IDC_BUTTON_CNFS, _T("风速设置(手动)"));
			//}
			//else if(g_nFlagMode == MODE_AUTO)
			//{
			//	SetDlgItemText(IDC_BUTTON_CNFS, _T("风速设置(自动)"));
			//}
			break;
		}
	}
}



 void CIntgCtrl::OnSize(UINT nType, int cx, int cy)
 {
	 CDialogEx::OnSize(nType, cx, cy);

	 // TODO: 在此处添加消息处理程序代码
	 float fsp[2];
	 POINT Newp; //获取现在对话框的大小  
	 CRect recta;
	 pMainDlg->m_tab.GetClientRect(&recta); //取客户区大小    
	 Newp.x = recta.right - recta.left;
	 Newp.y = recta.bottom - recta.top;
	 fsp[0] = (float)Newp.x / g_OldSizeTab.x;
	 fsp[1] = (float)Newp.y / g_OldSizeTab.y;
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
		 GetDlgItem(woc)->MoveWindow(Rect, TRUE);
		 hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
	 }
	 g_OldSizeTab = Newp;
 }


 void CIntgCtrl::OnBnClickedButtonMode()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 CChoosingModeDlg Dlg;
	 Dlg.DoModal();
 }

 void CIntgCtrl::OnBnClickedButtonTimeStart()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 g_bTimeCountEnable = TRUE;
	 g_bTimeCountEnable = TRUE;
	 g_TimeStartCount = timeGetTime();
 }


 void CIntgCtrl::OnBnClickedButtonTimePause()
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


 void CIntgCtrl::OnBnClickedButtonTimeClear()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 g_TimeStartCount = timeGetTime();
	 g_TimePauseMs = 0;
	 g_strTime = m_strTime = _T("0:0:0");
	 UpdateData(FALSE);
 }


 void CIntgCtrl::OnBnClickedStatic8()
 {
	 // TODO: 在此添加控件通知处理程序代码
 }


 void CIntgCtrl::OnStnClickedPicture8()
 {
	 // TODO: 在此添加控件通知处理程序代码
 }


 void CIntgCtrl::OnEnChangeEditRecv()
 {
	 // TODO:  如果该控件是 RICHEDIT 控件，它将不
	 // 发送此通知，除非重写 CDialogEx::OnInitDialog()
	 // 函数并调用 CRichEditCtrl().SetEventMask()，
	 // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	 // TODO:  在此添加控件通知处理程序代码
 }

 void CIntgCtrl::OnBnClickedButtonRec1()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 g_strRecData[0] = g_strSpeedHotWire[0];
 }

 void CIntgCtrl::OnBnClickedButtonRec2()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 g_strRecData[1] = g_strWindAmtPitot[0];
 }


 void CIntgCtrl::OnBnClickedButtonRec3()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 g_strRecData[2] = g_strPressPitot[0];
 }

 void CIntgCtrl::OnBnClickedButtonRec4()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 g_strRecData[3] = g_strPressDiff[0];
 }

 void CIntgCtrl::OnBnClickedButtonRec5()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 g_strRecData[4] = g_strPressMS5611[0];
 }


 void CIntgCtrl::OnBnClickedButtonRec6()
 {
	 // TODO: 在此添加控件通知处理程序代码
	 g_strRecData[5] = g_strTempNew[0];
 }


 void CIntgCtrl::OnBnClickedButtonArun()
 {
	 // TODO: 在此添加控件通知处理程序代码
 }


 void CIntgCtrl::OnBnClickedButtonAstop()
 {
	 // TODO: 在此添加控件通知处理程序代码
 }


 void CIntgCtrl::OnBnClickedButtonBrun()
 {
	 // TODO: 在此添加控件通知处理程序代码
 }


 void CIntgCtrl::OnBnClickedButtonBstop()
 {
	 // TODO: 在此添加控件通知处理程序代码
 }


 void CIntgCtrl::OnBnClickedButtonCrun()
 {
	 // TODO: 在此添加控件通知处理程序代码
 }


 void CIntgCtrl::OnBnClickedButtonCstop()
 {
	 // TODO: 在此添加控件通知处理程序代码
 }
