// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// void solve()
// {
//     int n;
//     cin >> n;

//     vector<int> k(n, 0);
//     for (int i = 0; i < n; i++)
//         cin >> k[i];

//     map<int, int> map;
//     int first = 0, last = 0;

//     int curr_size = 0, maxsize = -1;

//     for (int i = 0; i < n; i++)
//     {
//         if (map.count(k[i]) == 0)
//         {
//             last++;
//             map[k[i]] = i;
//             curr_size++;
//         }
//         else
//         {
//             maxsize = max(maxsize, curr_size);
//             while (first <= last)
//             {
//                 if (k[first] == k[last])
//                     break;
//                 map.erase(k[first]);
//                 first++;
//             }
//             first++;
//             last++;
//             curr_size = last - first;
//         }
//     }
//     maxsize = max(maxsize, curr_size);
//     cout << maxsize;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modval = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> k(n, 0);
    for (int i = 0; i < n; i++)
        cin >> k[i];

    unordered_set<int> st;
    map<int, int> map;
    queue<int> temp;

    int curr_size = 0, maxsize = -1;

    for (int i = 0; i < n; i++)
    {
        // if(st.count(k[i])==0)
        if (map.find(k[i]) == map.end())
        {
            // st.insert(k[i]);
            map[k[i]] = i;
            temp.push(k[i]);
            curr_size++;
        }
        else
        {
            maxsize = max(maxsize, curr_size);
            while (temp.front() != k[i])
            {
                int val = temp.front();
                // st.erase(val);
                map.erase(val);
                temp.pop();
                curr_size--;
            }
            temp.pop();
            temp.push(k[i]);
        }
    }

    maxsize = max(maxsize, curr_size);
    cout << maxsize;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin >> t; while (t--)
    solve();
    return 0;
}