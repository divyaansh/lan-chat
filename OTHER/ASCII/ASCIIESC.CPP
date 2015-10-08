#include<iostream.h>
#include<conio.h>

void main()
{
 clrscr();
 char ch='\a';
 cout<<"A";
 cout<<ch;
 cout<<"B";
 for(int i=0;i<255;i++)
  if(ch==i)
   cout<<(int)ch;
 getch();
}