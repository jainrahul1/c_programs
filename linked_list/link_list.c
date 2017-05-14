/* Linked List
 * Insertion at both ends.
 * Reversing the List using recursive and iterative methods.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *create_node (int data) {
	struct Node *node = malloc (sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void insert_at_head (struct Node **head, int data) {
	struct Node *node = create_node (data);
	if (head != NULL) {
		node->next = *head;
	}
	*head = node;
	return;
}

void insert_at_end (struct Node **head, int data) {
	struct Node *node = create_node (data);
	if (head == NULL) {
		*head = node;
	} else {
		struct Node *temp = *head;
		while (temp->next != NULL) 
			temp = temp->next;

		temp->next = node;
	}
	return;
}

void print_list (struct Node *head) {
	while (head != NULL) {
		printf ("%d\n", head->data);
		head = head->next;
	}
}

void reverse_link_list_r (struct Node **head, struct Node *node) {
	if ( *head == NULL)
		return;


	if (node->next == NULL) {
		*head = node;
		return;
	}

	reverse_link_list_r (head, node->next);
	(node->next)->next = node;
	node->next = NULL;
}

void reverse_link_list_i (struct Node **head) {
	struct Node *node = *head;
	if (node == NULL || node->next == NULL)
		return;

	struct Node *next = NULL, *prev = NULL;

	while (node->next != NULL) {
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
	node->next = prev;
	*head = node;
}

int main (void) {
	struct Node *head = NULL;
	insert_at_head (&head, 40);
	insert_at_head (&head, 30);
	insert_at_head (&head, 20);
	insert_at_head (&head, 10);

	insert_at_end (&head, 50);
	insert_at_end (&head, 60);
	insert_at_end (&head, 70);

	insert_at_head (&head, -10);
	insert_at_head (&head, -20);
	print_list (head);
	
	printf("reversing link list\n");
	reverse_link_list_r (&head, head);
	print_list (head);
	
	printf("reversing link list\n");
	reverse_link_list_i (&head);
	print_list (head);
	return 0;
}
