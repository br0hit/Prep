#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,f,k;
    cin>>n>>f>>k;

    vector<int> a(n,0);
    for(int i=0; i<n; i++) cin>>a[i];

    int indexval = a[f-1];

    int greatercount =0, equalcount=0, lessercount=0;

    for(int i=0; i<n; i++)
    {
        if(a[i]>indexval) greatercount++;
        if(a[i]==indexval) equalcount++;
        if(a[i]<indexval) lessercount++;
    }

    if(k<=greatercount)
    {
        cout<<"NO"<<endl;
        return;
    }

    if(k< greatercount+ equalcount)
    {
        cout<<"MAYBE"<<endl;
        return;
    }

    cout<<"YES"<<endl;
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