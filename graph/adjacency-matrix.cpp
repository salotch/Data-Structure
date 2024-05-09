//
// Created by DELL on 5/6/2024.
//
#include <iostream>
#include<queue>
using namespace std;
char heart = 3;
template<class t>
class graph{
    int size;
    int index;
    int ** matrix;
    t* data;
    queue<int>q;
    bool *visited;

public:
    graph(int s){
        size=s;
        index=0;
        matrix=new int*[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = 0;
            }
        }
        data=new t[size];
        visited =new bool[size];
        for (int i = 0; i < size; ++i) {
            visited[i] =false;
        }
    }
    void addNode(t d)
    {
        if(index<size)
        {
        data[index]=d;
        visited[index]=false;
        index++;
        }
    }
void addEdge(int src,int dst)
{
        if(src<size&&dst<size)
            matrix[src][dst]=1;
}
bool checkEdge(int src,int dst)
{
        if(src<size&&dst<size)
            return matrix[src][dst]==1;
        else
            return false;
}
void print()
{
        cout<<"  ";
    for (int i = 0; i < index; ++i) {
        cout<<data[i]<<" ";
    }cout<<endl;
    for (int i = 0; i < index; ++i) {
        cout<<data[i]<<" ";
        for (int j = 0; j < index; ++j) {
            if(matrix[i][j]==1)
                cout<<heart<<" ";
            else
                cout<<"  ";
        }cout<<endl;
    }
}
void depthSearchFirst(int src)
{
    if(visited[src])
        return;
    visited[src]=true;
    cout<<data[src]<<" = visited\n";
    for (int i = 0; i <= index; ++i) {
        if(matrix[src][i]==1)
        {
            depthSearchFirst(i);
        }
    }
}
void breadthSearchFirst(int src)
{
    if(visited[src])
        return;
    visited[src]=true;
    cout<<data[src]<<" = visited\n";
    for(int i=0;i<size;i++)
    {
        if(matrix[src][i]==1&&!visited[i])
        {  q.push(i);
        }
    }
    while(q.size()>0)
    {
        int x=q.front();
        q.pop();
        breadthSearchFirst(x);
    }
}
};
int main() {
    graph<char> g(5);
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
    g.addEdge(3, 4);

    g.print();
  g.breadthSearchFirst(0);
}