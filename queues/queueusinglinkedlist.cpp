#include <bits/stdc++.h>
using namespace std;

struct Queuenode
{
    int value;
    Queuenode *next;
};

Queuenode *front, *rear;

void enqueue(int x)
{
    Queuenode *newNode = new Queuenode;
    newNode->value = x;
    newNode->next = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    if (front == NULL)
        cout << "\nQUEUE is Empty!!! Deletion is not possible";
    else
    {
        Queuenode *temp = front;
        front = front->next;
        cout << "\nDeleting : " << temp->value;
        delete temp;
    }
}

void display()
{
    if (front == NULL)
        cout << "\nQUEUE is Empty!!!";
    else
    {
        Queuenode *temp = front;
        while (temp != NULL)
        {
            cout << temp->value << "\t";
            temp = temp->next;
        }
    }
}

int main()
{

    int ch, x;

    do
    {
        cout << "\n1. Enqueue ";
        cout << "\n2. Dequeue";
        cout << "\n3. Display Elements";
        cout << "\n4. Show Front Element ";
        cout << "\n5. Show Rear Element";
        cout << "\nEnter your choice : ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Insert : ";
            cin >> x;
            enqueue(x);
        }
        else if (ch == 2)
        {
            dequeue();
        }
        else if (ch == 3)
        {
            display();
        }
        else if (ch == 4)
        {
            cout << front->value;
        }
        else if (ch == 5)
        {
            cout << rear->value;
        }

    } while (ch != 0);

    return 0;
}