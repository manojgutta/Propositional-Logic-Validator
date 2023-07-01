#include <iostream>
#include "PrefixToTree.cpp"
/// This is the function used to print the infix expression from the parse tree generated in Task 2.
///@param ptr represents the address of the node object created in the main method.
void printInfix(Node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        printInfix(ptr->left);
        cout << ptr->data;
        printInfix(ptr->right);
    }
}

// int main()
// {
//     Node *tree = NULL;
//     char a[] = "*>pq>+~rp~s";
//     formTree(tree, a);
//     cout << "The Infix expression is: " << endl;
//     printInfix(tree);
//     return 0;
// }
