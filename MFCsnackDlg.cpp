
// MFCsnackDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCsnack.h"
#include "MFCsnackDlg.h"
#include "afxdialogex.h"
#include "Snack.h"
#include "Resource.h"
#include <iostream>

#include <random>

#include "windows.h"

#include "mmsystem.h" 

#include "CInfoDlg.h"

#pragma comment(lib, "WINMM.LIB")



#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCsnackDlg 对话框



CMFCsnackDlg::CMFCsnackDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSNACK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	pen1.CreatePen(PS_SOLID, 4, RGB(174, 221, 129));
}

void CMFCsnackDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1speed, Box);

	DDX_Control(pDX, IDC_EDIT1score, EDIT_Score);
}

BEGIN_MESSAGE_MAP(CMFCsnackDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2stop, &CMFCsnackDlg::OnBnClickedButton2stop)
	ON_BN_CLICKED(IDC_BUTTON1start, &CMFCsnackDlg::OnBnClickedButton1start)
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_STATICspeed, &CMFCsnackDlg::OnStnClickedStaticspeed)
	ON_CBN_SELCHANGE(IDC_COMBO1speed, &CMFCsnackDlg::OnCbnSelchangeCombo1speed)
	ON_WM_WINDOWPOSCHANGING()
	ON_STN_CLICKED(IDC_STATICscore, &CMFCsnackDlg::OnStnClickedStaticscore)
	ON_EN_CHANGE(IDC_EDIT1score, &CMFCsnackDlg::OnEnChangeEdit1score)
	ON_STN_CLICKED(IDC_STATICgame, &CMFCsnackDlg::OnStnClickedStaticgame)
	ON_BN_CLICKED(IDC_music, &CMFCsnackDlg::OnBnClickedmusic)
END_MESSAGE_MAP()


// CMFCsnackDlg 消息处理程序

