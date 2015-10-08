#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<iomanip.h>

class USER
{
 char Username[9], Password[9];
 public:
  char* R_Username(){return Username;}
  char* R_Password(){return Password;}
  void Change_Username(char Name[]){strcpy(Username,Name);}
  void Change_Password(char Pass[]){strcpy(Password,Pass);}
};

class ENTRY
{
 char Name[33], PhoneNo[9];
 public:
  char* R_Name(){return Name;}
  char* R_PhoneNo(){return PhoneNo;}
  void Change_Name(char New_Name[]){strcpy(Name,New_Name);}
  //void Change_Password(char Pass[]){strcpy(Password,Pass);}
};

class LOG
{
 char PhoneNo[9];
 time dur,cur;
 date dat;
 public:
  LOG(char A[],time a,time b,date d)
  {
   strcpy(PhoneNo,A);
   dur=a;
   cur=b;
   dat=d;
  }
  LOG(){}
  void output(int i)
  {
   int r=i+5;
   gotoxy(1,r);setw(5);cout<<i;
   gotoxy(18,r);cout<<PhoneNo;
   gotoxy(36,r);cprintf("%2d:%02d:%02d",dur.ti_hour,dur.ti_min,dur.ti_sec);
   gotoxy(52,r);cprintf("%2d:%02d:%02d",cur.ti_hour,cur.ti_min,cur.ti_sec);
   gotoxy(66,r);cprintf("%02d-%02d-%2d",dat.da_day,dat.da_mon,dat.da_year);
  }
};

/////////////////////////////////////////////////////////////////////////////


void Screen1();
int LogIn(char[],char[]);
void Layout_LogIn(int,char[],char[]);
int Validity(char[],char[]);
int Search_LogIn(char[],char[]);
int Condition();
int Search_Online2(char[]);
int SignUp(char[],char[]);
void Layout_SignUp(int,char[],char[],char[]);
void File_SignUp(char[],char[]);

void username(int,char[]);
void password(int,char[]);
void log_in(int);
void sign_up(int);

void IN(int,char[],char[],char);

void reenter(int,char[]);
void sign_up2(int);

void option(char,int,int,int);

void Account(char[],char[]);
void Screen2();
void Desktop();
void Theme();
void Wallpaper();
void Header();
void Time();
void Menu(char[]);

void Online(char[],char[]);
void Offline(char[]);
void CopyFile(char [], char []);

void Dial(char,char[]);
void Number(char, int);
int Caller(char[]);

void Call(char [],char[]);
int Search_Online(char [],char[]);
int Pulse(char [],char[]);
void DePulse(char[],char[]);
time Chat(char [],char[]);
void HeadFoot(char [],char[]);
long TimeCall();
void ShowTime(long);

void Messages();
 void CreateMessage();
 void Inbox();
 void Sentbox();
 void Outbox();
 void Drafts();
 void MessageSettings();

void Phonebook();

void CallLog(char[]);
 void Received(char[]);
 void Dialled(char[]);
 void Missed(char[]);
 void CallDuration(char[]);
 void CallCosts();
void FileLog(char[],char[],char[],time);

void Organiser();
 void Calendar();
 void Alarm();
 void Calculator();
 void Convertor();
 void StopWatch();
 void Timer();

void Settings();
void Media();

/////////////////////////////////////////////////////////////////////////////

void A()
{
 clrscr();
 USER U;
 fstream fil;
 fil.open("DAT\\ONLINE.dat",ios::in|ios::binary);
 while(fil.read((char*)&U,sizeof(U)))
  cout<<U.R_Username()<<" "<<U.R_Password()<<endl;
 fil.close();
 delay(1000);
}

/////////////////////////////////////////////////////////////////////////////

void main()
{
 char Username[9]="", Password[9]="";
 Screen1();
 while(LogIn(Username,Password))
 {
  Account(Username,Password);
 }
}

/////////////////////////////////////////////////////////////////////////////

void Screen1()
{
 _setcursortype(_NOCURSOR);
 textbackground(BLACK);
 clrscr();
 fstream fil;
 char Lin[80];
 int flag=1,l=1;
 fil.open("TEXT\\animate.txt",ios::in);
 while(fil.getline(Lin,80))
 {
  if(strcmp(Lin,"X")==0)
  {
   if(flag)
   {
    flag=0;
    delay(500);
   }
   else
    delay(200);
   clrscr();
  }
  else
  {
   cout<<Lin;
   if(l!=25)
    cout<<endl;
   else
    l=0;
   l++;
  }
 }
 fil.close();
 getch();
}

void username(int Q,char Username[])
{
 gotoxy(30,12);
 textcolor(Q);
 cprintf("Phone No: ");
 cprintf(Username);
}

void password(int Q,char Password[])
{
 gotoxy(30,13);
 textcolor(Q);
 cprintf("Password: ");
 for(int j=0;Password[j]!='\0';j++)
  cprintf("*");
}

void log_in(int Q)
{
 gotoxy(36,15);
 textcolor(Q);
 cprintf("Log In");
}

void sign_up(int Q)
{
 gotoxy(1,25);
 textcolor(Q);
 cprintf("Sign Up");
}

