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

static Node *
partition(Node *head, int x)
{
	if (!head)
		return NULL;

	Node *prev = head;

	// For each node past the first,
	while (prev->next) {
		Node *cur = prev->next;
		Node *next = prev->next->next;

		// If the current node is below x,
		if (cur->data < x) {
			// Move it to head of list.
			prev->next = next;
			cur->next = head;
			head = cur;

			// Then, do not advance "prev".
		}
		else {
			prev = prev->next;
		}
	}

	return head;
}

int
main()
{
	Node *head =
		cons(3,
		cons(5,
		cons(8,
		cons(5,
		cons(10,
		cons(2,
		cons(1, NULL
		)))))));
	head = partition(head, 5);
	printList(head); // Prints "1 2 3 5 8 5 10"
	return 0;
}
