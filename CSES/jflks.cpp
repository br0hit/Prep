#include<bits/stdc++.h>
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


#include<thread>
#include<unistd.h>

void funa()
{
    for(int i=0; i<5; i++)
    {
        sleep(1);
        cout<<i<<endl;
        fflush(stdout);
    }
}

void funb()
{
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        cout << i << endl;
        fflush(stdout);
    }
}

void solve()
{
    // multiset<int> ms;
    // ms.insert(2);
    // ms.insert(3);
    // ms.insert(4);

    // auto u = upper_bound(ms.begin(), ms.end(),2);
    // cout<<distance(u, ms.end())<<endl;



    return;


}


signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   thread t1(funa);
   thread t2(funb);

   t1.join();
   t2.join();
}