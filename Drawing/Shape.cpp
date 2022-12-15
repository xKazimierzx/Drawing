#include "pch.h"
#include "Shape.h"

CSquare::CSquare()
{
	Type = SQUARE;//ͼԪ����
	OrgX = 100;//ԭ������
	OrgY = 100;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	width = 100;
}

CSquare::CSquare(int x, int y, int w)
{
	Type = SQUARE;//ͼԪ����
	OrgX = x;//ԭ������
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
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

IMPLEMENT_SERIAL(CSquare, CObject, 1)//ʵ����CSquare�����л���ָ���汾Ϊ1
void CSquare::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
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
	Type = CIRCLE;//ͼԪ����
	OrgX = 200;//ԭ������
	OrgY = 200;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	width = 100;
}

CCircle::CCircle(int x, int y, int w)
{
	Type = CIRCLE;//ͼԪ����
	OrgX = x;//ԭ������
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
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

IMPLEMENT_SERIAL(CCircle, CObject, 1)//ʵ����CCircle�����л���ָ���汾Ϊ1
void CCircle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
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
	Type = ELLIPSE;//ͼԪ����
	OrgX = 300;//ԭ������
	OrgY = 300;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	width = 50;
	height = 100;
}

CEllipse::CEllipse(int x, int y, int w,int h)
{
	Type = ELLIPSE;//ͼԪ����
	OrgX = x;//ԭ������
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
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

IMPLEMENT_SERIAL(CEllipse, CObject, 1)//ʵ����CEllipse�����л���ָ���汾Ϊ1
void CEllipse::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
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
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
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
	Type = RECTANGLE;//ͼԪ����
	OrgX = 350;//ԭ������
	OrgY = 350;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	width = 100;
	height = 50;
}

CRectangle::CRectangle(int x, int y, int w, int h)
{
	Type = RECTANGLE;//ͼԪ����
	OrgX = x;//ԭ������
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
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

IMPLEMENT_SERIAL(CRectangle, CObject, 1)//ʵ����CEllipse�����л���ָ���汾Ϊ1
void CRectangle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
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
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
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
	Type = TRIANGLE;//ͼԪ����
	OrgX = 400;//ԭ������
	OrgY = 300;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	width = 80;
}

CTriangle::CTriangle(int x, int y, int w)
{
	Type = TRIANGLE;//ͼԪ����
	OrgX = x;//ԭ������
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
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

IMPLEMENT_SERIAL(CTriangle, CObject, 1)//ʵ����CEllipse�����л���ָ���汾Ϊ1
void CTriangle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
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
	Type = TEXT;//ͼԪ����
	OrgX = 450;//ԭ������
	OrgY = 250;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	text = "Yangtze University";
	this->height = 50;
	this->width = 45;
}

CText::CText(int x, int y, CString text, int height, int w)
{
	Type = TEXT;//ͼԪ����
	OrgX = x;//ԭ������
	OrgY = y;
	BorderColor = RGB(255, 0, 0);//�߽���ɫ
	BorderType = PS_SOLID;//�߽�����--ʵ�ߡ����ߡ�����ߵ�
	BorderWidth = 1;//�߽���
	FillColor = RGB(0, 255, 0);//�����ɫ
	FillType = HS_HORIZONTAL;//�������--ʵ�ġ�˫�Խǡ�ʮ�ֽ����
	this->text = text;
	this->height = height;
	this->width = w;
}

void CText::Draw(CDC* pDC)
{
	CFont font;
	font.CreateFont(
		height,                    // nHeight ���ָ߶�
		20,                        // nWidth ���ֿ��Ĭ��20
		width,                     // nEscapement ��ת�Ƕ�
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
	pDC->SetTextColor(BorderColor); //������ɫ
	pDC->SetBkColor(FillColor); //�����ɫ
	pDC->TextOut(OrgX, OrgY, text); //��ʾ����
	pDC->SetBkColor(RGB(255,255,255)); //��ԭ���ɫΪ��ɫ
}

bool CText::IsMatched(CPoint pnt)
{
	if ((pnt.x >= OrgX) && (pnt.x <= OrgX + text.GetLength()*20) && (pnt.y >= OrgY) && (pnt.y <= OrgY + text.GetLength() * height))
		return true;
	else
		return false;
}

IMPLEMENT_SERIAL(CText, CObject, 1)//ʵ����CEllipse�����л���ָ���汾Ϊ1
void CText::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
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
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
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