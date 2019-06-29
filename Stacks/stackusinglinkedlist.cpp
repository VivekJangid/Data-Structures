#include <bits/stdc++.h>
using namespace std;

struct Stacknode
{
    int data;
    Stacknode *next;
};

Stacknode *top;

void push(int x)
{
    Stacknode *newnode = new Stacknode;
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    if (top == NULL)
    {
        cout << "\nUnderflow";
    }
    else
    {
        Stacknode *temp = top;
        cout << "Deleted Element : " << temp->data;
        top = top->next;
        delete temp;
    }
}

void peek()
{
    Stacknode *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}

void showtop()
{
    cout << top->data;
}

int main()
{
    int ch, x;
    do
    {
        cout << "\n1. Push Element";
        cout << "\n2. Pop Element";
        cout << "\n3. Display Elements";
        cout << "\n4. Show Top Element";
        cout << "\nENter your choice : ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "\nInsert : ";
            cin >> x;
            push(x);
        }
        else if (ch == 2)
        {
            pop();
        }
        else if (ch == 3)
        {
            peek();
        }
        else if (ch == 4)
        {
            showtop();
        }

    } while (ch != 0);
}