#include <bits/stdc++.h>
using namespace std;

int *cqueue;
int front, rear, capacity;

void enqueue(int x)
{
    if ((rear + 1) % capacity == front)
    {
        cout << "\nQUEUE is FULL!!Insertion is not possible";
    }
    else
    {
        rear = (rear + 1) % capacity;
        cqueue[rear] = x;
        if (front == -1)
            front = rear;
    }
    // cout << "\nFront :" << front << "\t Rear :" << rear;
}

int dequeue()
{
    if (front == -1)
    {
        cout << "\nQUEUE is EMPTY!!Deletion is not possible";
        return 0;
    }
    else
    {
        int element = cqueue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        // cout << "\nFront :" << front << "\t Rear :" << rear << "\n";
        return element;
    }
}

void display()
{
    if (front == -1)
        cout << "Queue is empty";
    else
    {
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << cqueue[i] << "\t";
            }
        }
        else
        {
            for (int i = front; i < capacity; i++)
                cout << cqueue[i] << "\t";
            for (int i = 0; i <= rear; i++)
                cout << cqueue[i] << "\t";
        }
    }
}

int main()
{
    int ch, x;
    cout << "Enter capacity of Circular Queue : ";
    cin >> capacity;
    cqueue = new int[capacity];
    front = rear = -1;

    do
    {
        cout << "\n1. Enqueue ";
        cout << "\n2. Dequeue";
        cout << "\n3. Display Elements";
        cout << "\nEnter your choice : ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "\nInsert : ";
            cin >> x;
            enqueue(x);
        }
        else if (ch == 2)
        {
            cout << dequeue();
        }
        else if (ch == 3)
        {
            display();
        }

    } while (ch != 0);

    return 0;
}