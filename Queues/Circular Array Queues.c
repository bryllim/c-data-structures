#include <stdio.h>
#include <conio.h>
#define SIZE 8

typedef char ElemArray[SIZE];

typedef struct{
	ElemArray E;
	int rear, front;
}Queue;

void initQueue(Queue *Q);
void Enqueue(Queue *Q, char elem);
void Dequeue(Queue *Q);
void Display(Queue Q);

int main()
{
	Queue Q;
	initQueue(&Q);
	Enqueue(&Q, 'B');
	Enqueue(&Q, 'A');
	Enqueue(&Q, 'b');
	Enqueue(&Q, 'b');
	Enqueue(&Q, 'b');
	Enqueue(&Q, 'b');
	Enqueue(&Q, 'c');

	Dequeue(&Q);
	
	Display(Q);
	return 0;
}

void initQueue(Queue *Q)
{
	Q->front = 1;
	Q->rear = 0;
}

void Display(Queue Q)
{
	printf("Front element: %c, Rear Element: %c", Q.E[Q.front], Q.E[Q.rear]);
}

void Enqueue(Queue *Q, char elem)
{
	if(Q->front!= (Q->rear+2)%SIZE){
		Q->rear = (Q->rear+1)%SIZE;	
		Q->E[Q->rear] = elem;
	}else{
		printf("Queue is Full!\n");
	}
	
	
}

void Dequeue(Queue *Q)
{
	if((Q->rear+1)%SIZE!=Q->front){
		Q->front = (Q->front+1)%SIZE;
	}else{ 
		printf("Queue is Empty!\n");
	}
}

