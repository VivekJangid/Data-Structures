#include <bits/stdc++.h>
using namespace std;

string stck[100];
int top = -1;

int push(string c)
{
    stck[++top] = c;
}

string pop()
{
    return stck[top--];
}

bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
        return true;
    }
    return false;
}

string postfixtoprefix(string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperator(exp[i]))
        {
            string op1 = pop();
            string op2 = pop();
            string res = exp[i] + op2 + op1;
            push(res);
        }
        else
        {
            push(string(1, exp[i]));
        }
    }
    return pop();
}

int main()
{
    string exp;
    cout << "Enter Expression : ";
    cin >> exp;
    cout << postfixtoprefix(exp);
    return 0;
}