
// DlgProxy.cpp : ʵ���ļ�
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
	
	// ΪʹӦ�ó������Զ��������ڻ״̬ʱһֱ���� 
	//	���У����캯������ AfxOleLockApp��
	AfxOleLockApp();

	// ͨ��Ӧ�ó����������ָ��
	//  �����ʶԻ���  ���ô�����ڲ�ָ��
	//  ָ��Ի��򣬲����öԻ���ĺ���ָ��ָ��
	//  �ô���
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
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	//	������������ AfxOleUnlockApp��
	//  ���������������⣬�⻹���������Ի���
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CbibtechnologyDlgAutoProxy::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CbibtechnologyDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CbibtechnologyDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_Ibibtechnology ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {EC0FC0B3-4E42-4A76-A5DF-AE4216F73ACF}
static const IID IID_Ibibtechnology =
{ 0xEC0FC0B3, 0x4E42, 0x4A76, { 0xA5, 0xDF, 0xAE, 0x42, 0x16, 0xF7, 0x3A, 0xCF } };

BEGIN_INTERFACE_MAP(CbibtechnologyDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CbibtechnologyDlgAutoProxy, IID_Ibibtechnology, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ���ڴ���Ŀ�� StdAfx.h �ж���
// {F80D09B9-02CB-4991-86C5-5A91B6E64D9B}
IMPLEMENT_OLECREATE2(CbibtechnologyDlgAutoProxy, "bibtechnology.Application", 0xf80d09b9, 0x2cb, 0x4991, 0x86, 0xc5, 0x5a, 0x91, 0xb6, 0xe6, 0x4d, 0x9b)


// CbibtechnologyDlgAutoProxy ��Ϣ�������
