/*
Write C++ program for storing appointment schedule for day. Appointments are booked randomly using linked list. Set start and end time and min and max duration for visit slot. Write functions for-
a) Display free slots
b) Book appointment
c) Cancel appointment ( check validity, time bounds, availability etc)
d) Sort list based on time
e) Sort list based on time using pointer manipulation*/

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

struct node
{
	int no;
	int start,end,time;
	bool status;
	node *prev,*next;
	node()
	{
		prev=next=NULL;
		no=0;
	}
};

class appt
{
	protected:
		node *head,*tail;
	public:		
		appt()
		{
			head=tail=NULL;
		}
		void create(int n,int t);
		void display();
		void traverse(int n);
		void display_status();
		void cancel(int n);
};

void appt :: create(int n,int t)
{
	node *curr,*temp;
	for(int i=0;i<n;i++)
	{
		curr=new node;
		curr->no=i+1;
		curr->time=t;
		curr->status=0;
		if(head==NULL)
		{
			head=curr;
			temp=curr;
			curr->start=00;
			curr->end=curr->start+60/n;
		}
		else
		{
			curr->start=temp->end;
			curr->end=curr->start+60/n;
			temp->next=curr;
			curr->prev=temp;
			temp=curr;	
		}
	
	}
	tail=curr;
}

void appt :: display()
{
	node *curr;
	curr=head;
	cout<<"\n\n----------------------------------------------------------";
	cout<<"\n   Appointment No.\t Timing\t\t       Status\n-----------------------------------------------------------\n";
	while(curr!=NULL)
	{
		if(curr->status==0)
		{
			
			cout<<"\n\t"<<curr->no<<"\t\t"<<curr->time<<":"<<curr->start<<"-"<<curr->time<<":"<<curr->end<<"\t\tFree";
		}
		else
		{
			cout<<"\n\t"<<curr->no<<"\t\t"<<curr->time<<":"<<curr->start<<"-"<<curr->time<<":"<<curr->end<<" \t\tBooked";
		}
		curr=curr->next;
	}
	cout<<"\n---------------------------------------------------------------------";
}

void appt :: traverse(int n)
{
	node *curr;
	curr=head;
	while(curr!=NULL)
	{
		if(curr->no==n)
		{
			curr->status=1;
			break;
		}
		curr=curr->next;
	}
}

void appt :: display_status()
{
	node *curr;
	curr=head;
	cout<<"\n\n----------------------------------------------------------";
	cout<<"\n   Appointment No.\t Timing\t\t       Status\n-----------------------------------------------------------\n";
	while(curr!=NULL)
	{
		if(curr->status==0)
		{
			
			cout<<"\n\t"<<curr->no<<"\t\t"<<curr->time<<":"<<curr->start<<"-"<<curr->time<<":"<<curr->end<<"\t\tFree";
		}
		else
		{
			cout<<"\n\t"<<curr->no<<"\t\t"<<curr->time<<":"<<curr->start<<"-"<<curr->time<<":"<<curr->end<<" \t\tBooked";
		}
		curr=curr->next;
	}
	cout<<"\n---------------------------------------------------------------------";
}

void appt :: cancel(int n)
{
	node *curr;
	curr=head;
	while(curr!=NULL)
	{
		if(curr->no==n)
		{
			curr->status=0;
			cout<<"\nNumber:"<<curr->no;
			cout<<"\nAppointment cancelled";
			break;
		}
		curr=curr->next;
	}
}

int main()
{
	appt a;
	int ch,n,m;
	do
	{
		cout<<"\n1.Create appointment schedule.\n2.Display schedule.\n3.Display slot status.\n4.Book appointment.\n5.Cancel appointment.\n6.Exit.\nEnter choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"\nEnter the time when doctor is available : ";
					cin>>n;
					cout<<"\nEnter the no of slots to be made : ";
					cin>>m;
					a.create(m,n);
					break;
					
			case 2:	cout<<"\nDisplaying appointment schedule : \n";
					a.display();
					break;
					
			case 3:	cout<<"\n------------SLOT STATUS-------------";
					a.display_status();
					break;
					
			case 4:	cout<<"\n------------SLOT STATUS-------------";
					a.display_status();	
					cout<<"\nEnter the appointment no to be booked : ";
					cin>>m;
					a.traverse(m);
					break;
					
			case 5:	cout<<"\n------------SLOT STATUS-------------";
					a.display_status();	
					cout<<"\nEnter the appointment to be cancelled : ";
					cin>>n;
					a.cancel(n);
					break;
					
			case 6:	exit(0);
			
			default:	cout<<"\nEnter valid choice!";
		}
	}while(ch!=6);
	
return 0;
}
