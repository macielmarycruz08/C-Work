#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int SIZE = 50;

class Stacktype
{
public:

    Stacktype() : top(-1) {}

    bool IsFull() const; 
    bool IsEmpty() const;
    void Push(char operation);
    char Pop();
    int Precedence(char operation);
    void DisplayExpression() const;
    char Top() const; 

private:
    char stack[SIZE];
    int top;
};

// checking if the stack is full
bool Stacktype::IsFull() const
{
    return top == SIZE - 1;
}

// checking if the stack is empty
bool Stacktype::IsEmpty() const
{
    return top == -1;
}

// Push an element onto the stack
void Stacktype::Push(char operation)
{
    if (IsFull())
    {
        cerr << "Error: Stack is full!" << endl;
        exit(1);
    }
    top++;
    stack[top] = operation;
}

// Pop an element from the stack
char Stacktype::Pop()
{
    if (IsEmpty())
    {
        cerr << "Error: Stack is empty!" << endl;
        exit(1);
    }
    char poppedElement = stack[top];
    top--;
    return poppedElement;
}

// The operators 
int Stacktype::Precedence(char operation)
{
    if (operation == '*' || operation == '/')
        return 2;
    else if (operation == '+' || operation == '-')
        return 1;
    else
        return 0; 
}

void Stacktype::DisplayExpression() const
{
    if (IsEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack contents: ";
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

char Stacktype::Top() const
{
    if (IsEmpty())
    {
        cerr << "Error: Stack is empty!" << endl;
        exit(1);
    }
    return stack[top];
}

string infixToPostfix(const string &infix)
{
    string postfix = "";
    Stacktype operators;

    for (char symbol : infix)
    {
        if (isspace(symbol))
        {
            continue; // Ignore spaces
        }
        else if (isalnum(symbol))
        { // Operand
            postfix += symbol;
        }
        else if (symbol == '(')
        {
            operators.Push(symbol);
        }
        else if (symbol == ')')
        {
            while (!operators.IsEmpty() && operators.Top() != '(')
            {
                postfix += operators.Pop();
            }
            operators.Pop(); // Discard the '('
        }
        else
        { // Operator
            while (!operators.IsEmpty() && operators.Top() != '(' && operators.Precedence(operators.Top()) >= operators.Precedence(symbol))
            {
                postfix += operators.Pop();
            }
            operators.Push(symbol);
        }
    }

    while (!operators.IsEmpty())
    {
        postfix += operators.Pop();
    }

    return postfix;
}

int main()
{
    Stacktype operators;

    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    return 0;
}
