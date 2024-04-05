#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a(n,0);
        vector<int> val(n,0);

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        if(n>=1)
        {
            int first = a[0], last = a[n - 1];

            int first_count=1, last_count=1;

            for (int i = 1; i <= n - 2; i++)
            {
                if (a[i] == first)
                    first_count++;
                else
                    break;
            }

            for (int i = n - 2; i >= 1; i--)
            {
                if (a[i] == last)
                    last_count++;
                else
                    break;
            }

            if (first != last)
            {
                // cout<<"here"<<first_count<<last_count<<endl;
                if (first_count < last_count)
                    first_count = last_count;
                cout << n - first_count<<endl;
            }
            else
            {
                if(first_count+last_count>n) cout<<0<<endl;
                else cout<<n-first_count-last_count<<endl;

            }
        }
        else cout<<0<<endl;

       
    }
}