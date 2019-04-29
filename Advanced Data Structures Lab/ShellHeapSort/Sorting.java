/*Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell data
structure with modularity of programming language*/


import java.io.*;
import java.util.*;

class Sort 
{
	public static void main(String[] args) throws IOException
	{
		DataInputStream s=new DataInputStream(System.in);
		int iArr[]=new int[50];
		int iN,i,iGap,iFlag,iTemp,iCh;
		System.out.println("   HEAP AND SHELL SORT");
		System.out.println();	
		iN=read_array(iArr);
		System.out.println("-----------------------");
		System.out.println("\tMENU");
		System.out.println("-----------------------");
		System.out.println("1.Heap sort\n2.Shell sort\n3.Exit");
		System.out.println("-----------------------");
		System.out.println("Enter you choice : ");
		iCh=Integer.parseInt(s.readLine());
		switch(iCh)
		{
			case 1:	shellsort(iArr,iN);
					System.out.println("\nThe shell sorted array is : ");		
					for(i=0;i<iN;i++)
					{
						System.out.println(+iArr[i]);
					}
					break;
			
			case 2:	heapsort(iArr,iN);
					System.out.println("\nThe heap sorted array is : ");
					for(i=0;i<iN;i++)
					{
						System.out.println(+iArr[i]);
					}
					break;
					
			case 3:	System.exit(0);
					break;
					
			default:System.out.println("INVALID choice!");						
		}			
	}
	
	public static int read_array(int iArr[])throws IOException
	{
		int iN,i;
		DataInputStream a= new DataInputStream(System.in);
		System.out.println("\nEnter the size of the array : ");
		iN=Integer.parseInt(a.readLine());
		System.out.println("\nEnter the elements of array : ");
		for(i=0;i<iN;i++)
		{
			iArr[i]=Integer.parseInt(a.readLine());
		}
		return iN;		
	}
	
	public static void display_array(int iArr[], int iN)
	{
		int i;
		System.out.println("\nThe elements of array are : ");
		for(i=0;i<iN;i++)
		{
			System.out.println(+iArr[i]);
		}
	}
	
	public static void reheap_down(int i,int x,int Array[])
	{
		int j,temp;
		while(2*i+1<x)
		{
			j=2*i+1;
			if(j+1<x && Array[j]<Array[j+1])
				j=j+1;
			if(Array[i]>Array[j])
				break;
					
			temp=Array[i];
			Array[i]=Array[j];
			Array[j]=temp;
			i=j;
		}
	}
		
	
	public static void heapsort(int Array[],int n)
	{	
		int z=n,temp;
		for(int i=(z-1)/2;i>=0;i--)
			reheap_down(i,z,Array);
		while(z>0)
		{	
			temp=Array[0];
			Array[0]=Array[z-1];
			Array[z-1]=temp;
			z--;
			reheap_down(0,z,Array);	
		}
	
	}
	
	public static void shellsort(int iArr[], int iN)
	{
		int iGap,iFlag,i,iTemp;
		iGap=iN/2;
		do
		{
			do
			{
				iFlag=0;
				for(i=0;i<iN-iGap;i++)
				{	
					
					if(iArr[i]>iArr[i+iGap])
					{
						iTemp=iArr[i];
						iArr[i]=iArr[i+iGap];
						iArr[i+iGap]=iTemp;
						iFlag=1;
					}
				}
			}while(iFlag==1);
		}while((iGap=iGap/2)>=1);
	}
}


