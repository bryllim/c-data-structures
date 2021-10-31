#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int elem;
	struct node *left, *right;
	int height;
}*BST, nodeType;

void insert(BST *B, int x);
void rightRotate(BST *y);
void leftRotate(BST *x);
int max(int x, int y);
int getBalance(BST B);
int height(BST B);


int main()
{
	BST B;
	B = NULL;
	
	insert(&B, 10);
	insert(&B, 20);
	insert(&B, 30);
//	insert(&B, 40);
//	insert(&B, 50);
//	insert(&B, 25);
	
//	printf("height from top: %d", B->height);
//	printf("\n%d", B->left->elem);

	return 0;
}

void rightRotate(BST *y)
{
	BST x = (*y)->left;
	BST T2 = x->right;
	
	x->right = (*y);
	(*y)->left = T2;
	
	(*y)->height = max(height((*y)->left), height((*y)->right))+1;
	x->height 	 = max(height(x->left), height(x->right))+1;
	

}

void leftRotate(BST *x)
{
	BST y = (*x)->right;
	BST T2 = y->left;
	
	y->left = (*x);
	(*x)->right = T2;
	
	(*x)->height = max(height((*x)->left), height((*x)->right))+1;
	y->height    = max(height(y->left), height(y->right))+1;
    
}

void insert(BST *B, int x)
{
	if((*B)==NULL){
		(*B) = (BST)malloc(sizeof(nodeType));
		(*B)->elem = x;
		(*B)->left = NULL;
		(*B)->right = NULL;
		(*B)->height = 1;
	} 
	if(x < (*B)->elem){
		insert(&(*B)->left, x);
	}else if(x > (*B)->elem){
		insert(&(*B)->right, x);
	}
	

	(*B)->height = 1+max(height((*B)->left), height((*B)->right));
	
	
	int balance =getBalance((*B)) ;
	printf("BALANCE: %d \n",getBalance((*B)));
	
	if(balance > 1 && x < (*B)->left->elem){
		rightRotate(B);
	}
	
	if(balance < -1 && x > (*B)->right->elem){
		leftRotate(B);
	}
	
	if(balance > 1 && x > (*B)->left->elem){
		leftRotate(&(*B)->left);
		rightRotate(B);
	}
	
	if(balance < -1 && x < (*B)->right->elem){
		rightRotate(&(*B)->right);
		leftRotate(B);
	}
	
}

int max(int x, int y)
{
	return (x > y)?x:y;
}

int height(BST B)
{
	if(B==NULL){
		return 0;
	}
	return B->height;
	
}

int getBalance(BST B)
{
	if(B==NULL){
		return 0;
	}
	return height(B->left) - height(B->right);
}
