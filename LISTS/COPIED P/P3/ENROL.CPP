#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
class candidate
{
  int cno;
  char cname[20];
  int score;
 public:
  void enter();
  void display();
  int rscore();
};
void candidate::enter()
{
 cout<<"Enter the details of the candidate : "<<endl;
 cout<<"Candidate number : ";cin>>cno;
 cout<<"Candidate name : ";gets(cname);
 cout<<"Candidate score : ";cin>>score;
}
void candidate::display()
{
 cout<<"Candidate number : "<<cno<<endl;
 cout<<"Candidate name : ";puts(cname);
 cout<<"Candidate score : "<<score<<endl;
}
int candidate::rscore()
{
 return score;
}

void enrol()
{
 fstream fil;
 fil.open("candidate.dat",ios::binary|ios::out);
 candidate c;
 char ch;
 do
 {
  c.enter();
  fil.write((char*)&c,sizeof(c));
  cout<<"Continue(y/n)"<<endl;
  cin>>ch;
 }
  while(ch!='n');
  fil.close();
}
void getpass()
{
 fstream fil;
 fil.open("candidate.dat",ios::binary|ios::in);
 candidate c;
 cout<<"The details of candidates who have passed :"<<endl;
 while(fil.read((char*)&c,sizeof(c)))
 {
   if(c.rscore()>=33)
      c.display();
 }
 fil.close();
}
void main()
{
 clrscr();
 enrol();
 getpass();
 getch();
}