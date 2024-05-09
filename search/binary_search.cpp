//
// Created by DELL on 5/7/2024.
//
#include<iostream>
using namespace std;
int binary_search(int *array,int val,int size)
{
    int low=0;
    int high=size-1;
    int middle;
    while (low<=high)
    {
        middle=low+(high-low)/2;
        if(array[middle]>val)
            high=middle-1;
        else if(array[middle]<val)
            low=middle+1;
        else
            return middle;
    }
    return -1;
}
int main()
{
    int *array;
    array=new int[51];
    for (int i = 0; i <51 ; ++i) {
        array[i]=i;
    }
    cout<<binary_search(array,27,51);
}