// COMSETTING.cpp : 实现文件
//

#include "stdafx.h"
#include "bib-technology.h"
#include "COMSETTING.h"
#include "afxdialogex.h"
#include "bib-technologyDlg.h"
#include <Dbt.h>
#include "GLOBAL.h"

extern CDataCtrl* pDtaCtrlDlg;
int g_nFlagComDisconnect = 0;
// COMSETTING 对话框

IMPLEMENT_DYNAMIC(COMSETTING, CDialogEx)

BOOL COMSETTING::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	((CComboBox*)GetDlgItem(IDC_COMBO_BOTELV))->SetCurSel(9);
	((CComboBox*)GetDlgItem(IDC_COMBO_CHECK))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO_DATA))->SetCurSel(3);
	((CComboBox*)GetDlgItem(IDC_COMBO_STOP))->SetCurSel(0);

	((CComboBox*)GetDlgItem(IDC_COMBO_BOTELV2))->SetCurSel(2);
	((CComboBox*)GetDlgItem(IDC_COMBO_CHECK2))->SetCurSel(2);
	((CComboBox*)GetDlgItem(IDC_COMBO_DATA2))->SetCurSel(2);
	((CComboBox*)GetDlgItem(IDC_COMBO_STOP2))->SetCurSel(0);
	if (!pDtaCtrlDlg->m_cComm.get_PortOpen())
		SetDlgItemText(IDOK, _T("打开串口"));
	else
	{
		SetDlgItemText(IDOK, _T("关闭串口"));
		m_combo_botelv.EnableWindow(FALSE);
		m_combo_com.EnableWindow(FALSE);
		m_combo_check.EnableWindow(FALSE);
		m_combo_data.EnableWindow(FALSE);
		m_combo_stop.EnableWindow(FALSE);
	}
	if (!pDtaCtrlDlg->m_cComm2.get_PortOpen())
		SetDlgItemText(IDC_BUTTON1, _T("打开串口"));
	else
	{
		SetDlgItemText(IDC_BUTTON1, _T("关闭串口"));
		m_combo_botelv2.EnableWindow(FALSE);
		m_combo_com2.EnableWindow(FALSE);
		m_combo_check2.EnableWindow(FALSE);
		m_combo_data2.EnableWindow(FALSE);
		m_combo_stop2.EnableWindow(FALSE);
	}
	MYUART_GetComNum();
	UpdateData(FALSE);
	SetTimer(10, 5000, 0);
	return 1;
}

COMSETTING::COMSETTING(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COM_SET, pParent)
{

	EnableAutomation();

}

COMSETTING::~COMSETTING()
{
}

void COMSETTING::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void COMSETTING::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COM, m_combo_com);
	DDX_Control(pDX, IDC_COMBO_BOTELV, m_combo_botelv);
	DDX_Control(pDX, IDC_COMBO_DATA, m_combo_data);
	DDX_Control(pDX, IDC_COMBO_STOP, m_combo_stop);
	DDX_Control(pDX, IDC_COMBO_CHECK, m_combo_check);
	DDX_Control(pDX, IDC_COMBO_COM2, m_combo_com2);
	DDX_Control(pDX, IDC_COMBO_BOTELV2, m_combo_botelv2);
	DDX_Control(pDX, IDC_COMBO_DATA2, m_combo_data2);
	DDX_Control(pDX, IDC_COMBO_STOP2, m_combo_stop2);
	DDX_Control(pDX, IDC_COMBO_CHECK2, m_combo_check2);
}


BEGIN_MESSAGE_MAP(COMSETTING, CDialogEx)
	ON_BN_CLICKED(IDOK, &COMSETTING::OnBnClickedOk)
	ON_WM_DEVICECHANGE()
	ON_BN_CLICKED(IDC_BUTTON1, &COMSETTING::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &COMSETTING::OnBnClickedCancel)
	ON_STN_CLICKED(IDC_STATIC_COM2, &COMSETTING::OnStnClickedStaticCom2)
	ON_WM_TIMER()
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COMSETTING, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IOMSETTING 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {18484DAC-CA0A-44EA-B71B-5968923276EB}
static const IID IID_ICOMSETTING =
{ 0x18484DAC, 0xCA0A, 0x44EA, { 0xB7, 0x1B, 0x59, 0x68, 0x92, 0x32, 0x76, 0xEB } };

BEGIN_INTERFACE_MAP(COMSETTING, CDialogEx)
	INTERFACE_PART(COMSETTING, IID_ICOMSETTING, Dispatch)
