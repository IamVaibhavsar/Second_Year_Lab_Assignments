
/*
An m x n matrix is said to have a saddle point if some entry a[i][j] is the smallest value in row i and the largest value in j. 
Write C/ C++ function that determines the location of a saddle point if one exists.
*/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class matrix
{
	private:
		int a[5][5],b[5][5],c[5][5],m,n;
	public:
		void getA();
		void putA();
		void saddlePoint();
		void order();
};

void matrix :: order()
{
		cout<<"\nEnter number of rows and columns";
		cin>>m>>n;
}

void matrix::getA()
{
	order();
	cout<<"Enter the matrix for which you want to find saddle point: "<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
}

void matrix::putA()
{
	//order();
	cout<<"Entered Matrix is:"<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}



void matrix::saddlePoint()
{
	int pos[2][2],min,max;
	int i,j,k;
	for(i=0;i<n;i++){
		min=a[i][0];
		for(j=0;j<n;j++){
			if(min>=a[i][j])
			{
				min=a[i][j];
				pos[0][0]=i;
				pos[0][1]=j;
			}
		}
		j=pos[0][1];
		max=a[0][j];
		for(k=0;k<n;k++)
		{
			if(max<=a[k][j])
			{
				max=a[i][j];
				pos[1][0]=k;
				pos[1][1]=j;
			}
		}
		//min of row and max of column
		if(min==max)
		{
			if(pos[0][0]==pos[1][0] && pos[0][1]==pos[1][1])
				cout<<"\nSaddle point at ( "<<pos[0][0]<<","<<pos[0][1]<<") = "<<max<<endl;;
		}
	}
}



int main()
{
	matrix mat;
	mat.getA();
	mat.putA();
	mat.saddlePoint();
	return 0;
}
