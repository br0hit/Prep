#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int> h(n,0),t(m,0);
    vector<int> visit(n,0);

    for(int i=0; i<n; i++) cin>>h[i];
    for(int i=0; i<m; i++) cin>>t[i];

    // multiset<int> bigbrain;
    list<int> bigbrain;

    for(int i=0; i<n; i++) bigbrain.push_back(h[i]);

    sort(h.begin(),h.end());

    for(int i=0; i<m; i++)
    {
        if(bigbrain.size()==0)
        {
            cout<<-1<<" ";
            continue;
        }
        auto index = lower_bound(bigbrain.begin(), bigbrain.end(), t[i]);
        // if(h[index]!=t[i]) index--;
        if(index==bigbrain.begin())
        {
            if(*index>t[i])
            {
                cout<<-1<<" ";
            }
            else
            {
                cout << *index << " ";
                bigbrain.erase(index);
            }
        }
        else
        {
            if(index==bigbrain.end()) index--;
            else
            if (*index > t[i])
                index--;
            cout << *index << " ";
            bigbrain.erase(index);
        }
       // cout << index << endl;

        // while(visit[index]==1 && index>=0)
        // {
        //     index--;
        // }
      //  cout << index << endl;
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