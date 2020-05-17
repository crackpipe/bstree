#ifndef BSTREE_H
#define BSTREE_H

struct bst_node
{
	int data;
	struct bst_node *left;
	struct bst_node *right;
};

struct bst_node *bst_create(int);

void bst_free(struct bst_node*);

struct bst_node *bst_insert(struct bst_node*, int);

struct bst_node *bst_delete(struct bst_node*, int);

struct bst_node *bst_search(struct bst_node*, int);

void treesort_i(int*, int);

void treesort_d(int*, int);

#endif
