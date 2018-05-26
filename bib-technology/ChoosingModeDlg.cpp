// ChoosingModeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bib-technology.h"
#include "ChoosingModeDlg.h"
#include "afxdialogex.h"
#include "IntgCtrl.h"
#include "DataCtrl.h"
#include "GLOBAL.h"

extern CDataCtrl* pDtaCtrlDlg;
extern CIntgCtrl* pIntgCtrlDlg;
// CChoosingModeDlg �Ի���

IMPLEMENT_DYNAMIC(CChoosingModeDlg, CDialogEx)

CChoosingModeDlg::CChoosingModeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CChoosingModeDlg::~CChoosingModeDlg()
{
}

void CChoosingModeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChoosingModeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CChoosingModeDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CChoosingModeDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON10, &CChoosingModeDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CChoosingModeDlg ��Ϣ�������


void CChoosingModeDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_nFlagMode = MODE_MANU_FREQUENCE;
	pIntgCtrlDlg->m_strStatic14 = _T("�ֶ�ģʽ-Ƶ��");
	pIntgCtrlDlg->m_button_cnfs.EnableWindow(FALSE);
	pIntgCtrlDlg->m_button_fjpl.EnableWindow(TRUE);
	pIntgCtrlDlg->m_static_12.EnableWindow(FALSE);
	pIntgCtrlDlg->m_static_13.EnableWindow(TRUE);
	pIntgCtrlDlg->m_button_fjyx.EnableWindow(TRUE);
	pIntgCtrlDlg->m_button_fshd.EnableWindow(FALSE);

	pDtaCtrlDlg->m_button_cnfs.EnableWindow(FALSE);
	pDtaCtrlDlg->m_button_fjpl.EnableWindow(TRUE);
	pDtaCtrlDlg->m_static_12.EnableWindow(FALSE);
	pDtaCtrlDlg->m_static_13.EnableWindow(TRUE);
	pDtaCtrlDlg->m_button_fjyx.EnableWindow(TRUE);
	pDtaCtrlDlg->m_button_fshd.EnableWindow(FALSE);

	//pDtaCtrlDlg->ForceMPLC(ADDRESSM_MODE, FALSE);
	CDialogEx::OnOK();
}


void CChoosingModeDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_nFlagMode = MODE_AUTO;
	pIntgCtrlDlg->m_strStatic14 = _T("�Զ�ģʽ-����");
	pIntgCtrlDlg->m_button_cnfs.EnableWindow(TRUE);
	pIntgCtrlDlg->m_button_fjpl.EnableWindow(FALSE);
	pIntgCtrlDlg->m_static_12.EnableWindow(TRUE);
	pIntgCtrlDlg->m_static_13.EnableWindow(FALSE);
	pIntgCtrlDlg->m_button_fjyx.EnableWindow(FALSE);
	pIntgCtrlDlg->m_button_fshd.EnableWindow(TRUE);

	pDtaCtrlDlg->m_button_cnfs.EnableWindow(TRUE);
	pDtaCtrlDlg->m_button_fjpl.EnableWindow(FALSE);
	pDtaCtrlDlg->m_static_12.EnableWindow(TRUE);
	pDtaCtrlDlg->m_static_13.EnableWindow(FALSE);
	pDtaCtrlDlg->m_button_fjyx.EnableWindow(FALSE);
	pDtaCtrlDlg->m_button_fshd.EnableWindow(TRUE);

	//pDtaCtrlDlg->ForceMPLC(ADDRESSM_MODE, TRUE);
	CDialogEx::OnOK();
}


void CChoosingModeDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_nFlagMode = MODE_MANU_SPEED;
	pIntgCtrlDlg->m_strStatic14 = _T("�ֶ�ģʽ-����");
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

	//pDtaCtrlDlg->ForceMPLC(ADDRESSM_MODE, FALSE);
	CDialogEx::OnOK();
}
