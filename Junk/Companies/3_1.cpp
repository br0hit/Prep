#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
#define lli long long int
#define nl '\n'
#define loop(i, start, end) for (i = start; i < end; ++i)
#define rloop(i, end) for (i = end; i >= 0; --i)
#define primary first
#define secondary second

string flip(string text)
{
    int left, right = text.length() - 1;
    for (left = 0; left < right; ++left, --right)
    {
        swap(text[left], text[right]);
    }
    return text;
}

lli memo[200001][5][2];

lli solve(int idx, string &str, int maximum, bool flag)
{
    int length = str.length();
    if (idx == length)
        return 0;
    if (memo[idx][maximum][flag] != -1)
        return memo[idx][maximum][flag];
    lli result = -1e18;
    lli values[5] = {1, 10, 100, 1000, 10000};
    if (flag)
    {
        int current = str[idx] - 'A';
        result = (maximum > current) ? -values[current] : values[current];
        result += solve(idx + 1, str, max(maximum, current), flag);
        memo[idx][maximum][flag] = result;
        return memo[idx][maximum][flag];
    }
    for (int k = 0; k < 5; ++k)
    {
        lli temp = (maximum > k) ? -values[k] : values[k];
        temp += solve(idx + 1, str, max(maximum, k), (str[idx] - 'A') != k);
        result = max(result, temp);
    }
    memo[idx][maximum][flag] = result;
    return result;
}

int main()
{
    string input;
    cin >> input;
    // A=0,B=1,C=2,D=3,E=4;
    int length = input.length();
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < 5; ++j)
            memo[i][j][0] = memo[i][j][1] = -1;
    }
    reverse(input.begin(), input.end());
    cout << solve(0, input, 0, 0);
    return 0;
}