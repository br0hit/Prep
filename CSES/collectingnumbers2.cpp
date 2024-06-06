#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n,m;
    cin >> n>>m;

    vector<pair<int, int>> perm(n, {0, 0});
    vector<pair<int, int>> org(n, {0, 0});

    vector<pair<int,int>> query(m,{0,0});

    for (int i = 0; i < n; i++)
    {
        cin >> perm[i].first;
        perm[i].second = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> query[i].first;
        cin>>query[i].second;
    }

    org = perm;
    sort(perm.begin(), perm.end());

    for(int k=0; k<m; k++)
    {
        if (n == 1)
        {
            cout << 1;
            continue;;
        }

        int count = 0;

        int temp = perm[org[query[k].first-1].first-1].second;
        perm[org[query[k].first - 1].first - 1].second = perm[org[query[k].second - 1].first - 1].second;
        perm[org[query[k].second - 1].first - 1].second = temp;

        for (int i = 0; i < n - 1; i++)
        {
            if (perm[i + 1].second < perm[i].second)
            {
                count++;
            }
        }
        cout << ++count << endl;
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