END_INTERFACE_MAP()


// COMSETTING 消息处理程序
void COMSETTING::MYUART_GetComNum(void)
{
	long lReg;
	HKEY hKey;
	DWORD MaxValueLength;
	DWORD dwValueNumber;

	lReg = RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM"),
		0, KEY_QUERY_VALUE, &hKey);


	if (lReg != ERROR_SUCCESS) //成功时返回ERROR_SUCCESS，
	{
		//AfxMessageBox(_T("未自动找到串口!"), MB_ICONSTOP, 0);
		return;
	}


	lReg = RegQueryInfoKey(hKey, NULL, NULL, NULL, NULL, NULL, NULL,
		&dwValueNumber, &MaxValueLength, NULL, NULL, NULL);


	if (lReg != ERROR_SUCCESS) //没有成功
	{
		//AfxMessageBox(_T("未自动找到串口!"), MB_ICONSTOP, 0);
		return;
	}


	TCHAR *pValueName, *pCOMNumber;
	DWORD cchValueName, dwValueSize = 10;
	for (int i = 0; i < dwValueNumber; i++)
	{
		cchValueName = MaxValueLength + 1;
		dwValueSize = 10;
		pValueName = (TCHAR*)VirtualAlloc(NULL, cchValueName, MEM_COMMIT, PAGE_READWRITE);
		lReg = RegEnumValue(hKey, i, pValueName,
			&cchValueName, NULL, NULL, NULL, NULL);


		if ((lReg != ERROR_SUCCESS) && (lReg != ERROR_NO_MORE_ITEMS))
		{
			//AfxMessageBox(_T("未自动找到串口!"), MB_ICONSTOP, 0);
			return;
		}


		pCOMNumber = (TCHAR*)VirtualAlloc(NULL, 6, MEM_COMMIT, PAGE_READWRITE);
		lReg = RegQueryValueEx(hKey, pValueName, NULL,
			NULL, (LPBYTE)pCOMNumber, &dwValueSize);


		if (lReg != ERROR_SUCCESS)
		{
			//AfxMessageBox(_T("未自动找到串口!"), MB_ICONSTOP, 0);
			return;
		}
		CString str(pCOMNumber);
		CString str1;
		CComboBox* CB = ((CComboBox*)GetDlgItem(IDC_COMBO_COM));
		CComboBox* CB2 = ((CComboBox*)GetDlgItem(IDC_COMBO_COM2));
		int j;
		for (j = 0; j != CB->GetCount(); j++)
		{
			CB->GetLBText(j, str1);
			if (str.Compare(str1)==0)
			{
				break;
			}
		}
		if (j == CB->GetCount())
		{
			CB->AddString(str);
			CB2->AddString(str);
		}
		VirtualFree(pValueName, 0, MEM_RELEASE);
		VirtualFree(pCOMNumber, 0, MEM_RELEASE);
	}
}

