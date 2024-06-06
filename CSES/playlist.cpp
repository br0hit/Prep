#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin>>n;

    vector<int> k(n,0);
    for(int i=0; i<n; i++) cin>>k[i];

    map<int, int> map;
    int first=0, last=0;    

    int curr_size = 0, maxsize = -1;

    for (int i = 0; i < n; i++)
    {
        if (map.count(k[i]) == 0 || (map[k[i]]<first))
        {
            map[k[i]] = i;
            curr_size++;
        }
        else
        {
            maxsize = max(maxsize, curr_size);
            first = map[k[i]]+1;
            map[k[i]] = i;
            curr_size = i-first+1;
        }
    }
    maxsize = max(maxsize, curr_size);
    cout << maxsize;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    solve();    
    return 0;
}