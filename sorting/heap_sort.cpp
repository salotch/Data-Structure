#include<iostream>
using namespace std;
void heapify(int *arr, int s, int i)
{
    int l=(i*2)+1;
    int r= (i*2) +2;
    int max=i;
    if(l<s && arr[l]>arr[max])
        max=l;
    if (r<s && arr[r]>arr[max])
        max=r;
    if(max!=i)
    {  swap(arr[max],arr[i]);
       heapify(arr,s,max);
    }
}
void build_heap(int *arr, int s)
{
    for (int j = (s/2) -1; j >=0; j--) {
        heapify(arr, s, j);
    }
}
void heap_sort(int *arr, int s)
{
    build_heap(arr,s);
    for (int i = s-1; i >=0; i--) {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}
int main()
{
    int *arr=new int[6]{20,80,50,30,90,10};
    heap_sort(arr,6);
    for (int i = 0; i < 6; ++i) {
       cout<<arr[i]<<" ";
    }
}