#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
// Insert item x into the tree t
if(t != NULL){ /* Runs if there is a value. */
  if(x > t->item) {
    t->right = Insert(x, t->right); /* Recursively inserts to the right.  */
    return t;
    }
  else if(x < t->item || x == t->item) {
    t->left = Insert(x, t->left); /* Adds to the left.  */
    return t;
    }
  }
else{
  tree_node* Ins = malloc(sizeof(tree_node)); /* Allocates an node with empty right and left childs. */
  Ins->item = x;
  Ins->left = NULL;
  Ins->right = NULL;
  return Ins;
  }
}

struct tree_node *Remove(int x, struct tree_node *t) { /* Remove an item from tree */
if(t == NULL) {
  return t; /* If already empty just return t. */
  }
else if(t->item == x) {
  if(t->left == NULL) {
    t = t->right; /* If the left one is NULL i know that I can remove and set it equal to t->right. */
  } 
  else if(t->left->right != NULL){
    tree_node* temp = t->left->right; /* Configure a temp so I can free, this can also be done at the two other remove cases. But I figured one example is enough */
    while(temp->right->right != NULL){ /* Runs a loop to get to the end. */
      temp = temp->right; 
    }
    t->item = temp->right->item; /* Sets t's item equal to the right trees item, because we want to remove t and replace with right trees item.*/
    free(temp->right); /* Free the removedo n.*/
    temp->right = NULL; /* Makes sure that right is now empty. */

    }
    else if(t->left->right == NULL) {
      t->left->right = t->right; /* Puts the right tree to the new t's right*/
      t = t->left; /* Sets the left to the original t after having set tree onto its right.*/
    }
  }

else if(x > t->item) {
  t->right = Remove(x, t->right); /* Goes through the right side recursively. */
  }
else if(x < t->item) {
  t->left = Remove(x, t->left); /* Goes through the left side recursively. */
  }
return t;
}


int Contains(int x, struct tree_node *t) {
// Return true if the tree t contains item x. Return false otherwise.
if(t == NULL) {
  return 0; /* If there is no value return value false / zero. */
  }
else if(t->item == x) {
  return 1; /* True if we are at the value. */
  }
else if(x > t->item) {
  return Contains(x, t->right); /* Look for the value in the right tree. */
  }
else if(x < t->item) {
  return Contains(x, t->left); /* Same as above but in left tree. */
  }
}


struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree - Done.
  return NULL;
}

int Empty(struct tree_node *t) {
  return t == NULL; /* Its empty */
}

int Full(struct tree_node *t) {
  // Test if full - I would have to run out of memory for it to be full.
  return 0;
}
