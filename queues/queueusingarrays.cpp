#include <iostream>
using namespace std;

int *queue;
int front, rear, capacity;

void enqueue(int x)
{
    if (rear == capacity - 1)
    {
        cout << "\nQUEUE is FULL!!Insertion is not possible";
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        queue[rear++] = x;
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "\nQueue is EMPTY";
    }
    else
    {
        cout << "\n Deleted : "
             << queue[front++];
        for (int i = front; i <= rear; i++)
        {
            queue[i - front] = queue[i];
        }
        rear = rear - front;
        front = 0;
    }
}

void display()
{
    for (int i = front; i < rear; i++)
    {
        cout << queue[i] << "\t";
    }
}

int main()
{
    int ch, x;
    cout << "Enter capacity of Queue : ";
    cin >> capacity;
    queue = new int[capacity];
    front = -1;
    rear = -1;

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