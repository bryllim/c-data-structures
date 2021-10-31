#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char elem;
	struct node *prev, *next;
}*Queue, nodeType;

void initQueue(Queue *Q);
void Display(Queue Q);
void Enqueue(Queue *Q, char x);
void Dequeue(Queue *Q);
char Front(Queue Q);

int main()
{
	Queue Q;
	initQueue(&Q);
	Enqueue(&Q, 'x');
	Enqueue(&Q, 'a');
	Enqueue(&Q, 'b');
	
	Dequeue(&Q);
	
	Display(Q);
	
	printf("\n\n%c", Front(Q));
	
	return 0;
}

void initQueue(Queue *Q)
{
	(*Q) = NULL;
}

void Display(Queue Q)
{
	if(Q!=NULL){
		printf("First elem: %c, Last elem: %c", Q->elem, Q->prev->elem);
	}else{
		printf("List is Empty!");
	}
}

void Enqueue(Queue *Q, char x)
{
	Queue temp;
	if((*Q)==NULL){
		(*Q) = (Queue)malloc(sizeof(nodeType));
		(*Q)->prev = (*Q)->next = (*Q);
	}else{
		temp = (Queue)malloc(sizeof(nodeType));
		if(temp!=NULL){
			(*Q)->prev->next = temp;
			temp->prev = (*Q)->prev;
			(*Q)->prev = temp;
			temp->next = (*Q);
		}

	}
	(*Q)->prev->elem = x;
}

void Dequeue(Queue *Q)
{
	Queue temp;
	if((*Q)->next == (*Q)){
		(*Q) = NULL;
	}else{
		temp = (*Q);
		(*Q)->next->prev = (*Q)->prev;
		(*Q)->prev->next = (*Q)->next;
		(*Q) = (*Q)->next;
		free(temp);
	}
}

char Front(Queue Q)
{
	return Q->elem;
}