void Layout_LogIn(int p,char Username[], char Password[])
{
 int j;
 switch(p)
  {
   case 0:
    username(CYAN,Username);
    password(WHITE,Password);
    log_in(WHITE);
    sign_up(WHITE);
    break;

   case 1:
    username(WHITE,Username);
    password(CYAN,Password);
    log_in(WHITE);
    sign_up(WHITE);
    break;

   case 2:
    username(WHITE,Username);
    password(WHITE,Password);
    log_in(CYAN);
    sign_up(WHITE);
    break;

   case 3:
    username(WHITE,Username);
    password(WHITE,Password);
    log_in(WHITE);
    sign_up(CYAN);
    break;
 }
}

void IN(int ROW,char WORD[],char Q[],char CH)
{
 gotoxy(30,ROW);
 clreol();
 textcolor(LIGHTGREEN);
 cprintf(WORD);
 _setcursortype(_NORMALCURSOR);
 int i=0;
 char ch=getch();
 while(ch!=13)
 {
  textcolor(LIGHTGREEN);
  if(ch==8)
  {
   if(i>0)
   {
    cprintf("\b \b");
    i--;
   }
  }
  else
  {
   if(i<8)
   {
    char c[2];
    c[1]='\0';
    if(CH=='*')
     c[0]='*';
    else
     c[0]=ch;
    cprintf(c);
    Q[i++]=ch;
   }
  }
  ch=getch();
 }
 Q[i]='\0';
}

int LogIn(char Username[], char Password[])
{
 int pos=0,exit=0,log=0,i;
 char ch;
 Username[0]='\0';
 Password[0]='\0';
 _setcursortype(_NOCURSOR);
 while(!exit)
 {
  textbackground(BLACK);
  textcolor(WHITE);
  clrscr();
  Layout_LogIn(pos,Username,Password);
  char key=getch();
  if(key==50||key==54||key==80||key==77)
   pos=pos==3?0:pos+1;
  else if(key==72||key==75||key==52||key==56)
   pos=pos==0?3:pos-1;
  if(key==13)
  {
   switch(pos)
   {
    case 0:
     IN(12,"Phone No: ",Username,ch);
     break;

    case 1:
     IN(13,"Password: ",Password,'*');
     break;

    case 2:
     gotoxy(36,15);
     textcolor(LIGHTGREEN);
     cprintf("Log In");
     delay(100);
     if(!Search_LogIn(Username,Password))
     {
      gotoxy(30,15);
      textcolor(LIGHTGREEN);
      cprintf("Incorrect Phone No/Password");
      delay(1000);
     }
     else if(Search_Online2(Username))
     {
      gotoxy(30,15);
      textcolor(LIGHTGREEN);
      cprintf("You're already logged in");
      delay(1000);
     }
     else
     {
      log=1;
      exit=1;
     }
     break;

    case 3:
     gotoxy(1,25);
     textcolor(LIGHTGREEN);
     cprintf("Sign Up");
     delay(100);
     log=SignUp(Username,Password);
     if(log)exit=1;
     break;
   }
   _setcursortype(_NOCURSOR);
  }
  if(key==27)
   exit=1;
 }
 return log;
}

int Condition(char ch)
{
 return !((ch>=65 && ch<=90)||(ch==95)||(ch>=97 && ch<=122)||(ch>=48&&ch<=57));
}

int Validity(char Username[],char Password[])
{
 int i=0,valid=1;
 while(Username[i]!='\0' && valid)
 {
  char ch=Username[i++];
  if(!(ch>=48 && ch<=57))
   valid=0;
 }
 if(i<3) valid=0;

 i=0;
 while(Password[i]!='\0' && valid)
 {
  char ch=Password[i++];
  if(Condition(ch))
   valid=0;
 }
 if(i<3) valid=0;

 return valid;
}

int Search_LogIn(char Username[],char Password[])
{
 int found=0;
 USER U;
 fstream file;
 file.open("DAT\\USER.dat",ios::binary|ios::in);
 while(!found && file.read((char*)&U,sizeof(U)))
 {
  if(strcmp(U.R_Username(),Username)==0 && strcmp(U.R_Password(),Password)==0)
   found++;
 }
 file.close();
 return found;
}

int Search_Online2(char Username[])
{
 int found=0;
 USER U;
 fstream file;
 file.open("DAT\\ONLINE.dat",ios::binary|ios::in);
 while(!found && file.read((char*)&U,sizeof(U)))
 {
  if(strcmp(U.R_Username(),Username)==0)
   found++;
 }
 file.close();
 return found;
}

/////////////////////////////////////////////////////////////////////////////

void reenter(int Q, char Password2[])
{
 gotoxy(30,14);
 textcolor(Q);
 cprintf("Re-Enter: ");
 for(int j=0;Password2[j]!='\0';j++)
  cprintf("*");
}

void sign_up2(int Q)
{
 gotoxy(36,16);
 textcolor(Q);
 cprintf("Sign Up");
}

void Layout_SignUp(int p,char Username[],char Password[],char Password2[])
{
 int j;
 switch(p)
  {
   case 0:
    username(CYAN,Username);
    password(WHITE,Password);
    reenter(WHITE,Password2);
    sign_up2(WHITE);
    break;

   case 1:
    username(WHITE,Username);
    password(CYAN,Password);
    reenter(WHITE,Password2);
    sign_up2(WHITE);
    break;

   case 2:
    username(WHITE,Username);
    password(WHITE,Password);
    reenter(CYAN,Password2);
    sign_up2(WHITE);
    break;

   case 3:
    username(WHITE,Username);
    password(WHITE,Password);
    reenter(WHITE,Password2);
    sign_up2(CYAN);
    break;
 }
}

