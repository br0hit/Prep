#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl '\n'
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second
int modval = 1e9 + 7;

void merge(vector<int> &A, int l, int mid, int r)
{
    if(A[l]<=A[mid+1])
    {
    vector<int> t(r-l+1,0);
    int i=l;
    int k=mid+1;
    
    for(int j=l;j<=mid-1;j++)
    {
        int first=A[j];
        int last=A[j+1];
        
        t[i]=first;
        i++;
        while(k<=r)
        {
            if(A[k]>= first && A[k]<=last)
            {
                t[i]=A[k];
                i++;
                k++;
            }
            else{
                break;
            }
        }
        
    }
    t[i]=A[mid];
    i++;
    while(k<=r)
    {
        
         t[i] = A[k];
        k++ ;
        i++;
    }
    for(int h=l;h<=r;h++)
    {
        A[h]=t[h];
    }
    }
    else{
        vector<int> t2(r - l + 1, 0);
        int i2 = l;
        int k2 = l;

        for (int j2=mid+1; j2 <= r; j2++)
        {
            int first = A[j2];
            int last = A[j2 + 1];

            t2[i2] = first;
            i2++;
            while (k2 <= r)
            {
                if (A[k2] >= first && A[k2] <= last)
                {
                    t2[i2] = A[k2];
                    i2++;
                    k2++;
                }
                else
                {
                    break;
                }
            }
        }
        t2[i2] = A[r];
        i2++;
        while (k2 <= mid)
        {

            t2[i2] = A[k2];
            k2++;
            i2++;
        }
        for (int h = l; h <= r; h++)
        {
            A[h] = t2[h];
        }
    }
    
    
}
void mergesort(vector<int> &A, int l , int r)
{
    int size=r-l+1;
    if(size==1)
    {
        
        return;
        
    }
    if(size==2)
    {
        if(A[l]>A[r])
        {
            int temp1=A[l];
            A[l]=A[r];
            A[r]=temp1;
        }
        
        return;
    }
    int mid=(r+l)/2;
    
    mergesort(A,l,mid);
    
    mergesort(A,mid+1,r);
    
    merge(A,l,mid,r);
    
}
void solve()
{
    vector<int> A = {-1,3,1,6,5,5,-1,0};

    int n = A.size();
    mergesort(A,0,n-1);



    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}