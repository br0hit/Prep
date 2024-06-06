#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;

    vector<pair<int,int>> perm(n,{0,0});
    for(int i=0; i<n; i++)
    {
        cin>>perm[i].first;
        perm[i].second = i;
    }

    if(n==1)
    {
        cout<<1;
        return;
    }

    sort(perm.begin(),perm.end());

    int count=0;

    for(int i=0; i<n-1; i++)
    {
        if(perm[i+1].second<perm[i].second) 
        {
            count++;
        }
    }

    cout<<++count<<endl;
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