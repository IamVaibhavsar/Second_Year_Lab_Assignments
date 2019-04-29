/*Write a menu driven program that will create a data file containing the list of telephone numbers in the following form 
John 23456 
Ahmed 9876 
Use a class object to store each set of data, access the file created and implement the following tasks 
I. Determine the telephone number of specified person 
II. Determine the name if telephone number is known 
III. Update the telephone number, whenever there is a change.
*/


#include<iostream>
#include<fstream>
using namespace std;
class customer
{
public :
	char name[20];
	long int tel_no;
	void read();
	void display();
};
void customer :: read()
{
cout<<"\n Enter the name of the customer : ";
cin>>name;
cout<<"\n Enter the Telephone Number of the custome : ";
cin>>tel_no;	
}
void customer :: display()
{
cout<<"\n Customer Name    : "<<name;
cout<<"\n Telephone Number : "<<tel_no; 
}
int main()
{
customer c1;
int n,i,n1,n2;
int choice,search;
do
{
cout<<"\n Enter your choice tha what you want to do : ";
cout<<"\n1. Write in file : ";
cout<<"\n2. Read a file : ";
cout<<"\n3. Search a Telephone Number : ";
cout<<"\n4. Modify the number :";
cout<<"\n4. For exit....... ";

cin>>choice;


fstream obj;
switch(choice)
{
	case 1 : 
		obj.open("file.txt",ios :: app);
		cout<<"\n Enter the number of the customer : ";
		cin>>n;
		for(i=0;i<n;i++)
			{
			c1.read();
			obj.write((char *)&c1,sizeof(c1));
			}
		obj.close();
		break;
	case 2 :
		obj.open("file.txt",ios :: in|ios ::out|ios ::app);
		while(obj.read((char*)&c1,sizeof(c1)))
			{
			c1.display();
			}
		obj.close();
		break;
	case 3 :
		obj.open("file.txt",ios :: in|ios ::out|ios ::app);
		cout<<"\n Enter the number to be searched : ";
		cin>>search;
		while(obj.read((char*)&c1,sizeof(c1)))
		{
		if(c1.tel_no==search)
			{
			c1.display();	
			} 
		}
		obj.close();
		break;
	case 4 :
		cout<<"\n Enter the number to be change : ";
		cin>>n1;
		obj.open("file.txt",ios :: in|ios ::out);
		//obj.seekg(0,ios :: cur);
		while(obj.read((char*)&c1,sizeof(c1)))
			{
			if(c1.tel_no==n1)
				{
				obj.seekp(-1*sizeof(c1),ios :: cur);
				cout<<"\n Enter the name of the student :";
				cin>>c1.name;
				cout<<"\n Enter the telephone number : ";
				cin>>c1.tel_no;
				obj.write((char*)&c1,sizeof(c1));
				}
			}
		obj.close();
		break;
	case 5 :
		{
		cout<<"\n Enter the number to be deleted : ";
		cin>>n2;
		fstream f;
		obj.open("file.txt",ios::in|ios ::out);
		f.open("vaibhav.txt",ios::in|ios ::out);
		while(obj.read((char *)&c1,sizeof(c1)))
			{
			if(c1.tel_no==n2)
				{
				continue;
				}
			else
				{
				f.write((char*)&c1,sizeof(c1));	
				}	
			f.write((char*)&c1,sizeof(c1));	
			c1.display();
			}	
		}
		break;	
	default :
		cout<<"\n Please,Enter the valid option :";
		
}

}while(choice<6);
return 0;
}
