/*
 Problem Statement: Write C++ program to draw any object such as flower waves using any curve generation
 techniques. (Bezier Curve)
 */
#include<iostream>
#include<graphics.h>
#include<math.h>
#include<fstream>
using namespace std;

void bezier(int x[4][4], int y[4][4])
{
	int i,j;
	double t;

	for(i=0;i<4;i++)
	{
		for(t=0.0;t<1.0;t=t+0.005)
		{
			double xt=(pow(1-t,3)*x[i][0]) + (3*t*pow(1-t,2)*x[i][1]) + (3*pow(t,2)*(1-t)*x[i][2])+ (pow(t,3)*x[i][3]);
			double yt=(pow(1-t,3)*y[i][0]) + (3*t*pow(1-t,2)*y[i][1]) + (3*pow(t,2)*(1-t)*y[i][2])+ (pow(t,3)*y[i][3]);
			putpixel(xt,yt,CYAN);
			delay(3);
		}
	}

}
int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	
	fstream fin;								//object of fstream class
	fin.open("data.txt", ios :: in | ios :: out);			//opening the file data.txt in input and output mode
	
	int x[4][4],y[4][4];
	int i,j;
	
	cout<<"\nEnter the x and y coordinates of four control points: ";
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			fin>>x[i][j]>>y[i][j];
		
	bezier(x,y);
		
	getch();
	closegraph();
	return 0;
}



/*
from file data.txt

200 200 	160 160 240 160 		200 200
200 200 	240 160 240 240 		200 200
200 200 	240 240 160 240 		200 200
200 200 	160 240 160 160 		200 200
*/


