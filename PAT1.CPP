#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

void Dalg(int X0, int Y0, int X1, int Y1)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    int len = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float) len;
    float Yinc = dy / (float) len;

    float X = X0;
    float Y = Y0;

    for (int i = 0; i <= len; i++)
    {
	putpixel (X,Y,WHITE);
	X += Xinc;
	Y += Yinc;
     }
}


void dispCircle(int xc_,int yc_, int x, int y) {

    putpixel(xc_+x, yc_+y, WHITE);
    putpixel(xc_-x, yc_+y, WHITE);
    putpixel(xc_+x, yc_-y, WHITE);
    putpixel(xc_-x, yc_-y, WHITE);
    putpixel(xc_+y, yc_+x, WHITE);
    putpixel(xc_-y, yc_+x, WHITE);
    putpixel(xc_+y, yc_-x, WHITE);
    putpixel(xc_-y, yc_-x, WHITE);
}

void Bres(int _x, int _y, int _r){

	int x = 0, y = _r;
	int d = 3 - 2 * _r;

	dispCircle(_x, _y, x, y);

	while(y >= x)
	{
		x++;

		if(d > 0){
			y--;
			d = d + 4 * (x - y) + 10;
		}

		else{
			d = d + 4 * x + 6;
		}

		dispCircle(_x, _y, x, y);
	}
}

int main(){

	int gd = DETECT, gm;
	initgraph(&gd, &gm,"c:\\turboc3\\bgi ");
      //	int offset = 0;
       //	int hori_height = 0;

	Bres(150,180,57);
	delay(300);
	Bres(150,180,57/2);
	delay(300);
	Dalg(102, 150, 198, 150);
	delay(300);
	Dalg(102, 150, 150, 236);
	delay(300);
	Dalg(150, 236, 198, 150);
	delay(300);
	getch();

	closegraph();
	return 0;
}