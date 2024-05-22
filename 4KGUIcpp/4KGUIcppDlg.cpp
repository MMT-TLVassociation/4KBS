
// 4KGUIcppDlg.cpp : 実装ファイル
//

//#include "pch.h"
#include "stdafx.h"
#include "framework.h"
#include "4KGUIcpp.h"
#include "4KGUIcppDlg.h"
#include "afxdialogex.h"
#include "BonRecTest.h"
#include <string>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_COMBO1, m_combo1);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy4KGUIcppDlg ダイアログ



CMy4KGUIcppDlg::CMy4KGUIcppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY4KGUICPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy4KGUIcppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy4KGUIcppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMy4KGUIcppDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &CMy4KGUIcppDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy4KGUIcppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy4KGUIcppDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CMy4KGUIcppDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMy4KGUIcppDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy4KGUIcppDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy4KGUIcppDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMy4KGUIcppDlg メッセージ ハンドラー

CBonRecTest pBonRecTest;
CBonRecTest pBonRecTest2;

BOOL CMy4KGUIcppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
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

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定


	// TODO: 初期化をここに追加します。
	SetDlgItemText(IDC_EDIT1, _T("4Kstream1.mmts"));
	SetDlgItemText(IDC_EDIT2, _T("4Kstream2.mmts"));
	
	//BonDriver_BDA.iniのCH000～CH018に対応。
	 // コンボボックスに項目を追加します。
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("BS朝日 4K"));//値を登録します。
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("BSテレ東 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("BS日テレ 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("NHK BS 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("BS-TBS 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("BSフジ 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("ショップチャンネル 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("4K QVC"));
	//((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("ザ・シネマ 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("NHK BS 8K"));
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_T("WOWOW 4K"));

	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(8);//=std::string chan = "8";//CH008にチューニング

	// コンボボックスに項目を追加します。
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("BS朝日 4K"));//値を登録します。
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("BSテレ東 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("BS日テレ 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("NHK BS 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("BS-TBS 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("BSフジ 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("ショップチャンネル 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("4K QVC"));
	//((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("ザ・シネマ 4K"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("NHK BS 8K"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("WOWOW 4K"));

	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(8);//=std::string chan = "8";//CH008にチューニング
	TCHAR* pEnd;
	bool used = false;

	//LPCTSTR* argv=0;
	CString argvCSb;
	CString argvCSt;
	CString argvCSc;
	std::string bon = "BonDriver_BDA.dll";


	std::string ts = "hoge.ts";
	std::string chan = "8";//CH008にチューニング

	//MFCのCStringクラスを使って,　StringをLPCTSTRに変換

	argvCSb = bon.c_str();
	LPCTSTR argv = argvCSb;

	pBonRecTest.bonDriverPath = argv;//Tuner1
	pBonRecTest2.bonDriverPath = argv;//Tuner2

	argvCSt = ts.c_str();
	argv = argvCSt;

	pBonRecTest.outputPath = argv;
	pBonRecTest2.outputPath = argv;

	argvCSc = chan.c_str();
	argv = argvCSc;


	DWORD channel = _tcstoul(argv, &pEnd, 10);

	if (channel < 10000) {
		pBonRecTest.channel = channel;
		pBonRecTest2.channel = channel;
	}
	else {
		pBonRecTest.space = channel / 10000UL;
		pBonRecTest.channel = channel % 10000UL;
	}
	used = true;

	if (!pBonRecTest.Start()) {
		return -1;
	}
	if (!pBonRecTest2.Start()) {
		return -1;
	}

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CMy4KGUIcppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMy4KGUIcppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMy4KGUIcppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy4KGUIcppDlg::OnCbnSelchangeCombo1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	
}


void CMy4KGUIcppDlg::OnBnClickedOk()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CDialogEx::OnOK();
	//pBonRecTest.StopRec();
	
}


void CMy4KGUIcppDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	//CDialogEx::OnOK();
	CButton* button = (CButton*)GetDlgItem(IDC_BUTTON2);
	pBonRecTest.StopRec();
	SetDlgItemText(IDC_BUTTON2, L"録画開始\r\n");
	button->EnableWindow(TRUE);
}

void CMy4KGUIcppDlg::OnBnClickedButton2()
{
	TCHAR* pEnd;
	CString argvCSt;
	int argvCSci;
	CString argvCSc;
	std::string chan;

	GetDlgItemText(IDC_EDIT1, argvCSt);
	LPCTSTR argv =argvCSt;
	pBonRecTest.outputPath = argv;
	argvCSci = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	argvCSc.Format(_T("%d"), argvCSci);

	argv = argvCSc;
	DWORD channel = _tcstoul(argv, &pEnd, 10);
	pBonRecTest.channel = channel;

	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CButton* button = (CButton*)GetDlgItem(IDC_BUTTON2);
	SetDlgItemText(IDC_BUTTON2, L"録画中\r\n");
	button->EnableWindow(FALSE);
	pBonRecTest.RecMain();
}


void CMy4KGUIcppDlg::OnEnChangeEdit1()
{
	// TODO: これが RICHEDIT コントロールの場合、このコントロールが
	// この通知を送信するには、CDialogEx::OnInitDialog() 関数をオーバーライドし、
	// CRichEditCtrl().SetEventMask() を関数し呼び出します。
	// OR 状態の ENM_CHANGE フラグをマスクに入れて呼び出す必要があります。

	// TODO: ここにコントロール通知ハンドラー コードを追加してください。
}


void CMy4KGUIcppDlg::OnEnChangeEdit2()
{
	// TODO: これが RICHEDIT コントロールの場合、このコントロールが
	// この通知を送信するには、CDialogEx::OnInitDialog() 関数をオーバーライドし、
	// CRichEditCtrl().SetEventMask() を関数し呼び出します。
	// OR 状態の ENM_CHANGE フラグをマスクに入れて呼び出す必要があります。

	// TODO: ここにコントロール通知ハンドラー コードを追加してください。
}


void CMy4KGUIcppDlg::OnBnClickedButton3()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	//CDialogEx::OnOK();
	CButton* button = (CButton*)GetDlgItem(IDC_BUTTON4);
	pBonRecTest2.StopRec();
	SetDlgItemText(IDC_BUTTON4, L"録画開始\r\n");
	button->EnableWindow(TRUE);
}

void CMy4KGUIcppDlg::OnBnClickedButton4()
{
	TCHAR* pEnd;
	CString argvCSt;
	int argvCSci;
	CString argvCSc;
	std::string chan;

	GetDlgItemText(IDC_EDIT2, argvCSt);
	LPCTSTR argv = argvCSt;
	pBonRecTest2.outputPath = argv;
	argvCSci = ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetCurSel();
	argvCSc.Format(_T("%d"), argvCSci);

	argv = argvCSc;
	DWORD channel = _tcstoul(argv, &pEnd, 10);
	pBonRecTest2.channel = channel;

	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CButton* button = (CButton*)GetDlgItem(IDC_BUTTON4);
	SetDlgItemText(IDC_BUTTON4, L"録画中\r\n");
	button->EnableWindow(FALSE);
	pBonRecTest2.RecMain();
}