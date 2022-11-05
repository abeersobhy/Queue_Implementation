#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

void CreatQueue (Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}
void Append (QueueEntry e , Queue*pq)
{
	if(pq->rear == (MAXQUEUE-1))
	{
		pq->rear = 0;
	}
	else
	{
		pq->rear++; 
	}
	pq->entry[pq->rear] = e;
	pq->size ++;
}
void serve (QueueEntry* pe , Queue*pq)
{
	*pe = pq->entry[pq->front];
	if(pq->front == (MAXQUEUE-1))
	{
		pq->front = 0;
	}
	else
	{
		pq->front++;
	}
	pq->size--;
}
int QueueEmpty (Queue* pq)
{
	if(pq->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int QueueFull (Queue* pq)
{
	if(pq->size == MAXQUEUE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int QueueSize (Queue* pq)
{
	return pq->size;
}
void ClearQueue (Queue* pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}
void TraverseQueue (Queue*pq , void(*pfun)(QueueEntry))
{
	int p = pq->front;
	for(int i = 0; i < pq->size ; i++)
	{
		(*pfun)(pq->entry[p]);
		p = (p+1) % MAXQUEUE;			
	}
}