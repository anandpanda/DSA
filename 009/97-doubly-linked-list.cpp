#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        data = d;
        prev = next = NULL;
    }

    ~Node()
    {
        next = NULL;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int len(Node *head)
{
    int c = 0;
    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}

// insert at head
void iah(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    // empty list
    if (head == NULL)
        head = tail = temp;
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// insert at tail
void iat(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    // empty list
    if (tail == NULL)
        head = tail = temp;
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// insert at position
void iap(Node *&head, Node *&tail, int d, int p)
{
    if (p == 1)
    {
        iah(head, tail, d);
        return;
    }
    Node *pos = head;
    for (int i = 1; i < p - 1; ++i)
        pos = pos->next;

    if (pos->next == NULL)
    {
        iat(head, tail, d);
        return;
    }

    Node *temp = new Node(d);
    temp->next = pos->next;
    (pos->next)->prev = temp;
    pos->next = temp;
    temp->prev = pos;
}

// delete node at position
void dnap(Node *&head, Node *&tail, int p)
{
    if (p == 1)
    {
        Node *curr = head;
        curr->next->prev = NULL;
        head = curr->next;
        // curr->next = NULL;
        delete curr;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        for (int i = 0; i < p - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (prev->next == NULL)
            tail = prev;
        // curr->next = NULL;
        delete curr;
    }
}

// void print(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

int main()
{
    Node *n1 = new Node(10);
    Node *head = n1;
    Node *tail = n1;

    print(head);
    // cout << len(head);

    iah(head, tail, 11);
    print(head);

    iat(head, tail, 12);
    print(head);

    iap(head, tail, 13, 4);
    print(head);

    dnap(head, tail, 1);
    print(head);

    return 0;
}