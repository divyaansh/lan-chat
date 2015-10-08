/*
Practical List: 1
Program No.:4
Developed By: Dipankar Behera,Divyaansh Anuj
Date: 16th April 2010
Write a program to perform the following operations(using separate function
for each) on an array of type float
(a) To enter the content of the array
(b) To display the content of the array
(c) To sort the array using Selection Sort
(d) To search for a real number from the content of the array using binary
    search
*/
#include<iostream.h>
#include<conio.h>
void Enter(float []);
void Display(float []);
void Ssort(float[]);
void Bsearch( float [], float );
void main()
{
 clrscr();
 float A[10];
 float n;
 Enter(A);
 Display(A);
 cout<<" The sorted array is: " ;
 Ssort(A);
 Bsearch(A,n);
 getch();
}


void Enter(float X[10])
 { cout<<"Enter the array: \n";
   for(int i=0; i<10; i++)
   cin>>X[i];
 }

void Display(float X[10])
 { cout<<endl<<"The array is: \n";
   for(int i=0; i<10; i++)
   cout<<X[i]<<endl;
 }

void Ssort(float X[10])
 {
  for( int i=0; i<10; i++)
   {
    float small=i;
    for(int j=i+1; j<10; j++)
    if (X[j]< X[small])
      small=j;
     if(small!=i)
      {
       float Temp=X[small];
       X[small]=X[i];
       X[i]=Temp;
       }
    }
    for(int t=0; t<10; t++)
    cout<<X[t]<<endl;
 }

void Bsearch(float X[10], float N)
 {
  float lb=0, ub=9, found=0, data;
    cout<<"Enter the value to be searched: ";
    cin>>data;
  while ((lb<=ub) && !found)
   {
     float mid=(lb+ub)/2;
     if (X[mid]>data)
      ub=mid-1;
     else
      if (X[mid]<data)
       lb=mid+1;
     else
      found++;
   }
  if (found)
   cout<<"the value is found";
  else
   cout<<"value not found" ;
 }


 /*
  OUTPUT:

  3

The array is:
4
3
2
1
6
7
8
5
4
3
 The sorted array is: 1
2
3
3
4
4
5
6
7
8
Enter the value to be searched: 3
the value is found
*/