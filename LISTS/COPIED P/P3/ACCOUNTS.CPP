
/*
  Program no. : 19
  Question    : Define a class Account with following members :
		private: int acno
			string name
			float balance
		public: void init() - to input the details
			void show() - to display the details
			void deposit(int amt) - to increase balance
			void withdraw(int amt) - to reduce balance
			float rbalane() - to return balance
		Define a function Register() to create a binary file
		Accounts.dat to enter the details by user
		Define a function transact() to withdraw or deposit money.
		The minimum balance should be 500.
		Define a function display to details all the details.

  Developed by: Aayush Sahni, Aala Saifi
  Date        : 21-July-2010
*/
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class account
{
  int acno;
  char name[20];
  float balance;
 public:
  void init();
  void show();
  void deposit(int amt);
  void withdraw(int amt);
  float rbalance();
  int racno();
};
void account::init()
{
 cout<<"Enter the details : "<<endl;
 cout<<"Account no. : "; cin>>acno;
 cout<<"Name : "; gets(name);
 cout<<"Balance : "; cin>>balance;
}
void account::show()
{
 cout<<"Account no. : "<<acno<<endl;
 cout<<"Name : "<<name<<endl;
 cout<<"Balance : "<<balance<<endl;
}
void account::deposit(int amt)
{
 balance+=amt;
 cout<<"The new balance is "<<balance<<endl;
}
void account::withdraw(int amt)
{
 if((balance-amt)>=500)
  {
    balance-=amt;
    cout<<"Your new balance is "<<balance<<endl;
  }
 else
   cout<<"You cannot withdraw. Not enough balance"<<endl;
}
float account::rbalance()
{
 return balance;
}
int account::racno()
{
 return acno;
}

void Register()
{
 fstream fil;
 fil.open("Account.dat",ios::binary|ios::out);
 account a;char ch;
 do
 {
  a.init();
  fil.write((char*)&a,sizeof(a));
  cout<<"Continue(y/n): ";
  cin>>ch;
 }while(ch=='y');
 cout<<"The details have been entered"<<endl;
 fil.close();
}
void transact()
{
 fstream fil;
 fil.open("Account.dat",ios::binary|ios::in|ios::out);
 account a;
 int n,amt,ac,j=0;
 cout<<"Enter the account no. you want to transact:";
 cin>>ac;
 while(fil.read((char*)&a,sizeof(a)))
 {
  if(a.racno()==ac)
  {
    cout<<"1.Deposit	2.Withdraw"<<endl;
    cout<<"Enter your choice: ";
    cin>>n;
     if(n==1)
      {
       cout<<"Enter the amount to be deposited :";
       cin>>amt;
       a.deposit(amt);
      }
     else
     if(n==2)
      {
       cout<<"Enter the amount to be withdrawn :";
       cin>>amt;
       a.withdraw(amt);
      }
  }
  else
   cout<<"The required account does not exist"<<endl;
 fil.seekg(j*sizeof(a),ios::beg);
 fil.write((char*)&a,sizeof(a));
 j++;
 }
fil.close();
}
void displayall()
{
 fstream fil;
 fil.open("Account.dat",ios::binary|ios::in);
 account a;
 while(fil.read((char*)&a,sizeof(a)))
   a.show();
 fil.close();
}
void main()
{
 clrscr();
 int n;char ch;
 do
 {
  cout<<"1. Register the details"<<endl
      <<"2. Transact an account"<<endl
      <<"3. Display all the details"<<endl
      <<"Enter your choice : ";
  cin>>n;
   switch(n)
   {
    case 1: Register();
	    break;
    case 2: transact();
	    break;
    case 3: displayall();
	    break;
    default: cout<<"Enter a correct choice."<<endl;
   }
  cout<<"Continue(y/n): ";
  cin>>ch;
 }while(ch=='y');

getch();
}











