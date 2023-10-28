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
// reverse LL iteratively
void revListIt(Node *&head)
{
    Node *prev = NULL;
    Node *nxt = head->next;

    while (nxt)
    {
        head->next = prev;
        prev = head;
        head = nxt;
        nxt = nxt->next;
    }
    head->next = prev;
}

// reverse LL recursively
void revListRec(Node *&head, Node *prev, Node *curr)
{
    // base case
    if (!curr->next)
    {
        head->next = NULL;
        head = curr;
        curr->next = prev;
        return;
    }
    revListRec(head, curr, curr->next);
    curr->next = prev;
}

// Method 2
Node *revListRec(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *chotaHead = revListRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return chotaHead;
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
    Node *n1 = new Node(1);

    Node *head = n1;
    Node *tail = n1;

    iat(tail, 2);
    iat(tail, 3);
    iat(tail, 4);
    iat(tail, 5);
    iat(tail, 6);
    iat(tail, 7);
    print(head);

    revListIt(head);
    print(head);

    Node *prev = head;
    Node *curr = head->next;
    revListRec(head, prev, curr);
    print(head);

    head = revListRec(head);
    print(head);

    delList(head);
    return 0;
}