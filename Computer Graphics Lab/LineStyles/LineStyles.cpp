/*Write C++/Java program for line drawing using DDA or Bresenhams algorithm with patterns
such as solid, dotted, dashed, dash dot and thick.*/


#include<iostream>
#include<graphics.h>
using namespace std;
class drawline
 {
	public :
		float x1,x2,y1,y2;
		void get();
		void dda(int);
};

void drawline :: get() 
{
	cout<<"\n Enter the co ordinate : ";
	cout<<"\n Starting point X and Y:";
	cin>>x1>>y1;
	cout<<"\n Ending point X and Y: ";
	cin>>x2>>y2;
}
void drawline:: dda(int id)
{
	float x,y,dx,dy,step,xInc,yInc;
	int w;
	int flag;
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	if(dx>dy)
	{
		flag = 0;
		step = dx;
	} 
	else
	{
		flag = 1;
		step = dy;
	}
	xInc = dx/step;
	yInc = dy/step;
	
	x = x1;
	y = y1;
	putpixel(x,y,WHITE);
	
	if(id == 5)
	{	
	cout<<"\n Enter the width : ";	
	cin>>w;	
	}	

	int i=1;
	while(i <= step)
	{
		x = x + xInc;
		y = y + yInc;
	
		x1 = x + 0.5;
		y1 = y + 0.5;
		
	
		if(id == 1) 
		{
			putpixel(x1,y1,WHITE);		//solid
		}
		
		if(id == 2)					//dotted
		{
			if(flag == 0)
			{
				if((int)x%2 == 0)
				putpixel(x1,y1,WHITE);
			}
			else 
			{
				if((int)y%2 == 0)
				putpixel(x1,y1,WHITE);			
			}
		}
		if(id == 3)					//dotted and dashed
		{
			if(flag == 0)
			{
				if((int)x%2==0||(int)x%3==0)
				putpixel(x1,y1,WHITE);		
			}else 
			{
				if((int)y%2==0||(int)y%3==0)
				putpixel(x1,y1,WHITE);	
			}
		}
		if(id == 4)					//dashed
		{
			if(flag == 0)
			{
				if((int)x%2!=0||(int)x%3!=0)
				putpixel(x1,y1,WHITE);	
			}else 
			{
				if((int)x%2!=0||(int)x%3!=0)
				putpixel(x1,y1,WHITE);	
			}
		}
		if(id == 5)
		{
			if(flag == 0)
			{
				for(int j=0;j<w;j++)
				putpixel(x1+j,y1,WHITE);	
			}else 
			{
				for(int j=0;j<w;j++)
				putpixel(x1,y1+j,WHITE);	
			}
		}
	i++;
	}
}

int main()
{
int gd = DETECT,gm;
initgraph(&gd,&gm,NULL);
drawline d;

int ch;
	do
	{
		cout<<"STYLES:\n1:SOLID\n2:DOTTED\n3:DOTTED AND DASHED\n4:DASHED\n5:THICK\nCHOICE:";
		cout<<"\n Enter your choice : ";			
		cin>>ch;
		switch(ch)
		{
			case 1 :
				cleardevice();
				d.get();
				d.dda(1);
				break;
			case 2:cleardevice();
				d.get();	
				d.dda(2);
				break;
			case 3:cleardevice();
				d.get();
				d.dda(3);
				break;
			case 4:cleardevice();
				d.get();
				d.dda(4);
				break;
			case 5:cleardevice();
				d.get();
				d.dda(5);
				break;					
		}
						
	
	}while(ch != 6);

}
