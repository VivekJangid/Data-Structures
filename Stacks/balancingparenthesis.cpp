#include <iostream>
#include <string>
using namespace std;

char *stack;
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int main()
{
    string exp;
    stack = new char[exp.size()];
    cout << "\nEnter Expression :";
    cin >> exp;
    char w, x, y, z;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[' || exp[i] == '<')
        {
            push(exp[i]);
        }
        else
            switch (exp[i])
            {
            case ')':
                w = pop();
                if ((w == '{') || (w == '[') || (w == '<'))
                {
                    cout << "invalid Expression";
                }
                break;

            case '>':
                x = pop();
                if ((x == '{') || (x == '[') || (x == '('))
                {
                    cout << "invalid Expression";
                }
                break;

            case '}':
                y = pop();
                if ((y == '[') || (y == '(') || (y == '<'))
                {
                    cout << "invalid Expression";
                }
                break;

            case ']':
                z = pop();
                if ((z == '{') || (z == '(') || (z == '<'))
                {
                    cout << "invalid Expression";
                }
                break;
            }
    }

    if (top == -1)
    {
        cout << "\nValid Expression";
    }
    else
    {
        cout << "\nInValid Expression ";
    }

    return 0;
}