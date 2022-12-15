// CShapeDlg.cpp: 实现文件
//

#include "pch.h"
#include "Drawing.h"
#include "afxdialogex.h"
#include "CShapeDlg.h"


// CShapeDlg 对话框

IMPLEMENT_DYNAMIC(CShapeDlg, CDialogEx)

CShapeDlg::CShapeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ShapeDlg, pParent)
	, m_x(0)
	, m_y(0)
	, m_width(0)
	, m_height(0)
	, m_text(_T(""))
	, m_PenWidth(0)
{

}

CShapeDlg::~CShapeDlg()
{
}

void CShapeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_CmbShapeType);
	DDX_Text(pDX, IDC_EDIT2, m_x);
	DDX_Text(pDX, IDC_EDIT3, m_y);
	DDX_Text(pDX, IDC_EDIT4, m_width);
	DDX_Text(pDX, IDC_EDIT5, m_height);
	DDX_Text(pDX, IDC_EDIT6, m_text);
	DDX_Text(pDX, IDC_EDIT7, m_PenWidth);
	DDX_Control(pDX, IDC_LIST1, m_LstPenType);
	DDX_Control(pDX, IDC_LIST2, m_LstBrushType);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_ColorPen);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_ColorBrush);
}


BEGIN_MESSAGE_MAP(CShapeDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CShapeDlg::OnCbnSelchangeCombo1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CShapeDlg::OnLbnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_LIST2, &CShapeDlg::OnLbnSelchangeList2)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CShapeDlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CShapeDlg::OnBnClickedMfccolorbutton2)
	ON_BN_CLICKED(IDOK, &CShapeDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CShapeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_LstPenType.AddString("PS_SOLID");
	m_LstPenType.AddString("PS_DASH");
	m_LstPenType.AddString("PS_DOT");
	m_LstPenType.AddString("PS_DASHDOT");
	m_LstPenType.AddString("PS_DASHDOTDOT");

	m_LstBrushType.AddString("HS_HORIZONTAL");
	m_LstBrushType.AddString("HS_VERTICAL");
	m_LstBrushType.AddString("HS_BDIAGONAL");
	m_LstBrushType.AddString("HS_FDIAGONAL");
	m_LstBrushType.AddString("HS_CROSS");
	m_LstBrushType.AddString("HS_DIAGCROSS");

	if (pshape)  ShapeToDlg();
	else {
		UpdateData(false);
		Type = SQUARE; m_CmbShapeType.SetCurSel(0);
		BorderColor = RGB(255, 0, 0); m_ColorPen.SetColor(BorderColor);
		FillColor = RGB(0, 255, 0); m_ColorBrush.SetColor(FillColor);
		BorderType = PS_SOLID; m_LstPenType.SetCurSel(0);
		FillType = HS_HORIZONTAL; m_LstBrushType.SetCurSel(0);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CShapeDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 图元类型组合框
	int i = m_CmbShapeType.GetCurSel();
	switch (i)
	{
	case 0: Type = SQUARE;  break;
	case 1: Type = RECTANGLE;  break;
	case 2: Type = CIRCLE;  break;
	case 3: Type = ELLIPSE;  break;
	case 4: Type = TRIANGLE;  break;
	case 5: Type = TEXT;  break;
	}
}


void CShapeDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 边线样式列表框
	int i = m_LstPenType.GetCurSel();
	switch (i)
	{
	case 0:BorderType = PS_SOLID; break;
	case 1:  BorderType = PS_DASH; break;
	case 2:  BorderType = PS_DOT; break;
	case 3:  BorderType = PS_DASHDOT; break;
	case 4:  BorderType = PS_DASHDOTDOT; break;
	}
}


void CShapeDlg::OnLbnSelchangeList2()
{
	// TODO: 在此添加控件通知处理程序代码
	// 画刷阴影风格
	int i = m_LstBrushType.GetCurSel();
	switch (i)
	{
	case 0:FillType = HS_HORIZONTAL; break;
	case 1:FillType = HS_VERTICAL; break;
	case 2:FillType = HS_FDIAGONAL; break;
	case 3:FillType = HS_BDIAGONAL; break;
	case 4:FillType = HS_CROSS; break;
	case 5:FillType = HS_DIAGCROSS; break;
	}
}


void CShapeDlg::OnBnClickedMfccolorbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 颜色按钮
	BorderColor = m_ColorPen.GetColor();
}


void CShapeDlg::OnBnClickedMfccolorbutton2()
{
	// TODO: 在此添加控件通知处理程序代码
	FillColor = m_ColorBrush.GetColor();
}


void CShapeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CDialogEx::OnOK();
}

void CShapeDlg::DlgToShape()
{
	if (pshape)
	{
		pshape->SetBrush(FillColor, FillType);
		pshape->SetPen(BorderColor, BorderType, m_PenWidth);
		pshape->SetValue(Type, m_x, m_y, m_width, m_height,m_text);
	}
}

void CShapeDlg::ShapeToDlg()
{
	if (pshape)
	{
		pshape->GetBrush(FillColor, FillType);
		pshape->GetPen(BorderColor, BorderType, m_PenWidth);
		pshape->GetValue(Type, m_x, m_y, m_width, m_height,m_text);
		UpdateData(false);
		switch (Type)
		{
		case SQUARE:m_CmbShapeType.SetCurSel(0);
			break;
		case RECTANGLE:m_CmbShapeType.SetCurSel(1);
			break;
		case CIRCLE:m_CmbShapeType.SetCurSel(2);
			break;
		case ELLIPSE:m_CmbShapeType.SetCurSel(3);
			break;
		case TRIANGLE:m_CmbShapeType.SetCurSel(4);
			break;
		case TEXT:m_CmbShapeType.SetCurSel(0);
			break;
		default:
			break;
		}
		switch (BorderType)
		{
		case PS_SOLID:m_LstPenType.SetCurSel(0); break;
		case PS_DASH:m_LstPenType.SetCurSel(1); break;
		case PS_DOT:m_LstPenType.SetCurSel(2); break;
		case PS_DASHDOT:m_LstPenType.SetCurSel(3); break;
		case PS_DASHDOTDOT:m_LstPenType.SetCurSel(4); break;
		}
		switch (FillType)
		{
		case HS_HORIZONTAL:m_LstBrushType.SetCurSel(0); break;
		case HS_VERTICAL:m_LstBrushType.SetCurSel(1); break;
		case HS_BDIAGONAL:m_LstBrushType.SetCurSel(2); break;
		case HS_FDIAGONAL:m_LstBrushType.SetCurSel(3); break;
		case HS_CROSS:m_LstBrushType.SetCurSel(4); break;
		case HS_DIAGCROSS:m_LstBrushType.SetCurSel(5); break;
		}
		m_ColorPen.SetColor(BorderColor);
		m_ColorBrush.SetColor(FillColor);
	}
}
