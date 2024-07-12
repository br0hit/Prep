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

    vi a(n, 0);
    int i;
    fr(i, 0, n) cin >> a[i];

    // sort(a.begin(),a.end());
    unordered_map<int, int> newmp;
    fr(i, 0, n) newmp[a[i]] = i;

    if (n <= 3 || (n == 4 && a[0] + a[1] + a[2] + a[3] != x))
    {
        cout << "IMPOSSIBLE";
        return;
    }

    fr(i, 0, n)
    {
        int newtarget1 = x - a[i];
        if(newtarget1<3) continue;
        int index1 = i;

        // map<int,int> mp;

        for (int j = 0; j < n; j++)
        {
            if (j != index1)
            {
                int newtarget = newtarget1-a[j];
                if(newtarget<2) continue;
                int index = j;

                for(int k=0; k<n; k++)
                {
                    if(k!= index && k!= index1)
                    {
                        if(newtarget-a[k]<1) continue;
                        if (newmp.find(newtarget - a[k]) != newmp.end())
                        {
                           if (newmp[newtarget - a[k]]!=k)
                           {
                               cout << index1 + 1 << " " << index + 1 << " " << newmp[newtarget - a[k]] + 1 << " " << k + 1 << endl;
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