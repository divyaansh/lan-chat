#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

char Username[33]="", Password[33]="";

class USER;

void Screen1();
void ClearFiles();
int LogIn();
void Layout_LogIn();
int Validity();
int Search_LogIn();
int Condition();
int SignUp();
void Layout_SignUp();
void File_SignUp();

void Account();
void Screen2();
void Desktop();
void Theme();
void Wallpaper();
void Header();
void Time();
void Menu();

void Online();
void Offline();
void CopyFile(char [], char []);

void Dial(char);
void Number(char, int);
int Caller();

void Call(char []);
int Search_Online(char []);
int Pulse(char []);
void DePulse();
void Chat(char []);
void HeadFoot(char []);
void TimeCall();

void Messages();
 void CreateMessage();
 void Inbox();
 void Sentbox();
 void Outbox();
 void Drafts();
 void MessageSettings();

void Phonebook();

void CallLog();
 void Received();
 void Dialled();
 void Missed();
 void CallDuration();
 void CallCosts();

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

class USER
{
 char Username[33], Password[33];
 public:
  char* R_Username(){return Username;}
  char* R_Password(){return Password;}
  void Change_Username(char Name[]){strcpy(Username,Name);}
  void Change_Password(char Pass[]){strcpy(Password,Pass);}
};

class ENTRY
{
 char Name[33], PhoneNo[33];
 public:
  char* R_Name(){return Name;}
  char* R_PhoneNo(){return PhoneNo;}
  void Change_Name(char New_Name[]){strcpy(Name,New_Name);}
  void Change_Password(char Pass[]){strcpy(Password,Pass);}
};

/////////////////////////////////////////////////////////////////////////////

void A()
{
 clrscr();
 USER U;
 fstream fil;
 fil.open("ONLINE.txt",ios::in|ios::binary);
 while(fil.read((char*)&U,sizeof(U)))
  cout<<U.R_Username()<<" "<<U.R_Password()<<endl;
 fil.close();
 delay(1000);
}

/////////////////////////////////////////////////////////////////////////////

void main()
{
 Screen1();
 while(LogIn())
 {
  Account();
 }
}

/////////////////////////////////////////////////////////////////////////////

void Screen1()
{
 clrscr();
}

void ClearFiles()
{
 fstream fil;
 fil.open("ONLINE.txt",ios::out);
 fil.close();
}

#define username(Q) {gotoxy(30,12);textcolor(Q);cprintf("Phone No: ");cprintf(Username);}
#define password(Q) {gotoxy(30,13);textcolor(Q);cprintf("Password: ");for(j=0;Password[j]!='\0';j++)cprintf("*");}
#define log_in(Q)   {gotoxy(36,15);textcolor(Q);cprintf("Log In");}
#define sign_up(Q)  {gotoxy(1,25);textcolor(Q);cprintf("Sign Up");}


void Layout_LogIn(int p)
{
 int j;
 switch(p)
  {
   case 0:
    username(CYAN);
    password(WHITE);
    log_in(WHITE);
    sign_up(WHITE);
    break;

   case 1:
    username(WHITE);
    password(CYAN);
    log_in(WHITE);
    sign_up(WHITE);
    break;

   case 2:
    username(WHITE);
    password(WHITE);
    log_in(CYAN);
    sign_up(WHITE);
    break;

   case 3:
    username(WHITE);
    password(WHITE);
    log_in(WHITE);
    sign_up(CYAN);
    break;
 }
}

#define IN(ROW,WORD,Q,CH){gotoxy(30,ROW);clreol();textcolor(RED);cprintf(WORD);_setcursortype(_NORMALCURSOR);i=0;ch=getch();while(ch!=13){textcolor(RED);if(ch==8){if(i>0){cprintf("\b \b");i--;}}else{cprintf(CH);Q[i++]=ch;}ch=getch();}Q[i]='\0';}

