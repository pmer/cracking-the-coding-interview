#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	struct _Node *next;
	int i;
} Node;

static Node *
cons(Node *next, int i)
{
	Node *node = calloc(1, sizeof(Node *));
	node->next = next;
	node->i = i;
	return node;
}

static Node *
fibonacciList(int length)
{
	int a = 1, b = 1;
	Node *head = NULL;
	while (length--) {
		head = cons(head, a);
		int sum = a + b;
		a = b;
		b = sum;
	}
	return head;
}

static void
printList(Node *head)
{
	for (; head; head = head->next) {
		printf("%d ", head->i);
	}
	printf("\n");
}

static Node *
reverseList(Node *head)
{
	Node *prev, *cur, *next;

	if (!head)
		return NULL;

	prev = NULL;
	cur = head;
	next = cur->next;

	while (next) {
		cur->next = prev;

		prev = cur;
		cur = next;
		next = next->next;
	}

	cur->next = prev;
	head = cur;

	return head;
}

int
main()
{
	Node *head = fibonacciList(30);
	printList(head);
	head = reverseList(head);
	printList(head);
	return 0;
}
