#include <bits\stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    int idx = -1, dia = 0, idx2 = -1;
    vector<int> v;

    //build tree using preorder sequence
    Node* preOrderBuildTree(vector<int>& Nodes) {
        idx++;
        if (Nodes[idx] == -1)
            return NULL;

        Node* newNode = new Node(Nodes[idx]);
        newNode->left = preOrderBuildTree(Nodes);
        newNode->right = preOrderBuildTree(Nodes);
        return newNode;
    }

    //build tree using levelorder sequence
    Node* levelOrderBuildTree(vector<int>& Nodes) {
        if(Nodes.empty()) return NULL;
        int n = Nodes.size();
        Node* root = new Node(Nodes[0]);
        int i = 1;
        queue<Node*> q({root});
        while (i<n) {
            Node* curr = q.front(); q.pop();
            int left = Nodes[i++];
            if(left != -1){
                curr->left = new Node(left);
                q.push(curr->left);
            }
            if(i < n) {
                int right = Nodes[i++];
                if (right != -1) {
                    curr->right = new Node(right);
                    q.push(curr->right);
                }
            }
        }
        return root;
    }

    Node* levelOrderBuildTreeREC(Node *root, vector<int> a, int n, int i = 0){
        if(!n) return NULL;
        if(!a[i] || i >= n) return NULL;
        root = new Node(a[i]);
        root->left = levelOrderBuildTreeREC(root->left, a, n, 2*i+1);
        root->right = levelOrderBuildTreeREC(root->right, a, n, 2*i+2);
        return root;
    }

    //print tree by preorder traversal, root left subtree right subtree
    void preorder(Node* root) {
        if (root == NULL) {
            // cout << -1 << " "; // choice to print -1 if leaf Node
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
    //preorder iterative
    void itpreorder(Node* root){
        if(!root) return;
        stack<Node*> s({root});
        while(s.size()){
            Node *curr = s.top(); s.pop();
            cout << curr->data << " ";
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        }
    }
    
    //print tree by inorder traversal, left subtree root right subtree
    void inorder(Node* root) {
        if (root == NULL) {
            // cout << -1 << " "; // choice to print -1 if leaf Node
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    //inorder iterative
    void itinorder(Node* root){
        if(!root) return;
        stack<Node*> s;
        while(1){
            if(root){
                s.push(root);
                root = root->left;
            }
            else{
                if(s.empty()) break;
                root = s.top(); s.pop();
                cout << root->data << " ";
                root = root->right;
            }
        }
    }
    

    //print tree by postorder traversal, left subtree right subtree root
    void postorder(Node* root) {
        if (root == NULL) {
            // cout << -1 << " "; // choice to print -1 if leaf Node
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    //postorder iterative
    void itpostorder_2stacks(Node* root){
        if(!root) return;
        stack<Node*> s1({root});
        stack<Node*> s2;
        while(s1.size()){
            root = s1.top(); s1.pop();
            s2.push(root);
            if(root->left) s1.push(root->left);
            if(root->right) s1.push(root->right);
        }
        while(s2.size()){
            cout << s2.top()->data << " ";
            s2.pop();
        }
    } 
    void itpostorder_1stack(Node* root){
        vector<int> v;
        if(!root) return;
        stack<Node*> s({root});
        while(s.size()){
            Node *t = s.top(); s.pop();
            if(t){
                v.push_back(t->data);
                s.push(t->left);
                s.push(t->right);
            }
        }
        reverse(begin(v), end(v));
    }


    //print tree by levelorder traversal
    void levelorder(Node* root) {
        if (root == NULL) {
            // cout << -1 << " "; // choice to print -1 if leaf Node
            return;
        }
        queue<Node*> bfs({root,NULL});
        while(!bfs.empty()){
            Node *curr = bfs.front(); bfs.pop();
            if(curr == NULL){
                cout << "\n";
                if(bfs.empty()) break;
                else bfs.push(NULL);
            }
            else{
                cout << curr->data << " ";
                if(curr->left) bfs.push(curr->left);
                if(curr->right) bfs.push(curr->right);
            }
        }
    }

    void left(Node *root){
        if(!root) return;
        if(!(root->left) && !(root->right)) return;
        v.push_back(root->data);
        if(root->left) left(root->left);
        else left(root->right);
    }
    void leaves(Node *root){
        if(!root) return;
        if(!(root->left) && !(root->right)) v.push_back(root->data);
        leaves(root->left);
        leaves(root->right);
    }
    void right(Node *root){
        if(!root) return;
        if(!(root->left) && !(root->right)) return;
        if(root->right) right(root->right);
        else right(root->left);
        v.push_back(root->data);
    }
    
    vector<int> boundary(Node *root){
        if(!root){ 
            // cout << -1 << " "; // choice to print -1 if leaf Node
            return {};
        }
        v.push_back(root->data);
        left(root->left);
        if((root->left) || (root->right)) leaves(root);
        right(root->right);
        for(int i : v) cout << i << " ";
        cout << endl;
    }

    //count the number of non null Nodes
    int countNodes(Node *root){
        if(root == NULL)
            return 0;
        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        return (leftCount + rightCount + 1);
    }

    //sum of non null Nodes
    int sumNodes(Node *root){
        if(root == NULL)
            return 0;
        int leftSum = sumNodes(root->left);
        int rightSum = sumNodes(root->right);
        return (leftSum + rightSum + root->data);
    }

    //height of tree
    int height(Node *root){
        if(root == NULL)
            return 0;
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        dia = max(dia, leftHt+rightHt+1); //updates dia if dia with curr Node is larger than previous
        return (max(leftHt,rightHt) + 1);
    }

    //diameter of tree, O(n^2)
    int slowDiameter(Node *root){
        if(root == NULL)
            return 0;
        int leftdia = slowDiameter(root->left);
        int rightdia = slowDiameter(root->right);
        int rootdia = height(root->left) + height(root->right) + 1;
        return max({leftdia, rightdia, rootdia});
    }

    // diameter of tree, O(n)
    int diameter(Node* root){
        if(root == NULL)
            return 0;
        height(root);
        return dia;
    }

    // class NodeInfo{
    // public:
    //     int ht, dia;
    //     NodeInfo(int di, int hi) : ht(hi), dia(di) {}
    // };

    // diameter of tree, O(n)
    // NodeInfo diameter(Node* root){
    //     if(root == NULL)
    //         return NodeInfo(0,0);

    //     NodeInfo left = diameter(root->left);
    //     NodeInfo right = diameter(root->right);

    //     int d1 = left.dia;
    //     int d2 = right.dia;
    //     int d3 = left.ht + right.ht + 1;
    //     int myheight = max(left.ht, right.ht) + 1;
    //     int mydia = max({d1,d2,d3});
    //     NodeInfo myInfo(mydia, myheight); 
    //     return myInfo;
    // }

};

int main() {
    vector<int> preOrderNodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}; //preorder data
    vector<int> levelOrderNodes = {14, 14, 3, -1, 8, 8, 12, -1, 6, 17, 3, -1, 1, 11, 10, -1, 6, 6, 13, -1, 10, 17, 7, -1, 11, 7}; //levelorder data
    BinaryTree tree, tree2;
    Node* root = tree.preOrderBuildTree(preOrderNodes);
    Node* root2 = tree2.levelOrderBuildTree(levelOrderNodes);
    cout << "Total Nodes are : " << tree.countNodes(root) << "\n";
    cout << "Sum of Nodes are : " << tree.sumNodes(root) << "\n";
    cout << "Height of tree is : " << tree.height(root) << "\n";
    cout << "Diameter of tree is : " << tree.diameter(root) << "\n";
    cout << "\nPreorder Sequence : \n";
    tree.preorder(root);
    cout << "\nInorder Sequence : \n";
    tree.inorder(root);
    cout << "\nPostorder Sequence : \n";
    tree.postorder(root);
    cout << "\nLevelorder Sequence : \n";
    tree.levelorder(root);
    cout << "\nBoundary : \n";
    tree.boundary(root);
    cout << "\nLevelorder Sequence : \n";
    tree2.levelorder(root2);

    return 0;
}
