#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
struct DATE
{
 int Day;
 int Month;
 int Year;
};
struct STUDENT
{
 int Admno;
 char Sname[20];
 DATE DOB;
};
void Display(STUDENT[],int);
void Select(STUDENT[],int);
void main()
{
 clrscr();
 int choice,n;
 STUDENT S[20];
 char ch;
 cout<<"Enter no. of students: "; cin>>n;
 cout<<"Enter Details:\n";
 for(int i=0;i<n;i++)
 {
  cout<<"Admno: "; cin>>S[i].Admno;
  cout<<"Sname: "; gets(S[i].Sname);
  cout<<"DOB (dd mm yyyy): "; cin>>S[i].DOB.Day>>S[i].DOB.Month>>S[i].DOB.Year;
 }
 do
 {
 cout<<"Enter Choice: \n";
 cout<<"1)Display All details\n2)Display Details of Students born on";
 cout<<"01/01/1990 or 02/02/1990 or 03/03/1990\n";
 cin>>choice;
 switch(choice)
 {
  case 1: cout<<"DISPLAYING.....\n";
	  Display(S,n);
	  break;
  case 2: cout<<"DISPLAYING SELECT RECORDS.....\n";
	  Select(S,n);
	  break;
  default: cout<<"Wrong choice"<<endl;
 }
 cout<<"\nDo you wish to continue? (y/n): ";
 cin>>ch;
 } while (ch=='y');
}
void Display(STUDENT S[],int n)
{
 for(int i=0;i<n;i++)
 {
  cout<<"Admno: "<<S[i].Admno<<endl;
  cout<<"Sname: "; puts(S[i].Sname);
  cout<<"DOB (dd mm yyyy):"<<S[i].DOB.Day<<" "<<S[i].DOB.Month;
  cout<<" "<<S[i].DOB.Year<<endl;
 }
}

void Select(STUDENT S[],int n)
{
 for(int i=0;i<n;i++)
 {
  if(S[i].DOB.Day==01 && S[i].DOB.Month==01 && S[i].DOB.Year==1990)
  {
   cout<<"Admno: "<<S[i].Admno<<endl;
   cout<<"Sname: "; puts(S[i].Sname);
   cout<<"DOB (dd mm yyyy): "<<S[i].DOB.Day<<" ";
   cout<<S[i].DOB.Month<<" "<<S[i].DOB.Year;
  }
  else
  if(S[i].DOB.Day==02 && S[i].DOB.Month==02 && S[i].DOB.Year==1990)
  {
   cout<<"Admno: "<<S[i].Admno<<endl;
   cout<<"Sname: "; puts(S[i].Sname);
   cout<<"DOB (dd mm yyyy): "<<S[i].DOB.Day<<" ";
   cout<<S[i].DOB.Month<<" "<<S[i].DOB.Year;
  }
  else
  if(S[i].DOB.Day==03 && S[i].DOB.Month==03 && S[i].DOB.Year==1990)
  {
   cout<<"Admno: "<<S[i].Admno<<endl;
   cout<<"Sname: "; puts(S[i].Sname);
   cout<<"DOB (dd mm yyyy): "<<S[i].DOB.Day<<" ";
   cout<<S[i].DOB.Month<<" "<<S[i].DOB.Year;
  }
 }
}

/*
OUTPUT:

Enter no. of students: 2
Enter Details:
Admno: 101
Sname: Lokpriya
DOB (dd mm yyyy): 01 01 1990
Admno: 102
Sname: Lavanya
DOB (dd mm yyyy): 14 07 1993
Enter Choice:
1)Display All details
2)Display Details of Students born on01/01/1990 or 02/02/1990 or 03/03/1990
1
DISPLAYING.....
Admno: 101
Sname: Lokpriya
DOB (dd mm yyyy):1 1 1990
Admno: 102
Sname: Lavanya
DOB (dd mm yyyy):14 7 1993

Do you wish to continue? (y/n): y

Enter Choice:
1)Display All details
2)Display Details of Students born on01/01/1990 or 02/02/1990 or 03/03/1990
2
DISPLAYING SELECT RECORDS.....
Admno: 101
Sname: Lokpriya
DOB (dd mm yyyy): 1 1 1990
Do you wish to continue? (y/n): n
*/