void COMSETTING::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
	static int i = 0;
	if (nIDEvent == 10 && g_nFlagComDisconnect)
	{
		if (i == 30)
		{
			i = 0;
			g_nFlagComDisconnect = 0;
			return;
		}
		i++;
		if (g_nFlagComDisconnect == 1)
		{
			
				pDtaCtrlDlg->m_cComm.put_CommPort(g_nCom1);   //选择COM端口
				pDtaCtrlDlg->m_cComm.put_InputMode(1);   //输入方式为二进制方式
				pDtaCtrlDlg->m_cComm.put_InBufferSize(1024); //设置输入缓冲区
				pDtaCtrlDlg->m_cComm.put_OutBufferSize(1024); //设置输出缓冲区
				CString Combo_BOTELV, Combo_JIAOYANWEI, Combo_SHUJUWEI, Combo_TINGZHIWEI;
				GetDlgItemText(IDC_COMBO_BOTELV, Combo_BOTELV);
				GetDlgItemText(IDC_COMBO_CHECK, Combo_JIAOYANWEI);
				GetDlgItemText(IDC_COMBO_DATA, Combo_SHUJUWEI);
				GetDlgItemText(IDC_COMBO_STOP, Combo_TINGZHIWEI);
				if (Combo_JIAOYANWEI == "无")
					Combo_JIAOYANWEI = "n";
				else if (Combo_JIAOYANWEI == "奇校验")
					Combo_JIAOYANWEI = "o";
				else
					Combo_JIAOYANWEI = "e";
				CString str = Combo_BOTELV + ',' + Combo_JIAOYANWEI + ',' \
					+ Combo_SHUJUWEI + ',' + Combo_TINGZHIWEI;
				pDtaCtrlDlg->m_cComm.put_Settings(str);//配置波特率，校验位，数据位，停止位
				pDtaCtrlDlg->m_cComm.put_PortOpen(TRUE); //打开串口
				pDtaCtrlDlg->m_cComm.put_RThreshold(1); //每当接收缓冲区有个字符则接收串口数据
				pDtaCtrlDlg->m_cComm.put_InputLen(0); //设置当前缓冲区长度为0
				pDtaCtrlDlg->m_cComm.get_Input(); //预读缓冲区以清除残留数据
				if (pDtaCtrlDlg->m_cComm.get_PortOpen())
				{
					i = 0;
					g_nFlagComDisconnect = 0;
					g_bComOpen1 = 1;
					SetDlgItemText(IDOK, _T("关闭串口"));
					m_combo_botelv.EnableWindow(FALSE);
					m_combo_com.EnableWindow(FALSE);
					m_combo_check.EnableWindow(FALSE);
					m_combo_data.EnableWindow(FALSE);
					m_combo_stop.EnableWindow(FALSE);
				}
		}
		else if (g_nFlagComDisconnect == 2)
		{
			
			pDtaCtrlDlg->m_cComm2.put_CommPort(g_nCom2);   //选择COM端口
			pDtaCtrlDlg->m_cComm2.put_InputMode(1);   //输入方式为二进制方式
			pDtaCtrlDlg->m_cComm2.put_InBufferSize(1024); //设置输入缓冲区
			pDtaCtrlDlg->m_cComm2.put_OutBufferSize(1024); //设置输出缓冲区
			CString Combo_BOTELV, Combo_JIAOYANWEI, Combo_SHUJUWEI, Combo_TINGZHIWEI;
			GetDlgItemText(IDC_COMBO_BOTELV2, Combo_BOTELV);
			GetDlgItemText(IDC_COMBO_CHECK2, Combo_JIAOYANWEI);
			GetDlgItemText(IDC_COMBO_DATA2, Combo_SHUJUWEI);
			GetDlgItemText(IDC_COMBO_STOP2, Combo_TINGZHIWEI);
			if (Combo_JIAOYANWEI == "无")
				Combo_JIAOYANWEI = "n";
			else if (Combo_JIAOYANWEI == "奇校验")
				Combo_JIAOYANWEI = "o";
			else
				Combo_JIAOYANWEI = "e";
			CString str = Combo_BOTELV + ',' + Combo_JIAOYANWEI + ',' \
				+ Combo_SHUJUWEI + ',' + Combo_TINGZHIWEI;
			pDtaCtrlDlg->m_cComm2.put_Settings(str);//配置波特率，校验位，数据位，停止位
			pDtaCtrlDlg->m_cComm2.put_PortOpen(TRUE); //打开串口
			pDtaCtrlDlg->m_cComm2.put_RThreshold(1); //每当接收缓冲区有个字符则接收串口数据
			pDtaCtrlDlg->m_cComm2.put_InputLen(0); //设置当前缓冲区长度为0
			pDtaCtrlDlg->m_cComm2.get_Input(); //预读缓冲区以清除残留数据
			if (pDtaCtrlDlg->m_cComm2.get_PortOpen())
			{
				i = 0;
				g_nFlagComDisconnect = 0;
				g_bComOpen2 = 1;
				SetDlgItemText(IDC_BUTTON1, _T("关闭串口"));
				m_combo_botelv2.EnableWindow(FALSE);
				m_combo_com2.EnableWindow(FALSE);
				m_combo_check2.EnableWindow(FALSE);
				m_combo_data2.EnableWindow(FALSE);
				m_combo_stop2.EnableWindow(FALSE);
			}
		}
	}
}

