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
    int n;
    cin>>n;

    vector<pair<int,int>> dates(n+1,{0,0});
    vector<pair<int,int>> vi(2*n+1,{0,0});
    int i;
    fr(i,1,n+1)
    {
        cin>>dates[i].F>>dates[i].S;
        vi[2*i-1].F=dates[i].F;
        vi[2*i-1].S=-i;
        vi[2*i].F = dates[i].S;
        vi[2*i].S = i;
    }   

    stack<int> rooms;
    unordered_map<int,int> mp;

    sort(vi.begin()+1,vi.end());

    int count=1;
    vector<pair<int,int>> ans;

    fr(i,1,2*n+1)
    {
        if(vi[i].S<0)
        {
            if (rooms.empty())
            {
                rooms.push(count);
                count++;
            }

            // cout << vi[i].F << " " << vi[i].S << " " << rooms.top();

            mp[vi[i].S] = rooms.top();
            ans.push_back({-vi[i].S,rooms.top()});
            rooms.pop();

        }
        else
        {
            int emptyroom = mp[-vi[i].S];
            // cout << vi[i].F << " " << vi[i].S << " " << emptyroom;
            rooms.push(emptyroom);
        }
    }

    sort(ans.begin(),ans.end());

    cout<<count-1<<endl;
    fr(i,0,ans.size()) cout<<ans[i].S<<" ";

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