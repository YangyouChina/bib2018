
// bib-technologyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bib-technology.h"
#include "bib-technologyDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include "COMSETTING.h"
#include "GLOBAL.h"
#include "MyAboutBox.h"
#include "XYSetting.h"
#include "Instruction.h"
#include "DataCtrl.h"
#include "ChooseHeater.h"
#include "IntgCtrl.h"
#include <shellapi.h>
#include <fstream>
#include <sstream>

#include "shlwapi.h"  
#pragma comment(lib,"shlwapi.lib")  

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CbibtechnologyDlg* pMainDlg;
extern CDataCtrl* pDtaCtrlDlg;
extern CIntgCtrl* pIntgCtrlDlg;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CbibtechnologyDlg 对话框


IMPLEMENT_DYNAMIC(CbibtechnologyDlg, CDialogEx);

CbibtechnologyDlg::CbibtechnologyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BIBTECHNOLOGY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	m_pAutoProxy = NULL;
}

CbibtechnologyDlg::~CbibtechnologyDlg()
{
	// 如果该对话框有自动化代理，则
	//  将此代理指向该对话框的后向指针设置为 NULL，以便
	//  此代理知道该对话框已被删除。
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CbibtechnologyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CbibtechnologyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CbibtechnologyDlg::OnTcnSelchangeTab1)
	ON_COMMAND(ID_COM_SET, &CbibtechnologyDlg::OnComSet)
	ON_WM_SIZE()
	ON_COMMAND(ID_32783, &CbibtechnologyDlg::OnAbout)
	ON_COMMAND(ID_32784, &CbibtechnologyDlg::OnYvalue)
	ON_WM_TIMER()
	ON_COMMAND(ID_32785, &CbibtechnologyDlg::OnSavepicPath)
	ON_COMMAND(ID_32786, &CbibtechnologyDlg::OnSaveData)
	ON_COMMAND(ID_32787, &CbibtechnologyDlg::OnInstruct)
	ON_COMMAND(ID_32788, &CbibtechnologyDlg::OnMainTempSensor)
	ON_COMMAND(ID_32789, &CbibtechnologyDlg::OnBackupTempSensor)
	ON_COMMAND(ID_32780, &CbibtechnologyDlg::OnExit)
	ON_BN_CLICKED(IDC_BUTTON1, &CbibtechnologyDlg::OnBnClickedButton1)
	ON_COMMAND(ID_32790, &CbibtechnologyDlg::On_ChooseHeater)
	ON_COMMAND(ID_32791, &CbibtechnologyDlg::On_Lock)
	ON_COMMAND(ID_32792, &CbibtechnologyDlg::On_Unlock)
	ON_COMMAND(ID_32793, &CbibtechnologyDlg::On_calibration)
END_MESSAGE_MAP()


// CbibtechnologyDlg 消息处理程序

BOOL CbibtechnologyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str = _T("D:\\BibTechnology");
	if (!PathIsDirectory(str))
	{
		::CreateDirectory(str, NULL);//创建目录,已有的话不影响  
	}
	str += _T("\\BibData");
	if (!PathIsDirectory(str))
	{
		::CreateDirectory(str, NULL);//创建目录,已有的话不影响  
	}
    str = _T("D:\\BibTechnology");
	if (!PathIsDirectory(str))
	{
		::CreateDirectory(str, NULL);//创建目录,已有的话不影响  
	}
	str += _T("\\BibPic");
	if (!PathIsDirectory(str))
	{
		::CreateDirectory(str, NULL);//创建目录,已有的话不影响  
	}


	// 将“关于...”菜单项添加到系统菜单中。
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	
	// TODO: 在此添加额外的初始化代码
	pMainDlg = this;
	

	//修改主窗口底部文字
	((CStatic*)GetDlgItem(IDC_STATIC_BOTTOM))->SetWindowText(_T(TEXT_BOTTOM));

	//读取风速对照表
	CStdioFile  file;
	if (!file.Open(_T("风速对照表.txt"), CFile::modeRead))
	{
		MessageBox(_T("风速对照表打开失败"));
	}
	else
	{
		CString s;
		CString strWord;
		file.ReadString(s);
		while (file.ReadString(s))
		{
			s.Trim();
			int nPos = s.Find(_T(" "));
			if (nPos < 0)
				continue;
			double speed= _wtof(s.Left(nPos));
			s.Delete(0, nPos + 1);
			s.Trim();
			g_fSpeedToFrequence[(int)(speed * 10) - 1][0] = speed;
			g_fSpeedToFrequence[(int)(speed * 10) - 1][1] = _wtof(s.Left(nPos));
		}
	}

	//CString  a;
	//a.Format(_T("%f"), g_fSpeedToFrequence[2][1]);
	//MessageBox(a);

	//选项卡设置
	m_tab.InsertItem(0, _T("数据显控"));
	m_tab.InsertItem(1, _T("综合显控"));

	m_data.Create(IDD_DATA_DISPLAYCONTROL, GetDlgItem(IDC_TAB1));
	m_intg.Create(IDD_INTEGRATE_DISPLAYCONTROL, GetDlgItem(IDC_TAB1));

	CRect rs;
	m_tab.GetClientRect(&rs);
	rs.top += 20;
	g_OldSizeTab.x = g_OldSizeTab2.x = rs.right - rs.left;
	g_OldSizeTab.y = g_OldSizeTab2.y = rs.bottom - rs.top;

	m_data.MoveWindow(&rs);
	m_intg.MoveWindow(&rs);

	m_data.ShowWindow(false);
	m_intg.ShowWindow(true);
	m_tab.SetCurSel(0);
	
	if (m_LoginDlg.DoModal() != IDOK)
	{
		OnOK();
	}
	
	SetTimer(1, 50, 0);
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CbibtechnologyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CbibtechnologyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CbibtechnologyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。  这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

