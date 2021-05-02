#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>

#define HOR for(use = 1; use<=80; use++)\
		printf("%c", 196);
#define VER printf("%c", 179);
#define LBOT printf("%c", 192);
#define RBOT printf("%c", 217);
#define T printf("%c", 193);

int use;//for using in MACROS
static int i= 0;//very important
//Request Auto-Detection
int gd = DETECT, gm, error;

struct bank{
	char acno[20];
	char name[20];
	int bal;
	char password[10];
}b[5];

void randomcircle();
void openingscreen();
void menu();

void createac();
void printinfo();
void createlayout();
void query();
void money();
int check();
void showinfo(int);
void deposit(int);
void withdraw(int);
void transact(int);

void main(){
	clrscr();
	openingscreen();
	menu();
	getch();
}

void openingscreen(){



	int maxx, maxy, tmp;//maxx, maxy = > highest screen resolution
	//Initializes the graphics system
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	//check for errors
	error = graphresult();
	if(error!=0){
		printf("Grpahics error : %s\n", grapherrormsg(error));
		printf("Press any key to halt...");
		getch();
		exit(1);
	}
	maxx = getmaxx();
	maxy = getmaxy();
	/*
	setcolor(3);
	setfillstyle(7, 11);
	rectangle((maxx/2-150), (maxy/2-150), (maxx/2+150), (maxy/2+150));
	floodfill(maxx/2, maxy/2, 3);
	*/
	setcolor(10);
	setfillstyle(4, 10);
	circle(0, 0, 100);
	floodfill(0, 0, 10);
	circle(maxx, 0, 100);
	floodfill(maxx, 0, 10);
	circle(0, maxy, 100);
	floodfill(0, maxy, 10);
	circle(maxx, maxy, 100);
	floodfill(maxx, maxy, 10);

	tmp = 0;
	randomize();
	while(!kbhit()){
	  if(tmp){
		setcolor(random(14)+1);
		tmp = 0;
	  }else{
		setcolor(BLACK);
		tmp = 1;
	  }
	  setlinestyle(2, 0, 3);
	//B
		line(100, 120, 100, 360);
		delay(100);
		line(100, 360, 200, 300);
		delay(200);
		line(200, 300, 100, 240);
		delay(300);
		line(100, 240, 200, 180);
		delay(100);
		line(200, 180, 100, 120);
		delay(200);
	//A
		line(220, 300, 250, 180);
		line(250, 180, 280, 300);
		circle(250, 240, 10);
	//N
		line(300, 300, 300, 180);
		line(300, 180, 350, 300);
		line(350, 300, 350, 180);
	//K
		line(400, 150, 400, 330);
		line(400, 240, 480, 160);
		line(400, 240, 480, 340);
	}
	closegraph();
	randomcircle();
	getch();
	clrscr();


}
void randomcircle(){
	int i = 1, x, y, color, r;
	int maxx, maxy;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	error = graphresult();
	if(error!=0){
		printf("Graphics error in randomcircle : %s\n", grapherrormsg(error));
		printf("Press any key to halt");
		getch();
		exit(1);
	}
	maxx = getmaxx();
	maxy = getmaxy();
	setlinestyle(0, 0, 1);
	while(i<=10){
		color = random(15);
		setcolor(color);
		x = random(maxx);
		y = random(maxy);
		r = random(200);
		circle(x, y, r);
		setfillstyle(1, color);
		floodfill(x, y, color);

		delay(100);
		i++;
	}
	closegraph();
}

void menu(){
	int op;
	printf("Turbo-C Bank Department\n\n");
	printf(" 1. Create an account\n");
	printf(" 2. Query within account\n");
	printf(" 3. Withdraw/Deposit/Make Transactions\n");
	printf(" 4. See all records(Only for MANAGER)\n" );
	printf(" 5. EXIT\n\n");
	HOR;
	printf("\nEnter your choice(1/2/3/4) : ");
	scanf("%d", &op);
	clrscr();
	switch(op){
		case 1 :
			createac();
			break;
		case 2 :
			query();
			break;
		case 3 :
			money();
			//Transaction Department
			break;
		case 4 :
			printinfo();
			//Manager's Department
			break;
		case 5 :
			puts("Very Thankful! that you tried our product");
			puts("HARE KRISHNA");
			delay(1000);
			randomcircle();
			exit(0);
		default :
			randomcircle();
			exit(1);
	}
}

void createac(){
	char again;
	do{
		textbackground(WHITE);
		textcolor(0);
		cprintf("\nWELCOME to ACCOUNT CREATION DEPARTMENT");
		textcolor(WHITE);
		textbackground(0);
		printf("\n");
		HOR;
		printf("\n");
		printf("Entry No. %d\n\n", i+1);

		textbackground(WHITE);
		textcolor(0);
		cprintf("AC/NO :- ");
		scanf("%s", b[i].acno);
		cprintf("NAME :- ");
		scanf("%s", b[i].name);
		cprintf("BALANCE :- ");
		scanf("%d", &b[i].bal);
		cprintf("SECURITY KEY :- ");
		scanf("%s", b[i].password);
		textcolor(WHITE);
		textbackground(0);

		printf("Open 1 more Account(Y/N) : ");
		scanf(" %c", &again);
		i++;
		clrscr();
	}while(again=='y' || again=='Y');
	randomcircle();
	menu();
}

void printinfo(){
	char manager[10];
	printf("ENTER PASSCODE : ");
	scanf("%s", manager);
	if(strcmp(manager, "manager") == 0){
		randomcircle();
		createlayout();
	}
	else{
		printf("UNAUTHORIZED ACCESS");
	}
	getch();
	randomcircle();
	menu();
}

