/*write a c++ or java program for line styles using dda or bresahnams algorithms
1 solid line
2 dotted line
3 dashline
4 thick line*/
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int sign(int x)
{
	if(x<0)
		return -1;
	else if(x>0)
		return 1;
	else
		return 0;
}
void bline(int x1,int y1,int x2,int y2,int col)
{
int dx,dy,e,x,y,i=1;
dx=x2-x1;
dy=y2-y1;
x=x1;
y=y1;
e=2*dy-dx;
while(i<=dx)
{
while(e>=0)
{
y++;
e=e-2*dx;
}
x++;
e=e+2*dy;
putpixel(x,y,col);
i++;
}
}


void ddaline(int x1,int y1,int x2,int y2,int col)
{
int x,y,len,i;
float dx,dy;
if(x1==x2&&y1==y2)
	putpixel(x1,y1,col);
else
{
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>dy)
		len=dx;
	else
		len=dy;
	dx=(x2-x1)/len;
	dy=(y2-y1)/len;
	x=x1+0.5*sign(dx);
	y=y1+0.5*sign(dy);
	i=1;
	while(i<len)
	{
		if(x%5==1||x%5==2)
		putpixel(x,y,col);

		else if(x%5==4)
		putpixel(x,y,col);
		x=x+dx;
		y=y+dy;
		i++;
	       //delay(100);
	}
}
}
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
ddaline(200,200,400,400,13);
getch();
closegraph();
}

