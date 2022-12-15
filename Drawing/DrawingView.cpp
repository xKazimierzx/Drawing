
// DrawingView.cpp: CDrawingView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif

#include "DrawingDoc.h"
#include "DrawingView.h"
#include "Shape.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CShapeDlg.h"


// CDrawingView

IMPLEMENT_DYNCREATE(CDrawingView, CScrollView)

BEGIN_MESSAGE_MAP(CDrawingView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_Square, &CDrawingView::OnSquare)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_Circle, &CDrawingView::OnCircle)
	ON_COMMAND(ID_Ellipse, &CDrawingView::OnEllipse)
	ON_COMMAND(ID_RECTANGLE, &CDrawingView::OnRectangle)
	ON_COMMAND(ID_TRIANGLE, &CDrawingView::OnTriangle)
	ON_COMMAND(CD_TEXT, &CDrawingView::OnText)
END_MESSAGE_MAP()

// CDrawingView 构造/析构

CDrawingView::CDrawingView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDrawingView::~CDrawingView()
{
}

BOOL CDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CDrawingView 绘图

void CDrawingView::OnDraw(CDC* pDC)
{
	CDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->m_Elements.GetCount(); i++)
	{
		CShape* p = (CShape*)pDoc->m_Elements[i];
		p->Draw(pDC);
	}

}

void CDrawingView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CDrawingView 打印


void CDrawingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDrawingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawingView 诊断
#ifdef _DEBUG
void CDrawingView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDrawingView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDrawingDoc* CDrawingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawingDoc)));
	return (CDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawingView 消息处理程序


void CDrawingView::OnSquare()
{
	// TODO: 在此添加命令处理程序代码
	static int StaticSquareX = 100, StaticSquareY = 100;//正方形的中心点坐标
	CDrawingDoc* pDoc = GetDocument();
	pDoc->m_Elements.Add(new CSquare(StaticSquareX, StaticSquareY, 100));
	StaticSquareX += 25;
	StaticSquareY += 50; //下一个正方形的中心点坐标值增加
	pDoc->UpdateAllViews(NULL);
}


void CDrawingView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc* pDoc = GetDocument();
	CShape* p;
	for (int i = pDoc->m_Elements.GetSize() - 1; i >= 0; i--)
	{
		p = (CShape*)pDoc->m_Elements[i];
		if (p->IsMatched(point))
		{
			pDoc->m_Elements.RemoveAt(i);
			delete p;
				pDoc->UpdateAllViews(NULL);
			break;
		}
	}
	CScrollView::OnLButtonDblClk(nFlags, point);
}


void CDrawingView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc* pDoc = GetDocument();
	CShape* p;
	for (int i = pDoc->m_Elements.GetSize() - 1; i >= 0; i--)
	{
		p = (CShape*)pDoc->m_Elements[i];
		if (p->IsMatched(point))
		{
			CShapeDlg d1;
			d1.pshape = p;
			if (d1.DoModal() == IDOK)
			{
				d1.DlgToShape();
			}
			pDoc->UpdateAllViews(NULL);
			break;
		}
	}

	CScrollView::OnRButtonDblClk(nFlags, point);
}


void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if ((nFlags & MK_CONTROL) == MK_CONTROL)//Ctrl键按下
	{
		CShapeDlg mydlg;
		mydlg.pshape = NULL;
		if (mydlg.DoModal() == IDOK)
		{
			switch (mydlg.Type)
			{
			case SQUARE:mydlg.pshape = new CSquare(); break;
			case RECTANGLE:mydlg.pshape = new CRectangle(); break;
			case CIRCLE:mydlg.pshape = new CCircle(); break;
			case ELLIPSE:mydlg.pshape = new CEllipse(); break;
			case TRIANGLE:mydlg.pshape = new CTriangle(); break;
			case TEXT:mydlg.pshape = new CText(); break;
			}
			mydlg.DlgToShape();
			CDrawingDoc* pDoc = GetDocument();
			pDoc->m_Elements.Add(mydlg.pshape);
			pDoc->UpdateAllViews(NULL);
		}
	}

	CScrollView::OnLButtonDown(nFlags, point);
}


void CDrawingView::OnCircle()
{
	// TODO: 在此添加命令处理程序代码
	static int StaticCircleX = 200, StaticCircleY = 200;//圆形的中心点坐标
	CDrawingDoc* pDoc = GetDocument();
	pDoc->m_Elements.Add(new CCircle(StaticCircleX, StaticCircleY, 100)); /*to do*/
	StaticCircleX += 25;
	StaticCircleY += 50; //下一个圆形的中心点坐标值增加
	pDoc->UpdateAllViews(NULL);
}

void CDrawingView::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	static int StaticEllipseX = 300, StaticEllipseY = 300;//中心点坐标
	CDrawingDoc* pDoc = GetDocument();
	pDoc->m_Elements.Add(new CEllipse(StaticEllipseX, StaticEllipseY, 50,100));
	StaticEllipseX += 25;
	StaticEllipseY += 50; //下一个中心点坐标值增加
	pDoc->UpdateAllViews(NULL);
}

void CDrawingView::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	static int StaticRectangleX = 350, StaticRectangleY = 350;//中心点坐标
	CDrawingDoc* pDoc = GetDocument();
	pDoc->m_Elements.Add(new CRectangle(StaticRectangleX, StaticRectangleY, 100, 50));
	StaticRectangleX += 25;
	StaticRectangleY += 50; //下一个中心点坐标值增加
	pDoc->UpdateAllViews(NULL);
}


void CDrawingView::OnTriangle()
{
	// TODO: 在此添加命令处理程序代码
	static int StaticTriangleX = 400, StaticTriangleY = 300;//中心点坐标
	CDrawingDoc* pDoc = GetDocument();
	pDoc->m_Elements.Add(new CTriangle(StaticTriangleX, StaticTriangleY, 100));
	StaticTriangleX += 25;
	StaticTriangleY += 50; //中心点坐标值增加
	pDoc->UpdateAllViews(NULL);
}


void CDrawingView::OnText()
{
	// TODO: 在此添加命令处理程序代码
	static int StaticTextX = 450, StaticTextY = 250;//左上角点坐标
	CDrawingDoc* pDoc = GetDocument();
	pDoc->m_Elements.Add(new CText(StaticTextX, StaticTextY, "Yangtze University",50,45));
	StaticTextX += 25;
	StaticTextY += 50; //下一个点坐标值增加
	pDoc->UpdateAllViews(NULL);
}
