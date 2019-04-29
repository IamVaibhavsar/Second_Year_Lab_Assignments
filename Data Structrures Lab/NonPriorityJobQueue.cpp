
/*Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. 
If the operating system does not use priorities, then the jobs are processed in the order they enter the system. 
Write C++ program for simulating job queue. Write functions to add job and delete job from queue
*/

#include<iostream>
using namespace std;
#define size 10

class JobQue
{
	private:
		struct queue
		{
			int que[size];
			int front;
			int rear;
		}Q;
	public:
		JobQue();				//Constructor
		int Qfull();
		int insert(int);
		int Qempty();
		int Delete();
		void display();
};

JobQue::JobQue()					//Initializing the Job Queue
{
	Q.front=-1;
	Q.rear=-1;
}

int JobQue::Qfull()
{
	if(Q.rear>=size-1)
		return 1;
	else
		return 0;
}

int JobQue::insert(int item)
{
	if(Q.front==-1)
		Q.front++;
	Q.que[++Q.rear]=item;
		return Q.rear;
}

int JobQue::Qempty()
{
	if((Q.front==-1)||(Q.front>Q.rear))
		return 1;
		
	else
		return 0;
}

int JobQue::Delete()
{
	int item;
	item=Q.que[Q.front];
	Q.front++;
	
		cout<<"\n The deleted job is:"<<item;
			return Q.front;
}

void JobQue::display()
{
	int i;
	for(i=Q.front;i<=Q.rear;i++)
	cout<<" "<<Q.que[i];
}

int main()
{
	int ch,item;
	char ans;
	JobQue J;
	do
	{
		cout<<"\n Main Menu:";
		cout<<"\n 1.ADD Job\n 2.Delete Job\n 3.Display Job Queue:";
		cout<<"\n Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:	
				if(J.Qfull())		//Queue Overflow
					cout<<"\n Can not insert the job";
					
				else
				{
					cout<<"\n Enter the Job number:";
					cin>>item;
					J.insert(item);
				}
				break;
						
			case 2:	
				if(J.Qempty())		//Queue Underflow
					cout<<"\n Queue Underflow:";
					
				else 
					J.Delete();
				break;
						
			case 3:	
				if(J.Qempty())
					cout<<"\n Job Queue is Empty:";
					
				else
					J.display();
				break;
					
			default: 
				cout<<"\n Wrong Choice:";
					break;
		}
				
				cout<<"\n Do you want to continue?:";
				cin>>ans;
	}while(ans=='Y'||ans=='y');
	return 0;
}
		
	
					
