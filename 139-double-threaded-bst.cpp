#include <bits\stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool lthread, rthread;
    Node(int data) : data(data), left(NULL), right(NULL), lthread(1), rthread(1) {}
    // 1 means thread, 0 means child
};

class BinaryTree {
public:

    Node* BuildTree(Node *root, int d) {
        Node *nn = new Node(d), *cur = root;
        if(!root) return nn;
        
        while(cur){
            if(d < cur->data){
                if(!cur->lthread) cur = cur->left;
                else{
                    nn->left = cur->left;
                    nn->right = cur;
                    cur->left = nn;
                    cur->lthread = 0;
                    return root;
                }
            }
            else{
                if(!cur->rthread) cur = cur->right;
                else{
                    nn->right = cur->right;
                    nn->left = cur;
                    cur->right = nn;
                    cur->rthread = 0;
                    return root;                    
                }
            }
        }
        return root;
    }

    Node *isucc(Node *n){
        if(n->rthread) return n->right;

        n = n->right;
        while(!n->lthread) n = n->left;
        return n;
    }

    void threadedInorder(Node *root){
        if(!root) return;
        Node *cur = root;
        while(!cur->lthread) cur = cur->left;
        while(cur){
            cout << cur->data << " ";
            cur = isucc(cur);
        }
    }

    void threadedPreorder(Node *root){
        if(!root) return;
        Node *cur = root;
        while(cur){
            cout << cur->data << " ";
            if(!cur->lthread) cur = cur->left;
            else if(!cur->rthread) cur = cur->right;
            else cur = cur->right->right;
        }
    }

    void threadedPostorder(Node *root){
        if(!root) return;
        Node *cur = root;
        while(cur){
            cout << cur->data << " ";
            if(!cur->lthread) cur = cur->left;
            else if(!cur->rthread) cur = cur->right;
            else cur = cur->right->right;
        }
    }    
};

int main() {
    Node *root = NULL;
    BinaryTree tree;
    root = tree.BuildTree(root, 20);
    root = tree.BuildTree(root, 10);
    root = tree.BuildTree(root, 30);
    root = tree.BuildTree(root, 5);
    root = tree.BuildTree(root, 16);
    root = tree.BuildTree(root, 14);
    root = tree.BuildTree(root, 17);
    root = tree.BuildTree(root, 13);
    root = tree.BuildTree(root, 15);

    // cout << "\nInorder Sequence : \n";
    // tree.threadedInorder(root);
    cout << "\nPreorder Sequence : \n";
    tree.threadedPreorder(root);

    return 0;
}
