/*Write C++/Java program to draw inscribed and Circumscribed circles in the triangle as shown
as an example below. (Use any Circle drawing and Line drawing algorithms)*/

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
using namespace std;

int sign(float x)
	{
		if(x<0)
			return -1;
		if(x>0)
			return 1;
		else
			return 0;
	}


void drawline(int x1, int y1,int x2, int y2)
{
	float dx,dy,len,xnew,ynew,x,y;
		
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		if(dx>dy)
			len=dx;
		else
			len=dy;

		xnew=dx/len;
		ynew=dy/len;
		
		x=x1+0.5;
		y=y1+0.5;

		for(int i=1;i<=len;i++)
		{
			putpixel(x,y,10);
			
		      if(sign(x2-x1)==1)
		          x=x+xnew;
		      else
				 x=x-xnew;
		      
		      if(sign(y2-y1)==1)
		          y=y+ynew;
		      else
		          y=y-ynew;
		}
}


void mh(int *xi,int *yi,int *di)
{
	*xi=*xi+1;
	*di=*di+(2*(*xi))+1;
}

void md(int *xi,int *yi,int *di)
{
	*xi=*xi+1;
	*yi=*yi-1;
	*di=*di+(2*(*xi))-(2*(*yi))+2;
}

void mv(int *xi,int *yi,int *di)
{
	*yi=*yi-1;
	*di=*di-(2*(*yi))+1;
}

void drawCircle(int x,int y,int r)
{
	int xi,yi,dI,limit=0,S;
	xi=0;
	yi=r;
	dI=2*(1-r);
	while(yi>=limit)
	{
		putpixel(x+xi,y+yi,10);
		putpixel(x-xi,y-yi,10);
		putpixel(x-xi,y+yi,10);
		putpixel(x+xi,y-yi,10);
		if(dI<0)
		{
			S=(2*dI)+(2*yi)-1;		// (100,250) (300,250) (200,76) (200,193,57)
			if(S<=0)
				mh(&xi,&yi,&dI);
			else
				md(&xi,&yi,&dI);
		}
		else if(dI>0)
		{
			S=(2*dI)-(2*xi)-1;
			if(S<=0)
				md(&xi,&yi,&dI);
			else
				mv(&xi,&yi,&dI);
		}
		else if(dI==0)
			md(&xi,&yi,&dI);
	}
}

int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	drawline(100,250,300,250);
	drawline(100,250,200,76);
	drawline(200,76,300,250);
	drawCircle(200,193,57);
	//drawline(143,193,200,136);
	//drawline(200,136,257,193);
	//drawline(200,250,257,193);
	//drawline(200,250,143,193);
	drawCircle(200,193,116);
	getch();
	delay(2000);
	closegraph();
	return 0;
}

