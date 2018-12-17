
// AADlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AA.h"
#include "AADlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CAADlg �Ի���



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


// CAADlg ��Ϣ�������

BOOL CAADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, TRUE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	// �༭���ڵ�ֵ��ʼ��Ϊ0
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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

	// ��������Ƿ�Ϸ�
	if (rsl4 < 0 || rsl5 < 0 || rsl6 < 0 || rsl7 < 0 || other < 0		||
		ground1 < 0 || ground2 < 0 || ground3 < 0 || ground4 < 0		|| total_members == 0 ||
		price_rsl4 < 0 || price_rsl5 < 0 || price_rsl6 < 0 || price_rsl7 < 0 || price_other < 0)
	{
		::MessageBox(NULL, "���벻�Ϸ���", "ERROR!", MB_OK);
	}
	else
	{
		// ���
		total_price_ball = rsl4*price_rsl4 + rsl5*price_rsl5 + rsl6*price_rsl6 + rsl7*price_rsl7 + other*price_other;
		str.Format("%.2f", total_price_ball);
		GetDlgItem(IDC_BALL_PRICE_TOTAL)->SetWindowTextA(str);

		// ���ط�
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

				str.AppendFormat("��%d=%.2f", total_members, each_price);
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

				str.AppendFormat("��(%d*2-%d)]*2=%.2f", total_members, half, each_price);
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// �༭���ڵ�ֵ��ʼ��Ϊ0
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
