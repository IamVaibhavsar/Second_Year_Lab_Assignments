
/*
Implement a class CppArray which is identical to a one-dimensional C++ array (i.e., the index set is a set of consecutive integers starting at 0) except for the following : 
1. It performs range checking. 
2. It allows one to be assigned to another array through the use of the assignment operator (e.g. cp1= cp2) 
3. It supports a function that returns the size of the array. 
4. It allows the reading or printing of array through the use of cout and cin.*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class SafeArray
{
	public:
		int size;
		int arr[5];
	
	public:
		SafeArray(int size) 		//parameterised constructor
		{
			this->size=size;
			for(int i=0;i<size;i++)		//each element 0
			{
				arr[i]=0;
			}
		}
		
		void operator = (SafeArray &temp)		//assignment function
		{
			for(int i=0;i<size;i++)
			{
				arr[i]=temp.arr[i];
			}
		}
		
		int& operator [](int index)							//reference will be returned and value will be assigned to that index.
		{													//range checking
			if(index >=size || index<0)
			{
				cout<<"Index out of bound"<<endl;
				exit(1);
			}
			return arr[index];
		}
		
		int getSize()
		{
			return size;
		}
		
		friend istream& operator >>(istream&, SafeArray&);
		friend ostream& operator <<(istream&, SafeArray&);
};

istream& operator >>(istream& in, SafeArray& z)
{
	for(int i=0;i<z.size;i++)
	{
		in>>z[i];
	}
	return in;
}

ostream& operator <<(ostream& out, SafeArray& z)
{
	for(int i=0;i<z.size;i++)
	{
		out<<z[i]<<endl;
	}
	return out;
}

int main()
{
	SafeArray sa(5);
	
	cout<<"Enter the Elements in the array:"<<endl;
	cin>>sa;
	
	cout<<"Displaying SA:"<<endl;
	cout<<sa;
	
	cout<<"The size of SA is ="<<sa.getSize()<<endl;
		
	//sa[0]=10;		//because of [] operator overloading function is called
	//sa[1]=20;
	//sa[2]=30;
	//sa[3]=40;
	//sa[4]=50;
	
	//cout<<sa[0]<<endl;
	//cout<<sa[1]<<endl;
	//cout<<sa[2]<<endl;
	//cout<<sa[3]<<endl;
	//cout<<sa[4]<<endl;
					//invalid operation
	
	SafeArray sa2(5);
	sa2=sa;
	
	cout<<"Displaying the values of sa2"<<endl;
	cout<<sa2;
	
	cout<<"The size of SA2 is ="<<sa2.getSize()<<endl;
	
	sa[10]=4;
	
	//cout<<sa2[0]<<endl;
	//cout<<sa2[1]<<endl;
	//cout<<sa2[2]<<endl;
	//cout<<sa2[3]<<endl;
	//cout<<sa2[4]<<endl;
	return 0;	
}


