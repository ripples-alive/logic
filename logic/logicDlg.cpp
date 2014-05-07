
// logicDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "logic.h"
#include "logicDlg.h"
#include "afxdialogex.h"
#include "logicCalc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ClogicDlg 对话框




ClogicDlg::ClogicDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ClogicDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ClogicDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT1, InputFrame);
    DDX_Control(pDX, IDC_EDIT2, TypeFrame);
    DDX_Control(pDX, IDC_EDIT3, PDNFFrame);
    DDX_Control(pDX, IDC_EDIT4, PCNFFrame);
    DDX_Control(pDX, IDC_BUTTON2, ResetButton);
    DDX_Control(pDX, IDOK, CalcButton);
    DDX_Control(pDX, IDC_BUTTON1, WatchButton);
    DDX_Control(pDX, IDC_EDIT5, ConvertFrame);
    DDX_Control(pDX, IDC_RICHEDIT21, TruthTableFrame);
    DDX_Control(pDX, IDC_COPY_TYPE, CopyType);
    //  DDX_Control(pDX, IDC_COPY_PDNF, COPY_PDNF);
    DDX_Control(pDX, IDC_COPY_PDNF, CopyPDNF);
    DDX_Control(pDX, IDC_COPY_PCNF, CopyPCNF);
    DDX_Control(pDX, IDC_COPY_CONVERT, CopyConvert);
    DDX_Control(pDX, IDC_COPY_TRUTH_TABLE, CopyTruthTable);
}

BEGIN_MESSAGE_MAP(ClogicDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &ClogicDlg::OnBnClickedOk)
//    ON_WM_CHAR()
ON_EN_UPDATE(IDC_EDIT1, &ClogicDlg::OnEnUpdateEdit1)
ON_BN_CLICKED(IDC_BUTTON2, &ClogicDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON1, &ClogicDlg::OnBnClickedButton1)
ON_STN_CLICKED(IDC_COPY_TYPE, &ClogicDlg::OnStnClickedCopyType)
ON_STN_CLICKED(IDC_COPY_PDNF, &ClogicDlg::OnStnClickedCopyPdnf)
ON_STN_CLICKED(IDC_COPY_PCNF, &ClogicDlg::OnStnClickedCopyPcnf)
ON_STN_CLICKED(IDC_COPY_CONVERT, &ClogicDlg::OnStnClickedCopyConvert)
ON_STN_CLICKED(IDC_COPY_TRUTH_TABLE, &ClogicDlg::OnStnClickedCopyTruthTable)
END_MESSAGE_MAP()


// ClogicDlg 消息处理程序

BOOL ClogicDlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
    LOGFONT lf;
    CopyType.GetFont()->GetLogFont(&lf);
    lf.lfUnderline = true;
    CFont *pFont = new CFont();
    pFont->CreateFontIndirect(&lf);
    CopyType.SetFont(pFont);
    CopyPDNF.SetFont(pFont);
    CopyPCNF.SetFont(pFont);
    CopyConvert.SetFont(pFont);
    CopyTruthTable.SetFont(pFont);

    MessageBox(CString("为方便输入，输入时，可用：\r\n ") + SIGN_INPUT_NEGATIVE + _T("   代替  ") + SIGN_NEGATIVE + 
        _T("\r\n ") + SIGN_INPUT_CONJUNCTION + _T("  代替  ") + SIGN_CONJUNCTION +
        _T("\r\n ") + SIGN_INPUT_DISJUNCTION + _T("   代替  ") + SIGN_DISJUNCTION +
        _T("\r\n ") + SIGN_INPUT_INCLUSION + _T("  代替  ") + SIGN_INCLUSION +
        _T("\r\n ") + SIGN_INPUT_EQUIVALENCE + _T("  代替  ") + SIGN_EQUIVALENCE + '(' + SIGN_EQUIVALENCE_SINGLE + ')', 
        _T("Important Notification"), MB_ICONEXCLAMATION);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void ClogicDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ClogicDlg::OnPaint()
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
HCURSOR ClogicDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ShowTruthTable(const int deep, const int index, CString &sTruthTable, int &varCnt, CString &sShow, const CString &sBlankLine, int columeWidth[])
{
    if (deep == varCnt)
    {
        sShow += _T("\r\n");
        for (int j = 0; j <= varCnt; j++)
        {
            sShow += ' ';
            int &curWidth = columeWidth[j];
            for (int i = 0; i < (curWidth >> 1); i++)
            {
                sShow += ' ';
            }
            sShow += (j == varCnt) ? sTruthTable[index] : (TCHAR)('0' + ((index >> (varCnt - j - 1)) & 1));
            for (int i = 0; i < ((curWidth - 1) >> 1); i++)
            {
                sShow += ' ';
            }
        }
        sShow += _T(" \r\n") + sBlankLine;
        return;
    }

    ShowTruthTable(deep + 1, index << 1, sTruthTable, varCnt, sShow, sBlankLine, columeWidth);
    ShowTruthTable(deep + 1, index << 1 | 1, sTruthTable, varCnt, sShow, sBlankLine, columeWidth);
}

void ClogicDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString inputString;
	InputFrame.GetWindowTextW(inputString);

    CString varName[MAXCONTENT];
    CString sTruthTable;
    int varCnt;
    CString sConvertFormula;
    if (!CalcTruthTable(inputString, sTruthTable, varCnt, varName, sConvertFormula))
    {
        MessageBox(_T("Input formula is invalid."));
        return;
    }
    
    ConvertFrame.SetWindowTextW(sConvertFormula);
    
    CString sType;
    TypeFrame.SetWindowTextW(JudgeType(sTruthTable));
    
    CString sPDNF, sPCNF;
    JudgePDNFAndPCNF(sTruthTable, sPDNF, sPCNF);
    PDNFFrame.SetWindowTextW(sPDNF);
    PCNFFrame.SetWindowTextW(sPCNF);
    
    if (varCnt > MAX_ALLOW_VARIABLE)
    {
        TruthTableFrame.SetWindowTextW(_T("Too many variables."));
    }
    else
    {
        CHARFORMAT cf;
        ZeroMemory(&cf, sizeof(CHARFORMAT));
        cf.cbSize = sizeof(CHARFORMAT);
        cf.dwMask = CFM_BOLD | CFM_COLOR | CFM_FACE | CFM_ITALIC | CFM_SIZE | CFM_UNDERLINE;
        cf.dwEffects = 0;
        cf.yHeight = 15*15;//文字高度
        cf.crTextColor = RGB(0, 0, 0); //文字颜色
        wcscpy_s(cf.szFaceName ,_T("楷体"));//设置字体
        TruthTableFrame.SetDefaultCharFormat(cf);
    
        CString sShow("");
        int columeWidth[MAXCONTENT + 1];
        int lineWidth = 0;
        for (int i = 0; i < varCnt; i++)
        {
            sShow += _T("  ") + varName[i] + ' ';
            columeWidth[i] = varName[i].GetLength() + 2;
            lineWidth += columeWidth[i] + 1;
        }
        sShow += _T("  ") + inputString + _T("  ");
        columeWidth[varCnt] = inputString.GetLength() + 2;
        lineWidth += columeWidth[varCnt] + 2;
        sShow = CString(' ', lineWidth) + _T("\r\n") + sShow + _T("\r\n") + CString(' ', lineWidth);
        ShowTruthTable(0, 0, sTruthTable, varCnt, sShow, CString(' ', lineWidth), columeWidth);
        TruthTableFrame.SetWindowTextW(sShow);
    
        CHARFORMAT2 cf2; //声明为CHARFORMAT2结构，详细见MSDN
        ZeroMemory(&cf2, sizeof(CHARFORMAT2));
        cf2.cbSize = sizeof(CHARFORMAT2);
        cf2.dwMask = CFM_BACKCOLOR;
        cf2.crBackColor = RGB(155, 174, 175);
        TruthTableFrame.SetSel(TruthTableFrame.LineIndex(1), TruthTableFrame.LineIndex(1) + TruthTableFrame.LineLength(1)); //设置处理区域
        TruthTableFrame.SendMessage(EM_SETCHARFORMAT,SCF_SELECTION,(LPARAM)&cf2);

        if (varCnt > MAX_ALLOW_TRUTH_TABLE)
        {
            //TruthTableFrame.SetSel(TruthTableFrame.LineIndex(0), TruthTableFrame.LineIndex(0) + TruthTableFrame.LineLength(0)); //设置处理区域
            //TruthTableFrame.SendMessage(EM_SETCHARFORMAT,SCF_SELECTION,(LPARAM)&cf2);
            cf2.crBackColor = RGB(210, 209, 186);
            TruthTableFrame.SetSel(TruthTableFrame.LineIndex(2), TruthTableFrame.GetTextLength()); //设置处理区域
            TruthTableFrame.SendMessage(EM_SETCHARFORMAT,SCF_SELECTION,(LPARAM)&cf2);
        }
        else
        {
            for (int i = 0; i <= (1 << varCnt << 1) + 2; i ++)
            {
                if ((i > 1) && ((i & 1) == 1))
                {
                    cf2.crBackColor = RGB(210, 209, 186);
                    TruthTableFrame.SetSel(TruthTableFrame.LineIndex(i), TruthTableFrame.LineIndex(i) + TruthTableFrame.LineLength(i)); //设置处理区域
                    TruthTableFrame.SendMessage(EM_SETCHARFORMAT,SCF_SELECTION,(LPARAM)&cf2);
                }
        
                int pos = 0;
                for (int j = 0; j <= varCnt + 1; j++)
                {
                    cf2.crBackColor = RGB(0, 0, 0);
                    TruthTableFrame.SetSel(TruthTableFrame.LineIndex(i) + pos, TruthTableFrame.LineIndex(i) + pos + 1); //设置处理区域
                    TruthTableFrame.SendMessage(EM_SETCHARFORMAT,SCF_SELECTION,(LPARAM)&cf2);
                    pos += columeWidth[j] + 1;
                    cf.yHeight = 15;//文字高度
                    TruthTableFrame.SetSelectionCharFormat(cf);
                }

                if ((i & 1) == 0)
                {
                    PARAFORMAT2 pf2;
                    pf2.cbSize = sizeof(PARAFORMAT2);
                    pf2.dwMask = PFM_LINESPACING | PFM_SPACEAFTER;
                    pf2.dyLineSpacing = 15;
                    pf2.bLineSpacingRule = 4;
                    TruthTableFrame.SetParaFormat(pf2);

                    cf2.crBackColor = RGB(0, 0, 0);
                    TruthTableFrame.SetSel(TruthTableFrame.LineIndex(i), TruthTableFrame.LineIndex(i) + TruthTableFrame.LineLength(i)); //设置处理区域
                    TruthTableFrame.SendMessage(EM_SETCHARFORMAT,SCF_SELECTION,(LPARAM)&cf2);
                }
            }
        }
        
        cf.dwMask = CFM_FACE;
        wcscpy_s(cf.szFaceName ,_T("宋体"));//设置字体
        TruthTableFrame.SetSel(0, -1);
        TruthTableFrame.SetSelectionCharFormat(cf);
    }
    
	//CDialogEx::OnOK();
}


