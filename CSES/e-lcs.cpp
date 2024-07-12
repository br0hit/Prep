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
int i;

int modval = 1e9 + 7;

void solve()
{
    string s,t;
    cin>>s>>t;

    int l1= s.size();
    int l2 = t.size();

    vector<vector<int>> dp(l1+1, vector<int>(l2+1,0));
    vector<vector<pair<int,int>>> vals(l1+1, vector<pair<int,int>>(l2+1));


    int temp=0;

    for(int i=1; i<l2+1; i++)
    {
        if(temp==0)
        {
            if (t[i-1]==s[0])
            {
                dp[1][i] = 1;
                temp=1; 
            }
            else dp[1][i] =0;
        }
        else dp[1][i] =1;
    }
    temp=0;
    for (int i = 1; i < l1 + 1; i++)
    {
        if (temp == 0)
        {
            if (s[i - 1] == t[0])
            {
                dp[i][1] = 1;
                temp = 1;
            }
            else
                dp[i][1] = 0;
        }
        else
            dp[i][1] = 1;
    }

    for(int i=2; i<l1+1; i++)
    {
        for(int j=2; j<l2+1; j++)
        {
            int val1 = -1;
            if(s[i-1]==t[j-1])
            {
                val1 = dp[i-1][j-1]+1;
            }

            pair<int,int> temp;
            int ans;

            int val2 = dp[i-1][j];
            int val3 = dp[i][j-1];

            if(val2>val3)
            {
                ans = val2;
                temp.first = i-1;
                temp.second = j;
            }
            else
            {
                ans = val3;
                temp.first = i;
                temp.second = j-1;
            }

            if(val1>ans)
            {
                ans = val1;
                temp.first = i-1;
                temp.second = j-1;
            }

            // int ans = max(val2,val3);
            // ans = max(ans, val1);

            dp[i][j] = ans;
            vals[i][j] = temp;
        }
    }

    //cout << dp[l1][l2] << endl;

    pair<int,int> anspair; 
    stack<char> ans;

    while(1)
    {
        anspair = vals[l1][l2];
        int x = anspair.first;
        int y = anspair.second;

        //  cout << "(" << l1 << l2 << ")" << "(" << x << y << ")" << endl;

        if(l2==1)
        {
            if(dp[l1][l2]==1)
            {
                ans.push(t[l2-1]);
                break;
            }
            else break;
        }

        if (l1 == 1)
        {
            if (dp[l1][l2] == 1)
            {
                ans.push(s[l1 - 1]);
                break;
            }
            else
                break;
        }


        if (x == l1 - 1 && y == l2 - 1)
        {
            ans.push(s[l1 - 1]);
        }

        if (x == 0 && y == 0)
        {
            break;
        }


        l1 = x;
        l2 = y;
    }

    while(!ans.empty())
    {
        cout<<ans.top();
        ans.pop();
    }



}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}