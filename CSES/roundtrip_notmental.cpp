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

int dfs(int node, int prevnode, vector<int> gr[], vector<int> &visited, vector<int> &visited_new, vector<int> &child, int &count )
{   
    if(!visited_new[node]) visited_new[node]++;

   //  cout<<node<<" "<<prevnode<<" "<<count<<endl;

    count++;
    visited[node]+=1;
    child[prevnode] = node;

    if(visited[node]==2 && count>=3)
    {
        return node;
    }
    else if(visited[node]==2)
    {
        return 0;
    }

    for(auto u: gr[node])
    {
        if(u!= prevnode)
        {
            int ans = dfs(u, node, gr, visited, visited_new, child, count);
            if(ans>0) return ans;
            count--;
            visited[node]--;
        }
    }

    return 0;
}


void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int> gr[n+1];

    int i;
    fr(i,0,m)
    {
        int val1,val2;
        cin>>val1>>val2;

        gr[val1].push_back(val2);
        gr[val2].push_back(val1);
    }
    vector<int> visited_new(n + 1, 0);

    int count;
    int ans;
    stack<int> finalans;

    vector<int> visited(n + 1, 0);
    vector<int> child(n + 1, 0);

    // cout<<"start"<<endl;

    fr(i,1,n+1)
    {
        count=0;

        if(!visited_new[i])
        {
            ans = dfs(i,0, gr, visited, visited_new, child, count);
            int temp = ans;
            if(ans!=0)
            {
                // cout<<"here"<<temp<<endl;
                while(1)
                {
                    finalans.push(ans);
                    ans = child[ans];
                    if (ans == temp)
                    {
                        // cout << ans << " ";
                        finalans.push(ans);
                        break;
                    }
                }
                break;

            }
        }
    }

    if(finalans.size()==0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    } 
    else
    {
        cout<<finalans.size()<<endl;
        while(!finalans.empty())
        {
            cout<<finalans.top()<<" ";
            finalans.pop();
        }
    }

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       solve();
}