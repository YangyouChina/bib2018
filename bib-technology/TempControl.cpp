// TempControl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bib-technology.h"
#include "TempControl.h"
#include "afxdialogex.h"
#include "GLOBAL.h"
#include "DataCtrl.h"
#include "IntgCtrl.h"
#include<stdlib.h>

extern CDataCtrl*  pDtaCtrlDlg;
extern CIntgCtrl*  pIntgCtrlDlg;
// CTempControl �Ի���

IMPLEMENT_DYNAMIC(CTempControl, CDialogEx)

BOOL CTempControl::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//���û���������
	switch (g_nFlagTemp)
	{
	case CNWD:  m_sliderTemp.SetRange(0, 130);//�����¶Ȼ�����Χ
				m_sliderTemp.SetTicFreq(10);//ÿ10����λ��һ�̶�
				((CStatic *)GetDlgItem(IDC_STATIC1))->SetWindowText(_T("��"));
				m_sliderTemp.SetPos(g_nTempCon);
				m_strTemp.Format(_T("%d"), g_nTempCon);
				UpdateData(FALSE);
				break;

	case SMin:  m_sliderTemp.ShowWindow(FALSE);
				//m_sliderTemp.SetRange(0, 12);//���÷��ٻ�����Χ
				//m_sliderTemp.SetTicFreq(1);//ÿ1����λ��һ�̶�
				((CStatic *)GetDlgItem(IDC_STATIC1))->SetWindowText(_T("M/S"));
				break;

	case SMax:  m_sliderTemp.ShowWindow(FALSE);
				//m_sliderTemp.SetRange(0, 12);//���÷��ٻ�����Χ
				//m_sliderTemp.SetTicFreq(1);//ÿ1����λ��һ�̶�
				((CStatic *)GetDlgItem(IDC_STATIC1))->SetWindowText(_T("M/S"));
				break;
	case TMin:  m_sliderTemp.ShowWindow(FALSE);
				//m_sliderTemp.SetRange(-100, 200);//�����¶����߻�����Χ
				//m_sliderTemp.SetTicFreq(1);//ÿ10����λ��һ�̶�
				((CStatic *)GetDlgItem(IDC_STATIC1))->SetWindowText(_T("��"));
				break;
	case TMax:  m_sliderTemp.ShowWindow(FALSE);
				//m_sliderTemp.SetRange(-100, 200);//�����¶����߻�����Χ
				//m_sliderTemp.SetTicFreq(1);//ÿ10����λ��һ�̶�
				((CStatic *)GetDlgItem(IDC_STATIC1))->SetWindowText(_T("��"));
				break;
	}

	//��������
	m_font1.CreatePointFont(200, _T("����"));
	CButton* Butt= (CButton *)GetDlgItem(IDC_BUTTON0);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTON0);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTON1);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTON2);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTON3);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTON4);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTON5);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTON6);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTON7);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTON8);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTON9);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTONBACK);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDC_BUTTONDOT);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDOK);
	Butt->SetFont(&m_font1, FALSE);
	Butt = (CButton *)GetDlgItem(IDCANCEL);
	Butt->SetFont(&m_font1, FALSE);
	CEdit* edi= (CEdit *)GetDlgItem(IDC_EDIT1);
	edi->SetFont(&m_font1, FALSE);
	CStatic* stati=(CStatic*)GetDlgItem(IDC_STATIC1);
	stati->SetFont(&m_font1, FALSE);
	return 1;
}

CTempControl::CTempControl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CNWD, pParent)
	, m_strTemp(_T(""))
{

	EnableAutomation();

}

CTempControl::~CTempControl()
{
}

void CTempControl::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CTempControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strTemp);
	DDX_Control(pDX, IDC_SLIDER1, m_sliderTemp);
}


BEGIN_MESSAGE_MAP(CTempControl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTempControl::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTempControl::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTempControl::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTempControl::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTempControl::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CTempControl::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CTempControl::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CTempControl::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CTempControl::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CTempControl::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTONBACK, &CTempControl::OnBnClickedButtonback)
	ON_BN_CLICKED(IDC_BUTTONDOT, &CTempControl::OnBnClickedButtondot)
	ON_BN_CLICKED(IDOK, &CTempControl::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTempControl::OnBnClickedCancel)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CTempControl::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTempControl, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_ITempControl ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {57B0CB89-518B-4068-BB13-F03698A978F0}
static const IID IID_ITempControl =
{ 0x57B0CB89, 0x518B, 0x4068, { 0xBB, 0x13, 0xF0, 0x36, 0x98, 0xA9, 0x78, 0xF0 } };

BEGIN_INTERFACE_MAP(CTempControl, CDialogEx)
	INTERFACE_PART(CTempControl, IID_ITempControl, Dispatch)
