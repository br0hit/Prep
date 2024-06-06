#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> median(n,0);
    
    for(int i=1; i<n; i++)
    {
        if()
    }



    // sort(a.begin(),a.end());
    int maxval = a[0];

    for(int i=0; i<n-1; i++)
    {
        if(a[i]<a[i+1])
        {
            if(a[i]>maxval) maxval = a[i];
        }
        else if(a[i]>a[i+1])
        {
            if(a[i+1]>maxval) maxval = a[i+1];
        }
    }

    int ans = maxval;
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--)
    solve();
    return 0;
}