void createlayout(){
	int j, px=0, py=2;
	textbackground(15);
	textcolor(0);
	clrscr();

	HOR;
	gotoxy(px, py);
	printf("  NAME");
	px+=20;
	gotoxy(px, py);
	VER;

	printf("  AC/NO");
	px+=20;
	gotoxy(px, py);
	VER;

	printf("  BALANCE");
	px+=20;
	gotoxy(px, py);
	VER;

	printf("  PASSWORD");
	printf("\n");
	HOR;
	py++;
	if(!i){
		printf("Nothing in Records. TILL NOW.");
	}else{
		j = 0;
		while(j<i){
			px=0;
			py++;


			gotoxy(px, py);
			printf("%s", b[j].name);
			px+=20;
			gotoxy(px, py);
			VER;

			printf("%s", b[j].acno);
			px+=20;
			gotoxy(px, py);
			VER;

			printf("%d", b[j].bal);
			px+=20;
			gotoxy(px, py);
			VER;

			printf("%s", b[j].password);
			printf("\n");

			j++;
		}
	}
	textbackground(0);
	textcolor(15);

}

void query(){
	char q_acno[20], q_pass[20];
	int j;
	textcolor(YELLOW);
	if(i){
		cprintf("KNOW ALL ABOUT YOUR ACCOUNT HERE");
		//Check for authorized user
		j = check();
		//Checking ends here
		if(j>=0){
			showinfo(j);
		}else{
			printf("Sorry! Either you have misspelled\n  or you don't have any account here");
		}
		getch();
	}else{
		printf("NOT any record in the register YET.");
		delay(1000);
	}
	textcolor(WHITE);
	randomcircle();
	menu();
}

void money(){
	int op, found;
	if(!i){
		printf("Nothing in the ENTRIES yet!");
		delay(1000);
	}else{

	textcolor(BLUE);

	cprintf("Serving DEPT.");
	textcolor(YELLOW);

	cprintf("\n\r  1. WITHDRAW Cash");
	cprintf("\n\r  2. DEPOSIT Money");
	cprintf("\n\r  3. Make TRANSACTION");
	cprintf("\n\r  4. GO BACK");
	textcolor(15);
	textbackground(0);
	printf("\n\r");
	HOR;
	printf("\n Choose (1/2/3/4) : ");
	scanf("%d", &op);
	switch(op){
		case 1 :
			found = check();
			if(found>=0){
				showinfo(found);
				withdraw(found);
			}
			else
				puts("Incorrect info OR A/C not created");
			break;
		case 2 :
			found = check();
			if(found>=0){
				showinfo(found);
				deposit(found);
			}
			else
				puts("Incorrect info OR A/C not created");
			break;
		case 3 :
			found = check();
			if(found>=0){
				showinfo(found);
				transact(found);
			}else
				puts("Incorrect info OR A/C not created");

			break;
		default :
			break;
	}
	getch();
	}
	randomcircle();
	menu();
}

int check(){
	char q_acno[20], q_pass[20];
	int found=0, j=0;
	printf("\n\n  Enter your AC/NO. => ");
	scanf("%s", q_acno);
	printf("  Enter your Security key => ");
	scanf("%s", q_pass);
	while(j<i){
		if(strcmp(b[j].acno, q_acno) == 0 && strcmp(b[j].password, q_pass) == 0){
			found = 1;
			break;
		}
		j++;
	}
	if(found)
		return j;
	else
		return -1;
}

void showinfo(int j){
       printf("\nInfo of AC/NO. : %s\n", b[j].acno);
       HOR;
       printf("\nYour Name : %s\n", b[j].name);
       printf("Balance in AC. : %d\n", b[j].bal);
       printf("Security KEY : %s\n", b[j].password);
       HOR;
}

void deposit(int j){
	int dep;
	HOR;
	printf("Enter the amount to be deposited : ");
	scanf("%d", &dep);
	b[j].bal += dep;
	delay(1000);
	printf("Your Current balance is : %d\n", b[j].bal);
	puts("Thank You! for using our service");
}


void withdraw(int j){
	int cash;
	char sure;
	HOR;
	printf("Enter the amount to be withdrawn : ");
	scanf("%d", &cash);
	if(cash>(b[j].bal-100)){
		puts("You don't have enough balance to withdraw");
		puts("At Least Rs.100 must be in your account always");
	}else{
		printf("Are you Sure : (Y/N) => ");
		scanf(" %c", &sure);
		if(sure=='y' || sure=='Y'){
			b[j].bal -= cash;
			printf("Left balance : %d", b[j].bal);
		}else{
			printf("OK! No ISSUE");
		}
		printf("Thankyou! For using this dept. service");
	}
}

void transact(int j){
	char q_acno[20], sure;
	int j2=0, cash;
	HOR;
	printf("Enter the A/C no. for transaction : ");
	scanf("%s", q_acno);
	while(j2<i){
		if(strcmp(q_acno, b[j2].acno) == 0)
			break;
		j2++;
	}
	if(j2==i || j2==j)
		printf("Sorry Sir! RECORD NOT FOUND");
	else{
		printf("Enter amount to be transacted : ");
		scanf("%d", &cash);
		if(cash>(b[j].bal-100)){
			puts("You don't have enough balance to transfer");
			puts("At Least Rs.100 must always be in your account");
		}else{
			printf("Are you Sure : (Y/N) => ");
			scanf(" %c", &sure);
			if(sure=='y' || sure=='Y'){
				b[j].bal -= cash;
				b[j2].bal += cash;
				printf("Left balance : %d", b[j].bal);
			}else{
				printf("OK! No ISSUE");
			}
		printf("\nThankyou! For using this dept. service");
	}
	}
}