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

    sort(h.begin(),h.end());

    for(int i=0; i<m; i++)
    {
        int index;
        index = upper_bound(h.begin(),h.end(), t[i]) - h.begin();
        // if(h[index]!=t[i]) index--;
        index--;

       // cout << index << endl;

        // while(visit[index]==1 && index>=0)
        // {
        //     index--;
        // }
      //  cout << index << endl;
      
        if(index<0) index=0;
        if((index==0) && visit[index]==0)
        {
            cout<<h[index]<<endl;
            visit[index]=1;
            continue;
        } 
        else if(index==0)
        {
            cout<<-1<<endl;
            continue;
        }

        if(index==n-1 && visit[index]==1)
        {
            cout<<-1<<endl;
            continue;
        }

        cout<<h[index]<<endl;
        visit[index]=1;
        if(index!= n-1) h[index] = h[index+1];
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