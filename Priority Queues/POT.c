#include <stdio.h>
#include <stdlib.h>
#define MAX 13

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
	int elem[MAX];
	int last;
}Set;

void init(Set *A);
void insert(Set *A, int x);
void display(Set A);
void insertMin(Set *A, int x);
void heapifyMin(Set *A);
int deleteMin(Set *A);
void heapSortMax(Set *P);

int main()
{
	Set A;
	init(&A);
	//insert(&A, 9);
	int x,y,z;
	
	scanf("%d",&x);
	for(y = 0;y < x;y++){
		printf("Element no.%d: ",y+1);
		scanf("%d",&z);
		insert(&A,z);
	}
	printf("After Insertion: ");display(A);
	heapifyMin(&A);
	printf("After Min Heapification: ");display(A);
	deleteMin(&A);
	printf("After DeleteMin: ");display(A);
	heapifyMin(&A);
	printf("After Min Heapification: ");display(A);
	heapSortMax(&A);
	printf("After heapsortMax: ");display(A);
	return 0;
}

void init(Set *A)
{
	int i;
	for(i=0;i<MAX;i++){
		A->elem[i] = 0;
	}
	A->last = -1;
}

void insert(Set *A, int x)
{
	if(A->last!=MAX-1){
		A->elem[++A->last] = x;
	}
}

void insertMin(Set *P, int x)
{
	int cPos,pPos; 
	if(P->last < MAX-1){
		cPos = ++P->last;
		P->elem[cPos] = x;
		for(pPos = (cPos-1)/2;pPos >= 0 && P->elem[cPos] < P->elem[pPos];cPos = pPos, pPos = (cPos-1)/2){
			P->elem[cPos] = P->elem[pPos];
			P->elem[pPos] = x;
			
		}
	}
}

void heapifyMin(Set *A)
{
	int tree, parentPos, leftChild, rightChild, temp, top;
	for(tree = (A->last-1)/2;tree>=0;tree--){
		parentPos = tree;
		top = A->elem[parentPos];
		
		leftChild = (parentPos*2)+1;
		rightChild = leftChild +1;
		
		while(leftChild < A->last && (top > A->elem[leftChild] ||  top > A->elem[rightChild])){
			temp = (A->elem[leftChild] < A->elem[rightChild])? leftChild: rightChild;
			
			A->elem[parentPos] = A->elem[temp];
			A->elem[temp] = top;
			parentPos = temp;
			leftChild = (parentPos*2)+1;
			rightChild = leftChild +1;
		}
	}
}

int deleteMin(Set *A)
{
	int parentPos, leftChild, rightChild, temp, top, retval;
	retval = A->elem[0];
	if(A->last > 0){
		top = A->elem[0] = A->elem[A->last--];
		parentPos = 0;
		leftChild = 1;
		rightChild = 2;
		
		while(leftChild <= A->last && (top > A->elem[leftChild] || top > A->elem[rightChild])){
			temp = (A->elem[leftChild] < A->elem[rightChild])?leftChild:rightChild;
			A->elem[parentPos] = A->elem[temp];
			A->elem[temp] = top;
			parentPos = temp;
			leftChild = (parentPos*2)+1;
			rightChild = leftChild +1; 
		}
	}else if(A->last == 0){
		A->last--;
	}
	return retval;
}

void heapSortMax(Set *P)
{
	int oldLast,x;
	oldLast = P->last;
	for(x = 0;x < oldLast;x++){
		P->elem[oldLast-x] = deleteMin(P);
	}
	P->last = oldLast;
}

void display(Set A)
{
	int i;
	for(i=0;i<A.last;i++){
		printf("%d - ", A.elem[i]);
	}
	printf("%d\n", A.elem[i]);
}
