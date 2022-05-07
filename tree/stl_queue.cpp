#include<iostream>
#include<queue>
using namespace std;
void show(queue<int>gp)           // here in this function there is a call by value called so change occur in this this remains here it doesnot
{                                // reflects in the actual queue because it is display function
    queue<int>g=gp;
    while(!g.empty())
    {
        cout<<"\t"<<g.front();
        g.pop();
    }
    cout<<endl;
}
int main()
{
    queue<int>g;
    g.push(10);
    g.push(20);
    g.push(30);
    cout<<g.front()<<endl;
    cout<<g.back()<<endl;
    show(g);
    g.pop();
    show(g);
    return 0;
}