#include <iostream.h>
#include <conio.h>
#include<string.h>
void enterarray(BOOK [],int);
void displarray(BOOK [],int);
void bnosearch(BOOK [],int);
void bnamesearch(BOOK [],int);

class BOOK
{
 int bno;
 char bname[20];
 char author[20];
 float price;
 public:
 void enter()
  {
   cout<<"enter the values::";
   cout<<"BOOK NUMBER::";
   cin>>bno;
   cout<<"BOOK NAME::";
   gets(bname);
   cout<<"AUTHOR::";
   cin>>author;
   cout<<"PRICE::";
   cin>>price;
  }
  void display()
  {
   cout<<"BOOK NUMBER::";
   cout<<bno;
   cout<<"BOOK NAME::";
   puts(bname);
   cout<<"AUTHOR::";
   cout<<author;
   cout<<"PRICE::";
   cout<<price;
  }
 int rbno()
  {
    return bno;
  }
 char *rbname()
  {
   return bname;
  }

}
void main()
{
 BOOK B[20]; int n;
 cout<<"enter the number of elements";
 cin>>n;
 cout<<"enter the elements and their details";
 for(int i=0;i<n;i++)
 cin>>B[i];





}


