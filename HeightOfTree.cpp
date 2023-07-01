#include <iostream>
#include "PrefixToTree.cpp"
/// This function is used to calculate the height of the parse tree.
///@param node represents the address of the node object created from the main method.

int parseHeight(Node *node) // function to calculate the maximum height of parse tree.
{
    if (node == NULL)
        return 0; // base case i.e. to search for operand as the leaf node.
    else
    {
        int l_heigth = parseHeight(node->left);
        int r_height = parseHeight(node->right);
        // recursive algorithm to calculate maximum height
        if (l_heigth > r_height)
            return (l_heigth + 1);
        else
            return (r_height + 1);
    }
}

// int main()
// {
//     Node* tree = NULL;
//     char a[100];
//     cout<<"Enter any prefix expression "<<endl;
//     cin.getline(a,100);
//     formTree(tree, a);
//     cout<<" The maximum of height of the tree is : "<<endl;
//     cout<< parseHeight(tree)<<endl;
//     return 0;
// }
