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
    cin>>n;

    vector<pair<string,string>> data;

    for(int i=0; i<n; i++)
    {
        string father, child;
        cin>>father>>child;

        data.push_back({father,child});
    }

    map<string,vector<string>> gr;
    map<string, int> mp;

    for(int i=0; i<n; i++)
    {
        auto u = data[i];
        string father = u.first;
        string child = u.second;

        gr[father].push_back(child);
        mp[child]++;
    }

    for(auto u: gr)
    {
        string father = u.first;
        int no_children = u.second.size();

        if(mp[father]==0)
        {
            cout<<father<<endl;
            cout<<(n-no_children)<<endl;
        }
    }

    return;





}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}