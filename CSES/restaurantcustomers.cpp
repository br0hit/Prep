#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;

    vector<pair<int,int>> time(2*n,{0,0});
    vector<vector<int>> timeeach(n, vector<int>(2,0));

    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;

        time[2*i].first = a;
        time[2*i].second = 0;
        time[2*i+1].first = b;
        time[2*i+1].second = 1;

        timeeach[i][0] =a;
        timeeach[i][1] = b;
    }

    sort(time.begin(),time.end());

    int curr_max=0,maxval=-1;

    for(int i=0; i<2*n; i++)
    {
        if(time[i].second==0) curr_max++;
        else curr_max--;

        maxval = max(maxval, curr_max);
    }

    cout<<maxval<<endl;
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