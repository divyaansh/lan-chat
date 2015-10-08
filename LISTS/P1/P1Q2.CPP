/*
Practical List 1
Program No : 2
Developed By : Dipankar Behera ,Divyaansh Anuj
Date : 16th April 2010
Write a menu driven program to check the following for a given
number passed as parameter  to relevant user-defined function:
(a) Prime Number  (b) Palindrome
*/
#include<iostream.h>
#include<conio.h>
int Prime(int);
int Palin(int);
void main()
{
 clrscr();
 int n;
 char choice;
 cout<<"Enter the choice:"<< endl;
 cout<<" (a) To check if a number is prime no." <<endl;
 cout<<" (b) To check if a number is palindrome" <<endl;
 cin>> choice;
 switch(choice)
 {
  case 'a': cout<<" Enter a number: " <<endl;
	    cin>>n;
	    if(Prime(n))cout<<"Prime";else cout<<"Not Prime";
	    break;
  case 'b': cout<<" Enter a number: "<<endl;
	    cin>>n;
	    if(Palin(n))cout<<"Palindrome";else cout<<"Not a Palindrome";
	    break;

 }
 getch();
}

int Prime(int N)
{ int found=0;
  int i=2;
  while((found==0) && (i<=N/2))
  {
   if(N%i==0)
   found++;
   i++;
  }
  if(found==1)
  return 0;
  else
  return 1;
}

int Palin(int a)
{ int b=0,c=1,num;
  num=a;
  while(a>0)
  {c=a%10;
   b=b*10+c;
   a=a/10;
  }
  if(num==b)
  return 1;
  else
  return 0;

}

/*
OUTPUT:

Enter the choice:
 (a) To check if a number is prime no.
 (b) To check if a number is palindrome

a
 Enter a number:
97
Prime

b
 Enter a number:
12321
Palindrome

*/






















