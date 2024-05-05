//
// Created by DELL on 5/3/2024.
#include<iostream>
using namespace std;

template<class t>
class node{
public:
    t data;
    node*prev;
    node*next;
    node(){
        next=prev=NULL;
    }
};

template<class t>
class doubly_linked_list{
public:
    node<t>*front,*rear;
    doubly_linked_list()
    {
        front=rear=NULL;
    }
    void append(t val)
    {
        node<t>*newnode=new node<t>;
        newnode->data=val;
        if(front==NULL) {
            rear=newnode;
            front=newnode;

        }
        else
        {
            node<t> * temp=front;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            rear=newnode;
        }
    }
    void display()
    {node<t> * temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main()
{
    doubly_linked_list<int>d;
    d.append(1);
    d.append(2);
    d.append(3);
    d.display();
}