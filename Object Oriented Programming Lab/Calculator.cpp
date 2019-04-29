/*
Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). 
The program should take two operands from user and performs the operation on those two operands depending upon the operator entered by user. 
Use a switch statement to select the operation. Finally, display the result. 
Some sample interaction with the program might look like this: 
Enter first number, operator, second number: 10 / 3 Answer = 3.333333 
Do another (y/n)? y 
Enter first number, operator, second number: 12 + 100 Answer = 112 
Do another (y/n)? n*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class calculator
{
	public:
		float a;
		float b;
		
		calculator()
		{
			a=0.0;
			b=0.0;
		}
	
		friend calculator operator +(calculator, calculator);
		friend calculator operator -(calculator, calculator);
		friend calculator operator *(calculator, calculator);
		friend calculator operator /(calculator, calculator);
		friend istream& operator >>(istream&, calculator&);
		friend ostream& operator <<(ostream&, calculator&);

	
		~calculator()
		{}

};

calculator operator +(calculator c, calculator d)
{
	calculator temp;
	temp.a=c.a+c.b;
	return temp;
}

calculator operator -(calculator c, calculator d)
{
	calculator temp;
	temp.a=c.a-c.b;
	return temp;
}

calculator operator *(calculator c, calculator d)
{
	calculator temp;
	temp.a=c.a*c.b;
	return temp;
}

calculator operator /(calculator c, calculator d)
{
	calculator temp;
	temp.a=c.a/c.b;
	return temp;
}

istream& operator >>(istream& in, calculator& z)
{
	cout<<"Enter the first Operand:"<<endl;
	in>>z.a;
	cout<<"Enter the second Operand:"<<endl;
	in>>z.b;
	return in;
}

ostream& operator <<(ostream& out, calculator& z)
{
	out<<""<<z.a;
	return out;
}

int main()
{
	calculator c1,c2,c3;
	char ch;
	
	cout<<c1<<endl;
	
	cin>>c1;
	//cin>>c2;
	
	do
	{
	
		cout<<"**********WELCOME TO CALCULATOR PROGRAM**********"<<endl;
		cout<<"The available choices are as follows:"<<endl;
		cout<<"+. For Addition"<<endl;
		cout<<"-. For Subtraction"<<endl;
		cout<<"*. For Multiplication"<<endl;
		cout<<"/. For Division"<<endl;
		cout<<"0. For Exit"<<endl;
		
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case '+':
					c3=c1+c2;							
					cout<<"The addition is ="<<endl;
					cout<<c3<<endl;
					break;				
			
			case '-':
					c3=c1-c2;
					cout<<"The subtraction is ="<<endl;
					cout<<c3<<endl;
					break;
				
			case '*':
					c3=c1*c2;
					cout<<"The multiplication is ="<<endl;
					cout<<c3<<endl;
					break;
				
			case '/':
					c3=c1/c2;
					cout<<"The division is ="<<endl;
					cout<<c3<<endl;
					break;
					
			case '0':
					exit(0);
					break;
		
		}
	}while(ch!='0');
	return 0;
}












