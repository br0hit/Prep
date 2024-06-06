#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n,0);
    for(int i=0; i<n; i++) cin>>a[i];

    if(n==2)
    {
        cout<<"yes"<<endl;
        return;
    }

    int testval = 0;
    int ans=0;

    for(int i=0; i<n-1; i++)
    {
        if(testval==0)
        {
            if(a[i+1]<a[i])
            {
                testval=1;
                continue;
            }
        }

        if(testval==1)
        {
            if(a[i+1]<a[i])
            {
                ans=1;
                break;
            }
        }

        // cout<<a[i]<<" "<<testval<<" "<<ans<<endl;
    }

    if(testval==1 ) 
    { if(a[0]<a[n-1]) ans=1; }

    if(ans==0)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--)
    solve();
    return 0;
}

// vector<pair<int,int>> thop(n,{0,0});

// for(int i=0; i<n; i++)
// {
//     thop[i].first = a[i];
//     thop[i].second = i;
// }

// sort(thop.begin(), thop.end());

// for(int i=0; i<n; i++)
// {
//     cout<<thop[i].first<<" "<<thop[i].second<<endl;
// }
