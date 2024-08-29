#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        multiset<int> even;

        int ct = 0;
        int odd = INT_MIN;
        bool first = true;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
            {
                even.insert(arr[i]);

                ct++;
            }
            else
            {
                odd = max(odd, arr[i]);
            }
        }
        long long odd2 = odd;
        int ans = 0;
        if (ct == n || ct == 0)
        {
            cout << ans << endl;
            continue;
        }

        for (auto a : even)
        {
            if (a < odd2)
            {

                odd2 = odd2 + a;

                ans++;
            }
            else
            {
                if (first == true)
                {

                    ans = ans + 2;
                    first = false;
                }
                else
                {

                    ans = ans + 1;
                }
            }
        }
        cout << ans << endl;
    }
}