void CbibtechnologyDlg::OnClose()
{
	if (MessageBox(_T("退出系统将关闭所有工作状态，是否确定退出系统?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		if (g_bComOpen1)
		{
			pDtaCtrlDlg->SendMessageToController(CLOSE_HEATER);
			Sleep(400);
			pDtaCtrlDlg->SendMessageToController(CLOSE_REFRIGERATION);
		} 
		if (g_bComOpen2)
		{
			/*pDtaCtrlDlg->ForceMPLC(ADDRESSM_START, FALSE);
			Sleep(400);
			pDtaCtrlDlg->ForceMPLC(ADDRESSM_MODE, FALSE);
			Sleep(400);
			pDtaCtrlDlg->WriteDToPLC(ADDRESSD_SPEED_SETTING, 0);
			Sleep(400);
			pDtaCtrlDlg->WriteDToPLC(ADDRESSD_FREQUENCY_SETTING, 0);*/
			pDtaCtrlDlg->WriteToInverter(INVERTER_RUN_COMMAMD, INVERTER_RUN_DATA_STOP, 1);
		}
	}
	else
		return;
	if (CanExit())
		CDialogEx::OnClose();
}

void CbibtechnologyDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CbibtechnologyDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CbibtechnologyDlg::CanExit()
{
	// 如果代理对象仍保留在那里，则自动化
	//  控制器仍会保持此应用程序。
	//  使对话框保留在那里，但将其 UI 隐藏起来。
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}
	
	return TRUE;
}



void CbibtechnologyDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int CurSel  = m_tab.GetCurSel();
	switch (CurSel)
	{
	case 0:

		m_data.ShowWindow(false);
		m_intg.ShowWindow(true);
		SetImg(bButtonFlag, 0);
		break;
	case 1:
		m_data.ShowWindow(true);
		m_intg.ShowWindow(false);
		SetImg(bButtonFlag, 1);
		break;
	}
}


void CbibtechnologyDlg::OnComSet()
{
	// TODO: 在此添加命令处理程序代码
	COMDLG.ShowWindow(true);
}