int LogIn()
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
  Layout_LogIn(pos);
  char key=getch();
  if(key==50||key==54||key==80||key==77)
   pos=pos==3?0:pos+1;
  else if(key==72||key==75||key==52||key==56)
   pos=pos==0?3:pos-1;
  else if(key==13)
  {
   switch(pos)
   {
    case 0:
     IN(12,"Phone No: ",Username,&ch);
     break;

    case 1:
     IN(13,"Password: ",Password,"*");
     break;

    case 2:
     gotoxy(36,15);
     textcolor(RED);
     cprintf("Log In");
     delay(100);
     if(!Search_LogIn())
     {
      gotoxy(30,15);
      textcolor(RED);
      cprintf("Incorrect Phone No/Password");
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
     textcolor(RED);
     cprintf("Sign Up");
     delay(100);
     log=SignUp();
     if(log)exit=1;
     break;
   }
   _setcursortype(_NOCURSOR);
  }
  else if(key==27)
   exit=1;
 }
 return log;
}

int Condition(char ch)
{
 return !((ch>=65 && ch<=90)||(ch==95)||(ch>=97 && ch<=122)||(ch>=48&&ch<=57));
}

int Validity()
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

int Search_LogIn()
{
 int found=0;
 USER U;
 fstream file;
 file.open("USER.txt",ios::binary|ios::in);
 while(!found && file.read((char*)&U,sizeof(U)))
 {
  if(strcmp(U.R_Username(),Username)==0 && strcmp(U.R_Password(),Password)==0)
   found++;
 }
 file.close();
 return found;
}

/////////////////////////////////////////////////////////////////////////////

#define reenter(Q) {gotoxy(30,14);textcolor(Q);cprintf("Re-Enter: ");for(j=0;Password2[j]!='\0';j++)cprintf("*");}
#define sign_up2(Q) {gotoxy(36,16);textcolor(Q);cprintf("Sign Up");}

void Layout_SignUp(int p,char Password2[])
{
 int j;
 switch(p)
  {
   case 0:
    username(CYAN);
    password(WHITE);
    reenter(WHITE);
    sign_up2(WHITE);
    break;

   case 1:
    username(WHITE);
    password(CYAN);
    reenter(WHITE);
    sign_up2(WHITE);
    break;

   case 2:
    username(WHITE);
    password(WHITE);
    reenter(CYAN);
    sign_up2(WHITE);
    break;

   case 3:
    username(WHITE);
    password(WHITE);
    reenter(WHITE);
    sign_up2(CYAN);
    break;
 }
}

