#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<string.h>

void main()
{
 _setcursortype(_NOCURSOR);
 clrscr();
 char ch[33]="";
 double gr=24, h, e=0.8, a=25, u, v, S=1, t;
 if(gr<25 && e<1){
 int i;
 gotoxy(1,gr+1);
 for(i=1;i<=79;i++)
  cout<<"ß";
 h=gr;
 while(h>0.5)
 {
  u=0;
  for(i=1;i<=h;i++)
  {
   v=sqrt(u*u+2*a*S);
   t=(v-u)/a;
   u=v;
   gotoxy(40-strlen(ch)/2,gr-h+i);
   cout<<ch;
   delay(t*1000);
   gotoxy(1,gr-h+i);
   clreol();
  }
  h=e*e*h;
  u=sqrt(2*a*h);
  for(i=1;i<=h;i++)
  {
   v=sqrt(u*u-2*a*S);
   t=(u-v)/a;
   u=v;
   gotoxy(40-strlen(ch)/2,gr-(i-1));
   cout<<ch;
   delay(t*1000);
   gotoxy(1,gr-(i-1));
   clreol();
  }
 }
 gotoxy(40-strlen(ch)/2,gr);
 cout<<ch;
 getch();}
}