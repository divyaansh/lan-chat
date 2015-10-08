/*
Practical List 1
Program No : 1
Developed By : Dipankar Behera,Divyaansh Anuj
Date : 16-April-2010
Write a menu driven program to find the sum of the following series using
user-defined functions:
(a) X + X*X + ... N times
(b) U + U*U/2! + ... N times
(c) 2 + (2+4) + .... N times
*/
#include<iostream.h>
#include<conio.h>
void P1(int, int);
void P2(float, int);
void P3(int);
float sum=0;
void main()
{
clrscr();
cout<<"Select the series you want to print :"<< endl;
cout<<"(a) X + X*X + ... N times"<<endl;
cout<<"(b) U + U*U/2! + ... N times"<<endl;
cout<<"(c) 2 + (2+4) + .... N times"<<endl;
char m;
cin>>m;
int n,b;
switch(m)
{ case 'a':cout<<"Enter no. of terms:\n";
	 cin>>n;
	 cout<<"Enter base: \n";
	 cin>>b;
	 P1(b,n);
	 break;

  case 'b':cout<<"Enter no. of terms:\n";
	 cin>>n;
	 cout<<"Enter base: \n";
	 cin>>b;
	 P2(b,n);
	 break;

  case 'c':cout<<"Enter no. of terms:\n";
	 cin>>n;
	 P3(n);
	 break;

  default:cout<<"Invalid";
 }
 getch();
 }

 void P1(int B, int N)
 {int prod=1;
  for(int i=1; i<=N; i++)
  {
   prod*=B;
   sum+=prod;
  }
  cout<<"The sum is: "<<sum;
 }

 void P2(float U, int N)
 {float prod=1,fact=1;
  float term=1;
  for(int i=1; i<=N; i++)
  {
   term*=U;
   fact*=i;
   prod=term/fact;
   sum+=prod;
  }
  cout<<"The sum is: "<<sum;
 }

 void P3(int N)
 {int s1=0,j=2, term;
  for(int i=1; i<=N; i++)
  {
   term=j*i;
   s1+=term;
   sum+=s1;
  }
  cout<<"The sum is: "<<sum;
 }
/*        OUTPUT

 Select the series you want to print :
(a) X + X*X + ... N times
(b) U + U*U/2! + ... N times
(c) 2 + (2+4) + .... N times
a
Enter no. of terms:
3
Enter base:
2
The sum is: 14


b
Enter no. of terms:
3
Enter base:
2
The sum is: 5.333333

c
Enter no. of terms:
3                                                                               
The sum is: 20                                                                  
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                















*/














