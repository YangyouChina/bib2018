// XYSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "bib-technology.h"
#include "XYSetting.h"
#include "afxdialogex.h"
#include "TempControl.h"

CXYSetting* pXYSettingDlg;
// CXYSetting 对话框

IMPLEMENT_DYNAMIC(CXYSetting, CDialogEx)

BOOL CXYSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	pXYSettingDlg = this;
	//风速/风压Y轴设置
	m_Speedmin.SetRange(0, 50);
	m_Speedmin.SetTicFreq(1);
	m_Speedmin.SetPos(Speed_minchange);

	m_Speedmax.SetRange(0, 50);
	m_Speedmax.SetTicFreq(1);
	m_Speedmax.SetPos(Speed_maxchange);

	//温度Y轴设置
	m_Ymin.SetRange(-120, 500);
	m_Ymin.SetTicFreq(15);
	m_Ymin.SetPos(Temp_minchange);

	m_Ymax.SetRange(-120, 500);
	m_Ymax.SetTicFreq(15);
	m_Ymax.SetPos(Temp_maxchange);
	return 1;
}

CXYSetting::CXYSetting(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

	EnableAutomation();

}

CXYSetting::~CXYSetting()
{
}

void CXYSetting::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CXYSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Xmin, m_Speedmin);
	DDX_Control(pDX, IDC_Ymin, m_Ymin);
	DDX_Control(pDX, IDC_Xmax, m_Speedmax);
	DDX_Control(pDX, IDC_Ymax, m_Ymax);
}


BEGIN_MESSAGE_MAP(CXYSetting, CDialogEx)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_Xmin, &CXYSetting::OnNMCustomdrawXmin)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_Xmax, &CXYSetting::OnNMCustomdrawXmax)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_Ymin, &CXYSetting::OnNMCustomdrawYmin)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_Ymax, &CXYSetting::OnNMCustomdrawYmax)
	ON_BN_CLICKED(IDC_Sminset, &CXYSetting::OnBnClickedSminset)
	ON_BN_CLICKED(IDC_Smaxset, &CXYSetting::OnBnClickedSmaxset)
	ON_BN_CLICKED(IDC_Tminset, &CXYSetting::OnBnClickedTminset)
	ON_BN_CLICKED(IDC_Tmaxset, &CXYSetting::OnBnClickedTmaxset)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CXYSetting, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IXYSetting 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {32686463-54B0-4066-AEA8-BADC71EF3F39}
static const IID IID_IXYSetting =
{ 0x32686463, 0x54B0, 0x4066,{ 0xAE, 0xA8, 0xBA, 0xDC, 0x71, 0xEF, 0x3F, 0x39 } };

BEGIN_INTERFACE_MAP(CXYSetting, CDialogEx)
	INTERFACE_PART(CXYSetting, IID_IXYSetting, Dispatch)
END_INTERFACE_MAP()


// CXYSetting 消息处理程序


void CXYSetting::OnNMCustomdrawXmin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	Speed_minchange = m_Speedmin.GetPos();
}



void CXYSetting::OnNMCustomdrawXmax(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	Speed_maxchange = m_Speedmax.GetPos();
}


void CXYSetting::OnNMCustomdrawYmin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	Temp_minchange = m_Ymin.GetPos();
}


void CXYSetting::OnNMCustomdrawYmax(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	Temp_maxchange = m_Ymax.GetPos();
}


void CXYSetting::OnBnClickedSminset()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nFlagTemp = SMin;
	CTempControl Dlg;
	Dlg.DoModal();
}


void CXYSetting::OnBnClickedSmaxset()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nFlagTemp = SMax;
	CTempControl Dlg;
	Dlg.DoModal();
}


void CXYSetting::OnBnClickedTminset()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nFlagTemp = TMin;
	CTempControl Dlg;
	Dlg.DoModal();
}


void CXYSetting::OnBnClickedTmaxset()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nFlagTemp = TMax;
	CTempControl Dlg;
	Dlg.DoModal();
}
