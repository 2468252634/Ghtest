// Exp12_4.cpp : Defines the entry point for the application.
//


#include<afxwin.h>
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	CRect rect(0,0,100,50);
	ASSERT(rect.Width()==100);
	ASSERT(rect.Height()==50);
	RECT sdkRect;
	sdkRect.left=0;
	sdkRect.top=0;
	sdkRect.right=100;
	sdkRect.bottom=50;
	CRect rect2(sdkRect);
	CRect rect3(&sdkRect);
	ASSERT(rect2==rect);
	ASSERT(rect3==rect);
	CPoint pt1(0,0);
	CSize sz1(100,50);
	CRect rect4(pt1,sz1);
	ASSERT(rect4==rect2);
	CPoint rightBottom(100,50);
//	CRect rect(pt1,rightBottom);
	CRect rect5(pt1, rightBottom);
	ASSERT(rect5==rect4);
	CSize szEmpty();
	CSize szPointA(10,25);
	SIZE sz;
	sz.cx=10;
	sz.cy=25;
	CSize szPointB(sz);
	POINT pt;
	pt.x=10;
	pt.y=25;
	CSize szPointC(pt);
	CPoint ptObject(10,25);
	CSize szPointD(ptObject);
	DWORD dw=MAKELONG(10,25);
	CSize szPointE(dw);
}
