#include <bits/stdc++.h>
using namespace std;

char stck[100];
int top = -1;

void push(char x)
{
    stck[++top] = x;
}

char pop()
{
    return stck[top--];
}

int getpriority(char c)
{
    int priority;
    if (c == '(')
        priority = 0;
    if (c == '+' || c == '-')
        priority = 1;
    else if (c == '/' || c == '*')
        priority = 2;
    else if (c == '^')
        priority = 3;
    return priority;
}

string infixtopostfix(string exp)
{
    char x;
    string postfix;
    for (int i = 0; i < exp.length(); i++)
    {
        if (isalnum(exp[i]))
        {
            postfix += exp[i];
        }
        else if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (top != -1 && stck[top] != '(')
            {
                postfix += pop();
            }
            top--;
        }
        else
        {
            while (top != -1 && getpriority(stck[top]) >= getpriority(exp[i]))
            {
                postfix += pop();
            }
            push(exp[i]);
        }
    }

    while (top != -1)
    {
        postfix += pop();
    }

    return postfix;
}

int main()
{
    string exp;
    cout << "Enter Expression : ";
    cin >> exp;
    cout << infixtopostfix(exp);
    return 0;
}