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
deleteMiddleNode(Node *head, Node *target)
{
	if (!head || !target)
		return;

	for (; head->next; head = head->next) {
		if (head->next == target) {
			head->next = head->next->next;
			return;
		}
	}
}

int
main()
{
	Node *tail =
		cons(4,
		cons(5, NULL
		));
	Node *head =
		cons(1,
		cons(2,
		cons(3, tail
		)));
	deleteMiddleNode(head, tail);
	printList(head); // Prints "1 2 3 5"
	return 0;
}
