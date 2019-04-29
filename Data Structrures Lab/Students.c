/*Write C/C++ program to store marks scored for first test of subject 'Data Structures and Algorithms' for N students. Compute
I. The average score of class
ii. Highest score and lowest score of class
iii. Marks scored by most of the students
iv. list of students who were absent for the test*/


#include<stdio.h>
void main()
{
    printf(" ------------- STUDENT PROFILE SYSTEM -----------------\n");
    
	int marks[20],n,i,m=0,max=0,cnt=0,flag=0,count[50],maxm=0,z,ch,h;
	char choice[1],y;
	
	printf("Enter the number of students : ");
	scanf("%d",&n);
	
	if(n>20)
    {
        printf("ERROR:\n\tThe number entered exceeds the LIMIT\n\tMaximum number to be entered is 20\n\tPLEASE RE-ENTER NUMBER OF STUDENTS:");
        scanf("%d",&n);

    }
    
	printf("enter marks of students and enter ' -1 ' as marks for absent students:\n");
	for(i=0;i<n;i++)
	{
	    	printf(" Roll no. %d: ",i+1);
		scanf("%d",&marks[i]);
		
		if(marks[i]!=-1)
		{
			m=m+marks[i];
			flag++;
		}

	}
	
	 if(flag==0)
	    {
	    	printf("ERROR:\n\tNO STUDENTS ARE PRESENT\n\t");
	    }
    	else
    {



	label:printf("\n 1: TO DISPLAY The AVERAGE of marks of students NOT considering absent students \n 2:  TO display The AVERAGE of marks of students considering absent students \n 3: For obtaining MAXIMUM marks \n 4: for obtaining MINIMUM marks \n 5: for obtaining number of absent students with their roll numbers \n 6: to display marks obtained by maximum students \n");
	printf(" Enter your Choice:");
	scanf("\n %d",&ch);

    switch(ch)
    {


        case 1:
        {

            printf(" \nThe AVERAGE of marks of students NOT considering absent students is: %d",m/flag);
        }
        break;
        
        case 2:
        {
            printf("\n The AVERAGE of marks of students considering absent students is: %d",m/n);
        }
        break;
        
        case 3:
        {
            for(i=0;i<n;i++)
            {
                if(max<marks[i])
                {
                    max=marks[i];
                }

       }
        printf(" \nThe MAXIMUM mark among students is %d",max);
        }
        break;
        
        case 4:
        {
            int min=100;
            for(i=0;i<n;i++)
            {
                if(marks[i]!=-1)
                {
                    if(min>marks[i])
                    {
                        min=marks[i];		//note the diference
                    }
                }
            }
        printf(" \nThe MINIMUM mark among students is %d",min);
        }
        break;
        
        case 5:
        {
            printf(" \nroll numbers of absent students are : ");
            for(i=0;i<n;i++)
            {
                if(marks[i]==-1)
                {
                    printf("%d  ",i+1);
                    cnt++;
                }

            }
            printf("\n the number of absent students is : %d ",cnt);
        }
        break;
        
        case 6:
        {
                for(i=0;i<n;i++)		//frequency measurement.
                {
                    count[i]=0;
                    for(z=0;z<n;z++)
                    {
                        if(marks[i]==marks[z])
                        {
                            count[i]++;
                        }
                    }
                }
        for(i=0;i<n;i++)		
        {
            if(marks[i]!=-1)
                {
                    if(maxm<count[i])
                    {
                        maxm=count[i];
                        h=i;
                    }
                }
        }

        printf(" The marks obtained by maximum number of students is %d \n and is obtained by %d students",marks[h],maxm);
        }
        break;
        default:
        {
            printf(" the entered choice is not valid");
        }
    }
    printf("\n DO YOU WANT TO RE-ENTER CHOICE(Y/N):");
    scanf("%s",choice);
    if(choice[0]==121||choice[0]==89)
    {
        goto label;
    }

    }

}




























