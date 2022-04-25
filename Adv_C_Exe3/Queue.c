#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

/***************** Queue ADT Implementation *****************/


int howmany(Queue q);

int average(Queue q, int amount);


void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	intNode* current = q->head;
	intNode* scouter = NULL;
	while (current) {
		scouter = current->next;
		free(current);
		current = scouter;
	}
	initQueue(q);
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* temp = (intNode*)malloc(sizeof(intNode));
	if (!temp) exit(1);
	temp->data = data;
	temp->next = NULL;
	if (q->head == NULL)
	{
		q->head = temp;
		q->tail = q->head;
		q->tail->next = NULL;

	}
	else {
		q->tail->next = temp;
		q->tail = temp;
	}
}

unsigned int dequeue(Queue* q)
{
	if (isEmptyQueue(q)) {
		printf("queue is empty cannot dequeue\n");
		exit(0);
	}
	else {
		int res = q->head->data;
		q->head = q->head->next;
		return res;
	}
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL)
		return 1;
	else return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	if (q == NULL) {
		puts("illigal queue\n");
		return;
	}
	if (isEmptyQueue(q))
		return;
	Queue* q1 = (Queue*)malloc(sizeof(q));
	if (!q1) {
		puts("allocation failed\n");
	}
	else {
		int counter = 0;
		while (isEmptyQueue(q)) {
			enqueue(q1, dequeue(q));
			counter++;
		}
		for (int i = 0; i < counter - 1; i++)
			enqueue(q, dequeue(q1));
		for (int i = 0; i < counter - 1; i++)
			enqueue(q1, dequeue(q));
		for (int i = 0; i < counter; i++)
			enqueue(q, dequeue(q1));
	}



	free(q1);

}









void cutAndReplace(Queue* q)
{
	int f_helf = 0;

	int s_helf = 0;
	int reverse_index = 0;


	Queue tmp = *q;

	Queue* tmp1 = (Queue*)malloc(1 * sizeof(Queue));
	if (tmp1 == NULL)
		exit(1);


	Queue* tmp2 = (Queue*)malloc(1 * sizeof(Queue));
	if (tmp2 == NULL)
		exit(1);


	Queue* tmp3 = (Queue*)malloc(1 * sizeof(Queue));
	if (tmp3 == NULL)
		exit(1);

	initQueue(tmp1);
	initQueue(tmp2);
	initQueue(tmp3);




	int counter = howmany(tmp);



	tmp = *q;

	if ((counter % 2) == 0)
	{
		for (int i = 0; i < (counter / 2); i++)
		{

			enqueue(tmp1, tmp.head->data);
			tmp.head = tmp.head->next;

		}



		for (int i = 0; i <= (counter / 2); i++)
		{
			tmp.head = tmp.head->next;
			if (i == (counter / 2))
			{
				enqueue(tmp2, tmp.head->data);
				tmp = *q;
				i++;
			}



		}








		destroyQueue(q);
		initQueue(q);


		for (int i = 0; i < counter / 2; i++)
		{
			enqueue(q, tmp2->head->data);
			tmp2->head = tmp2->head->next;

		}


		for (int i = 0; i < counter / 2; i++)
		{

			enqueue(q, tmp1->head->data);
			tmp1->head = tmp1->head->next;

		}



	}

	else if ((counter % 2) != 0)
	{

		f_helf = (counter / 2) + 1;
		s_helf = counter - f_helf;

		for (int i = 0; i < f_helf; i++)
		{
			enqueue(tmp1, tmp.head->data);
			tmp.head = tmp.head->next;
		}



		while (tmp.head != NULL)
		{
			if (tmp.head->next == NULL)
			{
				enqueue(tmp2, dequeue(&tmp));


			}

			else tmp.head = tmp.head->next;

		}






		enqueue(tmp3, average(*q, counter));


		destroyQueue(q);
		initQueue(q);

		enqueue(q, dequeue(tmp3));

		for (int i = 0; i < s_helf; i++)
		{
			enqueue(q, tmp2->head->data);
			tmp2->head = tmp2->head->next;
		}

		for (int i = 0; i < f_helf; i++)
		{
			enqueue(q, tmp1->head->data);
			tmp1->head = tmp1->head->next;

		}








	}


}

void sortKidsFirst(Queue* q)
{
	if (q == NULL) {
		puts("illigal queue\n");
		return;
	}
	if (isEmptyQueue(q))
		return;
	Queue* q1 = (Queue*)malloc(sizeof(*q));
	Queue* q2 = (Queue*)malloc(sizeof(*q));
	if (!q1 || !q2) {
		puts("allocation failed\n");
	}
	int counter = 0, min = INT_MAX, check;
	while (!isEmptyQueue(q)) {
		check = dequeue(q);
		counter++;
		if (check < min)
			min = check;
		enqueue(q1, check);
	}

	for (int i = 0; i < counter; i++) {
		while (!isEmptyQueue(q1)) {
			check = dequeue(q1);
			if (check <= min) {
				enqueue(q, check);
			}
			else {
				enqueue(q2, check);
			}
		}
		min = INT_MAX;
		while (!isEmptyQueue(q2)) {
			check = dequeue(q2);
			if (check < min)
				min = check;
			enqueue(q1, check);
		}
	}
}








int average(Queue q, int amount)
{
	int sum = 0;
	for (int i = 0; i < amount; i++)
	{
		sum = sum + q.head->data;
		q.head = q.head->next;
	}

	return(sum / amount);


}


int howmany(Queue q) {
	int i = 0;
	Queue q_tmp = q;

	if (q_tmp.head == NULL)
		return 0;


	else if ((q_tmp.head != NULL))
	{
		while (q_tmp.head != NULL)
		{
			q_tmp.head = q_tmp.head->next;
			i++;
		}

	}

	return i;


}




