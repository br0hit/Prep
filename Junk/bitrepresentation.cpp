#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x=43;
    int k=0;
    int y;

    for(int i=10; i>=0; i--)
    {
        if(x&(1<<i)) cout<<1;
        else cout<<0;
    }

    cout<<endl<<__builtin_clz(x)<<endl;
    cout<<__builtin_ctz(x)<<endl;
    cout<<__builtin_popcount(x)<<endl;

    int set=0;

    set|=1<<1;
    set|=1<<3;
    set|=1<<4;
    set|=1<<8;
    cout<<set<<" "<<__builtin_popcount(set)<<endl;

    for(int i=0; i<32;i++)
    {
        if(set&(1<<i)) cout<<i<<endl;
    }

    return 0;


}