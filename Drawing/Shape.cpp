#include "pch.h"
#include "Shape.h"

CSquare::CSquare()
{
	Type = SQUARE;//图元类型
	OrgX = 100;//原点坐标
	OrgY = 100;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = 100;
}

CSquare::CSquare(int x, int y, int w)
{
	Type = SQUARE;//图元类型
	OrgX = x;//原点坐标
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = w;
}

void CSquare::Draw(CDC* pDC)
{
	CPen* pOldPen, * pNewPen;
	pNewPen = new CPen(BorderType, BorderWidth, BorderColor);
	pOldPen = pDC->SelectObject(pNewPen);
	CBrush* pOldBrush, * pNewBrush;
	pNewBrush = new CBrush(FillType, FillColor);
	pOldBrush = pDC->SelectObject(pNewBrush);
	pDC->Rectangle(OrgX - width / 2, OrgY - width / 2, OrgX + width / 2, OrgY + width / 2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	delete pNewPen;
	delete pNewBrush;

}

bool CSquare::IsMatched(CPoint pnt)
{
	if ((pnt.x >= OrgX - width / 2) && (pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY - width / 2) && (pnt.y <= OrgY + width / 2))
		return true;
	else
		return false;
}

IMPLEMENT_SERIAL(CSquare, CObject, 1)//实现类CSquare的序列化，指定版本为1
void CSquare::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;
		ar >> FillType;
		ar >> width;
	}
}

void CSquare::SetValue(ElementType t, int x, int y, int w, int h, CString text)
{
	Type = t; OrgX = x; OrgY = y; width = w;
}
void CSquare::GetValue(ElementType& t, int& x, int& y, int& w, int& h, CString& text)
{
	t = Type; x = OrgX; y = OrgY; w = width; h = 0,text = "0";
}

CShape::CShape()
{
}

CShape::~CShape()
{
}

void CShape::SetPen(COLORREF bcolor, int btype, int bwidth)
{
	BorderColor = bcolor; BorderType = btype; BorderWidth = bwidth;
}
void CShape::GetPen(COLORREF& bcolor, int& btype, int& bwidth)
{
	bcolor = BorderColor; btype = BorderType; bwidth = BorderWidth;
}
void CShape::SetBrush(COLORREF fcolor, int ftype)
{
	FillColor = fcolor; FillType = ftype;
}
void CShape::GetBrush(COLORREF& fcolor, int& ftype)
{
	fcolor = FillColor; ftype = FillType;
}

CCircle::CCircle()
{
	Type = CIRCLE;//图元类型
	OrgX = 200;//原点坐标
	OrgY = 200;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = 100;
}

CCircle::CCircle(int x, int y, int w)
{
	Type = CIRCLE;//图元类型
	OrgX = x;//原点坐标
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = w;
}

void CCircle::Draw(CDC* pDC)
{
	CPen* pOldPen, * pNewPen;
	pNewPen = new CPen(BorderType, BorderWidth, BorderColor);
	pOldPen = pDC->SelectObject(pNewPen);
	CBrush* pOldBrush, * pNewBrush;
	pNewBrush = new CBrush(FillType, FillColor);
	pOldBrush = pDC->SelectObject(pNewBrush);
	pDC->Ellipse(OrgX - width / 2, OrgY - width / 2, OrgX + width / 2, OrgY + width / 2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	delete pNewPen;
	delete pNewBrush;
}

bool CCircle::IsMatched(CPoint pnt)
{
	if ((pnt.x - OrgX) * (pnt.x - OrgX) + (pnt.y - OrgY) * (pnt.y - OrgY) < width * width)
		return true;
	else
		return false;
}

IMPLEMENT_SERIAL(CCircle, CObject, 1)//实现类CCircle的序列化，指定版本为1
void CCircle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;
		ar >> FillType;
		ar >> width;
	}
}

void CCircle::SetValue(ElementType t, int x, int y, int w, int h, CString text)
{
	Type = t; OrgX = x; OrgY = y; width = w;
}

