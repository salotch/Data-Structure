#include<iostream>
#include <queue>
using namespace std;
template<class t>
class Node {
public:
    t data;
    Node *left;
    Node *right;
    int height;
    Node(){
        right=left= nullptr;
        height=1;
    }

};
template<class t>
class AVL{
    Node<t> *root;

    int height(Node<t>* n){
        if(n == nullptr)
            return 0;
        return  n->height;
    }
    int getBalance(Node<t>*n)
    {
        if(n==nullptr)
            return 0;
        return height(n->left)- height(n->right);
    }
    Node<t>* rightRotate(Node<t>* y)
    {
        Node<t> *x=y->left;
        Node<t> *temp=x->right;

        x->right=y;
        y->left=temp;

        y->height= 1+max(height(y->left), height(y->right));
        x->height= 1+max(height(x->left), height(x->right));

        return x;
    }

    Node<t>* leftRotate(Node<t>* y){


        Node<t> *x=y->right;
        Node<t> *temp=x->left;

        x->left=y;
        y->right=temp;

        y->height= 1+max(height(y->left), height(y->right));
        x->height= 1+max(height(x->left), height(x->right));

        return x;

    }

    Node<t>* insertHelper(Node<t>* node,t key) {

        if (node == nullptr) {
            auto newNode = new Node<t>;
            newNode->data = key;
            return newNode;
        }
        if (!(key > node->data))
        {
            node->left= insertHelper(node->left,key);
        }
        else if(key>node->data)
        {
            node->right = insertHelper(node->right,key);
        }
        else
            return node;//to prevent multiplication in AVL

        node->height=1+max(height(node->right), height(node->left));

        int balance= getBalance(node);
//rotations
        if(balance>1 && !(key > node->left->data))
            return rightRotate(node);

        if(balance<-1 && key > node->right->data)
            return leftRotate(node);

        if (balance>1 && key > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && !(key > node->right->data))
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    Node<t>* deleteHelper(Node<t>* root,t data){
        if(root==nullptr)
            return root;
        if(data < root->data)
            root->left = deleteHelper(root->left,data);
        else if(!(data <= root->data))
            root->right =deleteHelper(root->right,data)  ;
        else{
            if((root->left == nullptr)||(root->right == nullptr)){
                Node<t> *temp=root->left? root->left : root->right;
                if (temp==nullptr)
                {
                    temp=root;
                    root=nullptr;
                }
                else
                    *root = *temp;
                free(temp);
            }
            else{
                Node<t> *temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteHelper(root->right,temp->data);
            }
        }
        if(root==nullptr)
            return root;
        root->height =1 + max(height(root->left),height(root->right));
        int balance = getBalance(root);
        if(balance>1 && getBalance(root->left)>=0)
            return rightRotate(root);
        if(balance>1 && getBalance(root->left)<0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if(balance<-1 && getBalance(root->right)<=0)
            return leftRotate(root);
        if(balance<-1 && getBalance(root->left)>0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    void inorder(Node<t>* n)
    {
        if(n != nullptr) {

            inorder(n->left);
            cout<<n->data<<" ";
            inorder(n->right);
        }
    }
    void des(Node<t>* n)
    {
        if(n != nullptr) {

            des(n->right);
            cout<<n->data<<" ";
            des(n->left);
        }
    }
    void printH(Node<t>* n)
    {
        if(n != nullptr) {

            cout<<n->data<<" ";;
            printH(n->left);
            printH(n->right);

        }
    }
    Node<t>* minValueNode(Node<t>*node)
    {
        Node<t>* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;

    }
public:
    AVL(){
        root= nullptr;
    }
    void insert(t val)
    {
        root = insertHelper(root,val);
    }
    void insertn(t val)
    {
        root = insertHelpername(root,val);
    }
    void printAsc()
    {
        inorder(root);
        cout<<endl;
    }
    void printDes()
    {
        des(root);
        cout<<endl;
    }
    void printNormally()
    {
        printH(root);
        cout<<endl;
    }
    void BF()
    {
        if(root==NULL)
            return;
        queue<Node<t>*> q;
        q.push(root);
        while(!q.empty())
        {
            cout<<q.front()->data<<" ";
            if(q.front()->left!=NULL)
                q.push(q.front()->left);
            if(q.front()->right!=NULL)
                q.push(q.front()->right);
            q.pop();
        }cout<<endl;
    }
    void Delete(t val)
    {
        root = deleteHelper(root,val);
    }
    void Deletep(t val)
    {
        root = deleteHelperp(root,val);
    }
};

int main()
{
    AVL<int> tree;
    tree.insert(15);
    tree.BF();
    tree.insert(20);
    tree.BF();
    tree.insert(24);
    tree.BF();
    tree.insert(10);
    tree.BF();
    tree.insert(13);
    tree.BF();
    tree.insert(7);
    tree.BF();
    tree.insert(30);
    tree.BF();
    tree.insert(36);
    tree.BF();
    tree.insert(25);
    tree.BF();
}