/*Double Ended Queue is also a Queue data structure in which the insertion and deletion operations are performed at both the ends (front and rear). 
That means, we can insert at both front and rear positions and can delete from both front and rear positions.
*/
/*Double Ended Queue can be represented in TWO ways, those are as follows... 
        In input restricted double-ended queue, the insertion operation is performed at only front end and deletion operation is performed at both the ends.
        In output restricted double ended queue, the deletion operation is performed at only rear end and insertion operation is performed at both the ends.
*/
#include <bits/stdc++.h>
using namespace std;

int *DEqueue;
int front = -1, rear = -1;
int capacity;

bool isFull()
{
    return (rear == capacity - 1);
}
bool isEmpty()
{
    return (rear == -1);
}

void enqueueFront(int x)
{
    if (isFull())
        cout << "\nQueue is FULL ";
    if (front >= 0)
    {
        DEqueue[--front] = x;
    }
    else
    {
        cout << "Cant Insert at front";
    }
}

void enqueueRear(int x)
{
    if (isFull())
        cout << "\nQueue is FULL ";
    if (front == -1)
    {
        front = 0;
    }
    DEqueue[++rear] = x;
}
void dequeueFront()
{
    if (isEmpty())
    {
        cout << "\nQueue is EMPTY!!!";
        return;
    }
    cout << "Deleted : " << DEqueue[front++];
}
void dequeueRear()
{
    if (isEmpty())
    {
        cout << "\nQueue is EMPTY!!!";
        return;
    }
    cout << "Deleted : " << DEqueue[rear--];
}

void display()
{
    if (isEmpty())
    {
        cout << "Dequeue is EMPTY";
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << DEqueue[i] << "\t";
    }
    cout << "\nFront : " << front << "\tRear : " << rear << "\tCapacity : " << capacity;
}

int main()
{
    int ch, x;
    cout << "Enter capacity of Queue : ";
    cin >> capacity;
    DEqueue = new int[capacity];
    front = -1;
    rear = -1;

    do
    {
        cout << "\n1. Enqueue at Front";
        cout << "\n2. Enqueue at Rear";
        cout << "\n3. Dequeue at Front";
        cout << "\n4. Dequeue at Rear";
        cout << "\n5. Display Elements";
        cout << "\nEnter your choice : ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Insert : ";
            cin >> x;
            enqueueFront(x);
        }
        else if (ch == 2)
        {
            cout << "Insert : ";
            cin >> x;
            enqueueRear(x);
        }
        else if (ch == 3)
        {
            dequeueFront();
        }
        else if (ch == 4)
        {
            dequeueRear();
        }
        else if (ch == 5)
        {
            display();
        }

    } while (ch != 0);

    return 0;
}