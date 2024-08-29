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


void solve()
{
    string s,t;
    cin>>s>>t;

    int cond = 0;
    int pos, newpos;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==t[0] || s[i]=='?')
        {
            if(t.size()==1) 
            { 
                cond=1;
            }

            for(int j=1; j<t.size(); j++)
            {
                if(i+j>=s.size())
                {
                    break;
                }

                if(s[i+j]==t[j]) 
                {
                    if(j==t.size()-1)
                    {
                        cond=1;
                        break;
                    }
                    continue;
                }
                else if(s[i+j]=='?')
                {
                    // s[i+j] = t[j];
                    if(j==t.size()-1)
                    {
                        cond = 1;
                        break;
                    }

                }
                else break;
            }
        }

        if(cond==1)
        {
            for(int pos=0; pos<t.size(); pos++)
            {
                s[i+pos] = t[pos];
            }

            for(int j=i+t.size(); j<s.size(); j++)
            {
                if(s[j]=='?') s[j]='a';
            }

            cout<<"yes"<<endl;
            cout<<s<<endl;
            return;
        }
    }

    cout<<"no"<<endl;

}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;cin>>t;while(t--)
       solve();
}