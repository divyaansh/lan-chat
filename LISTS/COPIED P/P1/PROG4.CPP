/*
  Program no. :4
  Developed by:Aayush Sahni, Aala Saifi
  Date        :20-april-2010
*/
#include<iostream.h>
#include<conio.h>
void input(float A[],int n)
{
 for(int i=0;i<n;i++)
 {
   cout<<"Enter the element no. "<<i+1<<": ";
     cin>>A[i];
 }
}
void display(float A[],int n)
{
 for(int i=0;i<n;i++)
   cout<<A[i]<<" ";
 cout<<endl;
}
void ssort(float A[],int n)
{ float small,temp;
   for(int i=0;i<n-1;i++)
     {
       small=i;

      for(int j=i+1;j<n;j++)
       {
	 if(A[small]>A[j])
	    small=j;
       }
    if(small!=i)
    {
      temp=A[small];
      A[small]=A[i];
      A[i]=temp;
    }
     }
   cout<<"The sorted array is: ";
    display(A,n);
}
void bsearch(float A[],int n)
{
 float data;
 int found=0;
 cout<<"Enter the data you want to search: ";
  cin>>data;
 int lb=0,ub=n-1,mid;
 while(lb<=ub&&(!found))
 {
  mid=(lb+ub)/2;
  if(data>A[mid])
    lb=mid+1;
  else
  if(data<A[mid])
    ub=mid-1;
  else
   found++;
 }
 if(!found)
  cout<<"Data not found";
 else
  cout<<"Data found at "<<mid+1;
}

void main()
{
 clrscr();
 float A[25],n;
 do
 {
   cout<<"Enter the no. of elements less than 25"<<endl;
     cin>>n;
 }while(n>25);
 input(A,n);
 display(A,n);
 ssort(A,n);
 bsearch(A,n);
 getch();
}
/*
OUTPUT

Enter the no. of elements less than 25
4                                                                               
Enter the element no. 1: 5                                                      
Enter the element no. 2: 6                                                      
Enter the element no. 3: 1                                                      
Enter the element no. 4: 3                                                      
5 6 1 3                                                                         
The sorted array is: 1 3 5 6                                                    
Enter the data you want to search: 5                                            
Data found at 3

OUTPUT 2

Enter the no. of elements less than 25
3                                                                               
Enter the element no. 1: 10                                                     
Enter the element no. 2: 20                                                     
Enter the element no. 3: 30                                                     
10 20 30                                                                        
The sorted array is: 10 20 30                                                   
Enter the data you want to search: 52                                           
Data not found
*/
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