void CbibtechnologyDlg::SetImg(byte* bButtonFlag,int nMode)
{
	if (nMode == 1)
	{
		HBITMAP hBitmap3 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP3),
			IMAGE_BITMAP, 0, 0,
			LR_LOADMAP3DCOLORS);
		HBITMAP hBitmap4 = (HBITMAP)LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP4),
			IMAGE_BITMAP, 0, 0,
			LR_LOADMAP3DCOLORS);
		CStatic *pStatic1 = (CStatic *)m_data.GetDlgItem(IDC_PICTURE1);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
		CStatic *pStatic2 = (CStatic *)m_data.GetDlgItem(IDC_PICTURE2);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic3 = (CStatic *)m_data.GetDlgItem(IDC_PICTURE3);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic4 = (CStatic *)m_data.GetDlgItem(IDC_PICTURE4);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
		CStatic *pStatic5 = (CStatic *)m_data.GetDlgItem(IDC_PICTURE5);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic6 = (CStatic *)m_data.GetDlgItem(IDC_PICTURE6);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic7 = (CStatic *)m_data.GetDlgItem(IDC_PICTURE7);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
		CStatic *pStatic8 = (CStatic *)m_data.GetDlgItem(IDC_PICTURE8);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic9 = (CStatic *)m_data.GetDlgItem(IDC_PICTURE9);//控件ID     
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
		switch (bButtonFlag[0])
		{
		case 1: pStatic1->SetBitmap(hBitmap4); break;
		case 2: pStatic2->SetBitmap(hBitmap4); break;
		case 3: pStatic3->SetBitmap(hBitmap4); break;
		default:break;
		}
		switch (bButtonFlag[1])
		{
		case 1: pStatic4->SetBitmap(hBitmap4); break;
		case 2: pStatic5->SetBitmap(hBitmap4); break;
		case 3: pStatic6->SetBitmap(hBitmap4); break;
		default:break;
		}
		switch (bButtonFlag[2])
		{
		case 1: pStatic7->SetBitmap(hBitmap4); break;
		case 2: pStatic8->SetBitmap(hBitmap4); break;
		case 3: pStatic9->SetBitmap(hBitmap4); break;
		default:break;
		}
	}
	else
	{
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
		CStatic *pStatic1 = (CStatic *)m_intg.GetDlgItem(IDC_PICTURE1);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
		CStatic *pStatic2 = (CStatic *)m_intg.GetDlgItem(IDC_PICTURE3);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic3 = (CStatic *)m_intg.GetDlgItem(IDC_PICTURE4);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic4 = (CStatic *)m_intg.GetDlgItem(IDC_PICTURE6);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
		CStatic *pStatic5 = (CStatic *)m_intg.GetDlgItem(IDC_PICTURE10);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic6 = (CStatic *)m_intg.GetDlgItem(IDC_PICTURE11);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic7 = (CStatic *)m_intg.GetDlgItem(IDC_PICTURE14);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中 
		CStatic *pStatic8 = (CStatic *)m_intg.GetDlgItem(IDC_PICTURE15);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic9 = (CStatic *)m_intg.GetDlgItem(IDC_PICTURE12);//控件ID     
																//设置静态控件的样式，使其可以使用位图，并试位标显示使居中
		CStatic *pStatic10 = (CStatic *)m_intg.GetDlgItem(IDC_PICTURE13);//控件ID     
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
		switch (bButtonFlag[0])
		{
		case 1: pStatic1->SetBitmap(hBitmap2); break;
		//case 2: pStatic2->SetBitmap(hBitmap2); break;
		case 3: pStatic2->SetBitmap(hBitmap2); break;
		default:break;
		}
		switch (bButtonFlag[1])
		{
		case 1: pStatic3->SetBitmap(hBitmap2); break;
		//case 2: pStatic5->SetBitmap(hBitmap2); break;
		case 3: pStatic4->SetBitmap(hBitmap2); break;
		default:break;
		}
		switch (bButtonFlag[2])
		{
		case 1: pStatic5->SetBitmap(hBitmap2); break;
		//case 2: pStatic8->SetBitmap(hBitmap2); break;
		case 3: pStatic6->SetBitmap(hBitmap2); break;
		default:break;
		}
		switch (bButtonFlag[3])
		{
		case 1: pStatic7->SetBitmap(hBitmap2); break;
			//case 2: pStatic8->SetBitmap(hBitmap2); break;
		case 3: pStatic8->SetBitmap(hBitmap2); break;
		default:break;
		}
		switch (bButtonFlag[4])
		{
		case 1: pStatic9->SetBitmap(hBitmap2); break;
			//case 2: pStatic8->SetBitmap(hBitmap2); break;
		case 3: pStatic10->SetBitmap(hBitmap2); break;
		default:break;
		}
	}
}

void CbibtechnologyDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	static int i=1;
	if ( nType == SIZE_MAXIMIZED || nType == SIZE_RESTORED)//窗体大小发生变动。处理函数rdesize
	{
		if (i == 0)
		{
			CRect recta;
			m_tab.GetClientRect(&recta); //取客户区大小   
			recta.top += 20;
			m_data.MoveWindow(&recta);
			m_intg.MoveWindow(&recta);
		}
		i = 0;
	}
	
}


void CbibtechnologyDlg::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	CMyAboutBox AboutDlg;
	AboutDlg.DoModal();
}


void CbibtechnologyDlg::OnYvalue()
{
	// TODO: 在此添加命令处理程序代码
	CXYSetting Dlg;
	Dlg.DoModal();
}


void CbibtechnologyDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
	static int i = 1;
	if (nIDEvent == 1 && i==1) 
	{
		i = 0;
		COMDLG.Create(IDD_COM_SET, this);
		COMDLG.ShowWindow(true);
	}
}


