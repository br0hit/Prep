#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int start, int end)
{
    cout<<"atleast once "<<endl;
    int mid = start + (end-start)/2;
    int pos1=0, pos2 = 0;

    vector<int> temp1,temp2;

    for(int i=start; i<mid; i++)
    {
        temp1.push_back(a[i]);
    }

    for(int i=mid; i<end; i++)
    {
        temp2.push_back(a[i]);
    }
    int pos = start;

    while(pos1<mid && pos2<end-mid)
    {
        if(temp1[pos1]<=temp2[pos2])
        {
            a[pos] = temp1[pos1];
            pos1++;
            pos++;
        }
        if(temp1[pos1]>temp2[pos2])
        {
            a[pos] = temp2[pos2];
            pos2++;
            pos++;
        }
    }

    if(pos1==mid)
    {
        for(int i=pos2; i<end-mid; i++)
        {
            a[pos] = temp2[i];
            pos++;
        }
    }

    if (pos2 == end-mid)
    {
        for (int i = pos1; i < mid; i++)
        {
            a[pos] = temp1[i];
            pos++;
        }
    }

    return;
}


void mergesort(vector<int>&a, int start, int end)
{
    if(end>start+1)
    {
        int mid = start + (end - start) / 2;

        mergesort(a, start, mid);

        mergesort(a, mid, end);

        cout<<"Stuck here"<<start<<" "<<mid<<" "<<end<<endl;

        merge(a, start, end);
        cout << "out of merge step" << endl;
        return;
    }
}
int main()
{
    vector<int> a={3,5,1,2,8};
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }

    cout<<"here"<<endl;
    mergesort(a,0,5);
    cout<<"there"<<endl;
    
    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}