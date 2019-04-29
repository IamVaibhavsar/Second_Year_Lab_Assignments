/*
Write C++ program for sparse matrix realization and operations on it- Transpose, Fast Transpose and addition of two matrices*/


#include<iostream>
using namespace std;
class spmatrix
{
	public:
	int a[20][3],strans[20][3],ftrans[20][3],add[20][3];
	void read()
	{
		cout<<"\nEnter the number of rows of matrix"<<endl;
		cin>>a[0][0];
		cout<<"\nEnter the number of columns of matrix"<<endl;
		cin>>a[0][1];
		cout<<"\nEnter the total number of non zero elements of matrix"<<endl;
		cin>>a[0][2];
		cout<<"\nEnter the elements of matrix in (row no,col no,value) form"<<endl;
		for(int i=1;i<=a[0][2];i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
	}
	void display(int b[20][3])
	{
		cout<<"\n";
		for(int i=0;i<=b[0][2];i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<b[i][j]<<"\t";
			}
		cout<<"\n";
		}
	}
	
	
	void stranspose()
	{
		strans[0][0]=a[0][1];
		strans[0][1]=a[0][0];
		strans[0][2]=a[0][2];
		if(strans[0][2]!=0)
		{
			int i=1;
			for(int j=0;j<strans[0][0];j++)
			{
				for(int k=1;k<=a[0][2];k++)
				{
					if(a[k][1]==j)
					{
						strans[i][0]=a[k][1];
						strans[i][1]=a[k][0];
						strans[i][2]=a[k][2];
						i++;
					}
				}
			}
			cout<<"\nThe new matrix is as follows:"<<endl;
			display(strans);
		}
			
	}
	
	
	void ftranspose()
	{
		int freq[20],row_start_pos[20];
		ftrans[0][0]=a[0][1];
		ftrans[0][1]=a[0][0];
		ftrans[0][2]=a[0][2];
		if(ftrans[0][2]!=0)
		{
			for(int i=0;i<ftrans[0][0];i++)
			{
				freq[i]=0;
			}
			for(int i=1;i<=ftrans[0][2];i++)
			{
				freq[a[i][1]]++;
			}
			row_start_pos[0]=1;
			for(int i=1;i<ftrans[0][0];i++)
			{
				row_start_pos[i]=row_start_pos[i-1]+freq[i-1];
			}
			int k=0;
			for(int i=1;i<=ftrans[0][2];i++)
			{
				k=row_start_pos[a[i][1]];
				ftrans[k][0]=a[i][1];
				ftrans[k][1]=a[i][0];
				ftrans[k][2]=a[i][2];
				row_start_pos[a[i][1]]++;
			}
			cout<<"\nThe new matrix is as follows:"<<endl;
			display(ftrans);
		}
	}
	void addm(spmatrix m)
	{
		int i=1,j=1,k=1;
		if(a[0][0]==m.a[0][0]&&a[0][1]==m.a[0][1])
		{
			add[0][0]=a[0][0];
			add[0][1]=a[0][1];
			while(i<=a[0][2]&&j<=m.a[0][2])
			{
				if(a[i][0]==m.a[j][0])
				{
					if(a[i][1]==m.a[j][1])
					{
						add[k][0]=a[i][0];
						add[k][1]=a[i][1];
						add[k][2]=a[i][2]+m.a[j][2];
						i++;
						j++;
						k++;
					}
					else if(a[i][1]<m.a[j][1])
					{
						add[k][0]=a[i][0];
						add[k][1]=a[i][1];
						add[k][2]=a[i][2];
						i++;
						k++;
					}
					else
					{
						add[k][0]=m.a[j][0];
						add[k][1]=m.a[j][1];
						add[k][2]=m.a[j][2];
						j++;
						k++;
					}
				}
				else if(a[i][0]<m.a[j][0])
				{
					add[k][0]=a[i][0];
					add[k][1]=a[i][1];
					add[k][2]=a[i][2];
					i++;
					k++;
				}
				else
				{
					add[k][0]=m.a[j][0];
					add[k][1]=m.a[j][1];
					add[k][2]=m.a[j][2];
					j++;
					k++;
				}
			}
			while(i<=a[0][2])
			{
				add[k][0]=a[i][0];
				add[k][1]=a[i][1];
				add[k][2]=a[i][2];
				i++;
				k++;
			}
			while(j<=m.a[0][2])
			{
				add[k][0]=m.a[j][0];
				add[k][1]=m.a[j][1];
				add[k][2]=m.a[j][2];
				j++;
				k++;
			}
			add[0][2]=k-1;
			cout<<"\nThe new matrix is as follows:"<<endl;
			display(add);
		}
		else 
		cout<<"\nAddition is not possible";
	}
};
int main()
{
	spmatrix s1,s2;
	int ch=0;
	char c=' ';
	do
	{
		cout<<"\nEnter 1:Addition of 2 sparse matrices,2:Simple Transpose of a sparse matrix,3:Fast Transpose of a sparse matrix"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			s1.read();
			s2.read();
			s1.addm(s2);
			break;1
			case 2:
			s1.read();
			s1.stranspose();
			break;
			case 3:
			s1.read();
			s1.ftranspose();
			break;
			default:
			cout<<"Invalid input";
		}
		cout<<"\nDo you wish to continue?(Y/N)"<<endl;
		cin>>c;
	}while(c=='Y'||c=='y');
	return 0;
}
