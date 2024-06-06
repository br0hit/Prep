#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool weirdsort(vector<int> num1, vector<int> num2)
{
    if (num1[0] == num2[0])
        return num1[1] > num2[2];
    return num1[0] > num2[0];
}

bool merge(vector<int> num1, vector<int> num2)
{
    if (num1[0] == num2[0])
        return 1;
    if (num1[1] < num2[0])
        return 0;
    return 1;
}

void solve()
{
    vector<vector<int>> intervals;
    intervals.push_back(vector<int>{1,4});
    intervals.push_back(vector<int>{1,4});

    sort(intervals.begin(), intervals.end(), weirdsort);
    for (int i = 1; i < intervals.size(); i++)
    {
        cout << intervals[i][0] << " " << intervals[i][1] << endl;
    }

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    if (intervals.size() == 1)
        return;

    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> tempval = ans[ans.size() - 1];
        ans.pop_back();
        if (!merge(tempval, intervals[i]))
        {
            cout << i << "Case 1" << endl;
            ans.push_back(tempval);
            ans.push_back(intervals[i]);
        }
        else
        {
            cout << i << "Case 2" << endl;
            tempval[1] = max(tempval[1], intervals[i][1]);
            cout << tempval[0] << " " << tempval[1] << endl;
            ans.push_back(tempval);
        }
    }
    

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin>>t; while(t--)
    solve();
    return 0;
}