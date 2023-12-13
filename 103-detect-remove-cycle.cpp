#include <iostream>
#include <limits.h>
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

// Floyd's Cycle Detection Algo.
Node *hasCycle(Node *head)
{
    Node *dummy = new Node(INT_MIN);
    if (!head || !head->next)
        return dummy;
    Node *slow = head;
    Node *fast = head->next;

    bool ans = true;

    while (slow != fast)
    {
        if (!fast || !fast->next || !fast->next->next)
        {
            ans = false;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (ans == true)
        return slow;
    else
        return dummy;
}

Node *cycleStart(Node *head, Node *intersect) // view Notion
{
    intersect = intersect->next;

    while (head != intersect)
    {
        head = head->next;
        intersect = intersect->next;
    }
    return head;
}

Node *removeLoop(Node *head, Node *start)
{
    Node *tail = head;
    while (tail->next != start)
        tail = tail->next;
    tail->next = NULL;
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
    iat(tail, 8);

    tail->next = head->next->next; // cycle at node 3

    Node *intersect = hasCycle(head);
    Node *start = NULL;

    if (intersect->data != INT_MIN)
    {
        cout << "Has Cycle." << endl;
        start = cycleStart(head, intersect);
        cout << "Loop Starts at Node with Data : " << start->data << endl;
        removeLoop(intersect, start);
        cout << "Cycle Removed." << endl;
        print(head);
    }

    return 0;
}   