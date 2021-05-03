#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>

struct engine
{
	char sno[4];
	char material[10];
	int yom;
	int qty;
}e[60];

int from=-1, to=-1;
int *picker;//used in material type and manufacturing query
int size = 0 ;//picker's size

void menu();
void fillsno();
void display();
void fillmaterial();
void fillyom();
void fillqty();
void layout();
void printall(int);
void findrange();
void query();

/*Query*/
int snoquery();
int materialquery();
void pickerprint();
int yomquery();

void main(){
	clrscr();
	fillsno();//Fills the serial no. in sequence form
	//display();
	randomize();
	fillmaterial();
	//display();
	fillyom();
	//display();
	fillqty();
	//display();
	menu();
	getch();
}


void fillsno(){
	int i;
	char letter1, no, sno[4];

	i = 0;
	letter1 = 'A';
	while(letter1<='F'){
		no = '0';
		while(no <= '9'){
			sno[0] = letter1;
			sno[1] = letter1;
			sno[2] = no;
			sno[3] = '\0';
			strcpy(e[i].sno, sno);
			i++;
			no++;
		}
		letter1++;
	}


}

void fillmaterial(){
	char *material[3] = {"Iron", "Aluminium", "Steel"};
	int i, pick;

	i = 0;
	while(i<60){
		pick = random(3);
		strcpy(e[i].material, *(material + pick));
		i++;
	}
}

void display(){
	int i =0;
	while(i<60){
		printf("%d\n", e[i].qty);
		i++;
	}
}

void fillyom(){
	int begin=1990, till=2021, diff = (till-begin)+1, year;
	int i = 0, choose;

	while(i<60){
		choose = random(diff);
		year = begin + choose;
		e[i].yom = year;
		i++;
	}

}

void fillqty(){
	int i = 0, qty;
	while(i<60){
		qty = random(1000) + 1;
		e[i].qty = qty;
		i++;
	}
}

void menu(){
	int op;
	printf("WELCOME to NEW ENGINE WORKSHOP\n\n");
	printf(" 1. VISIT OUR WORKSHOP\n");
	printf(" 2. SEE A PARTICULAR RANGE\n");
	printf(" 3. QUERY\n");
	printf(" 4. QUIT\n");
	printf("\n  Enter your choice : ");
	scanf("%d", &op);
	clrscr();
	switch(op){
		case 1 :
			printall(0);
			break;
		case 2 :
			findrange();
			clrscr();
			if(from!=-1 && to!=-1){
				printall(1);
			}else{
				puts("ENTERED INCORRECT RANGE");
			}
			break;
		case 3 :
			query();
			break;
		default :
			exit(0);
	}


	clrscr();
	menu();
}

void layout(){
	int px=0, py=1;
	gotoxy(px,py);
	printf("SERIAL NO.");
	px+=20;
	gotoxy(px,py);
	printf("MATERIAL");
	px+=20;
	gotoxy(px,py);
	printf("QUANTITY");
	px+=20;
	gotoxy(px, py);
	printf("MANUFACTURING DATE");
}

void printall(int specific){
	int i, max=60, min=0;
	int px, py=3, order;
	layout();
	if(specific){
		if(from!=-1 && to!=-1){
			min = from;
			max = to+1;
		}
	}
	i=min;
	order = 0;
	while(i<max && !kbhit()){
		px=1;
		gotoxy(px,py);
		printf("%s", e[i].sno);
		px+=20;
		gotoxy(px,py);
		printf("%s", e[i].material);
		px+=20;
		gotoxy(px,py);
		printf("%d", e[i].qty);
		px+=20;
		gotoxy(px, py);
		printf("%d", e[i].yom);
		delay(100);
		if(order==20 || order==40){
			clrscr();
			py=2;
			order = 0;
		}
		order++;
		py++;
		i++;
	}
	getch();
}
void findrange(){
	int i;
	char begin[4], end[4];
	printf("SERIAL NO. TO BEGIN : ");
	scanf("%s", begin);
	printf("SERIAL NO. TO END : ");
	scanf("%s", end);
	i = 0;
	while(i<60){
		if(strcmp(begin, e[i].sno)==0)
			from = i;
		if(strcmp(end, e[i].sno) == 0){
			to = i;
			break;
		}

		i++;
	}
}

