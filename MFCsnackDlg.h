
// MFCsnackDlg.h: 头文件
//

#pragma once
#include "Snack.h"


// CMFCsnackDlg 对话框
class CMFCsnackDlg : public CDialogEx
{
// 构造
public:
	CMFCsnackDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSNACK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2stop();
	afx_msg void OnBnClickedButton1start();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnCbnSelchangeCombo1speed();
	CComboBox Box;
	CEdit EDIT_Score;
	CFont m_showFont1;
	CFont m_showFont2;
	CFont m_showFont3;
	CBrush m_brush[4];
	CRect m_map[30][38];
	Point pos = { 0, 0 };
	CSnake my_snake;
	CPen pen1;

	int speed = 150; // 设置速度
	int score = 0;
	bool INIT = true;
	bool START = false;
	bool DEAD = false;
	void SnackInit();
	bool setBean();
	void drawSnake();
	void MvUp();
	void MvDown();
	void MvLeft();
	void MvRight();
	void eatBean();
	bool checkLive();
	void gameOver();



	virtual BOOL PreTranslateMessage(MSG* pMsg);

	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);

	

	afx_msg void OnStnClickedStaticspeed();

	afx_msg void OnStnClickedStaticscore();
	afx_msg void OnEnChangeEdit1score();
	afx_msg void OnStnClickedStaticgame();
	afx_msg void OnStnClickedStaticmusic();
	afx_msg void OnBnClickedmusic();
};
