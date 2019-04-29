/*
Write a C++ program to realize polynomial equation and perform operations. Write function
a) To input and output polynomials represented as bmxem+ bm-1xem-1 +….. +b0xe0.
	Your functions should overload the << and >> operators.
1. b) Evaluates a polynomial at given value of x
2. c) Add two polynomials
3. d) Multiplies two polynomials*/


#include<iostream>
#include<math.h>
using namespace std;
#define maxsize 100

typedef struct
{
	
	float coeff;
	int expo;
}poly;

class polynomial
{
	private:
		poly x[maxsize];
		int tot;
		double e;
	public:
		polynomial()
		{	
			tot=0;
			e=0.00;
		}
		
	void read()
	{
		cout<<"\nEnter the total number of terms "<<endl;
		cin>>tot;
		for(int i=0;i<tot;i++)
		{
			cout<<"\nEnter the exponent of "<<i+1<<" term "<<endl;
			cin>>x[i].expo;
			cout<<"\nEnter the coefficient of "<<i+1<<" term "<<endl;
			cin>>x[i].coeff;
		}
	}
	void display()
	{
		cout<<"\nThe polynomial term is:";
		for(int i=0;i<tot;i++)
		{
			if(x[i].coeff!=0)
			{
				if(x[i].coeff==1)
				{
					if(x[i].expo==0)
				    		cout<<1;
				    	else if(x[i].expo==1)
				   		cout<<"x";
				    	else
				    		cout<<"x^"<<x[i].expo;
				}
				else
				{
					if(x[i].expo==0)
				    		cout<<x[i].coeff;
				    	else if(x[i].expo==1)
				    		cout<<x[i].coeff<<"x";
				    	else
				    		cout<<x[i].coeff<<"x^"<<x[i].expo;   
				}
				if(i<tot-1)				//(i!=tot-1)
					cout<<"+";
			}
			
		}
	}
	polynomial add(polynomial p)
	{
		cout<<"\n";
		int m,n,i=0,j=0,k=0;
		polynomial a;		//in which addition is going to store
		while((i<tot)&&(j<p.tot))
		{
			if(x[i].expo== p.x[j].expo)
			{
				a.x[k].coeff=x[i].coeff+p.x[j].coeff;
				a.x[k].expo=x[i].expo;		//p.x[j].expo
				i++;
				j++;
				k++;
			}
			else if(x[i].expo>p.x[j].expo)
			{
				a.x[k].coeff=x[i].coeff;
				a.x[k].expo=x[i].expo;
				i++;
				k++;
			}
			else
			{
				a.x[k].coeff=p.x[j].coeff;
				a.x[k].expo=p.x[j].expo;
				j++;
				k++;
			}
		}
		while(i<tot)
		{
			a.x[k].coeff=x[i].coeff;
			a.x[k].expo=x[i].expo;
			i++;
			k++;
		}
		while(j<p.tot)
		{
			a.x[k].coeff=p.x[j].coeff;
			a.x[k].expo=p.x[j].expo;
			j++;
			k++;
		}
		a.tot=k;
		return a;
	}

	void evaluate()
	{
		double n;
		cout<<"\nEnter a number "<<endl;
		cin>>n;
		for(int i=0;i<tot;i++)
		{
			e=e+(x[i].coeff*pow(n,x[i].expo));		//double e
		}
		cout<<"\nThe value="<<e;
	}
};

int main()
{
	polynomial p1,p2,p3;
	int ch=0;
	char c;
	do
	{
		cout<<"\nEnter 1:To add 2 polynomials,\n2:To evaluate a polynomial "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				p1.read();
		    		p2.read();
		    		p1.display();
		    		p2.display();
				p3=p1.add(p2);		//p2 explicitly called
				p3.display();
				break;

			case 2:
				p1.read();
				p1.display();
				p1.evaluate();
				break;
				
			default:
				cout<<"\nInvalid input";
		}
		cout<<"\nDo you wish to continue?(Y/N) "<<endl;
		cin>>c;
	}while(c=='Y'||c=='y');
	return 0;
}
