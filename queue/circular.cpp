#include <iostream>
using namespace std;
template<class t>
class node {
public:
    t data;
    node* next;
node()
{
    next=nullptr;
}
};

template<class t>
class circular_queue{
    int qsize;
    int size;
    node<t>*front, *rear;
public:
    circular_queue(int s):size(s){
        front=rear=nullptr;
        qsize=0;
    }
    void enqueue(t ele)
    {
        if(qsize<size) {
            node<t> *newnode = new node<t>;
            newnode->data = ele;
            newnode->next = nullptr;
            if (front == nullptr) {
                front = rear = newnode;
                qsize++;
            } else {
                rear->next = newnode;
                rear=newnode;
                qsize++;
            }
        }
        else
            cout<<"the queue is full.\n";
    }
    bool is_empty()
    {
        return front==nullptr;
    }
    t dequeue()
    {
        if(is_empty())
            return t();
        node<t>* temp=front;
        if(front==rear)
            rear=nullptr;
        front=front->next;
        qsize--;
        return temp->data;
    }
    int get_queuesize()
    {return qsize;
    }
    t first()
    {
        if(is_empty())
            return t();
        return front->data;
    }
    void clear()
    {
        front=rear=nullptr;
        qsize=0;
    }
    void print()
    {
        if(!is_empty())
        {
            node<t> *temp=front;
            while(temp!=rear->next)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }cout<<endl;
        }
    }
};
int main()
{
    circular_queue<int>q(9);
    q.enqueue(8);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(0);
    q.print();
    cout<<q.dequeue()<<endl;
    cout<<q.first()<<endl;
    cout<<q.get_queuesize()<<endl;
    q.clear();
    q.enqueue(7);
    q.enqueue(6);
    q.enqueue(2);
    q.enqueue(1);
    q.print();
}