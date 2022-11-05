#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Queue_Config.h"
#define MAXQUEUE MAX_QUEUE_SIZE

typedef struct queue
{
	int front;
	int rear;
	int size;
	QueueEntry entry[MAXQUEUE];
}Queue;

void  CreatQueue                   (Queue *pq);
void  Append                       (QueueEntry e , Queue*pq);
void  serve                        (QueueEntry* pe , Queue*pq);
int   QueueEmpty                   (Queue* pq);
int   QueueFull                    (Queue* pq);
int   QueueSize                    (Queue* pq);
void  ClearQueue                   (Queue* pq);
void  TraverseQueue                (Queue*pq , void(*pfun)(QueueEntry)); 
#endif