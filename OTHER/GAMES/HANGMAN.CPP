#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include<dos.h>
#include <ctype.h>

int col=35;
void hangman(int wrong)
{
 if(wrong==0)
 {
   gotoxy(37,17);
  cout<<"     |~~~~~~~~~~  ";
   gotoxy(37,18);
  cout<<"     |            ";
   gotoxy(37,19);
  cout<<"     |            ";
   gotoxy(37,20);
  cout<<"     |            ";
   gotoxy(37,21);
  cout<<"     |            ";
   gotoxy(37,22);
  cout<<"     |             ";
   gotoxy(37,23);
  cout<<"     |              ";
 }
 else if(wrong==1)
 {
   gotoxy(37,17);
  cout<<"     |~~~~|~~~~~  ";
   gotoxy(37,18);
  cout<<"     |            ";
   gotoxy(37,19);
  cout<<"     |            ";
   gotoxy(37,20);
  cout<<"     |            ";
   gotoxy(37,21);
  cout<<"     |            ";
   gotoxy(37,22);
  cout<<"     |             ";
   gotoxy(37,23);
  cout<<"     |              ";
 }
 else if(wrong==2)
 {
   gotoxy(37,17);
  cout<<"     |~~~~|~~~~~  ";
   gotoxy(37,18);
  cout<<"     |   {**}     ";
   gotoxy(37,19);
  cout<<"     |            ";
   gotoxy(37,20);
  cout<<"     |            ";
   gotoxy(37,21);
  cout<<"     |            ";
   gotoxy(37,22);
  cout<<"     |             ";
   gotoxy(37,23);
  cout<<"     |              ";
 }
 else if(wrong==3)
 {
   gotoxy(37,17);
  cout<<"     |~~~~|~~~~~  ";
   gotoxy(37,18);
  cout<<"     |   {**}     ";
   gotoxy(37,19);
  cout<<"     |    |        ";
   gotoxy(37,20);
  cout<<"     |    |        ";
   gotoxy(37,21);
  cout<<"     |    |        ";
   gotoxy(37,22);
  cout<<"     |             ";
   gotoxy(37,23);
  cout<<"     |              ";
 }
 else if(wrong==4)
 {
   gotoxy(37,17);
  cout<<"     |~~~~|~~~~~  ";
   gotoxy(37,18);
  cout<<"     |   {**}     ";
   gotoxy(37,19);
  cout<<"     |    |        ";
   gotoxy(37,20);
  cout<<"     |    |\\        ";
   gotoxy(37,21);
  cout<<"     |    |        ";
   gotoxy(37,22);
  cout<<"     |             ";
   gotoxy(37,23);
  cout<<"     |              ";
 }
 else if(wrong==5)
 {
   gotoxy(37,17);
  cout<<"     |~~~~|~~~~~  ";
   gotoxy(37,18);
  cout<<"     |   {**}     ";
   gotoxy(37,19);
  cout<<"     |    |        ";
   gotoxy(37,20);
  cout<<"     |   /|\\        ";
   gotoxy(37,21);
  cout<<"     |    |        ";
   gotoxy(37,22);
  cout<<"     |             ";
   gotoxy(37,23);
  cout<<"     |              ";
 }
 else if(wrong==6)
 {
   gotoxy(37,17);
  cout<<"     |~~~~|~~~~~  ";
   gotoxy(37,18);
  cout<<"     |   {**}     ";
   gotoxy(37,19);
  cout<<"     |    |        ";
   gotoxy(37,20);
  cout<<"     |   /|\\        ";
   gotoxy(37,21);
  cout<<"     |    |        ";
   gotoxy(37,22);
  cout<<"     |     \\        ";
   gotoxy(37,23);
  cout<<"     |              ";
 }
 else if(wrong==7)
 {
   gotoxy(37,17);
  cout<<"     |~~~~|~~~~~  ";
   gotoxy(37,18);
  cout<<"     |   {**}     ";
   gotoxy(37,19);
  cout<<"     |    |        ";
   gotoxy(37,20);
  cout<<"     |   /|\\        ";
   gotoxy(37,21);
  cout<<"     |    |        ";
   gotoxy(37,22);
  cout<<"     |   / \\        ";
   gotoxy(37,23);
  cout<<"     |              ";
 }
}
int check(char a,char word[80])
{
  int y=0;
  for (int i=0;i<strlen(word);i++)
{
  word[i]=toupper(word[i]);
  if (word[i]==a)
  y=1;
}
 if(y==0)
 {
  gotoxy(col,15);
  cout<<a;
  col+=2;
 }
  return (y);
}

int disp(char a,char word[80])
{
  int count=0;
  for (int i=0;word[i]!='\0';i++)
  if(word[i]==a)
  {
   int z = 20+(2*i);
   gotoxy(z,10);
   cout<<a;
   count++;
  }
   return(count);
}

void main()
{    clrscr();
     char word[100];
     int count=1;
     char name[80];
     cout<<"Type in Your Name:" <<endl;
     gets(name);
     cout<<"Welcome To Hangman "<<name<<endl;
     cout<<"The rules of the game are :\n 1.Make a Player enter a word.\n 2.Now another player chooses a letter to fill the blanks before the man hangs\n 3.Choose only one letter at a time\n 4.Press Enter to Continue. \n"<<endl;
     cout<<"Best of Luck !!"<<endl;
     delay(2000);
     getch();
     clrscr();
     cout<<"Player 1 enter the word: ";
     gets(word);
     int spaces=0;
     for(int x=0;word[x]!='\0';x++)
     {
      if(word[x]==' ')
      spaces++;
     }
     clrscr();
     gotoxy(30,1);
     cout<<"HANGMAN";
     char a;
     int q=20;
     for (int w=0;word[w]!='\0';w++)
     {
      if((word[w]>='a' && word[w]<='z') || (word[w]>='A' && word[w]<='Z'))
     {if(word[w]=='a'|| word[w]=='e'||word[w]=='i'||word[w]=='o'||
       word[w]=='u'||word[w]=='A'||word[w]=='E'||word[w]=='I'||
       word[w]=='O'||word[w]=='U')
		{
		  gotoxy(q,10);
		  cout<<word[w];
		}
      else
		{ gotoxy(q,10);
		  cout<<"_ ";
		}
      q+=2;
     }
      else
     {
      gotoxy(q,10);
      cout<<"/ ";
      q+=2;
     }
     }
     cout<<endl;
     int c, ccount=strlen(word);
     int wrong,mxwrong,right=0;
     mxwrong=7;
     wrong=0;
     do
     {
      hangman(wrong);
      gotoxy(5,12);
      cin>>a;
      a=toupper(a);
      gotoxy(5,15);
      cout<<"Wrong characters entered are: ";
      c = check(a,word);
       if (c==1)
       {
	gotoxy(5,13);
	cout<<"Result: Correct   ";
	right++;
	count = disp(a,word);
       }
       else if (c==0)
       {
	gotoxy(5,13);
	cout<<"Result: Try again    ";
	wrong++;
       }
      gotoxy(5,12);
      cout<<"   ";
      delay(1500);
      gotoxy(13,13);
      cout<<"                 ";
      ccount-=(count-1);
      hangman(wrong);
     }while(wrong<mxwrong && right<ccount-spaces);

  if (wrong==mxwrong)
  {
   gotoxy(5,17);
   cout<<"Sorry you lost,";
  }

  else if (right==ccount-spaces)
  {
  gotoxy(5,18);
  cout<<"You won,";
  }
gotoxy(5,19);
cout<<"Thank You For Playing...";
getch();
}
