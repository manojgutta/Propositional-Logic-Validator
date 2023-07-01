#include <iostream>
#include "InfixToPrefix.cpp"
#include "HeightOfTree.cpp"

/// This is a recursive function to evaluate the truth value of the logical expression.
/// @param ptr represents the address of the node object created in the main method.

int truthValue(Node *ptr)
{
    if (ptr->data == '~')
        return !(bool)truthValue(ptr->right);
    else if (ptr->data == '+')
        return (bool)truthValue(ptr->left) || (bool)truthValue(ptr->right);
    else if (ptr->data == '*')
        return (bool)truthValue(ptr->left) && (bool)truthValue(ptr->right);
    else if (ptr->data == '>')
        return !(bool)truthValue(ptr->left) || (bool)truthValue(ptr->right);

    switch (ptr->data)
    {
    case 'p':
        return 0;
    case 'q':
        return 0;
    case 'r':
        return 0;
    case 's':
        return 0;
    }
}
///@attention It is important to make sure that the input infix expression is  well-Parenthasized i.e in BACKUS-NAUR FORM (BNF).
int main()
{

    char s1[50] = "(p>q)*(((~r)+p)>(~s))"; // to collect the well formed logic expression
                                           // that is internally taken as input from the function

    char a[50]; // to collect the prefix expression of the well-formed logic formula.
    infixToPrefix(s1, a);

    Node *tree = NULL; // forming the tree with
    formTree(tree, a); // the obtained prefix expression
                       //  using task 3.

    // Assigning logic values

    cout << (bool)truthValue(tree) << endl;
}
