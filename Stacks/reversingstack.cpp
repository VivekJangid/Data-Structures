#include <bits/stdc++.h>
using namespace std;

char stck[100], top = -1;

char push(char x)
{
    stck[++top] = x;
}

char pop()
{
    return stck[top--];
}

char insertatbottom(char x)
{
    if (top == -1)
        push(x);
    else
    {
        char a = pop();
        insertatbottom(x);
        push(a);
    }
}

char reverse()
{
    while (top != -1)
    {
        char x = pop();
        reverse();
        insertatbottom(x);
    }
}

int main()
{
    push('1');
    push('2');
    push('3');
    push('4');
    string output;
    reverse();
    while (top != -1)
    {
        char p = pop();
        output += p;
    }

    cout << output;
    return 0;
}