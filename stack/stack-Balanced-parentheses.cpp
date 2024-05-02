//
// Created by DELL on 5/2/2024.
//
#include<iostream>
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
bool pairs(char o,char c)
{
    if ((o == '(' && c == ')')||(o == '{' && c == '}')||(o == '[' && c == ']')){
        return true;
    }
    return false;
}
bool balanced(string x)
{
    stack<char> open;

    for (int i = 0; i < x.length(); ++i) {
        if(x[i]=='('||x[i]=='{'||x[i]=='[')
            open.push(x[i]);
        else if(x[i]==')'||x[i]=='}'||x[i]==']')
        {
            if(open.isempty()||pairs(open.topele(),x[i]) == false)
                return false;
            else
            {
                open.pop();
            }
        }
    }
    if(open.isempty())
        return true;
    else
        return false;

}
int main()
{
    string b;
    cin>>b;
    cout<<balanced(b);

}