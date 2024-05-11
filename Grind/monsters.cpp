#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<long long> a(n,0),x(n,0), total_helth(n+1,0);

        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for (long long i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        for(long long i=0; i<n; i++)
        {
            if(x[i]<0)
            {
                total_helth[-1*x[i]] += a[i]; 
            }
            else
            {
                total_helth[x[i]]+= a[i];
            }
        }
        long long temp=0;

        for(long long i=1; i<=n; i++)
        { 
            if(n>1)
            {
                if(total_helth[i-1]<0) total_helth[i] += total_helth[i-1];
            }

            total_helth[i] -= k;

            if(total_helth[i]>0)
            {
                temp=-1;
                break;
            }
        }

        if(temp==-1) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
}

// if(total_helth[i]>k)
// {
//     temp=-1;
//     // cout<<i<<"here";
//     break;
// }
// else
// {
//     long long rem_bull = k - total_helth[i];

//     if(i==n)
//     {
//         if(total_helth[i]-k>0)
//         {
//             temp=-1;
//             break;
//         }
//     }
//     for(int j=i+1; j<=n; j++)
//     {
//         if(rem_bull>total_helth[j])
//         {
//             rem_bull -= total_helth[j];
//             total_helth[j]=0;
//         }
//         else
//         {
//             total_helth[j]-=rem_bull;
//             break;
//         }
//     }
// }