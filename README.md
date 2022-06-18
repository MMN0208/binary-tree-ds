# binary-tree-ds
Binary Search Tree and AVL Tree Data Structures

Binary Search Tree and AVL Tree implementation using Binary Tree interface.

The following functions are available:

template "class T, class K"
class BST/AVL

1. void insertNode(T data, K key); # Insert a node, location of the node depends on its key
2. void removeNode(T data, K key); # Remove a node
3. int callLargestKeySum(int k); # Return the data sum of k nodes with the largest keys
4. int callSmallestKeySum(int k); # Return the data sum of k nodes with the smallest keys
5. void printLNR(); # Print the tree in inorder