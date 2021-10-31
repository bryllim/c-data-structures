#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#define EMPTY '!'
#define DELETED '~'
#define OCCUPIED '@'

typedef struct{
	char FN[24], LN[16], MI;
}nameType;

typedef struct{
	nameType name;
	char course[5];
	int yearLevel;
	unsigned long idNumber;
}studType;

typedef struct{
	studType Student;
	char checker; /*check if deleted or empty*/
	int next;
}cellType;

typedef struct{
	cellType cells[SIZE];
	int avail;
}Dictionary;

typedef enum{TRUE,FALSE}Boolean;

void initDictionary(Dictionary *D);
void displayDictionary(Dictionary D);
void insertDictionary(Dictionary *D, studType S);
int hash(unsigned long x);
void deleteDictionary(Dictionary *D, studType S);

int main()
{
	Dictionary D;
	initDictionary(&D);
	D.cells[3].Student.idNumber = 0;
	
	D.avail = 10;
	
	studType P[] = {
				{{"Robert", "Lim", 'L'}, "BSCS", 2, 12345},
				{{"Robert", "Lim", 'L'}, "BSCS", 2, 5},
				{{"Robert", "Lim", 'L'}, "BSCS", 2, 32},
				{{"Robert", "Lim", 'L'}, "BSCS", 2, 23},
				{{"Robert", "Lim", 'L'}, "BSCS", 2, 45},
				{{"Robert", "Lim", 'L'}, "BSCS", 2, 54},
				{{"Robert", "Lim", 'L'}, "BSCS", 2, 63},
					
				
				};
	
	insertDictionary(&D, P[0]);
	insertDictionary(&D, P[1]);
	insertDictionary(&D, P[2]);
	insertDictionary(&D, P[3]);
	deleteDictionary(&D, P[0]);
	deleteDictionary(&D, P[1]);

	displayDictionary(D);
	printf("\nAVAIL %d", D.avail);
	return 0;	
}

void initDictionary(Dictionary *D)
{
	int i;
	
	for(i=0;i<SIZE;i++){
		if(i<SIZE/2){
			D->cells[i].checker = EMPTY;
			D->cells[i].next = -1;
		}else{
			D->cells[i].next = i+1;
		}
	}
	D->cells[i].next = -1;
	D->avail = SIZE/2;
}

void displayDictionary(Dictionary D)
{
	int i, temp;
	
	for(i=0;i<SIZE;i++){
		if(D.cells[i].checker != OCCUPIED){
			printf((D.cells[i].checker == DELETED)?"DELETED ":"OCCUPIED ");
		}else{
			printf("OCCUPIED ");
		}
		printf("Index[%d]: %d Next: %d\n", i, D.cells[i].Student.idNumber, D.cells[i].next);
	}

}

int hash(unsigned long x)
{
	int sum = 0;
	while (x!=0){
		sum +=(x%10);
		x/=10;
 }
	return sum % (SIZE/2);
}

Boolean isMember(Dictionary D, studType S)
{
	int temp = hash(S.idNumber);
	Boolean retval = FALSE;
	
	printf("%d %d\n", D.cells[temp].Student.idNumber, S.idNumber);
	
	if(D.cells[temp].checker != EMPTY){
		while(temp!=-1 && D.cells[temp].Student.idNumber != S.idNumber){
			temp = D.cells[temp].next;
		}
		if(temp!=-1){
			retval = TRUE;
		}
	}
	
	return retval;
}

void insertDictionary(Dictionary *D, studType S)
{
	int temp, hv;
	hv = hash(S.idNumber);

	
	if(isMember((*D), S)==FALSE){
		if(D->cells[hv].checker != OCCUPIED){
			D->cells[hv].Student = S;
			D->cells[hv].checker = OCCUPIED;
		}else{
			temp = D->avail;
			
			D->avail = D->cells[temp].next;
			
			D->cells[temp].Student = S;
			D->cells[temp].checker = OCCUPIED;
			
			D->cells[temp].next = D->cells[hv].next;
			D->cells[hv].next = temp;
		}
	}else{
		printf("\nAlready a member in the dictionary\n");
	}
}

void deleteDictionary(Dictionary *D, studType S)
{
	int *trav, temp, hv;
	hv = hash(S.idNumber);
	
	if(isMember((*D), S) == TRUE){
		if(D->cells[hv].Student.idNumber == S.idNumber){
			D->cells[hv].checker = DELETED;
		}else{
			trav = &hv;
			while((*trav)!=-1 && D->cells[(*trav)].Student.idNumber!=S.idNumber){
				trav = &D->cells[(*trav)].next;
			}
			temp = (*trav);
			
			D->cells[temp].checker =DELETED;
			(*trav) = D->cells[temp].next;
			D->cells[temp].next = D->avail;
			D->avail = temp;
		}
	}
}

