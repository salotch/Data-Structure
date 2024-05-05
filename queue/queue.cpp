#include <iostream>
using namespace std;
template<class t>
class array_queue{
    int index;
    int size;
    int qsize;
    t* front;
    t* rare;
    t* arr;
public:
    array_queue():size(100), index(0), qsize(0)
    {
        arr = new t[size];
        front = nullptr;
        rare = nullptr;
    }
    array_queue(int s) : size(s), index(0), qsize(0) {
        arr = new t[size];
        front = nullptr;
        rare = nullptr;
    }
    ~array_queue() {
        delete[] arr;
    }

    void enqueue(t ele) {
        if (qsize < size) {
            arr[index] = ele;
            if (qsize == 0)
                front = &arr[index];
            rare = &arr[index];
            index++;
            qsize++;

        } else {
            cout << "Error: The Queue is Full.\n" <<endl;
        }
    }
    t dequeue()
    {
        if(isempty())
        {
            cout<<"Error: The Queue is Empty.\n";
            return t();
        }
        else if(front==rare)
        {  t *i=front;
            clear();
            return *i;
        }
        else{
            qsize--;
            t *i=front;
            front++;
            return *i;
        }
    }
    t first()
    {
        if(isempty())
        {
            cout<<"Error: The Queue is Empty.\n";
            return t();
        }
        else{
            t *i=front;
            return *i;
        }
    }
    bool isempty()
    {   if(qsize==0)
        {return true;
        rare=0;
        }
        else
            return false;

    }
    void clear()
    {
        qsize=0;
        index=0;
        front=nullptr;
        rare=nullptr;
        delete[] arr;
        arr = new t[size];

    }
    int queuesize(){
        return qsize;
    }
    void print()
    {
        if(isempty())
            cout<<"Error: The Queue is Empty.\n";
        else{
            t *i=front;
            while (i!=rare+1) {
                cout<<*i<<" ";
                i++;
            }cout<<"\n";
        }
    }

};


void functions_of_array_queue()
{

    array_queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<"the current values in the array based queue: \n";
    q.print();
    auto  deleted=q.dequeue();
    cout<<"\nthe first element -->"<<deleted<<"<-- in the queue is deleted\n";
    q.enqueue(40);
    q.enqueue(50);
    cout<<"\nthe current values in the queue array based: \n";
    q.print();
    auto first_ele=q.first();
    cout<<"\n-->"<<first_ele<<"<-- is the first element in queue\n";
    cout<<"\nis the queue empty? "<<q.isempty()<<"\n";
    cout<<"\nthe queue size: "<<q.queuesize()<<"\n";
    q.clear();
    cout<<"\nthe current values in the queue : \n";
    q.print();
    cout<<"\nis the queue empty? "<<q.isempty()<<"\n";

}
int main() {

    functions_of_array_queue();

}

