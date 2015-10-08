/*
  Program no. :5
  Developed by:Aayush Sahni, Aala Saifi
  Date        :20-april-2010
*/
#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
void enter(int A[][5],int &m,int &n)
{
 do
 {
  cout<<"Enter the no. of rows and columns less than 5 :";
  cin>>m>>n;
 }while((m>5)&&(n>5));
 for(int i=0;i<m;i++)
   for(int j=0;j<n;j++)
    {
     cout<<"Enter element ["<<i<<"]["<<j<<"] :" ;
     cin>>A[i][j];
    }
}
void display(int A[][5],int m,int n)
{
 cout<<endl;
 for(int i=0;i<m;i++)
 {
  for(int j=0;j<n;j++)
   cout<<setw(3)<<A[i][j];
  cout<<endl;
 }
}
void transpose(int A[][5],int m,int n)
{
 cout<<"The transpose is: "<<endl;
 for(int j=0;j<n;j++)
 {
   for(int i=0;i<m;i++)
    cout<<setw(3)<<A[i][j];
   cout<<endl;
 }
}
void add(int A[][5],int B[][5],int C[][5],int m,int n)
{
 cout<<"The addition is : ";
  for(int i=0;i<m;i++)
   for(int j=0;j<n;j++)
     C[i][j]=A[i][j]+B[i][j];
  display(C,m,n);
}
void subtract(int A[][5],int B[][5],int C[][5],int m,int n)
{
 cout<<"The subtraction is : ";
  for(int i=0;i<m;i++)
   for(int j=0;j<n;j++)
     C[i][j]=A[i][j]-B[i][j];
  display(C,m,n);
}

void main()
{
 clrscr();
 int A[5][5],B[5][5],C[5][5],D[5][5],n,m,p,q;
 enter(A,m,n);
 enter(B,p,q);
 display(A,m,n);
 display(B,p,q);
 transpose(A,m,n);
 transpose(B,p,q);
 if((m==p)&&(n==q))
 {
  add(A,B,C,m,n);
  subtract(A,B,D,m,n);
 }
 else
  cout<<"Arrays cannot be added and subtracted";
 getch();
}
/*
      OUTPUT

Enter element [1][1] :5
Enter the no. of rows and columns less than 5 :2 2                              
Enter element [0][0] :5                                                         
Enter element [0][1] :6                                                         
Enter element [1][0] :3                                                         
Enter element [1][1] :9                                                         
                                                                                
  1  2                                                                          
  4  5                                                                          
                                                                                
  5  6                                                                          
  3  9                                                                          
The transpose is:                                                               
  1  4                                                                          
  2  5                                                                          
The transpose is:                                                               
  5  3                                                                          
  6  9                                                                          
The addition is :                                                               
  6  8                                                                          
  7 14                                                                          
The subtraction is :                                                            
 -4 -4                                                                          
  1 -4
  */
                                                                                

