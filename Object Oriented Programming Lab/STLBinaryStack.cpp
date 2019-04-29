/*Write a C++ program using STL to add binary numbers(asssume one bit as one number.)*/

#include<iostream>
#include<stack>
using namespace std;
 
        
stack<int> read()
{
    	stack<int> s;
    	int x,n,i;
 
    	cout<<"Enter the no. of bits in the no. :"<<endl;
    	cin>>n;
    	cout<<"\nEnter the binary number : "<<endl;
 
    	for(i=0;i<n;i++)
      {
    		cin>>x;
    		s.push(x);
      }
    	return s;
}
      
 
void display(stack<int> &s)
{
    	cout<<"  ";
    	while(!s.empty())
      	{
    		cout<<s.top()<<" ";
    		s.pop();
      	}
}
        
stack<int> add(stack<int> &s1, stack<int> &s2)
{
    	stack<int> s;
    	int sum,carry=0,b1,b2;
 
    	while(!s1.empty()||!s2.empty())
      {
    		b1=b2=0;
    		if(!s1.empty())
      		{
        		b1=s1.top();
      			s1.pop();
    		}
    		if(!s2.empty())
      		{
        		b2=s2.top();
        		s2.pop(); 
      		}

    		sum=(b1+b2+carry)%2;
    		carry=(b1+b2+carry)/2; 
    		s.push(sum);
      }

    	if(carry==1)
      		s.push(1);
    	return s;
} 
int main()
{
    	stack<int> s1,s2,s3;
    	int ch;
 
    	cout<<"*******************MENU*************************"<<endl;
    	cout<<"The available choices are as follows: "<<endl;
		cout<<"1.To Read first number: "<<endl;
		cout<<"2.To Read second number: "<<endl;
    	cout<<"3.To add 2 binary numbers: "<<endl;
    	cout<<"4.Exit"<<endl;
 
	do
    	{
    		cout<<"\nEnter your choice: "<<endl;
    		cin>>ch;
 
    		switch(ch)
      		{
        		case 1:
           			s1=read();		//read function returns a stack
					cout<<"-------------------------------------------"<<endl;
           			break;
 
        		case 2:
          	 		s2=read();
					cout<<"-------------------------------------------"<<endl;
           			break;
 
        		case 3:
           			cout<<"\nThe result of addition is = "<<endl;
           			s3=add(s1,s2);
           			display(s3);
           			
				cout<<"\n-------------------------------------------"<<endl;
           			break;
      	}
      }while(ch!=4);
    return 0;
}

