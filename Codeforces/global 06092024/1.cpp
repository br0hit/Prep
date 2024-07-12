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
    cin>>n;

    vector<int> a(n,0);
    int i;
    fr(i,0,n) cin>>a[i];

    int val = a[0];
    if(upper_bound(a.begin(),a.end(),val)==a.end())
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    if(a[0]==a[n-2])
    {
        cout<<"R";
        fr(i,1,n)cout<<"B";
        cout<<endl;
    }
    else
    {
        fr(i, 0, n - 1) cout << "R";
        cout << "B" << endl;
    }

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