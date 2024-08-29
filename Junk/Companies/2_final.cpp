#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void s(string a[], int n)
{
    vector<string> r(n);
    int i = 0, j = n - 1;
    unordered_map<string, int> p, np;

    for (int k = 0; k < n; k++)
    {
        string s1 = a[k];
        string s2 = string(s1.rbegin(), s1.rend());
        if (s1 == s2)
        {
            p[s1]++;
        }
        else
        {
            int f = np[s2];
            if (f == 0)
            {
                np[s1]++;
            }
            else
            {
                r[i++] = s1;
                r[j--] = s2;
                np[s2]--;
            }
        }
    }

    string o;
    for (auto &kv : p)
    {
        string ps = kv.first;
        int f = kv.second;
        if (f % 2 == 1)
        {
            while (f > 1)
            {
                r[i++] = ps;
                r[j--] = ps;
                f -= 2;
            }
            if (o.empty())
                o = ps;
        }
        else
        {
            while (f > 0)
            {
                r[i++] = ps;
                r[j--] = ps;
                f -= 2;
            }
        }
    }

    if (!o.empty())
        r[i++] = o;

    string res;
    for (auto &t : r)
    {
        if (!t.empty())
            res += t;
    }

    cout << res << endl;
}

int main()
{
    string a1[] = {"aba", "aba"};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    s(a1, n1);

    string a2[] = {"ab", "ba", "xyx", "de"};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    s(a2, n2);

    return 0;
}