#include <iostream>
#include <vector>
using namespace std;

vector<int> count(vector<int> v) {
    //time complexity in all cases O(n+k) where k is the range of the array
    vector<int> sorted(v.size()),sum(10,0);
    for (auto x:v) {
        sum[x]++;

    }
int s=sum[0];
    for (int i=1;i<sum.size();i++) {
        s += sum[i];
        sum[i] = s;
    }

    for (int i = (v.size())-1;  i>=0 ; i--) {
        sum[v[i]]--;
        int ind = sum[v[i]];
        sorted[ind] = v[i];
    }

return sorted;
}

int main(){
    vector<int> v;

    v.push_back(4);
    v.push_back(8);
    v.push_back(4);
    v.push_back(2);
    v.push_back(9);
    v.push_back(9);
    v.push_back(6);
    v.push_back(2);
    v.push_back(9);
    for (auto x:v) {
        cout<<x<<" ";

    }cout<<endl;
    v=count(v);
    for (auto x:v) {
        cout<<x<<" ";

    }
}