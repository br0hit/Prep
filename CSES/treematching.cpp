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

int findval(int node, int parent, vector<int> gr[], vector<int>&matching, map<int,int> &mp)
{
    mp[node] = 1;
    queue<int> qu;
    qu.push(node);
    mp[node]++;
    int count=0;
    int totalcount=0;

    while(!qu.empty())
    {
        int n=qu.size();
        int i;
        fr(i,0,n)
        {
            int val = qu.front();
            qu.pop();
            //cout<<val<<endl;

            for(auto u: gr[val])
            {
                //cout<<u<<" ";
                if(mp.count(u)==0)
                {
                    qu.push(u);
                    mp[u]++;
                    if(count%2==0) totalcount++;
                }
            
            }
            //cout<<endl;
        }
        count++;
    }

    return totalcount;
}


void solve()
{
    int n;
    cin>>n;

    vector<int> gr[n+1];
    int i;
    fr(i,0,n-1) 
    {
        int t1,t2;
        cin>>t1>>t2;

        gr[t1].push_back(t2);
        gr[t2].push_back(t1);
    }

    vector<int> matching(n+1,0);

    fr(i,0,n)
    {
        map<int, int> mp;
        cout<<findval(i+1, 0, gr, matching, mp)<<endl;
    }

}


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
       return 0;
}