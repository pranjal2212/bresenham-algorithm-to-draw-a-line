/*NAME-PRANJAL AGGARWAL
  17BCE1168
  CODE-BRESENHAM LINE ALGORITHM
*/

# include <iostream.h>
# include <conio.h>
# include <graphics.h>
# include <math.h>
char IncFlag;
void Bresenham(int x1,int x2,int y1,int y2);
void DrawLine(int X,int Y,int End,int PInc,int NInc,int P,int XInc,int YInc);
void main()
{
    int gDriver=DETECT, gMode;
    int x1,x2,y1,y2;

    void Bresenham(int,int,int,int);
    initgraph(&gDriver,&gMode,"c:\\tc\\bgi");

    cout<<endl<<"ENTER THE X1 COORDINATE   : ";
    cin>>x1;
    cout<<endl<<"ENTER THE Y1 COORDINATE   : ";
    cin>>y1;
    cout<<endl<<"ENTER THE X2 COORDINATE    : ";
    cin>>x2;
    cout<<endl<<"ENTER THE Y2 COORDINATE    : ";
    cin>>y2;
    Bresenham(x1,x2,y1,y2);
    getch();
}

void Bresenham(int x1,int x2,int y1,int y2)
{
    int F,L,End;
    int P;
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    float Slope;
    int PInc,NInc,XInc,YInc;
    if (dx == 0)  //Slope Infinite
    {
    }
    else
    {
	Slope = (float)(y1 - y2) / (x1 - x2);
	if (Slope>-1 && Slope<1)
	{
	    IncFlag = 'X';
	    PInc = 2 * (dy - dx);
	    NInc = 2 * dy;
	    P = 2 * dy - dx;
	    if (x1>x2)
	    {
		F = x2;
		L = y2;
		End = x1;
	    }
	    else
	    {
		F = x1;
		L = y1;
		End = x2;
	    }
//            DrawLine(x,y,End,PInc,NInc,P,XInc,YInc);
	}
	else
	{
	    IncFlag = 'Y';
	    PInc = 2 * (dx - dy);
	    NInc = 2 * dx;
	    P = 2 * dx - dy;
	    if (y1 > y2)
	    {
		F = x2;
		L = y2;
		End = y1;
	    }
	    else
	    {
		L = x1;
		F = y1;
		End = y2;
	    }
	}
	if (IncFlag == 'X')
	    putpixel(320+F,240-L,12);
	else
	    putpixel(320+L,240-F,12);
	while (F <= End)
	{
	    F++;
	    if (P<0)
		P = P + NInc;
	    else
	    {
		P = P + PInc;
		if (Slope>0.0)
		    L++;
		else
		    L--;
	    }
	    if (IncFlag == 'X')
		putpixel(320+F,240-L,12);
	    else
		putpixel(320+L,240-F,12);
	}
    }
}