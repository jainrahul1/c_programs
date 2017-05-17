#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *left;
	int data;
	struct Node *right;
};

struct Node *create_node (int d) {
	struct Node *node = malloc (sizeof(struct Node));
	node->left = NULL;
	node->data = d;
	node->right = NULL;
	return node;
}

void inorder (struct Node *root) {
	if (root != NULL) {
		inorder (root->left);
		printf("%d ", root->data);
		inorder (root->right);
	}
}

void preorder (struct Node *root) {
	if (root != NULL) {
		printf ("%d ", root->data);
		preorder (root->left);
		preorder (root->right);
	}
}

void postorder (struct Node *root) {
	if (root != NULL) {
		postorder (root->left);
		postorder (root->right);
		printf ("%d ", root->data);
	}
}

struct Node *insert (struct Node *root, int d) {
		if (root == NULL) {
			// first node
			return create_node (d);
		} else {
			if (root->data > d) {
				root->left = insert (root->left, d);
			} else {
				root->right = insert (root->right, d);
			}
		}
		return root;
}

int search_key (struct Node *root, int key) {
	if (root != NULL) {
		if (root->data == key) {
			return 1;
		} else if (root->data > key) {
			return search_key (root->left, key);
		} else if ( root->data < key) {
			return search_key (root->right, key);
		}
	}
	return 0;
}

struct Node *min_value_node (struct Node *root) {
	// left most node should be a min value node 
	struct Node *temp = root;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

struct Node *delete_key ( struct Node *root, int key) {
	if (root == NULL)
		return root;

	if (key < root->data) {
		root->left = delete_key (root->left, key);
	} else if (key > root->data) {
		root->right = delete_key (root->right, key);
	} else {
		// key is equal to root
		if (root->left == NULL) {
			struct Node *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			struct Node *temp = root->left;
			free(root);
			return temp;
		}
		// node with 2 childer get the inorder successor, (smallest on the right sub tree)
		struct Node *temp = min_value_node (root->right);
		root->data = temp->data;
		root->right = delete_key (root->right, temp->data);
	}
	return root;
}

int main() {
	struct Node *root_node = NULL;
	root_node = insert (root_node, 10);
	insert (root_node, 5);
	insert (root_node, 6);
	insert (root_node, 3);
	insert (root_node, 12);
	insert (root_node, 13);
	insert (root_node, 11);

	printf ("inorder traversal\n");
	inorder (root_node);
	printf ("\npre traversal\n");
	preorder (root_node);
	printf ("\npost traversal\n");
	postorder (root_node);

	if (search_key (root_node, 20)) {
		printf("key is found\n");
	} else {
		printf("key is not present\n");
	}

	delete_key (root_node, 100);
	printf ("inorder traversal\n");
	inorder (root_node);

	return 0;
}
