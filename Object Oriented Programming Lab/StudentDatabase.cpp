/*
Develop an object oriented program in C++ to create a database of student information system containing the following information: 
Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone number, driving license no. etc 
Construct the database with suitable member functions for initializing and destroying the data viz constructor, default constructor, Copy constructor, destructor, 
static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete.*/

#include <iostream>
#include<string.h>
using namespace std;
class student
{
	public:
	int roll_no;	
	char clas[10];
	int sr_no;
	long int tele_no;
	char name[20];
	char div;
	char blood_grp;
	char DOB[10];
	static int count;
	

	void getdata();
	friend void display(student & obj);

	student()  //Constructor

	{
		roll_no=0;
		cout<<"\tConstructor";
		roll_no=count;
		count++;
	}
	~student()  //Destructor
	{
		cout<<"\nDestructor";
		cout<<"\nDestroying the object";
		count--;
	}
	student(int roll_no)
	{
		this->roll_no=roll_no;
	}

	student (student & obj)

	{
		roll_no=obj.roll_no;
		strcpy(name,obj.name);
		strcpy(DOB,obj.DOB);
		strcpy(clas,obj.clas);
		blood_grp=obj.blood_grp;
		div=obj.div;
		tele_no=obj.tele_no;
		sr_no=count;
		count++;
	}
};
	int student :: count=0;
	void student:: getdata()
	{
		cout<<"\n"<<"Enter the roll number of the student:";
		cin>>roll_no;

		cout<<"\n"<<"Enter the name of the student:";
		cin>>name;

		cout<<"\n"<<"Enter the date of birth of the student:";
		cin>>DOB;

		cout<<"\n"<<"Enter the blood group of the student:";
		cin>>blood_grp;

		cout<<"\n"<<"Enter the class of the student:";
		cin>>clas;

		cout<<"\n"<<"Enter the division of the student:";
		cin>>div;

		cout<<"\n"<<"Enter the contact of the student:";
		cin>>tele_no;
	}
	void display(student & obj)
	{
		cout<<"\n"<<obj.roll_no;
		cout<<"\t"<<obj.name;
		cout<<"\t"<<obj.DOB;
		cout<<"\t"<<obj.blood_grp;
		cout<<"\t"<<obj.clas;
		cout<<"\t"<<obj.div;
		cout<<"\t"<<obj.tele_no;
		
	}
		
int main()
{

	student s1;
	student s2(s1);
	cout<<"\n Enter the details of a student:"<<"\n";
	s1.getdata();

	cout<<"All data is as displayed below:"<<"\n";
	cout<<"\n---------------------------------------------------------------------";
	cout<<"\nROLL NUMBER\tNAME\tDOB\tBLOOD GRP\tCLASS\tDIVISION\tCONTACT NUMBER";
	display(s1);
cout<<"\n---------------------------------------------------------------------";

	int i,n;

	student *s[50];
	cout<<"\nEnter how many student object do you want us to create?"<<"\n";
	cin>>n;

	for(i=0;i<n;i++)
	{
		s[i]= new student();
	}

	for(i=0;i<n;i++)
	{
		s[i]->getdata();
	}
	
	
	for(i=0;i<n;i++)
	{
		display(*s[i]);
	}
	
	for(i=0;i<n;i++)
	{
		delete (s[i]);
	}
	return 0;
}

