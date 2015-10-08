#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>

class Student
{
 int Rno;
 char Name[30];
 float Ave;
 public:
  void Input();
  void Output();
  int Rno_();
  char* Name_();
  float Ave_();
};

void CreateFile();
void ReadFile();
void CopyFile();
void WriteFile();
void CreateBinFile();
void ReadBinFile();
void SearchBinFile();
void WriteBinFile();

void main()
{
 clrscr();
 int ch;
 do
 {
  getch();
  cout<<"Menu:-\n1.Create a file\n2.Read from file\n3.Copy a file\n";
  cout<<"4.Write on a file\n5.Create a Binary file\n";
  cout<<"6.Read a Binary file\n7.Search for in a Binary file\n";
  cout<<"8.Write on a Binary file\n9.Exit\nEnter Choice\n";
  cin>>ch;
  switch(ch)
  {
   case 1:CreateFile();break;
   case 2:ReadFile();break;
   case 3:CopyFile();break;
   case 4:WriteFile();break;
   case 5:CreateBinFile();break;
   case 6:ReadBinFile();break;
   case 7:SearchBinFile();break;
   case 8:WriteBinFile();break;
   case 9:cout<<"Thank you\n";break;
   default:cout<<"Wrong choice\n";
  }
 }while(ch!=9);
 getch();
}

/////////////////////////////////////////////////

void Student::Input()
{
 cout<<"Enter Roll No., Name, Average\n";
 cin>>Rno; gets(Name); cin>>Ave;
}

void Student::Output()
{
 cout<<setw(16)<<"Roll No.:"<<Rno<<endl;
 cout<<setw(16)<<"Name:"<<Name<<endl;
 cout<<setw(16)<<"Average:"<<Ave<<endl;
}

int Student::Rno_()
{
 return Rno;
}

char* Student::Name_()
{
 return Name;
}

float Student::Ave_()
{
 return Ave;
}

/////////////////////////////////////////////////

void CreateFile()
{
 char FileName[20],Lin[80],ans;
 cout<<"Enter the file name\n";
 cin>>FileName;
 fstream fil;
 fil.open(FileName,ios::out);
 do
 {
  cout<<"Enter Text:\n\n";
  gets(Lin);
  fil<<Lin<<endl;
  cout<<"Continue? (y/n)";
  cin>>ans;
 }while(ans=='y');
 fil.close();
}

void ReadFile()
{
 char FileName[20],Lin[80];
 cout<<"Enter the file name\n";
 cin>>FileName;
 fstream fil;
 fil.open(FileName,ios::in);
 while(fil.getline(Lin,80))
  cout<<Lin<<endl;
 fil.close();
}

void CopyFile()
{
 char Source[20],Dest[20],Lin[80],ans;
 cout<<"Enter name of source file\n";
 cin>>Source;
 fstream source,dest;
 source.open(Source,ios::in);
 cout<<"Enter name of destination file\n";
 cin>>Dest;
 dest.open(Dest,ios::out);
 while(source.getline(Lin,80))
  dest<<Lin<<endl;
 source.close();
 dest.close();
}

void WriteFile()
{
 char FileName[20],Lin[80],ans;
 cout<<"Enter the file name\n";
 cin>>FileName;
 fstream fil;
 fil.open(FileName,ios::app);
 do
 {
  cout<<"Enter Text:\n\n";
  gets(Lin);
  fil<<Lin<<endl;
  cout<<"Continue? (y/n)";
  cin>>ans;
 }while(ans=='y');
 fil.close();
}

/////////////////////////////////////////////////

void CreateBinFile()
{
 char FileName[20],ans;
 Student S;
 cout<<"Enter the file name\n";
 cin>>FileName;
 fstream fil;
 fil.open(FileName,ios::out|ios::binary);
 do
 {
  S.Input();
  fil.write((char*)&S,sizeof(S));
  cout<<"Continue? (y/n)";
  cin>>ans;
 }while(ans=='y');
 fil.close();
}

void ReadBinFile()
{
 char FileName[20];
 Student S;
 cout<<"Enter the file name\n";
 cin>>FileName;
 fstream fil;
 fil.open(FileName,ios::in|ios::binary);
 while(fil.read((char*)&S,sizeof(S)))
  S.Output();
 fil.close();
}

void SearchBinFile()
{}
void WriteBinFile()
{}
