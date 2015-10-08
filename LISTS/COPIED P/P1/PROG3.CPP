/*
  Program no. :2
  Developed by:Aayush Sahni, Aala Saifi
  Date        :13-april-2010
*/

#include<iostream.h>
#include<conio.h>
void input(float [],int n);
void display(float [],int n);
void isort(float [],int n);
void lsearch(float [],int n);
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
 isort(A,n);
 lsearch(A,n);
 getch();
}
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
void isort(float A[],int n)
{ float temp;
  int j;
    for(int i=1;i<n;i++)
      {
	temp=A[i];
	j=i-1;
	while(temp<A[j]&&j>=0)
	{
	   A[j+1]=A[j];
	   j--;
	}
	A[j+1]=temp;
      }
   cout<<"The sorted array is : ";
     display(A,n);


}
void lsearch(float A[],int n)
{
 float data;
 int found=0,i=0;
 cout<<"Enter the data you want to search: ";
  cin>>data;
 while((i<n)&&(!found))
 {
   if(data==A[i])
      found++;
   else
      i++;
 }
 if(!found)
  cout<<"Data not found";
 else
  cout<<"Data found at"<<" "<<i+1;
}
/*
OUTPUT 1

Enter the no. of elements less than 25
5                                                                               
Enter the element no. 1: 5                                                      
Enter the element no. 2: 6                                                      
Enter the element no. 3: 1                                                      
Enter the element no. 4: 4                                                      
Enter the element no. 5: 9                                                      
5 6 1 4 9                                                                       
The sorted array is : 1 4 5 6 9                                                 
Enter the data you want to search: 5                                            
Data found at 3


OUTPUT 2

Enter the no. of elements less than 25
5                                                                               
Enter the element no. 1: 6                                                      
Enter the element no. 2: 3                                                      
Enter the element no. 3: 2
Enter the element no. 4: 21                                                     
Enter the element no. 5:                                                        
352                                                                             
6 3 2 21 352                                                                    
The sorted array is : 2 3 6 21 352                                              
Enter the data you want to search: 43                                           
Data not found
*/
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                



