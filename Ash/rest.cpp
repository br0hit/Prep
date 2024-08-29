#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl '\n'
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second
int modval = 1e9 + 7;


void solve()
{
    int n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        arr.push_back(a[i]);
        arr.push_back(b[i]);
    }
    sort(arr.begin(),arr.end());
    


}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
}