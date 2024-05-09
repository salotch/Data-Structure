//
// Created by DELL on 5/7/2024.
//merge sort is not in place sort so it has space complexity of O(n) and
// time complexity with best and worst and average cases is O(nlog n)

#include<iostream>
using namespace std;
void merge(int *arr,int l,int m,int r)
{
    int sl=m-l+1,sr=r-m;
    int *leftArr=new int[sl],*rightArr=new int[sr];

    for (int i = 0; i < sl; ++i) {
        leftArr[i]=arr[l+i];
        cout<<leftArr[i]<<" ";
    }cout<<endl;

    for (int i = 0; i < sr; ++i) {
        rightArr[i]=arr[i+m+1];
    cout<<rightArr[i]<<" ";
    }cout<<endl;

    int i=0,j=0,k=l;
    while(i<sl&&j<sr)
    {
        if(leftArr[i]<=rightArr[j]) {
            arr[k] = leftArr[i];
        i++;
        k++;
        }
        else
        {
            arr[k]=rightArr[j];
            j++;
            k++;
        }
    }
    while(i<sl)
    {
        arr[k]=leftArr[i];
        i++;
        k++;
    }
    while(j<sr)
    {   arr[k]=rightArr[j];
        j++;
        k++;

    }

}
void mergeSort(int *arr,int left, int right)
{
    if(left<right)
    {
        int middle=left+(right-left)/2;
        mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);
        merge(arr,left,middle,right);
    }

}
void print(int*arr,int size){
    for (int i = 0; i < size; ++i) {
        cout<<arr[i]<<" ";
    }cout<<"\n";
}
int main()
{
    int arr[]={9,5,20,14,3};
    mergeSort(arr,0,4);
print(arr,5);
}