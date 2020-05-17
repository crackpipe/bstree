#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bstree.h"

struct bst_node *bst_create(int d)
{
	struct bst_node *n = malloc(sizeof(struct bst_node));

	n->data = d;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void bst_free(struct bst_node *n)
{
	memset(n, 0, sizeof(n));
	free(n);
}

struct bst_node *bst_insert(struct bst_node *n, int d)
{
	if(!n || n->data == d) {
		return bst_create(d);
	} else {
		if(d > n->data)
			n->right = bst_insert(n->right, d);
		else
			n->left = bst_insert(n->left, d);
	}
}

struct bst_node *bst_delete(struct bst_node *n, int d)
{
	struct bst_node *t;

	if(!n)
		return n;

	if(d > n->data) {
		n->right = bst_delete(n->right, d);
	} else if(d < n->data) {
		n->left = bst_delete(n->left, d);
	} else {
		if(!(n->left && n->right)) {
			t = (n->left) ? n->left : n->right;
			bst_free(n);
			return t;
		}

		t = n->right;
		while(t->left)
			t = t->left;

		n->data = t->data;
		n->right = bst_delete(n->right, t->data);
	}

	return n;
}

struct bst_node *bst_search(struct bst_node *n, int d)
{
	if(!n) return NULL;

	if(n->data == d) return n;

	bst_search(n->left, d);
	bst_search(n->right, d);
}

void _treesort_i(struct bst_node *n)
{
	if(n) {
		_treesort_i(n->left);
		printf("%d ", n->data);
		_treesort_i(n->right);
	}
}

void _treesort_d(struct bst_node *n)
{
	if(n) {
		_treesort_d(n->right);
		printf("%d ", n->data);
		_treesort_d(n->left);
	}
}

void treesort_i(int *l, int len)
{
	struct bst_node *n;

	if(l[0]) {
		n = bst_create(l[0]);

		for(int i = 1; i < len; i++) {
			n = bst_insert(n, l[i]);
		}

		_treesort_i(n);
	}
}

void treesort_d(int *l, int len)
{
	struct bst_node *n;

	if(l[0]) {
		n = bst_create(l[0]);

		for(int i = 1; i < len; i++) {
			n = bst_insert(n, l[i]);
		}

		_treesort_d(n);
	}
}
