//
// Created by DELL on 5/3/2024.
//
#include <iostream>
using namespace std;
template<class t>
class node {
public:
    t data;
    node* next;
};

template<class t>
class linked_queue {
    int queuesize;
    node<t> *front, *rear;
public:
    linked_queue() {
        front =NULL;
        rear = NULL;
        queuesize=0;

    }
    void enqueue(t ele) {

        node<t> *newnode = new node<t>;
        newnode->data=ele;
        newnode->next=NULL;
        if (isempty()) {
            front = newnode;
            rear = newnode;
        } else {

            rear->next=newnode;
            rear=newnode;
        }
        queuesize++;
    }
    t dequeue()
    {
        if(isempty()) {
            cout << "Error: The Queue is Empty.\n";
            return t();
        }
        node<t> *temp=front;
        front=front->next;
        queuesize--;
        return temp->data;
    }
    void print()
    {
        if(isempty())
            cout<<"Error: The Queue is Empty.\n";
        else
        {
            node<t>*temp=front;
            while(temp!=rear)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<rear->data<<endl;
//            another way to display elements
//            while(temp->next!=NULL)
//            {
//                cout<<temp->data<<" ";
//                temp=temp->next;
//            }
//            cout<<temp->data<<endl;

        }

    }
    bool isempty()
    {
        return front==NULL;
    }
    t first()
    {
        if(isempty())
        {cout<<"Error: The Queue is Empty.\n";
            return t();
        }
        return front->data;
    }
    int get_queuesize()
    {return queuesize;
    }
    void clear()
    {
        front=NULL;
        rear=NULL;
        queuesize=0;
    }
};

void functions_of_linked_queue()
{
    linked_queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<"\nthe current values in the linked list based queue: \n";
    q.print();
    auto  deleted=q.dequeue();
    cout<<"\nthe first element -->"<<deleted<<"<-- in the queue is deleted\n";
    cout<<"\nthe current values in the queue array based: \n";
    q.print();
    auto first_ele=q.first();
    cout<<"\n-->"<<first_ele<<"<-- is the first element in queue\n";
    cout<<"\nis the queue empty? "<<q.isempty()<<"\n";
    cout<<"\nthe queue size: "<<q.get_queuesize()<<"\n";
    q.clear();
    cout<<"\nthe current values in the queue : \n";
    q.print();
    cout<<"\nis the queue empty? "<<q.isempty()<<"\n";
}
int main()
{
    functions_of_linked_queue();
}