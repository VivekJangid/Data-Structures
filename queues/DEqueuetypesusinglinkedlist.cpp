#include <bits/stdc++.h>
using namespace std;

struct DEqueue
{
    int data;
    DEqueue *next;
};
DEqueue *front, *rear;

void enqueueRear(int x)
{
    DEqueue *newNode = new DEqueue;
    newNode->data = x;
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

void enqueueFront(int x)
{
    DEqueue *newNode = new DEqueue;
    newNode->data = x;
    if (front == NULL)
    {
        newNode->next = NULL;
        front = newNode;
        rear = newNode;
    }
    else
    {
        newNode->next = front;
        front = newNode;
    }
}

void dequeueRear()
{
    if (rear == NULL || front == NULL)
        cout << "DEqueue is Empty!!!";
    else
    {
        DEqueue *temp = rear;
        DEqueue *temp1 = front;
        if (temp == front)
        {
            cout << "Deleting : " << temp->data;
            front = NULL;
            rear == NULL;
            cout << "Now NULL";
        }
        else
        {
            while (temp1->next != rear)
            {
                temp1 = temp1->next;
            }
        }
        rear = temp1;
        rear->next = NULL;
        delete temp, temp1;
    }
}

void dequeueFront()
{
    if (rear == NULL || front == NULL)
        cout << "DEqueue is Empty!!!";
    else
    {
        cout << "Deleting : " << front->data;
        front = front->next;
    }
}

void display()
{
    DEqueue *temp = front;
    while (temp->next != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << temp->data;
}

int main()
{
    int ch, x, capacity;
    cout << "\n******* Type of Double Ended Queue *******\n";
    cout << "\n1.Input-restricted deque";
    cout << "\n2.output-restricted deque";
    cout << "\nEnter your choice of Queue Type : ";
    cin >> ch;
    if (ch == 1)
    {
        do
        {
            cout << "\n1. Insert at front ";
            cout << "\n2. Delete from front";
            cout << "\n3. Delete from rear";
            cout << "\n4. Display";
            cout << "\nEnter your choice : ";
            cin >> ch;
            if (ch == 1)
            {
                cout << "Insert : ";
                cin >> x;
                enqueueFront(x);
            }
            if (ch == 2)
            {
                dequeueFront();
            }
            if (ch == 3)
            {
                dequeueRear();
            }
            if (ch == 4)
            {
                display();
            }
        } while (ch != 0);
    }
    if (ch == 2)
    {
        do
        {
            cout << "\n1. Insert at front ";
            cout << "\n2. Insert at rear";
            cout << "\n3. Delete from rear";
            cout << "\n4. Display";
            cout << "\nEnter your choice : ";
            cin >> ch;
            if (ch == 1)
            {
                cout << "Insert : ";
                cin >> x;
                enqueueFront(x);
            }
            if (ch == 2)
            {
                cout << "Insert : ";
                cin >> x;
                enqueueRear(x);
            }
            if (ch == 3)
            {
                dequeueRear();
            }
            if (ch == 4)
            {
                display();
            }
        } while (ch != 0);
    }
    return 0;
}