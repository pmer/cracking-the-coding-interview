#include <stdio.h>

struct Node {
	int data;
	Node *next;

	Node(int data, Node *next) : data(data), next(next) {}
};

static Node *
cons(int data, Node *next)
{
	return new Node(data, next);
}

static void
printList(Node *head)
{
	for (; head; head = head->next) {
		printf("%d ", head->data);
	}
	printf("\n");
}

static void
deleteMiddleNode(Node *head)
{
	// "middle" should point to the node before the middle, so we can skip
	// over the real middle node.
	Node *middle = head;

	// Move "head" by itself until middle is in the middle of the list.
	if (head)
		head = head->next;
	if (head)
		head = head->next;
	if (head)
		head = head->next;

	// Keep iterating middle once and head twice.
	while (head) {
		middle = middle->next;
		head = head->next;
		if (head)
			head = head->next;
	}

	// Remove the real middle node.
	if (middle->next)
		middle->next = middle->next->next;
}

int
main()
{
	Node *head =
		cons(1,
		cons(2,
		cons(3,
		cons(4,
		cons(5, NULL
		)))));
	deleteMiddleNode(head);
	printList(head);
	return 0;
}
