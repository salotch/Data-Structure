//
// Created by DELL on 5/5/2024.
//
#include <iostream>
using namespace std;
class priority_queue{
    int size,fixed;
    int *arr;

    void heapify(int s,int i){
        int l=(i*2)+1;
        int r=(i*2)+2;
        int max=i;
        if(l<s&&arr[max]<arr[l])
            max=l;
        if(r<s&&arr[max]<arr[r])
            max=r;
        if(max!=i)
        {
            swap(arr[max],arr[i]);
            heapify(s,max);
        }
    }

    void build_heap() {
        for (int i = (size / 2) - 1; i >= 0; i--)
            heapify(size,i);

    }
public:
    priority_queue(int f){
        size=0;
        fixed=f;
        arr=new int [fixed];
    }
    void add(int val){
        if(size>fixed)
            return;
    arr[size]=val;
    build_heap();
        for (int i = size-1; i >=0 ; i--) {
            swap(arr[0],arr[i]);
            heapify(i,0);
        }
        size++;
}
void print()
{
    for (int i = 0; i < size; ++i) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void pop()
{
    if(size==0)
        return;
    swap(arr[0],arr[size-1]);
    size--;
    build_heap();
    for (int i = size-1; i >=0 ; i--) {
        swap(arr[0],arr[i]);
        heapify(i,0);
    }
}
};
int main()
{
    priority_queue x(4);
    x.add(2);
    x.add(3);
    x.add(4);
    x.add(5);
    x.pop();
    x.print();
}