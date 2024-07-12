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
    int n, x;
    cin >> n >> x;

    vector<pair<int,int>> a(n, {0,0});
    int i;
    fr(i, 0, n){
        cin >> a[i].F;
        a[i].S = i;
    }

    vector<pair<int,int>> b;
    fr(i, 0, n)
    {
        if (a[i].F <= x - 3)
        {
            b.push_back(a[i]);
        }
    }
    a.clear();
    a = b;
    n = b.size();

    sort(a.begin(),a.end());
    map<int, int> newmp;
    fr(i, 0, n) newmp[a[i].F] = i;

    if (n <= 3 || (n == 4 && a[0].F + a[1].F + a[2].F + a[3].F != x))
    {
        cout << "IMPOSSIBLE";
        return;
    }

    fr(i, 0, n)
    {
        int newtarget1 = x - a[i].F;
        if (newtarget1 < 3)
            continue;
        int index1 = i;

        // map<int,int> mp;

        for (int j = 0; j < n; j++)
        {
            if (j != index1)
            {
                int newtarget = newtarget1 - a[j].F;
                if (newtarget < 2)
                    continue;
                int index = j;

                for (int k = 0; k < n; k++)
                {
                    if (k != index && k != index1)
                    {
                        if (newtarget - a[k].F < 1)
                            continue;
                        if (newmp.find(newtarget - a[k].F) != newmp.end())
                        {
                            if (newmp[newtarget - a[k].F] != k)
                            {
                                cout << a[index1].S + 1 << " " << a[index].S + 1 << " " << a[newmp[newtarget - a[k].F]].S + 1 << " " << a[k].S + 1 << endl;
                                return;
                            }
                        }
                    }
                }

                // else
                // {
                //     mp[a[j]] = j;
                // }
            }
        }
    }

    cout << "IMPOSSIBLE";
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