#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;

    vector<int> p(n,0);

    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }

    sort(p.begin(),p.end());
    int j=0;
    int count=0;

    for(int i=n-1; i>=0; 1)
    {
        if(j>i) break;
        if(i==j)
        {
            count++;
            break;
        }
        if(p[i]+p[j]<=x)
        {
            i--;
            j++;
                        count++;
    
        }
        else
        {
            i--;
                        count++;

        }
    }

    cout<<count;
}