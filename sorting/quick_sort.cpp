//
// Created by DELL on 5/8/2024.
//quick sort it is in place but sitll has space complexity O(log n)as best and
// average case and O(n)as worst case
// and has time complexity with best and average case O(n log n) and worst O(n2)
#include <iostream>
using namespace std;
void quickSort(int*arr,int left,int right){
    int pivot=(right+left)/2;
    int i=left,j=right;
    while(i<=j)
    {
        if(arr[pivot]>arr[i])
            i++;
        else if(arr[pivot]<arr[j])
            j--;
        else
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j--;
            i++;
        }
    }
    if(i<right)
        quickSort(arr,i,right);
    if(j>left)
        quickSort(arr,left,j);

}
void print(int*arr,int size){
    for (int i = 0; i < size; ++i) {
        cout<<arr[i]<<" ";
    }cout<<"\n";
}
int main()
{
    int arr[]={9,5,20,14,3};
   quickSort(arr,0,4);
    print(arr,5);
}