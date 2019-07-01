#include <bits/stdc++.h>
using namespace std;

struct Doublylist
{
    int data;
    Doublylist *prev;
    Doublylist *next;
};

Doublylist *head;

void insertAtBeginning(int x)
{
    Doublylist *newNode = new Doublylist;
    newNode->data = x;
    newNode->prev = NULL;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtEnd(int x)
{
    Doublylist *newNode = new Doublylist;
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        Doublylist *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
}
void insertAtposition(int x, int pos)
{
    Doublylist *newNode = new Doublylist;
    newNode->data = x;
    if (head == NULL)
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        return;
    }
    else if (pos == 0)
    {
        insertAtBeginning(x);
        return;
    }
    else
    {

        Doublylist *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Linked List Don't have that much elements";
                return;
            }
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            temp->next = newNode;
            newNode->next = NULL;
            newNode->prev = temp;
            return;
        }
        else
        {
            newNode->next = temp->next;
            newNode->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            return;
        }
    }
}

void display()
{
    if (head == NULL)
        cout << "Empty Linked List";
    else
    {
        Doublylist *ptr = head;
        int i = 1;
        while (ptr->next != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
            i++;
        }
        cout << ptr->data;
        cout << "\nLinked List has " << i << " Nodes";
        cout << "\nReverse\n";
        while (ptr->prev != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->prev;
        }
        cout << ptr->data;
    }
}
void removeBeginning()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty";
        return;
    }
    else
    {
        Doublylist *temp = head;
        if (head->next == NULL)
        {
            cout << "Deleting : " << temp->data;
            head = NULL;
            delete temp;
            return;
        }
        else
        {
            cout << "Deleting :  " << temp->data;
            head = temp->next;
            head->prev = NULL;
            return;
        }
    }
}
void removeEnd()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty";
        return;
    }
    else
    {
        Doublylist *temp = head;
        if (head->next == NULL)
        {
            cout << "Deleting : " << temp->data;
            head = NULL;
            return;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            cout << "Deleting :  " << temp->data;
            temp = temp->prev;
            temp->next = NULL;
        }
    }
}
void removePosition(int pos)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty !!!";
        return;
    }
    if (pos == 0)
    {
        cout << "List is starting from 1";
        return;
    }
    else
    {
        Doublylist *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "Linked List Don't have that much elements";
                return;
            }
        }
        if (temp->next == NULL)
        {
            cout << "DELETING ::::: " << temp->data;
            removeEnd();
            return;
        }
        else
        {
            cout << "deleting :: " << temp->data;
            temp = temp->prev;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            return;
        }
    }
}

int main()
{
    int ch, x, y, pos;
    do
    {
        cout << "\n1. Insert ";
        cout << "\n2. Delete ";
        cout << "\n3. Display ";
        cout << "\nENter your choice : ";
        cin >> ch;
        if (ch == 1)
        {
            do
            {
                cout << "\n1. Insert at Beginning";
                cout << "\n2. Insert at End ";
                cout << "\n3. Insert at Position";
                cout << "\nENter your choice : ";
                cin >> y;
                if (y == 1)
                {
                    cout << "Insert Data :";
                    cin >> x;
                    insertAtBeginning(x);
                }
                if (y == 2)
                {
                    cout << "Insert Data : ";
                    cin >> x;
                    insertAtEnd(x);
                }
                if (y == 3)
                {
                    cout << "Insert Data :";
                    cin >> x;
                    cout << "Enter Index starting front 1  : ";
                    cin >> pos;
                    insertAtposition(x, pos - 1);
                }
            } while (y != 0);
        }
        else if (ch == 2)
        {
            do
            {
                cout << "\n1. Delete from Beginning";
                cout << "\n2. Delete from End ";
                cout << "\n3. Delete at Position";
                cout << "\nENter your choice : ";
                cin >> y;
                if (y == 1)
                    removeBeginning();
                if (y == 2)
                    removeEnd();
                if (y == 3)
                {
                    cout << "Enter Index to delete starting front 1  : ";
                    cin >> pos;
                    removePosition(pos);
                }
            } while (y != 0);
        }
        else if (ch == 3)
        {
            display();
        }
    } while (ch != 0);
    return 0;
}