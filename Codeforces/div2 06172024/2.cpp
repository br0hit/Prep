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
    ll n,a,b;
    cin>>n>>a>>b;


    ll i;
    i = b-a;

    if(i>n) i=n; if(i<0) i=0;
    ll tempprofit = (b + 1) * i - (i * (i + 1)) / 2 + (n - i) * a;
    i = b-a+1;
    if(i>n) i=n; if(i<0) i=0;
    ll profit = (b + 1) * i - (i * (i + 1)) / 2 + (n - i) * a;
    profit = max(profit, tempprofit);

    cout<<profit<<endl;
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