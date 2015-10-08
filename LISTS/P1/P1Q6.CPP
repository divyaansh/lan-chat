/*
 Program No. :1
 Developed By:DIpankar Behera, Divyaansh Anuj
 Date        :16-April-2010

Write the program to accept the content in a string and count & display the
no. of vowels, consonants and the digits presentin it.Also display the
reversed content of the string.
*/

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
void main()
{
 clrscr();
 char A[50];
 cout<<"Enter the string"<<endl;
 gets(A);
 int v=0;int c=0;int d=0;
 char ch;
 for (int i=0;i<strlen(A);i++)
 {
  if (isalpha(A[i]))
   {
    ch=toupper(A[i]);
    if (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
     v++;
    else
     c++;
   }
   else if (isdigit(A[i]))
   d++;
  }
  cout<<"The number if vowels are "<<v<<endl;
  cout<<"The number of consonants are "<<c<<endl;
  cout<<"The number of digits are "<<d<<endl;
  char temp;
  char B[50];
  strcpy(B,A);
  for( int j=0; j<strlen(A)/2 ;j++)
   {
    temp=B[j];
    B[j]=B[strlen(B)-j-1];
    B[strlen(A)-j-1]=temp;
   }
  cout<<"The reverse of the string is "<<endl;
  puts(B);
  getch();
  }


/************************************Output***********************
Enter the string
qwerty1234
The number if vowels are 1
The number of consonants are 5
The number of digits are 4
The reverse of the string is
4321ytrewq
****************************************************************/









                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
