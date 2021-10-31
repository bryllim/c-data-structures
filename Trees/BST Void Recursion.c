#include <stdio.h>
#include <stdlib.h>

typedef enum{TRUE, FALSE}Boolean;

typedef struct node{
	int elem;
	struct node *left, *right;
}*BST, BSTType;

Boolean isMember(BST B, int x);
void insert(BST *B, int x);
void deleteBST(BST *B, int x);
BST findMin(BST B);
void Inorder(BST B);

int main()
{
	BST B;
	B=NULL;

	insert(&B, 50);
   	insert(&B, 30);
    insert(&B, 20);
    insert(&B, 40);
    insert(&B, 70);
    insert(&B, 60);
	insert(&B, 80);
	

	deleteBST(&B, 50);
	printf("%d\n", B->elem);
	
	if(isMember(B,0)==TRUE){
		printf("MEMBER\n");
	}else{
		printf("NOT A MEMBER\n");
	}
	printf("%d\n\n", B->elem);
	Inorder(B);
	return 0;
}

void insert(BST *B, int x)
{
	if((*B)==NULL){
		(*B) = (BST)malloc(sizeof(BSTType));
		(*B)->elem = x;
		(*B)->left = (*B)->right = NULL;
	}else{
		if(x < (*B)->elem){
			insert(&(*B)->left, x);
		}else if(x > (*B)->elem){
			insert(&(*B)->right, x);
		}
	}
}

void deleteBST(BST *B, int x)
{
	BST temp;
	if((*B)==NULL){
		*B = NULL;
	}else if(x < (*B)->elem){
		deleteBST(&(*B)->left, x);
	}else if(x > (*B)->elem){
		deleteBST(&(*B)->right, x);
	}else{
		if((*B)->left == NULL && (*B)->right == NULL){
			*B = NULL;
		}else if((*B)->left == NULL){
			temp = (*B);
			(*B) = (*B)->right;
			free(temp);
		}else if((*B)->right == NULL){
			temp = (*B);
			(*B) = (*B)->left;
			free(temp);
		}else{
			temp = findMin((*B)->right);
			(*B)->elem = temp->elem;
			deleteBST(&(*B)->right, temp->elem);
		}
	}
}

BST findMin(BST B)
{
	if(B->left==NULL){
		return B;
	}else{
		return findMin(B->left);
	}
}

Boolean isMember(BST B, int x)
{
	if(B==NULL){
		return FALSE;
	}
	if(B->elem == x){
		return TRUE;
	}
	if(x < B->elem){
		return isMember(B->left, x);
	}else{
		return isMember(B->right, x);
	}
}

void Inorder(BST B)
{
	if(B!=NULL){
		Inorder(B->left);
		printf("%d\n", B->elem);
		Inorder(B->right);
	}
}
