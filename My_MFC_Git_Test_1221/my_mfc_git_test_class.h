#pragma once

#include <afxwin.h>
#include <afxtempl.h>
#include <afxext.h>
#include "resource.h"

class GraphicObject;

class Shape;
class LineShape;
class EllipseShape;
class RectangleShape;

class MyDocument;
class MyFrame;
class MyView;
class MyApp;

class GraphicObject :public CObject {
public:
	GraphicObject();                                 //It's empty(do nothing)
	GraphicObject(int shape_num, BOOL filled_state, COLORREF fill_color, COLORREF line_color, int line_width, CPoint start_point, CPoint end_point); 
	GraphicObject(GraphicObject& g);              
	GraphicObject& operator= (GraphicObject& g);
private:
	int shape_num_;
	BOOL filled_state_;
	COLORREF fill_color_;
	COLORREF line_color_;
	int line_width_;
	CPoint start_point_;
	CPoint end_point_;
};

//it's base class of a painter object, that storage how to paint on th device content
class Shape {
	friend class MyView;                                        //for MyView access it conveniently
public:
	Shape();                                                    //It's empty: do nothing
	Shape(CPoint start_point, CPoint end_point, int shape_num);  
	Shape(const Shape& s);
	Shape& operator = (const Shape & s);

	virtual void draw(CDC & a_dc, COLORREF color, COLORREF fcolor, int width, BOOL filled = false) = 0;
	int GetShapeNum();
	void SetPoint(CPoint start_point, CPoint end_point);
protected:
	CPoint start_point_, end_point_;                          //the start_point and end_point of shapenum;
	int shape_num_ = 0;
};

class LineShape :public Shape {
	friend class MyView;
public:
	LineShape();
	LineShape(CPoint start_point, CPoint end_point);
	LineShape(const LineShape& e);
	LineShape& operator= (LineShape& e);
	void draw(CDC& a_dc, COLORREF color, COLORREF fcolor, int width, BOOL filled = false);
};

class RectangleShape :public Shape {
	friend class MyView;
public:
	RectangleShape();
	RectangleShape(CPoint start_point, CPoint end_point);
	RectangleShape(const RectangleShape& r);
	RectangleShape& operator= (RectangleShape& r);
	void draw(CDC& a_dc, COLORREF color, COLORREF fcolor, int width, BOOL filled = false);
};

class EllipseShape :public Shape {
	friend class MyView;
public:
	EllipseShape();
	EllipseShape(CPoint start_point, CPoint end_point);
	EllipseShape(const EllipseShape& l);
	EllipseShape& operator= (EllipseShape& l);
	void draw(CDC& a_dc, COLORREF color, COLORREF fcolor, int width, BOOL filled = false);
};

class MyDocument :public CDocument {
	DECLARE_DYNCREATE(MyDocument)
	DECLARE_MESSAGE_MAP()
public:
	void AddObject(GraphicObject& add_graphic);
	GraphicObject& GetGraphic(int i);
	int GetObjectSize();

private:
	CArray<GraphicObject, GraphicObject> graphic_object_array;
};

class MyFrame : public CFrameWnd {
	DECLARE_DYNCREATE(MyFrame)
	DECLARE_MESSAGE_MAP();
public:
	MyFrame();                                               //It's empty: do nothing
	~MyFrame();                                              //It's empty: do nothing
	afx_msg int OnCreate(LPCREATESTRUCT lp_create_struct);  
	CStatusBar status_bar_;
private:
	CMenu* p_menu_;
	CToolBar tool_bar_;
};

class MyView :public CView {
	DECLARE_DYNCREATE(MyView)
	DECLARE_MESSAGE_MAP()
public:
	MyView();      
	~MyView();                                               //It's empty: do nothing

	afx_msg void OnDraw(CDC* p_dc);                          //It's empty: do nothing
	afx_msg void OnLButtonDown(UINT n_flags, CPoint point); 
	afx_msg void OnMouseMove(UINT n_flags, CPoint point);
	afx_msg void OnLButtonUp(UINT n_flags, CPoint point);
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnUpdateRed(CCmdUI* a_cmd_ui);
	afx_msg void OnUpdateGreen(CCmdUI* a_cmd_ui);
	afx_msg void OnUpdateBlue(CCmdUI* a_cmd_ui);
	afx_msg void OnLine();
	afx_msg void OnRect();
	afx_msg void OnEllipse();
	afx_msg void OnUpdatUpdateLine(CCmdUI* p_cmd_ui);
	afx_msg void OnUpdatRect(CCmdUI* p_cmd_ui);
	afx_msg void OnUpdatEllipse(CCmdUI* p_cmd_ui);
private:
	COLORREF l_color_;
	COLORREF filled_color_;
	Shape* p_shape_ = nullptr;
	LineShape line_shape_;
	EllipseShape ellipse_shape_;
	RectangleShape rectangle_shape_;
	int line_width_;
	Shape* rd_shape_;
};

class MyApp : public CWinApp {
public:
	BOOL InitInstance();            
};
