#include <iostream>
#include <cmath>
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
int priority(char r)
{
    if(r=='-'||r=='+')
        return 1;
    else if(r=='/'||r=='*')
        return 2;
    else if(r=='^')
        return 3;
    else
        return 0;
}
string to_postfix(string x)
{stack<char>c;
    string y;
    for (int i = 0; i < x.length(); ++i) {
        if(x[i]==' ')
            continue;
        else if(x[i]=='(')
            c.push(x[i]);
        else if(x[i]==')') {
            while (c.topele() != '(') {
                y.push_back(c.topele());
                c.pop();
            }
            c.pop();
        }
        else if(x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'||x[i]=='^')
        {

            while(!c.isempty()&& priority(x[i])<= priority(c.topele())){
                    y.push_back(c.topele());
                    c.pop();
                }
         c.push(x[i]);
        }
        else
            y.push_back(x[i]);
    }
   while(!c.isempty())
   {
       y.push_back(c.topele());
       c.pop();
   }
    return y;
}
float mathoperation(float f,float s,char o)
{
    if(o=='+')
        return (f+s);
    else if(o=='-')
        return (f-s);
    else if(o=='*')
        return (f*s);
    else if(o=='/')
        return (f/s);
    else if(o=='^')
        return pow(f,s);
    else
        return 0;
}
float evaluate_post(string x)//to make it work with prefix we will change small things
{stack<float>stk;
    for(int i=0;i<x.length();i++)//reversed for loop
    {
        if(x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'||x[i]=='^') {
            float f,s,r;
            s=stk.topele();//first element in the top
            stk.pop();

            f=stk.topele();//second element will be the second one
            stk.pop();

            r=mathoperation(f,s,x[i]);
            stk.push(r);
        }
        else{
            stk.push(x[i]-'0');
        }

    }
return stk.topele();

}
//function only works with numbers with one digit
int main()
{
    string j;
    j="(3+2)+7/2*((7+3)*2)";
    string p=to_postfix(j);
    cout<<p<<endl;
    cout<<evaluate_post(p); // 75
}