END_INTERFACE_MAP()


// CTempControl ��Ϣ�������


void CTempControl::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if (m_strTemp.GetLength() == 1 && m_strTemp.Left(1) == "0")
		{
			m_strTemp.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strTemp += '1';
		UpdateData(FALSE);
	}
}


void CTempControl::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if (m_strTemp.GetLength() == 1 && m_strTemp.Left(1) == "0")
		{
			m_strTemp.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strTemp += '2';
		UpdateData(FALSE);
	}
}


void CTempControl::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if (m_strTemp.GetLength() == 1 && m_strTemp.Left(1) == "0")
		{
			m_strTemp.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strTemp += '3';
		UpdateData(FALSE);
	}
}


void CTempControl::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if (m_strTemp.GetLength() == 1 && m_strTemp.Left(1) == "0")
		{
			m_strTemp.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strTemp += '4';
		UpdateData(FALSE);
	}
}


void CTempControl::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if (m_strTemp.GetLength() == 1 && m_strTemp.Left(1) == "0")
		{
			m_strTemp.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strTemp += '5';
		UpdateData(FALSE);
	}
}


void CTempControl::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if (m_strTemp.GetLength() == 1 && m_strTemp.Left(1) == "0")
		{
			m_strTemp.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strTemp += '6';
		UpdateData(FALSE);
	}
}


void CTempControl::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if (m_strTemp.GetLength() == 1 && m_strTemp.Left(1) == "0")
		{
			m_strTemp.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strTemp += '7';
		UpdateData(FALSE);
	}
}


void CTempControl::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if (m_strTemp.GetLength() == 1 && m_strTemp.Left(1) == "0")
		{
			m_strTemp.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strTemp += '8';
		UpdateData(FALSE);
	}
}


void CTempControl::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if (m_strTemp.GetLength() == 1 && m_strTemp.Left(1) == "0")
		{
			m_strTemp.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strTemp += '9';
		UpdateData(FALSE);
	}
}


void CTempControl::OnBnClickedButton0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if ((m_strTemp.GetLength()==1 )&& (m_strTemp.Left(1) == "0"))
		{
			return;
		}
			m_EditClearButtonFlag = FALSE;
			m_strTemp += '0';
			UpdateData(FALSE);
	}
}


void CTempControl::OnBnClickedButtonback()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	m_EditClearButtonFlag = FALSE;
	m_strTemp=m_strTemp.Left(m_strTemp.GetLength()-1) ;
	UpdateData(FALSE);
}


void CTempControl::OnBnClickedButtondot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	if (m_strTemp.GetLength() <= 10)
	{
		if (m_strTemp.Find(_T(".")) == -1)
		{
			m_EditClearButtonFlag = FALSE;
			if (m_strTemp[0] != '-')
			{
				m_strTemp = '-' + m_strTemp;
			}
			else
			{
				m_strTemp = m_strTemp.Mid(1);
			}
			UpdateData(FALSE);
		}
	}
}


void CTempControl::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	float ftemp = (float)_tstof(m_strTemp);
	switch (g_nFlagTemp)
	{
	case CNWD:
		g_nTempCon = (int)ftemp;
		pDtaCtrlDlg->m_strStatic11.Format(_T("%d"), g_nTempCon);
		pDtaCtrlDlg->m_strStatic11 += _T("��C");
		pIntgCtrlDlg->m_strStatic11.Format(_T("%d"), g_nTempCon);
		pIntgCtrlDlg->m_strStatic11 += _T("��C");
		switch (g_nFlagDTRZMode)
		{
		default:
			break;
		case DTRZMODE_HEATING:
			pDtaCtrlDlg->SendMessageToController(CONSTANT_HEATING, g_nTempCon);
			break;
		case DTRZMODE_REFRIGING:
			pDtaCtrlDlg->SendMessageToController(CONSTANT_REFRIGING, g_nTempCon);
			break;
		}
		UpdateData(FALSE);
		break;
	case SMin:Speed_minchange = ftemp; break;
	case SMax:Speed_maxchange = ftemp; break;
	case TMin:Temp_minchange = ftemp; break;
	case TMax:Temp_maxchange = ftemp; break;
	}
	CDialogEx::OnOK();
}


void CTempControl::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

void CTempControl::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!m_EditClearButtonFlag)
	{
		m_strTemp.Empty();
	}
	m_EditClearButtonFlag = TRUE;
	*pResult = 0;
	UpdateData(TRUE);
	CString str;
	int sldValue = m_sliderTemp.GetPos();
	str.Format(_T("%d"), sldValue);
	m_strTemp=str;
	UpdateData(FALSE);
}
