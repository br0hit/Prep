#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

long getMinimumSize(std::vector<int> &payloadSize, std::vector<int> &cacheA, std::vector<int> &cacheB, int minThreshold)
{
    int n = payloadSize.size();
    std::vector<std::pair<int, int>> requests(n);

    for (int i = 0; i < n; i++)
    {
        requests[i] = {payloadSize[i], i};
    }

    std::sort(requests.begin(), requests.end());

    std::vector<long> sumA(n + 1, 0), sumB(n + 1, 0);
    std::vector<int> countA(n + 1, 0), countB(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int idx = requests[i - 1].second;
        sumA[i] = sumA[i - 1] + (cacheA[idx] ? payloadSize[idx] : 0);
        sumB[i] = sumB[i - 1] + (cacheB[idx] ? payloadSize[idx] : 0);
        countA[i] = countA[i - 1] + cacheA[idx];
        countB[i] = countB[i - 1] + cacheB[idx];
    }

    long minSum = LONG_MAX;

    for (int i = 0; i <= n; i++)
    {
        if (countA[i] >= minThreshold)
        {
            int left = i, right = n;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (countB[mid] - countB[i] >= minThreshold)
                {
                    minSum = std::min(minSum, sumA[i] + (sumB[mid] - sumB[i]));
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
    }

    return minSum == LONG_MAX ? -1 : minSum;
}

int main()
{
    std::vector<int> payloadSize = {10, 8, 12, 4, 5, 25};
    std::vector<int> cacheA = {1, 0, 1, 1, 0, 1};
    std::vector<int> cacheB = {1, 0, 1, 0, 1, 1};
    int minThreshold = 3;

    long result = getMinimumSize(payloadSize, cacheA, cacheB, minThreshold);

    std::cout << "Minimum sum of payload sizes: " << result << std::endl;

    return 0;
}