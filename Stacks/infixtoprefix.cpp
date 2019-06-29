#include <bits/stdc++.h>
#include <algorithm>
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
    if (c == ')')
        priority = 0;
    if (c == '+' || c == '-')
        priority = 1;
    if (c == '/' || c == '*')
        priority = 2;
    if (c == '^')
        priority = 3;
    return priority;
}

string infixtoprefix(string exp)
{
    reverse(exp.begin(), exp.end());
    char x;
    string prefix;
    for (int i = 0; i < exp.length(); i++)
    {
        if (isalnum(exp[i]))
        {
            prefix += exp[i];
        }
        else if (exp[i] == ')')
        {
            push(exp[i]);
        }
        else if (exp[i] == '(')
        {
            while (top != -1 && stck[top] != ')')
            {
                prefix += pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && getpriority(stck[top]) >= getpriority(exp[i]))
            {
                prefix += pop();
            }
            push(exp[i]);
        }
    }

    while (top != -1)
    {
        prefix += pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string exp;
    cout << "Enter the Expression : ";
    cin >> exp;

    cout << infixtoprefix(exp);
    return 0;
}