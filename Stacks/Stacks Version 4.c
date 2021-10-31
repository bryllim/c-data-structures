#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef char *ElemArray, ElemType;

typedef struct stack{
	ElemArray E;
	int top;
}*Stack;

typedef enum {TRUE,FALSE}Boolean;

void initStack(Stack *S);
void Push(Stack *S, char x);
void Pop(Stack *S);
char Top(Stack S);
Boolean isFull(Stack S);
Boolean isEmpty(Stack S);

int main()
{
	Stack S;
 	initStack(&S);
 	int i;
 	
	for(i=0;i<SIZE;i++){
		Push(&S, 'a'+1);
	}
	Pop(&S);
	for(i=0;i<SIZE;i++){
		printf("%c ", S->E[i]);
	}
	
	printf("\n%c, %d", S->E[S->top],S->top);
	
	return 0;
}

void initStack(Stack *S)
{
	*S = (Stack)malloc(sizeof(struct stack));
	(*S)->E = (ElemArray)malloc(sizeof(ElemType)*10);
	(*S)->top = SIZE;
}

void Push(Stack *S, char x)
{
	if(isFull(*S)){
		(*S)->E[--(*S)->top] = x;
	}
}

void Pop(Stack *S)
{
	if(isEmpty(*S) == FALSE){
		(*S)->top++;
	}
}

char Top(Stack S)
{
	return(isEmpty(S)==FALSE)?S->E[S->top]:'!'; /*returns a ! if Stack is Empty*/
}


Boolean isEmpty(Stack S)
{
	return (S->top == SIZE)?TRUE:FALSE;
}

Boolean isFull(Stack S)
{
	return (S->top == 0)?TRUE:FALSE;
}

