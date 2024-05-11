#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n,p,l,t;
        cin>>n>>p>>l>>t;

        ll no_tasks;
        no_tasks = (n+6)/7;

        ll doubletasks = no_tasks/2;
        ll rem = no_tasks%2;

        ll score1,score2,score3;

        score1 = l+2*t;
        score2 = l+t;
        score3 = l;

        ll workdays;

        if(doubletasks*score1>=p)
        {
            if(p%score1==0) workdays = p/score1;
            else 
            workdays = (p/score1)+1;
        }
        else if (rem == 1 && doubletasks * score1 + score2 >= p)
        {
            workdays = doubletasks + 1;
        }
        else
        {
            ll remainingscore=p;
            if(rem==1) 
            { remainingscore-=score2;
              workdays++;
            }
            remainingscore-=doubletasks*score1;

            if(remainingscore%score3==0)
            workdays = remainingscore/ score3 + doubletasks;
            else
            workdays = remainingscore / score3 + doubletasks +1;
        }

        cout<<n-workdays<<endl;
    }

    return 0;
}
