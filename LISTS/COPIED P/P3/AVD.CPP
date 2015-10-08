#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<ctype.h>
void countavd()
{
 fstream fil;
 fil.open("story.txt",ios::in);
 char ch;
 int a=0,v=0,d=0;
 while(!fil.eof())
 {
  ch=fil.get();
  cout<<ch;
  ch=tolower(ch);
  if(isalpha(ch))
   {
     a++;
       if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
	  v++;
   }
  else
  if(isdigit(ch))
     d++;
 }
 cout<<"The number of alphabets is : "<<a<<endl;
 cout<<"The number of vowels is : "<<v<<endl;
 cout<<"The number of digits is : "<<d;
fil.close();
}
void main()
{
 clrscr();
 countavd();
 getch();
}


