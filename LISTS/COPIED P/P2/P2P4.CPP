/*
  Program No. : 4
  Developed By: Aaysuh Sahni,Aala Saifi
  Date        : 4-May-2010
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct flight
{
 int flno;
 char deptime[20],arrtime[20];
 float fare;
};
void enter(flight f[],int &n);
void display(flight f[],int n);
void lowest(flight f[],int n);
void main()
{
 clrscr();
 flight a[10];
 int n;
 enter(a,n);
 display(a,n);
 lowest(a,n);
 getch();
}
void enter(flight f[],int &n)
{
 do
 {
   cout<<"Enter the no. of flights less than 10 : ";
     cin>>n;
 }while(n>10);

 for(int i=0;i<n;i++)
 {
   cout<<"Enter the detalis of flight"<<i+1<<":\n "
       <<"Flight number: ";cin>>f[i].flno;
   cout<<"Departure time: ";gets(f[i].deptime);
   cout<<"Arrival time: ";gets(f[i].arrtime);
   cout<<"Fare: ";cin>>f[i].fare;

 }
}
void display(flight f[],int n)
{
 for(int i=0;i<n;i++)
 { cout<<"Details of flight"<<i+1<<" : "<<endl;
   cout<<"Flight number: ";cout<<f[i].flno<<endl;
   cout<<"Departure time: ";puts(f[i].deptime);
   cout<<"Arrival time: ";puts(f[i].arrtime);
   cout<<"Fare: ";cout<<f[i].fare<<endl;

 }
}
void lowest(flight f[],int n)
{
 float low=f[0].fare;
 int x=0;
  for(int i=1;i<n;i++)
    if(f[i].fare<low)
     {
	x= i;
     }
 cout<<"The flight with the lowest fare is :"<<endl;
 cout<<"Flight number: ";cout<<f[x].flno<<endl;
 cout<<"Departure time: ";puts(f[x].deptime);
 cout<<"Arrival time: ";puts(f[x].arrtime);
 cout<<"Fare: ";cout<<f[x].fare<<endl;
}
