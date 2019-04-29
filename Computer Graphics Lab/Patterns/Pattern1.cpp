/*Write C++/Java program to draw inscribed and Circumscribed circles in the triangle as shown
as an example below. (Use any Circle drawing and Line drawing algorithms)*/


#include<iostream>
#include<graphics.h>
using namespace std;
class DDA
{
public:
		float X1,Y1,X2,Y2,DX,DY,X,Y,X_INC,Y_INC;
		int X0,Y0,STEPS;
		int gd=DETECT,gm;
	DDA()
	{
		X0=0;
		Y0=0;
	}
	void drawLINE(int x2,int y2,int x1,int y1);				//DRAWS A LINE USING DDA LINE DRAWING ALGORITHM
	void drawSHAPE();													//DRAWS THE REQUIRED SHAPE
};
void DDA::drawLINE(int x2,int y2,int x1,int y1)
{
	X2=x2;Y2=y2;X1=x1;Y1=y1;
	X0=getmaxx()/2;Y0=getmaxy()/2;					//FOR GETTING MIDPOINT OF THE SCREEN
	//putpixel(X0,Y0,WHITE);								//PUTTING MIDPOINT
	DX=X2-X1;												
	DY=Y2-Y1;
	
	if(DX<0)
		DX=-DX;		//compensation of the - sign effect
	if(DY<0)
		DY=-DY;
	if(DX>=DY)												//TO DECIDE: COLUMN /ROW STEPING
		STEPS=DX;
	else
		STEPS=DY;
	
	
	DX=X2-X1;		//reassigning the original values.
	DY=Y2-Y1;
	
	X_INC=(float)DX/STEPS;								//X INCREMENTATION VALUE CORRESSPONDING TO THE SLOPE
	Y_INC=(float)DY/STEPS;								//Y INCREMENTATION VALUE CORRESSPONDING TO THE SLOPE
	X=X1;
	Y=Y1;		
	while(STEPS)											//LOOP EXECUTES "STEPS" TIMES
	{
		putpixel(X0+X+0.5,Y0+Y+0.5,WHITE);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		X+=X_INC;											//X INCREMENTATION
		Y+=Y_INC;											//Y INCREMENTATION
		STEPS--;
	}
	//putpixel(X0,Y0,WHITE);										//CLOSING THE GRAPH
}
void DDA::drawSHAPE()
{
	initgraph(&gd,&gm,NULL);							//INITALIZING GRAPH
	drawLINE(100,50,100,-50);
	drawLINE(100,-50,-100,-50);
	drawLINE(-100,-50,-100,50);
	drawLINE(-100,50,100,50);
	
	drawLINE(200,100,200,-100);
	drawLINE(200,-100,-200,-100);
	drawLINE(-200,-100,-200,100);
	drawLINE(-200,100,200,100);
	
	drawLINE(200,0,0,100);
	drawLINE(200,0,0,-100);
	drawLINE(-200,0,0,100);
	drawLINE(-200,0,0,-100);
	delay(10000);											//DELAY FOR DISPLAY
	closegraph();	
}	
	
int main()													//MAIN FUNCTION
{
	cout<<"DRAWING SHAPE USING DDA LINE DRAWING ALGORITHM"<<endl;
	DDA LINE;										//CREATING OBJECT OF CLASS DDA WHER ALL DATA IS STORED
	LINE.drawSHAPE();
	cout<<endl<<"LINE DRAWN SUCCESSFULLY"<<endl;
	return 0;
}

