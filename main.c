#include <stdio.h>
#include "bstree.h"

void bst_print(struct bst_node *n)
{
	if(n) {
		bst_print(n->left);
		printf("%d ", n->data);
		bst_print(n->right);
	}
}

int main()
{
	puts("Binary Search Tree\n");

	struct bst_node *root = bst_insert(root, 10);

	puts("Insert Nodes");
	root = bst_insert(root, 20);
	root = bst_insert(root, 30);
	root = bst_insert(root, 5);
	root = bst_insert(root, 6);
	root = bst_insert(root, 4);

	bst_print(root); printf("\n");

	puts("Delete Nodes");
	root = bst_delete(root, 5);
	root = bst_delete(root, 20);
	root = bst_delete(root, 4);
	
	bst_print(root); printf("\n");

	int x[] = {3, 15, 4, 25, 92};

	puts("Treesort (Ascending and Descending)");

	treesort_i(x, 5); printf("\n");
	treesort_d(x, 5); printf("\n");

	bst_free(root);
}
