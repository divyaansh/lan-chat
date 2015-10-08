#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

void main()
{
 clrscr();
 char User[30],ch=1;
 cout<<"Enter Username:\n";
 cin>>User;
 fstream fil3;
 fil3.open("CHATTING.txt",ios::out);
 fil3.close();
 clrscr();
 while(ch!=27)
 {
  while(!kbhit())
  {
   clrscr();
   char Lin[80];
   fstream fil;
   fil.open("CHATTING.txt",ios::in);
   while(fil.getline(Lin,80))
    cout<<Lin<<endl;
   fil.close();
   delay(100);
  }
  ch=getch();
  if(ch==13)
  {
   char Lin[80];
   fstream fil2;
   fil2.open("CHATTING.txt",ios::app);
   cout<<User<<": ";
   gets(Lin);
   fil2<<User<<": "<<Lin<<endl;
   fil2.close();
  }
 }
}