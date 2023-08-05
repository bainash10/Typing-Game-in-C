#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include<stdlib.h>

static int x=1;//used for x cursor co-ordinate
#define pos gotoxy(33,x++) /*for cursor movement*/
#define ln  printf(".......................");
//.......................................................................................................................................................................
 COORD coord={0,0};
 void gotoxy(int x,int y);
void gotoxy(int x,int y)//function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//.......................................................................................................................................................................
void delay(unsigned int mseconds)//function for delay
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}
//.............................................................................................................................................................................
void setcolor(int ForgC) //function to change setcolor
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }

//.................................................................................................................................................................................
void sett();//sets time limit for playing game
int t=30;
int c=0;

char name[15];
void getscore(int score,int speed,int level);
void startgame();  //to start the game
void scorecard();  //to update high score
void About_me();
void help();
//...............................................................................................................................................................................

void rectangle(int x,int y,int l,int b)//to create a rectangle
{
    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
   
}

//................................................................................................................................................................................
//			main function
int main()
{       int ch;

	time_t t;
	time(&t);
rectangle(0,0,80,20);
	x=1;
	system("cls");  //clear screen
	pos;
	setcolor(11) ;
	printf("Hello World, Let the game begin!");
	setcolor(14) ;
	pos;   //position specific thau ma halcha
	printf("%s",ctime(&t)); //current time and date print gareko cha
	pos;
    ln pos;
	if(c==0)
	   {	printf("Enter player's name::"); 
	    
		gets(name);
	   }
	   c++;
	pos;
	ln pos;

		printf("#..MAIN MENU..#");
		pos;
		ln pos;

		printf("1.Startgame");
		pos;
		printf("2.Scorecard");
		pos;
		printf("3.Set the time limit");
		pos;
		printf("4.Help");
		pos;
		printf("5.About US");
		pos;
		printf("0.exit");
		pos;
		printf("Enter your choice::");
		scanf("%d",&ch);
		pos;
		switch(ch)
		{       case 1:startgame();break;
			case 2:scorecard();break;
			case 3:sett();main();
			case 4:help();break;
			case 5:About_me();break;
			case 0:system("cls");gotoxy(17,10);printf("#This Game is edited by Nis#");delay(1000);exit(1);
			default:main();
		}

getch();
}
//.....................end of main function.................................

			   //startgame
//..........................................................................
void startgame()
{       int score=0,level=1,mode=100,count=0;
	clock_t begin;int time_spent,speed;

	int r,letter,ch;
rectangle(0,0,80,20);
	delay(500);

	system("cls");
	srand(time(NULL)) ; //initilizes random function and seed with time
	x=2;
	pos;
	setcolor(14);
	printf("#..select the Mode..#");pos;
	ln
	pos;
	printf("1.Easy mode#");
	pos;
	printf("2.Normal mode#");
	pos;
	printf("3.hard mood#");
	pos;
	printf("4.Back to main menu#");
	pos;
	scanf("%d",&level);
	if(level==4)
	main();

	else

	{     if(level==1)    //boundary addition for lowercase alphabet
	       mode=65;
	     if(level==2)    //boundary addition for uppercase
		mode=97;
	     if(level==3)    //condition for mixed case
		mode=120;
		begin=clock();
		while(1)
		{       system("cls");
			time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;

			if(time_spent>=t)
			break;
			r=rand()%1000;
			r=r%26+mode;
			gotoxy(20,8);
			printf("....Type the following character....");
			gotoxy(36,11) ;
			printf(" %c",r); //prints random character

			letter=getch();

			if(letter!=r)
			{
			system ("cls");
			printf("Looser!");
			break;
			}
			else
			{       count++;
				score=score+10;
				gotoxy(28,9);
				printf("score=%d",score);//prints score
				gotoxy(37,9);
				printf("time_spent=%d sec",time_spent);//prints time spent during game

				if(level==1)
				delay(400);
				if(level==2)
				delay(200);
				if(level==3)
				delay(100);

			} //end of else
		}//end of while
		gotoxy(26,x);

		delay(400);

		setcolor(6); //blue text color
		++x;
		pos;
		speed=(count*60)/time_spent ;
	       //	symbol=2;
		if(time_spent<t-1)
		{
		
		system("cls");
		printf("You  are looser! Game Over! Better Luck Next Time!");
		}
		else
		{       setcolor(12);
			printf("Times up !Game over!");
			pos;
			setcolor(4);
			if((speed>=40)&&(speed<=50))
			{	printf("Good Work !Keep it up!");pos;

				printf("You got silver medal");
			}
			else
			if(speed>50)
			{
				printf("Nice work! You got Gold medal");
			}
			else
			printf("Sorry no medal !Try Harder..");
		}
		pos;
		printf("Total score is ::%d",score);
		pos;

		printf("Your net speed=%d letter per minute",speed);

		getscore(score,speed,level);//saves data to file
		++x;
		pos;
		printf("1.# play again #");
		pos;

		printf("2.# main menu #");pos;
		printf("3.exit"); pos;
		printf("Enter your choice::");
		scanf("%d",&ch);
		switch(ch)
		{
		      case 1:startgame();break;//recursive call
		      case 2:main();break;
		      case 3:system("cls");gotoxy(17,10);printf("#This Game is edited by Nis#");delay(1000);exit(1);
		      default:pos;printf("wrong choice!");pos;
				main();
		}

	}

}
//......................end of start game function..........................


//...........................sett function starts..........................
void sett()  //set time limit
{
	int ch;
	system("cls");
	rectangle(0,0,80,20);
	setcolor(14);
	x=5;
	pos;
	printf("Set the time limit for game in minute::");
	pos;
	ln
	pos;
	printf("press 0 for 10seconds") ;pos;
	printf("press 1 for 1 minute"); pos;
	printf("press 2 for 2 minute");pos;
	scanf("%d",&ch);
	switch(ch)
	{
		case 0:t=10;break;
		case 1:t=60;break;
		case 2:t=120;break;
		default:main();
	}
}
//....................sett function ends....................................

//........................................................................
void help()
{
	system("cls");

	gotoxy(7,5);
	setcolor(6);

	printf("#......Rules of the Game......#");gotoxy(7,6);
	printf("=>Enter your name as player name");gotoxy(7,7);
	printf("=>Set the time limit under option 3 in main menu(default limit is 30 sec)");gotoxy(7,8);
	printf("=>select the level and get started :");gotoxy(7,9);
	printf("=>Characters are displayed and you have to type them as fast as you can..");gotoxy(7,10);
	printf("=>Avoid incorrect typing otherwise game will be over..");
	getch();main();
}
void About_me()
{       system("cls");
	gotoxy(7,7);
	printf("Hello everyone");
       getch();
       main();
}
//.........................................................................
void getscore(int score,int speed,int level)
{
	FILE *fp;
	fp=fopen("file.txt","a");
	pos;
	if(fp==NULL)
	printf("error in opening file");
	fprintf(fp,"\nname=%s   score=%d    speed=%d    level=%d",name,score,speed,level);
	fclose(fp);
	pos;
	printf("scorecard updated");
}
void scorecard()
{       int ch;
	FILE *fp;
	system("cls");
	x=3;

	printf("\t....The scores are...\n");

	fp=fopen("file.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{	printf("%c",ch);
	}
	getch();
	main();
}


