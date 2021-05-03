#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>

struct employee{
	char name[10];
	char empcode[5];
	char doj[11];
}e[10];

int i=0; //very important
int *picker;//picks specific employees
int p = 0 ;

void fillstruct();
void query();
int convert(char *, int);

void main(){
	clrscr();
	fillstruct();
	query();
	getch();
}

void fillstruct(){
	char again;
	do{
		puts("EMPLOYEE's DATA RECORD\n");
		printf("Entry NO. %d\n\n", i + 1);
		printf(" NAME : ");
		scanf("%s", e[i].name);
		printf(" EMPLOYEE CODE : ");
		scanf("%s", e[i].empcode);
		printf(" DATE OF JOINING : ");
		scanf("%s", e[i].doj);
		printf("\nEnter 1 more record(Y/N) : ");
		scanf(" %c", &again);
		i++;
		clrscr();
	}while(again == 'y' || again == 'Y');
}

void query(){
	char date[11];
	int curr, cmp, j, currmonth, cmpmonth, currday, cmpday;
	printf("Enter Current date(DD/MM/YYYY) : ");
	scanf("%s", date);
	j = 0;
	curr = convert(&date[6], 4);
	while(j<i){
		cmp = convert(&(e[j].doj[6]), 4);
		if(cmp<curr-3){
			picker = (int *)realloc(picker, (p+1)*sizeof(int));
			*(picker + p) = j;
			p++;
		}else{
			if(cmp==curr-3){
				currmonth = convert(&date[3] ,2);
				cmpmonth =  convert(&(e[j].doj[3]), 2);
				if(cmpmonth > currmonth){
					picker = (int *)realloc(picker, (p+1)*sizeof(int));
					*(picker + p) = j;
					p++;
				}else{
					if(cmpmonth == currmonth){
						currday = convert(&date[0] ,2);
						cmpday =  convert(&(e[j].doj[0]), 2);
						if(cmpday>=currday){
							picker = (int *)realloc(picker, (p+1)*sizeof(int));
							*(picker + p) = j;
							p++;
						}
					}
				}
			}
		}
		j++;
	}

	j = 0;
	while(j<p){
		curr = *(picker + j);
		printf("Name : %s \t Code : %s \y DOJ : %s\n", e[curr].name, e[curr].empcode, e[curr].doj);
		j++;
	}
	free(picker);
}


int convert(char *year, int len){
	int y=0, j;
	int no, rem;

	j = 0;
	while(j<len){
		no = (int)*(year+j);
		no = no-48;
		y = (y*10) + no;
		j++;
	}

	return y;
}