#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
void main()
{
 randomize();
 int num=1000,ans;
 do
 {
  clrscr();
  int i=1,w=0,p,money=0,loss=0,n=1,least=0;
  cout<<"Prob. of Win out of 100: ";
  cin>>p;
  while(i++<=num)
  {
   int win=random(100);
   n=loss?2*n:1;
   if(win>=0 && win<p)
   {
    w++;
    money+=n;
    loss=0;
   }
   else
   {
    money-=n;
    loss=1;
   }
   least=(money<least)?money:least;
  }
  cout<<"WIN %="<<(double)w*100/num;
  cout<<"\nMONEY="<<money;
  cout<<"\nLEAST="<<least;
  cout<<"\nContinue?(1/0): ";
  cin>>ans;
 }while(ans);
 cout<<"Thanks!\n";
 getch();
}
