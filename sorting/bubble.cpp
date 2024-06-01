#include <iostream>
#include <vector>
using namespace std;

void bubble(vector<int>& v) {
    //time complexity best O(n)
    //worst average O(n^2)
    bool flag=true;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 1; j < v.size(); ++j) {
            if(v[j]<v[j-1])
            {
                int t=v[j];
                v[j]=v[j-1];
                v[j-1]=t;
            flag=false;
            }
        }
        if(flag)
        {
            break;
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
    v.push_back(98);
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(4);
    for (auto x:v) {
        cout<<x<<" ";

    }cout<<endl;
    bubble(v);
    for (auto x:v) {
        cout<<x<<" ";

    }
}