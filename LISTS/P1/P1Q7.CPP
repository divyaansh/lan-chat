/*
Program No. : 7
Developed By: Dipankar Behera, Divyaansh Anuj
Date	    : 16-April-2010
*/

/*
Write a program to perform the following operations on an array
of strings (containing Names of countries):
(a) To allow user to enter the names of countries
(b) To display the of names of the countries
(c) To sort the array in descending alphabetical order
(d) To search for a name of a country from the array and display
    "Country registered" else display "Country not registered"
    (using Linear Search)
*/


#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void Input(char [][20],int);
void Output(char [][20],int);
void Sort(char [][20],int);
void Search(char [][20],int,char []);

void main()
{
 clrscr();
 char Country[20][20],search[20];
 int n;
 cout<<"Enter the no. of Countries\n";
 cin>>n;
 cout<<"\nEnter the names of the Countries\n";
 Input(Country,n);
 cout<<"\nThe Countries entered are:-\n";
 Output(Country,n);
 Sort(Country,n);
 cout<<"\nThe Countries in descending alphabetical order are:-\n";
 Output(Country,n);
 cout<<"\nEnter the name of the Country to be searched\n";
 cin>>search;
 Search(Country,n,search);
 getch();
}
void Input(char A[][20],int n)
{
 for(int i=0;i<n;i++)
  gets(A[i]);
}
void Output(char A[][20],int n)
{
 for(int i=0;i<n;i++)
  puts(A[i]);
}
void Sort(char A[][20],int n)
{
 for(int i=0;i<n-1;i++)
 {
  for(int j=0;j<n-i-1;j++)
  {
   if(strcmp(A[j],A[j+1])<0)
   {
    char temp[20];
    strcpy(temp,A[j]);
    strcpy(A[j],A[j+1]);
    strcpy(A[j+1],temp);
   }
  }
 }
}
void Search(char A[][20],int n,char search[20])
{
 int found=0;
 for(int i=0;i<n&&!found;i++)
  if(strcmp(A[i],search)==0)
   found++;
 if(found)
  cout<<"Country registered";
 else
  cout<<"Country not registered";
}

/* OUTPUT***********************************************
Enter the no. of Countries
3

Enter the names of the Countries
uganda
india
aus

The Countries entered are:-
uganda
india
aus **********************************/
                                                                                
The Countries in descending alphabetical order are:-                            
uganda                                                                          
india                                                                           
aus                                                                             
                                                                                
Enter the name of the Country to be searched                                    
eng                                                                             
Country not registered                                                          
                                                                                
                                                                                
                                                                                
                                                                                



