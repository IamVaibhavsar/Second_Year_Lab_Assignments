/*Write C++/Java program to draw circle using Bresenham‘s algorithm. Inherit pixel class.*/

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
using namespace std;


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
			S=(2*dI)+(2*yi)-1;
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
	int gd,gm,x,y,r;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	cout<<"Enter the coordinates of centre:"<<endl;
	cin>>x>>y;
	cout<<"Enter the radius of circle:"<<endl;
	cin>>r;

	drawCircle(x,y,r);
	getch();
	
	delay(2000);
	closegraph();
	return 0;
}


