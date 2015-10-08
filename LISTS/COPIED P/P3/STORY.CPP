/*
  Program no. : 15
  Question    : Define a function intext() to create a text file "story.txt"
		which should contain text lines entered by the user.
		Define another function outext() to read and display each
		word of the above text file on different lines on screen.
		Write a program which uses the above two functions to create
		and display the contents of the above text file.
  Developed by: Akshit Sharma, Akshay Punhani
  Date        : 21-July-2010
*/
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
void intext()
{
  fstream fil;
  fil.open("story.txt",ios::out);
  char lin[80],ch;
  do
  {
   cout<<"Text : ";
     gets(lin);
    fil<<lin<<endl;
   cout<<"Continue(y/n) :";
    cin>>ch;
  }while(ch=='y');
  fil.close();
}
void outtext()
{
 fstream fil;
 fil.open("story.txt",ios::in);
 char lin[10];
 while(!fil.eof())
 {
   fil>>lin;
   cout<<lin<<endl;
 }
 fil.close();
}
void main()
{
 clrscr();
 intext();
 clrscr();
 outtext();
 getch();
}
/*
       SAMPLE OUTPUT
There
was
a
king
and
a
queen
They
lived
peacefully
till
they
died..
*/