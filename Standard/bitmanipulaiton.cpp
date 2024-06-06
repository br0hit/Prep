#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    // Funcitons which you keep forgetting 
    int n;
    // cin>>n;
    n=5;

    int count=0;
    while(n/(1<<count))
    {
        cout<<n%(1<<count);
        count++;
    }

    cout<<endl<<__builtin_popcount(5);
    cout<<endl<<__builtin_clz(5);
    cout<<endl<<__builtin_ctz(5);

    // Learn how negative integers are represented in c++
    /*
        Lastbit=1;
        to get the negative number, take the 1's complement of the remaning number and add 1
        -( this number ) is the negative number, THis is also called the 2's complement of the number  
    */
    for(int i=2,ans=1; i<=12; i++)
    {
        ans^=i;
        cout<<ans<<" ";
    }

    for(int mask=0; mask<(1<<n);mask++)
    {
        bitset<5>temp = mask;
        cout<<temp<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin>>t; while(t--)
    solve();
    return 0;
}