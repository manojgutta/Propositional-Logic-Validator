#include <iostream>
#include <string>
using namespace std;
/// This is the Node class that creates a double linked list
class Node
{ // declaring the Tree Node
public:
    char data;
    Node *left, *right;
};
/// This is the function to form the complete binary parse tree from the prefix expression
///@param ptr represents the address of the node object copied from the main method
///@param a represents the address of the array input from the main method.
char *formTree(Node *&ptr, char *a)
{

    if (*a == '\0')
        return NULL;

    while (true)
    {
        char *val = NULL;
        if (ptr == NULL)
        {

            Node *nextNode = new Node();
            nextNode->data = *a;
            nextNode->left = NULL;
            nextNode->right = NULL;
            ptr = nextNode;
        }
        else
        {

            if (*a >= 'a' && *a <= 'z')
            { // if the character is an operand
                return a;
            }
            if (ptr->data == '~')
            {
                val = formTree((ptr)->right, a + 1);
                return val;
            }
            else
            {
                val = formTree((ptr)->left, a + 1); // developing the left subTree

                val = formTree((ptr)->right, val + 1); // developing the right subTree

                return val;
            }
        }
    }
}

// int main()
// {
//     Node* tree = NULL;
//     char a[] = "*+ab+cd";
//     formTree(tree, a);
//    // cout<<"The Infix expression is: "<<endl;
//     //inr(tree);
//     return 0;
// }
