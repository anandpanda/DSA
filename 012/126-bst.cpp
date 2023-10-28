#include <bits\stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(NULL), right(NULL) {}
};

class BinarySearchTree {

    Node *helper(Node *node){
        if(!node->left) return node->right;
        else if(!node->right) return node->left;
        Node *rightChild = node->right;
        Node *lstRight = lastRight(node->left);
        lstRight->right = rightChild;
        return node->left;
    }
    Node *lastRight(Node *node){
        if(!node->right) return node;
        return lastRight(node->right);
    }
    void del(Node* r, int k){
        if(!r){
            cout << "Node not Found!" << endl << endl;
            return;
        }
        if(k < r->data) {
            if(r->left && r->left->data == k) r->left = helper(r->left);
            else del(r->left, k);
        }
        else{
            if(r->right && r->right->data == k) r->right = helper(r->right);
            else del(r->right, k);
        }
    }

    public:
    // insert node recursively
    Node* insertNode(Node *r, int d){
        if(!r) return new Node(d);
        if(d < r->data) r->left = insertNode(r->left, d);
        else r->right = insertNode(r->right, d);
        return r;
    }

    // insert node iteratively
    Node* insert(Node *root, int d){
        if(!root) return new Node(d);
        Node *cur = root;
        while(1){
            if(d >= cur->data){
                if(cur->right) cur = cur->right;
                else {
                    cur->right = new Node(d);
                    break;
                }
            }
            else{
                if(cur->left) cur = cur->left;
                else {
                    cur->left = new Node(d);
                    break;
                }
            }
        }
    }

    Node* deleteNode(Node* &root, int k){
        if(!root){
            cout << "Tree Empty!" << endl << endl;
            return NULL;
        }
        else if(root->data == k) root = helper(root);
        else del(root, k);
    }

    Node* findmin(Node *root){
        if(!root || !root->left) return root;
        return findmin(root->left);
    }

    Node* deletebyvalue(Node *&root, int d){
        if(!root) return root;
        if(d < root->data) root->left = deletebyvalue(root->left, d);
        else if(d > root->data) root->right = deletebyvalue(root->right, d);
        else{
            //No child
            if(!root->left && !root->right) {
                delete root; root = NULL;
            }
            // 1 child
            else if(!root->left) {
                Node *temp = root;
                root = root->right;
                delete temp; temp = NULL;
            }
            else if(!root->left) {
                Node *temp = root;
                root = root->left;
                delete temp; temp = NULL;
            }

            //2 childs
            else {
                Node *temp = findmin(root->right);
                root->data = temp->data;
                root->right = deletebyvalue(root->right, temp->data);
            }
            return root;
        }
    }

    // inorder of bst is sorted
    Node *kth_small(Node* r, int &k){
        if(!r) return NULL;
        Node* left = kth_small(r->left, k);
        if(left) return left;
        if(--k == 0) return r;
	    return kth_small(r->right, k);
    }  

    //lowest common ancestor
    Node* LCA(Node *r, int p, int q){
        if(!r) return NULL;
        if(p < r->data && q < r->data) return LCA(r->left, p, q);
        else if(p > r->data && q > r->data) return LCA(r->right, p, q);
        return r;
    }

    //build bst from preorder
    Node* buildPreorder(vector<int> a, int ub = INT_MAX){
        static int i = 0;
        if(i == a.size() || a[i] >= ub) return NULL;
        Node *root = new Node(a[i++]);
        root->left = buildPreorder(a, root->data);
        root->right = buildPreorder(a, ub);
        return root;
    }

    //build inorder successor of a node
    int inorderSuccessor(Node* root, int d){
        if(!root) return -1;
        int s = -1;
        while(root){
            if(d >= root->data) root = root->right;
            else {
                s = root->data;
                root = root->left;
            }
        }
        return s;
    }

    public:

    //inorder predecessor and successor
    Node* presuc(Node* root, int k, int op){
        Node* ans = NULL;
        while(root){
            int t = (op? k>=root->data : k<=root->data);
            if(t) root = (op? root->right : root->left);
            else{
                ans = root;
                root = (op? root->left : root->right);
            }
        }
        return ans;
    }

    //next() gives next in ascending, or in descending as per reverse value
    class BSTIterator {
    stack<Node*> st;
    bool rev = false;
    void pushAll(Node* root){
        while(root){
            st.push(root);
            root = (!rev)? root->left : root->right;
        }
    }
public:
    BSTIterator(Node* root, bool reverse) {
        rev = reverse;
        pushAll(root);
    }
    
    int next() {
        Node* ans = st.top(); st.pop();
        pushAll((!rev)? ans->right : ans->left);
        return ans->data;
    }
};
    
    void print(Node *r){
        if(!r) return;
        print(r->left);
        cout << r->data << " ";
        print(r->right);
    }
    
    bool validate(Node* root, int l = INT_MIN, int r = INT_MAX){
        if(!root) return true;
        if(root->data < l || root->data > r) return false;
        bool left = validate(root->left, l, root->data-1);
        bool right = validate(root->right, root->data, r);
        return left && right;
    }
};

Node* insertend(Node *root){
    if(!root) return new Node(INT_MIN);
    root->right = insertend(root->right);
    return root;
}

int main(){
    BinarySearchTree bst;
    Node *root = NULL;
    // root = bst.insertNode(root, rand()%50);
    // for(int i = 0; i < 10; i++) bst.insertNode(root, rand()%50);
    // bst.print(root);
    // int k = 3;
    // cout << "kth smallest : " << bst.kth_small(root, k)->data << endl;
    // cout << bst.validate(root) << endl;
    root = bst.buildPreorder({8,5,1,7,10,12});
    bst.print(root);
    cout << endl;
    return 0;
}