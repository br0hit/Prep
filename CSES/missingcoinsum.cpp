#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;

    vector<int> x(n,0);
    for(int i=0; i<n; i++) cin>>x[i];

    sort(x.begin(),x.end());

    set<int> genious;
    set<int> megagenius;
    int curr_val=1;

    genious.insert(x[0]);
    // cout << "Reached here" << endl;

    int midval;

    for(int i=1; i<n; i++)
    {
        midval=1;
        megagenius.insert(x[i]);
        for(auto u: genious)
        {
            if(u!=midval)
            {
                cout<<midval<<endl;
                return;
            }
            // cout<<u<<endl;
            megagenius.insert(u);
            megagenius.insert(x[i]+u);
            midval++;
        }
        genious = megagenius;
        megagenius.clear();   
    }

    int minval=1;

    for(auto u: genious)
    {
        // cout<<u<<endl;
        if(u==minval)
        {
            minval++;
        }
        else 
        {
            break;
        }
    }
    cout<<minval<<endl;
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