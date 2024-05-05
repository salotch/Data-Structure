//
// Created by DELL on 5/4/2024.
//
#include <iostream>
#include <queue>
using namespace std;
template<class t>
class node{
public:
    t data;
    node *right,*left;
    node(){
        right=left=NULL;
    }
};
template<class t>
class BST{
    node<t>*root;
int get_height_helper(node<t>*temp)
{
    if(temp==NULL)
        return -1;
    return 1+max(get_height_helper(temp->left), get_height_helper(temp->right));
}

void pre_help( node<t>* temp)
{
    cout<<temp->data<<" ";
    if(temp->left!=NULL)
        pre_help(temp->left);
    if(temp->right!=NULL)
        pre_help(temp->right);
    return;
}
void in_help( node<t>* temp)
    {

        if(temp->left!=NULL)
            in_help(temp->left);
        cout<<temp->data<<" ";
        if(temp->right!=NULL)
            in_help(temp->right);
        return;
    }
    void post_help( node<t>* temp)
    {

        if(temp->left!=NULL)
            post_help(temp->left);
        if(temp->right!=NULL)
           post_help(temp->right);
        cout<<temp->data<<" ";
        return;
    }
    node<t>* delete_helper(node<t>*r,t val)
    {
    if(r==NULL)
        return NULL;
    else if(val<r->data)
        r->left= delete_helper(r->left,val);
    else if(val>r->data)
        r->right= delete_helper(r->right,val);
    else{
        if(r->left==NULL)
        {
            node<t>* temp=r->right;
            delete r;
            return temp;
        }
        else if(r->right==NULL)
        {
            node<t>*temp=r->left;
            delete r;
            return temp;
        }
        else
        { node<t>*temp=r->left;
            while(temp->left!=NULL)
                temp=temp->left;
            r->data=temp->data;
            r->left= delete_helper(r->left,temp->data);
        }
    }
        return r;
    }
    void add_helper(node<t>* temp,t val)
    {
    node<t>* newnode=new node<t>;
        newnode->data=val;

    if(val>temp->data) {
        if(temp->right==NULL)
        {
            temp->right=newnode;
        }
        else {
            add_helper(temp->right, val);

        }

    }
    else {
        if (temp->left == NULL) {
            temp->left = newnode;
        } else{
            add_helper(temp->left, val);
        }

    }

    }
//    void apply_rotation(node<t>* temp2)
//    {
//
//        int balance=get_height_helper(temp2->left)-get_height_helper(temp2->right);
//        cout<<balance<<endl;
//
//        if (balance < -1) {
////            cout<<temp2;
//            node<t> *temp = temp2->right;
//            temp2->right = NULL;
//            temp->left = temp2;
//            root = temp;
////        left rotation
//        } else if (balance > 1) {
////            cout<<temp2;
//            node<t> *temp = temp2->left;
//            temp2->left = NULL;
//            temp->right = temp2;
//            root = temp;
////        right rotation
//        }
//    }
public:
    BST(){
        root=NULL;
    }
    void append(t val){
        node<t>* newnode=new node<t>;
        newnode->data=val;
        if(root==NULL)
        {
            root=newnode;
            return;
        }
        add_helper(root,val);

    }
    t get_min()
    {
        if(root==NULL)
            return t();
        else{
            node<t>* temp=root;
            while(temp->left!=NULL)
                temp=temp->left;
            return temp->data;
        }
    }
    t get_max()
    {
        if(root==NULL)
            return t();
        else{
            node<t>* temp=root;
            while(temp->right!=NULL)
                temp=temp->right;
            return temp->data;
        }
    }
int get_height()
{
    return get_height_helper(root);
}
void DF_pre()
{if(root!=NULL)
        pre_help(root);
}
void DF_in(){
    if(root!=NULL)
        in_help(root);
}
void DF_post(){
    if(root!=NULL)
        post_help(root);
}
void BF()
{
    if(root==NULL)
        return;
    queue<node<t>*> q;
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
void delete_ele(t val) {
    root =delete_helper(root,val);
}


};
int main(){
    BST<int> b;
    cout<<b.get_height()<<endl;

    b.append(6);
    b.append(3);
    b.append(9);
    b.append(10);
    b.append(25);
    cout<<b.get_min()<<endl;
    cout<<b.get_max()<<endl;
    cout<<b.get_height()<<endl;
    b.DF_pre();
    cout<<endl;
    b.DF_in();
    cout<<endl;
    b.DF_post();
    cout<<endl;
b.delete_ele(15);
b.BF();
}