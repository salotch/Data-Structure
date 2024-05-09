//
// Created by DELL on 5/7/2024.
//
#include <iostream>
#include <vector>

using namespace std;
template <class t>
class graph{
    int size;
    int index;
    vector<t> *adj;

public:
    graph(int s){
        size=s;
        index=0;
        adj=new vector<t>[size];
    }
    void addNode(t data)
    {
        if(index<size) {
            adj[index].push_back(data);
        index++;
        }
    }
    void addEdge(int src,int dst)
    {
        if(size>src&&size>dst&&src>-1&&dst>-1)
        {
                    t data=adj[dst][0];
            adj[src].push_back(data);

        }
    }
    void print()
    {
        for (int i = 0; i < size; ++i) {
            for (auto j:adj[i]) {
                cout<<j<<"->";

            }cout<<endl;
        }
    }
};
int main()
{
    graph<char>g(6);
    g.addNode('A');
    g.addNode('B');
    g.addNode('C');
    g.addNode('D');
    g.addNode('E');
    g.addNode('F');
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.print();

}