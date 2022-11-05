#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedQueue.h"

void creatQueue(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}
void append(QueueEntry e , Queue *pq)
{
	QueueNode *pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn->entry = e;
	pn->next = NULL;
	if(pq->front == NULL)
	{
		pq->front = pn;
	}
	else
	{
        pq->rear->next = pn; 		
	}
	pq->rear = pn;
	pq->size++;
}
void serve(QueueEntry *pe , Queue *pq)
{
	QueueNode* pn = pq->front;
    pq->front = pq->front->next;
	*pe = pn->entry;
	free(pn);
	if(pq->front == NULL)
	{
		pq->rear = NULL;
	}
    pq->size--;   	
}
int queueEmpty(Queue* pq)
{
	if(pq->front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int queueFull(Queue* pq)
{
	return 0;
}
int queueSize(Queue* pq)
{
	return pq->size;
}
void clearQueue(Queue* pq)
{
	while(pq->front != NULL)
	{
		pq->rear = pq->front->next;
		free(pq->front);
		pq->front = pq->rear;
	}
}
void TraverseQueue(Queue* pq , void(*pfunc)(QueueEntry))
{
	for(QueueNode*pn = pq-> front ; pn != NULL ; pn = pn->next)
	{
		(*pfunc)(pn->entry);
	}
}