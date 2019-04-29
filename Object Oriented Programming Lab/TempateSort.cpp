/*
Write a function template selection Sort. Write a program that inputs, sorts and outputs an integer array and a float array.*/

#include<iostream>
using namespace std;
int n;

template<class T>
class mysort
{
	private :
		T a[20];
	public :
		void read();
		void display();
		void sort();
};


template<class T>
void mysort <T>:: read()
{
	cout<<"\n Enter the number of the elements you want to insert : "<<endl;
	cin>>n;
	cout<<"\n Enter the numbers : "<<endl;
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
}

template<class T>
void mysort<T> :: display()
{
	//cout<<"\n The Entered numbers are: " <<endl;
	for(int i=0;i<n;i++)
		{
			cout<<"\n"<<a[i];
		}	
		cout<<endl;
}

	
template<class T>
void mysort <T>:: sort()
{
	T temp;
	for(int i=0;i<(n-1);i++)
	{
		for(int j=(i+1);j<n;j++)
		{
			if(a[j] < a[i])	
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;		
			}
				
		}	
		for(int  k=0;k<n;k++)								//To display Passes
		{
			cout<<" "<<a[k];
		}
		cout<<endl;	
	}
		
}
int main()
{
	int ch;
	do
	{
		cout<<"\n Enter your choice " ;
		cout<<"\n 1. For integer array sorting " ;
		cout<<"\n 2. For float array sorting " ;
		cout<<"3.Exit"<<endl;
		
		cin>>ch;
		switch(ch)
		{
			case 1 :	
				mysort <int>s1;			//for sorting integer numbers
				s1.read();
				cout<<"The Elements in the UNSORTED order are as follows:"<<endl;
				s1.display();
				s1.sort();
				cout<<"The Elements in the SORTED order are as follows:"<<endl;
				s1.display();
				break;
			case 2 :	
				mysort<float>s2;		//for sorting float numbers
				s2.read();
				cout<<"The Elements in the UNSORTED order are as follows:"<<endl;
				s2.display();
				s2.sort();
				cout<<"The Elements in the SORTED order are as follows:"<<endl;
				s2.display();
				break;
	
			default :
				cout<<"\n Please, Enter the valid option "<<endl;			
		}	
	}while(ch!=3);
	return 0;
}
