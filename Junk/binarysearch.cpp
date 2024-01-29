#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> temp{1,4,4,4,4,4,5};

    auto a = lower_bound(temp.begin(),temp.end(),4);
    auto b = upper_bound(temp.begin(),temp.end(),4);
    auto d = equal_range(temp.begin(),temp.end(),4);

    auto c = distance(temp.begin(),a);

    cout<<" "<<*d.second;

    return 0;
}