/*Write a program on template and exception handling in Java: in this assignment multiple
templates are to be designed as a pattern and these patterns to be used to take decisions.*/


import java.util.Scanner;

public class Temp
{
	public static void main(String[] args)
	{
		Template t;
		t=new Multiply();			//store object of multiply in t
		t.perform();			// perform method of multiply is called
		
		t=new Divide();			//store object of divide in t
		t.perform();			// perform method of divide is called
	}
}

abstract class Template				//abstract class 
{
	public final void perform()			//glue method- not overridden
	{
		accept();
		process();
		display();
	}
	
	public abstract void accept();		//abstract functions which are overridden.
	public abstract void process();
	public abstract void display();
}


class Multiply extends Template
{
	float var1,var2,result=0;
	
	public void accept()
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the first number:");
		var1=sc.nextFloat();
		System.out.println("Enter the second number:");
		var2=sc.nextFloat();
		
	}
	
	public void process()
	{
		result=var1*var2;
	}
	
	public void display()
	{
		System.out.println("The result is:"+result);
	}
}


class Divide extends Template
{
	int var1,var2,result=0;
	
	public void accept()
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the first number:");
		var1=sc.nextInt();
		System.out.println("Enter the second number:");
		var2=sc.nextInt();
		
	}
	
	public void process()
	{
		try
		{
			if(var2==0)
			{
				throw new ArithmeticException();
			}
			
			result=var1/var2;
			
		}
		catch(ArithmeticException ae)
		{
			System.out.println("Divide by Zero Error"+ae);
			accept();
		}
	}
	
	public void display()
	{
		System.out.println("The result is:"+result);
	}
}