void query(){
	int op, j, k;
	char again;
	printf("QUERY on :\n\n");
	printf("  1. Serial No.\n");
	printf("  2. Material type\n");
	printf("  3. Year of manufacturing\n\n");
	printf("Enter your choice : ");
	scanf("%d", &op);
	clrscr();
	switch(op){
		case 1 :
			do{
			clrscr();
			j = snoquery();
			clrscr();
			if(j!=-1){
				printf("\nRECORD OF S.NO. : %s\n\n", e[j].sno);
				printf("MATERIAL : %s\n", e[j].material);
				printf("QUANTITY : %d\n", e[j].qty);
				printf("MANUFACTURING YEAR : %d", e[j].yom);
			}else
				puts("Record No. not found with this serial no. ");

			printf("\n\nWant to search again : (Y/N) => ");
			scanf(" %c", &again);
			}while(again == 'y' || again == 'Y');
			break;
		case  2 :
			do{
			clrscr();
			k = materialquery();
			clrscr();
			if(k==1){
				layout();
				pickerprint();
			}else
				printf("\nNot found");

			printf("\n\nWant to search again :(Y/N) => ");
			scanf(" %c", &again);
			}while(again == 'Y' || again == 'y');
			break;
		case 3 :

			do{
			clrscr();
			k = yomquery();
			clrscr();
			if(k==1){
				layout();
				pickerprint();
			}else
				printf("\nNot found");

			printf("\n\nWant to search again :(Y/N) => ");
			scanf(" %c", &again);
			}while(again == 'Y' || again == 'y');
			break;
		default :
			break;
	}
}

int snoquery(){
	char sno[4];
	int i = 0, found = 0;
	printf("Enter Serial No. : ");
	scanf("%s", sno);
	i = 0;
	while(i<60){
		if(strcmp(sno, e[i].sno) == 0){
			found = 1;
			break;
		}
		i++;
	}
	if(found)
		return i;
	else
		return -1;
}

int materialquery(){
	int i, j=0;
	char type[10];
	printf("Enter Material Type(Iron, Aluminium, Steel <= only in camelcase) : ");
	scanf("%s", type);

	i=0;
	while(i<60){
		if(strcmp(type, e[i].material) == 0){
			size ++;
			picker = (int *) realloc(picker, size*sizeof(int));
			*(picker + j) = i;
			j++;
		}
		i++;
	}
	if(!size)
		return -1;
	else
		return 1;
}

void pickerprint(){
	int px = 1, py = 3, order = 0, i=0, packet;

	while(i<size && !kbhit()){
		packet = *(picker + i);
		px=1;
		gotoxy(px,py);
		printf("%s", e[packet].sno);
		px+=20;
		gotoxy(px,py);
		printf("%s", e[packet].material);
		px+=20;
		gotoxy(px,py);
		printf("%d", e[packet].qty);
		px+=20;
		gotoxy(px, py);
		printf("%d", e[packet].yom);
		delay(100);
		if(order==20 || order==40){
			clrscr();
			py=2;
			order = 0;
		}
		order++;
		py++;
		i++;
	}
	size=0;
	free(picker);

}

int yomquery(){
	int i, j=0;
	int yom;
	printf("Enter Year of Manufacturing : ");
	scanf("%d", &yom);

	i=0;
	while(i<60){
		if(yom == e[i].yom){
			size ++;
			picker = (int *) realloc(picker, size*sizeof(int));
			*(picker + j) = i;
			j++;
		}
		i++;
	}
	if(!size)
		return -1;
	else
		return 1;
}