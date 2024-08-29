#include <iostream>
#include <vector>
#include <set>

using namespace std;

int minBiscuitTowers(int n, vector<int> &sizes)
{
    multiset<int> towers;

    for (int size : sizes)
    {
        auto it = towers.upper_bound(size);
        if (it != towers.end())
        {
            towers.erase(it);
        }
        towers.insert(size);
    }

    return towers.size();
}

int main()
{
    // Example input
    int n = 5;
    vector<int> sizes = {3, 8, 2, 1, 5};

    // Calculate the minimum number of biscuit towers
    int result = minBiscuitTowers(n, sizes);

    // Print the result
    cout << "The minimum number of biscuit towers: " << result << endl;

    return 0;
}
