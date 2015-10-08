#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 char ch;
 do
 {
  while(!kbhit())
  {
   cout<<"hey";
  }
  ch=getch();
 }while(ch!=27);
 getch();
}