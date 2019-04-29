
/*
Write C++ program using STL for Sorting and searching with user-defined records such as Person Record (Name, birth date, telephone no), 
item record (item code, item name, quantity and cost)
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<list>
using namespace std;

typedef struct rec
{
	char item_name[20];
	int item_code;
	int quantity;
	float cost;
}node;

	node temp;
	list < node > lst;
	list < node > ::iterator ptr;
	bool operator <(node &p,node &q)
	{
		if(p.item_code<q.item_code)
			return true;
		else 
			return false;
	}
	
	void Create()
	{
		int n,i;
		cout<<"\n How many elements you want to insert?"<<endl;
		cin>>n;
		cout<<"\n Enter the Elements in the List"<<endl;
		for(i=0;i<n;i++)
		{
			cout<<"\n Item code:";
			cin>>temp.item_code;
			cout<<"\n Item Name:";
			cin>>temp.item_name;
			cout<<"\n Quantity:";
			cin>>temp.quantity;
			cout<<"\n Cost:";
			cin>>temp.cost;
			lst.push_back(temp);
		}
	}
	
	void Display()
	{
		cout<<"\n\t The contents of the List are:";
		cout<<"\n******************************************************";
		cout<<"\n Item Code		Item Name		Quantity		Cost";
		cout<<"\n*******************************************************";
		for(ptr=lst.begin();ptr!=lst.end();ptr++)
		{
			cout<<"\n";
			cout<<"	"<<(*ptr).item_code;
			cout<<"		"<<(*ptr).item_name;
			cout<<"		"<<(*ptr).quantity;
			cout<<"		"<<setw(4)<<(*ptr).cost;
		}
	}

	void Searching()
	{
		int key;
		int flag=0;
		cout<<"\n Enter the element which you want to search";
		cin>>key;
		for(ptr=lst.begin();ptr!=lst.end();ptr++)
		{
			if((*ptr).item_code==key)
			{
				flag=1;
				break;
			}
			else
				flag=0;
		}
		if(flag==1)
			cout<<"\n The desired element is present in the list";
		else 
			cout<<"\n The desired element is not present in the list";
	}
	
	void Sorting()
	{
		lst.sort();
		cout<<"\n\n Record is Sorted!!!"<<endl;
	}
	
	int main()
	{
		char ans='y';
		int choice;
		cout<<"\n Program for Searching and sorting";
		do
		{
			cout<<"\n Main Menu ";
			cout<<"\n 1. Create a list";
			cout<<"\n 2. Display a list";
			cout<<"\n 3. Search particular element";
			cout<<"\n 4. Sort the list";
			cout<<"\n Enter your choice";
			cin>>choice;
			switch(choice)
			{
				case 1:
					Create();
					break;
				
				case 2:
					Display();
					break;
				
				case 3:
					Searching();
					break;
		
				case 4:
					Sorting();
					Display();
					break;
			}
				cout<<"\n Do you want to go back to Main Menu?";
				cin>>ans;
		}while(ans=='y');
		return 0;
	}
