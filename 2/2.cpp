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

static Node *
findKthToLast(Node *head, int k)
{
	Node *end = head;

	// Give "end" a k-position head start.
	while (k--) {
		end = end->next;
	}

	// Advance both until the end.
	while (end) {
		head = head->next;
		end = end->next;
	}

	// "head" holds the node that is k-th from the last in the list.
	return head;
}

int
main()
{
	Node *head =
		cons(1,
		cons(2,
		cons(3,
		cons(4,
		cons(5,
		cons(6, NULL
		))))));
	// Prints 3.
	printf("The 4th from the last is %d\n", findKthToLast(head, 4)->data);
	return 0;
}
