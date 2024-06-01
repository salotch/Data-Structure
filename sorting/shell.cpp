#include <iostream>
#include <vector>
using namespace std;

void shell(vector<int>& v) {
    //time complexity best average O(n log n)
    //worst O(n^2)
    for (int gap = v.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < v.size(); ++i) {
            int key = v[i];
            int j = i;
            while (j >= gap && v[j - gap] > key) {
                v[j] = v[j - gap];
                j -= gap;
            }
            v[j] = key;
        }
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
//    v.push_back(98);
    for (auto x:v) {
        cout<<x<<" ";

    }cout<<endl;
    shell(v);
    for (auto x:v) {
        cout<<x<<" ";

    }
}