int SignUp(char Username[],char Password[])
{
 int pos=0,exit=0,i,log=0;
 char ch,Password2[9]="";
 Username[0]='\0';
 Password[0]='\0';
 _setcursortype(_NOCURSOR);
 while(!exit)
 {
  clrscr();
  gotoxy(34,10);
  textcolor(WHITE);
  cprintf("Signing Up");
  Layout_SignUp(pos,Username,Password,Password2);
  char key=getch();
  if(key==50||key==54||key==80||key==77)
   pos=pos==3?0:pos+1;
  else if(key==72||key==75||key==52||key==56)
   pos=pos==0?3:pos-1;
  if(i==0||i==1)
   key=13;
  if(key==13)
  {
   switch(pos)
   {
    case 0:
     IN(12,"Phone No: ",Username,ch);
     break;

    case 1:
     IN(13,"Password: ",Password,'*');
     break;

    case 2:
     IN(14,"Re-Enter: ",Password2,'*');
     break;

    case 3:
     gotoxy(36,16);
     textcolor(LIGHTGREEN);
     cprintf("Sign Up");
     delay(100);
     if(!Validity(Username,Password) || strcmp(Password,Password2)!=0)
     {
      gotoxy(30,15);
      textcolor(LIGHTGREEN);
      cprintf("Invalid Username/Password");
      delay(1000);
     }
     else
     {
      File_SignUp(Username,Password);
      log=1;
      exit=1;
     }
     break;
    }
   _setcursortype(_NOCURSOR);
  }
  else if(key==27)
   exit=1;
 }
 return log;
}

void File_SignUp(char Username[],char Password[])
{
 fstream file;
 file.open("DAT\\USER.dat",ios::binary|ios::app);
 USER U;
 U.Change_Username(Username);
 U.Change_Password(Password);
 clrscr();
 file.write((char*)&U,sizeof(U));
 file.close();
}

/////////////////////////////////////////////////////////////////////////////

void Online(char Username[],char Password[])
{
 USER U;
 U.Change_Username(Username);
 U.Change_Password(Password);
 fstream fil;
 fil.open("DAT\\ONLINE.dat",ios::binary|ios::app);
 fil.write((char*)&U,sizeof(U));
 fil.close();
}

void Offline(char Username[])
{
 USER U;
 fstream fil,temp;
 fil.open("DAT\\ONLINE.dat",ios::binary|ios::in);
 temp.open("DAT\\TEMP.dat",ios::binary|ios::out);
 while(fil.read((char*)&U,sizeof(U)))
  if(strcmp(U.R_Username(),Username)!=0)
   temp.write((char*)&U,sizeof(U));
 fil.close();
 temp.close();
 CopyFile("DAT\\ONLINE.dat","DAT\\TEMP.dat");
}

void CopyFile(char Dest[20], char Source[20])
{
 fstream dest, source;
 dest.open(Dest,ios::out|ios::binary);
 source.open(Source,ios::in|ios::binary);
 USER U;
 while(source.read((char*)&U,sizeof(U)))
  dest.write((char*)&U,sizeof(U));
 dest.close();
 source.close();
}

void Screen2()
{
 _setcursortype(_NOCURSOR);
 clrscr();
 char ch[33]="WELCOME";
 double gr=13, h, e=0.9, a=1000, u, v, S=1, t;
 if(gr<25 && e<1){
 int i;
 gotoxy(1,gr+1);
 //for(i=1;i<=79;i++)
 // cout<<"-";
 h=gr;
 while(h>0.5)
 {
  u=0;
  for(i=1;i<=h;i++)
  {
   v=sqrt(u*u+2*a*S);
   t=(v-u)/a;
   u=v;
   gotoxy(40-strlen(ch)/2,gr-h+i);
   cout<<ch;
   delay(t*1000);
   gotoxy(1,gr-h+i);
   clreol();
  }
  h=e*e*h;
  u=sqrt(2*a*h);
  for(i=1;i<=h;i++)
  {
   v=sqrt(u*u-2*a*S);
   t=(u-v)/a;
   u=v;
   gotoxy(40-strlen(ch)/2,gr-(i-1));
   cout<<ch;
   delay(t*1000);
   gotoxy(1,gr-(i-1));
   clreol();
  }
 }
 gotoxy(40-strlen(ch)/2,gr);
 cout<<ch;
 getch();}
}

void Account(char Username[], char Password[])
{
 Screen2();
 Online(Username,Password);
 //A();
 char ch1;
 do
 {
  Desktop();
  while(!kbhit())
  {
   if(Caller(Username))
    Desktop();
   Time();
   delay(100);
  }
  ch1=getch();
  if(ch1==13)
  {
   Menu(Username);
  }
  if(ch1>=48&&ch1<=57 || ch1=='+' || ch1=='*')
  {
   Dial(ch1,Username);
  }
  if(ch1==27)
  {
   textcolor(LIGHTGREEN);
   gotoxy(20,11);cprintf("ษออออออออออออออออออออออออออออออออออออออป");
   gotoxy(20,12);cprintf("บ                                      บ");
   gotoxy(20,13);cprintf("บ ARE YOU SURE YOU WANT TO EXIT? (Y/N) บ");
   gotoxy(20,14);cprintf("บ                                      บ");
   gotoxy(20,15);cprintf("ศออออออออออออออออออออออออออออออออออออออผ");
   char ch2;
   do
   {
    ch2=getch();
    if(ch2=='n')
     ch1=1;
   }while(!(ch2=='y' || ch2=='n'));
  }
 }while(ch1!=27);
 Offline(Username);
 //A();
}

