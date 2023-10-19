#pragma once

// A Binary Search Tree implementation.
template <typename T>
class BSTree {
private:

	// A node in the tree. Each node has pointers to its left and right nodes
	// as well as its parent. When a node is created, the parent and data item
	// must be provided.
	class node {
	public:
		T data;
		node* left;
		node* right;
		node* parent;
		node (const T& d, node* p) {
			parent = p;
			data = d;
			left = right = nullptr;
		}
	};

	// Pointer to the root node. Initially this is null for an empty tree.
	node* root;

	// Copy the subtree of another BSTree object into this object. Used by
	// the copy constructor and assignment operator.
	void copy (node* p) {
		if (p) { // If p points to a node...
			insert(p->data); // Insert data item
			copy(p->left); // Copy the left subtree
			copy(p->right); // Copy the right subtree
		}
	}

	// Destroy a node and all nodes in both subtrees. Called by the
	// destructor.
	void destroy (node* p) {
		if (p) { // If p is not null...
			destroy(p->left); // Destroy the left subtree
			destroy(p->right); // Destroy the right subtree
			delete p; // Destroy the node
		}
	}

	// Helper function to determine if a data value is contained in the tree.
	// Takes the data value being searched and a pointer to the node in the
	// tree. Returns pointer to node in which data item is found, a null
	// pointer otherwise.
	node* find (const T& d, node* p) const {
		// Given: p is a pointer to an existing node
		if (d == p->data) // Is this the value we're looking for?
			return p;
		if (d < p->data) // Check left side, if null then not found
			return p->left ? find(d, p->left) : nullptr;
		return p->right ? find(d, p->right) : nullptr; // Check right side...
	}

	// Helper function to insert a data item into the tree. Takes the data
	// and a pointer to a node in the tree. Recursively decends down the tree
	// until position were insertion should take place is found.
	void insert (const T& d, node* p) {
		// Given: p is a pointer to an existing node (root of a subtree)
		if (d < p->data) { // Insert into left subtree?
			if (p->left) // Left subtree exists?
				insert(d, p->left); // Insert into left subtree...
			else // No left subtree, insert the new node
				p->left = new node(d, p);
		}
		else if (d > p->data) { // Insert into right subtree?
			if (p->right) // Right subtree exists?
				insert(d, p->right); // Insert into right subtree...
			else // No right subtree, insert the new node
				p->right = new node(d, p);
		}
		// else: node p has data value being inserted, ignore (no dups allowed)
	}

	// An inorder traversal for a subtree rooted at node p. Performs an
	// inorder traversal on the left subtree, then calls f for the data item
	// at p, then performs an inorder traversal on the right subtree.
	template <typename U>
	void inorder (node* p, U f) const {
		if (p) {
			inorder(p->left, f);
			f(p->data);
			inorder(p->right, f);
		}
	}

	// A preorder traversal for a subtree rooted at node p. Calls f for the
	// data item at p with the given depth, then performs a preorder
	// traversal on the left and right subtrees passing the depth plus 1.
	template <typename U>
	void preorder (node* p, U f, int depth) const {
		if (p) {
			f(p->data, depth);
			preorder(p->left, f, depth + 1);
			preorder(p->right, f, depth + 1);
		}
	}

public:

	// Constructor, initializes an empty tree by setting the root pointer to
	// null.
	BSTree() { root = nullptr; }

	// Copy constructor
	BSTree(const BSTree& t) { root = nullptr; copy(t.root); }

	// Assignment overload
	BSTree& operator= (const BSTree& t) {
		destroy(root); // Destroy the current tree
		root = nullptr; // Initialize root pointer
		copy(t.root); // Copy the tree
	}

	// Destructor, destroys all nodes
	~BSTree() { destroy(root); }

	// Find a data item in the tree. Return true if data value exists,
	// otherwise return false. Calls recursive find helper function.
	bool find (const T& d) const {
		return root && find(d, root);
	}

	// Insert a new data item into the tree. If the data item already exists,
	// it is ignored (no duplicates are added). Calls recursive insert helper
	// function.
	void insert (const T& d) {
		if (!root) // Is tree empty?
			root = new node(d, nullptr); // Create root node
		else if (d < root->data) { // Add new value to left side?
			if (root->left) // Is there is a left subtree?
				insert(d, root->left); // Insert into left subtree...
			else // No left subtree, create node on left side
				root->left = new node(d, root);
		}
		else if (d > root->data) { // Add new value to right side?
			if (root->right) // Is there a right subtree?
				insert(d, root->right); // Insert into right subtree...
			else // No right subtree, create node on right side
				root->right = new node(d, root);
		}
	}

	// Perform an inorder traversal using function f. Calls the recursive
	// helper function.
	template <typename U>
	void inorder (U f) const { inorder(root, f); }

	// Perform a preorder traversal using function f. Calls the recursive
	// helper function. Note that function f requires a second parameter
	// which is the depth.
	template <typename U>
	void preorder (U f) const { preorder(root, f, 0); }
};