//void ClogicDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//    MessageBox(_T("Hello!"));
//    // TODO: 在此添加消息处理程序代码和/或调用默认值
//    if (((nChar >= '0') && (nChar <= '9')) || 
//        ((nChar >= 'a') && (nChar <= 'z')) || 
//        ((nChar >= 'A') && (nChar <= 'Z')) || 
//        (nChar == VK_BACK) || (nChar == VK_DELETE))
//    {
//        CDialogEx::OnChar(nChar, nRepCnt, nFlags);
//    }
//    //CDialogEx::OnChar(nChar, nRepCnt, nFlags);
//}


void ClogicDlg::OnEnUpdateEdit1()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialogEx::OnInitDialog()
    // 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
    // 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。

    // TODO:  在此添加控件通知处理程序代码
    DWORD pos = InputFrame.GetSel();
    CString inputString;
    InputFrame.GetWindowTextW(inputString);

    //替换各种运算符
    inputString.Replace(SIGN_INPUT_NEGATIVE, SIGN_NEGATIVE);
    inputString.Replace(SIGN_INPUT_CONJUNCTION, SIGN_CONJUNCTION);
    inputString.Replace(SIGN_INPUT_DISJUNCTION, SIGN_DISJUNCTION);
    inputString.Replace(SIGN_INPUT_INCLUSION, SIGN_INCLUSION);
    inputString.Replace(SIGN_INPUT_EQUIVALENCE, SIGN_EQUIVALENCE);
    //将输入字符串中的全角运算符替换成半角运算符
    inputString.Replace(SIGN_FULL_LEFT_PARENTHESIS, SIGN_LEFT_PARENTHESIS);
    inputString.Replace(SIGN_FULL_RIGHT_PARENTHESIS, SIGN_RIGHT_PARENTHESIS);
    inputString.Replace(SIGN_FULL_NEGATIVE, SIGN_NEGATIVE);
    inputString.Replace(SIGN_FULL_INCLUSION, SIGN_INCLUSION);
    //去除输入字符串中的换行与空格
    inputString.Replace(_T("\r\n"), _T(""));
    inputString.Replace(_T("\r"), _T(""));
    inputString.Replace(_T("\n"), _T(""));
    inputString.Replace(_T(" "), _T(""));

    InputFrame.SetWindowTextW(inputString);
    InputFrame.SetSel(pos);
}


