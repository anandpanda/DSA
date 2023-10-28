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

Node *middleNode(Node *head)
{
    if (head == NULL)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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
    // iat(tail, 6);
    print(head);

    cout << "Middle Node Data is: " << (middleNode(head))->data << endl;

    delList(head);
    return 0;
}