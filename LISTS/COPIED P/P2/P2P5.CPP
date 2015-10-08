/*
  Program No. : 5
  Developed By: Aayush Sahni
  Date        : 5-May-2010
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct date
{
 int date;
 int month;
 int year;
};
struct student
{
 int admno;
 char sname[20];
 date dob;
};
void enter(student s[],int &n);
void display(student s[],int n);
void check(student s[],int n);
void main()
{
 clrscr();
 student a[10];
 int n;
 enter(a,n);
 clrscr();
 display(a,n);
 check(a,n);
 getch();
}
void enter(student s[],int &n)
{
 do
 {
   cout<<"Enter the no. of students less than 10 : ";
     cin>>n;
 }while(n>10);

 for(int i=0;i<n;i++)
 {
   cout<<"Enter the details of student"<<i+1<<":\n "
       <<"Admission number: ";cin>>s[i].admno;
   cout<<"Student name: ";gets(s[i].sname);
   cout<<"Date of birth: ";cin>>s[i].dob.date>>s[i].dob.month>>s[i].dob.year;

 }
}
void display(student s[],int n)
{
 for(int i=0;i<n;i++)
 { cout<<"Details of student"<<i+1<<" : "<<endl;
   cout<<"Admission number: ";cout<<s[i].admno<<endl;
   cout<<"Student name: ";puts(s[i].sname);
   cout<<"Date of birth: ";cout<<s[i].dob.date<<"-"
			       <<s[i].dob.month<<"-"
			       <<s[i].dob.year<<endl;

 }
}
void check(student s[],int n)
{cout<<"Details of required students : "<<endl;
 int d,m,y;
 for(int i=0;i<n;i++)
 { d=s[i].dob.date;
   m=s[i].dob.month;
   y=s[i].dob.year;
   if(y==1990)
    if((d==1&&m==1)||(d==2&&m==2)||(d==3&&m==3))
     {  cout<<"Details of student"<<endl;
	cout<<"Admission number: ";cout<<s[i].admno<<endl;
	cout<<"Student name: ";puts(s[i].sname);
	cout<<"Date of birth: ";cout<<s[i].dob.date<<"-"
			       <<s[i].dob.month<<"-"
			       <<s[i].dob.year;

     }
  }
}