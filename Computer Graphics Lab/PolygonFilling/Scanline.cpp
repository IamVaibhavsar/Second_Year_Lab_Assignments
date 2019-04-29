
/*Write C++/Java program to fill polygon using scan line algorithm.*/

#include<graphics.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class polygon
{
	public:
		int x[10],y[10];
		int min_y,max_y,y_val;
		int n,i;
		int cnt;
		float m[20],xint[200];
		void draw_poly();
		void scanline();
		void sort(float[],int);
		void floodfill(int,int,int,int);
		void boundaryFill(int,int,int,int);
		
};

void polygon::draw_poly()
{
	cout<<"\nEnter no of vertices";
	cin>>n;
	if(n<3)
	{
		cout<<"\nError";
		exit(0);
	}
	else
	{
		for(i=0;i<n;i++)
		{
			cin>>x[i];
			cin>>y[i];
		}
		x[n]=x[0];
		y[n]=y[0];
		for(i=0;i<n;i++)
		{
			line(x[i],y[i],x[i+1],y[i+1]);
		}
	}
}
void polygon::scanline()
{
	draw_poly();
	setcolor(BLUE);
	min_y=480;
	max_y=0;
	for(i=0;i<n;i++)
	{
		if(min_y >= y[i])
			min_y=y[i];
		
		if(y[i]>= max_y)
			max_y=y[i];
		
		int dx=x[i+1]-x[i];
		int dy=y[i+1]-y[i];
		if(dx==0)
		{
			m[i]=0;
		}
		else if(dy==0)
		{
			m[i]=1;
		}
		else
		{
			m[i]=(dy/dx);
		}
		//cout<<m[i];
	}
	
	for(y_val=max_y;y_val>=min_y;y_val--)
	{
		cnt=0;
		for(i=0;i<n;i++)
		{
			if((y[i]>y_val && y[i+1]<=y_val) || (y[i]<=y_val && y[i+1]>y_val))
			{
				//if (m[i]!=0)
					xint[cnt]=x[i]+((y_val-y[i])*m[i]);
				//else
					//xint[cnt]=x[i];
				cnt++;
			}
		}
		sort(xint,cnt);

		for(int k=0;k<cnt-1;k=k+2)
		{
			line(xint[k],y_val,xint[k+1],y_val);
			delay(50);
		}
	}

}

void polygon::sort(float xint[],int cnt)
{
	float temp;
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<cnt-1;j++)
		{
			if(xint[i] > xint[j])
			{
				temp=xint[j];
				xint[j]=xint[j+1];
				xint[j+1]=temp;
			}
		}
	}
}

void polygon::floodfill(int x,int y,int new_color,int old_color)		// also called as SeedFill
{ 
    if (getpixel(x,y) == old_color) 						//OR (getpixel(x,y) != new_color) 
    { 	
        putpixel(x,y,new_color); // put new pixel with new color 
  
        floodfill(x+1,y,new_color,old_color); 
  	  floodfill(x-1,y,new_color,old_color); 
  	  floodfill(x,y+1,new_color,old_color); 
  	  floodfill(x,y-1,new_color,old_color); 
    }

}

void polygon::boundaryFill(int x, int y, int new_color,int old_color)
{
    if(getpixel(x,y) != old_color && getpixel(x,y) != new_color)
    {
        putpixel(x,y,new_color);
        boundaryFill(x+1,y,new_color,old_color);
        boundaryFill(x,y+1,new_color,old_color);
        boundaryFill(x-1,y,new_color,old_color);
        boundaryFill(x,y-1,new_color,old_color);
    }
}

int main()
{
	int gd,gm;
	int new_color,x,y,ch;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	
	polygon p;
	do
	{
		cout<<"\n1.Scanline algorithm\n2.Floodfill algorithm\n3.Boundaryfill algorithm";
		cout<<"\nEnter choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
				p.scanline();
				break;
			case 2:
				p.draw_poly();
				cout<<"\nEnter x and y ";
				cin>>x>>y;
				p.floodfill(x,y,BLUE,BLACK);			//SeedFill
				break;
			case 3:
				p.draw_poly();
				cout<<"\nEnter x and y ";
				cin>>x>>y;
				p.boundaryFill(x,y,YELLOW,15);
				break;
			default:
				cout<<"\nEnter valid choice";
		}
	}while(ch<4);
	
	getch();
	closegraph();
	return 0;
}
