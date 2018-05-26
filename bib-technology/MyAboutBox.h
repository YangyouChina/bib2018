#pragma once


// CMyAboutBox 对话框

class CMyAboutBox : public CDialogEx
{
	DECLARE_DYNAMIC(CMyAboutBox)

public:
	CMyAboutBox(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyAboutBox();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