void COMSETTING::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!pDtaCtrlDlg->m_cComm.get_PortOpen())
	{
		CString m_Combo_COM;
		GetDlgItemText(IDC_COMBO_COM, m_Combo_COM);
		m_Combo_COM = m_Combo_COM.Right(1);
		g_nCom1 = atoi((LPSTR)(LPCTSTR)m_Combo_COM);
		pDtaCtrlDlg->m_cComm.put_CommPort(g_nCom1);   //选择COM端口
		pDtaCtrlDlg->m_cComm.put_InputMode(1);   //输入方式为二进制方式
		pDtaCtrlDlg->m_cComm.put_InBufferSize(1024); //设置输入缓冲区
		pDtaCtrlDlg->m_cComm.put_OutBufferSize(1024); //设置输出缓冲区
		CString Combo_BOTELV, Combo_JIAOYANWEI, Combo_SHUJUWEI, Combo_TINGZHIWEI;
		GetDlgItemText(IDC_COMBO_BOTELV, Combo_BOTELV);
		GetDlgItemText(IDC_COMBO_CHECK, Combo_JIAOYANWEI);
		GetDlgItemText(IDC_COMBO_DATA, Combo_SHUJUWEI);
		GetDlgItemText(IDC_COMBO_STOP, Combo_TINGZHIWEI);
		if (Combo_JIAOYANWEI == "无")
			Combo_JIAOYANWEI = "n";
		else if (Combo_JIAOYANWEI == "奇校验")
			Combo_JIAOYANWEI = "o";
		else
			Combo_JIAOYANWEI = "e";
		CString str = Combo_BOTELV + ',' + Combo_JIAOYANWEI + ',' \
						+ Combo_SHUJUWEI + ',' + Combo_TINGZHIWEI;
		pDtaCtrlDlg->m_cComm.put_Settings(str);//配置波特率，校验位，数据位，停止位
		pDtaCtrlDlg->m_cComm.put_PortOpen(TRUE); //打开串口
		pDtaCtrlDlg->m_cComm.put_RThreshold(1); //每当接收缓冲区有个字符则接收串口数据
		pDtaCtrlDlg->m_cComm.put_InputLen(0); //设置当前缓冲区长度为0
		pDtaCtrlDlg->m_cComm.get_Input(); //预读缓冲区以清除残留数据
		if (pDtaCtrlDlg->m_cComm.get_PortOpen())
		{
			g_bComOpen1 = 1;
			g_strComNumber1 = _T("COM") + m_Combo_COM;
			SetDlgItemText(IDOK, _T("关闭串口"));
			m_combo_botelv.EnableWindow(FALSE);
			m_combo_com.EnableWindow(FALSE);
			m_combo_check.EnableWindow(FALSE);
			m_combo_data.EnableWindow(FALSE);
			m_combo_stop.EnableWindow(FALSE);
		}
		else
		{
			AfxMessageBox(_T("打开端口失败!"), MB_ICONSTOP, 0);
		}
	}
	else
	{
		g_bComOpen1 = 0;
		g_strComNumber1 = _T("");
		pDtaCtrlDlg->m_cComm.put_PortOpen(FALSE);
		SetDlgItemText(IDOK, _T("打开串口"));
		m_combo_botelv.EnableWindow(TRUE);
		m_combo_com.EnableWindow(TRUE);
		m_combo_check.EnableWindow(TRUE);
		m_combo_data.EnableWindow(TRUE);
		m_combo_stop.EnableWindow(TRUE);
	}
}

BOOL COMSETTING::OnDeviceChange(UINT nEventType, DWORD dwData)
{
	CComboBox* CB = ((CComboBox*)GetDlgItem(IDC_COMBO_COM));
	CComboBox* CB2 = ((CComboBox*)GetDlgItem(IDC_COMBO_COM2));
	CB->ResetContent();
	CB2->ResetContent();
	MYUART_GetComNum();
	UpdateData(FALSE);
	if (nEventType == DBT_DEVICEREMOVECOMPLETE)
	{
		if (CB->FindStringExact(0, g_strComNumber1) == CB_ERR && g_bComOpen1==1)
		{
			g_bComOpen1 = 0;
			g_nFlagComDisconnect = 1;
			g_strComNumber1 = _T("");
			pDtaCtrlDlg->m_cComm.put_PortOpen(FALSE);
			SetDlgItemText(IDOK, _T("打开串口"));
			m_combo_botelv.EnableWindow(TRUE);
			m_combo_com.EnableWindow(TRUE);
			m_combo_check.EnableWindow(TRUE);
			m_combo_data.EnableWindow(TRUE);
			m_combo_stop.EnableWindow(TRUE);
			//MessageBox(_T("控制器串口断开,请检查并重新连接!"));
		}
		if (CB->FindStringExact(0, g_strComNumber2) == CB_ERR && g_bComOpen2==1)
		{
			g_nFlagComDisconnect = 2;
			g_bComOpen2 = 0;
			g_strComNumber2 = _T("");
			pDtaCtrlDlg->m_cComm2.put_PortOpen(FALSE);
			SetDlgItemText(IDC_BUTTON1, _T("打开串口"));
			m_combo_botelv2.EnableWindow(TRUE);
			m_combo_com2.EnableWindow(TRUE);
			m_combo_check2.EnableWindow(TRUE);
			m_combo_data2.EnableWindow(TRUE);
			m_combo_stop2.EnableWindow(TRUE);
			//MessageBox(_T("PLC串口断开,请检查并重新连接!"));
		}
	}
	return 0;
}

