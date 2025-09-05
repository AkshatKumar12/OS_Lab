#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

typedef class process{
    public:

    int pid,at,bt,p;
    int st,ct,wt,tat,rt;
}p;

p* maker()
{
    p *temp = new p();

    int pid,at,bt,p;
    cout<<"Enter pid, at, bt, p"<<endl; 
    cin>>pid>>at>>bt>>p;

    temp->pid = pid;
    temp->bt = bt;
    temp->at = at;
    temp->p = p;
}
int main()
{

    int n = 0;
    cout<<"Enter the number of processes: ";
    cin>>n;

    vector<p*>vec(n);

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the details for "<<i<<" process ";
        vec[i] = maker();
    }
}