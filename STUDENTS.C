#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>

#define HOR for(use=1; use<=80; use++) \
		printf("%c", 196);
#define VER printf("%c", 179);


int use;//for using in MACROS
static int i = 0;

struct students{
	char name[10];
	char dept[10];
	char course[10];
	int yoj;
	int roll;
}s[5];

void menu();
void fill();
void print(int);
void query();

void main(){

	clrscr();
	menu();
	getch();
}

void menu(){
	int op, time;
	clrscr();
	printf("Student's Info Control Dept.");
	printf("\n\n 1. Fill Information");
	printf("\n 2. Print All Information");
	printf("\n 3. Query a information");
	printf("\n 4. EXIT\n\n");
	printf("Please enter your choice(1/2/3/4) : ");
	scanf("%d", &op);

	clrscr();
	switch(op){
		case 1 :
			fill();
			break;
		case 2 :
			print(0);
			break;
		case 3 :
			query();
			break;
		case 4 :
			clrscr();
			printf("Thanks for using our product\nHARE KRISHNA");
			delay(1000);
			exit(0);
		default :
			time = 3;
			while(time){
				printf("Program is going to terminate in %d seconds...", time);
				delay(1000);
				clrscr();
				time--;
			}
			exit(1);

	}

}

void fill(){
	char again;

	do{
		printf("Entry No. : %d\n", i+1);
		printf("NAME : ");
		scanf("%s", &s[i].name);
		printf("ROLL : ");
		scanf("%d", &s[i].roll);
		printf("DEPARTMENT : ");
		scanf("%s", &s[i].dept);
		printf("COURSE : ");
		scanf("%s", &s[i].course);
		printf("YEAR OF JOINING : ");
		scanf("%d", &s[i].yoj);
		HOR;

		i++;
		printf("Enter 1 more record(y/n) : ");
		scanf(" %c", &again);
		clrscr();
	}while(again == 'Y' || again == 'y');
	menu();
}

void print(int q){
	int px = 14, py = 1;
	int *srch, loc = 0, j = 0, tmp, value;
	char s_name[10], s_dept[10], s_course[10];
	int s_roll, s_yoj;
	clrscr();
	if(q!=0){
		srch = (int *) malloc((i-1) * sizeof(char));
		switch(q){
			case 1 :
				printf("SEARCH by which NAME : ");
				scanf("%s", s_name);
				while(j<i){
					if(strcmp(s_name, s[j].name) == 0){
						*(srch+loc) = j;
						loc++;
					}
					j++;
				}
				break;
			case 2 :
				printf("SEARCH by which ROLL : ");
				scanf("%d", &s_roll);
				while(j<i){
					if(s_roll == s[j].roll){
						*(srch + loc) == j;
						loc++;
					}
					j++;
				}
				break;
			case 3 :
				printf("SEARCH by which DEPT. :");
				scanf("%s", s_dept);
				while(j<i){
					if(strcmp(s_dept, s[j].dept) == 0){
						*(srch+loc) = j;
						loc++;
					}
					j++;
				}
				break;
			case 4 :
				printf("SEARCH by which COURSE : ");
				scanf("%s", s_course);
				while(j<i){
					if(strcmp(s_course, s[j].course) == 0){
						*(srch+loc) = j;
						loc++;
					}
					j++;
				}
				break;
			case 5 :
				printf("SEARCH by which Y-O-J : ");
				scanf("%d", &s_yoj);
				while(j<i){
					if(s_yoj == s[j].yoj){
						*(srch + loc) == j;
						loc++;
					}
					j++;
				}
				break;
			default :
				//wrong query
				break;
		}
	}

	VER;
	printf("  S. NO.");
	gotoxy(px, py);
	px += 14;
	VER;
	printf("  NAME");
	gotoxy(px, py);
	px += 14;
	VER;
	printf(" ROLL NO.");
	gotoxy(px, py);
	VER;
	printf(" DEPARTMENT");
	px += 14;
	gotoxy(px, py);
	VER;
	printf("  COURSE");
	px += 14;
	gotoxy(px, py);
	VER;
	printf("  Y-O-J");
	px = 80;
	gotoxy(px, py);
	VER;
	HOR;
	py++;

	if(q==0){
		j = 0;
		while(j<i){
			px = 0;
			py++;
			VER;
			printf("  %d", j+1);
			px += 14;
			gotoxy(px, py);
			VER;
			printf("%s", s[j].name);
			px += 14;
			gotoxy(px, py);
			VER;
			printf("%d", s[j].roll);
			px += 14;
			gotoxy(px, py);
			VER;
			printf("%s", s[j].dept);
			px += 14;
			gotoxy(px, py);
			VER;
			printf("%s", s[j].course);
			px += 14;
			gotoxy(px, py);
			VER;
			printf("%d", s[j].yoj);
			px = 80;
			gotoxy(px, py);
			VER;
			j++;
		}
	}else{
		if(loc==0){
			clrscr();
			printf("Sorry but, the data that you searched didn't exist.");
			delay(1000);
		}else{
			tmp = 0;
			while(tmp<loc){
				value = *(srch + tmp);

				px = 0;
				py++;
				VER;
				printf("  %d", tmp+1);
				px += 14;
				gotoxy(px, py);
				VER;
				printf("%s", s[value].name);
				px += 14;
				gotoxy(px, py);
				VER;
				printf("%d", s[value].roll);
				px += 14;
				gotoxy(px, py);
				VER;
				printf("%s", s[value].dept);
				px += 14;
				gotoxy(px, py);
				VER;
				printf("%s", s[value].course);
				px += 14;
				gotoxy(px, py);
				VER;
				printf("%d", s[value].yoj);
				px = 80;
				gotoxy(px, py);
				VER;
				tmp++;
			}
		}
	}
	free(srch);
	puts("\n\nPRESS ANY KEY TO GO TO MENU");
	getch();
	menu();
}

void query(){
	char again;
	int op;
	if(i){
	do{
		printf("Query on : \n\n");
		puts(" 1. Name");
		puts(" 2. Roll No.");
		puts(" 3. Department");
		puts(" 4. Course");
		puts(" 5. Year of Joining\n");
		HOR;
		printf("\nEnter choice(1/2/3/4/5) : ");
		scanf("%d", &op);
		print(op);
	}while(0);
	}else{
		puts("Sorry, You have nothing to search right now.");
		delay(1000);
		menu();
	}

}