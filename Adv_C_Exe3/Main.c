#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	charNode* node = (charNode*)malloc(1 * sizeof(charNode));
	if (node == NULL)
	{
		exit(1);
	}
	
	Stack* s = (Stack*)malloc(1 * sizeof(Stack));
	if (s == NULL)
	{
		exit(1);
	}

	initStack(s);
	int is_empty = isEmptyStack(s);
	printf("%d\n", is_empty);


	char data = 'a';
	char data2 = 'b';
	char data3 = 'c';
	char data4 = 'd';
	char data5 = 'e';
	char data6 = 'f';
	push(s, data);
	printf("%c\n", s->head->data);

	push(s, data2);
	printf("%c\n", s->head->data);

	push(s, data3);
	printf("%c\n", s->head->data);

	push(s, data4);
	printf("%c\n", s->head->data);

	push(s, data5);
	printf("%c\n", s->head->data);

	push(s, data6);
	printf("%c\n", s->head->data);



	//pop(s);
	//printf("%c\n", s->head->data);



	int is_stil_empty = isEmptyStack(s);
	printf("%d\n", is_stil_empty);

	char sentence[] = { "#meR#embe#siht r# practice" };
	flipBetweenHashes(sentence);





	rotateStack(s, 3);

	Stack check_rotate = *s;

	while (check_rotate.head != NULL)
	{
		printf("\n%c", check_rotate.head->data);
		check_rotate.head = check_rotate.head->next;

	}

	




	//(isPalindrome == 1 ? printf("stack is palindrome\n") : printf("stack is not palindrome\n"));
	//rotateStack(s, 3);
	//Stack check_rotate = *s;
	//while (check_rotate.head != NULL)
	//{
		//printf("\n%c", check_rotate.head->data);
		//check_rotate.head = check_rotate.head->next;

	//}
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (!q)exit(1);
	initQueue(q);
	printf("%d", isEmptyQueue(q));
	int x1 = 3, x2 = 2, x3 = 1;
	enqueue(q, x1);
	enqueue(q, x2);
	enqueue(q, x3);


	Queue q_tmp = *q;
	printf("\n");
	for (int i = 0; i < 5; i++)
	{

		printf("\n%d", q_tmp.head->data);

		q_tmp.head = q_tmp.head->next;

	}



	printf("%d", isEmptyQueue(q));
	rotateQueue(q);
	sortKidsFirst(q);
	printf("%d", dequeue(q));
	destroyQueue(q);
	printf("%d", isEmptyQueue(q));
	free(q); free(s);

}