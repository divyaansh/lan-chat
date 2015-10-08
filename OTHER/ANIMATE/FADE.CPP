#include<fstream.h>
#include<conio.h>
#include<dos.h>
void main()
{
 _setcursortype(_NOCURSOR);
 int a=0,b=15,c;
 while(!kbhit())
 {
 delay(200);
 textcolor(a);
 textbackground(b);
 c=a;a=b;b=c;
 clrscr();
 delay(200);

 clrscr();
 for(int i=1;i<80*25;i++)
  cout<<'°';
 delay(200);

 clrscr();
 for(i=1;i<80*25;i++)
  cout<<'±';
 delay(200);

 clrscr();
 for(i=1;i<80*25;i++)
  cout<<'²';
 delay(200);

 clrscr();
 for(i=1;i<80*25;i++)
  cout<<'Û';

 }
 getch();
}