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

static int
addBack(Node *left, Node *right)
{
	int sum = 0;

	// The first nodes are digits in the 1's column.
	// The second nodes are digits in the 10's column.
	// The third nodes are digits in the 100's column.
	for (int column = 1; left || right; column *= 10) {
		if (left) {
			sum += left->data * column;
			left = left->next;
		}
		if (right) {
			sum += right->data * column;
			right = right->next;
		}
	}

	return sum;
}

static int
addForw(Node *left, Node *right)
{
	int sum = 0;

	// The first nodes are digits in the 100's column.
	// The second nodes are digits in the 10's column.
	// The third nodes are digits in the 1's column.
	while (left || right) {
		sum *= 10;
		if (left) {
			sum += left->data;
			left = left->next;
		}
		if (right) {
			sum += right->data;
			right = right->next;
		}
	}

	return sum;
}

static Node *
toBackList(int n)
{
	return n ? cons(n % 10, toBackList(n / 10)) : NULL;
}

static Node *
toForwList(int n)
{
	Node *node = NULL;

	for (; n; n /= 10) {
		node = cons(n % 10, node);
	}

	return node;
}

int
main()
{
	Node *left, *right, *sum;

	left =
		cons(7,
		cons(1,
		cons(6, NULL
		)));
	right =
		cons(5,
		cons(9,
		cons(2, NULL
		)));
	sum = toBackList(addBack(left, right));
	printList(sum); // Prints "2 1 9"

	left =
		cons(6,
		cons(1,
		cons(7, NULL
		)));
	right =
		cons(2,
		cons(9,
		cons(5, NULL
		)));
	sum = toForwList(addForw(left, right));
	printList(sum); // Prints "9 1 2"

	return 0;
}
