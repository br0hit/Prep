#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl "\n"
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second
int i;

int modval = 1e9 + 7;

void solve()
{
    int n;
    vector<pair<int,int>>range(n,{0,0});

    vector<pair<int,int>> ff(2*n,{0,0});

    fr(i,0,n)
    { 
        cin>>range[i].F>>range[i].S;
        ff[2*i].F = range[i].F;
        ff[2*i].S = 0;
        ff[2*i+1].F = range[i].S;
        ff[2*i+1].S = 1;
    }

    sort()


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}