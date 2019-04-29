/*Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell data
structure with modularity of programming language*/


import java.util.Scanner;
public class shell
{
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		int a[]=new int[50];
		int pass=1;
		int n,i,sum=0,avg=0,swap,temp;
		System.out.println("\nEnter size of array:");
		n=s.nextInt();
		System.out.println("\n Enter element of array:");
		for(i=0;i<n;i++)
		{
			a[i]=s.nextInt();
		}
		System.out.println("Elemets before Sorting:\n");
		for(i=0;i<n;i++)
		{
			System.out.println(+a[i]);
		}
		
		int gap=n/2;
		do
		{
			do
			{
				swap=0;
				for(i=0;i<(n-gap);i++)
				{
					if(a[i]>a[i+gap])
					{
						temp=a[i];
						a[i]=a[i+gap];
						a[i+gap]=temp;
						
						swap=1;
					}
				}
			}while(swap==1);
			
		
		
			System.out.println("pass: "+pass);
			for(i=0;i<n;i++)
			{
				System.out.println(+a[i]);
			}
			pass++;
		}while((gap=gap/2)>=1);
		
		System.out.println("Element after Sorting\n:");
		for(i=0;i<n;i++)
		{
			System.out.println(+a[i]);
		}
	}//end of main
}//end of class



