#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int start, int end)
{
    int size = a.size();
    int pivot = a[start];

    int less_last=start;

    for(int i=start+1; i<end; i++)
    {
        if(a[i]<pivot)
        {
            // int temp = a[less_last+1];
            // a[less_last+1] = a[i];
            // a[i] = temp;    
            // less_last++; 

            swap(a[++less_last], a[i]);
        }
    }

    a[start] = a[less_last];
    a[less_last]  = pivot;

    return less_last;
}

void quicksort(vector<int> &a, int start, int end)
{
    if(start>=end) return;
    int pos = partition(a, start, end);
    quicksort(a,start,pos-1);
    quicksort(a,pos+1,end);

    return;

}

int main()
{
    vector<int> vec = {3,1,2,6,8,1};

    quicksort(vec,0,6);

    for(int i=0; i<6; i++) cout<<vec[i]<<" "<<endl;

    return 0;

}