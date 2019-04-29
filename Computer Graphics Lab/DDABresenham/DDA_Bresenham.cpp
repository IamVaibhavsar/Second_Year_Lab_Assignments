
/*Title: Write a C++ program to draw a line using DDA line algorithm
and Bresenham's Algorithm. Inherit pixel class and use function Overloading.*/


#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class pixel
{
public:
	float x,y,col;
	void drawpixel(float x, float y,float col)
	{
		putpixel(x,y,col);
	}
};

class myline : public pixel
{
public:
	float x1,y1,x2,y2,dx,dy,xnew,ynew,len,x,y;

	int sign(float x)
	{
		if(x<0)
			return -1;
		if(x>0)
			return 1;
		else
			return 0;
	}

	void drawline(float x1,float y1,float x2,float y2)			//DDA
	{
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
			drawpixel(x,y,10);
			
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

	void drawline(int x1, int y1,int x2, int y2)
	{
		int i,exchange,x,y,s1,s2,G;
		int dx,dy,temp;
		
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		
		x=x1;
		y=y1;
		G=(2*dy)-dx;
		
		s1=sign(x2-x1);
		s2=sign(y2-y1);
		
		if(dy>dx)
		{
			temp=dx;		//swap dx and dy
			dx=dy;
			dy=temp;
			exchange=1;
		}
		else
			exchange=0;
		//i=1;
		for(i=1;i<=dx;i++)
		{
				drawpixel(x,y,3);
				while(G>=0)
				{
					if(exchange==1)
						x=x+s1;
					else
						y=y+s2;
					G=G-(2*dx);
				}
				if(exchange==1)
					y=y+s2;
				else
					x=x+s1;
				G=G+2*dy;
		}
				delay(100);
	}
};

int main()
{
	myline obj;
	float x1,y1,x2,y2;
	int X1,Y1,X2,Y2;
	int gd,gm,ch;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);

	do
	{
		cout<<"\n\n----------LINE ALGORITHMS------------";
		cout<<"\n\n1.DDA line algorithm";
		cout<<"\n2.Bresenham line algorithm\n3.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"DDA LINE ALGORITHM: "<<endl;
					cout<<"\nEnter first point(x1,y1): "<<endl;
					cin>>x1>>y1;
					cout<<"\nEnter second point(x2,y2): "<<endl;
					cin>>x2>>y2;
					obj.drawline(x1,y1,x2,y2);					//float
					break;

			case 2: cout<<"BRESENHAM LINE ALGORITHM: "<<endl;
					cout<<"\nEnter first point(x1,y1): "<<endl;
					cin>>X1>>Y1;
					cout<<"\nEnter second point(x2,y2): "<<endl;
					cin>>X2>>Y2;
					obj.drawline(X1,Y1,X2,Y2);					//integer
					break;

			case 3: cout<<"\nYou are out of the Program !"<<endl;
					break;

			default: cout<<"\nEnter proper choice !"<<endl;
					break;
		}
	}while(ch!=3);
	return 0;
}