void CCircle::GetValue(ElementType& t, int& x, int& y, int& w, int& h, CString& text)
{
	t = Type; x = OrgX; y = OrgY; w = width; h = 0,text = "0";
}

CEllipse::CEllipse()
{
	Type = ELLIPSE;//图元类型
	OrgX = 300;//原点坐标
	OrgY = 300;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = 50;
	height = 100;
}

CEllipse::CEllipse(int x, int y, int w,int h)
{
	Type = ELLIPSE;//图元类型
	OrgX = x;//原点坐标
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = w;
	height = h;
}

void CEllipse::Draw(CDC* pDC)
{
	CPen* pOldPen, * pNewPen;
	pNewPen = new CPen(BorderType, BorderWidth, BorderColor);
	pOldPen = pDC->SelectObject(pNewPen);
	CBrush* pOldBrush, * pNewBrush;
	pNewBrush = new CBrush(FillType, FillColor);
	pOldBrush = pDC->SelectObject(pNewBrush);
	pDC->Ellipse(OrgX - height/2, OrgY - width/2, OrgX + height/2, OrgY + width/2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	delete pNewPen;
	delete pNewBrush;
}

bool CEllipse::IsMatched(CPoint pnt)
{
	if ((pnt.x - OrgX) * (pnt.x - OrgX) + (pnt.y - OrgY) * (pnt.y - OrgY) < width * width)
		return true;
	else
		return false;
}

IMPLEMENT_SERIAL(CEllipse, CObject, 1)//实现类CEllipse的序列化，指定版本为1
void CEllipse::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
		ar << height;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;
		ar >> FillType;
		ar >> width;
		ar >> height;
	}
}

void CEllipse::SetValue(ElementType t, int x, int y, int w, int h, CString text)
{
	Type = t; OrgX = x; OrgY = y; width = w,height = h;
}

void CEllipse::GetValue(ElementType& t, int& x, int& y, int& w, int& h, CString& text)
{
	t = Type; x = OrgX; y = OrgY; w = width; h = height,text = "0";
}

CRectangle::CRectangle()
{
	Type = RECTANGLE;//图元类型
	OrgX = 350;//原点坐标
	OrgY = 350;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = 100;
	height = 50;
}

CRectangle::CRectangle(int x, int y, int w, int h)
{
	Type = RECTANGLE;//图元类型
	OrgX = x;//原点坐标
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = w;
	height = h;
}

void CRectangle::Draw(CDC* pDC)
{
	CPen* pOldPen, * pNewPen;
	pNewPen = new CPen(BorderType, BorderWidth, BorderColor);
	pOldPen = pDC->SelectObject(pNewPen);
	CBrush* pOldBrush, * pNewBrush;
	pNewBrush = new CBrush(FillType, FillColor);
	pOldBrush = pDC->SelectObject(pNewBrush);
	pDC->Rectangle(OrgX - width / 2, OrgY - height / 2, OrgX + width / 2, OrgY + height / 2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	delete pNewPen;
	delete pNewBrush;
}

bool CRectangle::IsMatched(CPoint pnt)
{
	if ((pnt.x >= OrgX - width / 2) && (pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY - height / 2) && (pnt.y <= OrgY + height / 2))
		return true;
	else
		return false;
}

IMPLEMENT_SERIAL(CRectangle, CObject, 1)//实现类CEllipse的序列化，指定版本为1
void CRectangle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
		ar << height;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;
		ar >> FillType;
		ar >> width;
		ar >> height;
	}
}

void CRectangle::SetValue(ElementType t, int x, int y, int w, int h, CString text)
{
	Type = t; OrgX = x; OrgY = y; width = w, height = h;
}

void CRectangle::GetValue(ElementType& t, int& x, int& y, int& w, int& h, CString& text)
{
	t = Type; x = OrgX; y = OrgY; w = width; h = height,text = "0";
}

CTriangle::CTriangle()
{
	Type = TRIANGLE;//图元类型
	OrgX = 400;//原点坐标
	OrgY = 300;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = 80;
}

