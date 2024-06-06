#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;

    vector<ll> x(n,0);
    for(int i=0; i<n; i++) cin>>x[i];

    ll prevmaxsum= x[0];
    ll currmax=x[0];

    for(int i=1; i<n; i++)
    {
        if(prevmaxsum>0)
        {
            prevmaxsum+=x[i];
        }
        else
        {
            prevmaxsum = x[i];
        }

        currmax = max(currmax, prevmaxsum);
    }

    // currmax = max(currmax, prevmaxsum);
    cout<<currmax<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin >> t; while (t--)
    solve();
    return 0;
}