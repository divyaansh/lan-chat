/*
  Program no.   :7
  Developed by  :Aayush Sahni, Aala Saifi
  Date          :27-april-2010
*/

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void enter(char s[10][40],int n)
{
 for(int i=0;i<n;i++)
 {
  cout<<"Enter the name of country "<<i+1<<" : ";
  gets(s[i]);
 }
}
void display(char s[10][40],int n)
{
 for(int i=0;i<n;i++)
    puts(s[i]);
}
void sort(char s[10][40],int n)
{ char temp[40];
  int big;
   for(int i=0;i<n-1;i++)
     {
       big=i;

      for(int j=i+1;j<n;j++)
       {
	 if(strcmpi(s[big],s[j])<0)
	    big=j;
       }
    if(big!=i)
    {
      strcpy(temp,s[big]);
      strcpy(s[big],s[i]);
      strcpy(s[i],temp);
    }
     }
  cout<<"The sorted array is: "<<endl;
    display(s,n);
}
void lsearch(char s[10][40],int n)
{
 char data[40];
 int found=0,i=0;
 cout<<"Enter the data you want to search: ";
  gets(data);
 while((i<n)&&(!found))
 {
   if(strcmpi(data,s[i])==0)
      found++;
   else
      i++;
 }
 if(!found)
  cout<<"Country Not Registered";
 else
  cout<<"Country Registered At Position : "<<i+1;
}

void main()
{
 clrscr();
 char c[10][40];
 int n;
 do
 {
  cout<<"Enter the no. of countries you want to enter (<10) : ";
   cin>>n;
 }while(n>10);
 enter(c,n);
 display(c,n);
 sort(c,n);
 lsearch(c,n);
 getch();
}
/*
    OUTPUT

Enter the no. of countries you want to enter (<10) : 4
Enter the name of country 1 : INDIA                                             
Enter the name of country 2 : AUSTRALIA                                         
Enter the name of country 3 : SRILANKA                                          
Enter the name of country 4 : WEST INDIES                                       
INDIA                                                                           
AUSTRALIA                                                                       
SRILANKA                                                                        
WEST INDIES                                                                     
The sorted array is:                                                            
AUSTRALIA                                                                       
INDIA                                                                           
SRILANKA                                                                        
WEST INDIES
Enter the data you want to search: INDIA
Country Registered At Position : 2
*/
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                




                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
