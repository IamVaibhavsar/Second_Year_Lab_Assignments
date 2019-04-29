/*Write C++/Java program to implement reflection of2-D object about X axis, Y axis and about
X=Y axis. Also implement shear of 2-D object about x-shear and y-shear.
*/

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class Transformation
{
public:
	float a[10][3],b[10][3],c[10][3];
	int n;

	void userInput();
	void display(float c[10][3]);
	void shearing();
	void reflection();
	void mult();
};

void Transformation :: userInput()
{
	int i;
	cout<<"\nEnter total number of vertices: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter "<<i+1<<" co-ordinate: ";
		cin>>c[i][0]>>c[i][1];
		c[i][2]=1;
	}
	display(c);
}

void Transformation :: display(float c[10][3])
{
	float maxx,maxy;
	maxx=getmaxx();
	maxy=getmaxy();
	maxx=maxx/2;
	maxy=maxy/2;
	int i=0;
	while(i<n-1)
	{
		line(maxx+c[i][0],maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
		i++;
	}
	i=n-1;
	line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);
	setcolor(RED);
	line(0,maxy,maxx*2,maxy);
	line(maxx,0,maxx,maxy*2);
	setcolor(WHITE);
}

void Transformation :: mult()
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

void Transformation :: reflection()
{
	int i,j,ch;
	cout<<"\n-------------REFLECTION-------------";
	cout<<"\n1.About X-axis\n2.About Y-axis\n3.About origin";
	cout<<"\n4.About line X=Y\n5.About line X=-Y\n6.Exit";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	cleardevice();
	display(c);

	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
		{
			b[i][j]=0;
			if(i==j)
				b[i][j]=1;
		}

	switch(ch)
	{
		case 1: b[1][1]=-1;
				break;

		case 2: b[0][0]=-1;
				break;

		case 3: b[0][0]=-1;
			  b[1][1]=-1;
				break;

		case 4: b[0][0]=0;			//X=Y
				b[1][1]=0;
				b[0][1]=1;
				b[1][0]=1;
				break;

		case 5: b[0][0]=0;
				b[1][1]=0;
				b[0][1]=-1;
				b[1][0]=-1;
				break;

		case 6: return;
		default: cout<<"\nInvalid choice !";
				break;
	}
	mult();
	setcolor(GREEN);
	display(a);
}

void Transformation :: shearing()
{
	int ch,i,j;
	float sh;
	cleardevice();
	display(c);
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
		{
			b[i][j]=0;
			if(i==j)
				b[i][j]=1;
		}
	cout<<"\n-----------------SHEARING----------------";
	cout<<"\n1.X-shear\n2.Y-shear\n3.Exit";
	cin>>ch;
	cout<<"Enter shear value: ";
	cin>>sh;

	switch(ch)
	{
		case 1: b[1][0]=sh;
				break;

		case 2: b[0][1]=sh;
				break;

		case 3: return;
		default: cout<<"Invalid choice !";
				break;
	}
	mult();
	setcolor(CYAN);
	display(a);
}




int main()
{
	int gd,gm,ch;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	
	Transformation t;
	t.userInput();
	do
	
	{
		cout<<"\n-------SHEARING AND REFLECTION-------";
		cout<<"\n1.Shearing\n2.Reflection\n3.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1: t.shearing();
				break;
		case 2: t.reflection();
				break;
		case 3: cout<<"\nThank you !";
				break;
		default: cout<<"Invalid choice !";
				break;
		}
	}while(ch!=3);

	getch();
	closegraph();
	return 0;
}


