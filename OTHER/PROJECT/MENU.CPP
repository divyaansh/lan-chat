//sample Program for Vertical and Horizontal Menus
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

#include <string.h>
/*
 cprintf(<String cvonstant>);
 cprintf("Hello");


 cprintf(<Format string>,<Var List>);
 int A=90, B=80, C;
 C=A+B;
 cout<<"Result="<<C<<endl;
 cprintf("Result=%d\n",C);
 cprintf("%d hello %d bye %d",A,B,C);//90 hello 80 bye 170
 cprintf("%d + %d = %d",A,B,C);//90 + 80 = 170
 cprintf("My Name is %s", Name);//My Name is Mukesh Kumar
 // %c char
 // %d int
 // %f float
 // %s string
*/
//0..255
//Constant character declaration   --------³   Ú ¿ À Ù Ä  ³
const char TL=218,TR=191,BL=192,BR=217,HL=196,VL=179;
//GENERAL FUNCTIONS PROTOTYPES
void DispCh(int C,int R,char Ch);
void DispCh(int C,int R,char Ch[]);
void Color(int TC,int TB);
void Recta(int C1,int R1,int C2,int R2);
int VMenu(int C,int R,char Men[][15],int Noo);
int HMenu(int C,int R,char Men[][15],int Noo);
//MAIN CLASS
class YourClass
{


};
//Binary file Functions
void YourBinaryFileFunctions();

void main()
{
  Color(WHITE,BLUE);
  clrscr();
  Recta(10,10,48,20);
  Recta(2,2,10,9);
  Recta(1,1,49,24);
  //While specifying the options, keep each option's no. of char same
  char Menu[][15]={"Admin ",
		   "search",
		   "Report",
		   "Quit  "};
  char SMenu[][15]={"Add New       ",
		    "Modify Class  ",
		    "Modify Section",
		    "Modify P Info ",
		    "Modify Stream ",
		    "Quit          "};
  int Quit=0;
  do
  {
    clrscr();
    //Display Main Menu1
    int N=HMenu(1,1,Menu,4),SN;
    switch (N)
    {
    case 0://Displaying Vertical Popup menu
	 SN=VMenu(1,2,SMenu,6);
	 switch(SN)
	 {
	   case 0://Call the Function for SubOption1
		DispCh(30,10,"SubOption 1");break;
	   case 1:DispCh(30,10,"SubOption 2");break;
	   case 2:DispCh(30,10,"SubOption 3");break;
	 }
	 getch();
	 break;
    case 1:DispCh(30,10,"Option 2");break;
    case 2:DispCh(30,10,"Option 3");break;
    case 3:DispCh(30,10,"Thank u");
	 Quit=1;
    }
  }
  while (!Quit);
  getch();
}
//GENRAL FUNCTIONS
void DispCh(int C,int R,char Ch)
{
  gotoxy(C,R);cprintf("%c",Ch);//C 1-80 R 1-25
}

void DispCh(int C,int R,char S[])
{
  gotoxy(C,R);cprintf("%s",S);
}

void Color(int TC,int TB)
{
  textcolor(TC);
  textbackground(TB);
}
void Recta(int C1,int R1,int C2,int R2)
{
  DispCh(C1,R1,TL);
  DispCh(C2,R1,TR);
  DispCh(C1,R2,BL);
  DispCh(C2,R2,BR);
  for (int i=C1+1;i<C2;i++)
  {
    DispCh(i,R1,HL);
    DispCh(i,R2,HL);
  }
  for (i=R1+1;i<R2;i++)
  {
    DispCh(C1,i,VL);
    DispCh(C2,i,VL);
  }
}

int VMenu(int C,int R,char Men[][15],int Noo)
{
  Color(YELLOW,BLUE);
  Recta(C,R,C+strlen(Men[0])+1,R+Noo+1);//Drawing a rectangle enclosing options
  for (int i=0;i<Noo;i++)
    DispCh(C+1,R+i+1,Men[i]);           //Displaying All options

  int Exit=0,Sel=0;

  do
  {
    int Tsel=Sel;
    Color(BLUE,YELLOW);          //Changing color for highlighting
    DispCh(C+1,R+Sel+1,Men[Sel]);//Redisplaying the selected option with changed color
    Color(YELLOW,BLUE);          //Changing color to normal
    char Ch=getch();             //Accepting option from user
    switch(Ch)
    {
    case 71:Sel=0;break;        //Home -> Move to first option
    case 79:Sel=Noo-1;break;    //End  -> Move to Last option
    case 72:if (Sel==0)         //Up   -> Checking if already on top
	      Sel=Noo-1;        //        Move to the last option
	    else                //
	      Sel--;            //        Move one option up
	    break;
    case 80:if (Sel==Noo-1)     //Down -> Checking if already at bottom
	      Sel=0;            //        Move to the first option
	    else                //
	      Sel++;            //        Move one step down
	    break;
    case 27:Sel=-1;      //Escape-> Getting out of the Menu without valid selection
    case 13:Exit=1;      //Enter-> Getting out of the Menu with current selection
    }
    DispCh(C+1,R+Tsel+1,Men[Tsel]);//Redisplaying the non-highlighted option
  }
  while (!Exit);
  return Sel;             //Returning the selected value from menu
}
int HMenu(int C,int R,char Men[][15],int Noo)
{
  int Exit=0,Sel=0;
  Color(YELLOW,BLUE);
  for (int i=0;i<Noo;i++)
    DispCh(C+10*i+1,R,Men[i]);
  do
  {
    int Tsel=Sel;
    Color(BLUE,YELLOW);
    DispCh(C+10*Sel+1,R,Men[Sel]);
    Color(YELLOW,BLUE);
    char Ch=getch();
    switch(Ch)
    {
    case 71:Sel=0;break;     //Home
    case 79:Sel=Noo-1;break; //End
    case 75:if (Sel==0)      //Left
	  Sel=Noo-1;
	else
	  Sel--;
	break;
    case 77:if (Sel==Noo-1)  //Right
	  Sel=0;
        else
          Sel++;
        break;
    case 27:Sel=-1;    //Escape
    case 13:Exit=1;   //Enter
    }
    DispCh(C+10*Tsel+1,R,Men[Tsel]);
  }
  while (!Exit);
  return Sel;
}