void Desktop()
{
 Wallpaper();
 Theme();
 Header();
 gotoxy(39,25);
 textcolor(LIGHTGREEN);
 cprintf("Menu");
}

void Theme()
{
 textbackground(BLACK);
 textcolor(WHITE);
 _setcursortype(_NOCURSOR);
}

void Wallpaper()
{
 char FileName[20],Lin[80];
 strcpy(FileName,"TEXT\\ferrari.txt");
 textcolor(CYAN);
 clrscr();
 fstream fil;
 fil.open(FileName,ios::in);
 while(fil.getline(Lin,80))
  cout<<Lin<<endl;
 fil.close();
}

void Header()
{
 gotoxy(1,1);
 cprintf("ั     Ü Û");gotoxy(1,2);
 cprintf("ณ Ü Û Û Û");
 gotoxy(75,1);
 cprintf("þÝฐฑฒÞ");
}

void Time()
{
 time T;
 gettime(&T);
 gotoxy(37,15);
 textcolor(WHITE);
 cprintf("%2d:%02d:%02d\n",T.ti_hour, T.ti_min, T.ti_sec);
 date D;
 getdate(&D);
 gotoxy(36,17);
 cprintf("%02d-%02d-%2d",D.da_day,D.da_mon,D.da_year);
}

/////////////////////////////////////////////////////////////////////////////

void option(char WORD[],int Q,int COLUMN,int ROW)
{
 gotoxy(COLUMN-strlen(WORD)/2,ROW);
 textcolor(Q);
 cprintf(WORD);
}

void Layout_Menu(int p)
{
 int j;
 option("Messages",WHITE,20,8);
 option("Phonebook",WHITE,40,8);
 option("Call Log",WHITE,60,8);
 option("Organiser",WHITE,20,16);
 option("Settings",WHITE,40,16);
 option("Media",WHITE,60,16);
 switch(p)
 {
  case 0:
   option("Messages",CYAN,20,8);
   break;

  case 1:
   option("Phonebook",CYAN,40,8);
   break;

  case 2:
   option("Call Log",CYAN,60,8);
   break;

  case 3:
   option("Organiser",CYAN,20,16);
   break;

  case 4:
   option("Settings",CYAN,40,16);
   break;

  case 5:
   option("Media",CYAN,60,16);
   break;
 }
}

void Menu(char Username[])
{
 int pos=0,exit=0;
 char ch;
 _setcursortype(_NOCURSOR);
 while(!exit)
 {
  clrscr();
  Layout_Menu(pos);
  char key=getch();
  if(key==77)
   pos=pos==5?0:pos+1;
  else if(key==80)
   pos=pos<3?pos+3:pos==5?0:pos-2;
  else if(key==75)
   pos=pos==0?5:pos-1;
  else if(key==72)
   pos=pos>=3?pos-3:pos==0?5:pos+2;
  else if(key==13)
  {
   switch(pos)
   {
    case 0:
     option("Messages",LIGHTGREEN,20,8);
     delay(100);
     Messages();
     break;

    case 1:
     option("Phonebook",LIGHTGREEN,40,8);
     delay(100);
     Phonebook();
     break;

    case 2:
     option("Call Log",LIGHTGREEN,60,8);
     delay(100);
     CallLog(Username);
     break;

    case 3:
     option("Organiser",LIGHTGREEN,20,16);
     delay(100);
     Organiser();
     break;

    case 4:
     option("Settings",LIGHTGREEN,40,16);
     delay(100);
     Settings();
     break;

    case 5:
     option("Media",LIGHTGREEN,60,16);
     delay(100);
     Media();
     break;
   }
  }
  else if(key==27)
   exit=1;
 }
}

/////////////////////////////////////////////////////////////////////////////

void Layout_General(int pos,char OPTIONS[][32],int n)
{
 int i=0;
 while(i<n)
 {
  gotoxy(2,2+2*i);
  if(i==pos)
   textcolor(CYAN);
  else
   textcolor(WHITE);
  cprintf(OPTIONS[i++]);
 }
}

/////////////////////////////////////////////////////////////////////////////

void Messages()
{
 int pos=0,exit=0;
 char ch;
 char options[6][32]=
 {
  "1. Create Message",
  "2. Inbox",
  "3. Sentbox",
  "4. Outbox",
  "5. Drafts",
  "6. Settings"
 };
 _setcursortype(_NOCURSOR);
 while(!exit)
 {
  clrscr();
  Layout_General(pos,options,6);
  char key=getch();
  if(key>=48+1 && key<=48+6)
  {
   gotoxy(2,2+2*pos);
   textcolor(WHITE);
   cprintf(options[pos]);
   pos=key-48-1;
   key=13;
  }
  if(key==77||key==80)
   pos=pos==5?0:pos+1;
  else if(key==75||key==72)
   pos=pos==0?5:pos-1;
  else if(key==13)
  {
   gotoxy(2,2+2*pos);
   textcolor(LIGHTGREEN);
   cprintf(options[pos]);
   delay(100);
   switch(pos)
   {
    case 0:
     CreateMessage();
     break;

    case 1:
     Inbox();
     break;

    case 2:
     Sentbox();
     break;

    case 3:
     Outbox();
     break;

    case 4:
     Drafts();
     break;

    case 5:
     MessageSettings();
     break;
   }
  }
  else if(key==27)
   exit=1;
 }
}

