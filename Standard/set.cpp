#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    set<int> testing;
    testing.insert(1);
    testing.insert(2);
    testing.insert(3);

    for(auto u: testing)
    {
        cout<<u<<" ";
    }

    auto ans = testing.find(1);
    if(ans==testing.end()) cout<<"Element not found";

    cout<<endl<<*ans;

    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);

    cout<<"Done with dequeue "<<dq[0];

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin>>t; while(t--)
    solve();
    return 0;
}