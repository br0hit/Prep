#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[10000];
// int tree[40000];
vector<pair<int,int>> tree(40000,{0,0});

class node
{
    public:
    int minval;
    int count;

    node(int min=1e9, int count=0)
    {
        minval = min;
        count = count;
    }
};

void build(int index, int l, int r)
{
    if(l==r)
    {
        tree[index] = {arr[l],1};
        return;
    }

    int mid = (l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1,r);

    if(tree[2*index].first==tree[2*index+1].first)
    {
        tree[index].first = tree[2*index].first;
        tree[index].second = tree[2*index].second + tree[2*index+1].second;
    }
    else
    {
        if (tree[2 * index].first > tree[2 * index + 1].second)
        {
            tree[index].first = tree[2 * index+1].first;
            tree[index].second = tree[2 * index + 1].second;
        }
        else
        {
            tree[index].first = tree[2 * index ].first;
            tree[index].second = tree[2 * index].second;
        }
    }
}



void solve()
{

    int n;
    cin>>n;

    for(int i=0; i<n; i++) cin>>arr[i];

    build(1,0,n-1);

    for(int i=1; i<2*n; i++)
    {
        cout<<tree[i].first<<" "<<tree[i].second<<endl;
    }
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