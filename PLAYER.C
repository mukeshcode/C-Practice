#include<stdio.h>
#include<conio.h>

struct player{
	char name[20];
	int age;
	int matches;
	float score;
}p[10] = {
	{"Krishna", 32, 423, 72.03},
	{"Madhava", 28, 200, 99.12},
	{"Gopala", 23, 111, 45.32},
	{"Govinda", 28, 201, 54.54},
	{"Achyuta", 48, 182, 35.43},
	{"Keshava", 30, 400, 72.04},
	{"Madhusudan", 25, 300, 45.43},
	{"Damodaram", 47, 100, 95.43},
	{"Narayana", 48, 300, 78.32},
	{"Nimai", 12, 120, 99.32}
};

int compfunc(const void *, const void *);

void main(){
	int i =0, size;
	clrscr();
	size = 20 + (2 * sizeof(int)) + sizeof(float);
	puts("Before Sorting\n");
	while(i<10){
		printf("%s  ", p[i].name);
		printf("%d  ", p[i].age);
		printf("%d  ", p[i].matches);
			printf("%f  \n", p[i].score);
		i++;
	}

	puts("\nAfter sorting \n");
	qsort(p, 10, size, compfunc);

	i=0;
	while(i<10){
		printf("%s  ", p[i].name);
		printf("%d  ", p[i].age);
		printf("%d  ", p[i].matches);
		printf("%f  \n", p[i].score);
		i++;
	}
	getch();
}

int compfunc(const void *a, const void *b){
	return(((struct player *)a)->score - ((struct player *)b)->score);
}

