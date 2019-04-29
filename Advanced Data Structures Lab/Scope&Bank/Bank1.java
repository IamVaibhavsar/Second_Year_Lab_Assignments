/*A bank maintains three  kinds of accounts for customers  -- Savings account Fixed deposit and Current account . The Saving account provides compound interest and withdrawal facilities but no cheque  book facility. The fixed deposit account can be Short term, Long term or Medium term. The current account provides cheque book facility but no interest. Both savings and current account holders should maintain minimum balance and if the balance falls below this level a service charge is imposed. Design all the classes provide necessary member functions to deposit and withdraw  amount, Check for minimum balance and compute and deposit the interest.
*/

import java.util.*;
import java.util.Scanner;
class Account {
    private String name;
    public int acctNum;
    public float balance;
    public float minbalance;
    public float interestRate;
    public  boolean checkbookFacility;
  // constructor
    public Account(int acctNum, String name, float bal) {
        this.acctNum = acctNum;
        this.name = name;
        this.balance = bal;
        interestRate = 0;
    }
    public void Display()
	{
		System.out.println("\nACCOUNT NAME : "+name);
		System.out.println("\nACCOUNT NUMBER : "+acctNum);
		System.out.println("\nACCOUNT BALANCE : "+balance);
                System.out.println("\nCheckbook Facility : "+checkbookFacility);
	}
    public float interestPerYear() {
        return balance * interestRate/100;
    }

    public void deposit(float amount) {
           balance += amount;
   }

}


class Saving extends Account {
    public Saving(int acctNum, String name, float bal) 
    {
        super(acctNum, name, bal);
        interestRate = 2;
        checkbookFacility=false;
        minbalance=500;
    }

    public void withdraw (float amount)     {
        if (  balance-amount < minbalance)        {
             System.out.println("Amount is larger than current balance.");
         }
         else
         balance=balance-amount;
    }
    public void setBalance(){
                 balance = balance + balance * interestRate/100 ;

    }

    public void printInterest()    {
           System.out.println("\nInteret : "+balance*interestRate/100);
           System.out.println("your interest rate and balance is:" + interestRate+ " " + balance);
   }
}

class FixedDeposit extends Account {
    String term;
    public FixedDeposit(int acctNum, String name, float bal, String t) {
        super(acctNum, name, bal);

        term=t;
        checkbookFacility=false;
    }
    public void setBalance(){
              interestRate=4;
             if (term.equals("Medium")){
                 interestRate=6; balance = balance + balance * 6/100 ;}
             if (term.equals("Long")){
                 interestRate=8; balance = balance + balance * 8/100;}
            balance = balance + balance * interestRate/100 ;

    }
    public void DisplayFD(){
          Display();  System.out.println("\nTerm:"+term);
    }
    public void printInterest()    {
           System.out.println("\nInteret : "+balance*interestRate/100);
           System.out.println("your interest rate and balance is:" + interestRate+ " " + balance);
   }
}

class Current extends Account {
    public Current(int acctNum, String name, float bal) {
        super(acctNum, name, bal);

        checkbookFacility=true;
        minbalance=5000;
    }

    public void withdraw (float amount)     {
        if (  balance-amount < minbalance)        {
             System.out.println("Amount is larger than current balance.");
         }
         else
         balance=balance-amount;
    }

}


public class Bank {
    public static void main (String args [])
    {

        String Name,t; int AcctNum,choice; float Balance,amt;


        Scanner ACC=new Scanner(System.in); int typ;
        System.out.println("\nENTER account type (1 Saving 2 FD 3 Current)");
        typ=ACC.nextInt();
        if (typ==1){
		System.out.println("\nENTER THE ACCOUNT HOLDER NAME : ");
		Name=ACC.next();
		System.out.println("\nENTER THE ACCOUNT NUMBER : ");
		AcctNum=ACC.nextInt();
		System.out.println("\nENTER THE ACCOUNT BALANCE : ");
		Balance=ACC.nextFloat();

        Saving  S1  = new Saving(AcctNum, Name, Balance);
        do{
        	System.out.println("\n1. Display Account info");
            System.out.println("\n2. Withdraw");
        	System.out.println("\n3. Deposit");
        	System.out.println("\n4. Calculate interest and print");
        	System.out.println("\nEnter choice:");
        	choice=ACC.nextInt();
            switch(choice){
                	case 1: S1.Display(); break;
        	        case 2:	System.out.println("\nENTER THE Amount : ");
		                amt=ACC.nextInt();    S1.withdraw(amt);break;
                    case 3:	System.out.println("\nENTER THE Amount : ");
		                amt=ACC.nextInt();   S1.deposit(amt); break;
                	case 4: S1.setBalance();S1.printInterest(); break;
               }
               }while(choice < 5);
       }// end of saving
       if (typ==2){
		System.out.println("\nENTER THE ACCOUNT HOLDER NAME : ");
		Name=ACC.next();
		System.out.println("\nENTER THE ACCOUNT NUMBER : ");
		AcctNum=ACC.nextInt();
		System.out.println("\nENTER THE FD ACCOUNT : ");
		Balance=ACC.nextFloat();
        System.out.println("\nENTER TERM (Short/Long/Medium): ");
		t=ACC.next();
        FixedDeposit  FD1  = new FixedDeposit(AcctNum, Name, Balance,t);
        do{
        	System.out.println("\n1. Display Account info");
       	 	System.out.println("\n2. Calculate interest and print");
        	System.out.println("\nEnter choice:");
        	choice=ACC.nextInt();
            switch(choice){
                case 1: FD1.DisplayFD(); break;
        		case 2: FD1.setBalance();FD1.printInterest(); break;
               }
        }while(choice < 3);
       }// end of FD
       if (typ==3){
		System.out.println("\nENTER THE ACCOUNT HOLDER NAME : ");
		Name=ACC.next();
		System.out.println("\nENTER THE ACCOUNT NUMBER : ");
		AcctNum=ACC.nextInt();
		System.out.println("\nENTER THE Balance(>5000) : ");
		Balance=ACC.nextFloat();
        Current  C1  = new Current(AcctNum, Name, Balance);
        do{
        	System.out.println("\n1. Display Account info");
            System.out.println("\n2. Withdraw");
           	System.out.println("\n3. Deposit");
        	System.out.println("\n4. Calculate interest and print");
        	System.out.println("\nEnter choice:");
        	choice=ACC.nextInt();
            switch(choice){
                	case 1: C1.Display(); break;
        	        case 2:	System.out.println("\nENTER THE Amount : ");
		                amt=ACC.nextInt();    C1.withdraw(amt);break;
                    case 3:	System.out.println("\nENTER THE Amount : ");
		                amt=ACC.nextInt();   C1.deposit(amt); break;
                	case 4: System.out.println("\nNO INTEREST "); break;
               }
        }while(choice < 5);
       }// end of Current

    }
}
