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

int modval = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> gr[n + 1];
    int i;
    fr(i, 0, m)
    {
        int val1, val2;
        cin >> val1 >> val2;

        gr[val1].push_back(val2);
        gr[val2].push_back(val1);
    }
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