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

int check(int i, int j, vector<vector<int>> m)
{
    int val=m[i][j];

    int val1 = m[i-1][j];
    int val2 = m[i+1][j];
    int val3 = m[i][j-1];
    int val4 = m[i][j+1];

    // if(val==val1 || val==val2 || val==val3 || val==val4) return 0;

    int maxval=0;
    maxval = max(maxval,val1);
    maxval = max(maxval, val2);
    maxval = max(maxval, val3);
    maxval = max(maxval, val4);

    if(m[i][j] > maxval) return maxval;
    else return 0; 
}

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n+2,vector<int>(m+2,0));

    int i,j;

    fr(i,1,n+1) fr(j,1,m+1) cin>>a[i][j];

    int tempval;

    // while(1)
    {
        tempval=-1;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                int ans = check(i, j, a);
                if (ans == 0)
                    continue;
                else
                {
                    a[i][j] = ans;
                    j++;
                    tempval=0;
                }
            }
        }
        //if(tempval==-1) break;
    }


    fr(i, 1, n + 1)
    {
        fr(j, 1, m + 1)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t; while (t--)
    solve();
    return 0;
}