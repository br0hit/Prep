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

int specialSubsequence(string &s)
{
    const int MOD = 1e9 + 7;
    int n = s.size();

    // Count of 0's , 1's , 00's , 11's , 01's and 10's

    // Of left side
    int left0 = 0, left00 = 0;
    int left1 = 0, left11 = 0;
    int left01 = 0, left10 = 0;

    // Of right side
    int right0 = 0, right00 = 0;
    int right1 = 0, right11 = 0;
    int right01 = 0, right10 = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            right00 += right0;
            right01 += right1;
            right0 += 1;
        }
        else
        {
            right11 += right1;
            right10 += right0;
            right1 += 1;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        // Updating the right Part
        if (s[i] == '0')
        {
            right0 -= 1;
            right00 -= right0;
            right01 -= right1;
        }
        else
        {
            right1 -= 1;
            right11 -= right1;
            right10 -= right0;
        }
        // couting possible pallidromes

        //   00_00
        res = (0LL + res + 1LL * left00 * right00 % MOD) % MOD;
        //   11_11
        res = (0LL + res + 1LL * left11 * right11 % MOD) % MOD;
        //   01_10
        res = (0LL + res + 1LL * left01 * right10 % MOD) % MOD;
        //  10_01
        res = (0LL + res + 1LL * left10 * right01 % MOD) % MOD;

        // Updating the Left Part

        if (s[i] == '0')
        {
            left00 += left0;
            left10 += left1;
            left0 += 1;
        }
        else
        {
            left11 += left1;
            left01 += left0;
            left1 += 1;
        }
    }
    
    return res ;
}

void solve()
{
    string s = "0100110";
    int ans = specialSubsequence(s);

    cout<<ans<<endl;
}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // int t;cin>>t;while(t--)
       solve();
}