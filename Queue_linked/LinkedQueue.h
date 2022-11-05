#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_

#include "Queue_Config.h"

#define QueueEntry  ENTRY_TYPE /*Defined in stack_confg.h file.*/
typedef struct queueNode
{
	QueueEntry entry;
	struct queueNode *next;
}QueueNode;
 
typedef struct queue
{
	QueueNode* front;
	QueueNode* rear;
	int size;
}Queue; 

void  creatQueue    (Queue *pq);
void  append        (QueueEntry e , Queue *pq);
void  serve         (QueueEntry *pe , Queue *pq);
int   queueEmpty    (Queue* pq);
int   queueFull     (Queue* pq);
int   queueSize     (Queue* pq);
void  clearQueue    (Queue* pq);
void  TraverseQueue (Queue* pq , void(*pfunc)(QueueEntry));

#endif