
// logicDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// ClogicDlg 对话框
class ClogicDlg : public CDialogEx
{
// 构造
public:
	ClogicDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LOGIC_DIALOG };

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
	CEdit InputFrame;
	CEdit TypeFrame;
	CEdit PDNFFrame;
	CEdit PCNFFrame;
	CButton ResetButton;
	CButton CalcButton;
	CButton WatchButton;
	afx_msg void OnBnClickedOk();
//    afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnEnUpdateEdit1();
    CEdit ConvertFrame;
    afx_msg void OnBnClickedButton2();
    CRichEditCtrl TruthTableFrame;
    afx_msg void OnBnClickedButton1();
    afx_msg void OnStnClickedCopyType();
    CStatic CopyType;
//    CStatic COPY_PDNF;
    CStatic CopyPDNF;
    CStatic CopyPCNF;
    CStatic CopyConvert;
    afx_msg void OnStnClickedCopyPdnf();
    afx_msg void OnStnClickedCopyPcnf();
    afx_msg void OnStnClickedCopyConvert();
    afx_msg void OnStnClickedCopyTruthTable();
    CStatic CopyTruthTable;
};
