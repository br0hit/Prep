#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int countWaysToCreateWave(std::vector<int>& arr, int m) {
    int n = arr.size();
    std::vector<std::vector<long long>> dp(n, std::vector<long long>(2, 0));

    // Initialize the first element
    if (arr[0] == -1) {
        dp[0][0] = dp[0][1] = m;
    } else {
        dp[0][0] = dp[0][1] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] == -1) {
            // Case 1: Current element is smaller than the previous
            dp[i][0] = (arr[i-1] == -1 ? m * dp[i-1][1] : (arr[i-1] > 1 ? dp[i-1][1] : 0));

            // Case 2: Current element is larger than the previous
            dp[i][1] = (arr[i-1] == -1 ? m * dp[i-1][0] : (arr[i-1] < m ? dp[i-1][0] : 0));
        } else {
            // Case 1: Current element is smaller than the previous
            dp[i][0] = (arr[i-1] == -1 ? (arr[i] > 1 ? dp[i-1][1] : 0) : (arr[i] < arr[i-1] ? dp[i-1][1] : 0));

            // Case 2: Current element is larger than the previous
            dp[i][1] = (arr[i-1] == -1 ? (arr[i] < m ? dp[i-1][0] : 0) : (arr[i] > arr[i-1] ? dp[i-1][0] : 0));
        }

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }

    return (dp[n-1][0] + dp[n-1][1]) % MOD;
}

int main() {
    int n = 3;
    std::vector<int> arr = {-1, 3, -1};
    int m = 3;

    int result = countWaysToCreateWave(arr, m);
    std::cout << "Number of ways to create a wave array: " << result << std::endl;

    return 0;
}