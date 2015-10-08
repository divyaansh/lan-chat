#include<iostream.h>
#include<conio.h>
#include<dos.h>
void main()
{
 time T;
 while(!kbhit())
 {
  clrscr();
  gettime(&T);
  cout<<(int)T.ti_hour<<":"<<(int)T.ti_min<<":"<<(int)T.ti_sec;
  delay(1000);
 }
 getch();
}
