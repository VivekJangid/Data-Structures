#include <bits/stdc++.h>
using namespace std;

struct Cqueuenode
{
    int data;
    Cqueuenode *next;
};

Cqueuenode *front, *rear;
void enqueue(int val)
{
    Cqueuenode *newNode = new Cqueuenode;
    newNode->data = val;
    if (front == NULL || rear == NULL)
    {
        newNode->next = NULL;
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        newNode->next = front;
        rear = newNode;
    }
}
void dequeue()
{
    int n = 0;
    if (front == NULL)
    {
        cout << "Queue is Empty!!Deletion is not possible";
    }

    else if (front == rear && front != NULL)
    {
        n = front->data;
        front = rear = NULL;
    }
    else
    {
        n = front->data;
        front = front->next;
        rear->next = front;
    }
    cout << n;
}
void traverse()
{
    if (front == NULL)
    {
        cout << "Queue is Empty!!Nothing to display";
    }
    else
    {
        Cqueuenode *ptr = front;
        do
        {
            cout << ptr->data << "  ";
            ptr = ptr->next;
        } while (ptr != front);
        delete ptr;
    }
}
void showfront()
{
    cout << front->data;
}
void showrear()
{
    cout << rear->data;
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
            traverse();
        }
        else if (ch == 4)
        {
            showfront();
        }
        else if (ch == 5)
        {
            showrear();
        }

    } while (ch != 0);
    return 0;
}