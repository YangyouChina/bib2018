// Instruction.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bib-technology.h"
#include "Instruction.h"
#include "afxdialogex.h"


// CInstruction �Ի���


BOOL CInstruction::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//((CStatic *)GetDlgItem(IDC_INSTRUCT))->SetWindowText(_T("\r\nͼƬ���ݱ�����D:\\BibTechnology\\BibPic \r\n�������ݱ�����D:\\BibTechnology\\BibData\r\n"));

	return 1;
}

IMPLEMENT_DYNAMIC(CInstruction, CDialogEx)

CInstruction::CInstruction(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CInstruction::~CInstruction()
{
}

void CInstruction::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INSTRUCT, m_Instruct);
}


BEGIN_MESSAGE_MAP(CInstruction, CDialogEx)
	ON_STN_CLICKED(IDC_INSTRUCT, &CInstruction::OnStnClickedInstruct)
END_MESSAGE_MAP()


// CInstruction ��Ϣ�������


void CInstruction::OnStnClickedInstruct()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
