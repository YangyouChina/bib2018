// SpeedControl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bib-technology.h"
#include "SpeedControl.h"
#include "afxdialogex.h"
#include "GLOBAL.h"
#include "IntgCtrl.h"
#include "DataCtrl.h"

extern CDataCtrl*  pDtaCtrlDlg;
extern CIntgCtrl*  pIntgCtrlDlg;
// CSpeedControl �Ի���

IMPLEMENT_DYNAMIC(CSpeedControl, CDialogEx)

BOOL CSpeedControl::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//���û���������
	switch (g_nFlagMode)
	{
	case MODE_AUTO:
	case MODE_MANU_SPEED:
		m_sliderSpeed.SetRange(0, 700);//���÷��ٻ�����Χ(*100)
		m_sliderSpeed.SetTicFreq(100);//ÿ100����λ��һ�̶�
		((CStatic *)GetDlgItem(IDC_STATIC1))->SetWindowText(_T("m/s"));
		m_sliderSpeed.SetPos(g_fSpeedCon * 100);
		m_strSpeed.Format(_T("%.2f"), g_fSpeedCon);
		UpdateData(FALSE);
		break;
	case MODE_MANU_FREQUENCE:
		m_sliderSpeed.SetRange(0, 10000);//���÷��ٻ�����Χ(*100)
		m_sliderSpeed.SetTicFreq(100);//ÿ100����λ��һ�̶�
		((CStatic *)GetDlgItem(IDC_STATIC1))->SetWindowText(_T("Hz"));
		m_sliderSpeed.SetPos(g_fFrequencyCon * 100);
		m_strSpeed.Format(_T("%.2f"), g_fFrequencyCon);
		UpdateData(FALSE);
		break;
	default:break;
	}

	//��������
	m_font1.CreatePointFont(200, _T("����"));
	CButton* Butt = (CButton *)GetDlgItem(IDC_BUTTON0);
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
	CEdit* edi = (CEdit *)GetDlgItem(IDC_EDIT1);
	edi->SetFont(&m_font1, FALSE);
	CStatic* stati = (CStatic*)GetDlgItem(IDC_STATIC1);
	stati->SetFont(&m_font1, FALSE);
	return 1;
}

CSpeedControl::CSpeedControl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CNFS, pParent)
	, m_strSpeed(_T(""))
{
	EnableAutomation();
}

CSpeedControl::~CSpeedControl()
{
}

void CSpeedControl::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CDialogEx::OnFinalRelease();
}

void CSpeedControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strSpeed);
	DDX_Control(pDX, IDC_SLIDER1, m_sliderSpeed);
}


BEGIN_MESSAGE_MAP(CSpeedControl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSpeedControl::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSpeedControl::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSpeedControl::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CSpeedControl::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CSpeedControl::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CSpeedControl::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CSpeedControl::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CSpeedControl::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CSpeedControl::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTONBACK, &CSpeedControl::OnBnClickedButtonback)
	ON_BN_CLICKED(IDC_BUTTON0, &CSpeedControl::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTONDOT, &CSpeedControl::OnBnClickedButtondot)
	ON_BN_CLICKED(IDOK, &CSpeedControl::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSpeedControl::OnBnClickedCancel)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CSpeedControl::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSpeedControl, CDialogEx)
END_DISPATCH_MAP()

// ע��: ������� IID_ISpeedControl ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {CA8A0BF4-26DB-466D-93CD-3C5B8C25D90D}
static const IID IID_ISpeedControl =
{ 0xCA8A0BF4, 0x26DB, 0x466D, { 0x93, 0xCD, 0x3C, 0x5B, 0x8C, 0x25, 0xD9, 0xD } };

BEGIN_INTERFACE_MAP(CSpeedControl, CDialogEx)
	INTERFACE_PART(CSpeedControl, IID_ISpeedControl, Dispatch)
END_INTERFACE_MAP()


// CSpeedControl ��Ϣ�������


void CSpeedControl::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if (m_strSpeed.GetLength() == 1 && m_strSpeed.Left(1) == "0")
		{
			m_strSpeed.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strSpeed += '1';
		UpdateData(FALSE);
	}
}


void CSpeedControl::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if (m_strSpeed.GetLength() == 1 && m_strSpeed.Left(1) == "0")
		{
			m_strSpeed.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strSpeed += '2';
		UpdateData(FALSE);
	}
}


void CSpeedControl::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if (m_strSpeed.GetLength() == 1 && m_strSpeed.Left(1) == "0")
		{
			m_strSpeed.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strSpeed += '3';
		UpdateData(FALSE);
	}
}


void CSpeedControl::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if (m_strSpeed.GetLength() == 1 && m_strSpeed.Left(1) == "0")
		{
			m_strSpeed.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strSpeed += '4';
		UpdateData(FALSE);
	}
}


void CSpeedControl::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if (m_strSpeed.GetLength() == 1 && m_strSpeed.Left(1) == "0")
		{
			m_strSpeed.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strSpeed += '5';
		UpdateData(FALSE);
	}
}


