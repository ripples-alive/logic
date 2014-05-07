#pragma once

//定义各种运算符号
//const CString SIGN_TABLE(_T("﹁∧∨→↔↑"));
const CString SIGN_TABLE(_T("﹁∧∨→⇔↑↔()!&|>=（）！》←"));
const TCHAR SIGN_NEGATIVE = SIGN_TABLE[0];
const TCHAR SIGN_CONJUNCTION = SIGN_TABLE[1];
const TCHAR SIGN_DISJUNCTION = SIGN_TABLE[2];
const TCHAR SIGN_INCLUSION = SIGN_TABLE[3];
const TCHAR SIGN_EQUIVALENCE = SIGN_TABLE[4];
const TCHAR SIGN_NONCONJ = SIGN_TABLE[5];
const TCHAR SIGN_EQUIVALENCE_SINGLE = SIGN_TABLE[6];
const TCHAR SIGN_LEFT_PARENTHESIS = SIGN_TABLE[7];
const TCHAR SIGN_RIGHT_PARENTHESIS = SIGN_TABLE[8];
const TCHAR SIGN_INPUT_NEGATIVE = SIGN_TABLE[9];
const TCHAR SIGN_INPUT_CONJUNCTION = SIGN_TABLE[10];
const TCHAR SIGN_INPUT_DISJUNCTION = SIGN_TABLE[11];
const TCHAR SIGN_INPUT_INCLUSION = SIGN_TABLE[12];
const TCHAR SIGN_INPUT_EQUIVALENCE = SIGN_TABLE[13];
const TCHAR SIGN_FULL_LEFT_PARENTHESIS = SIGN_TABLE[14];
const TCHAR SIGN_FULL_RIGHT_PARENTHESIS = SIGN_TABLE[15];
const TCHAR SIGN_FULL_NEGATIVE = SIGN_TABLE[16];
const TCHAR SIGN_FULL_INCLUSION = SIGN_TABLE[17];

const int MAXCONTENT = 10000; //公式中变量和运算符出现的总次数上限

const int MAX_ALLOW_LENGTH = 10000; //允许的字符串最大长度
const int MAX_ALLOW_VARIABLE = 12; //显示不带边框真值表的变量个数最大值
const int MAX_ALLOW_TRUTH_TABLE = 6; //显示带边框真值表的变量个数最大值

bool CalcTruthTable(CString s, CString &sTruthTable, int &varNumberCnt, CString variable[], CString &sConvertFormula); //计算真值表和表达式的↑等值表达式
CString JudgeType(const CString &sTruthTable); //根据真值表判断公式类型
bool JudgePDNFAndPCNF(const CString &sTruthTable, CString &sPDNF, CString &sPCNF); //根据真值表求主析取范式和主合取范式
