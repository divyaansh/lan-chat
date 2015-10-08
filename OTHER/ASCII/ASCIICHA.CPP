#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 char ch=65;
 while(ch!=27)
 {
  ch=getch();
  cout<<ch<<'\t'<<(int)ch<<endl;
 }
 getch();
}
