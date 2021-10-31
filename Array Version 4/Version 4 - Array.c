#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct{
	char FN[24], LN[16], MI;
	char course[5];
	int yearlevel, idNumber;
}*studentRecord, studRec;

typedef struct{
	studentRecord S;
	int last; /*index of the last element*/
}*LIST, lType;

void initList(LIST *L);
void populateList(LIST *L, studRec S);
void display(LIST L);
void insertSorted(LIST *L, studRec S);
void deleteAllOccurrences(LIST *L, char x[]);


int main()
{
	LIST L;
	initList(&L);
	
	studRec S[]={
					{"Robert Michael", "Lim", ' ', "BSCS", 2, 15101135},
					{"Marvin", "Lim", 'S', "BSCS", 2, 15101138},
					{"Ranz", "Sapa", 'L', "BSCS", 2, 15101139},
					{"Hazel", "Cavite", 'B', "BSCS", 2, 15101140},
				
				};

	int i;
	for(i=0;i<4;i++){
		insertSorted(&L, S[i]);
	}
	display(L);
	
	studRec shane = {"Shane Khalid", "Lim", 'L', "BSCS", 2, 15101141};
	studRec shane2 = {"Shane Khalid", "Lim", 'L', "BSCS", 2, 15101142};
	studRec shane3 = {"Shane Khalid", "Lim", 'L', "BSCS", 2, 15101144};
	studRec shane4 = {"Shane Khalid", "Lim", 'L', "BSCS", 2, 15101136};
	insertSorted(&L, shane);
	insertSorted(&L, shane2);
	insertSorted(&L, shane3);
	insertSorted(&L, shane4);
	printf("\n\n");
	display(L);
	
	deleteAllOccurrences(&L, "Lim");
	printf("\n\n");
	display(L);


	return 0;
}

void initList(LIST *L)
{
	*L = (LIST)malloc(sizeof(lType));
	(*L)->S = (studentRecord)malloc(sizeof(studRec)*(SIZE));
	(*L)->last = -1;
}

void display(LIST L)
{
	int i;
	for(i=0;i<=L->last;i++){
		printf("%s %s %c. %s %d %d\n", L->S[i].FN, L->S[i].LN, L->S[i].MI, L->S[i].course, L->S[i].yearlevel, L->S[i].idNumber);
	}
	printf("\nLast index = %d\n", L->last);
}

void populateList(LIST *L, studRec T)
{
	(*L)->last++;
	(*L)->S[(*L)->last] = T;
}

void insertSorted(LIST *L, studRec S)
{
	int i;
	if((*L)->last<SIZE-1){
		for(i=0;i<=(*L)->last && (*L)->S[i].idNumber<S.idNumber;i++){}
		if((*L)->S[i].idNumber!=S.idNumber){
			memcpy((*L)->S+i+1,(*L)->S+i, sizeof(studRec)*((*L)->last-i+1));
			(*L)->S[i]=S;
			(*L)->last++;
		}
	}
}

void deleteAllOccurrences(LIST *L, char x[])
{
	int i;
	if((*L)->last!=-1){
		for(i=0;i<=(*L)->last;){
			if((strcmp((*L)->S[i].LN, x))==0){
				memcpy((*L)->S+i,(*L)->S+i+1, sizeof(studRec)*((*L)->last-i));
				(*L)->last--;
			}else{
				i++;
			}
		}
	}
}

