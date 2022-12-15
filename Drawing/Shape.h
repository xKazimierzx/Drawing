#pragma once

enum  ElementType { NOTSET, SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };
//声明CShape类，
class CShape : public CObject
{
public:
	CShape();
	virtual ~CShape();
	virtual void Draw(CDC* pDC) = 0;//绘制图元
	virtual bool IsMatched(CPoint pnt) = 0;// Cshape类
	virtual void Serialize(CArchive& ar) = 0;
	virtual void SetValue(ElementType t, int x, int y, int width, int height,CString text) = 0;
	virtual void GetValue(ElementType& t, int& x, int& y, int& width, int& height,CString& text) = 0;
	void SetPen(COLORREF bcolor, int btype, int bwidth);
	void GetPen(COLORREF& bcolor, int& btype, int& bwidth);
	void SetBrush(COLORREF fcolor, int ftype);
	void GetBrush(COLORREF& fcolor, int& ftype);

protected:
	ElementType Type;//图元类型
	int OrgX;//原点坐标
	int OrgY;
	COLORREF   BorderColor;//边界颜色
	int BorderType;//边界线型--实线、虚线、虚点线等
	int BorderWidth;//边界宽度
	COLORREF  FillColor;//填充颜色
	int FillType;//填充类型--实心、双对角、十字交叉等
};


//声明正方形类CSquare
class CSquare : public CShape
{
public:
	CSquare();
	CSquare(int x, int y, int w);
	void Draw(CDC* pDC);//绘制正方形    
	bool  IsMatched(CPoint pnt);// CSquare类；
	virtual void Serialize(CArchive& ar);//序列化正方形图元 
	DECLARE_SERIAL(CSquare)//声明类CSquare支持序列化
	virtual void SetValue(ElementType t, int x, int y, int w, int h,CString text);
	virtual void GetValue(ElementType & t, int& x, int& y, int& w, int& h, CString & text);

private:
	int width;

};

//圆形类CCircle
class CCircle : public CShape
{
public:
	CCircle();
	CCircle(int x, int y, int w);
	void Draw(CDC* pDC);//绘制圆形    
	bool  IsMatched(CPoint pnt);// CCircle类；
	virtual void Serialize(CArchive& ar);//序列化圆形图元 
	DECLARE_SERIAL(CCircle)//声明类CCircle支持序列化
	virtual void SetValue(ElementType t, int x, int y, int w, int h, CString text);
	virtual void GetValue(ElementType& t, int& x, int& y, int& w, int& h, CString& text);

private:
	int width;
};

//椭圆类CEllipse
class CEllipse:public CShape
{
public:
	CEllipse();
	CEllipse(int x, int y, int w,int h);
	void Draw(CDC* pDC);//绘制椭圆形    
	bool  IsMatched(CPoint pnt);// CEllipse类；
	virtual void Serialize(CArchive& ar);//序列化椭圆图元 
	DECLARE_SERIAL(CEllipse)//声明类CEllipse支持序列化
	virtual void SetValue(ElementType t, int x, int y, int w, int h, CString text);
	virtual void GetValue(ElementType& t, int& x, int& y, int& w, int& h, CString& text);

private:
	int width;
	int height;
};

//三角形类CRectangle
class CRectangle :public CShape
{
public:
	CRectangle();
	CRectangle(int x, int y, int w, int h);
	void Draw(CDC* pDC);//绘制三角形    
	bool  IsMatched(CPoint pnt);// CRectangle类；
	virtual void Serialize(CArchive& ar);//序列化图元 
	DECLARE_SERIAL(CRectangle)//声明类支持序列化
	virtual void SetValue(ElementType t, int x, int y, int w, int h, CString text);
	virtual void GetValue(ElementType& t, int& x, int& y, int& w, int& h, CString& text);

private:
	int width;
	int height;
};

//声明三角形类CTritangle
class CTriangle : public CShape
{
public:
	CTriangle();
	CTriangle(int x, int y, int w);
	void Draw(CDC* pDC);//绘制    
	bool  IsMatched(CPoint pnt);
	virtual void Serialize(CArchive& ar);//序列化图元 
	DECLARE_SERIAL(CTriangle)//声明类支持序列化
	virtual void SetValue(ElementType t, int x, int y, int w,int h, CString text);
	virtual void GetValue(ElementType& t, int& x, int& y, int& w,int& h, CString& text);

private:
	int width;
};

//声明文本类CText
class CText : public CShape
{
public:
	CText();
	CText(int x, int y, CString text,int height,int w);
	void Draw(CDC* pDC);//绘制文本    
	bool  IsMatched(CPoint pnt);
	virtual void Serialize(CArchive& ar);//序列化 
	DECLARE_SERIAL(CText)//声明类支持序列化
	virtual void SetValue(ElementType t, int x, int y, int w, int h, CString text);
	virtual void GetValue(ElementType& t, int& x, int& y, int& w, int& h,CString& text);

private:
	CString text; //字体内容
	int height; //字体高度
	int width; //旋转角度
};