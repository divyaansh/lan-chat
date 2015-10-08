/*
Program No. : 3
Developed By: Dipankar Behera, Divyaansh Anuj
Date	    : 16-April-2010
*/

/*
Write a program to perform the following operations
(using seperate function for each) on an array of type float
(a) To enter the content of the array
(b) To display the content of the array
(c) To sort the array using Insertion sort
(d) To search for a real number from the content of the array
    using linear search
*/

#include<iostream.h>
#include<conio.h>
void enter(float [],int);
void display(float [],int);
void isort(float [],int);
void lsearch(float [],int);
void main()
{
 clrscr();
 float A[100];int n,ch;
 cout<<"Enter the array elements::\n";
  cin>>n;

  enter(A,n);
  display(A,n);
  isort(A,n);
  lsearch(A,n);
getch();
}

void enter(float A[],int n)
{
 cout<<"Enter the array:";
 for(int i=0;i<n;i++)
 cin>>A[i];
}

void display(float A[],int n)
{
 for(int i=0;i<n;i++)
 cout<<"Element no.:"<<i+1<<" is "<<A[i]<<endl;
}

void isort(float A[],int n)
{
 for(int i=1;i<n;i++)
  {
   int temp=A[i];
   int j=i-1;
   while((j>=0) && (temp<A[j]))
    {
     A[j+1]=A[j];
     j--;

    } A[j+1]=temp;


  }
 cout<<"The sorted array is::";
 display(A,n);

}
void lsearch(float A[],int n)
{
 int data;
 cout<<"Enter the number to be searched:\n";
 cin>>data;
 int i=0,found=0;
 while((i<n) && (!found))
 {
  if(A[i]==data)
  found++;
  else
  i++;
 }
 if(found)
 cout<<"The number is at position::"<<i+1;
 else
 cout<<"number absent in the array";
}
 /* OUTPUT***************************************************
     Enter the array elements::
4
Enter the array:23
45
67
88
Element no.:1 is 23
Element no.:2 is 45
Element no.:3 is 67
Element no.:4 is 88
The sorted array is::Element no.:1 is 23
Element no.:2 is 45
Element no.:3 is 67
Element no.:4 is 88
Enter the number to be searched:
45
The number is at position::2 *********************/







                                                                                
                                                                                
