#include <iostream>
#include <string>
using namespace std;
#include "bstree.h"

// Prints a single string, used by FSTree::inorder to print all
// values in the tree in correct order.
void print_string (string s) { cout << s << endl; }

// Prints a single string preceeded by a number of hyphens, used by
// BSTree::preorder to print a visual representation of the tree.
void print_string_depth (string s, int n) {
    for (int i = 0; i < n; i++)
        cout << '-';
    cout << s << endl;
}

int main () {
    // Create a binary search tree.
    BSTree<string> t;

    // Insert some strings for testing.
    t.insert("dog");
    t.insert("bird");
    t.insert("cat");
    t.insert("turtle");
    t.insert("giraffe");
    t.insert("snake");
    t.insert("deer");
    t.insert("groundhog");
    t.insert("horse");

    // Output the values stored in the tree.
    cout << "Values stored in the tree are:\n";
    t.inorder(print_string);
    cout << "\n";

    cout << "The structure of the tree is as follows:\n";
    t.preorder(print_string_depth);
    cout << "\n";
}
