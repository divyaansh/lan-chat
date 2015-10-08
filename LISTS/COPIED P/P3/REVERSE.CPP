#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>

void revtext()
{
  fstream fil;
  fil.open("story.txt",ios::in);
  char lin[80],temp;
  int i,j;
  while(fil.getline(lin,80))
  {
    if(lin[0]=='T')
    {  i=strlen(lin)-1;
       j=0;
       while(j<=i/2)
       {
	 temp=lin[j];
	 lin[j]=lin[i-j];
	 lin[i-j]=temp;
	 j++;
       }
       puts (lin);
    }
  }
 fil.close();
}
void main()
{
 clrscr();
 revtext();
 getch();
}