BOOL CMFCsnackDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCsnackDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCsnackDlg::OnPaint()
                            //游戏界面初始化函数
{
	/*if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	*/
	CRect rect;

	(this->GetDlgItem(IDC_STATICgame))->GetWindowRect(&rect);  // 获取控件相对于屏幕的位置

	ScreenToClient(rect); // 转化为相对于客户区的位置

	GetDlgItem(IDC_STATICgame)->MoveWindow(rect.left, rect.top + 4, 760, 600, false);



	CDC* pClientDC = GetDC();

	(this->GetDlgItem(IDC_STATICgame))->GetWindowRect(&rect);  // 获取控件相对于屏幕的位置

	ScreenToClient(rect); // 转化为相对于客户区的位置

	CPen pen(PS_SOLID, 6, RGB(6, 128, 67)); //利用画笔工具进行界面颜色设置

	CPen pen2(PS_SOLID, 10, RGB(174, 221, 129));

	CPen* oldPen = pClientDC->SelectObject(&pen2);

	pClientDC->Rectangle(rect);

	rect.left -= 5;  //对矩形框的边缘位置间隔进行设置

	rect.right += 5;

	rect.top -= 5;

	rect.bottom += 5;

	pClientDC->SelectObject(&pen);

	pClientDC->Rectangle(rect);

	pen.DeleteObject();

	pen2.DeleteObject();

	pClientDC->DeleteDC();



	// 画刷初始化

	CBitmap bodybmp, headbmp, beanbmp, bgbmp;

	bgbmp.LoadBitmapW(IDB_BITMAP4);  //这边是用MFC里面的工具自己绘制的图标，有蛇头蛇身豆子等，然后导入资源在这里进行引用

	beanbmp.LoadBitmapW(IDB_BITMAP3);

	bodybmp.LoadBitmapW(IDB_BITMAP2);

	headbmp.LoadBitmapW(IDB_BITMAP1);

	m_brush[0].CreatePatternBrush(&bodybmp);

	m_brush[1].CreatePatternBrush(&headbmp);

	m_brush[2].CreatePatternBrush(&beanbmp);

	m_brush[3].CreatePatternBrush(&bgbmp);



	// 控件初始化，对游戏界面的相关字体字号等进行设置

	Box.SetCurSel(1);

	EDIT_Score.SetReadOnly(1);

	m_showFont1.CreatePointFont(200, L"黑体");

	GetDlgItem(IDC_EDIT1score)->SetFont(&m_showFont1);

	GetDlgItem(IDC_BUTTON1start)->SetFont(&m_showFont1);

	GetDlgItem(IDC_BUTTON2stop)->SetFont(&m_showFont1);

	m_showFont2.CreatePointFont(150, L"Consolas");

	GetDlgItem(IDC_STATICscore)->SetFont(&m_showFont2);

	GetDlgItem(IDC_STATICspeed)->SetFont(&m_showFont2);

	m_showFont3.CreatePointFont(100, L"Consolas");

	((CButton*)GetDlgItem(IDC_music))->SetFont(&m_showFont3);

	((CButton*)GetDlgItem(IDC_music))->SetCheck(BST_CHECKED);


	//此处为添加背景音乐的实现，有两种方法，第一种使用原本已有的wav音频文件进行导入，第二种直接使用wav音频的路径
	//由于一些原因，未能成功进行资源添加，所以我这里直接采用路径的方式进行添加
	PlaySound(_T("C:\\Users\\M\\Downloads\\g7h4d-ezigc.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//PlaySound(LPWSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);



	OnBnClickedButton2stop();



	SnackInit();



	CPaintDC pDC(this);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCsnackDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCsnackDlg::SnackInit()

{

	// 游戏区

	CDC* pdc = GetDlgItem(IDC_STATICgame)->GetWindowDC();



	// 棋盘初始化，利用循环的方式对每个格子进行初始化（用到了画刷）

	CBrush* pOldBrs = pdc->SelectObject(&m_brush[3]);

	CPen* pOldPen = pdc->SelectObject(&pen1);

	for (int i = 0; i < 30; i++) {

		for (int j = 0; j < 38; j++) {

			m_map[i][j].left = 0 + j * 20;

			m_map[i][j].right = 20 + j * 20;

			m_map[i][j].top = 0 + i * 20;

			m_map[i][j].bottom = 20 + i * 20;

			pdc->SelectObject(&m_brush[3]);

			pdc->Rectangle(m_map[i][j]);

			//pdc->SelectObject(&pen1);

			//pdc->Rectangle(m_map[i][j]);

		}

	}

	pdc->SelectObject(&pOldBrs);



	// 蛇初始化，包括画蛇，放置豆子，还有开始和死亡的初始值

	my_snake.init();

	score = 0;

	START = false;

	DEAD = false;

	srand((unsigned)time(NULL));

	drawSnake();

	setBean();





	// 控件初始化，设置按钮文本

	EDIT_Score.SetWindowTextW(_T("0"));

	SetDlgItemText(IDC_BUTTON1start, _T("start"));

}

void CMFCsnackDlg::OnBnClickedButton2stop()
{
	// TODO: 在此添加控件通知处理程序代码
	//游戏结束和初始化，重新开始
	gameOver();

	SnackInit();

	this->GetDlgItem(IDC_STATICgame)->SetFocus();

}


void CMFCsnackDlg::OnBnClickedButton1start()
{
	// TODO: 在此添加控件通知处理程序代码
	CString start, pause;

	start = "start";

	pause = "pause";

	if (DEAD == false) {

		if (START) {

			START = false;

			KillTimer(1);

			SetDlgItemText(IDC_BUTTON1start, start);

		}

		else {

			if (INIT) {

				INIT = false;

				SnackInit();

			}

			START = true;

			SetTimer(1, speed, NULL);

			SetDlgItemText(IDC_BUTTON1start, pause);

		}

		this->GetDlgItem(IDC_STATICgame)->SetFocus();

	}
}
void CMFCsnackDlg::OnTimer(UINT_PTR nIDEvent)

{   

	// TODO: 在此添加消息处理程序代码和/或调用默认值

	// main function about snake

	UpdateData(true);
	//如果游戏已经开始并且没有死亡，实现上下左右的方向移动
	if (START && DEAD == false) {

		switch (my_snake.direc)

		{

		case 1:MvUp(); break;

		case 2:MvDown(); break;

		case 3:MvLeft(); break;

		case 4:MvRight(); break;

		default:

			break;

		}
		//检测蛇是否存活，如果死亡将dead标志设为true，并且显示相应对话框
		if (checkLive() == false) {

			DEAD = true;

			CString str;

			str.Format(_T("sorry, your score is %d ~ \n\n Please try again ~ "), score);

			//str = TEXT("sorry, your score is " + str + " ~ \n\n Please try again~");



			/*CInfoDlg dlg(NULL, m_showFont1, str);

			CInfoDlg dlg;

			INT_PTR nres = dlg.DoModal();

			if (IDOK == nres) {

				OnBnClickedButtonStop();

			}*/


			//游戏结束以及吃豆子函数的调用
			if (MessageBox(str, TEXT("INFO"), MB_ICONINFORMATION) == IDOK) {

				OnBnClickedButton2stop();

			}

			gameOver();//判断死亡就调用gameover（）函数

		}

		eatBean();//判断存活就调用eatbean（）

		// drawSnake();

	}



	CDialogEx::OnTimer(nIDEvent);

}
//放置豆子
bool CMFCsnackDlg::setBean()

{

	srand((unsigned)time(NULL)); //获取随机数

	bool setB = false;

	bool safe = true;//安全标志，判断豆子是否放在了无效区域

	while (safe) {

		pos.x = rand() % 30;

		pos.y = rand() % 38;
		//避免放在蛇身上以及超出游戏区
		for (int i = 0; i < my_snake.len; i++) {

			if (pos.x == my_snake.body[i].x && pos.y == my_snake.body[i].y) {

				safe = false; break;

			}

		}

		if (safe) {

			setB = true;

			safe = false;

		}

		else safe = true;

	}
	//利用画刷对放置的豆子进行颜色等设计
	CDC* pdc = GetDlgItem(IDC_STATICgame)->GetWindowDC();

	CBrush* pOldBrs = pdc->SelectObject(&m_brush[2]);

	pdc->Rectangle(m_map[pos.x][pos.y]);

	pdc->SelectObject(&pen1);

	pdc->Rectangle(m_map[pos.x][pos.y]);

	pdc->SelectObject(&pOldBrs);

	pdc->DeleteDC();

	return setB;

}
//这一部分利用画刷绘制蛇
void CMFCsnackDlg::drawSnake()

{

	CDC* pdc = GetDlgItem(IDC_STATICgame)->GetWindowDC();

	CBrush* pOldBrs = pdc->SelectObject(&m_brush[0]);
	//利用循环对每个节点进行填充

	for (int i = 1; i < my_snake.len; i++) {

		pdc->SelectObject(&m_brush[0]);

		pdc->Rectangle(m_map[my_snake.body[i].x][my_snake.body[i].y]);

		pdc->SelectObject(&pen1);

		pdc->Rectangle(m_map[my_snake.body[i].x][my_snake.body[i].y]);

	}

	pdc->SelectObject(&m_brush[1]);

	pdc->Rectangle(m_map[my_snake.body[0].x][my_snake.body[0].y]);

	pdc->SelectObject(&pen1);

	pdc->Rectangle(m_map[my_snake.body[0].x][my_snake.body[0].y]);

	pdc->SelectObject(&pOldBrs);

	pdc->DeleteDC();

}

//向上移动
void CMFCsnackDlg::MvUp()
{
	CDC* pdc = GetDlgItem(IDC_STATICgame)->GetWindowDC();
	// 将最后一个恢复背景色，对将要移动的格子填充为蛇头，向下向左向右也是类似的操作，分别对蛇头和蛇尾进行一个处理
	CBrush* pOldBrs = pdc->SelectObject(&m_brush[3]);
	pdc->Rectangle(m_map[my_snake.body[my_snake.len - 1].x][my_snake.body[my_snake.len - 1].y]);
	pdc->SelectObject(&pen1);
	pdc->Rectangle(m_map[my_snake.body[my_snake.len - 1].x][my_snake.body[my_snake.len - 1].y]);
	pdc->SelectObject(pOldBrs);
	my_snake.UpMove();
	drawSnake();
}
//向下移动
void CMFCsnackDlg::MvDown()

{

	CDC* pdc = GetDlgItem(IDC_STATICgame)->GetWindowDC();

	CBrush* pOldBrs = pdc->SelectObject(&m_brush[3]);

	pdc->Rectangle(m_map[my_snake.body[my_snake.len - 1].x][my_snake.body[my_snake.len - 1].y]);

	pdc->SelectObject(&pen1);

	pdc->Rectangle(m_map[my_snake.body[my_snake.len - 1].x][my_snake.body[my_snake.len - 1].y]);

	pdc->SelectObject(pOldBrs);

	my_snake.DownMove();

	drawSnake();

}
//向左移动
void CMFCsnackDlg::MvLeft()

{

	CDC* pdc = GetDlgItem(IDC_STATICgame)->GetWindowDC();

	CBrush* pOldBrs = pdc->SelectObject(&m_brush[3]);

	pdc->Rectangle(m_map[my_snake.body[my_snake.len - 1].x][my_snake.body[my_snake.len - 1].y]);

	pdc->SelectObject(&pen1);

	pdc->Rectangle(m_map[my_snake.body[my_snake.len - 1].x][my_snake.body[my_snake.len - 1].y]);

	pdc->SelectObject(pOldBrs);

	my_snake.LeftMove();

	drawSnake();

}


//向右移动
void CMFCsnackDlg::MvRight()

{

	CDC* pdc = GetDlgItem(IDC_STATICgame)->GetWindowDC();

	CBrush* pOldBrs = pdc->SelectObject(&m_brush[3]);

	pdc->Rectangle(m_map[my_snake.body[my_snake.len - 1].x][my_snake.body[my_snake.len - 1].y]);

	pdc->SelectObject(&pen1);

	pdc->Rectangle(m_map[my_snake.body[my_snake.len - 1].x][my_snake.body[my_snake.len - 1].y]);

	pdc->SelectObject(pOldBrs);

	my_snake.RightMove();

	drawSnake();

}
//吃豆子，当蛇头的坐标和豆子的坐标相同时，可以实现吃豆子将蛇长加1，重新放置豆子，更新分数
void CMFCsnackDlg::eatBean()
{
	if (pos.x == my_snake.body[0].x && pos.y == my_snake.body[0].y) {
		my_snake.len++;
		setBean();
		score = score + (abs(pos.x - my_snake.body[0].x) + abs(pos.y - my_snake.body[0].y));
		CString str;
		str.Format(_T("%d"), score);
		EDIT_Score.SetWindowTextW(str);
	}
}


//游戏过程中蛇是否存活
bool CMFCsnackDlg::checkLive()
{
	// 判断是否出界
	if (my_snake.body[0].x < 0 || my_snake.body[0].x >= 30 || my_snake.body[0].y < 0 || my_snake.body[0].y >= 38) return false;
	// 判断是否撞到了自己
	for (int i = 1; i < my_snake.len; i++) {
		if (my_snake.body[0].x == my_snake.body[i].x && my_snake.body[0].y == my_snake.body[i].y) return false;
	}
	return true;
}


//游戏结束的实现
void CMFCsnackDlg::gameOver()

{
//killtimer标志置为1，start标志置为false
	KillTimer(1);

	START = false;

}
//控件处理
void CMFCsnackDlg::OnStnClickedStaticspeed()
{
	// TODO: 在此添加控件通知处理程序代码
}

//速度下拉框，设置初始速度
void CMFCsnackDlg::OnCbnSelchangeCombo1speed()
{
	// TODO: 在此添加控件通知处理程序代码
	//KillTimer(1);

	CString mode;

	Box.GetLBText(Box.GetCurSel(), mode);

	int tmp = 0;

	tmp = mode[0] - '0';//mode用来定义输出速度

	speed = 300 / tmp;

	SetTimer(1, speed, NULL);

	this->GetDlgItem(IDC_STATICgame)->SetFocus();
}
//获取键盘按键，WSAD分别标志为1，2，3，4，代表上下左右
BOOL CMFCsnackDlg::PreTranslateMessage(MSG* pMsg)

{

	// TODO: 在此添加专用代码和/或调用基类
	//条件：蛇处于存活状态时可进行的操作
	if (START && DEAD == false) {

		if (my_snake.direc != 2 && (pMsg->wParam == VK_UP || pMsg->wParam == 'w' || pMsg->wParam == 'W')) my_snake.direc = 1;

		else if (my_snake.direc != 1 && (pMsg->wParam == VK_DOWN || pMsg->wParam == 's' || pMsg->wParam == 'S')) my_snake.direc = 2;

		else if (my_snake.direc != 4 && (pMsg->wParam == VK_LEFT || pMsg->wParam == 'a' || pMsg->wParam == 'A')) my_snake.direc = 3;

		else if (my_snake.direc != 3 && (pMsg->wParam == VK_RIGHT || pMsg->wParam == 'd' || pMsg->wParam == 'D')) my_snake.direc = 4;

	}

	/*if (pMsg->message == WM_KEYDOWN)

	{

		if (pMsg->hwnd == GetDlgItem(IDC_EDIT_score)->m_hWnd)

		{

			return true;

		}

	}*/



	//return CDialogEx::PreTranslateMessage(pMsg);

	return FALSE;

}

void CMFCsnackDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)

{

	CDialogEx::OnWindowPosChanging(lpwndpos);



	// TODO: 在此处添加消息处理程序代码

	// 获取屏幕宽度

	int nMaxX = GetSystemMetrics(SM_CXSCREEN);

	// 获取屏幕高度

	int nMaxY = GetSystemMetrics(SM_CYSCREEN);



	// 判断窗口X坐标有无超过左边桌面。

	if (lpwndpos->x < 0)

	{

		lpwndpos->x = 0;

	}



	// 判断窗口X坐标有无超过右边桌面。

	if (lpwndpos->x + lpwndpos->cx > nMaxX)

	{

		lpwndpos->x = nMaxX - lpwndpos->cx;

	}



	// 判断窗口Y坐标有无超过顶部桌面。

	if (lpwndpos->y < 0)

	{

		lpwndpos->y = 0;

	}



	// 判断窗口Y坐标有无超过底部桌面。

	if (lpwndpos->y + lpwndpos->cy > nMaxY)

	{

		lpwndpos->y = nMaxY - lpwndpos->cy;

	}

}




void CMFCsnackDlg::OnStnClickedStaticscore()
{
	// TODO: 在此添加控件通知处理程序代码

}


void CMFCsnackDlg::OnEnChangeEdit1score()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCsnackDlg::OnStnClickedStaticgame()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCsnackDlg::OnStnClickedStaticmusic()
{
	// TODO: 在此添加控件通知处理程序代码
}



//音乐按键，获取按键状态播放音乐
void CMFCsnackDlg::OnBnClickedmusic()
{
	// TODO: 在此添加控件通知处理程序代码
	int state = ((CButton*)GetDlgItem(IDC_STATICmusic))->GetCheck();



	//PlaySound(LPWSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);


	//如果状态标志为0，不进行播放
	if (state == 0) {

		PlaySound(NULL, NULL, NULL);

		//((CButton*)GetDlgItem(IDC_Music))->SetCheck(BST_UNCHECKED);

	}
	//否则播放相关路径的音乐
	else {

		PlaySound(_T("C:\\Users\\M\\Downloads\\g7h4d-ezigc.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		//mciSendString(L"open ./4u497-jbsbf.wav alias bgm", 0, 0, 0);//打开音乐
		//mciSendString(L"open bgm repeat", 0, 0, 0);//播放音乐

		//PlaySound(LPWSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);

		//((CButton*)GetDlgItem(IDC_Music))->SetCheck(BST_CHECKED);

	}
}
