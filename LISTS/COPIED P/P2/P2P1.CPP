/*
  Program No. : 1
  Developed By: Aayush Sahni
  Date        : 27-April-2010
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct book
{
   int bno;
   char bname[80],author[80];
   float price;
};
void enter(book b[],int &n);
void display(book b[],int n);
void searchno(book b[],int n);
void searchname(book b[],int n);
void main()
{
 clrscr();
 book a[80];
 int n,choice;
 enter(a,n);
 display(a,n);
 cout<<"Enter Your Choice"<<endl;
 cout<<"1.Search Your Option Using Book No."<<endl;
 cout<<"2.Search Your Option Using Book Name"<<endl;
 cin>>choice;
 switch(choice)
 {case 1 : searchno(a,n);
	   break;
  case 2 : searchname(a,n);
	   break;
  default: cout<<"Please Re-enter";
  }
 getch();
}
void enter(book b[],int &n)
{
 do
 {
   cout<<"Enter the no. of elements less than 10 : ";
     cin>>n;
 }while(n>10);

 for(int i=0;i<n;i++)
 {
   cout<<"Enter the book"<<i+1<<" and its details "<<":\n "
       <<"Book number: ";cin>>b[i].bno;
   cout<<"Book name: ";gets(b[i].bname);
   cout<<"Book author: ";gets(b[i].author);
   cout<<"Book price: ";cin>>b[i].price;

 }
}
void display(book b[],int n)
{
 for(int i=0;i<n;i++)
 { cout<<"Details of book"<<i+1<<" : ";
   cout<<"Book number: ";cout<<b[i].bno<<endl;
   cout<<"Book name: ";puts(b[i].bname);
   cout<<"Book author: ";puts(b[i].author);
   cout<<"Book price: ";cout<<b[i].price<<endl;

 }
}
void searchno(book b[],int n)
{
 int data;
 int found=0,i=0;
 cout<<"Enter the book no. you want to search: ";
  cin>>data;
 while((i<n)&&(!found))
 {
   if(data==b[i].bno)
      found++;
   else
      i++;
 }
 if(!found)
  cout<<"Data not found"<<endl;
 else
  cout<<"Data found at"<<i+1<<endl;
}
void searchname(book b[80],int n)
{
 char data[20];
 int found=0,i=0;
 cout<<"Enter the book name you want to search: ";
  gets(data);
 while((i<n)&&(!found))
 {
   if(strcmpi(data,b[i].bname)==0)
      found++;
   else
      i++;
 }
 if(!found)
  cout<<"Data not found";
 else
  cout<<"Data found at "<<i+1;
}
