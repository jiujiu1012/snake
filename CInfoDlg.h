#pragma once
// CInfoDlg �Ի���


class CInfoDlg : public CDialogEx

{

	DECLARE_DYNAMIC(CInfoDlg)



public:

	CInfoDlg(CWnd* pParent = nullptr);   // ��׼���캯��

	CInfoDlg(CWnd* pParent /*=nullptr*/, CFont& m_showFont, CString& str);

	virtual ~CInfoDlg();

	CFont* m_showFont = NULL;

	CString* str;



	// �Ի�������

#ifdef AFX_DESIGN_TIME

	enum { IDD = IDD_DIALOG1 };

#endif



protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��



	DECLARE_MESSAGE_MAP()

};