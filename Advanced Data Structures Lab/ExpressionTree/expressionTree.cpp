/*For given expression eg. a-b*c-d/e+f construct inorder sequence and traverse it using
postorder traversal(non recursive).*/

#include<iostream>
#include<ctype.h>
#include<stack>
using namespace std;

struct node
{
    char data;
    node *left,*right;
};

class stack1
{
    public:
    node * a[20];
    int top;
    stack1()
    {
        top=-1;
    }
    void push(node *x)
    {
    
        if(!isfull())
        {
            top++;
            a[top]=x;
        }

    }
    int isempty()
    {
        if(top==-1)
        {
            return 1;
        }
        return 0;
    }
    int isfull()
    {
        if(top==19)
        {
            return 1;
        }
        return 0;
    }
    node *pop()
    {
        node *temp;
        temp=a[top];
        top--;
        return temp;
    }
};

class exptree
{
    public:
    node *root;
    exptree()
    {
        root=NULL;
    }
    void create();
    void inorder(node *);
    void non_rec_inor(node *);
    void non_rec_preor(node *);
    void non_rec_postor(node *);
    node *swap_LtoR(node *);

};
void exptree::create()
{
    int i;
    stack1 s;
    char z[20];
    char c;
    node *nnode,*t1,*t2;
    cout<<"Enter the postfix expression:";
    cin>>z;
    cout<<"The entered expression is:";
    i=0;
    while(z[i]!=NULL)
    {
        cout<<z[i];
        i++;
    }
    i=0;
    while(z[i]!=NULL)
    {
        c=z[i];
        nnode=new node;
        nnode->left=nnode->right=NULL;
        nnode->data=c;
        if(c >= 'a' && c <= 'z')     //isalnum(c);
        {
            s.push(nnode);
        }
        else
        {
            t2=s.pop();
            t1=s.pop();
            nnode->left=t1;
            nnode->right=t2;
            s.push(nnode);
        }
        i++;
    }
    root=s.pop();
    cout<<"\n";

}
void exptree::inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void exptree::non_rec_inor(node *T)
{
    stack1 s;
    while(T != NULL)
    {
        s.push(T);
        T=T->left;
    }
    while(!s.isempty())
    {
        T=s.pop();
        cout<<T->data;
        T=T->right;
        while(T != NULL)
        {
            s.push(T);
            T=T->left;
        }

    }
}
void exptree::non_rec_preor(node *T)
{
    stack1 s;
    while(T != NULL)
    {
        cout<<T->data;
        s.push(T);
        T=T->left;
    }
    while(!s.isempty())
    {
        T=s.pop();
        T=T->right;
        while(T != NULL)
        {
            cout<<T->data;
            s.push(T);
            T=T->left;
        }
    }
}
void exptree::non_rec_postor(node *T)
{
    stack1 s1;
    stack<char>s2;
    char retadd;
    while(T != NULL)
    {
        s1.push(T);
        s2.push('l');
        T=T->left;
    }
    while(!s1.isempty())
    {
        T=s1.pop();
        retadd=s2.top();
        s2.pop();
        if(retadd=='r')
        {
            cout<<T->data;

        }
        else
        {
            s1.push(T);
            s2.push('r');
            T=T->right;
            while(T!=NULL)
            {
                s1.push(T);
                s2.push('l');
                T=T->left;
            }
        }
    }

}
node *exptree::swap_LtoR(node *T)
{
    node *p;
    if(T != NULL)
    {
        p=T->left;
        T->left=swap_LtoR(T->right);
        T->right=swap_LtoR(p);
    }
    return T;
}
int main()
{
    exptree e;
    int ch;
    do
    {
        cout<<"\n\n***************************** Expression tree **************************\n";
        cout<<"1.create tree\n2.display inorder\n3.display preorder \n4.display postorder\n5.swap left and right pointers\n6.Exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
                e.create();
                break;
        case 2:
                cout<<"\nThe inorder traversal is:";
               // e.inorder(e.root);
                e.non_rec_inor(e.root);
                break;
        case 3:

                cout<<"\n\nThe Preorder treavrsal is:";
                e.non_rec_preor(e.root);
                break;
        case 4:
                  cout<<"\n\nThe postorder traversal is:";
                    e.non_rec_postor(e.root);
                    break;
        case 5:
                e.swap_LtoR(e.root);
                cout<<"\nThe altered expression is:";
                e.non_rec_inor(e.root);
                break;
        case 6:
                break;
        }
    }while(ch != 6);


    return 0;
}

