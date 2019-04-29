/*Implement all the functions of a dictionary (ADT) using hashing.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys
must be unique
Standard Operations: Insert(key, value), Find(key), Delete(key)*/


#include<iostream>
#include<cstring>
#define max 10
using namespace std;

struct dic
{
	char cWord[20];
	char cMeaning[20];

};//end of structure 	

class hashtable
{
	public:
		dic ht[max];
		hashtable()	//constructor
		{
			for(int i=0;i<max;i++)
			{
				strcpy(ht[i].cWord,"");
				strcpy(ht[i].cMeaning,"");
			}
		}
		
		int hash(char ckey[10])
		{
			int i,s=0;
			for(i=0;ckey[i]!='\0';i++)
			{
				s=s+ckey[i];
			}
			return(s%max);
		
		}//end of hash
		
		void insert_word(dic d);
		void display();
		int search_word(char cW[]);
		void del_word(char cW[]);
		
};//end of class

void hashtable::insert_word(dic d)
{
	int iIndex=10;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(d.cWord)+i*i)%max;
		cout<<"\n\n Position :"<<i<<" "<<iIndex;
		if(i>0)
		cout<<"\n Collision at "<<iIndex; 
		if(strcmp(ht[iIndex].cWord,"")==0)
		{
			ht[iIndex]=d;
			break;
		}
	}	
		
}//end  of insert

void hashtable::display()
{
	cout<<"index\t\tWord\t\tmeaning";
	for(int i=0;i<max;i++)
	{
		cout<<"\n"<<i<<"\t\t"<<ht[i].cWord<<"\t\t"<<ht[i].cMeaning<<"\n";
	}

}//end of display

int hashtable::search_word(char cW[10])
{
	int iIndex,iFlag=0;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(cW)+i*i)%max;
		if(strcmp(ht[iIndex].cWord,cW)==0)
		{
			cout<<"\nWord Found and Meaning is :"<<ht[iIndex].cMeaning;
			iFlag=1;
			break;
		}
	}
	if(iFlag==0)
	cout<<"\nWord Not Found";
	
}//end of search_word

void hashtable::del_word(char cW[10])
{
	int iIndex,iFlag=0;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(cW)+i*i)%max;
		if(strcmp(ht[iIndex].cWord,cW)==0)
		{
			cout<<"\nWord Found and deleted :"<<ht[iIndex].cMeaning;
			strcpy(ht[iIndex].cWord,"");
			strcpy(ht[iIndex].cMeaning,"");
			iFlag=1;
			break;
		}
	}
	if(iFlag==0)
	cout<<"\n Word Not Found";
	
}//end of del_word
	
int main()
{
	char cW[10];
	int iCh,iFlag=0;
	hashtable h;
	dic d;
	do
	{
		cout<<"\n---------------LIST--------------\n";
		cout<<"1.INSERT WORD\n2.DISPLAY\n3.SEARCH MEANING\n4.DELETE\n5.EXIT\n";
		cout<<"Enter your choice:";
		cin>>iCh;
		cout<<"\n";
		
		switch(iCh)
		{
			case 1://insert
				cout<<"\n Enter word to insert:";
				cin>>d.cWord;
				cout<<"\n Enter Meaning:";
				cin>>d.cMeaning;
				h.insert_word(d);
				break;
				
			case 2://display
				h.display();
				break;
				
			case 3://search
				cout<<"\n Enter word to be searched:";
				cin>>cW;
				h.search_word(cW);
				break;
				
			case 4://delete
				cout<<"\n Enter the word to be deleted:";
				cin>>cW;
				h.del_word(cW);
				break;
				
			case 5://exit
				break;
				
		}//end of switch
	}while(iCh!=5);			
return 0;
}					
						



