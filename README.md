# Binary Search Tree - AVL Property

This is an exercise related to AVL trees. Implement the following member
functions for the *BSTree* class:

## *height*

The given code includes a function
*height* that takes a pointer to a node and is to determine the height of
that node. If that pointer is null, the height returned is -1.
If the node has no children, its height is 0. Otherwise, the height is the
greater of the height of the left child and right child.

## *preorder_height*

Two *preorder_height* functions are to be implemented. The public member
function takes no parameters and performs a pre-order traversal of the tree
producing output for each node. The output for each node is to include:

- the data value at the node
- the height of the node
- the height of the left sub-tree
- the height of the right sub-tree
- "avl" or "non-avl" to indicate if the AVL property holds for the node

The private member function takes a pointer to a node and carries
out the traversal in a recursive manner.