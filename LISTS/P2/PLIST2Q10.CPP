#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct Account
{
  int acno;
  char name[20];
  float balance;
};
void enter(Account [], int);
void display(Account [], int);
void func(Account [], int);
void main()
{
  clrscr();
  Account A[10];
  int n, ch;
  do
  {
    cout<<"Enter the no. of accounts\n";
    cin>>n;
  }while(n>10);
  cout<<"Choose from the following menu \n";
  cout<<"1. To enter the values in the array of ACCOUNT\n";
  cout<<"2. To display the details of array ACCOUNT passed through parameter\n";
  cout<<"3. To display the details of all ACCOUNTs from arraay of ACCOUNT where Balance > 100000\n";
do
{
  cout<<"Enter your choice (1/2/3)\n";
  cin>>ch;
  switch(ch)
  {
   case 1:enter(A,n);
	  break;
   case 2:display(A,n);
	  break;
   case 3:func(A,n);
	  break;
   case 4:cout<< " Quitting........";
	  break;
   default : cout<<"Invalid Input ";

  }
}while(ch!=4);
  getch();

}

void enter (Account A[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<"Enter account no.\n";
    cin>>A[i].acno;
    cout<<"Enter account name \n";
    cin>>A[i].name;
    cout<<"Enter Balance\n";
    cin>>A[i].balance;
  }
}

void display(Account A[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<"Account no.:"<<A[i].acno;
    cout<<"\nAccount name :"<<A[i].name;
    cout<<"\nEnter Balance :"<<A[i].balance;
  }
}

void func(Account A[], int n)
{
  for(int i=0; i<n; i++)
  if(A[i].balance>100000)
   {
      cout<<"Account Information\n";
      cout<<"Account No. :"<<A[i].acno;
      cout<<"\nAccount name :"<<A[i].name;
      cout<<"\nBalance :"<<A[i].balance;
   }
}
