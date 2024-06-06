#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;

    vector<int> p(n+1,0);
    for(int i=1; i<=n; i++) cin>>p[i];

    sort(p.begin(),p.end());
    int val = (n+1)/2;

    int stickval = p[val];
    ll totalsum=0LL;

    for(int i=1; i<=n; i++)
    {
        totalsum += abs(stickval-p[i]);
    }

    cout<<totalsum<<endl;
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