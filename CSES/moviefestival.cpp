#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    vector<pair<int,int>> movie(n,{0,0});
    for(int i=0; i<n; i++)
    {
        cin>>movie[i].second>>movie[i].first;
    }

    sort(movie.begin(), movie.end());

    int maxcount=1;
    int curr_index=0;

    for(int i=1; i<n; i++)
    {
        if(movie[i].second>=movie[curr_index].first)
        {
            curr_index=i;
            maxcount++;
        }
    }

    cout<<maxcount<<endl;   


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