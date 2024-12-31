#include <stdlib.h>
#include "binary_tree.h"
#include "binary_type.h"

BinTree BintreeCreate(void)
{
  BinTree tree = (BinTree) malloc(sizeof(BINARYTREE));
  if (tree == NULL) return NULL;
  
  tree->type   = TREE_TYPE_ROOT;
  tree->parent = NULL;
  tree->node_r = NULL;
  tree->node_l = NULL;
  
  return tree;
}

void BintreeDelete(BinTree tree)
{
  for (int nest_deep = 0; ){}
  return;
}