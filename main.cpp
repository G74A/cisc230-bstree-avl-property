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
    string s;

    do {
        // Enter a string to be inserted into the tree
        cout << "Enter string: ";
        getline(cin, s);

        // If not an empty string, insert into the tree
        if (s.size()) {
            t.insert(s);
            // Show tree structure
            cout << "Pre-order traversal:\n";
            t.preorder(print_string_depth);
            // Show node heights
            cout << "Node height values:\n";
            t.preorder_height();
            // Blank line for readability
            cout << endl;
        }
    } while (s.size());
}
