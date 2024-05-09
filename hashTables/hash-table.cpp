//
// Created by DELL on 5/7/2024.
//
#include <iostream>
#include <list>
using namespace std;
class node{
public:
    int *data;
    int *key;
    node* next;
    node(){
        next=NULL;
        data=key=NULL;
    }
};
class hashtable{

int size;
node **table;
public:
hashtable(int s)
{
    size=s;
    table=new node*[s];
    for (int i = 0; i < s; ++i) {
        table[i]=new node[1];
    }
}
void add(int k, int v)
{
    int hash=k%size;
    if(table[hash]->data==NULL)
    {
        table[hash]->data=new int(v);
        table[hash]->key=new int(k);
        table[hash]->next=NULL;
    }
    else
    {
        node** temp=table;
    while(temp[hash]->next!=NULL)
        temp[hash]=temp[hash]->next;
    node *newNode=new node;
    newNode->key=new int(k);
    newNode->data=new int(v);
    newNode->next=NULL;
    temp[hash]->next=newNode;
    }


}
void print()
{
    for (int i = 0; i <size; ++i) {

        cout << "Bucket " << i << ": ";
        if (table[i]->data != NULL) {
            cout << "( " << *(table[i]->key) << ", " <<  *(table[i]->data)<< " ) ";
            while (table[i]->next != NULL) {
                node **temp = table;
                cout << "(" << *(temp[i]->next->key) << "," << *(temp[i]->next->data) << ") ";
                temp[i] = temp[i]->next;
            }

        }cout << endl;
    }
}

};

int main() {
    hashtable t(5);
    t.add(3,33);
    t.add(1,11);
    t.add(2,22);
    t.add(1,111);

    t.print();

    return 0;
}
