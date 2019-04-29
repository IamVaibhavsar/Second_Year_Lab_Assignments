
/*A bank maintains three  kinds of accounts for customers  -- Savings account Fixed deposit and Current account . The Saving account provides compound interest and withdrawal facilities but no cheque  book facility. The fixed deposit account can be Short term, Long term or Medium term. The current account provides cheque book facility but no interest. Both savings and current account holders should maintain minimum balance and if the balance falls below this level a service charge is imposed. Design all the classes provide necessary member functions to deposit and withdraw  amount, Check for minimum balance and compute and deposit the interest.
*/


import java.util.Scanner;

class account {
	public String name;
	public int balance,no;
	public int check_book;
	Scanner sc4=new Scanner(System.in);
	public int create()
        {
	System.out.println("Enter your name:");
	name=sc4.nextLine();
	System.out.println("Enter the account no:");
	no=sc4.nextInt();
	System.out.println("Enter the amount to be deposited:");
	balance=sc4.nextInt();
	int bal=deposit(balance,0);
	return bal;
        }
	int deposit(int bal,int amt)
	{
		return (bal+amt);
	}
	int withdraw(int bal,int amt)
	{
		return (bal-amt);
	} 
	boolean check_bal(int bal,int limit)
	{
		if(bal<limit)
		{
			return true;
		}
		else
		{
		return false;
		}
	}
	int interest(int bal,int t,int n,int r)
	{
	int amt;
	amt=bal*((1+(r/n))^n*t)-bal;
	return (bal+amt);
	}
	void display()
	{
	System.out.println("Name:"+name+"Balance"+balance);
	}


}
class Saving_account extends account
{
	public int limit;
	public int service_charge;
	public int n;
	public void creates()
	{
		limit=1000;
		service_charge=20;
		int bal=create();
		if(check_bal(bal,limit))
		{
			int amt=(20*bal)/100;
			balance=bal-amt;
		}
		display();
	}
			
}
class Current_account extends account
{
	public int chequeflag;
}
class fixed_deposit extends account
{
	public int long_interest,short_interest;
	public int term,time;
	Scanner sc=new Scanner(System.in);
	void createf(int l,int s)
	{
		long_interest=l;
		short_interest=s;
		int bal=create();
		System.out.println("\nEnter the term\n1.long\n2.short");
		term=sc.nextInt();
		System.out.println("\nEnter the time for the FD:");
		time=sc.nextInt();
		if(term==1)
		{
		 balance=interest(bal,time,1,long_interest);
		}
		else
		{
		balance=interest(bal,time,1,short_interest);
		}
		
	}		
}
public class bank
{
	public static void main(String args[])
	{
	Saving_account s[]=new Saving_account[20];
	Current_account c[]=new Current_account[20];
	fixed_deposit f[]=new fixed_deposit[20];
	int ch,chh,i=0,j=0,k=0,acc_no,limit=1000;
	int flag=1,amt,chhh,chcheque;
	int inter_long,inter_short;
	Scanner sc3=new Scanner(System.in);
	System.out.println("\nEnter the interest_rate on FD for long and short:");
	inter_long=sc3.nextInt();
	inter_short=sc3.nextInt();
	do
	{
	System.out.println("\nEnter the account type:\n1.Saving account\n2.Current account\n3.fixed deposit\n4.exit");
	ch=sc3.nextInt();
	if(ch==1)
	{
	System.out.println("\n1.create account\n2.Deposit\n3.Withdrawal\n4.compute interst\n5.chech_bal\n6.Display");	
	System.out.println("\nEnter the operation to be performed:");
	chh=sc3.nextInt();;
	switch(chh)
	{
		case 1:
			s[i]=new Saving_account();
			s[i].creates();
			i++;
			break;
		case 2:System.out.println("\nEnter the account number:");
		acc_no=sc3.nextInt();
			
			for(int x=0;x<i;x++)
			{
				if(acc_no==s[x].no)
				{
					System.out.println("\nEnter the amount to be deposit:");
					amt=sc3.nextInt();
					int bal=s[x].deposit(s[x].balance,amt);
					s[x].balance=bal;
					s[x].display();
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
			case 3:	System.out.println("\nEnter the account number:");
			acc_no=sc3.nextInt();
			for(int x=0;x<i;x++)
			{
				if(acc_no==s[x].no)
				{
					System.out.println("\nEnter the amount to be withdraw:");
					amt=sc3.nextInt();
					int bal=s[x].withdraw(s[x].balance,amt);
					s[x].balance=bal;
					if(s[x].check_bal(s[x].balance,limit))
						{
							amt=(20*s[x].balance)/100;
							s[x].balance=s[x].balance-amt;
						}
					s[x].display();
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
			case 4:System.out.println("\nEnter the account number:");
			acc_no=sc3.nextInt();
			int t,tt,r;
			for(int x=0;x<i;x++)
			{
				if(acc_no==s[x].no)
				{
					System.out.println("\nEnter the time:");
					t=sc3.nextInt();
					System.out.println("\nNo of times the compund interest:");
					tt=sc3.nextInt();
					System.out.println("\nEnter the rate of intrest:");
					r=sc3.nextInt();
					int bal=s[x].interest(s[x].balance,t,tt,r);
					s[x].balance=bal;
					s[x].display();
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
			case 5:System.out.println("\nEnter the account number:");
			acc_no=sc3.nextInt();
			for(int x=0;x<i;x++)
			{
				if(acc_no==s[x].no)
				{
					System.out.println("\nBalance="+s[x].balance);
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
			case 6:
			System.out.println("\nEnter the account number:");
			acc_no=sc3.nextInt();
			for(int x=0;x<i;x++)
			{
				if(acc_no==s[x].no)
				{
					s[x].display();
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
	}
	}
	else if(ch==2)
	{
		System.out.println("\n1.create account\n2.Deposit\n3.Withdrawal\n4.Check book facility\n5.chech_bal\n6.Display");	
	System.out.println("\nEnter the operation to be performed:");
	chhh=sc3.nextInt();
	switch(chhh)
	{
	case 1:c[j]=new Current_account();
		c[j].create();
		System.out.println("Do you want cheque book facility...\n1.yes\n2.no");
		chcheque=sc3.nextInt();
		if(chcheque==1)
		{
			c[j].chequeflag=1;
		}
		else
		{
			c[j].chequeflag=0;
		}
			j++;
			break;
		case 2:System.out.println("\nEnter the account number:");
			acc_no=sc3.nextInt();
			for(int x=0;x<j;x++)
			{
				if(acc_no==c[x].no)
				{
					System.out.println("\nEnter the amount to be deposit:");
					amt=sc3.nextInt();
					int bal=c[x].deposit(c[x].balance,amt);
					c[x].balance=bal;
					c[x].display();
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
			case 3:	System.out.println("\nEnter the account number:");
			acc_no=sc3.nextInt();
			for(int x=0;x<j;x++)
			{
				if(acc_no==c[x].no)
				{
					System.out.println("\nEnter the amount to be withdraw:");
					amt=sc3.nextInt();
					int bal=c[x].withdraw(c[x].balance,amt);
					c[x].balance=bal;
					if(c[x].check_bal(c[x].balance,limit))
						{
							int amtt=(20*c[x].balance)/100;
							c[x].balance=c[x].balance-amtt;
						}
					c[x].display();
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
			case 4:System.out.println("\nEnter the account number:");
			acc_no=sc3.nextInt();
			for(int x=0;x<j;x++)
			{
				if(acc_no==c[x].no)
				{
				System.out.println("Cheque book:");
		if(c[x].chequeflag==1)
		{
			System.out.println("You have cheque book");
		}
		else
		{
			System.out.println("You don't have cheque book");
		}
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
			case 5:System.out.println("Enter the account number:");
			acc_no=sc3.nextInt();
			for(int x=0;x<j;x++)
			{
				if(acc_no==c[x].no)
				{
					System.out.println("Balance="+c[x].balance);
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
			case 6:
			System.out.println("\nEnter the account number:");
			acc_no=sc3.nextInt();
			for(int x=0;x<j;x++)
			{
				if(acc_no==c[x].no)
				{
					c[x].display();
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
	}

	}
	else if(ch==3)
	{
	System.out.println("1.create fd\n2.check account");	
	System.out.println("\nEnter the operation to be performed:");
	chhh=sc3.nextInt();
	switch(chhh)
	{
	case 1:f[k]=new fixed_deposit();
		f[k].createf(inter_long,inter_short);
		
			k++;
			break;
		case 2:System.out.println("\nEnter the account number:");
			acc_no=sc3.nextInt();
			flag=1;
			for(int x=0;x<j;x++)
			{
				if(acc_no==f[x].no)
				{
					System.out.println("Your balace:"+f[x].balance);
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				System.out.println("Account doesn't exist...");
			}
			break;
			
	}	
	}		
	}while(ch!=4);
}
}
