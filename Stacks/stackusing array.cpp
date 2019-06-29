#include <iostream>
using namespace std;

int *stack;
int top = -1, capacity;

void push(int x)
{
    if (top == capacity - 1)
    {
        cout << "\nStack is Full!!! Insertion is not possible!!!";
    }
    else
    {
        stack[++top] = x;
        cout << "\nInsertion Successfull!!!";
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "\nStack is Empty!!! Deletion is not possible!!!";
    }
    else
    {
        cout << "\nElement Deleted : " << stack[top--];
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "\nStack is Empty!!";
    }
    else
    {
        cout << "\nStack elements are:\n";
        for (int i = top; i >= 0; i--)
        {
            cout << "\n"
                 << stack[i] << "\t";
        }
    }
}

void showtop()
{
    if (top == -1)
    {
        cout << "\nStack is Empty!!!";
    }
    else
    {
        cout << stack[top];
    }
}

int main()
{
    int ch, x;
    cout << "Enter capacity for Stack : ";
    cin >> capacity;
    stack = new int[capacity];
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
