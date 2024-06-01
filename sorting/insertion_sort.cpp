#include <iostream>
#include <vector>

using namespace std;
void insertion(vector<int> &v)
{// best case O(n)
// worst and average case O(n^2)
    for (int i = 1; i < v.size(); ++i) {
        int key=v[i];
        int j=i-1;
        while(j>=0 && v[j]>key)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
    }
}
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(90);
    v.push_back(60);
    v.push_back(3);
    v.push_back(1);
    v.push_back(45);
    v.push_back(56);
    v.push_back(98);
    for (auto x:v) {
        cout<<x<<" ";

    }cout<<endl;
    insertion(v);
    for (auto x:v) {
        cout<<x<<" ";

    }
}