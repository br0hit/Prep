#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define nl '\n'
#define loop(i, a, n) for (i = a; i < n; i++)
#define rloop(i, n) for (i = n; i >= 0; i--)
#define First first
#define Second second
int modulo = 1e9 + 7;

int countValidSequences(int idx, string &str, char start, char end, int seqLen, vector<vector<vector<vector<int>>>> &memo)
{
    if (seqLen == 5)
        return 1;
    if (idx == str.size())
        return 0;
    if (memo[start - '0'][end - '0'][seqLen][idx] != -1)
        return memo[start - '0'][end - '0'][seqLen][idx];

    long long choice1 = 0, choice2 = 0, choice3 = 0, choice4 = 0, choice5 = 0;

    if (seqLen == 0)
        choice1 = countValidSequences(idx + 1, str, str[idx], end, seqLen + 1, memo);
    else if (seqLen == 1)
        choice2 = countValidSequences(idx + 1, str, start, str[idx], seqLen + 1, memo);
    else if (seqLen == 2)
        choice3 = countValidSequences(idx + 1, str, start, end, seqLen + 1, memo);
    else if (seqLen == 3 && str[idx] == end)
        choice4 = countValidSequences(idx + 1, str, start, end, seqLen + 1, memo);
    else if (seqLen == 4 && str[idx] == start)
        choice5 = countValidSequences(idx + 1, str, start, end, seqLen + 1, memo);

    long long skipChoice = countValidSequences(idx + 1, str, start, end, seqLen, memo);

    return memo[start - '0'][end - '0'][seqLen][idx] = (choice1 + choice2 + choice3 + choice4 + choice5 + skipChoice) % modulo;
}

int totalPalindromeSubsequences(string str)
{
    vector<vector<vector<vector<int>>>> memo(10, vector<vector<vector<int>>>(10, vector<vector<int>>(5, vector<int>(str.size(), -1))));
    return countValidSequences(0, str, '1', '1', 0, memo);
}

int main()
{
    string input = "0100110";
    int result = totalPalindromeSubsequences(input);
    cout << result << nl;
}