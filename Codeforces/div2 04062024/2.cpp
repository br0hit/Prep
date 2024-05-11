#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n,k;
        cin>>n>>k;

        vector<ll> a(n,0);

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        ll prev_max=a[0], curr_max;
        ll ourcow = a[k];
        int maxscore,currmaxscore,swapindex, largerorsmaller;

        for(int i=0; i<n; i++)
        {

            if(i!=k)
            {
                if (prev_max > ourcow)
                    currmaxscore = 0;
                else
                {
                    currmaxscore = 1;
                }

                if (a[i] < ourcow)
                {
                    currmaxscore++;
                }

                if (a[i] > prev_max)
                    a[i] = prev_max;

                if (currmaxscore > maxscore)
                {
                    swapindex = i;
                }
            }
            else
            {

            }


        }

    }
}