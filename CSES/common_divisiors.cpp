#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int temp;
    cin>>n;

    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        arr[i] = temp;
    }

    sort(arr.begin(), arr.end());

    return 0;

}