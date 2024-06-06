#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int start, int end)
{
    
}


void mergesort(vector<int> &a, int start, int end)
{
    if(start>=end) return;

    int mid = (start+end)/2;

    mergesort(a,start, mid);
    mergesort(a,mid,end);
    merge(a,start,end);

    return;
}

int main()
{
    vector<int> vec = {3, 1, 2, 6, 8, 1};

    mergesort(vec, 0, 6);

    for (int i = 0; i < 6; i++)
        cout << vec[i] << " " << endl;

    return 0;
}