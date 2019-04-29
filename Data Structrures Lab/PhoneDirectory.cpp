
/*
Write C++ program to store names and mobile numbers of your friends in sorted order on names. 
a) Search your friend from list using binary search (recursive and non recursive). Insert friend if not present in phonebook. 
b) Search your friend from list using Fibonacci search. Insert friend if not present in phonebook.*/


#include<iostream>
#define MAX 50
#include<string.h>
using namespace std;

int n;		//no of students declared as global variable.

struct student
{
	char name[MAX];
	char mob_no[11];
};

class record
{
	struct student S[MAX];
	public:
	void read_data();
	void disp_data();
	void bubble_sort();
	int seq_search(char nm[20]);
	int binary_search(char nm[20]);
	int rec_binary_search(int low,int high,char nm[20]);
	void insert(char nm[20]);
};

void record::read_data()
{
	int i;
	cout<<"\nEnter no.of students to read : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter name : ";
		cin.ignore();
		cin.getline(S[i].name,50);
		cout<<"\nEnter mobile no. : ";
		cin>>S[i].mob_no;
	}
}
void record::disp_data()
{
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<S[i].name<<"\t"<<S[i].mob_no<<"\n";
	}
}

int record::seq_search(char nm[20])
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(S[i].name,nm)==0)
		{
			flag=1;	
			break;
		}
	}
	if(flag==1)
		return i;		//(i+1)
	else
		return(-1);
}

void record::bubble_sort()
{
	student t;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(strcmp(S[j].name,S[j+1].name)>0)
			{
				t=S[j];
				S[j]=S[j+1];
				S[j+1]=t;
			}
		}
	}
}

int record::binary_search(char nm[20])
{
	int low=0;
	int high=n-1;
	int mid,flag=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(strcmp(S[mid].name,nm)==0)
		{
			flag=1;
			break;
		}
		else if(strcmp(S[mid].name,nm)<0)
			low=mid+1;
		else
			high=mid-1;
	}
	if(flag==1)
		return mid;
	else
		return(-1);
}

int record::rec_binary_search(int low,int high,char nm[20])
{
	int mid, flag=0;		//high=n-1
	while(low<=high)
	{
		mid=(low+high)/2;
		if(strcmp(S[mid].name,nm)==0)
		{
			flag=1;
			break;
		}
		else if(strcmp(S[mid].name,nm)<0)
			return rec_binary_search(mid+1,high,nm);
		
		else
			return rec_binary_search(low,mid-1,nm);
	}
	if(flag==1)
		return mid;
	else
		return(-1);
	
}

void record::insert(char nm[20])
{
	char m[11];

	strcpy(S[n].name,nm);
	cout<<"\nEnter mob no.";
	cin>>m;
	strcpy(S[n].mob_no,m);
	n++;

}
int main()
{
	record R;
	char nm[20];
	int p,ch;
	do
	{
		cout<<"\n\n1.read data\n2.display data\n3.bubble sort\n4.sequential search\n5.binary search\n6.recursive binary search\n7.Exit\n";
		cout<<"\nEnter the choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				R.read_data();
				break;
			case 2:
				R.disp_data();
				break;
			case 3:
				cout <<"\n After bubble sort : \n";
				R.bubble_sort();
				R.disp_data();
				break;
			/*case 4:
				cout<<"\nEnter name to be search : ";
				cin>>nm;
				p=R.seq_search(nm);
				if(p==-1)
				{
					cout<<"\nNot Found.\n";
					R.insert(nm);
					cout<<nm<<" is inserted in the directory.\n";
					R.bubble_sort();
				}				
				else
					cout<<"\nfound at "<<p<<"\n";
				break;*/
			case 5:
				R.bubble_sort();
				cout<<"\nSorted Details\n";
				R.disp_data();
				cout<<"\nEnter name to be search : ";
				cin>>nm;
				p=R.binary_search(nm);
				if(p==-1)
				{
					cout<<"\nNot Found.\n";
					R.insert(nm);
					cout<<nm<<" is inserted in the directory.\n";
					R.bubble_sort();
				}
				else
					cout<<"\nfound at "<<p+1<<"\n";		//p initially
				break;
			case 6:
				R.bubble_sort();
				cout<<"\nSorted Details\n";
				R.disp_data();
				cout<<"\nEnter name to be search : ";
				cin>>nm;
				p=R.rec_binary_search(0,n-1,nm);
				if(p==-1)
				{
					cout<<"\nNot Found.\n";
					 R.insert(nm);
					cout<<nm<<" is inserted in the directory.\n";
					R.bubble_sort();
				}
				else
					cout<<"\nfound at "<<p+1<<"\n";		//p initially
				break;
			default :
				cout<<"\nProgram Exited.\n";
		}
	}while(ch<7);
	return 0;
}
	
	
	
	
	
	
	
