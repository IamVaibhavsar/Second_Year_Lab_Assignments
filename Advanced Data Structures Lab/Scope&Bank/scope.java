/*Any application defining scope of Formal parameter, Global parameter, Local parameter
accessing mechanism and also relevance to private, public and protected access. Write a Java
program which demonstrates the scope rules of the programming mechanism*/


import java.util.*;
class student
{
static int div_no=1;//static instance variable it have global scope for all objects
protected int rno; //protected instance var.
public String nm;//public instance var.
double per;
student()
{
rno=0;
nm="abc";
per=0.0;
}
}
class scope extends student
{
private String addr; //private instance var.
scope()
{
addr="xyz";
}
void display()
{
System.out.print(this.rno);//accessing instance variable of currently executing object
System.out.print("\t"+this.div_no);
System.out.print("\t"+nm);
System.out.print("\t"+per);
System.out.print("\t"+addr);
}
void get()
{
Scanner s=new Scanner(System.in);
System.out.println("enter rno ");
rno=s.nextInt();
System.out.println("enter name ");
nm=s.next();
System.out.println("enter  percentage");
per=s.nextDouble();
System.out.println("enter address");
addr=s.next();

}
public static void main(String args[])
{
int n;//local variable for main function
System.out.println("enter no of records");
Scanner in=new Scanner(System.in);
n=in.nextInt();

scope s[]=new scope[n];//array of objects
for(int i=0;i<n;i++)// local scope to the block for i
s[i]=new scope();

for(int i=0;i<n;i++) 
{               
s[i].get();
}
System.out.println("\nrno\tdiv\tname\tper\taddr\n");
for(int i=0;i<n;i++) 
{               
s[i].display();
System.out.println();
}
}
}