void COMSETTING::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!pDtaCtrlDlg->m_cComm2.get_PortOpen())
	{
		CString m_Combo_COM;
		GetDlgItemText(IDC_COMBO_COM2, m_Combo_COM);
		m_Combo_COM = m_Combo_COM.Right(1);
		g_nCom2 = atoi((LPSTR)(LPCTSTR)m_Combo_COM);
		pDtaCtrlDlg->m_cComm2.put_CommPort(g_nCom2);   //选择COM端口
		pDtaCtrlDlg->m_cComm2.put_InputMode(1);   //输入方式为二进制方式
		pDtaCtrlDlg->m_cComm2.put_InBufferSize(1024); //设置输入缓冲区
		pDtaCtrlDlg->m_cComm2.put_OutBufferSize(1024); //设置输出缓冲区
		CString Combo_BOTELV, Combo_JIAOYANWEI, Combo_SHUJUWEI, Combo_TINGZHIWEI;
		GetDlgItemText(IDC_COMBO_BOTELV2, Combo_BOTELV);
		GetDlgItemText(IDC_COMBO_CHECK2, Combo_JIAOYANWEI);
		GetDlgItemText(IDC_COMBO_DATA2, Combo_SHUJUWEI);
		GetDlgItemText(IDC_COMBO_STOP2, Combo_TINGZHIWEI);
		if (Combo_JIAOYANWEI == "无")
			Combo_JIAOYANWEI = "n";
		else if (Combo_JIAOYANWEI == "奇校验")
			Combo_JIAOYANWEI = "o";
		else
			Combo_JIAOYANWEI = "e";
		CString str = Combo_BOTELV + ',' + Combo_JIAOYANWEI + ',' \
			+ Combo_SHUJUWEI + ',' + Combo_TINGZHIWEI;
		pDtaCtrlDlg->m_cComm2.put_Settings(str);//配置波特率，校验位，数据位，停止位
		pDtaCtrlDlg->m_cComm2.put_PortOpen(TRUE); //打开串口
		pDtaCtrlDlg->m_cComm2.put_RThreshold(1); //每当接收缓冲区有个字符则接收串口数据
		pDtaCtrlDlg->m_cComm2.put_InputLen(0); //设置当前缓冲区长度为0
		pDtaCtrlDlg->m_cComm2.get_Input(); //预读缓冲区以清除残留数据
		if (pDtaCtrlDlg->m_cComm2.get_PortOpen())
		{
			g_bComOpen2 = 1;
			g_strComNumber2 = _T("COM") + m_Combo_COM;
			SetDlgItemText(IDC_BUTTON1, _T("关闭串口"));
			m_combo_botelv2.EnableWindow(FALSE);
			m_combo_com2.EnableWindow(FALSE);
			m_combo_check2.EnableWindow(FALSE);
			m_combo_data2.EnableWindow(FALSE);
			m_combo_stop2.EnableWindow(FALSE);
		}
		else
		{
			AfxMessageBox(_T("打开端口失败!"), MB_ICONSTOP, 0);
		}
	}
	else
	{
		g_bComOpen2 = 0;
		g_strComNumber2 = _T("");;
		pDtaCtrlDlg->m_cComm2.put_PortOpen(FALSE);
		SetDlgItemText(IDC_BUTTON1, _T("打开串口"));
		m_combo_botelv2.EnableWindow(TRUE);
		m_combo_com2.EnableWindow(TRUE);
		m_combo_check2.EnableWindow(TRUE);
		m_combo_data2.EnableWindow(TRUE);
		m_combo_stop2.EnableWindow(TRUE);
	}
}


void COMSETTING::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(false);
	//CDialogEx::OnCancel();
}


void COMSETTING::OnStnClickedStaticCom2()
{
	// TODO: 在此添加控件通知处理程序代码
}
