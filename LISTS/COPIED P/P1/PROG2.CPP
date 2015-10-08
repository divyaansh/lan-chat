/*
  Program no. :2
  Developed by:Aayush Sahni, Aala Saifi
  Date        :06-april-2010
*/

#include<iostream.h>
#include<conio.h>
int prime(int n);
int palindrome(int n);
void main()
{
 clrscr();
 int n,a,x;
 cout<<"Enter a no. :";
 cin>>n;
 cout<<"Enter your choice of program :\n"
     <<"1.Prime\n"
     <<"2.Palindrome\n";
 cin>>a;
 switch(a)
 {
  case 1:x=prime(n);
	 cout<<'\n'<<x;
	 break;
  case 2:x=palindrome(n);
	 cout<<'\n'<<x;
	 break;
  default:cout<<"Enter a correct choice";
 }
 getch();
}

int prime(int n)
{
 int flag=0;
  for(int i=2;i<=n/2;i++)
    if(n%i==0)
      flag++;
 if(!flag)
   return 1;
 else
   return 0;
}
int palindrome(int n)
{
 int rev=0,rem,temp=n;
   while(temp!=0)
   {
    rem=temp%10;
    rev=rev*10+rem;
    temp/=10;
   };
 if(rev==n)
  return 1;
 else
  return 0;
}

/*
     SAMPLE OUTPUT

Enter a no. :37
Enter your choice of program :
1.Prime
2.Palindrome
1

1

Enter a no. :1331
Enter your choice of program :
1.Prime
2.Palindrome
2

1
*/


































































