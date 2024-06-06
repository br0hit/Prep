#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int n;
        cin>>n;

        vector<int> a(n,0);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        sort(a.begin(),a.end());

        int count=1;
        int pos;

        if(n%2==0) pos = n/2 -1;
        else pos = (n/2);

        while(a[pos+1]==a[pos] && pos+1<a.size())
        {
            count++;
            pos++;
        }

        cout<<count<<endl;

    }

    return 0;
}