#pragma once
#include "afxdialogex.h"
#include "Shape.h"

// CShapeDlg 对话框

class CShapeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShapeDlg)

public:
	CShapeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CShapeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ShapeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_CmbShapeType;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	CString m_text;
	int m_PenWidth;
	CListBox m_LstPenType;
	CListBox m_LstBrushType;
	CMFCColorButton m_ColorPen;
	CMFCColorButton m_ColorBrush;
	ElementType Type;//图元类型
	COLORREF   BorderColor;//边界颜色
	int BorderType;//边界线型--实线、虚线、虚点线等
	COLORREF  FillColor;//填充颜色
	int FillType;//填充类型
	CShape* pshape;
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnLbnSelchangeList2();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedMfccolorbutton2();
	afx_msg void OnBnClickedOk();
	void DlgToShape();//将对话框中数据传到图元对象中
	void ShapeToDlg();//将图形对象数据传到对话框中
};
