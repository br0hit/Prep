#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int convert(int temp, int n)
{
    if(temp>0 && temp<=n) return temp;
    if (temp == 0 || abs(temp)%n==0)
        return n;

    if(temp>n)
    {
        return temp - (temp/n)*n;
    }
    if(temp<0)
    {
        return temp + ((abs(temp)/n)+1)*n;
    }

    return -1;
}

void solve()
{
    // cout<<(1<<0)<<"haha"<<endl;
    int n,m,x;
    cin>>n>>m>>x;

    vector<int> random;
    int totalval=0;

    for(int i=0; i<m; i++)
    {
        int tempint;
        char tempchar;
        cin >> tempint >> tempchar;

        if(tempchar=='?')
        {
            if(tempint!=n)
            random.push_back(tempint);
        }
        else if(tempchar=='1')
        {
            totalval-=tempint;
        }
        else totalval+=tempint;

    }

    int size = random.size();

    if(size==0)
    {   
        cout<<1<<endl;
        //cout<<totalval<<endl;
        int score = x + totalval;
        cout<<convert(score,n)<<endl;
        return;
    }

    set<int> tryset;
    set<int> newset;

    tryset.insert(convert(x+totalval,n));

    for(int i=0 ; i<size; i++)
    {
        int curr_val = random[i];
        for(int j: tryset)
        {
            newset.insert(convert(j+random[i],n));
            newset.insert(convert(j-random[i],n));
        }
        tryset = newset;
        newset.clear();
    }


    // for(int i=0; i< (1<<(size)); i++)
    // {
    //     ll randomval=0;
    //     for(ll j=0; j<size; j++)
    //     {
    //         ll tempbit = i&(1<<j);
    //         if(tempbit==0) randomval -=random[j];
    //         else randomval+=random[j];
    //     }

    //     tryset.insert(convert(x + totalval + randomval,n));
    //     // tryset.insert(convert(x + totalval - randomval, n));

    //     if(tryset.size()==n) break;
    // }

    cout<<tryset.size()<<endl;
    for(ll element: tryset)
    {
        cout<<element<< " ";
    }
    cout<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t; while(t--)
    solve();
    return 0;
}