#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int solve(string arr[], int n);
int main()
{
    string a1[] = {"aba", "aba"};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    cout << solve(a1, n1);
    string a2[] = {"abc", "dba", "kop", "abd", "cba"};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    cout << solve(a2, n2);
    return 0;
}
int solve(string arr[], int n)
{
    vector<string> ans(n);
    int i = 0, j = n - 1;
    unordered_map<string, int> pallMap;
    unordered_map<string, int> notPallMap;
    for (int k = 0; k < n; k++)
    {
        string str1 = arr[k];
        string str2 = string(str1.rbegin(), str1.rend());
        if (str1 == str2)
        {
            pallMap[str1]++;
        }
        else
        {
            int freq = notPallMap[str2];
            if (freq == 0)
            {
                notPallMap[str1]++;
            }
            else
            {
                ans[i] = str1;
                ans[j] = str2;
                i++;
                j--;
                notPallMap[str2]--;
            }
        }
    }
    string odd;
    for (auto &kk : pallMap)
    {
        string pall_string = kk.first;
        int freq = kk.second;
        if (freq % 2 == 1)
        {
            while (freq > 1)
            {
                ans[i++] = pall_string;
                ans[j--] = pall_string;
                freq -= 2;
            }
            if (odd.empty())
            {
                odd = pall_string;
            }
        }
        else
        {
            while (freq > 0)
            {
                ans[i++] = pall_string;
                ans[j--] = pall_string;
                freq -= 2;
            }
        }
    }
    if (!odd.empty())
    {
        ans[i++] = odd;
    }
    string res;
    for (auto &temp : ans)
    {
        if (!temp.empty())
        {
            res += temp;
        }
    }
    return res.size();
}
string reverse(string input)
{
    int l, r = input.size() - 1;
    for (l = 0; l < r; l++, r--)
    {
        char temp = input[l];
        input[l] = input[r];
        input[r] = temp;
    }
    return input;
}