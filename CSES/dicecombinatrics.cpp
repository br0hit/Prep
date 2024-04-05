#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    long ans = (1<<(n-1));

    long valans = (1e9+7);
    cout<<ans%valans;

    return 0;
}
