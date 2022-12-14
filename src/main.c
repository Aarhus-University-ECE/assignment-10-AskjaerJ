#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "btree.h"

// File for sandboxing and trying out code
int main(int argc, char **argv) {
  node* ns = make_node(1, make_node(2, make_node(3, make_node(4, make_node(5, NULL)))));
  print_list(ns);

  struct tree_node* root = NULL;

	root = Initialize(root);
	root = Insert(20, root);
	root = Insert(5, root);
	root = Insert(1, root);
	root = Insert(15, root);
	root = Insert(9, root);
	root = Insert(7, root);
	root = Insert(12, root);
	root = Insert(30, root);
	root = Insert(25, root);
	root = Insert(40, root);
	root = Insert(45, root);
	root = Insert(42, root);

  printf("%d",Contains(20, root));
  return 0;
}