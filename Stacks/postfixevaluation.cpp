#include <bits/stdc++.h>
using namespace std;

int stck[100];
int top = -1;

void push(int c)
{
    stck[++top] = c;
}

int pop()
{
    return stck[top--];
}

int calculate(int a, int b, char c)
{
    int res = 0;
    switch (c)
    {
    case '+':
        res = a + b;
        break;
    case '*':
        res = a * b;
        break;
    case '-':
        res = a - b;
        break;
    case '/':
        res = a / b;
        break;
    }
    return res;
}

int postfixeval(string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        char ep = exp[i];
        if (isdigit(ep))
        {
            push(ep - '0');
            cout << ep - '0' << "\n";
        }
        else
        {
            int b = pop();
            int a = pop();
            int result = calculate(a, b, ep);
            cout << a << ep << b << "\n";
            push(result);
        }
    }
    return pop();
}

int main()
{
    string exp;
    cout << "Enter Expression : ";
    cin >> exp;
    cout << postfixeval(exp);
    return 0;
}