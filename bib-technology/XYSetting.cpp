// XYSetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bib-technology.h"
#include "XYSetting.h"
#include "afxdialogex.h"
#include "TempControl.h"

CXYSetting* pXYSettingDlg;
// CXYSetting �Ի���

IMPLEMENT_DYNAMIC(CXYSetting, CDialogEx)

BOOL CXYSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	pXYSettingDlg = this;
	//����/��ѹY������
	m_Speedmin.SetRange(0, 50);
	m_Speedmin.SetTicFreq(1);
	m_Speedmin.SetPos(Speed_minchange);

	m_Speedmax.SetRange(0, 50);
	m_Speedmax.SetTicFreq(1);
	m_Speedmax.SetPos(Speed_maxchange);

	//�¶�Y������
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
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

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

// ע��: ������� IID_IXYSetting ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {32686463-54B0-4066-AEA8-BADC71EF3F39}
static const IID IID_IXYSetting =
{ 0x32686463, 0x54B0, 0x4066,{ 0xAE, 0xA8, 0xBA, 0xDC, 0x71, 0xEF, 0x3F, 0x39 } };

BEGIN_INTERFACE_MAP(CXYSetting, CDialogEx)
	INTERFACE_PART(CXYSetting, IID_IXYSetting, Dispatch)
END_INTERFACE_MAP()


// CXYSetting ��Ϣ�������


void CXYSetting::OnNMCustomdrawXmin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	Speed_minchange = m_Speedmin.GetPos();
}



void CXYSetting::OnNMCustomdrawXmax(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	Speed_maxchange = m_Speedmax.GetPos();
}


void CXYSetting::OnNMCustomdrawYmin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	Temp_minchange = m_Ymin.GetPos();
}


void CXYSetting::OnNMCustomdrawYmax(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	Temp_maxchange = m_Ymax.GetPos();
}


void CXYSetting::OnBnClickedSminset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_nFlagTemp = SMin;
	CTempControl Dlg;
	Dlg.DoModal();
}


void CXYSetting::OnBnClickedSmaxset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_nFlagTemp = SMax;
	CTempControl Dlg;
	Dlg.DoModal();
}


void CXYSetting::OnBnClickedTminset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_nFlagTemp = TMin;
	CTempControl Dlg;
	Dlg.DoModal();
}


void CXYSetting::OnBnClickedTmaxset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_nFlagTemp = TMax;
	CTempControl Dlg;
	Dlg.DoModal();
}
