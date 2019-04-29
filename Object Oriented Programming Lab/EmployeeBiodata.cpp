
/*Create employee bio-data using following classes i) Personal record ii))Professional record  iii) Academic record.
Assume appropriate data members and member function to accept required data & print bio-data. Create bio-data using multiple inheritance using C++.*/

#include <iostream>
#include<iomanip>
using namespace std;
class personal
{
protected:
	char name[20];
	char addr[50];
	char dob[10];
	char gender;
public:

	void getpersonal();
};

class professional
{
protected:
	char org_name[20];
	char proj_name[20];
	char proj_details[20];
	int yr_exp;
public:

	void getprof();
};

class academic
{
protected:
	char Class[10];//!st class, distinction
	int year;//passout year
	char degree[10];//be btech,etc
	float perc;
public:

	void getacademic();
};

class biodata:public personal,public professional,public academic
{
public:

	void display();
};

void personal::getpersonal()
{
	cout<<"Enter your name ";
	cin>>name;
	cout<<"Enter your address ";
	cin.ignore(256,'\n');
	cin.getline(addr,50);
	cout<<"Enter your date of birth ";
	cin>>dob;
	cout<<"Enter your gender(m/f) ";
	cin>>gender;
}

void professional::getprof()
{
	cout<<"Enter your organization name ";
	cin.ignore(256,'\n');
	cin.getline(org_name,20);
	cout<<"Enter your project name ";
	//cin.ignore(256,'\n');
	cin.getline(proj_name,20);
	cout<<"Enter your project details ";
	//cin.ignore(256,'\n');
	cin.getline(proj_details,20);
	cout<<"Enter your years of experience ";
	cin>>yr_exp;
}

void academic::getacademic()
{
	cout<<"Enter your class(1st,distinction) ";
	cin>>Class;
	cout<<"Enter your year of passing out ";
	cin>>year;
	cout<<"Enter your degree(BE,BTech) ";
	cin>>degree;
	cout<<"Enter your percentage ";
	cin>>perc;
}

void biodata::display()
{
	cout<<"\nPersonal details:";
	cout<<left<<setw(25)<<"\n\tName: "<<name;
	cout<<left<<setw(25)<<"\n\tAddress: "<<addr;
	cout<<left<<setw(25)<<"\n\tDate of birth: "<<dob;
	cout<<left<<setw(25)<<"\n\tGender: "<<gender;
	cout<<"\nProfessional details:";
	cout<<left<<setw(25)<<"\n\tOrganization name: "<<org_name;
	cout<<left<<setw(25)<<"\n\tProject name:    "<<proj_name;
	cout<<left<<setw(25)<<"\n\tProject details: "<<proj_details;
	cout<<left<<setw(25)<<"\n\tYears of experience: "<<yr_exp;
	cout<<"\nAcademic details:";
	cout<<left<<setw(25)<<"\n\tClass: "<<Class;
	cout<<left<<setw(25)<<"\n\tYear of passing out: "<<year;
	cout<<left<<setw(25)<<"\n\tDegree: "<<degree;
	cout<<left<<setw(25)<<"\n\tPercentage: "<<perc<<"\n";
}

int main()
{
	biodata b;
	cout<<"\nEnter personal details:\n";
	b.getpersonal();
	cout<<"\nEnter professional details:\n";
	b.getprof();
	cout<<"\nEnter academic details:\n";
	b.getacademic();
	cout<<"\nThe details are:\n";
	b.display();
	return 0;
}

