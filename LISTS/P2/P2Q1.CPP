/*
Program No. :1
Developed By:Dipankar Behera, Divyaansh Anuj, Geet Gupta
Date        :27-Apr-2010
Question    :Declare a structure BOOK with the following members:
	     bno       of type int
	     bname     of type char of size 30
	     author    of type char of size 30
	     price     of type float
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct BOOK
{
  int bno;
  char bname[20],author[20];
  float price;

};

void enter(BOOK [], int);
void display(BOOK [], int);
void searchbno(BOOK [],int,int);
void searchbname(BOOK [],int, char[]);
void main()
{
  clrscr();
  BOOK B[30];
  int n, no;
  char name[20];

  do
   {
    cout<<"Enter the no of books :";
    cin>>n;
   }while(n>10);

   enter(B, n);
   display(B, n);
   cout<<"Enter no. of the book to be searched\n";
   cin>>no;
   searchbno(B, n, no);
   cout<<"\nEnter the name to searched\n";
   gets(name);
   searchbname(B, n, name);

   getch();

}

void enter(BOOK b[],int n)
{

 cout<<"Enter books \n";
 for(int i=0;i<n;i++)
     {
	cout<<"Enter book no. :";
	cin>>b[i].bno;
	cout<<"Enter book name :";
	gets(b[i].bname);
	cout<<"Enter author name :";
	gets(b[i].author);
	cout<<"Enter the price  :";
	cin>>b[i].price;
	cout<<endl;
     }
}

void display(BOOK b[],int n)
{
 for(int i=0;i<n;i++)
       {
	cout<<"Book no.    :"<<b[i].bno<<endl;
	cout<<"Book name   :";
	puts(b[i].bname);
	cout<<"Author name :";
	puts(b[i].author);
	cout<<"Price       :"<<b[i].price<<endl;
       }
}

void searchbno(BOOK b[],int n,int no)
{
  int found=0,i=0;
  while(i<n && !found)
  {
   if(b[i].bno==no)
	found++;
   else
	i++;
  }
  if (found)
  {

    cout<<"Book info\n";
    cout<<"Book no.    :"<<b[i].bno<<endl;
    cout<<"Book name   :";
    puts(b[i].bname);
    cout<<"Author name :";
    puts(b[i].author);
    cout<<"Price       :"<<b[i].price<<endl;

  }
  else
	cout<<"Not present ";
}


void searchbname(BOOK b[],int n,char name[])
{
  int found=0,i=0;
  while(i<n && !found)
  {
   if(strcmp(b[i].bname,name)==0)
	found++;
   else
	i++;
  }
  if (found)
  {
   cout<<"Book info\n";
   cout<<"Book no.    :"<<b[i].bno<<endl;
   cout<<"Book name   :";
   puts(b[i].bname);
   cout<<"Author name :";
   puts(b[i].author);
   cout<<"Price       :"<<b[i].price<<endl;
  }
  else
	cout<<"Not present ";

}
/*
OUTPUT:

Book no.    :1
Book name   :The Kite Runner
Author name :Khaleid Hosseini
Price       :234
Book no.    :2
Book name   :QWERTY
Author name :Alpha singh
Price       :435
Enter no. of the book to be searched
2
Book info
Book no.    :2
Book name   :QWERTY
Author name :Alpha singh
Price       :435

Enter the name to searched
QWERTY
Book info
Book no.    :2
Book name   :QWERTY
Author name :Alpha singh
Price       :435


*/