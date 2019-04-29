
/*Write C++/Java program to simulate any one of or similar scene-
Clock with pendulum
National Flag hoisting
Vehicle/boat locomotion
Water drop falling into the water and generated waves after impact
Kaleidoscope views generation (at least 3 colorful patterns)
*/

#include<iostream>
#include<graphics.h>
using namespace std;

class car
{
public:
	void init();
	void close();
	void draw(int);
	void animate();
};

void car::init()
{
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
}

void car::close()
{
    getch();
    closegraph();
}

void car::draw(int addX=0)
{

	rectangle(0+addX, 20, 180+addX, 100);
	rectangle(180+addX, 60, 260+addX, 100);
	
	circle(40+addX, 120, 20);
	circle(220+addX, 120, 20);
	
	if(addX%80==0)
	{
		line(40+addX, 120, 40+addX, 100);
		line(220+addX, 120, 220+addX, 100);
	}
	else if(addX%80==20)
	{
		line(40+addX, 120, 60+addX, 120);
		line(220+addX, 120, 240+addX, 120);
	}
	else if(addX%80==40)
	{
		line(40+addX, 120, 40+addX, 140);
		line(220+addX, 120, 220+addX, 140);
	}
	else if(addX%80==60)
	{
		line(40+addX, 120, 20+addX, 120);
		line(220+addX, 120, 200+addX, 120);
	}
}

void car::animate()
{
	for(int i=0 ; i<=320 ; i=i+20)
	{
		draw(i);
		delay(500);
		cleardevice();
	}
}
int main()
{
	car CCX;
	CCX.init();
	CCX.animate();
	CCX.close();
	return 0;
}
