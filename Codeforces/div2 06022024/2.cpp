#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,m;
    cin>>n>>m;

    // int temp = n-m;
    // if(temp<0) temp=0;
    // int maxval = n+m;

    // int count=0;

    // cout<<"here"<<endl;

    // while((n+m)/(1<<count))
    // {
    //     count++;
    // }

    // if((n+m)%(1<<(count-1))==0) count--;
    // cout<<count<<endl;
    // int val=0;

    // for(int i=0; i<count+1; i++)
    // {
    //     val = val|(1<<i);
    // }

    // int ans = val;

    // cout<<ans<<" "<<val<<endl;

    // for(int i=n+m+1; i<=val; i++)
    // {
    //     ans = ans^i;
    // }

    // for(int i=0; i<n-m; i++)
    // {
    //     cout<<"Negative"<<endl;
    //     ans = ans^i;
    // }

    int lower = n-m;
    int upper = n+m;

    int lower2power=0, upper2power=0;

    while(upper/(1<<upper2power))
    {
        upper2power++;
    }
    upper2power--;

    if(n-m<0) lower2power=0;
    else
    {

        while (lower / (1 << lower2power))
        {
            lower2power++;
        }
        lower2power--;
    }


    int val=0;
    for(int i=lower2power; i<= upper2power; i++)
    {
        val|(1<<(i));
    }

    int ans = val;

    for(int i=(1<<upper2power)+1; i<= upper; i++)
    {
        ans = ans|i;
    }

    for(int i=lower; i<(1<<lower2power); i++)
    {
        ans =ans|i;
    }

    // int ans=0;

    // for(int i=temp; i<n+m+1; i++)
    // {
    //     ans = ans|i;
    // }

    cout<<ans<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}