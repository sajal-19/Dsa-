// program to demonstrate the stack stl here
#include<iostream>
#include<stack>
using namespace std;
void show(stack<int>st)
{
    stack<int>s=st;
    while(!s.empty())
    {
        cout<<"\t"<<s.top();
        s.pop();
    }
    cout<<endl;
}
int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    show(s);
    s.pop();
    show(s);
    return 0;
}