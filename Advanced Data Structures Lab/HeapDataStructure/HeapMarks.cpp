/*Read the marks obtained by students of second year in an online examination of particular
subject. Find out maximum and minimum marks obtained in that subject. Use heap data
structure. Analyze the algorithm*/


#include <iostream>
using namespace std;
class heap1{
public:

void MAX_HEAPIFY(int a[], int i, int n)		//reheapdown- deleting element from top location
{
    int l,r,largest,loc;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l]>a[i])
       largest=l;
    else
       largest=i;
    
    if((r<=n)&&(a[r]>a[largest]))
       largest=r;
   if(largest!=i)
    {
         loc=a[i];				//delet
         a[i]=a[largest];
         a[largest]=loc;
         MAX_HEAPIFY(a, largest,n);
    }
}
void BUILD_MAX_HEAP(int a[], int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        MAX_HEAPIFY(a, k, n);
    }
}
void HEAPSORT(int a[], int n)
{

    BUILD_MAX_HEAP(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];				//delete maximum element from the root.
        a[i] = a[1];
        a[1] = temp;
        MAX_HEAPIFY(a, 1, i - 1);
    }
}

void accept(){
		int n;
	    cout<<"Enter the number of students"<<endl;
	    cin>>n;
	    int a[n];
	    cout<<"Enter the marks of the students "<<endl;
	    for (int i = 1; i <= n; i++)
	    {
	        cin>>a[i];
	    }
	    HEAPSORT(a, n);
	    display(a,n);
}
void display(int a[],int n){

	
      cout<<":::::::SORTED MARKS::::::"<<endl;

	    for (int i = 1; i <= n; i++)
	    {
	        cout<<a[i]<<endl;
	    }
	  
	cout<<"Minimum marks obtained are:"<<a[1];
	cout<<"\nMaximum marks obtained are:"<<a[n];

}
};
int main()
{
   	heap1 h;
	h.accept();
	return 0;
}





