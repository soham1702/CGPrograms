#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

int sign(int x)
{
	if(x>0)
		return 1;
	else if(x<0)
		return -1;
	else
		return 0;
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
		putpixel(x,y,col);
		x=x+dx;
		y=y+dy;
		i++;
	       //delay(100);
	}
}
}
void floodfill(int x,int y,int ncol,int ocol)
{
	if(getpixel(x,y)==ocol)
	{
		putpixel(x,y,ncol);
		floodfill(x+1,y,ncol,ocol);
		floodfill(x-1,y,ncol,ocol);
		floodfill(x,y+1,ncol,ocol);
		floodfill(x,y-1,ncol,ocol);
	}
}
int main()
{
clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	ddaline(10,10,130,10,1);
	ddaline(10,40,130,40,1);
	ddaline(10,70,130,70,1);
	ddaline(10,100,130,100,1);
	ddaline(10,130,130,130,1);
	ddaline(10,10,10,130,1);
	ddaline(40,10,40,130,1);
	ddaline(70,10,70,130,1);
	ddaline(100,10,100,130,1);
	ddaline(130,10,130,130,1);

	floodfill(11,11,15,0);
	floodfill(11,99,15,0);
	floodfill(62,62,15,0);
	floodfill(99,99,15,0);
	floodfill(75,15,15,0);
	floodfill(41,129,15,0);
	floodfill(129,129,15,0);
	floodfill(105,45,15,0);
	getch();
	closegraph();

	return 0;
}
