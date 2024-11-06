#ifndef DATA_TREE_BINARY_TREE_H
#define DATA_TREE_BINARY_TREE_H

typedef struct tagBINARYTREE
{
  int type;
  struct tagBINARYTREE* parent;
  struct tagBINARYTREE* node_r;
  struct tagBINARYTREE* node_l;
} BINARYTREE;

typedef BINARYTREE* BinaryTree;
typedef BinaryTree  BinTree;

BinTree BintreeCreate(void);
void BintreeDelete(BinTree tree);

#endif