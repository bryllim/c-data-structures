#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define EMPTY '~'
#define EMPTYFIRST "EMPTY FIRST"
#define EMPTYLAST "EMPTY LAST"

typedef struct{
	char FN[24], LN[16], MI;
}nametype;

typedef struct{
	nametype elem;
	int next;
}nodetype;

typedef struct{
	nodetype NODES[SIZE];
	int avail;
}VirtualHeap;

typedef int List;

void display(VirtualHeap VH, List L);
void initializeVH(VirtualHeap *VH);
void insertLast(VirtualHeap *VH, int *L, char *fName, char *lName, char middleInitial);
void addNode(VirtualHeap *VH, List *L, nametype n);
void freeNode(VirtualHeap *VH, List *L);

int main()
{
	int i;
	List L;
	VirtualHeap VH;
	L=-1;
	initializeVH(&VH);
	
	insertLast(&VH, &L, "ROBERT", "LIM", 'L');
	
	

	nametype n;
	strcpy(n.FN,"Samantha");
	strcpy(n.LN,"LIM");
	n.MI = 'S';
	
	
	printf("Avail : %d head: %d\n", VH.avail, L);
	printf("\n\n");
	
	addNode(&VH, &L, n);
	addNode(&VH, &L, n);
	addNode(&VH, &L, n);
	addNode(&VH, &L, n);
	
	for(i=0;i<SIZE;i++){
		printf("%s %s %c pointer to the next node: %d\n", VH.NODES[i].elem.FN, VH.NODES[i].elem.LN, VH.NODES[i].elem.MI, VH.NODES[i].next);
	}
	
	printf("\n\n");
	display(VH, L);
	
	freeNode(&VH, &L);
	
	printf("\n\n");
	display(VH, L);
	
	
	return 0;
}

void initializeVH(VirtualHeap *VH)
{
	int x, lim=SIZE-1;
	VH->avail=0;
	for(x=0;x<lim;x++){
		VH->NODES[x].next = x+1;
	}
	VH->NODES[x].next = -1;
}

void insertLast(VirtualHeap *VH, List *L, char fName[], char lName[], char middleInitial)
{
	int temp, *p;
	if(VH->avail!=-1)
	{		
		for(p = L; *p!=-1 ;p = &VH->NODES[*p].next){}
		temp = VH->avail;
		if(temp!=-1){
			strcpy(VH->NODES[temp].elem.FN, fName);
			strcpy(VH->NODES[temp].elem.LN, lName);
			VH->NODES[temp].elem.MI = middleInitial;
			
			VH->avail = VH->NODES[VH->avail].next;
			VH->NODES[temp].next=*p;
			*p=temp;
		}
	}
}

void display(VirtualHeap VH, List L)
{
	int x = L;
	if(x==-1){
		printf("List is full\n");
	}
	for(;x!=-1;x = VH.NODES[x].next){
		printf("%s %s %c \n", VH.NODES[x].elem.FN, VH.NODES[x].elem.LN, VH.NODES[x].elem.MI);
	}
}

void addNode(VirtualHeap *VH, List *L, nametype n)
{
	List temp;
	if(VH->avail!=-1){
		VH->NODES[VH->avail].elem = n;
		
		temp = VH->avail;
		VH->avail = VH->NODES[VH->avail].next;
		VH->NODES[temp].next=*L;
		*L = temp;
	}
}

void freeNode(VirtualHeap *VH, List *L)
{
	int *trav = L, temp;
	if(*L!=-1){
		
		temp = (*trav);
		(*trav )= VH->NODES[temp].next;
		VH->NODES[temp].next = VH->avail;
		VH->avail = temp;
		
		
	}
}
