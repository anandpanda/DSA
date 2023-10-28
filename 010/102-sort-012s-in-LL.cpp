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
            // delete next;
            next = NULL;
        }
        cout << "Deleted Node with data : " << value << endl;
    }
};

// insert at tail
void iat(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
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

void insert(Node *&tail, Node *node)
{
    tail->next = node;
    tail = node;
}
void sort012(Node *&head, Node *&tail)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // create 3 partial LL
    while (curr)
    {
        int val = curr->data;
        if (val == 0)
            insert(zeroTail, curr);
        else if (val == 1)
            insert(oneTail, curr);
        else
            insert(twoTail, curr);
        curr = curr->next;
    }

    // merge sub LL
    twoTail->next = NULL;
    oneTail->next = twoHead->next;
    zeroTail->next = oneHead->next;

    head = zeroHead->next;
    if (twoHead->next)
        tail = twoTail;
    else if (oneHead->next)
        tail = oneTail;
    else
        tail = zeroTail;
}

int main()
{
    Node *n1 = new Node(1);

    Node *head = n1;
    Node *tail = n1;

    iat(tail, 0);
    iat(tail, 2);
    iat(tail, 2);
    iat(tail, 1);
    iat(tail, 0);
    print(head);

    sort012(head, tail);
    print(head);

    return 0;
}