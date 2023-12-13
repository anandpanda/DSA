#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
    ~Node()
    {
        int value = data;
        if (next != NULL)
        {
            next = NULL;
            delete next;
        }
        cout << "Deleted Node with data : " << value << endl;
    }
};

// insert at head
void iah(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// insert at tail
void iat(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

// insert at position
void iap(Node *&head, Node *&tail, int d, int p)
{
    if (p == 1)
    {
        iah(head, d);
        return;
    }
    Node *pos = head;
    for (int i = 1; i < p - 1; ++i)
        pos = pos->next;

    if (pos->next == NULL)
    {
        iat(tail, d);
        return;
    }

    Node *temp = new Node(d);
    temp->next = pos->next;
    pos->next = temp;
}

// delete node at position
void dnap(Node *&head, Node *&tail, int p)
{
    if (p == 1)
    {
        Node *curr = head;
        head = head->next;
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void delList(Node *&head)
{
    while (head != NULL)
    {
        Node *temp = head->next;
        delete head;
        head = temp;
    }
}

int main()
{
    Node *n1 = new Node(10);

    Node *head = n1;
    Node *tail = n1;
    print(head);

    iah(head, 12);
    print(head);

    iat(tail, 15);
    print(head);

    iap(head, tail, 17, 4);
    print(head);

    dnap(head, tail, 4);
    print(head);

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    delList(head);

    return 0;
}