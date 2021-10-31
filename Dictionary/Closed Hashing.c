#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
#define EMPTY -1
#define DELETED -2

typedef struct{
	char FN[24], LN[16], MI;
}nameType;

typedef struct{
	nameType name;
	char course[5];
	int yearLevel;
	unsigned long idNumber;
}studType;

typedef studType Dictionary[SIZE];

typedef enum{TRUE,FALSE}Boolean;

void initDictionary(Dictionary D);
void insert(Dictionary D, studType P);
void display(Dictionary D);
void deleteDictionary(Dictionary D, studType P);

int main()
{
	Dictionary A;
	initDictionary(A);
	A[1].idNumber = A[0].idNumber;
	
	studType P[] = {
					{{"Robert", "Lim", 'L'}, "BSCS", 2, 5},
					{{"Robert", "Lim", 'L'}, "BSCS", 2, 26},
					{{"Robert", "Lim", 'L'}, "BSCS", 2, 32},
					{{"Robert", "Lim", 'L'}, "BSCS", 2, 35},
					{{"Robert", "Lim", 'L'}, "BSCS", 2, 45},
					{{"Robert", "Lim", 'L'}, "BSCS", 2, 54},
					{{"Robert", "Lim", 'L'}, "BSCS", 2, 63},
					
				
				};
	int i=0;
//	for(i=0;i<SIZE;i++){
//	
	insert(A, P[1]);
	insert(A, P[0]);
	insert(A, P[2]);
	insert(A, P[3]);

	
	deleteDictionary(A, P[1]);

	display(A);
	
	return 0;
}

void initDictionary(Dictionary D)
{
	int i;
	for(i=0;i<SIZE;i++){
		
		D[i].yearLevel = EMPTY;
	}
}

int hash(unsigned long x)
{
	int sum;
	while (x!=0){
		sum +=(x%10);
		x/=10;
 }
	return sum % SIZE;
}

Boolean isMember(Dictionary D, studType P)
{
	int x, hv = hash(P.idNumber);

	Boolean retval = FALSE;
	
	if(D[hv].idNumber == P.idNumber){
		retval = TRUE;
	}else{
		x = (hv+1)%SIZE;
			printf("here: %d %d\n", x, hv);
		while(x!=hv && D[x].idNumber!= P.idNumber){
			x = (x+1)%SIZE;
		}
		retval = (D[hv].idNumber == P.idNumber)?TRUE:FALSE;
	}
	printf("\n%d %d\n", D[x].idNumber, D[hv].idNumber);
	
	
	return retval;
}

void insert(Dictionary D, studType P)
{
	int hv, x, ctr = 0;
	
	hv = hash(P.idNumber);
	
	if(isMember(D,P)==FALSE){
		if(D[hv].yearLevel == EMPTY || D[hv].yearLevel == DELETED){
			D[hv] = P;
		}else{
			x = (hv+1)%SIZE;
			while(x!=hv && D[x].yearLevel!=EMPTY && D[x].yearLevel!=DELETED){
				x = (x+1)%SIZE;
			}
			D[x] = P;
		}
	}else{
		printf("Already in the dictionary\n");
	}
}	

void deleteDictionary(Dictionary D, studType P)
{
	int hv, x, ctr = 0;
	hv = hash(P.idNumber);
	printf("\n\n%d\n", D[hv].idNumber);
	if(D[hv].idNumber == P.idNumber){
		D[hv].yearLevel = DELETED;
	}else{
		x = (hv+1)%SIZE;
		while(x != hv && D[x].yearLevel != EMPTY && D[x].idNumber!=P.idNumber){
			x = (x+1)%SIZE;
		}
		if(D[x].idNumber == P.idNumber){
			D[x].yearLevel = DELETED;
		}
	}
}

void display(Dictionary D)
{
	int i;
	for(i=0;i<SIZE;i++){
		printf("Index [%d]: ", i);
		if(D[i].yearLevel==DELETED){
			printf("Deleted node!");
		}else{
			printf("%d", D[i].idNumber);
			
		}
		printf("\n");
	}
}
