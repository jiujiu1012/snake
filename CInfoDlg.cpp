// CInfoDlg.cpp: ʵ���ļ�

//



#include "pch.h"

#include "MFCsnack.h" 

#include "CInfoDlg.h"

#include "afxdialogex.h"





// CInfoDlg �Ի���



IMPLEMENT_DYNAMIC(CInfoDlg, CDialogEx)



CInfoDlg::CInfoDlg(CWnd* pParent /*=nullptr*/)

	: CDialogEx(IDD_Snack, pParent)

{

	m_showFont = NULL;

	str = NULL;

	//m_showFont->CreatePointFont(200, L"����");

	//str->Format(_T("sorry, your snake is dead ~ \n\n Please try again ~ "));

}



CInfoDlg::CInfoDlg(CWnd* pParent /*=nullptr*/, CFont& m_showFont, CString& str)

	: CDialogEx(IDD_Snack, pParent)

	, m_showFont(&m_showFont)

	, str(&str)

{

	//this->GetDlgItem(IDC_INFO)->SetWindowTextW(str);

	//this->GetDlgItem(IDC_INFO)->SetFont(&m_showFont);



}



CInfoDlg::~CInfoDlg()

{

}



void CInfoDlg::DoDataExchange(CDataExchange* pDX)

{

	CDialogEx::DoDataExchange(pDX);

}





BEGIN_MESSAGE_MAP(CInfoDlg, CDialogEx)

END_MESSAGE_MAP()





// CInfoDlg ��Ϣ�������