/*List no.: 1
  Program:5 
 Developed by Dipankar Behera, Divyaansh Anuj
 Dated-16-April-2010
  Write a program to perform the following functions of two dimensional arrays of type integer(using separarte function for each)
  (a) To enter the content of the array(matrix)
  (b) To display the content of the array(matrix)
  (c) To display the transpose of an array(matrix)
  (d) To add the contents of the two arrays and store the  sum in third array(matrix)
  (e) To subtract an array from another array and store the difference in third array(matrix)
  */
#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
void Input(int [][50],int,int);
void Output(int [][50], int,int);
void Transpose(int [][50],int,int);
void Sum(int [][50], int[][50], int [][50], int, int);
void Subtract(int [][50], int [][50],int[][50], int, int);
void main()
{
 clrscr();
 int A[50][50], B[50][50];
 int sum[50][50],sub[50][50];
 int n,m;
 cout<<"Enter the no. of rows\n";
 cin>>m;
 cout<<"Enter the no. of columns\n";
 cin>>n;
 cout<<"Enter the contents of the array\n";
 Input(A,m,n);
 cout<<"The array entered is:\n";
 Output(A,m,n);
 cout<<"the Transpose of the given array is\n";
 Transpose(A,m,n);
 cout<<"Enter the contents of another array\n";
 Input(B,m,n);
 cout<<"The array entered is:\n";
 Output(B,m,n);
 Sum(A,B,sum,m,n);
 cout<<"The Sum of the two arrays is:\n";
 Output(sum,m,n);
 Subtract(A,B,sub,m,n);
 cout<<"The Difference of the two arrays is:\n";
 Output(sub,m,n);
 getch();
}

void Input(int A[][50], int r, int c)
{
 for(int i=0;i<r;i++)
  for(int j=0;j<c;j++)
   cin>>A[i][j];
}
void Output(int A[][50], int r, int c)
{
 for(int i=0;i<r;i++)
 {
  for(int j=0;j<c;j++)
  {
   cout<<setw(5)<<A[i][j];
  }
  cout<<endl;
 }
}
void Transpose(int A[][50], int r, int c)
{
 int C[50][50];
 if(r==c)
 {
  for(int i=0;i<r;i++)
  {
   for(int j=0;j<i;j++)
   {
    A[i][j]=A[j][i]+A[i][j];
    A[j][i]=A[i][j]-A[j][i];
    A[i][j]=A[i][j]-A[j][i];
   }
  }
  Output(A,r,c);
 }
 else
  cout<<"No transpose possible";
}
void Sum(int A[][50],int B[][50],int C[][50], int r, int c)
{
 for(int i=0;i<r;i++)
  for(int j=0;j<c;j++)
   C[i][j]=A[i][j]+B[i][j];
}
void Subtract(int A[][50],int B[][50],int C[][50], int r, int c)
{
 for(int i=0;i<r;i++)
  for(int j=0;j<c;j++)
   C[i][j]=A[i][j]-B[i][j];
}

/*
Enter the contents of an array
1
2
3
4
The array entered is:
    1    2
    3    4                                                                      
the Transpose of the given array is
    1    3                                                                      
    2    4
Enter the contents of another array
2
2
4
4                                                                               
The array entered is:                                                           
    2    2                                                                      
    4    4                                                                      
The Sum of the two arrays is:                                                   
    3    5                                                                      
    6    8                                                                      
The Difference of the two arrays is:                                            
   -1    1                                                                      
   -2    0                                                                      
                                                                                