void CSpeedControl::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if (m_strSpeed.GetLength() == 1 && m_strSpeed.Left(1) == "0")
		{
			m_strSpeed.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strSpeed += '6';
		UpdateData(FALSE);
	}
}


void CSpeedControl::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if (m_strSpeed.GetLength() == 1 && m_strSpeed.Left(1) == "0")
		{
			m_strSpeed.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strSpeed += '7';
		UpdateData(FALSE);
	}
}


void CSpeedControl::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if (m_strSpeed.GetLength() == 1 && m_strSpeed.Left(1) == "0")
		{
			m_strSpeed.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strSpeed += '8';
		UpdateData(FALSE);
	}
}


void CSpeedControl::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if (m_strSpeed.GetLength() == 1 && m_strSpeed.Left(1) == "0")
		{
			m_strSpeed.Empty();
		}
		m_EditClearButtonFlag = FALSE;
		m_strSpeed += '9';
		UpdateData(FALSE);
	}
}


void CSpeedControl::OnBnClickedButton0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if ((m_strSpeed.GetLength() == 1) && (m_strSpeed.Left(1) == "0"))
		{
			return;
		}
		m_EditClearButtonFlag = FALSE;
		m_strSpeed += '0';
		UpdateData(FALSE);
	}
}


void CSpeedControl::OnBnClickedButtonback()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	m_EditClearButtonFlag = FALSE;
	m_strSpeed = m_strSpeed.Left(m_strSpeed.GetLength() - 1);
	UpdateData(FALSE);
}


void CSpeedControl::OnBnClickedButtondot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	if (m_strSpeed.GetLength() <= 10)
	{
		if (m_strSpeed.Find(_T(".")) == -1)
		{
			m_EditClearButtonFlag = FALSE;
			m_strSpeed += '.';
			UpdateData(FALSE);
		}
	}
}


void CSpeedControl::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	float value= (float)_tstof(m_strSpeed);
	CString a;
	double frequence;
	if (value < 0.2)
	{
		AfxMessageBox(_T("���ٱ������0.2��"), 0, 0);
		return;
	}
	switch (g_nFlagMode)
	{
	case MODE_AUTO:
		g_fSpeedCon = value;
		pDtaCtrlDlg->m_strStatic12.Format(_T("%.2f"), g_fSpeedCon);
		pDtaCtrlDlg->m_strStatic12 += _T("m/s");
		pIntgCtrlDlg->m_strStatic12.Format(_T("%.2f"), g_fSpeedCon);
		pIntgCtrlDlg->m_strStatic12 += _T("m/s");
		//pDtaCtrlDlg->WriteDToPLC(ADDRESSD_SPEED_SETTING, g_fSpeedCon);
		UpdateData(FALSE);
		break;
	case MODE_MANU_FREQUENCE:
		g_fFrequencyCon = value;
		pIntgCtrlDlg->m_strStatic13.Format(_T("%.2f"), g_fFrequencyCon);
		pIntgCtrlDlg->m_strStatic13 += _T("Hz");
		pDtaCtrlDlg->m_strStatic13.Format(_T("%.2f"), g_fFrequencyCon);
		pDtaCtrlDlg->m_strStatic13 += _T("Hz");
		//pDtaCtrlDlg->WriteDToPLC(ADDRESSD_FREQUENCY_SETTING, g_fFrequencyCon);
		pDtaCtrlDlg->WriteToInverter(INVERTER_SET_FREQ_COMMAND, (int)(g_fFrequencyCon * 100), 2);
		UpdateData(FALSE);
		break;
	case MODE_MANU_SPEED:
		g_fSpeedCon = value;
		pDtaCtrlDlg->m_strStatic12.Format(_T("%.2f"), g_fSpeedCon);
		pDtaCtrlDlg->m_strStatic12 += _T("m/s");
		pIntgCtrlDlg->m_strStatic12.Format(_T("%.2f"), g_fSpeedCon);
		pIntgCtrlDlg->m_strStatic12 += _T("m/s");
		frequence = g_fSpeedToFrequence[(int)(g_fSpeedCon*10)-1][1];

		//pDtaCtrlDlg->WriteDToPLC(ADDRESSD_FREQUENCY_SETTING, frequence);
		pDtaCtrlDlg->WriteToInverter(INVERTER_SET_FREQ_COMMAND, (int)(frequence * 100), 2);
		UpdateData(FALSE);
		break;
	default:break;
	}
	CDialogEx::OnOK();
}


void CSpeedControl::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

void CSpeedControl::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!m_EditClearButtonFlag)
	{
		m_strSpeed.Empty();
	}
	m_EditClearButtonFlag = TRUE;
	*pResult = 0;
	UpdateData(TRUE);
	CString str;
	float sldValue = (float)m_sliderSpeed.GetPos()/100;
	str.Format(_T("%.2f"), sldValue);
	m_strSpeed = str;
	UpdateData(FALSE);
}
