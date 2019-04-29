/*
Write C++ program to store second year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a) Insertion sort b) Shell Sort and display top five scores.*/

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
	void is();
	void shs();
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
	cout<<"\nThe percentage of top 5 student are:"<<endl;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	//cout<<"\nThe percentage of top 5 student are:"<<endl;
	for(i=0;i<5;i++)
	{
		cout<<setprecision(2)<<fixed<<"\n"<<a[i];
	}
}


void student :: is()
{
	int i,j;
	double element;
	for(i=1;i<n;i++)
	{
		element=a[i];
		j=i;
		while((a[j-1]>element)&&(j>0))
		{
		    a[j]=a[j-1];
		    j=j-1;
		}

		a[j]=element;
	}
	
	
	cout<<"\nSorted list is:";
	for(i=0;i<n;i++)
	{
		cout<<setprecision(2)<<fixed<<"\n"<<a[i];
	}
}


void student :: shs()
{
	double temp;
	int gap,i,swapped;
	gap=n/2;
	do
	{
		do
		{
			swapped=0;
			for(i=0;i<n-gap;i++)
			if(a[i] > a[i+gap])
			{
				temp=a[i];
				a[i]=a[i+gap];
				a[i+gap]=temp;
				swapped=1;
			}
		}while(swapped==1);
	}while((gap=gap/2)>=1);
	
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
		cout<<"1:Insertion sort\n2:Shell sorts\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
			s.is();
			s.display();
			break;
			case 2:
			s.shs();
			s.display();
			break;
			default:
			cout<<"\nInvalid choice\nPlease re-enter:";
			break;
		}
		cout<<"\nDo you want to continue?";
		cin>>an;
	}
	while(an=='y'||an=='Y');
	return 0;
}
/*
Enter the number of students in the class:6
Enter the percentage of each student:6
070
80
90
88
77
1:Insertion sort
2:Shell sorts
Enter your choice:1

Sorted list is:
6.00
70.00
77.00
80.00
88.00
90.00
The percentage of top 5  student is:
90.00
88.00
80.00
77.00
70.00
Do you want to continue?y
1:Insertion sort
2:Shell sorts
Enter your choice:2

Sorted list is:
6.00
70.00
77.00
80.00
88.00
90.00
The percentage of top 5  student is:
90.00
88.00
80.00
77.00
70.00
Do you want to continue?n
*/
