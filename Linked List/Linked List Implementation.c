#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

/*trying everything to work lmao*/

typedef struct node{
	char elem;
	struct node *next;
}ctype, *List;

void populateList(List *L);
void init(List *L);
void display(List L);
int deleteFirstOccur(List *A, char data);
int deleteAllOccur(List *L, char x);
void insertFirst(List *L, char data);
int insertPosition(List *L, int pos, char data);
void insertSorted(List *L, char x);
void delDuplicate(List L);
void insertLast(List *L, char x);

int main()
{
	List A;
	int ret;
	int pos, numbers;
	
	init(&A);
	populateList(&A);
	

	
	pos = deleteFirstOccur(&A, 'Z');
	printf("Position of first occurence = %d \n", pos);
	display(A);
	
	numbers = deleteAllOccur(&A, 'Z');
	printf("Number of all occurences = %d \n", numbers);
	display(A);

	/*insertFirst(&A, 'Z');
	display(A);*/
	
	ret = insertPosition (&A, 20, 'Z');
	
	if(ret == 1){
		printf("Valid\n");
		display(A);
	}else{
		printf("Invalid\n\n");
	}
	insertSorted(&A, 'Z');
	insertSorted(&A, 'A');
	insertSorted(&A, 'A');
	insertSorted(&A, 'B');
	insertSorted(&A, 'B');
	insertSorted(&A, 'B');
	
	display(A);
	
	delDuplicate(A);
	printf("\n");
	display(A);
	
	insertLast(&A, '!');
	printf("\n");
	display(A);
	
	return 0;
	
}

void init(List *L)
{
	*L = NULL;
}

void display(List L)
{
	for(;L!=NULL;L=L->next){
		printf("%c ", L->elem);
	}
}

void populateList(List *L)
{
	List *trav, temp;
	int i, size;
	
	size = 65;
	for(i=0;i<13;i++){
		temp = (List)malloc(sizeof(struct node));
		for(trav = L; *trav!=NULL;trav = &(*trav)->next){}
			if(temp!=NULL){
			temp->elem = i+65;
			temp->next = *trav;
			*trav = temp;
			}
	}

}


int deleteFirstOccur(List *A, char data)
{
	List temp, *trav;
	int pos=1;
	
	for(trav = A; *trav!=NULL && (*trav)->elem != data; trav = &(*trav)->next){
		pos++;
	}
	if(*trav !=NULL ){
		temp = *trav;
		*trav = (*trav)->next;
		free(temp);
	}
	return(*trav!=NULL)?pos:-1;
}

int deleteAllOccur(List *L, char x)
{
	List temp, *trav;
	int retval;
	
	retval = 0;
	
	for(trav=L;*trav!=NULL;){
		if((*trav)->elem == x){
			retval++;
			temp = *trav;
			*trav = (*trav)->next;
			free(temp);
		}else{
			trav = &(*trav)->next;
		}
	}
	return (retval>0)?retval:-1;
}

void insertFirst(List *L, char data)
{
	List *trav, temp;
	for(trav = L; *trav!=NULL && (*trav)->elem != data; trav = &(*trav)->next){}
	if(*trav==NULL){
		temp = (List)malloc(sizeof(struct node));
		if(temp!=NULL){
			temp->elem = data;
			temp->next = *L;
			*L = temp;
		}
	}
	
}

int insertPosition(List *L, int pos, char x)
{
	List *trav, temp;
	int ctr;
	
	ctr = 1;
	
	for(trav = L; *trav!=NULL && ctr<pos ;trav = &(*trav)->next){
		ctr++;
	}
	
	if(ctr == pos){
		printf("%d\n\n", ctr);
		temp = (List)malloc(sizeof(struct node));
		if(temp!=NULL){
			temp->elem = x;
			temp->next = *trav;
			*trav = temp;
		}
		ctr = 1;
	}else{
		ctr = 0;
	}
	return ctr;
}

void insertSorted(List *L, char x)
{
	List *trav, temp;
	for(trav = L; *trav!=NULL && (*trav)->elem < x; trav = &(*trav)->next){}
	temp = (List)malloc(sizeof(struct node));
	if(temp!=NULL){
		temp->elem = x;
		temp->next = *trav;
		*trav = temp;
	}
}

void delDuplicate(List L)
{
	List p, *q, temp;
	for(p = L; p!=NULL;p = p->next){
		for(q=&p->next;*q!=NULL;){
			if(p->elem == (*q)->elem){
				temp = (*q);
				(*q)=temp->next;
				free(temp);
			}else{
				q = &(*q)->next;
			}
		}
	}
}

void insertLast(List *L, char x)
{
	List *trav, temp;
	for(trav=L;*trav!=NULL;trav=&(*trav)->next){}
	temp = (List)malloc(sizeof(struct node));
	if(temp!=NULL){
		temp->elem = x;
		temp->next = *trav;
		*trav=temp;
	}
}
