// MyAboutBox.cpp : 实现文件
//

#include "stdafx.h"
#include "bib-technology.h"
#include "MyAboutBox.h"
#include "afxdialogex.h"


// CMyAboutBox 对话框

IMPLEMENT_DYNAMIC(CMyAboutBox, CDialogEx)

CMyAboutBox::CMyAboutBox(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_ABOUTBOX, pParent)
{

}

CMyAboutBox::~CMyAboutBox()
{
}

void CMyAboutBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyAboutBox, CDialogEx)
END_MESSAGE_MAP()


// CMyAboutBox 消息处理程序
