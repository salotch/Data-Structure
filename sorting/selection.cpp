#include <iostream>
#include <vector>
using namespace std;
void selection(vector<int>&v)
{
// time complexity in all cases are O(n^2)
    for (int i = 0; i < v.size(); ++i) {
      int min=i;
        for (int j = i+1; j <v.size() ; ++j) {
            if(v[min]>v[j])
            {
                int t=v[min];
                v[min]=v[j];
                v[j]=t;
            }
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
    selection(v);
    for (auto x:v) {
        cout<<x<<" ";

    }
}