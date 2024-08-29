#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl '\n'
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second
int modval = 1e9 + 7;


void solve()
{
    int n;
    cin >> n;

    vector<int> gr[n + 1];
    int i;
    fr(i, 0, n - 1)
    {
        int t1, t2;
        cin >> t1 >> t2;

        gr[t1].push_back(t2);
        gr[t2].push_back(t1);
    }

    
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
}