void CbibtechnologyDlg::OnSavepicPath()
{
	// TODO: 在此添加命令处理程序代码
	BROWSEINFO browseInfo;
	browseInfo.hwndOwner = this->m_hWnd;
	browseInfo.pidlRoot = NULL;
	browseInfo.pszDisplayName = NULL;
	browseInfo.lpszTitle = _T("请选择图片保存路径");
	browseInfo.ulFlags = BIF_RETURNFSANCESTORS | BIF_RETURNONLYFSDIRS;
	browseInfo.lpfn = NULL;
	browseInfo.lParam = 0;
	LPITEMIDLIST lpItemIDList;

	if ((lpItemIDList = ::SHBrowseForFolder(&browseInfo)) != NULL)
	{
		if (::SHGetPathFromIDList(lpItemIDList, strSavepicpath))
		{
			if (strSavepicpath[0] == _T('\0'))
			{
				AfxMessageBox(_T("Fail to get directory"), MB_ICONSTOP | MB_OK);
				return;
			}

			MessageBox(strSavepicpath);
		}
		else
		{
			AfxMessageBox(_T("Fail to get directory!"), MB_ICONSTOP | MB_OK);
			return;
		}
	}

}


void CbibtechnologyDlg::OnSaveData()
{
	// TODO: 在此添加命令处理程序代码
	BROWSEINFO browseInfo;
	browseInfo.hwndOwner = this->m_hWnd;
	browseInfo.pidlRoot = NULL;
	browseInfo.pszDisplayName = NULL;
	browseInfo.lpszTitle = _T("请选择图片保存路径");
	browseInfo.ulFlags = BIF_RETURNFSANCESTORS | BIF_RETURNONLYFSDIRS;
	browseInfo.lpfn = NULL;
	browseInfo.lParam = 0;
	LPITEMIDLIST lpItemIDList;

	if ((lpItemIDList = ::SHBrowseForFolder(&browseInfo)) != NULL)
	{
		if (::SHGetPathFromIDList(lpItemIDList, strSavedatapath))
		{
			if (strSavedatapath[0] == _T('\0'))
			{
				AfxMessageBox(_T("Fail to get directory"), MB_ICONSTOP | MB_OK);
				return;
			}
			MessageBox(strSavedatapath);
		}
		else
		{
			AfxMessageBox(_T("Fail to get directory!"), MB_ICONSTOP | MB_OK);
			return;
		}
	}
}


void CbibtechnologyDlg::OnInstruct()
{
	// TODO: 在此添加命令处理程序代码
	//CInstruction  instr;
	//instr.DoModal();
	ShellExecute(NULL, _T("open"), _T("TR1800使用说明.pdf"), NULL, NULL, SW_SHOW);
}


void CbibtechnologyDlg::OnMainTempSensor()
{
	// TODO: 在此添加命令处理程序代码
	pDtaCtrlDlg->SendMessageToController(TEMPSENSOR_MAIN);
	this->GetMenu()->EnableMenuItem(ID_32788, MF_GRAYED);
	this->GetMenu()->EnableMenuItem(ID_32789, MF_ENABLED);
}

void CbibtechnologyDlg::OnBackupTempSensor()
{
	// TODO: 在此添加命令处理程序代码
	pDtaCtrlDlg->SendMessageToController(TEMPSENSOR_BACKUP);
	this->GetMenu()->EnableMenuItem(ID_32788, MF_ENABLED);
	this->GetMenu()->EnableMenuItem(ID_32789, MF_GRAYED);
}


void CbibtechnologyDlg::OnExit()
{
	// TODO: 在此添加命令处理程序代码
	SYS_OK = 0;
	if (g_bComOpen1)
	{
		pDtaCtrlDlg->SendMessageToController(CLOSE_HEATER);
		Sleep(400);
		pDtaCtrlDlg->SendMessageToController(CLOSE_REFRIGERATION);
	}
	if (g_bComOpen2)
	{
		/*pDtaCtrlDlg->ForceMPLC(ADDRESSM_START, FALSE);
		Sleep(400);
		pDtaCtrlDlg->ForceMPLC(ADDRESSM_MODE, FALSE);
		Sleep(400);
		pDtaCtrlDlg->WriteDToPLC(ADDRESSD_SPEED_SETTING, 0);
		Sleep(400);
		pDtaCtrlDlg->WriteDToPLC(ADDRESSD_FREQUENCY_SETTING, 0);
		Sleep(300);*/
		pDtaCtrlDlg->WriteToInverter(INVERTER_RUN_COMMAMD, INVERTER_RUN_DATA_STOP, 1);
	}
	SYS_OK = 1;
	OnOK();
}


void CbibtechnologyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nFlagDTRZMode = 0;
	SYS_OK = 0;
	if (g_bComOpen1)
	{
		pDtaCtrlDlg->SendMessageToController(CLOSE_HEATER);
		Sleep(400);
		pDtaCtrlDlg->SendMessageToController(CLOSE_REFRIGERATION);
	}
	if (g_bComOpen2)
	{
		/*pDtaCtrlDlg->ForceMPLC(ADDRESSM_START, FALSE);
		Sleep(300);
		pDtaCtrlDlg->ForceMPLC(ADDRESSM_MODE, FALSE);
		Sleep(300);
		pDtaCtrlDlg->ForceMPLC(24, TRUE);
		Sleep(300);
		pDtaCtrlDlg->WriteDToPLC(ADDRESSD_SPEED_SETTING, 0);
		Sleep(300);
		pDtaCtrlDlg->WriteDToPLC(ADDRESSD_FREQUENCY_SETTING, 0);
		Sleep(300);*/
		pDtaCtrlDlg->WriteToInverter(INVERTER_RUN_COMMAMD, INVERTER_RUN_DATA_STOP, 1);
	}
	SYS_OK = 1;
	g_nFlagMode = MODE_MANU_SPEED;
	pIntgCtrlDlg->m_button_mode.EnableWindow(TRUE);

	pIntgCtrlDlg->m_strStatic14 = _T("手动模式-风速");
	pIntgCtrlDlg->m_button_cnfs.EnableWindow(TRUE);
	pIntgCtrlDlg->m_button_fjpl.EnableWindow(FALSE);
	pIntgCtrlDlg->m_static_12.EnableWindow(TRUE);
	pIntgCtrlDlg->m_static_13.EnableWindow(FALSE);
	pIntgCtrlDlg->m_button_fjyx.EnableWindow(TRUE);
	pIntgCtrlDlg->m_button_fshd.EnableWindow(FALSE);

	pDtaCtrlDlg->m_button_cnfs.EnableWindow(TRUE);
	pDtaCtrlDlg->m_button_fjpl.EnableWindow(FALSE);
	pDtaCtrlDlg->m_static_12.EnableWindow(TRUE);
	pDtaCtrlDlg->m_static_13.EnableWindow(FALSE);
	pDtaCtrlDlg->m_button_fjyx.EnableWindow(TRUE);
	pDtaCtrlDlg->m_button_fshd.EnableWindow(FALSE);

	g_fSpeedCon = 0;
	pDtaCtrlDlg->m_strStatic12.Format(_T("%.2f"), g_fSpeedCon);
	pDtaCtrlDlg->m_strStatic12 += _T("m/s");
	pIntgCtrlDlg->m_strStatic12.Format(_T("%.2f"), g_fSpeedCon);
	pIntgCtrlDlg->m_strStatic12 += _T("m/s");

	g_fFrequencyCon = 0;
	pIntgCtrlDlg->m_strStatic13.Format(_T("%.2f"), g_fFrequencyCon);
	pIntgCtrlDlg->m_strStatic13 += _T("Hz");
	pDtaCtrlDlg->m_strStatic13.Format(_T("%.2f"), g_fFrequencyCon);
	pDtaCtrlDlg->m_strStatic13 += _T("Hz");
	UpdateData(FALSE);
	bButtonFlag[0] = bButtonFlag[1] = bButtonFlag[2] = bButtonFlag[3] = bButtonFlag[4] = 0;;
	SetImg(bButtonFlag, 0);
	SetImg(bButtonFlag, 1);

}

void CbibtechnologyDlg::On_ChooseHeater()
{
	// TODO: 在此添加命令处理程序代码
	CChooseHeater ChooseHeartDlg;
	ChooseHeartDlg.DoModal();
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

void CbibtechnologyDlg::On_Lock()
{
	// TODO: 在此添加命令处理程序代码
	g_FlagLineOk = FALSE;
	//pDtaCtrlDlg->ForceMPLC(24, TRUE);
}

void CbibtechnologyDlg::On_Unlock()
{
	// TODO: 在此添加命令处理程序代码
	g_FlagLineOk = TRUE;
	//pDtaCtrlDlg->ForceMPLC(24, FALSE);
}


void CbibtechnologyDlg::On_calibration()
{
	// TODO: 在此添加命令处理程序代码
	if (MessageBox(_T("你确定要标定传感器?"), _T("提示:"), MB_YESNO) == IDYES)
	{
		pDtaCtrlDlg->SendMessageToController(CALIBRATE_HEATER1);
		Sleep(500);
		pDtaCtrlDlg->SendMessageToController(CALIBRATE_HEATER2);
	}
	
}
