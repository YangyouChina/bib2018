// Instruction.cpp : 实现文件
//

#include "stdafx.h"
#include "bib-technology.h"
#include "Instruction.h"
#include "afxdialogex.h"


// CInstruction 对话框


BOOL CInstruction::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//((CStatic *)GetDlgItem(IDC_INSTRUCT))->SetWindowText(_T("\r\n图片数据保存在D:\\BibTechnology\\BibPic \r\n曲线数据保存在D:\\BibTechnology\\BibData\r\n"));

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


// CInstruction 消息处理程序


void CInstruction::OnStnClickedInstruct()
{
	// TODO: 在此添加控件通知处理程序代码
}
