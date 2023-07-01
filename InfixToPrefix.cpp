#include <iostream>
using namespace std; /* INFIX TO  PREFIX */
#define LIMIT 1000

/// This is the implementation of Stack class used to store elements of character type.
///
/// Here in stack class we are implementing push and pop functions and we are using
/// it in our algorithm to convert well-parenthesised infix expression to prefix expression.
class Stack
{
public:
	int tos;
	char a[LIMIT]; // Maximum size of Stack

	Stack() // constructor
	{
		tos = -1;
	}

	void push(char item) // to push elements into stack
	{
		if (tos == (LIMIT - 1))
		{
			cout << "Sorry, Stack is full ";
		}
		else
		{
			a[++tos] = item;
		}
	}

	char pop() // function to eliminate element out of stack
	{
		if (tos == -1)
		{
			cout << "Sorry, Stack is empty";
			return '$';
		}
		else
		{
			return a[tos--];
		}
	}

}; // end of Stack Implementation

char symbol, infix[100]; // Global
Stack stack;			 // Variables

/// To Check Whether The Symbol Read is Operator Or Not .
///@param smbl This describes the input operator to be checked.
int isOpr(char smbl)
{
	if (smbl == '~' || smbl == '*' || smbl == '+' || smbl == '>' || smbl == '(' || smbl == ')')
		return 1;
	else
		return 0;
}

/// This gives the priority order of the operators
///@param symbol This represents the operators in the expression.

int priority(char symbol)
{
	switch (symbol)
	{
	case '>':
		return 1;
		break;

	case '+':
		return 2;
		break;

	case '*':
		return 3;
		break;

	case '~':
		return 4;
		break;

	default:
		return -111; // returning a default value.
	}
}

/// This is the function to reverse the given array input
///@param s represents the character array
void reverse(char s[]) // to reverse a given array.
{
	for (int i = 0; i < strlen(s) / 2; i++)
	{
		swap(s[i], s[strlen(s) - 1 - i]);
	}
}

/// This function converts infix expression to prefix expression
///
/// Here, in this function, we first reverse the infix expression and apply the conversion algorithm
/// to get the prefix expression according to the precedence rules by using a user-defined stack.
/// @attention It is important to note that the input expression is well-parenthesised in Backus-Naur Form(BNF).
void infixToPrefix(char infix[100], char prefix[100])
{

	int j = 0;
	reverse(infix);
	for (int i = 0; i < strlen(infix); i++)
	{
		symbol = infix[i];
		if (isOpr(symbol) == 0)
		{
			prefix[j++] = symbol;
		}
		else
		{
			if (symbol == ')')
			{
				stack.push(symbol);
			}
			else if (symbol == '(')
			{
				while (stack.a[stack.tos] != ')')
				{
					prefix[j++] = stack.pop();
				}
				stack.pop();
			}
			else
			{
				if (priority(symbol) >= priority(stack.tos))
				{
					stack.push(symbol);
				}
				else
				{
					while (priority(symbol) <= priority(stack.tos))
					{
						prefix[j++] = stack.pop();
					}
					stack.push(symbol);
				}
			}
		}
	}
	while (stack.tos >= 0)
	{
		prefix[j++] = stack.pop();
	}
	prefix[j] = '\0';

	reverse(prefix);
	cout << "the prefix expression is : " << prefix << endl;
}

// int main()
// {
// 	char s1[100];
// 	char s2[100];
// 	cout << "Enter any well formed infix expression in BNF form " << endl;
// 	cin.getline(infix, 100); // any well formed formula in BNF form
// 							 // eg: (p>q)*(((~r)+p)>(~s))
// 	infixToPrefix(s1, s2);
// }
