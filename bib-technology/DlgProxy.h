
// DlgProxy.h: ͷ�ļ�
//

#pragma once

class CbibtechnologyDlg;


// CbibtechnologyDlgAutoProxy ����Ŀ��

class CbibtechnologyDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CbibtechnologyDlgAutoProxy)

	CbibtechnologyDlgAutoProxy();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��

// ����
public:
	CbibtechnologyDlg* m_pDialog;

// ����
public:

// ��д
	public:
	virtual void OnFinalRelease();

// ʵ��
protected:
	virtual ~CbibtechnologyDlgAutoProxy();

	// ���ɵ���Ϣӳ�亯��

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CbibtechnologyDlgAutoProxy)

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

