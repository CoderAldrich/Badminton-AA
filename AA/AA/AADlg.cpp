
// AADlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AA.h"
#include "AADlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CAADlg 对话框



CAADlg::CAADlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_AA, &CAADlg::OnBnClickedAA)
	ON_BN_CLICKED(ID_CLOSE, &CAADlg::OnBnClickedClose)
END_MESSAGE_MAP()


// CAADlg 消息处理程序

BOOL CAADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	SetIcon(m_hIcon, TRUE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	// 编辑框内的值初始化为0
	CString init = "0";
	GetDlgItem(IDC_TOTAL_RSL4)->SetWindowTextA(init);
	GetDlgItem(IDC_TOTAL_RSL5)->SetWindowTextA(init);
	GetDlgItem(IDC_TOTAL_RSL6)->SetWindowTextA(init);
	GetDlgItem(IDC_TOTAL_RSL7)->SetWindowTextA(init);
	GetDlgItem(IDC_TOTAL_OTHER)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_RSL4)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_RSL5)->SetWindowTextA("7");
	GetDlgItem(IDC_PRICE_RSL6)->SetWindowTextA("6.5");
	GetDlgItem(IDC_PRICE_RSL7)->SetWindowTextA("6");
	GetDlgItem(IDC_PRICE_OTHER)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_GROUND1)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_GROUND2)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_GROUND3)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_GROUND4)->SetWindowTextA(init);
	GetDlgItem(IDC_TOTAL_MEMBERS)->SetWindowTextA(init);
	GetDlgItem(IDC_HALF)->SetWindowTextA(init);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAADlg::OnPaint()
{
	if (IsIconic())
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
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAADlg::OnBnClickedAA()
{
	CString str;
	GetDlgItem(IDC_TOTAL_RSL4)->GetWindowTextA(str);
	int rsl4 = atoi(str);
	GetDlgItem(IDC_PRICE_RSL4)->GetWindowTextA(str);
	float price_rsl4 = atof(str);

	GetDlgItem(IDC_TOTAL_RSL5)->GetWindowTextA(str);
	int rsl5 = atoi(str);
	GetDlgItem(IDC_PRICE_RSL5)->GetWindowTextA(str);
	float price_rsl5 = atof(str);

	GetDlgItem(IDC_TOTAL_RSL6)->GetWindowTextA(str);
	int rsl6 = atoi(str);
	GetDlgItem(IDC_PRICE_RSL6)->GetWindowTextA(str);
	float price_rsl6 = atof(str);

	GetDlgItem(IDC_TOTAL_RSL7)->GetWindowTextA(str);
	int rsl7 = atoi(str);
	GetDlgItem(IDC_PRICE_RSL7)->GetWindowTextA(str);
	float price_rsl7 = atof(str);

	GetDlgItem(IDC_TOTAL_OTHER)->GetWindowTextA(str);
	int other = atoi(str);
	GetDlgItem(IDC_PRICE_OTHER)->GetWindowTextA(str);
	float price_other = atof(str);

	GetDlgItem(IDC_PRICE_GROUND1)->GetWindowTextA(str);
	float ground1 = atof(str);

	GetDlgItem(IDC_PRICE_GROUND2)->GetWindowTextA(str);
	float ground2 = atof(str);

	GetDlgItem(IDC_PRICE_GROUND3)->GetWindowTextA(str);
	float ground3 = atof(str);

	GetDlgItem(IDC_PRICE_GROUND4)->GetWindowTextA(str);
	float ground4 = atof(str);

	GetDlgItem(IDC_TOTAL_MEMBERS)->GetWindowTextA(str);
	int total_members = atoi(str);

	GetDlgItem(IDC_HALF)->GetWindowTextA(str);
	int half = atoi(str);

	float total_price_ball;
	float total_price_ground;
	float total_price;
	float each_price;
	float ret_price;

	// 检查输入是否合法
	if (rsl4 < 0 || rsl5 < 0 || rsl6 < 0 || rsl7 < 0 || other < 0		||
		ground1 < 0 || ground2 < 0 || ground3 < 0 || ground4 < 0		|| total_members == 0 ||
		price_rsl4 < 0 || price_rsl5 < 0 || price_rsl6 < 0 || price_rsl7 < 0 || price_other < 0)
	{
		::MessageBox(NULL, "输入不合法！", "ERROR!", MB_OK);
	}
	else
	{
		// 球费
		total_price_ball = rsl4*price_rsl4 + rsl5*price_rsl5 + rsl6*price_rsl6 + rsl7*price_rsl7 + other*price_other;
		str.Format("%.2f", total_price_ball);
		GetDlgItem(IDC_BALL_PRICE_TOTAL)->SetWindowTextA(str);

		// 场地费
		total_price_ground = ground1 + ground2 + ground3 + ground4;
		str.Format("%.2f", total_price_ground);
		GetDlgItem(IDC_PRICE_TOTAL)->SetWindowTextA(str);

		total_price = total_price_ball + total_price_ground;
		if (half == 0)
		{
			each_price = total_price / total_members;
			str.Format("%.2f", each_price);
			GetDlgItem(IDC_EACH_PRICE)->SetWindowTextA(str);
			str.Format("%.2f", total_price);
			GetDlgItem(IDC_ALL)->SetWindowTextA(str);
			GetDlgItem(IDC_IN)->SetWindowTextA(str);
			GetDlgItem(IDC_EACH_RET)->SetWindowTextA("0");

			if (total_price != 0)
			{
				str.Empty();

				str.Append("(");

				(rsl4 == 0) ? "" : str.AppendFormat("%d*%.1f+", rsl4, price_rsl4);
				(rsl5 == 0) ? "" : str.AppendFormat("%d*%.1f+", rsl5, price_rsl5);
				(rsl6 == 0) ? "" : str.AppendFormat("%d*%.1f+", rsl6, price_rsl6);
				(rsl7 == 0) ? "" : str.AppendFormat("%d*%.1f+", rsl7, price_rsl7);
				(other == 0) ? "" : str.AppendFormat("%d*%.1f+", other, price_other);

				(ground1 == 0) ? "" : str.AppendFormat("%.1f+", ground1);
				(ground2 == 0) ? "" : str.AppendFormat("%.1f+", ground2);
				(ground3 == 0) ? "" : str.AppendFormat("%.1f+", ground3);
				(ground4 == 0) ? "" : str.AppendFormat("%.1f+", ground4);
				str = str.Left(str.GetLength() - 1);

				str.Append(")");

				str.AppendFormat("÷%d=%.2f", total_members, each_price);
				GetDlgItem(IDC_DETAIL)->SetWindowTextA(str);
			}
			else
			{
				GetDlgItem(IDC_DETAIL)->SetWindowTextA("Are U kidding me ???");
			}
		}
		else
		{
			each_price = (total_price / (total_members * 2 - half)) * 2;
			ret_price = each_price / 2;
			str.Format("%.2f", each_price);
			GetDlgItem(IDC_EACH_PRICE)->SetWindowTextA(str);
			str.Format("%.2f", total_price);
			GetDlgItem(IDC_ALL)->SetWindowTextA(str);
			str.Format("%.2f", each_price*total_members);
			GetDlgItem(IDC_IN)->SetWindowTextA(str);
			str.Format("%.2f", ret_price);
			GetDlgItem(IDC_EACH_RET)->SetWindowTextA(str);

			if (total_price != 0)
			{
				str.Empty();

				str.Append("[");
				str.Append("(");

				(rsl4 == 0) ? "" : str.AppendFormat("%d*%.1f+", rsl4, price_rsl4);
				(rsl5 == 0) ? "" : str.AppendFormat("%d*%.1f+", rsl5, price_rsl5);
				(rsl6 == 0) ? "" : str.AppendFormat("%d*%.1f+", rsl6, price_rsl6);
				(rsl7 == 0) ? "" : str.AppendFormat("%d*%.1f+", rsl7, price_rsl7);
				(other == 0) ? "" : str.AppendFormat("%d*%.1f+", other, price_other);

				(ground1 == 0) ? "" : str.AppendFormat("%.1f+", ground1);
				(ground2 == 0) ? "" : str.AppendFormat("%.1f+", ground2);
				(ground3 == 0) ? "" : str.AppendFormat("%.1f+", ground3);
				(ground4 == 0) ? "" : str.AppendFormat("%.1f+", ground4);
				str = str.Left(str.GetLength() - 1);

				str.Append(")");

				str.AppendFormat("÷(%d*2-%d)]*2=%.2f", total_members, half, each_price);
				GetDlgItem(IDC_DETAIL)->SetWindowTextA(str);
			}
			else
			{
				GetDlgItem(IDC_DETAIL)->SetWindowTextA("Are U kidding me ???");
			}
		}
	}
}


void CAADlg::OnBnClickedClose()
{
	// TODO: 在此添加控件通知处理程序代码
	// 编辑框内的值初始化为0
	CString init = "0";
	GetDlgItem(IDC_TOTAL_RSL4)->SetWindowTextA(init);
	GetDlgItem(IDC_TOTAL_RSL5)->SetWindowTextA(init);
	GetDlgItem(IDC_TOTAL_RSL6)->SetWindowTextA(init);
	GetDlgItem(IDC_TOTAL_RSL7)->SetWindowTextA(init);
	GetDlgItem(IDC_TOTAL_OTHER)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_RSL4)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_RSL5)->SetWindowTextA("7");
	GetDlgItem(IDC_PRICE_RSL6)->SetWindowTextA("6.5");
	GetDlgItem(IDC_PRICE_RSL7)->SetWindowTextA("6");
	GetDlgItem(IDC_PRICE_OTHER)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_GROUND1)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_GROUND2)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_GROUND3)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_GROUND4)->SetWindowTextA(init);
	GetDlgItem(IDC_TOTAL_MEMBERS)->SetWindowTextA(init);
	GetDlgItem(IDC_HALF)->SetWindowTextA(init);

	init.Empty();
	GetDlgItem(IDC_BALL_PRICE_TOTAL)->SetWindowTextA(init);
	GetDlgItem(IDC_PRICE_TOTAL)->SetWindowTextA(init);
	GetDlgItem(IDC_DETAIL)->SetWindowTextA(init);
	GetDlgItem(IDC_EACH_PRICE)->SetWindowTextA(init);
	GetDlgItem(IDC_EACH_RET)->SetWindowTextA(init);
	GetDlgItem(IDC_ALL)->SetWindowTextA(init);
	GetDlgItem(IDC_IN)->SetWindowTextA(init);
}
