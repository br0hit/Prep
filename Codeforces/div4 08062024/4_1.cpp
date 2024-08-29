#include <bits/stdc++.h>
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
    string s, t;
    cin >> s >> t;

    int cond = 0;
    int pos, newpos;

    int tpos = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == t[tpos])
        {
            tpos++;
        }
        else if(s[i]=='?')
        {
            s[i] = t[tpos];
            tpos++;
        }

        if(tpos==t.size())
        {
            cond=1;
            pos = i;
            break;
        }
    }

    if(cond==1)
    {
        for(int i=pos+1; i<s.size(); i++)
        {
            if(s[i]=='?') s[i]='a';
        }

        cout<<"yes"<<endl;
        cout<<s<<endl;
        return;
    }

    cout << "no" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}