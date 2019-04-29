/*Write C++/Java program to draw 2-D object and perform following basic transformations,
a) Scaling
b) Translation
c) Rotation
Use operator overloading.*/


#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void display(int n, float c[][3])
{
	float maxx, maxy;
	int i=0;
	maxx=getmaxx();
	maxy=getmaxy();
	maxx=maxx/2;
	maxy=maxy/2;

	//draw polygon
	while(i<n-1)
	{
		line(maxx+c[i][0], maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
		i++;
	}
	i=n-1;
	line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);
    delay(1000);
	//draw X-Y axis
	setcolor(WHITE);
	line(0,maxy,maxx*2,maxy);
	line(maxx,0,maxx,maxy*2);
	setcolor(WHITE);
}

void mult(int n,float b[][3], float c[][3],float a[][3])
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			a[i][j]=0;

	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				a[i][j]+=(c[i][k]*b[k][j]);
}

void translation(int n,float c[][3],float tx,float ty)
{
	float b[10][3], a[10][3];
	int i=0,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][0]=1;
	b[1][1]=1;
	b[2][2]=1;
	b[2][0]=tx;
	b[2][1]=ty;
	
	mult(n,b,c,a);
	setcolor(YELLOW);
	display(n,a);
	//getch();
}

void scaling(int n,float c[][3],float sx,float sy)
{
	float b[10][3], a[10][3];
	int i=0,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][0]=sx;
	b[1][1]=sy;
	b[2][2]=1;
	mult(n,b,c,a);
	setcolor(YELLOW);
	display(n,a);
}
void rotation(int n,float c[][3], float ra)
{
	int i=0,j;
	float A;
	float b[10][3], xp,yp,a[10][3];
	xp=c[0][0];
	yp=c[0][1];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	A=(ra*3.14)/180;
	b[0][0]=b[1][1]=cos(A);
	b[0][1]=sin(A);			//anticlockwise
	b[1][0]=-sin(A);
	b[2][0]=(-xp * cos(A)) + (yp * sin(A)) + xp;
	b[2][1]=(-xp * sin(A)) - (yp * cos(A)) + yp;
	b[2][2]=1;
	mult(n,b,c,a);
	setcolor(YELLOW);
	display(n,a);
}

int main()
{
	int i,ch,n,gd,gm;
	gd=DETECT;
	float c[10][3],tx,ty,sx,sy,ra;
	initgraph(&gd,&gm,NULL);
	cout<<"\nEnter the number of vertices: ";
	cin>>n;

	for(i=0;i<n;i++)
	{
		cout<<"Enter the co-ordinates of vertex "<<i+1<<":";
		cin>>c[i][0]>>c[i][1];
		c[i][2]=1;
	}

	do
	{
		//cleardevice();
		cout<<"\n\n------------2-D Transformation-------------";
		cout<<"\n1.Translation\n2.Scaling\n3.Rotation\n4.Exit";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nEnter Translation factors tx and ty:";
					cin>>tx>>ty;
					cleardevice();
					setcolor(CYAN);
					display(n,c);
					translation(n,c,tx,ty);
					//getch();
					break;

			case 2: cout<<"\nEnter the scaling factors sx and sy:";
					cin>>sx>>sy;
					cleardevice();
					setcolor(CYAN);
					display(n,c);
					scaling(n,c,sx,sy);
					break;

			case 3: cout<<"\nEnter the angle for rotation: ";
					cin>>ra;
					cleardevice();
					setcolor(CYAN);
					display(n,c);
					rotation(n,c,ra);
					//getch();
					break;

			case 4: cout<<"\nYou are out of the program !";
					break;

			default: cout<<"\nEnter valid choice !";
					break;

		}

	}while(ch!=4);
	return 0;
}






