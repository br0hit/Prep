#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,m;
    cin>>n>>m;

    string s;
    cin>>s;

    vector<int> temp(7,0);

    for(int i=0; i<n; i++)
    {
        temp[s[i]-'A']++;
    }

    int sum=0;

    for(int i=0; i<7; i++)
    {
        int ans = m-temp[i];
        sum+= max(ans,0);
    }

    cout<<sum<<endl;
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