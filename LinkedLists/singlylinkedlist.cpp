#include <bits/stdc++.h>
using namespace std;

struct SinglyList
{
    int data;
    SinglyList *next;
};
SinglyList *head;

void insertAtBeginning(int x)
{
    SinglyList *newNode = new SinglyList;
    newNode->data = x;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void insertAtEnd(int x)
{
    SinglyList *newNode = new SinglyList;
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        SinglyList *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void insertAtposition(int x, int pos)
{
    if (head == NULL || pos == 1)
    {
        insertAtBeginning(x);
        return;
    }
    else
    {
        SinglyList *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Linked List Don't have that Much Elements";
                return;
            }
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            insertAtEnd(x);
            return;
        }
        else
        {
            SinglyList *newNode = new SinglyList;
            newNode->data = x;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void display()
{
    if (head == NULL)
        cout << "Empty Linked List";
    else
    {
        SinglyList *ptr = head;
        int i = 1;
        while (ptr->next != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
            i++;
        }
        cout << ptr->data;
        cout << "\nLinked List has " << i << " Nodes";
    }
}
void removeBeginning()
{
    if (head == NULL)
    {
        cout << "Empty Linked List";
        return;
    }
    else if (head->next == NULL)
    {
        cout << "Deleting :" << head->data;
        head = NULL;
        return;
    }
    else
    {
        cout << "Deleting :" << head->data;
        head = head->next;
    }
}
void removeEnd()
{
    if (head == NULL)
    {
        cout << "Empty Linked List";
        return;
    }
    else if (head->next == NULL)
    {
        cout << "Deleting :" << head->data;
        head = NULL;
        return;
    }
    else
    {
        SinglyList *ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        cout << "Deleting " << ptr->next->data;
        ptr->next = NULL;
    }
}
void removePosition(int pos)
{
    if (head == NULL)
    {
        cout << "Empty Linked List";
        return;
    }
    else if (head->next == NULL)
    {
        cout << "Deleting :" << head->data;
        head = NULL;
        return;
    }
    else
    {
        SinglyList *temp = head;
        int i = 0;
        while (i < pos - 2)
        {
            temp = temp->next;
            i++;
            if (temp == NULL)
            {
                cout << "Linked List Don't have that Much Elements";
                return;
            }
        }
        cout << "Deleting : " << temp->next->data;
        temp->next = temp->next->next;
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
                cout << "\nEnter your choice : ";
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
                    cout << "Insert Data : ";
                    cin >> x;
                    cout << "Enter idex to insert starting from 1 : ";
                    cin >> pos;
                    insertAtposition(x, pos);
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
                    cout << "Enter Position : ";
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