void ClogicDlg::OnBnClickedButton2()
{
    // TODO: 在此添加控件通知处理程序代码
    InputFrame.SetWindowTextW(CString(""));
    TypeFrame.SetWindowTextW(CString(""));
    PDNFFrame.SetWindowTextW(CString(""));
    PCNFFrame.SetWindowTextW(CString(""));
    ConvertFrame.SetWindowTextW(CString(""));
    TruthTableFrame.SetWindowTextW(CString(""));
}


void ClogicDlg::OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码
    CString sCaption;
    WatchButton.GetWindowTextW(sCaption);
    if ( sCaption == _T("查看真值表 (&V)"))
    {
        WatchButton.SetWindowTextW(_T("返回 (&V)"));
        TruthTableFrame.ShowWindow(SW_SHOW);
	    TypeFrame.ShowWindow(SW_HIDE);
        PDNFFrame.ShowWindow(SW_HIDE);
        PCNFFrame.ShowWindow(SW_HIDE);
        ConvertFrame.ShowWindow(SW_HIDE);
        CopyType.ShowWindow(SW_HIDE);
        CopyPDNF.ShowWindow(SW_HIDE);
        CopyPCNF.ShowWindow(SW_HIDE);
        CopyConvert.ShowWindow(SW_HIDE);
        GetDlgItem(IDC_STATIC_TYPE)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_STATIC_PDNF)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_STATIC_PCNF)->ShowWindow(SW_HIDE);
        GetDlgItem(IDC_STATIC_CONVERT)->ShowWindow(SW_HIDE);
        CopyTruthTable.ShowWindow(SW_SHOW);
    }
    else if ( sCaption == _T("返回 (&V)"))
    {
        WatchButton.SetWindowTextW(_T("查看真值表 (&V)"));
        TruthTableFrame.ShowWindow(SW_HIDE);
	    TypeFrame.ShowWindow(SW_SHOW);
        PDNFFrame.ShowWindow(SW_SHOW);
        PCNFFrame.ShowWindow(SW_SHOW);
        ConvertFrame.ShowWindow(SW_SHOW);
        CopyType.ShowWindow(SW_SHOW);
        CopyPDNF.ShowWindow(SW_SHOW);
        CopyPCNF.ShowWindow(SW_SHOW);
        CopyConvert.ShowWindow(SW_SHOW);
        GetDlgItem(IDC_STATIC_TYPE)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_STATIC_PDNF)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_STATIC_PCNF)->ShowWindow(SW_SHOW);
        GetDlgItem(IDC_STATIC_CONVERT)->ShowWindow(SW_SHOW);
        CopyTruthTable.ShowWindow(SW_HIDE);
    }
}


void ClogicDlg::OnStnClickedCopyType()
{
    // TODO: 在此添加控件通知处理程序代码
    TypeFrame.SetSel(0, -1);
    TypeFrame.Copy();
    MessageBox(_T("已复制到剪切板"));
}


void ClogicDlg::OnStnClickedCopyPdnf()
{
    // TODO: 在此添加控件通知处理程序代码
    PDNFFrame.SetSel(0, -1);
    PDNFFrame.Copy();
    MessageBox(_T("已复制到剪切板"));
}


void ClogicDlg::OnStnClickedCopyPcnf()
{
    // TODO: 在此添加控件通知处理程序代码
    PCNFFrame.SetSel(0, -1);
    PCNFFrame.Copy();
    MessageBox(_T("已复制到剪切板"));
}


void ClogicDlg::OnStnClickedCopyConvert()
{
    // TODO: 在此添加控件通知处理程序代码
    ConvertFrame.SetSel(0, -1);
    ConvertFrame.Copy();
    MessageBox(_T("已复制到剪切板"));
}


void ClogicDlg::OnStnClickedCopyTruthTable()
{
    // TODO: 在此添加控件通知处理程序代码
    TruthTableFrame.SetSel(0, -1);
    TruthTableFrame.Copy();
    MessageBox(_T("已复制到剪切板"));
}
