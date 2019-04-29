/*There are flight paths between cities. If there is a flight between city A and city B then there is
an edge between the cities. The cost of the edge can be the time that flight takes to reach city
B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can
be represented by airport name or name of the city. Use adjacency MATRIX representation of the graph.*/


#include<iostream>
#include <cstring>
#include <fstream>
#define m 100
using namespace std;

class graph
{
	public:
	int A[m][m],visited[m];
	int n;
	char city[m][20];
	graph()
	{
		int j;
		
		n=0;
		for(int i=0;i<m;i++)
			for(j=0;j<m;j++)
				A[i][j]=0;
				
				
	        strcpy(city[0],"Mumbai");
	        strcpy(city[1],"Nashik");
	        strcpy(city[2],"Pune");
	        strcpy(city[3],"Delhi");
	}
	
	void readgraph();
	void display();
	void dfs(int i);
	void init();
};

void graph::readgraph()
{
	int i,v1,v2,wh,n1;
	ifstream fp("xyz.txt");					//Taking data from the file xyz.txt
	
	cout<<"\nENTER THE NUMBER OF vertices : \n";
	fp>>n;
	cout<<"\nENTER THE NUMBER OF edges : \n";
	fp>>n1;
	cout <<"\n Enter edge \n";
	for(i=0;i<n1;i++)
	{
		cout<<"\nENTER THE VERTEX 1 :\n";
		fp>>v1;
		cout<<"\nENTER THE VERTEX 2 : \n";
		fp>>v2;
		cout<<"\nENTER THE WEIGHT : \n";
		fp>>wh;
		A[v1][v2]=wh;
		A[v2][v1]=wh;
	}
}


void graph::display()
{
    cout << "\n Graph is \n";
    for(int i=0;i<n;i++)
	{
	   cout << "\t" << city[i];
	}
	
	cout << "\n";
	
	for(int i=0;i<n;i++)
	{
	        cout << city[i]<<"\t";
		for(int j=0;j<n;j++)
		{
			
				cout<<A[i][j]<<"\t";
			
		}
		cout << "\n";
	}
}
void graph::init()
{
    
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
}
void graph::dfs(int i)
{
	
	
	visited[i]=1;
	cout<<"\t"<<i << "(" << city[i] << ")";
	for(int j=0;j<n;j++)
		{
			if(A[i][j]!=0)
			{
				if(visited[j]==0)
				{
			  		dfs(j);
				}
			}	
		}
}
int main()
{
	graph g;
	g.readgraph();
	g.display();
	g.init();
	cout << "\n DFS \n";
	g.dfs(0);
}
