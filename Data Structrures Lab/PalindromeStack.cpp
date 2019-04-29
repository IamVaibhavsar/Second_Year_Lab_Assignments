/*
Write c++ program for palindrome with functions:-

    a) to check wheather given string is palindrome or not that
    uses a atack to determine wheather a string is a palindorme

    b) to remove spaces and punctuation in string, convert all
    the characters to lowercase, and then call above palinrome
    checking functions to checkfor a palindrome

    c)to print string in reverse order using stack

*/

#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


class stack
{
    char s[25];
    int top;

public:
    stack()
        {
            top=-1;
        }
    void push(char val);
    char pop();
    int isfull();
    int isempty();

};

class str
{
    char inputstr[25], revstr[25];
    stack stobj;

public:
    void readstring();
    void revstring();
    void convertstring();
    void checkpalindrome();

};

int stack::isempty()
{
    if(top==-1)
        return 1;   
    else
        return 0;   
}

int stack::isfull()
{
    if(top==24)
        return 1;
    else
        return 0;
}

void stack::push(char val)
{
    if(!isfull())
    {
        top++;
        s[top]=val;
    }
    else
        cout<<endl<<"stack overflows/full......"<<endl;
}

char stack::pop()
{
    char val='\0';
    if(!isempty())
    {
        val=s[top];
        top--;

    }
    else
        cout<<endl<<"stack underflow/empty......"<<endl;
    return val;
}

void str::readstring()
{
    cout<<"\nEnter string  ";
    gets(inputstr);
    cout<<"\nYou entered:->  "<<inputstr;
}

void str::revstring()
{
    int i;
    char ch;
    for(i=0;inputstr[i]!='\0';i++)
    {
        stobj.push(inputstr[i]);
	}
    i=0;
    cout<<"\n\nAfter reverse your string:-> ";
    while(!stobj.isempty())
    {
        ch=stobj.pop();
        cout<<ch;
        revstr[i]=ch;
        i++;
    }
}

void str::convertstring()
{
    int i,j=0;
    char tempstr[25];
    for(i=0;inputstr[i]!='\0';i++)
    {
        if(inputstr[i]>=97  && inputstr[i]<=122)
        {
            tempstr[j]=inputstr[i];
            j++;
        }
        else if(inputstr[i]>=65 && inputstr[i]<=90)
        {
            tempstr[j]=inputstr[i]+32;
            j++;
        }

    }
    tempstr[j]='\0';
    strcpy(inputstr,tempstr);
    cout<<"\n\nYour converted string:-> "<<inputstr;
}


void str::checkpalindrome()
{
    cout<<"\n\n\n\n\n";
    cout<<"\nCheck for palindrome"<<endl;

    readstring();
    convertstring();
    revstring();

    if(strcmp(inputstr,revstr)==0)
        cout<<"\n\nYour string is PALINDROME";
    else
        cout<<"\n\nYour string is NOT PALINDROME";

}

int main()
{
    str obj;
    obj.readstring();
    obj.convertstring();
    obj.revstring();
    obj.checkpalindrome();
    return 0;
}

