//
// Created by DELL on 5/2/2024.
//
#include <iostream>
using namespace std;
template<class t>
class stack
{
    t * arr;
    int top;
public:
    stack(){
        top=-1;
        arr=new t[100];
    }
    void push(t x)
    {
        top++;
        arr[top]=x;
    }
    void pop()
    {   if(!isempty())
        {
        top--;
        }

    }
    bool isempty()
    {
        return top==-1;
    }
    t topele()
    {
        if(!isempty())
            return arr[top];
        return -1;
    }
    int length()
    {
        return top+1;
    }
};

int main(){

    stack<int> stk;

    cout<<"\nthe stack is empty? "<<stk.isempty();
    stk.push(4);
    stk.push(3);
    stk.push(2);
    stk.push(1);
    cout<<"\nthe stack is empty? "<<stk.isempty();
    cout<<"\n"<<stk.length();
    cout<<"\nthe elements in the stack are: \n";
    int length=stk.length();
    for (int i = 0; i <length ; ++i) {
        cout<<stk.topele()<<"\n";
        stk.pop();
    }
    cout<<"the stack is empty? "<<stk.isempty()<<"\n";
}