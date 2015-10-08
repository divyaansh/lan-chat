/*
  Program no. :6
  Developed by:Aayush Sahni,Aala Saifi
  Date        :27-april-2010
*/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
void words(char s[])
{
 int w=1;
  for(int i=0;s[i]!='\0';i++)
     if(s[i]==' ')
	w++;
 cout<<"The no. of words in the string is: "<<w<<endl;
}
void vowcons(char s[])
{
 int v=0,c=0;
 char w;
  for(int i=0;s[i]!='\0';i++)
   {
     w=tolower(s[i]);
     if(w=='a'||w=='e'||w=='i'||w=='o'||w=='u')
       v++;
     else
     if(w!=' ')
       c++;
   }
 cout<<"The no. of consonants is "<<c<<" and the no. of vowels is "<<v<<endl;
}
void reverse(char s[])
{ char temp;
  for(int i=0;s[i]!='\0';i++);
   i--;
  int j=0;
  while(j<=i/2)
   {
    temp=s[j];
    s[j]=s[i-j];
    s[i-j]=temp;
    j++;
   };

}
void main()
{
 clrscr();
 char a[80];
 cout<<"Enter the  string: ";
 gets(a);
 words(a);
 vowcons(a);
 reverse(a);
 cout<<"The reverse of the given string is : ";
 puts(a);
 getch();
}

/*
       OUTPUT

Enter the  string: Aayush
The no. of words in the string is: 1
The no. of consonants is 3 and the no. of vowels is 3
The reverse of the given string is : hsuyaA
*/
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

                                                                                
                                                                                
                                                                                


                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                