int SignUp()
{
 int pos=0,exit=0,i,log=0;
 char ch,Password2[33]="";
 Username[0]='\0';
 Password[0]='\0';
 _setcursortype(_NOCURSOR);
 while(!exit)
 {
  clrscr();
  gotoxy(34,10);
  textcolor(WHITE);
  cprintf("Signing Up");
  Layout_SignUp(pos,Password2);
  char key=getch();
  if(key==50||key==54||key==80||key==77)
   pos=pos==3?0:pos+1;
  else if(key==72||key==75||key==52||key==56)
   pos=pos==0?3:pos-1;
  else if(key==13)
  {
   switch(pos)
   {
    case 0:
     IN(12,"Phone No: ",Username,&ch);
     break;

    case 1:
     IN(13,"Password: ",Password,"*");
     break;

    case 2:
     IN(14,"Re-Enter: ",Password2,"*");
     break;

    case 3:
     gotoxy(36,16);
     textcolor(RED);
     cprintf("Sign Up");
     delay(100);
     if(!Validity() || strcmp(Password,Password2)!=0)
     {
      gotoxy(30,15);
      textcolor(RED);
      cprintf("Invalid Username/Password");
      delay(1000);
     }
     else
     {
      File_SignUp();
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

void File_SignUp()
{
 fstream file;
 file.open("USER.txt",ios::binary|ios::app);
 USER U;
 U.Change_Username(Username);
 U.Change_Password(Password);
 clrscr();
 file.write((char*)&U,sizeof(U));
 file.close();
}

/////////////////////////////////////////////////////////////////////////////

void Online()
{
 USER U;
 U.Change_Username(Username);
 U.Change_Password(Password);
 fstream fil;
 fil.open("ONLINE.txt",ios::binary|ios::app);
 fil.write((char*)&U,sizeof(U));
 fil.close();
}

void Offline()
{
 USER U;
 fstream fil,temp;
 fil.open("ONLINE.txt",ios::binary|ios::in);
 temp.open("TEMP.txt",ios::binary|ios::out);
 while(fil.read((char*)&U,sizeof(U)))
  if(strcmp(U.R_Username(),Username)!=0)
   temp.write((char*)&U,sizeof(U));
 fil.close();
 temp.close();
 CopyFile("ONLINE.txt","TEMP.txt");
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

void Account()
{
 Screen2();
 Online();
 //A();
 char ch1;
 do
 {
  Desktop();
  while(!kbhit())
  {
   if(Caller())
    Desktop();
   Time();
   delay(100);
  }
  ch1=getch();
  if(ch1==13)
  {
   Menu();
  }
  if(ch1>=48&&ch1<=57 || ch1=='+' || ch1=='*')
  {
   Dial(ch1);
  }
  if(ch1==27)
  {
   textcolor(RED);
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
 Offline();
 //A();
}

void Desktop()
{
 Wallpaper();
 Theme();
 Header();
 gotoxy(39,25);
 textcolor(RED);
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
 strcpy(FileName,"ferrari.txt");
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

#define option(WORD,Q,COLUMN,ROW) {gotoxy(COLUMN-strlen(WORD)/2,ROW);textcolor(Q);cprintf(WORD);}

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

void Menu()
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
     option("Messages",RED,20,8);
     delay(100);
     Messages();
     break;

    case 1:
     option("Phonebook",RED,40,8);
     delay(100);
     Phonebook();
     break;

    case 2:
     option("Call Log",RED,60,8);
     delay(100);
     CallLog();
     break;

    case 3:
     option("Organiser",RED,20,16);
     delay(100);
     Organiser();
     break;

    case 4:
     option("Settings",RED,40,16);
     delay(100);
     Settings();
     break;

    case 5:
     option("Media",RED,60,16);
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
   textcolor(RED);
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

void CallLog()
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
   textcolor(RED);
   cprintf(options[pos]);
   delay(100);
   switch(pos)
   {
    case 0:
     Received();
     break;

    case 1:
     Dialled();
     break;

    case 2:
     Missed();
     break;

    case 3:
     CallDuration();
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

void Received(){}
 void Dialled(){}
 void Missed(){}
 void CallDuration(){}
 void CallCosts(){}

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
   textcolor(RED);
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
   textcolor(RED);
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
   textcolor(RED);
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
/*
{
 gotoxy(30,ROW);
 clreol();
 textcolor(RED);
 cprintf(WORD);
 _setcursortype(_NORMALCURSOR);
 i=0;
 ch=getch();
 while(ch!=13)
 {
  textcolor(RED);
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
   cout<<"*";
   Q[i++]=ch;
  }
 ch=getch();
 }
 Q[i]='\0';
}
*/

void Dial(char ch)
{
 clrscr();
 gotoxy(38,25);
 cout<<"Call";
 gotoxy(32,13);
 char PhoneNo[33];
 PhoneNo[0]=ch;
 Number(ch,0);
 int i=1;
 //do
 //{
  do
  {
   ch=getch();
   if(ch>=48&&ch<=57)
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
   Call(PhoneNo);
 //}while(ch!=27);
}

int Search_Online(char PhoneNo[])
{
 int found=0;
 if(strcmp(PhoneNo,Username)!=0)
 {
  USER U;
  fstream file;
  file.open("ONLINE.txt",ios::binary|ios::in);
  while(!found && file.read((char*)&U,sizeof(U)))
  {
   if(strcmp(U.R_Username(),PhoneNo)==0)
    found++;
  }
  file.close();
 }
 return found;
}

int Pulse(char PhoneNo[])
{
 fstream fil;
 char FileName[40]="";
 strcat(FileName,"CALL\\");
 strcat(FileName,PhoneNo);
 strcat(FileName,"CALL.txt");
 fil.open(FileName,ios::out);
  fil<<Username;
 fil.close();

 char data[33];
 int accept=0,exit=0;
 FileName[0]='\0';
 strcat(FileName,"CALL\\");
 strcat(FileName,Username);
 strcat(FileName,"CALL.txt");
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

void DePulse(char PhoneNo[])
{
 fstream fil,fil2;
 char FileName[40]="";
 strcat(FileName,"CALL\\");
 strcat(FileName,PhoneNo);
 strcat(FileName,"CALL.txt");
 fil.open(FileName,ios::out);
 fil.close();

 FileName[0]='\0';
 strcat(FileName,"CALL\\");
 strcat(FileName,Username);
 strcat(FileName,"CALL.txt");
 fil2.open(FileName,ios::out);
 fil2.close();
}

void Chat(char PhoneNo[])
{
 _setcursortype(_NORMALCURSOR);
 char User[33],ch,Lin2[80]="";
 int l=3,i=0,read=0;
 strcpy(User,Username);
 fstream fil3;
 char FileName[40]="";
 strcat(FileName,"CHAT\\");
 strcat(FileName,User);
 strcat(FileName,"CHAT.txt");
 fil3.open(FileName,ios::out);
 fil3.close();
 textcolor(WHITE);
 clrscr();
 HeadFoot(PhoneNo);
 do
 {
  while(!kbhit())
  {
   char Lin[80]="";
   fstream fil;
   char FileName[40]="";
   strcat(FileName,"CHAT\\");
   strcat(FileName,User);
   strcat(FileName,"CHAT.txt");
   fil.open(FileName,ios::in);
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
     cout<<PhoneNo<<":"<<Lin<<"\n\n\n\n";
     HeadFoot(PhoneNo);
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
   textcolor(RED);
   cout<<ch;
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
    HeadFoot(PhoneNo);
   }
   fstream fil2;
   FileName[0]='\0';
   strcat(FileName,"CHAT\\");
   strcat(FileName,PhoneNo);
   strcat(FileName,"CHAT.txt");
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
   textcolor(RED);
   _setcursortype(_NOCURSOR);
   gotoxy(20,11);cprintf("ษออออออออออออออออออออออออออออออออออออออป");
   gotoxy(20,12);cprintf("บ                                      บ");
   gotoxy(20,13);cprintf("บ             CALL ENDED               บ");
   gotoxy(20,14);cprintf("บ                                      บ");
   gotoxy(20,15);cprintf("ศออออออออออออออออออออออออออออออออออออออผ");
   gotoxy(i+strlen(User)+2,24);
   getch();
  }
 }while(ch!=27);
}

void HeadFoot(char PhoneNo[])
{
 textcolor(RED);
 gotoxy(1,1);
 clreol();
 cprintf(PhoneNo);
 TimeCall();
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

void TimeCall()
{}

void Call(char PhoneNo[])
{
 clrscr();
 gotoxy(32,13);
 int on=Search_Online(PhoneNo);
 if(on)
 {
  textcolor(WHITE+BLINK);
  cprintf("Calling ");
  cprintf(PhoneNo);
  int accept=Pulse(PhoneNo);
  if(accept)
   Chat(PhoneNo);
  else
  {
   textcolor(RED);
   gotoxy(1,13);
   clreol();
   gotoxy(36,13);
   cprintf("User Busy");
   getch();
  }
  DePulse(PhoneNo);
 }
 else
 {
  textcolor(RED);
  gotoxy(1,13);
  clreol();
  gotoxy(36,13);
  cprintf("Unavailable");
  getch();
 }
}

int Caller()
{
 int call=0;
 fstream fil,fil2;
 char Caller[33],FileName[20]="",ch;
 strcat(FileName,"CALL\\");
 strcat(FileName,Username);
 strcat(FileName,"CALL.txt");
 fil.open(FileName,ios::in);
 fil.getline(Caller,33);
 if(Search_Online(Caller))
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
    strcat(FileName,"CALL.txt");
    fil2.open(FileName,ios::out);
    fil2<<Username;
    fil2.close();
    Chat(Caller);
   }
   else if(ch==27)
   {
    FileName[0]='\0';
    strcat(FileName,"CALL\\");
    strcat(FileName,Caller);
    strcat(FileName,"CALL.txt");
    fil2.open(FileName,ios::out);
    fil2<<Caller;
    fil2.close();
   }
   DePulse(Caller);
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