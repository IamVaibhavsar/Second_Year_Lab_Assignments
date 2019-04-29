
/*Write C++ program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a) Selection Sort b) Bubble sort and display top five scores.*/

#include<iostream>
#include<iomanip>
using namespace std;
class student
{
	public:
	double a[20];
	int n;
	void get();
	void display();
	//void swap(double, double);
	void ss();
	void bs();
};
void student :: get()
{
	int i;
	cout<<"Enter the number of students in the class:"<<endl;
	cin>>n;
	cout<<"Enter the percentage of each student:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void student :: display()
{
	int i,j;
	double temp;
	cout<<"\nThe percentage of top 5 student is:"<<endl;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[i])
			{
				temp=a[i];	
				a[i]=a[j];
				a[j]=temp;
				//swap(&a[i],&a[j]);
			}
		}
	}
	for(i=0;i<5;i++)
	{
		cout<<setprecision(2)<<fixed<<"\n"<<a[i];
	}
}

/*void swap(double *a,double *b)
{
	double t=*a;
	*a=*b;
	*b=t;
}*/

void student :: ss()
{
	int i,j;
	double temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				//swap(&a[i],&a[j]);
			}
		}
	}
	cout<<"\nSorted list is:";
	for(i=0;i<n;i++)
	{
		cout<<setprecision(2)<<fixed<<"\n"<<a[i];
	}
}


void student :: bs()
{
	int i,j;
	double temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				//swap(&a[j],&a[j+1]);
			}
		}
	}
	cout<<"\nSorted list is:";
	for(i=0;i<n;i++)
	{
		cout<<setprecision(2)<<fixed<<"\n"<<a[i];
	}
}


int main()
{
	int ch;
	char an;
	student s;
	s.get();
	do
	{
		cout<<"1:Selection sort\n2:Bubble sorts\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.ss();
				s.display();
				break;
			case 2:
				s.bs();
				s.display();
				break;
			default:
				cout<<"\nInvalid choice\nPlease re-enter:";
				break;
		}
		cout<<"\nDo you want to continue?";
		cin>>an;
		
	}while(an=='y'||an=='Y');
	return 0;
}
/*
Enter the number of students in the class:5
Enter the percentage of each student:60
70
80
90
88
1:Selection sort
2:Bubble sorts
Enter your choice:1

Sorted list is:
60.00
70.00
80.00
88.00
90.00
The percentage of top 5  student is:
90.00
88.00
80.00
70.00
60.00
Do you want to continue?y
1:Selection sort
2:Bubble sorts
Enter your choice:2

Sorted list is:
60.00
70.00
80.00
88.00
90.00
The percentage of top 5  student is:
90.00
88.00
80.00
70.00
60.00
Do you want to continue?n
*/
