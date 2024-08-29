#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int countWaysToCreateWave(vector<int> &arr, int m)
{
    int n = arr.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(2, 0)));

    // Initialize dp for the first element
    for (int j = 1; j <= m; ++j)
    {
        if (arr[0] == -1 || arr[0] == j)
        {
            dp[0][j][0] = 1;
            dp[0][j][1] = 1;
        }
    }

    // Fill dp table
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (arr[i] != -1 && arr[i] != j)
                continue;

            for (int k = 1; k <= m; ++k)
            {
                if (arr[i - 1] != -1 && arr[i - 1] != k)
                    continue;

                if (k < j)
                {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][1]) % MOD;
                }
                else if (k > j)
                {
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][0]) % MOD;
                }
            }
        }
    }

    // Calculate result
    int result = 0;
    for (int j = 1; j <= m; ++j)
    {
        result = (result + dp[n - 1][j][0]) % MOD;
        result = (result + dp[n - 1][j][1]) % MOD;
    }

    return result;
}

int main()
{
    vector<int> arr = {-1, 3, -1};
    int m = 3;
    cout << countWaysToCreateWave(arr, m) << endl; // Output: 4
    return 0;
}
