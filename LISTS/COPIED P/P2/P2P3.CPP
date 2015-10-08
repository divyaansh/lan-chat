/*
  Program No. : 2
  Developed By: Aayush Sahni, Aala Saifi
  Date        : 27-April-2010
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct account
{
 int acno;
 char name[20];
 float balance;
};
void enter(account a[],int &n);
void display(account a[],int n);
void gbal(account a[],int n);
void main()
{
 clrscr();
 account a[10];
 int n,choice,choice1,choice2;
 cout<<"Enter Your Choice"<<endl;
 cout<<"1.Enter Details "<<endl;
 cout<<"2.Display Details"<<endl;
 cout<<"3.Big Balance Holders"<<endl;
 cin>>choice;
 switch(choice)
 {case 1 : enter(a,n);
	   break;
  case 2 : display(a,n);
	   break;
  case 3 :  gbal(a,n);
	   break;
  default: cout<<"Please Re-enter";
  }

 cout<<"Enter Your Choice 2"<<endl;
 cout<<"1.Enter Details "<<endl;
 cout<<"2.Display Details"<<endl;
 cout<<"3.Big Balance Holders"<<endl;
 cin>>choice1;
 switch(choice1)
 {case 1 : enter(a,n);
	   break;
  case 2 : display(a,n);
	   break;
  case 3 :  gbal(a,n);
	   break;
  default: cout<<"Please Re-enter";
 }
  cout<<"Enter Your Choice"<<endl;
 cout<<"1.Enter Details "<<endl;
 cout<<"2.Display Details"<<endl;
 cout<<"3.Big Balance Holders"<<endl;
 cin>>choice2;
 switch(choice2)
 {case 1 : enter(a,n);
	   break;
  case 2 : display(a,n);
	   break;
  case 3 :  gbal(a,n);
	   break;
  default: cout<<"Please Re-enter";
   }


 getch();
}
void enter(account a[],int &n)
{
 do
 {
   cout<<"Enter the no. of elements less than 10 : ";
     cin>>n;
 }while(n>10);

 for(int i=0;i<n;i++)
 {
   cout<<"Enter the detalis of account"<<i+1<<":\n "
       <<"Account number: ";cin>>a[i].acno;
   cout<<"Account holder's name: ";gets(a[i].name);
   cout<<"Balance: ";cin>>a[i].balance;

 }
}
void display(account a[],int n)
{
 for(int i=0;i<n;i++)
 { cout<<"Details of account"<<i+1<<" : "<<endl;
   cout<<"Account number: ";cout<<a[i].acno<<endl;
   cout<<"Account holder's name: ";puts(a[i].name);
   cout<<"Balance: ";cout<<a[i].balance<<endl;

 }
}
void gbal(account a[],int n)
{
 cout<<"\n\nDetails of those  whose balance is  greater than  100000 "<<endl;
 for(int i=0;i<n;i++)
 {
   if (a[i].balance>100000)
   { cout<<"Account number: ";cout<<a[i].acno<<endl;
     cout<<"Account holder's name: ";puts(a[i].name);
     cout<<"Balance: ";cout<<a[i].balance<<endl;
   }
   cout<<endl;
 }
}

/*
	SAMPLE OUTPUT
Details of account1 :
Account number: 1
Account holder's name: Aayush Sahni
Balance: 1000000
Details of account2 :
Account number: 2
Account holder's name: Aala Saifi
Balance: 50000


Details of those  whose balance is  greater than  100000
Account number: 1
Account holder's name: Aayush Sahni
Balance: 1000000
*/


                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
