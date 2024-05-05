//
// Created by DELL on 5/3/2024.
//
#include<iostream>
using namespace std;
template<class t>
class node{
public:
    t data;
    node* next;
};

template<class t>
class linked_list{
public:
    node<t> *front,*rear;
    linked_list(){
        front=NULL;
        rear=NULL;
    }
    void Append(t val){
        node<t> *temp=new node<t>;
    temp->data=val;
    temp->next=NULL;
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
    }
    void print()
    {
        node<t> *temp=front;
        while(temp!=NULL)
        {
        cout<<temp->data<<" ";
        temp=temp->next;
        }

    }
    void insert(t val,int index)
    {
        node<t> *temp=front;
        node<t> *newnode=new node<t>;
        newnode->data=val;
        newnode->next=NULL;
        if(index==0)
        {newnode->next=front;
            front=newnode;
        }else
        {
            for (int i = 0; i < index-1 && temp->next!=NULL; ++i) {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }

    }
    void remove(t val)
    {
        node<t> *temp,*prev ;
        temp = prev = front;
        if(front==NULL)
            return;
        else if(front->data==val)
        {
            front=front->next;
            delete temp;
        }
        else {
            while (temp != NULL && temp->data != val) {
                prev=temp;
                temp = temp->next;
            }
            if(temp==NULL)
                return;
            else{
                prev->next = temp->next;
                delete temp;
            }
        }
    }
    void remove_at(int index)
    {
        node<t> *temp,*t2 ;
        temp =  front;
        if(front==NULL)
            return;
        else if(index==0)
        {
            t2=temp->next;
            front=t2;
            delete temp;
        }
        else
        {
            for (int i = 0; i < index-1 &&temp!=rear; ++i) {
                temp=temp->next;
            }
            t2=temp->next;
            temp->next=t2->next;
            if(temp==rear)
                rear=temp;
            delete t2;
        }
    }
    void reverse()
    {
        node<t> *curr=front,*prev=NULL,*nex=NULL;
        while (curr!=NULL) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        front=prev;
    }
};
int main()
{
    linked_list<int> k;

    k.Append(1);
    k.Append(2);
    k.Append(3);
    k.Append(3);
    k.remove(3);
    k.insert(4,50);
    k.remove_at(3);
    k.reverse();
    k.print();

}