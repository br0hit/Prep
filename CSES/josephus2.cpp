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

int modval = 1e9 + 7;

void solve()
{
    int n,k;
    cin>>n>>k; 
    int i;


    list<int> li;

    fr(i,1,n+1) li.push_back(i);
    int count=0;

    while(!li.empty())
    {
        // cout<<"round"<<endl;
        for(auto u=li.begin(); u!=li.end(); u++)
        {
            if(count==k)
            {
                cout<<*u<<" ";
                auto v = u;
                li.erase(v);
                if(li.empty())
                {
                    return;
                }
                count=0;
            }
            else count++;
        }
    }

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