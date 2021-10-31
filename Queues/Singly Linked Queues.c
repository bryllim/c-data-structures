#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType{
	char elem;
	struct nodeType *next;
}*nodePtr;

typedef struct{
	nodePtr front, rear;
}Queue;

void initQueue(Queue *Q);
void Display(Queue Q);
void Enqueue(Queue *Q, char x);
void Dequeue(Queue *Q);
char Front(Queue Q);

int main()
{
	Queue Q;
	initQueue(&Q);
	Enqueue(&Q, 'a');
	Enqueue(&Q, 'b');
	Enqueue(&Q, 'c');
	Enqueue(&Q, 'd');

	Dequeue(&Q);
	
	Display(Q);
	
	printf("\n\n%c", Front(Q));
	return 0;
}

void initQueue(Queue *Q)
{
	Q->front = Q->rear = NULL;
}

void Display(Queue Q)
{
	if(Q.front!=NULL){
		printf("Front: %c, Rear: %c", Q.front->elem, Q.rear->elem);
	}else{
		printf("Queue is Empty");
	}
}

void Enqueue(Queue *Q, char x)
{
	nodePtr temp;
	temp = (nodePtr)malloc(sizeof(struct nodeType));
	if(temp!=NULL){
		temp->elem = x;
		if(Q->front==NULL){
			Q->front=Q->rear= temp;		
		}else{
			Q->rear->next = temp;
			Q->rear = temp;
		}
	}
	Q->rear->next = NULL;
}

void Dequeue(Queue *Q)
{
	nodePtr temp;
	if(Q->front!=NULL){
		temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
	}
}

char Front(Queue Q)
{
	return Q.front->elem;	
}
