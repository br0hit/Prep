#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, l;
        cin >> a >> b >> l;

        int pow_a = 0;
        while (l % a == 0)
        {
            l /= a;
            pow_a++;
        }

        int count = 0;
        set<int> distinct_ks;

        if (l == 1)
        {
            // If l is reduced to 1, it means it was divisible only by 'a'
            // So, the distinct values of k are all powers of 'b' up to pow_a
            for (int i = 0; i <= pow_a; ++i)
            {
                int k = pow(b, i);
                distinct_ks.insert(k);
            }
        }
        else
        {
            // Otherwise, 'l' has remaining factors other than 'a'
            // In this case, we need to include all possible combinations of powers of 'a' and 'b'
            for (int i = 0; i <= pow_a; ++i)
            {
                int remaining_l = l * pow(a, i);
                int pow_b = 0;
                while (remaining_l % b == 0)
                {
                    remaining_l /= b;
                    pow_b++;
                }
                int k = pow(b, pow_b);
                distinct_ks.insert(k);
            }
        }

        cout << distinct_ks.size() << endl;
    }

    return 0;
}
