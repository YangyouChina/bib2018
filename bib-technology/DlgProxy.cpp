
// DlgProxy.cpp : 实现文件
//

#include "stdafx.h"
#include "bib-technology.h"
#include "DlgProxy.h"
#include "bib-technologyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbibtechnologyDlgAutoProxy

IMPLEMENT_DYNCREATE(CbibtechnologyDlgAutoProxy, CCmdTarget)

CbibtechnologyDlgAutoProxy::CbibtechnologyDlgAutoProxy()
{
	EnableAutomation();
	
	// 为使应用程序在自动化对象处于活动状态时一直保持 
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。  设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CbibtechnologyDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CbibtechnologyDlg)))
		{
			m_pDialog = reinterpret_cast<CbibtechnologyDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CbibtechnologyDlgAutoProxy::~CbibtechnologyDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CbibtechnologyDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CbibtechnologyDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CbibtechnologyDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_Ibibtechnology 的支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {EC0FC0B3-4E42-4A76-A5DF-AE4216F73ACF}
static const IID IID_Ibibtechnology =
{ 0xEC0FC0B3, 0x4E42, 0x4A76, { 0xA5, 0xDF, 0xAE, 0x42, 0x16, 0xF7, 0x3A, 0xCF } };

BEGIN_INTERFACE_MAP(CbibtechnologyDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CbibtechnologyDlgAutoProxy, IID_Ibibtechnology, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏在此项目的 StdAfx.h 中定义
// {F80D09B9-02CB-4991-86C5-5A91B6E64D9B}
IMPLEMENT_OLECREATE2(CbibtechnologyDlgAutoProxy, "bibtechnology.Application", 0xf80d09b9, 0x2cb, 0x4991, 0x86, 0xc5, 0x5a, 0x91, 0xb6, 0xe6, 0x4d, 0x9b)


// CbibtechnologyDlgAutoProxy 消息处理程序
