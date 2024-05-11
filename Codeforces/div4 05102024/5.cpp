#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int n,k,q;
        cin>>n>>k>>q;


        vector<int> a(k+1,0), b(k+1,0);
        for(int i=0; i<k; i++) cin>>a[i+1];
        for (int i = 0; i < k; i++) cin >> b[i+1];

        vector<int > queryyy(q,0);
        for(int i=0; i<q; i++) cin>>queryyy[i];

        int prev_val_j=1;

        for(int i=0; i<q; i++)
        {
            int query = queryyy[i];
            // cout<<query<<endl;

            int max_pos;

            int exact=0;

            for(int j=1; j<k+1; j++)
            {
                if(a[j]>=query)
                {
                    if(a[j]==query) exact=1;
                    max_pos = j;
                    prev_val_j = j;
                    break;
                }
            }

            if(exact==1) cout<<b[max_pos]<<" ";
            else
            {
                // cout<<max_pos<<a[max_pos]<<"Time"<<endl;
                long long time;
                time = ((query - a[max_pos - 1]));
                time*=(b[max_pos] - b[max_pos - 1]);
                // cout<<time<<endl;
                time = time / ((a[max_pos] - a[max_pos - 1]));
                // cout<<time<<"NEW"<<endl;
                time += b[max_pos - 1];
                cout<< time << " ";
            }
        }
        cout<<endl;
    }

    return 0;
}