void CreateMessage(){}
void Inbox(){}
void Sentbox(){}
void Outbox(){}
void Drafts(){}
void MessageSettings(){}

/////////////////////////////////////////////////////////////////////////////

void Phonebook()
{

}

/////////////////////////////////////////////////////////////////////////////

void CallLog(char Username[])
{
 int pos=0,exit=0;
 char ch;
 char options[6][32]=
 {
  "1. Received Calls",
  "2. Dialled Calls",
  "3. Missed Calls",
  "4. Call duration",
  "5. Call costs",
  "6. <option 6>"
 };
 _setcursortype(_NOCURSOR);
 while(!exit)
 {
  clrscr();
  Layout_General(pos,options,6);
  char key=getch();
  if(key>=48+1 && key<=48+6)
  {
   gotoxy(2,2+2*pos);
   textcolor(WHITE);
   cprintf(options[pos]);
   pos=key-48-1;
   key=13;
  }
  if(key==77||key==80)
   pos=pos==5?0:pos+1;
  else if(key==75||key==72)
   pos=pos==0?5:pos-1;
  else if(key==13)
  {
   gotoxy(2,2+2*pos);
   textcolor(LIGHTGREEN);
   cprintf(options[pos]);
   delay(100);
   switch(pos)
   {
    case 0:
     Received(Username);
     break;

    case 1:
     Dialled(Username);
     break;

    case 2:
     Missed(Username);
     break;

    case 3:
     CallDuration(Username);
     break;

    case 4:
     CallCosts();
     break;

    case 5:
     //();
     break;
   }
  }
  else if(key==27)
   exit=1;
 }
}

void Received(char Username[])
{
 clrscr();
 option("RECEIVED CALLS",LIGHTGREEN,40,2);
 option("S.No.",CYAN,8,4);
 option("Caller",CYAN,24,4);
 option("Duration",CYAN,40,4);
 option("Time",CYAN,56,4);
 option("Date",CYAN,72,4);
 fstream fil;
 char FileName[20]="";
 strcat(FileName,"LOG\\R\\");
 strcat(FileName,Username);
 strcat(FileName,".dat");
 fil.open(FileName,ios::binary|ios::in);
 fil.seekg(0,ios::end);
 int N=fil.tellg()/sizeof(LOG);
 for(int i=1;i<=20&&i<=N;i++)
 {
  fil.seekg((N-i)*sizeof(LOG));
  LOG L;
  fil.read((char*)&L,sizeof(LOG));
  L.output(i);
 }
 fil.close();
 getch();
}

void Dialled(char Username[])
{
 clrscr();
 option("DIALLED CALLS",LIGHTGREEN,40,2);
 option("S.No.",CYAN,8,4);
 option("Callee",CYAN,24,4);
 option("Duration",CYAN,40,4);
 option("Time",CYAN,56,4);
 option("Date",CYAN,72,4);
 fstream fil;
 char FileName[20]="";
 strcat(FileName,"LOG\\D\\");
 strcat(FileName,Username);
 strcat(FileName,".dat");
 fil.open(FileName,ios::binary|ios::in);
 fil.seekg(0,ios::end);
 int N=fil.tellg()/sizeof(LOG);
 for(int i=1;i<=20&&i<=N;i++)
 {
  fil.seekg((N-i)*sizeof(LOG));
  LOG L;
  fil.read((char*)&L,sizeof(LOG));
  L.output(i);
 }
 fil.close();
 getch();
}

void Missed(char Username[])
{
 clrscr();
 option("MISSED CALLS",LIGHTGREEN,40,2);
 option("S.No.",CYAN,8,4);
 option("Caller",CYAN,24,4);
 option("Duration",CYAN,40,4);
 option("Time",CYAN,56,4);
 option("Date",CYAN,72,4);
 fstream fil;
 char FileName[20]="";
 strcat(FileName,"LOG\\M\\");
 strcat(FileName,Username);
 strcat(FileName,".dat");
 fil.open(FileName,ios::binary|ios::in);
 fil.seekg(0,ios::end);
 int N=fil.tellg()/sizeof(LOG);
 for(int i=1;i<=20&&i<=N;i++)
 {
  fil.seekg((N-i)*sizeof(LOG));
  LOG L;
  fil.read((char*)&L,sizeof(LOG));
  L.output(i);
 }
 fil.close();
 getch();
}

void CallDuration(char Username[])
{
}

void CallCosts()
{
 clrscr();
 gotoxy(30,13);
 cout<<"THIS SECTION IS UNAVAILABLE";
 getch();
}

void FileLog(char type[],char Phone[],char Username[],time dur)
{
 fstream fil;
 time cur;
 date dat;
 gettime(&cur);
 getdate(&dat);
 char FileName[20]="";
 strcat(FileName,"LOG\\");
 strcat(FileName,type);
 strcat(FileName,"\\");
 strcat(FileName,Username);
 strcat(FileName,".dat");
 fil.open(FileName,ios::binary|ios::app);
 LOG L(Phone,dur,cur,dat);
 fil.write((char*)&L,sizeof(LOG));
 fil.close();
}

/////////////////////////////////////////////////////////////////////////////

