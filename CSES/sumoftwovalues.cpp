#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n,x;
    cin>>n>>x;

    vector<pair<int,int>> a(n,{0,0});
    for(int i=0; i<n; i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());

    int first=0, last=n-1;

    while(last>first)
    {
        int count = a[first].first + a[last].first;
        if(count==x)
        {
            cout << a[first].second + 1 << " " << a[last].second + 1 << endl;
            return;
        }
        else
        {
            if(count<x) first++;
            else last--;
        }
    }

    cout << "IMPOSSIBLE"<<endl;
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