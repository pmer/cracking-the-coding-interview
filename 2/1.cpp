#include <set>
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

// Time: O(N)
// Space: O(N)
static void
removeDuplicatesSet(Node *head)
{
	if (!head)
		return;

	// We've seen the first node.
	std::set<int> seen;
	seen.insert(head->data);

	// For each node, search through our set of previously-seen values.
	while (head->next) {
		// If we haven't seen this node's value before, keep it.
		if (seen.find(head->next->data) == seen.end()) {
			seen.insert(head->next->data);
			head = head->next;
		}
		// Otherwise, remove the node.
		else {
			delete head->next;
			head->next = head->next->next;
		}
	}
}

// Time: O(N^2)
// Space: O(1)
static void
removeDuplicatesScan(Node *head)
{
	// For each node, search through the remaining nodes.
	while (head) {
		for (Node *tail = head; tail->next; ) {
			// If we find a duplicate, remove it.
			if (head->data == tail->next->data) {
				delete tail->next;
				tail->next = tail->next->next;
			}
			// Otherwise, don't do anything.
			else {
				tail = tail->next;
			}
		}
		head = head->next;
	}
}

static void
printList(Node *head)
{
	for (; head; head = head->next) {
		printf("%d ", head->data);
	}
	printf("\n");
}

int
main()
{
	Node *head =
		cons(1,
		cons(2,
		cons(2,
		cons(3,
		cons(3,
		cons(2, NULL
		))))));
	printList(head);
	//removeDuplicatesSet(head);
	removeDuplicatesScan(head);
	printList(head);
	return 0;
}
