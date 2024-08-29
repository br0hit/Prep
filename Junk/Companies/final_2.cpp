#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl '\n'
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second

int mod = 1e9 + 7;
int solve(int i, string &s, char fr, char sec, int len, vector<vector<vector<vector<int>>>> &dp)
{
    if (len == 5)
        return 1;
    if (i == s.size())
        return 0;
    if (dp[fr - '0'][sec - '0'][len][i] != -1)
        return dp[fr - '0'][sec - '0'][len][i];

    long long op1 = 0, op2 = 0, op3 = 0, op4 = 0, op5 = 0;
    if (len == 0)
        op1 = solve(i + 1, s, s[i], sec, len + 1, dp);
    if (len == 1)
        op2 = solve(i + 1, s, fr, s[i], len + 1, dp);
    if (len == 2)
        op3 = solve(i + 1, s, fr, sec, len + 1, dp);
    if (len == 3 and s[i] == sec)
        op4 = solve(i + 1, s, fr, sec, len + 1, dp);
    if (len == 4 and s[i] == fr)
        op5 = solve(i + 1, s, fr, sec, len + 1, dp);
    long long op6 = solve(i + 1, s, fr, sec, len, dp);

    return dp[fr - '0'][sec - '0'][len][i] = (op1 + op2 + op3 + op4 + op5 + op6) % mod;
}
int countPalindromes(string s)
{
    vector<vector<vector<vector<int>>>> dp(10, vector<vector<vector<int>>>(10, vector<vector<int>>(5, vector<int>(s.size(), -1))));
    return solve(0, s, '1', '1', 0, dp);
}

int main()
{
    s ="01001"
}