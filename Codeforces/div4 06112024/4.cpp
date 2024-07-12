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
    int n,m;
    cin>>n>>m;

    vector<vector<char>> arr(n+1, vector<char>(m+1,0));
    int i,j;
    set<int> row, column;

    fr(i,1,n+1)
    {
        fr(j,1,m+1)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='#') row.insert(i);
        }
    }

    int size = (row.size()+1)/2;
    int val;


    for(auto u: row)
    {
       //  cout<<u<<" "<<size<<endl;
        size--;
        if(size==0)
        {
            val = u;
            break;
        }
    }

    fr(i,1,m+1)
    {
        if(arr[val][i]=='#') column.insert(i);
    }

    size = (column.size() + 1) / 2;
    int colval;
    for (auto u : column)
    {
        size--;
        if (size == 0)
        {
            colval = u;
            break;
        }
    }

    cout<<val<<" "<<colval<<endl;

    // fr(i, 1, n + 1)
    // {
    //     fr(j, 1, m + 1)
    //     {    
    //         if(arr[i][j]=='#')
    //         {

    //         }
    //     }
    // }
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