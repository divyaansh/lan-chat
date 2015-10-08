/*
  Program No. : 2
  Developed By: Aayush Sahni,Aala Saifi
  Date        : 4-May-2010
*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct candidate
{
 int cno,score;
 char cname[20];
};
void enter(candidate c[],int &n);
void display(candidate c[],int n);
void bsort(candidate c[],int n);
void main()
{
 clrscr();
 candidate a[10];
 int n,choice,choice1,choice2;



 cout<<"Enter Your Choice"<<endl;
 cout<<"1.Enter Details "<<endl;
 cout<<"2.Display Details"<<endl;
 cout<<"3.Sort Details"<<endl;
 cin>>choice;
 switch(choice)
 {case 1 : enter(a,n); ;
	   break;
  case 2 : display(a,n);;
	   break;
  case 3 : bsort(a,n);;
	   break;
  default: cout<<"Please Re-enter";
  }
cout<<"Enter Your Choice 2"<<endl;
 cout<<"1.Enter Details "<<endl;
 cout<<"2.Display Details"<<endl;
 cout<<"3.Sort Details"<<endl;
 cin>>choice1;
 switch(choice1)
 {case 1 : enter(a,n); ;
	   break;
  case 2 : display(a,n);;
	   break;
  case 3 : bsort(a,n);;
	   break;
  default: cout<<"Please Re-enter";
  }
cout<<"Enter Your Choice"<<endl;
 cout<<"1.Enter Details "<<endl;
 cout<<"2.Display Details"<<endl;
 cout<<"3.Sort Details"<<endl;
 cin>>choice2;
 switch(choice2)
 {case 1 : enter(a,n); ;
	   break;
  case 2 : display(a,n);;
	   break;
  case 3 : bsort(a,n);;
	   break;
  default: cout<<"Please Re-enter";
  }

  getch();
}
void enter(candidate c[],int &n)
{
 do
 {
   cout<<"Enter the no. of elements less than 10 : ";
     cin>>n;
 }while(n>10);

 for(int i=0;i<n;i++)
 {
   cout<<"Enter the candidate"<<i+1<<" and his details "<<":\n "
       <<"Candidate number: ";cin>>c[i].cno;
   cout<<"Candidate name: ";gets(c[i].cname);
   cout<<"Candidate score: ";cin>>c[i].score;

 }
}
void display(candidate c[],int n)
{
 for(int i=0;i<n;i++)
 { cout<<"Details of candidate"<<i+1<<" : ";
   cout<<"Candidate number: ";cout<<c[i].cno<<endl;
   cout<<"Candidate name: ";puts(c[i].cname);
   cout<<"Candidate score: ";cout<<c[i].score<<endl;

 }
}
void bsort(candidate c[],int n)
{
 int temp;
  for(int i=0;i<n-1;i++)
   for(int j=0;j<n-i-1;j++)
     if(c[j].score>c[j+1].score)
     {
       temp=c[j].score;
       c[j].score=c[j+1].score;
       c[j+1].score=temp;
     }
 cout<<"After sorting :";
 display(c,n);

}