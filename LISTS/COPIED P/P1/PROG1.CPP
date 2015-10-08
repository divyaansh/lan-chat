/*
  Program no. :1
  Developed by:Aayush Sahni, Aala Saifi
  Date        :06-april-2010
*/
#include<iostream.h>
#include<conio.h>
void series1(int x,int n);
void series2(int x,int n);
void series3(int n);
void main()
{
 clrscr();
 int a,n,x;
 cout<<"Enter the series you want to display :\n"
     <<"1.x+x^2+x^3+....... N times\n"
     <<"2.u+u^2/2!+u^3/3!.. N times\n"
     <<"3.2+(2+4).......... N times\n";
 cin>>a;
 switch(a)
 {
   case 1:cout<<"Enter the value of x :";
	  cin>>x;
	  cout<<"Enter the value of n :";
	  cin>>n;
	  series1(x,n);
	  break;
   case 2:cout<<"Enter the value of u :";
	  cin>>x;
	  cout<<"Enter the value of n :";
	  cin>>n;
	  series2(x,n);
	  break;
   case 3:cout<<"Enter the value of n :";
	  cin>>n;
	  series3(n);
	  break;
   default:cout<<"Enter a correct choice!!!";
 }
 getch();
}
void series1(int x,int n)
{
 int sum=0,pro;
  for(int i=1;i<=n;i++)
   {
    pro=1;
     for(int j=1;j<=i;j++)
	  pro*=x;
    sum+=pro;
   }
 cout<<"The sum of the given series is :"<<sum;
}
void series2(int x,int n)
{
 long pro,fact;
 float sum=0;

  for(int i=1;i<=n;i++)
   {
    pro=1,fact=1;
     for(int j=1;j<=i;j++)
      {	  pro*=x;
	  fact*=j;
      }
    sum+=(float)pro/fact;
   }
 cout<<"The sum of the given series is :"<<sum;
}
void series3(int n)
{
int sum=0;
 for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
	 sum+=2*j;
 cout<<"The sum of the given series is :"<<sum;
}

/*
       SAMPLE OUTPUT 1
Enter the series you want to display :
1.x+x^2+x^3+....... N times
2.u+u^2/2!+u^3/3!.. N times
3.2+(2+4).......... N times
1
Enter the value of x :2
Enter the value of n :3
The sum of the given series is :14

       SAMPLE OUTPUT 2
Enter the series you want to display :
1.x+x^2+x^3+....... N times
2.u+u^2/2!+u^3/3!.. N times
3.2+(2+4).......... N times
2
Enter the value of u :2
Enter the value of n :3
The sum of the given series is :5.333333

	    SAMPLE OUTPUT 3
Enter the series you want to display :
1.x+x^2+x^3+....... N times
2.u+u^2/2!+u^3/3!.. N times
3.2+(2+4).......... N times
3
Enter the value of n :3
The sum of the given series is :20

*/








                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
