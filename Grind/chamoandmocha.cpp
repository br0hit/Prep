#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n,0);
    for(int i=0; i<n; i++) cin>>a[i];

    int firstval = min(a[0],a[1]);

    vector<int> medarr;

    if(n==2)
    {
        cout<<firstval<<endl;
        return;
    }

    int l,r;
    int med,medmax=-1;

    deque<int> temp;


    for(int r=1; r<n; r++)
    {

    }

    
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