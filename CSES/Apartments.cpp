#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n,0);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> b(m, 0);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int count=0;
    int curra=0;
    int i=0;

    while(1)
    {
        if(i>=m || curra >= n) break;
        
        if(b[i]>=a[curra]-k && b[i]<=a[curra]+k)
        {
            i++;
            curra++;
            count++;
        }
        else 
        {
            if(b[i]<a[curra]+k) i++;
            else curra++;
        }
    }

    cout<<count<<endl;
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