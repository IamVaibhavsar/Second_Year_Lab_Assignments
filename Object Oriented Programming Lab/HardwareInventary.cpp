/*
You are the owner of a hardware store and need to keep an inventory that can tell you what different tools you have, 
how many of each you have on hand and the cost of each one. 
Write a program that initializes the random-access file hardware.dat to 100 empty records, 
lets you input the data concerning each tool, enables you to list all your tools, 
lets you delete a record for a tool that you no longer have and lets you update any information in the file. 
The tool identification number should be the record number. 
Use the following information to start your file: 


 Tool name 
 Quantity 
 Cost 

 Tool name 
 Quantity 
 Cost 

Quantity    
 3 
 Electric sander 
 7 
 57.98 
  17 
 Hammer 
 76 
 11.99 
  24 
 Jig saw 
 21 
 11.00 
  39 
 Lawn mower 
 3 
 79.50 
  56 
 Power saw 
 18 
 99.99 
 
*/

#include<iostream>
#include<fstream>
#include<string.h>
#define max 30
using namespace std;

class item
{
	public:

	int no;
	char name[max];
	int qty;
	float cost;


	item()
	{   no=0;
		strcpy(name," ");
		qty=0;
		cost=0;
	}
	void read();
	void display();
};


void item::read()
{
	cout<<"\nEnter item no: ";
	cin>>no;
	cout<<"\nEnter Name: ";
	cin>>name;
	cout<<"\nEnter Quantity: ";
	cin>>qty;
	cout<<"\nEnter Cost: ";
	cin>>cost;

}

void item::display()
{
	{
		cout<<"\nItem number:"<<no;
		cout<<"\nName:"<<name;
		cout<<"\nQuantity:"<<qty;
		cout<<"\nCost:"<<cost<<endl;
	}
}

int main()
{
	fstream file;
	item obj;

	int choice;
	do
	{
	cout<<"****************MENU******************";
	cout<<"\n1.Create new file:\n2.Add record:\n3.Display\n4.Modify\n5.Delete";
	cout<<"\nEnter your choice:\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			file.open("item.dat",ios::binary |ios::in |ios::out | ios::ate |ios::trunc);
			for(int i=0;i<100;i++)
				file.write((char *)&obj, sizeof(obj));

			file.close();
			cout<<"\nNEW FILE SUCCESSFULLY CREATED\n";
			break;
		case 2:
			file.open("item.dat",ios::binary |ios::in |ios::out | ios::ate);
			obj.read();

			int wloc;
			wloc= (obj.no-1)*sizeof(obj);
			if(file.eof())
				file.clear();

			file.seekp(wloc);


			file.write((char *)&obj, sizeof(obj));
			file.close();
			break;
		case 3:
			file.open("item.dat",ios::binary |ios::in |ios::out | ios::ate);
			file.seekg(0,ios::beg);

			while(file.read((char *)&obj, sizeof(obj)))
			{
			     if(obj.no!=0)
				     obj.display();
			}
			file.close();
			break;
		case 4:
	     		file.open("item.dat",ios::binary |ios::in |ios::out | ios::ate);
			cout<<"\nEnter item no to be modified: ";
			int n;
			cin>>n;

			int loc;
			loc= (n-1)*sizeof(obj);
			if(file.eof())
				file.clear();

			file.seekp(loc);

			cout<<"\nENTER NEW DATA ";
			obj.read();

			file.write((char *)&obj, sizeof(obj));
			
			file.close();
			break;
		case 5:
			file.open("item.dat",ios::binary |ios::in |ios::out | ios::ate);
			cout<<"\nEnter item no to be deleted:";
			int d;
			cin>>d;

			int dloc;
			dloc= (d-1)*sizeof(obj);
			if(file.eof())
				file.clear();

			file.seekp(dloc);

			obj.no=0;
			strcpy(obj.name , " ");
			obj.qty=0;
			obj.cost=0;
			file.write((char *)&obj, sizeof(obj));
			file.close();

			break;
	}
	}while(choice<6);

	return 0;
}
/*OUTPUT
****************MENU******************
1.Create new file:
2.Add record:
3.Display
4.Modify
5.Delete
Enter your choice:
1

NEW FILE SUCCESSFULLY CREATED
****************MENU******************
1.Create new file:
2.Add record:
3.Display
4.Modify
5.Delete
Enter your choice:
2

Enter item no: 45    

Enter Name: Chesis

Enter Quantity: 34

Enter Cost: 567
****************MENU******************
1.Create new file:
2.Add record:
3.Display
4.Modify
5.Delete
Enter your choice:
2

Enter item no: 67   

Enter Name: Wheel

Enter Quantity: 5

Enter Cost: 50
****************MENU******************
1.Create new file:
2.Add record:
3.Display
4.Modify
5.Delete
Enter your choice:
3

Item number:45
Name:Chesis
Quantity:34
Cost:567

Item number:67
Name:Wheel
Quantity:5
Cost:50
****************MENU******************
1.Create new file:
2.Add record:
3.Display
4.Modify
5.Delete
Enter your choice:
4

Enter item no to be modified: 67

ENTER NEW DATA 
Enter item no: 
67

Enter Name: Grease

Enter Quantity: 5

Enter Cost: 45
****************MENU******************
1.Create new file:
2.Add record:
3.Display
4.Modify
5.Delete
Enter your choice:
3

Item number:45
Name:Chesis
Quantity:34
Cost:567

Item number:67
Name:Grease
Quantity:5
Cost:45
****************MENU******************
1.Create new file:
2.Add record:
3.Display
4.Modify
5.Delete
Enter your choice:
5

Enter item no to be deleted:67
****************MENU******************
1.Create new file:
2.Add record:
3.Display
4.Modify
5.Delete
Enter your choice:
3

Item number:45
Name:Chesis
Quantity:34
Cost:567
****************MENU******************
1.Create new file:
2.Add record:
3.Display
4.Modify
5.Delete
Enter your choice:
6
*/

