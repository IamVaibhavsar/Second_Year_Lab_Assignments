/*
Write C/C++ program for storing matrix. Write functions for
a) Check whether given matrix is upper triangular or not
b) Compute summation of diagonal elements
c) Compute transpose of matrix
d) Add, subtract and multiply two matrices*/

#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

void read(int mat[10][10], int row,int column);
void display(int mat[10][10], int row,int column);
void add(int mat1[10][10],int mat2[10][10],int n,int z);
void subtract(int mat1[10][10],int mat2[10][10],int n,int z);
void multiply(int mat1[10][10],int mat2[10][10],int r, int c);
void transpose(int mat1[10][10],int r,int c);
void sumd(int mat[10][10],int row ,int column);
void upper(int mat[10][10],int row ,int column);

int main()
{
	int ch,r1,c1,r2,c2;
	char ans;
	int mat1[10][10],mat2[10][10],c[10][10];
	
	cout<<"Enter the Rows and Columns of first matrix:"<<endl;
	cin>>r1>>c1;
	cout<<"Enter the Rows and Columns of second matrix:"<<endl;
	cin>>r2>>c2;
	
	cout<<"Enter the elements of first matrix:"<<endl;
	read(mat1,r1,c1);
	cout<<"Enter the elements of second matrix:"<<endl;
	read(mat2,r2,c2);
	

	do
	{
		cout<<"*********************WELCOME TO MATRIX OPERATIONS***********************"<<endl;
		cout<<"The available choices are as follows:"<<endl;
		cout<<"1.Addition of 2 Matrices."<<endl;
		cout<<"2.Subtraction of 2 Matrices."<<endl;
		cout<<"3.Multiplication of 2 Matrices."<<endl;
		cout<<"4.Transpose of a matrix"<<endl;
		cout<<"5.Sum of Diagonal of a matrix"<<endl;
		cout<<"6.To check the matrix tringular or not."<<endl;
		cout<<"7.Exit"<<endl;
			
		cout<<"Enter your Choice:"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"The First matrix is:"<<endl;
				display(mat1,r1,c1);
				cout<<"The second matrix is:"<<endl;
				display(mat2,r2,c2);
				add(mat1,mat2,r1,c1);
				break;
				
			case 2:
				cout<<"The First matrix is:"<<endl;
				display(mat1,r1,c1);
				cout<<"The second matrix is:"<<endl;
				display(mat2,r2,c2);
				subtract(mat1,mat2,r1,c1);
				break;
				
			case 3:
				cout<<"The First matrix is:"<<endl;
				display(mat1,r1,c1);
				cout<<"The second matrix is:"<<endl;
				display(mat2,r2,c2);
				multiply(mat1,mat2,r1,c1);
				break;
				
			case 4:
				cout<<"The First matrix is:"<<endl;
				display(mat1,r1,c1);
				cout<<"The Transpose of first matrix is:"<<endl;
				transpose(mat1,r1,c1);
				cout<<"The second matrix is:"<<endl;
				display(mat2,r2,c2);
				cout<<"The Transpose of second matrix is:"<<endl;
				transpose(mat2,r2,c2);
				break;
				
			case 5:
				cout<<"The First matrix is:"<<endl;
				display(mat1,r1,c1);
				sumd(mat1,r1,c1);
				cout<<"The second matrix is:"<<endl;
				display(mat2,r2,c2);
				sumd(mat2,r2,c2);
				break;
				
			case 6:
				cout<<"The First matrix is:"<<endl;
				display(mat1,r1,c1);
				upper(mat1,r1,c1);
				cout<<"The second matrix is:"<<endl;
				display(mat2,r2,c2);
				upper(mat2,r2,c2);
				break;
				
			case 7:exit(0);
			
			
		}
		cout<<"\nDo you want to Continue (Y/N)"<<endl;
		cin>>ans;
	}while(ans=='Y'||ans=='y');
	return 0;
}

void read(int mat[10][10], int row,int column)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cin>>mat[i][j];
		}
	}

}

void display(int mat[10][10], int row,int column)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void add(int mat1[10][10],int mat2[10][10],int n,int z)
{
	int i,j,sum[10][10];
	cout<<"sum of matrix is:"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<z;j++)
		{
			sum[i][j]=mat1[i][j]+mat2[i][j];
			cout<<sum[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void subtract(int mat1[10][10],int mat2[10][10],int n,int z)
{
	int i,j,sub[10][10];
	cout<<"subtraction of matrix is:"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<z;j++)
		{
			sub[i][j]=mat1[i][j]-mat2[i][j];
			cout<<sub[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void multiply(int mat1[10][10],int mat2[10][10],int r, int c)
{
    int mul[10][10],k;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            mul[i][j]=0;
            for(int k=0;k<r;k++)
            {
                mul[i][j]=mul[i][j]+(mat1[i][k]*mat2[k][j]);
            }
        }
    }
    cout<<"Multiplication of matrix is:"<<endl;
    display(mul,r,c);
}

void transpose(int mat1[10][10],int r,int c)
{
    for(int i=0;i<r;i++)
	{
	    for(int j=0;j<c;j++)
        {
            cout<<mat1[j][i]<<"\t";
        }
        cout<<"\n";
    }
}

void sumd(int mat[10][10],int row ,int column)
{
	int sumdia=0;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				if(i==j)
					sumdia=sumdia+mat[i][j];
			}
		}
	cout<<"The sum of diagonal elements is = "<<sumdia<<endl;
}


void upper(int mat[10][10],int row ,int column)
{
	int count=0;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				if((i>j)&&(mat[i][j]!=0))
					count++;
			}
		}
	if(count==0)
		cout<<"Matrix is upper triangular : "<<endl;
	else
		cout<<"Matrix is NOT upper triangular : "<<endl;

}
