void Organiser()
{
 int pos=0,exit=0;
 char ch;
 char options[6][32]=
 {
  "1. Calendar",
  "2. Alarm Clock",
  "3. Calculator",
  "4. Convertor",
  "5. Stop Watch",
  "6. Timer"
 };
 _setcursortype(_NOCURSOR);
 while(!exit)
 {
  clrscr();
  Layout_General(pos,options,6);
  char key=getch();
  if(key>=48+1 && key<=48+6)
  {
   gotoxy(2,2+2*pos);
   textcolor(WHITE);
   cprintf(options[pos]);
   pos=key-48-1;
   key=13;
  }
  if(key==77||key==80)
   pos=pos==5?0:pos+1;
  else if(key==75||key==72)
   pos=pos==0?5:pos-1;
  else if(key==13)
  {
   gotoxy(2,2+2*pos);
   textcolor(LIGHTGREEN);
   cprintf(options[pos]);
   delay(100);
   switch(pos)
   {
    case 0:
     Calendar();
     break;

    case 1:
     Alarm();
     break;

    case 2:
     Calculator();
     break;

    case 3:
     Convertor();
     break;

    case 4:
     StopWatch();
     break;

    case 5:
     Timer();
     break;
   }
  }
  else if(key==27)
   exit=1;
 }
}

void Calendar(){}
 void Alarm(){}
 void Calculator(){}
 void Convertor(){}
 void StopWatch(){}
 void Timer(){}

/////////////////////////////////////////////////////////////////////////////

void Settings()
{
 int pos=0,exit=0;
 char ch;
 char options[6][32]=
 {
  "1. ",
  "2. ",
  "3. ",
  "4. ",
  "5. ",
  "6. "
 };
 _setcursortype(_NOCURSOR);
 while(!exit)
 {
  clrscr();
  Layout_General(pos,options,6);
  char key=getch();
  if(key>=48+1 && key<=48+6)
  {
   gotoxy(2,2+2*pos);
   textcolor(WHITE);
   cprintf(options[pos]);
   pos=key-48-1;
   key=13;
  }
  if(key==77||key==80)
   pos=pos==5?0:pos+1;
  else if(key==75||key==72)
   pos=pos==0?5:pos-1;
  else if(key==13)
  {
   gotoxy(2,2+2*pos);
   textcolor(LIGHTGREEN);
   cprintf(options[pos]);
   delay(100);
   switch(pos)
   {
    case 0:
     //();
     break;

    case 1:
     //();
     break;

    case 2:
     //();
     break;

    case 3:
     //();
     break;

    case 4:
     //();
     break;

    case 5:
     //();
     break;
   }
  }
  else if(key==27)
   exit=1;
 }
}

/////////////////////////////////////////////////////////////////////////////

void Media()
{
 int pos=0,exit=0;
 char ch;
 char options[6][32]=
 {
  "1. ",
  "2. ",
  "3. ",
  "4. ",
  "5. ",
  "6. "
 };
 _setcursortype(_NOCURSOR);
 while(!exit)
 {
  clrscr();
  Layout_General(pos,options,6);
  char key=getch();
  if(key>=48+1 && key<=48+6)
  {
   gotoxy(2,2+2*pos);
   textcolor(WHITE);
   cprintf(options[pos]);
   pos=key-48-1;
   key=13;
  }
  if(key==77||key==80)
   pos=pos==5?0:pos+1;
  else if(key==75||key==72)
   pos=pos==0?5:pos-1;
  else if(key==13)
  {
   gotoxy(2,2+2*pos);
   textcolor(LIGHTGREEN);
   cprintf(options[pos]);
   delay(100);
   switch(pos)
   {
    case 0:
     //();
     break;

    case 1:
     //();
     break;

    case 2:
     //();
     break;

    case 3:
     //();
     break;

    case 4:
     //();
     break;

    case 5:
     //();
     break;
   }
  }
  else if(key==27)
   exit=1;
 }
}

/////////////////////////////////////////////////////////////////////////////

void Dial(char ch,char Username[])
{
 clrscr();
 gotoxy(38,25);
 cout<<"Call";
 gotoxy(32,13);
 char PhoneNo[9];
 PhoneNo[0]=ch;
 Number(ch,0);
 int i=1;
 //do
 //{
  do
  {
   ch=getch();
   if(ch>=48&&ch<=57 && i<8)
   {
    Number(ch,i);
    PhoneNo[i++]=ch;
   }
   else if(ch==8)
   {
    if(i>0)
    {
     Number(ch,--i);
    }
   }
  }while(ch!=13&&ch!=27);
  PhoneNo[i]='\0';
  if(ch==13)
   Call(PhoneNo,Username);
 //}while(ch!=27);
}

int Search_Online(char PhoneNo[],char Username[])
{
 int found=0;
 if(strcmp(PhoneNo,Username)!=0)
 {
  USER U;
  fstream file;
  file.open("DAT\\ONLINE.dat",ios::binary|ios::in);
  while(!found && file.read((char*)&U,sizeof(U)))
  {
   if(strcmp(U.R_Username(),PhoneNo)==0)
    found++;
  }
  file.close();
 }
 return found;
}

int Pulse(char PhoneNo[],char Username[])
{
 fstream fil;
 char FileName[20]="";
 strcat(FileName,"CALL\\");
 strcat(FileName,PhoneNo);
 strcat(FileName,".dat");
 fil.open(FileName,ios::out);
  fil<<Username;
 fil.close();

 char data[9];
 int accept=0,exit=0;
 FileName[0]='\0';
 strcat(FileName,"CALL\\");
 strcat(FileName,Username);
 strcat(FileName,".dat");
 do
 {
  fstream fil2;
  fil2.open(FileName,ios::in);
   fil2>>data;
  if(strcmp(data,PhoneNo)==0)
  {
   accept=1;
   exit=1;
  }
  else if(strcmp(data,Username)==0)
  {
   accept=0;
   exit=1;
  }
  fil2.close();
 }while(!exit);
 return accept;
}

