/*Write C++ program for string operations- copy, concatenate, check substring, equal, reverse and length*/


#include<iostream>
#include<string.h>		//noted
using namespace std;

class str
{
	
	char a[20],b[20];				//Bydefault Private
	public:
		void read1(char []);
		void read2(char []);
		void copy(char [],char []);
		void concatenate(char [],char []);
		void substring(char []);
		void compare(char [],char []);
		void reverse(char [],char []);
		void length(char []);
		void toUppercase(char []);
		void toLowercase(char []);
		void palindrome(char []);
	
};

	void str :: read1(char [])
	{
		cout<<"\nEnter the first string :";
		cin>>a;
		cout<<"\nThe first string is= "<<a<<endl;
	}

	void str :: read2(char [])
	{
		cout<<"\nEnter the second string :";
		cin>>b;
		cout<<"\nThe  second string is= "<<b<<endl;
	}

	void str :: copy(char [],char [])
	{	
		int i;
		for(i=0;a[i]!='\0';i++)
		{
			b[i]=a[i];
		}
		cout<<"\nAfter copying, The second string is = "<<b<<endl;
		cout<<"\nHence first string is copied into second"<<endl;
	}


	void str :: concatenate(char [],char [])
	{
		int i,j;
		for (i = 0; a[i]!='\0'; i++);
 		{
   			for (j = 0; b[j]!='\0'; j++,i++)
  			{
  				a[i]=b[j];			//noted
  			}
  		}
  		a[i] = '\0';
 
  		cout<<"\n String after the Concatenate = "<<a<<endl;
	}
	
	void str :: substring(char [])
	{
		char search[20];
		int i,j,k;
		i=0,j=0;
		cout<<"\nEnter the Search Substring: "<<endl;
		cin>>search;
		
		while(a[i]!='\0')
		{
			while((a[i]!=search[0])&&(a[i]!='\0'))
			i++;
			if(a[i]=='\0')
			{
				cout<<"\nIt is not a substring";
				break;
			}
			k=i;
			while((a[i]==search[j])&&(a[i]!='\0')&&(search[j]!='\0'))
			{
				i++;
				j++;
			}
			if(search[j]=='\0')
			{
				cout<<"\nIt is a substring and present at position number "<<k+1<<endl;
				break;
			}
			if(a[i]=='\0')
			{
				cout<<"\nIt is not a substring";
				break;
			}
			i=k+1;
			j=0;
		}
	}
	


	void str :: compare(char [],char [])
	{
		int i=0;
		while((a[i]==b[i]) && (a[i]!='\0'))
		{
			i++;
		}
		if(a[i]>b[i])
			cout<<a<<" is greater than "<<b<<endl;
		else if(a[i]<b[i])
			cout<<a<<" is smaller than "<<b<<endl;
		else
			cout<<a<<" is equal to "<<b<<endl;
	}


	void str :: reverse(char [], char [])
	{
		int i,j,len;
		j = 0;
  		len = strlen(a);
 
  		for (i =len-1; i >= 0;i--)
  		{
  			b[j++] = a[i];
  		}
  		b[i] = '\0';
 		cout<<"\n String after Reversing = "<<b<<endl;
	}
	
	
	void str :: length(char [])
	{
		int i,cnt=0;
		for(i=0;a[i]!='\0';i++)
		{	
			cnt++;
		}	
		
		cout<<"\nThe length of String is = "<<cnt<<endl;
	}
	
	
	void str :: toUppercase(char [])
	{
		int i;
		for (i = 0; a[i]!='\0'; i++)
		{
  			if(a[i] >= 'a' && a[i] <= 'z')
  			{
  				a[i] = a[i] -32;
			}
  		}
 
  		cout<<"\n The Entered String in Upper Case = "<<a<<endl;
	}


	void str :: toLowercase(char [])
	{
		int i;
		for (i = 0; a[i]!='\0'; i++)
		{
  			if(a[i] >= 'A' && a[i] <= 'Z')
  			{
  				a[i] = a[i] +32;
			}
  		}
 
  		cout<<"\n The Entered String in Lower Case = "<<a<<endl;
	}

	void str :: palindrome(char [])
	{
    
		int l = 0;
	   	int h = strlen(a) - 1;
	 
	   	while (l<h)
	    	{
			if (a[l++] != a[h--])
			{
			    	cout<<"\n The String  "<<a<<" is Not a Palindrome"<<endl;
			    	return;
			}
	    	}
	    	cout<<"\n The String  "<<a<<" is a palindrome"<<endl;
	}

int main()
{
	str s1;
	
	int ch=0;
	char cont,ch1[20],ch2[20];

	

	do
	{
	
		cout<<"\nThe available choices are as follows: ";
		cout<<"\n1.To Copy a string into another.";
		cout<<"\n2.To concatenate two strings.";
		cout<<"\n3.To Chech the substring.";
		cout<<"\n4.To Compare the strings";
		cout<<"\n5.To reverse a string .";
		cout<<"\n6.To find the length of a string.";
		cout<<"\n7.To convert the string into upper case.";
		cout<<"\n8.To convert the string into Lower case.";
		cout<<"\n9.To check string is  palindrome or not.";
		

		cout<<"\nEnter Your Choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				s1.read1(ch1);
				s1.read2(ch2);
				s1.copy(ch1,ch2);
				cout<<"\n*********************************************************************";
				break;

			case 2:
				s1.read1(ch1);
				s1.read2(ch2);
				s1.concatenate(ch1,ch2);
				cout<<"\n*********************************************************************";
				break;

			case 3:
				s1.read1(ch1);
				s1.substring(ch1);
				cout<<"\n********************************************************************";
				break;

			case 4:
				s1.read1(ch1);
				s1.read2(ch2);
				s1.compare(ch1,ch2);
				cout<<"\n********************************************************************";
				break;


			case 5:
				s1.read1(ch1);
				s1.reverse(ch1,ch2);
				cout<<"\n********************************************************************";
				break;
			

			case 6:
				s1.read1(ch1);
				s1.length(ch1);
				cout<<"\n********************************************************************";
				break;

			case 7:
				s1.read1(ch1);
				s1.toUppercase(ch1);
				cout<<"\n********************************************************************";
				break;

			case 8:
				s1.read1(ch1);
				s1.toLowercase(ch1);
				cout<<"\n********************************************************************";
				break;

			case 9:
				s1.read1(ch1);
				s1.palindrome(ch2);
				cout<<"\n********************************************************************";
				break;

			default:
				{
					cout<<"\n SORRY! Please Enter a valid choice";
					
				}
		}
		cout<<"\nDo you want to Continue?"<<endl;
		cin>>cont;
		
	}while(cont=='Y'||cont=='y');
return 0;
}

