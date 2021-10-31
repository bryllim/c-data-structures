#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 26

typedef struct{
	char FN[24], LN[16], MI;
}nameType;

typedef struct{
	nameType N;
	unsigned long idNumber;
	char course[5];
}studRec;

typedef struct node{
	studRec S;
	struct node *next;
}nodeType, *nPtr;

typedef nPtr Dictionary[SIZE];

typedef enum{TRUE,FALSE}Boolean;

void init(Dictionary D);
void insert(Dictionary D, studRec S);
int hash(char LN[]);
void display(Dictionary D);
void deleteRec(Dictionary D, studRec S);

int main()
{
	Dictionary A;
	init(A);
	studRec P[] = {
					{{"Robert Michael","Albo",'L'}, 151011374, "BSCS"},
					{{"Samantha","A", 'L'}, 131001503, "BSCS"},
					{{"Samantha","Aa", 'L'}, 131001502, "BSCS"},
					{{"Marvin Gwapo","Lja", 'L'}, 151011381, "BSCS"}
					
				};			
	insert(A, P[0]);
	insert(A, P[1]);
	insert(A, P[2]);
	insert(A, P[3]);
	

	
	display(A);
	return 0;
}

void init(Dictionary D)
{
	int i;
	for(i=0;i<SIZE;i++){
		D[i] = NULL;
	}
}

void display(Dictionary D)
{
	int i;
	nPtr temp;
	printf("INDEX\tFIRST NAME\tLAST NAME\tMI\tCOURSE\tID NUMBER\n");
	printf("-----\t----------\t---------\t--\t------\t---------\n\n");
	for(i=0;i<SIZE;i++){
		printf("%d", i);
		temp = D[i];
		
		while(temp!=NULL){
			printf("\t%s\t%s\t\t%c\t%s\t%d", temp->S.N.FN, temp->S.N.LN, temp->S.N.MI, temp->S.course, temp->S.idNumber);
			temp = temp->next;
			if(temp == NULL){
				printf("->NULL");
			}
			printf("\n");
		}
		printf("\n");
	}
	
}

int hash(char LN[])
{
	return LN[0] - 'A'; /*0  for A, 2 for B, etc*/
}

Boolean isMember(Dictionary D, studRec S)
{
	int h;
	
	nPtr trav;
	h = hash(S.N.LN);
	
	for(trav = D[h];trav!=NULL && trav->S.idNumber != S.idNumber; trav=trav->next){}
	
	return (trav!=NULL)?TRUE:FALSE;
}

void deleteRec(Dictionary D, studRec S)
{
	nPtr *trav, temp;
	int h;
	
	h = hash(S.N.LN);
	
	if(isMember(D, S)==TRUE){
		for(trav = &D[h];*trav!=NULL && (*trav)->S.idNumber != S.idNumber ;trav = &(*trav)->next){}
		temp = (*trav);
		(*trav) = temp->next;
		free(temp);
	}else{
		printf("Element not in the set!\n");
	}
}

void insert(Dictionary D, studRec S)
{
	nPtr temp, *trav;
	int h;
	h = hash(S.N.LN);
	if(D[h] == NULL){
		D[h] = (nPtr)malloc(sizeof(nodeType));
		D[h]->S = S;
		D[h]->next = NULL;
	}else{
		if(isMember(D, S)==FALSE){
			for(trav = &D[h]; *trav!=NULL  && strcmp((*trav)->S.N.LN, S.N.LN) < 0;trav = &(*trav)->next){}
			temp = (nPtr)malloc(sizeof(nodeType));
			if(temp!=NULL){
				temp->S = S;
				temp->next = D[h];
				D[h] = temp;
			}
		}
		
	}
}
