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

void delList(Node *&head)
{
    while (head != NULL)
    {
        Node *temp = head->next;
        delete head;
        head = temp;
    }
}

void makeUnique(Node *&head, Node *&tail)
{
    Node *curr = head, *del = curr->next;
    while (del)
    {
        if (del->data == curr->data)
        {
            if (del == tail)
                tail = curr;
            curr->next = del->next;
            del->next = NULL;
            delete del;
            del = curr->next;
        }
        else
        {
            curr = del;
            del = curr->next;
        }
    }
}

int main()
{
    Node *n1 = new Node(1);

    Node *head = n1;
    Node *tail = n1;

    iat(tail, 2);
    iat(tail, 2);
    iat(tail, 3);
    iat(tail, 3);
    iat(tail, 3);
    iat(tail, 4);
    iat(tail, 4);
    print(head);

    makeUnique(head, tail);
    print(head);

    return 0;
}