CTriangle::CTriangle(int x, int y, int w)
{
	Type = TRIANGLE;//图元类型
	OrgX = x;//原点坐标
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	width = w;
}

void CTriangle::Draw(CDC* pDC)
{
	CPen* pOldPen, * pNewPen;
	pNewPen = new CPen(BorderType, BorderWidth, BorderColor);
	pOldPen = pDC->SelectObject(pNewPen);
	CBrush* pOldBrush, * pNewBrush;
	pNewBrush = new CBrush(FillType, FillColor);
	pOldBrush = pDC->SelectObject(pNewBrush);
	CPoint pt[3] = { CPoint(OrgX-width/2,OrgY+width/2),CPoint(OrgX,OrgY-width/2), CPoint(OrgX+width/2,OrgY+width/2) };
	pDC->Polygon(pt, 3);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	delete pNewPen;
	delete pNewBrush;
}

bool CTriangle::IsMatched(CPoint pnt)
{
	if ((pnt.x >= OrgX - width / 2) && (pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY - width / 2) && (pnt.y <= OrgY + width / 2))
		return true;
	else
		return false;
}

IMPLEMENT_SERIAL(CTriangle, CObject, 1)//实现类CEllipse的序列化，指定版本为1
void CTriangle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;
		ar >> FillType;
		ar >> width;
	}
}

void CTriangle::SetValue(ElementType t, int x, int y, int w,int h, CString text)
{
	Type = t; OrgX = x; OrgY = y; width = w;
}

void CTriangle::GetValue(ElementType& t, int& x, int& y, int& w,int &h, CString& text)
{
	t = Type; x = OrgX; y = OrgY; w = width, h = 0,text = "0";
}

CText::CText()
{
	Type = TEXT;//图元类型
	OrgX = 450;//原点坐标
	OrgY = 250;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	text = "Yangtze University";
	this->height = 50;
	this->width = 45;
}

CText::CText(int x, int y, CString text, int height, int w)
{
	Type = TEXT;//图元类型
	OrgX = x;//原点坐标
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//边界颜色
	BorderType = PS_SOLID;//边界线型--实线、虚线、虚点线等
	BorderWidth = 1;//边界宽度
	FillColor = RGB(0, 255, 0);//填充颜色
	FillType = HS_HORIZONTAL;//填充类型--实心、双对角、十字交叉等
	this->text = text;
	this->height = height;
	this->width = w;
}

void CText::Draw(CDC* pDC)
{
	CFont font;
	font.CreateFont(
		height,                    // nHeight 文字高度
		20,                        // nWidth 文字宽度默认20
		width,                     // nEscapement 旋转角度
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		text);
	pDC->SelectObject(font);
	pDC->SetTextColor(BorderColor); //文字颜色
	pDC->SetBkColor(FillColor); //填充颜色
	pDC->TextOut(OrgX, OrgY, text); //显示文字
	pDC->SetBkColor(RGB(255,255,255)); //还原填充色为白色
}

bool CText::IsMatched(CPoint pnt)
{
	if ((pnt.x >= OrgX) && (pnt.x <= OrgX + text.GetLength()*20) && (pnt.y >= OrgY) && (pnt.y <= OrgY + text.GetLength() * height))
		return true;
	else
		return false;
}

IMPLEMENT_SERIAL(CText, CObject, 1)//实现类CEllipse的序列化，指定版本为1
void CText::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;
		ar << FillType;
		ar << text;
		ar << height;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;
		ar >> FillType;
		ar >> text;
		ar >> height;
		ar >> width;
	}
}

void CText::SetValue(ElementType t, int x, int y, int w, int h, CString text)
{
	Type = t; OrgX = x; OrgY = y; this->text = text,this->height = h,this->width = w;
}

void CText::GetValue(ElementType& t, int& x, int& y, int& w, int& h, CString& text)
{
	t = Type; x = OrgX; y = OrgY; w = 0, h = this->height, text = this->text,w = this->width;
}