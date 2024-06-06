#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n+1,0),b(n+1,0);
    for(int i=1; i<=n; i++) cin>>a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];


    int m;
    cin>>m;
    vector<int> d(m+1,0);
    for (int i = 1; i <= m; i++)
        cin >> d[i];

    vector<int> asorted(n + 1, 0), bsorted(n + 1, 0), dsorted(m+1,0);

    asorted = a;
    bsorted = b;
    dsorted = d;

    sort(asorted.begin(), asorted.end());
    sort(bsorted.begin(), bsorted.end());
    sort(dsorted.begin(), dsorted.end());

    int diffcount=0;
    vector<int> diffvals;


    for(int i=0; i<n; i++)
    {
        if(a[i+1]!=b[i+1])
        {
            diffcount++;
            diffvals.push_back(b[i+1]);
        } 
    }

    if(diffcount>m)
    {
        cout<<"NO"<<endl;
        return;
    }

    int lastval = d[m];
    if(!binary_search(bsorted.begin(), bsorted.end(), lastval))
    {
        // cout<<"C1NO"<<endl;
        cout << "NO" << endl;
        return;
    }

    sort(diffvals.begin(), diffvals.end());

    for(int i=0; i<diffcount; i++)
    {
        if(binary_search(dsorted.begin(), dsorted.end(), diffvals[i]))
        {
            int  pos = lower_bound(dsorted.begin(), dsorted.end(), diffvals[i]) - dsorted.begin();
            dsorted[pos] = dsorted[pos-1];
        }
        else
        {
            // cout<<"C2NO"<<diffvals[i]<<endl;
            cout << "NO" << endl;
            return;
        }
    }

    cout<<"YEs"<<endl;

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