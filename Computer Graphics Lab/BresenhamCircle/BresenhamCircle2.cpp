/*Write C++/Java program to draw circle using Bresenham‘s algorithm. Inherit pixel class.*/

#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

class Pixel
{
	public:
		float x,y,colour;
		
		void getPixel(float x,float y,float colour)
		{
			putpixel(x,y,colour);
		}
};

class Bresenham : public Pixel
{
	public:
		int X,Y,X1,Y1,X0,Y0,R,S;//X=0, Y=R, X1 AND Y1 ARE FROM USER, X0 AND Y0 ARE MIDPOINT OF SCREEN, R IS RADIUS,S IS DECISION PARAMETER 
		int gd=DETECT, gm;
		
		void getdata();
		void putdata();
		void drawCircle();
};

void Bresenham :: getdata()
{
	cout<<"PLEASE ENTER THE DATA OF THE CIRCLE"<<endl;
	cout<<"RADIUS = ";
	cin>>R;
	cout<<"CO-ORDINATES OF THE CENTER"<<endl;
	cout<<"X = ";
	cin>>X1;
	cout<<"Y = ";
	cin>>Y1;
}

void Bresenham :: putdata()
{
	cout<<"DRAWING A CIRCLE OF "<<endl;
	cout<<"RADIUS = "<<R<<endl;
	cout<<"At THE POINT "<<endl;
	cout<<"X = "<<X1<<"\tY = "<<Y1<<endl;
}


void Bresenham :: drawCircle()
{
	initgraph(&gd,&gm,NULL);
	X0=getmaxx()/2;
	Y0=getmaxy()/2;
	
	S=3-(2*R);
	X=0;
	Y=R;
	
	while(X<Y)
	{
		if (S<=0)
		{
			S=S+(4*X)+6;
			X=X+1;
		}
		else
		{
			S=S+(4*(X-Y))+10;
			X=X+1;
			Y=Y-1;
			
		}
		getPixel(X0+X1+X,Y0+Y1+Y,WHITE);
		getPixel(X0+X1+Y,Y0+Y1+X,WHITE);
		getPixel(X0+X1-X,Y0+Y1+Y,WHITE);
		getPixel(X0+X1+Y,Y0+Y1-X,WHITE);
		getPixel(X0+X1+X,Y0+Y1-Y,WHITE);
		getPixel(X0+X1-Y,Y0+Y1+X,WHITE);
		getPixel(X0+X1-X,Y0+Y1-Y,WHITE);
		getPixel(X0+X1-Y,Y0+Y1-X,WHITE);
		
	}
	delay(10000);
	closegraph();
}

int main()
{
	Bresenham Circle;
	Circle.getdata();
	Circle.putdata();
	Circle.drawCircle();
	return 0;
}