void DePulse(char PhoneNo[],char Username[])
{
 fstream fil,fil2;
 char FileName[20]="";
 strcat(FileName,"CALL\\");
 strcat(FileName,PhoneNo);
 strcat(FileName,".dat");
 fil.open(FileName,ios::out);
 fil.close();

 FileName[0]='\0';
 strcat(FileName,"CALL\\");
 strcat(FileName,Username);
 strcat(FileName,".dat");
 fil2.open(FileName,ios::out);
 fil2.close();
}

time Chat(char PhoneNo[],char Username[])
{
 long sec=TimeCall();
 time tim;
 _setcursortype(_NORMALCURSOR);
 char User[9],ch,Lin2[80]="";
 int l=3,i=0,read=0;
 strcpy(User,Username);
 fstream fil3;
 char FileName[20]="";
 strcat(FileName,"CHAT\\");
 strcat(FileName,User);
 strcat(FileName,".dat");
 fil3.open(FileName,ios::out);
 fil3.close();
 textcolor(WHITE);
 clrscr();
 HeadFoot(PhoneNo,Username);
 gotoxy(76,1);
 ShowTime(sec);
 do
 {
  while(!kbhit())
  {
   char Lin[80]="";
   fstream fil;
   char FileName[20]="";
   strcat(FileName,"CHAT\\");
   strcat(FileName,User);
   strcat(FileName,".dat");
   fil.open(FileName,ios::in);
   gotoxy(76,1);
   ShowTime(sec);
   gotoxy(i+strlen(User)+2,24);
   if(fil.getline(Lin,80))
   {
    read=1;
    if(l<22)
    {
     gotoxy(1,l++);
     cout<<PhoneNo<<":"<<Lin<<endl;
    }
    else
    {
     gotoxy(1,l);
     clreol();
     textcolor(WHITE);
     cprintf(PhoneNo);
     cprintf(":");
     cprintf(Lin);
     cprintf("\n\n\n\n");
     HeadFoot(PhoneNo,Username);
     gotoxy(76,1);
     ShowTime(sec);
    }
    gotoxy(i+strlen(User)+2,24);
   }
   fil.close();
   if(read)
   {
    fil.open(FileName,ios::out);
    fil.close();
    read=0;
   }
  }
  ch=getch();

  if(ch>=32 && ch<=126 && i<80-strlen(User)-2)
  {
   Lin2[i]=ch;
   gotoxy(i++ +strlen(User)+2,24);
   textcolor(LIGHTGREEN);
   char c[2]={ch,'\0'};
   cprintf(c);
  }
  else if(ch==8 && i>0)
  {
   gotoxy(--i +strlen(User)+2,24);
   cout<<" \b";
  }
  else if(ch==13)
  {
   Lin2[i]='\0';
   textcolor(CYAN);
   if(l<22)
   {
    gotoxy(1,l++);
    cprintf("Me:");
    cprintf(Lin2);
    cout<<endl;
   }
   else
   {
    gotoxy(1,l);
    clreol();
    cprintf("Me:");
    cprintf(Lin2);
    cout<<"\n\n\n\n";
    HeadFoot(PhoneNo,Username);
    gotoxy(76,1);
    ShowTime(sec);
   }
   fstream fil2;
   FileName[0]='\0';
   strcat(FileName,"CHAT\\");
   strcat(FileName,PhoneNo);
   strcat(FileName,".dat");
   fil2.open(FileName,ios::out);
   fil2<<Lin2;
   fil2.close();
   Lin2[0]='\0';
   i=0;
   gotoxy(strlen(User)+2,24);
   clreol();
   gotoxy(i+strlen(User)+2,24);
  }
  else if(ch==27)
  {
   textcolor(LIGHTGREEN);
   _setcursortype(_NOCURSOR);
   gotoxy(20,11);cprintf("ษออออออออออออออออออออออออออออออออออออออป");
   gotoxy(20,12);cprintf("บ                                      บ");
   gotoxy(20,13);cprintf("บ             CALL ENDED               บ");
   gotoxy(20,14);cprintf("บ                                      บ");
   gotoxy(20,15);cprintf("ศออออออออออออออออออออออออออออออออออออออผ");
   gotoxy(38,14);ShowTime(sec);

   gettime(&tim);
   long now=(long)tim.ti_hour*3600+(long)tim.ti_min*60+(long)tim.ti_sec;
   long dur=now-sec;
   tim.ti_sec=dur%60;
   dur=dur/60;
   tim.ti_min=dur%60;
   tim.ti_hour=dur/60;

   gotoxy(i+strlen(User)+2,24);
   getch();
  }
 }while(ch!=27);
 return tim;
}

void HeadFoot(char PhoneNo[],char Username[])
{
 textcolor(LIGHTGREEN);
 gotoxy(1,1);
 clreol();
 cprintf(PhoneNo);

 gotoxy(1,2);
 for(int j=1;j<=80;j++)
  cprintf("ฤ");

 gotoxy(1,22);
 clreol();
 gotoxy(1,23);
 for(j=1;j<=80;j++)
  cprintf("ฤ");
 gotoxy(1,24);
 cprintf(Username);
 cprintf(":");
}

