/*
Implement a class Quadratic that represents degree two polynomials i.e., polynomials of type ax2+bx+c. 
The class will require three data members corresponding to a, b and c. Implement the following operations: 
1. A constructor (including a default constructor which creates the 0 polynomial). 
2. Overloaded operator+ to add two polynomials of degree 2. 
3. Overloaded << and >> to print and read polynomials. To do this, you will need to decide what you want your input and output format to look like. 
4. A function eval that computes the value of a polynomial for a given value of x. 
5. A function that computes the two solutions of the equation ax2+bx+c=0.*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class quadratic
{
	public:
		int a;
		int b;
		int c;
public :
	quadratic() {};
	quadratic(int x,int y,int z)
	{
		a=x;
		b=y;
		c=z;
	}
	
	quadratic operator+ (quadratic);
	void display();
	void addition();
	float evaluate(int , int ,int ,float);
	
};

quadratic quadratic::operator+ (quadratic d )
{
	quadratic temp;
	temp.a=a+d.a;
	temp.b=b+d.b;
	temp.c=c+d.c;

	return temp;
}

float quadratic:: evaluate(int c1,int c2,int c3,float var)
{
	float eval=((c1*var*var)+(c2*var)+(c3));
	return eval;
}



void quadratic::display()
{
	cout<<"\n the quadratic equation is =  "<<a<<"x^2"<<"+"<<b<<"x"<<"+"<<c<<endl;
}

void quadratic::addition()
{
	cout<<"\n THE ADDITION TWO QUADRATIC EQUATIONS IS =  "<<a<<"x^2"<<"+"<<b<<"x"<<"+"<<c<<endl;
}


int main()
{

	int coefA1,coefB1,coefC1,coefA2,coefB2,coefC2;
	quadratic q1,q2,q3;
	int ch;
	float key,a;
	

	do
	{
		cout<<"THE AVAILABLE CHOICES ARE AS FOLLOWS."<<endl;
		cout<<"1.For adding two quadratic equations using operator overloading."<<endl;
		cout<<"2.For Evaluation of a quadratic equation."<<endl;
		cout<<"3.Exit";<<endl
		
		
		cout<<"ENTER YOUR CHOICE:";
		cin>>ch;
		
		switch(ch)
		{
		
			case 1 :		
				cout<<"ENTER THE COEFFICIENTS OF FIRST QUADRATIC EQUATION"<<endl;
				cout<<"Enter coefficient a for first quadratic equation:"<<endl;
				cin>>coefA1;
				cout<<"Enter coefficient b for first quadratic equation:"<<endl;
				cin>>coefB1;
				cout<<"Enter coefficient c for first quadratic equation:"<<endl;
				cin>>coefC1;
	
				cout<<"ENTER THE COEFFICIENTS OF SECOND QUADRATIC EQUATION"<<endl;
				cout<<"Enter coefficient a for second quadratic equation:"<<endl;
				cin>>coefA2;
				cout<<"Enter coefficient b for second quadratic equation:"<<endl;
				cin>>coefB2;
				cout<<"Enter coefficient c for second quadratic equation:"<<endl;
				cin>>coefC2;
	
	
				q1=quadratic(coefA1,coefB1,coefC1);
				q2=quadratic(coefA2,coefB2,coefC2);
	
				q1.display();
				q2.display();
	
				q3=q1+q2;
				q3.addition();
				break;
				
			case 2:
				cout<<"ENTER THE COEFFICIENTS OF QUADRATIC EQUATION"<<endl;
				cout<<"Enter the coefficient a :"<<endl;
				cin>>coefA1;
				cout<<"Enter the coefficient b :"<<endl;
				cin>>coefB1;
				cout<<"Enter the coefficient c :"<<endl;
				cin>>coefC1;
				
				cout<<"\nENTER THE VALUE FOR WHICH YOU WANT TO EVALUATE QUADRATIC EQUATION:"<<endl;
				cin>>key;
				//q1.evaluate(coefA1,coefB1,coefC,key);
				a=q1.evaluate(coefA1,coefB1,coefC1,key);
				cout<<"THE ANSWER IS = "<<a<<endl;
				break;
				
						
			case 3:
					exit(0);
	
		}
	}while(ch<3);
	return 0;
}



























	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	





