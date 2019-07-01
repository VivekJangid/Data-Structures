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
        head = newNode;
        newNode->next = head;
    }
    else
    {
        SinglyList *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
}
void insertAtEnd(int x)
{
    SinglyList *newNode = new SinglyList;
    newNode->data = x;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        SinglyList *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}
void insertAtposition(int x, int pos)
{
    SinglyList *newNode = new SinglyList;
    newNode->data = x;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        SinglyList *temp = head;
        int i = 0;
        while (i < pos - 2)
        {
            temp = temp->next;
            i++;
            if (temp == head)
            {
                cout << "Linked List Don't have that Much Elements";
                return;
            }
            if (temp->next == head)
            {
                temp->next = newNode;
                newNode->next = head;
                return;
            }
        }
        SinglyList *temp1 = temp;
        newNode->next = temp1->next;
        temp->next = newNode;
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
        while (ptr->next != head)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
            i++;
        }
        cout << ptr->data << "\t\t" << ptr->next->data;
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
    else if (head->next == head)
    {
        cout << "Deleting :" << head->data;
        head = NULL;
        return;
    }
    else
    {
        SinglyList *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        cout << "Deleting :" << head->data;
        head = head->next;
        temp->next = head;
    }
}
void removeEnd()
{
    if (head == NULL)
    {
        cout << "Empty Linked List";
        return;
    }
    else if (head->next == head)
    {
        cout << "Deleting :" << head->data;
        head = NULL;
        return;
    }
    else
    {
        SinglyList *ptr = head;
        while (ptr->next->next != head)
        {
            ptr = ptr->next;
        }
        cout << "Deleting " << ptr->next->data;
        ptr->next = head;
    }
}
void removePosition(int pos)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty";
    }
    else
    {
        SinglyList *temp = head;
        int i = 0;
        while (i < pos - 2)
        {
            temp = temp->next;
            i++;
            if (temp == head)
            {
                cout << "Linked List Don't have that Position to Delete";
                return;
            }
            if (temp->next->next == head)
            {
                cout << "Deleting  :" << temp->next->data;
                temp->next = head;
                return;
            }
        }
        cout << "Deleting : : " << temp->next->data;
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
                    cout << "Enter Position : ";
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