void ShowTime(long start)
{
 time U;
 gettime(&U);
 long now=(long)U.ti_hour*3600+(long)U.ti_min*60+(long)U.ti_sec;
 long sec=now-start;
 U.ti_sec=sec%60;
 U.ti_min=sec/60;
 textcolor(LIGHTGREEN);
 cprintf("%02d:%02d\n",U.ti_min, U.ti_sec);
}

long TimeCall()
{
 time T;
 gettime(&T);
 long sec=(long)T.ti_hour*3600+(long)T.ti_min*60+(long)T.ti_sec;
 return sec;
}

void Call(char PhoneNo[],char Username[])
{
 clrscr();
 gotoxy(32,13);
 int on=Search_Online(PhoneNo,Username);
 if(on)
 {
  textcolor(WHITE+BLINK);
  cprintf("Calling ");
  cprintf(PhoneNo);
  int accept=Pulse(PhoneNo,Username);
  if(accept)
  {
   time dur=Chat(PhoneNo,Username);
   FileLog("D",PhoneNo,Username,dur);
  }
  else
  {
   textcolor(LIGHTGREEN);
   gotoxy(1,13);
   clreol();
   gotoxy(36,13);
   cprintf("User Busy");
   time dur={0,0,0};
   FileLog("D",PhoneNo,Username,dur);
   getch();
  }
  DePulse(PhoneNo,Username);
 }
 else
 {
  textcolor(LIGHTGREEN);
  gotoxy(1,13);
  clreol();
  gotoxy(36,13);
  cprintf("Unavailable");
  time dur={0,0,0};
  FileLog("D",PhoneNo,Username,dur);
  getch();
 }
}

int Caller(char Username[])
{
 int call=0;
 fstream fil,fil2,fil3;
 char Caller[9],FileName[20]="",ch;
 strcat(FileName,"CALL\\");
 strcat(FileName,Username);
 strcat(FileName,".dat");
 fil.open(FileName,ios::in);
 fil.getline(Caller,9);
 if(Search_Online(Caller,Username))
 {
  call=1;
  clrscr();
  gotoxy(30,13);
  textcolor(WHITE+BLINK);
  cprintf(Caller);
  cprintf(" calling...");
  gotoxy(38,25);
  cout<<"Accept";
  do
  {
   ch=getch();
   if(ch==13)
   {
    FileName[0]='\0';
    strcat(FileName,"CALL\\");
    strcat(FileName,Caller);
    strcat(FileName,".dat");
    fil2.open(FileName,ios::out);
    fil2<<Username;
    fil2.close();
    time dur=Chat(Caller,Username);
    FileLog("R",Caller,Username,dur);
   }
   else if(ch==27)
   {
    FileName[0]='\0';
    strcat(FileName,"CALL\\");
    strcat(FileName,Caller);
    strcat(FileName,".dat");
    fil2.open(FileName,ios::out);
    fil2<<Caller;
    fil2.close();
    time dur={0,0,0};
    FileLog("M",Caller,Username,dur);
   }
   DePulse(Caller,Username);
  }while(ch!=27 && ch!=13);
 }
 return call;
}

void Number(char ch,int pos)
{
 int c=(pos%26)*3+1, r=(pos/26)*3+1;
 switch(ch)
 {
  case '1':
  gotoxy(c,r);  cout<<" ฟ ";
  gotoxy(c,r+1);cout<<" ณ ";
  gotoxy(c,r+2);cout<<" ม ";
  break;

  case '2':
  gotoxy(c,r);  cout<<"ฺฟ ";
  gotoxy(c,r+1);cout<<"ฺู ";
  gotoxy(c,r+2);cout<<"ภู ";
  break;

  case '3':
  gotoxy(c,r);  cout<<"ฺฟ ";
  gotoxy(c,r+1);cout<<" ด ";
  gotoxy(c,r+2);cout<<"ภู ";
  break;

  case '4':
  gotoxy(c,r);  cout<<"ฺฺ ";
  gotoxy(c,r+1);cout<<"ภด ";
  gotoxy(c,r+2);cout<<" ม ";
  break;

  case '5':
  gotoxy(c,r);  cout<<"ฺฟ ";
  gotoxy(c,r+1);cout<<"ภฟ ";
  gotoxy(c,r+2);cout<<"ภู ";
  break;

  case '6':
  gotoxy(c,r);  cout<<"ฺฟ ";
  gotoxy(c,r+1);cout<<"รฟ ";
  gotoxy(c,r+2);cout<<"ภู ";
  break;

  case '7':
  gotoxy(c,r);  cout<<"ฺฟ ";
  gotoxy(c,r+1);cout<<" ด ";
  gotoxy(c,r+2);cout<<" ม ";
  break;

  case '8':
  gotoxy(c,r);  cout<<"ฺฟ ";
  gotoxy(c,r+1);cout<<"รด ";
  gotoxy(c,r+2);cout<<"ภู ";
  break;

  case '9':
  gotoxy(c,r);  cout<<"ฺฟ ";
  gotoxy(c,r+1);cout<<"ภด ";
  gotoxy(c,r+2);cout<<"ภู ";
  break;

  case '0':
  gotoxy(c,r);  cout<<"ฺฟ ";
  gotoxy(c,r+1);cout<<"ณณ ";
  gotoxy(c,r+2);cout<<"ภู ";
  break;

  case 8:
  gotoxy(c,r);  cout<<"   ";
  gotoxy(c,r+1);cout<<"   ";
  gotoxy(c,r+2);cout<<"   ";
 }
}