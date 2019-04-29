/*There are flight paths between cities. If there is a flight between city A and city B then there is
an edge between the cities. The cost of the edge can be the time that flight takes to reach city
B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can
be represented by airport name or name of the city. Use adjacency LIST representation of the graph.*/

#include<bits/stdc++.h> 
#include<iostream>
using namespace std;
#define MAX 5
class node
{
	public:
			char city[20];
			node* next;
			float distance;
			node()
			{
				next=NULL;
			}
};
class link_graph
{	node* head[MAX];
	int n;
	public:
			void read_graph();
			void display();
};
void link_graph::read_graph()
{
	cout<<"Enter total number of vertices\n";
	cin>>n;
	char ans;
	node* curr;	
	for(int i=0;i<n;i++)
	{	
		cout<<"Enter the city name\n";
		head[i]=new node();
		cin>>head[i]->city;
		node* head_l=NULL;
		node* prev;
		cout<<"add city connected to "<<head[i]->city<<" (Y/n)?\n";
		cin>>ans;
		while(ans=='y'||ans=='Y')
		{	
			curr=new node();
			cout<<"Enter city name\n";
			cin>>curr->city;
			cout<<"Enter distance from of "<<curr->city<<" from "<<head[i]->city<<endl;
			cin>>curr->distance;
			if(head_l==NULL)			
			{	head_l=curr;
				prev=curr;
			
			}
			else
			{
				prev->next=curr;
				prev=curr;
			}
			
			cout<<"add city connected to "<<head[i]->city<<" (Y/n)?\n";
			cin>>ans;
		}			
		head[i]->next=head_l;	
	}
}
void link_graph::display()
{
	node* temp;
	cout<<" source "<<" destination "<<" distance \n";
	for(int i=0;i<n;i++)
	{	temp=head[i]->next;
		while(temp!=NULL)
		{	cout<<" "<<head[i]->city<<"   "<<temp->city<<"    "<<temp->distance<<endl;
			temp=temp->next;
		}
	}
}
int main()
{	link_graph g;
	g.read_graph();
	g.display();


}
