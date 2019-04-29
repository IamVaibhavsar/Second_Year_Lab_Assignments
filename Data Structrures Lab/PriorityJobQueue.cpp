/*Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. 
If the operating system uses priorities, then the jobs are processed in the order they enter the system. 
Write C++ program for simulating job queue. Write functions to add job and delete job from queue
*/


#include<iostream>
using namespace std;
#define MAX 10
//const int MAX=5;

class Job
{
	int id;
	int priority;
	friend class Queue;		//Queue can access private members of class Job
public:
	void getdata()
	{
		cout<<"\nENter Job id: ";
		cin>>id;
		cout<<"\nENter Job priority: ";
		cin>>priority;
	}
	void putdata()
	{  
		cout<<"\n\t"<<id;
		cout<<"\t\t"<<priority;
	}
	
};

class Queue
{
	int front,rear;
	Job queue[MAX]; 
public:
	Queue()
	{
		front=-1;
		rear=-1;
	}
	bool isEmpty();
	bool isFull();
	void insert();
	void remove();
	void display();

};

bool Queue::isEmpty()
{
	if(front==(rear+1)||rear==-1)
	//if (front == rear)
		return 1;
	else 
		return 0;
}

bool Queue::isFull()
{
	if(rear==MAX-1)
	{
		return 1;
	}
	else
		return 0;
}

void Queue::insert()
{
	Job j;

	if(isFull())
	{
		cout<<"\nQueue is Full.";
	}
	else
	{
		j.getdata();
		if(rear==-1)//empty
		{
			front++;
			rear++;

			queue[rear]=j;
		}
		else
		{

			int i=rear;
			while((i>=front) && (queue[i].priority>j.priority)) 	//application of friend class
			{
				queue[i+1]=queue[i];
				i--;
			}
			queue[i+1]=j;
			rear++;
		}
		cout<<"\nJob Added To Queue."<<endl;
	}
}

void Queue::remove()
{
	if(isEmpty())
	{
		cout<<"\nQueue is Empty.";
	}
	else
	{
		front++;
		cout<<"\nJob Processed From Queue."<<endl;
	}
}

void Queue::display()
{
	if(isEmpty())
	{
		cout<<"\nQueue is Empty.";
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			queue[i].putdata();
		}
	}
}

int main()
{

	int ch;
	Queue q;

	do
	{

		cout<<"\n\n****MENU****\n";
		cout<<"1.Insert job\n";
		cout<<"2.Display jobs\n";
		cout<<"3.Remove job\n";
		cout<<"4.Exit\n";

		cout<<"Choice: ";
		cin>>ch;

		switch(ch)
		{

			case 1: 
				q.insert();
				break;

			case 2: 
				cout<<"\n\tJob id ";
				cout<<"\t  Job priority ";
				q.display();
				break;

			case 3: q.remove();
		}
	}while(ch!=4);
	return 0;
}
