/*Write a program on template and exception handling in Java: in this assignment multiple
templates are to be designed as a pattern and these patterns to be used to take decisions.*/


import java.io.*;
import java.util.*;
import java.util.Scanner;

class MyException extends Exception
{
   	MyException(String b) 
	{
    		System.out.println("Enter data greater than zero!");
   	}
}

class e1 
{
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);
		int Arr[]=new int[2];
		int N;
		System.out.println("-------------------------------");
                
		
		N=read_array(Arr);
		display_array(Arr,N);
                
	}
	
	public static int read_array(int Arr[])
	{
		int N,i;
            Scanner a=new Scanner(System.in);
		System.out.println("\nEnter the size of the array : ");
		N=a.nextInt();

		while(N>2)
		{
			System.out.println("Array Size Exceeded.Maximum limit is 2");
			System.out.println("\nEnter the size of the array : ");
			N=a.nextInt();
		}

		System.out.println("\nEnter the elements of array : ");
		for(i=0;i<N;i++)
		{		
 			try
			{
				Arr[i]=a.nextInt();
                                if(Arr[i]<0)
                                      throw new MyException("Wrong input");
			}

                      	catch(MyException e)
			{
    				System.out.println(e);
 			}

	                catch(NumberFormatException z)
			{
				System.out.println("Enter valid Data!");
			}
                        
			catch(ArrayIndexOutOfBoundsException m)
			{
				System.out.println(m);
			}		
		}
		return N;		
	}
	
	public static void display_array(int Arr[], int N)
	{
		int i;
		System.out.println("\nThe elements of array are : ");
		for(i=0;i<N;i++)
		{
			System.out.println(+Arr[i]);
		}
	}	
}	

/*

OUTPUT : 

-------------------------------

Enter the size of the array : 
5
Array Size Exceeded.Maximum limit is 2

Enter the size of the array : 
2

Enter the elements of array : 
-5

Enter data greater than zero!
MyException

g
Enter valid Data!


*/
