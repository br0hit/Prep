#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> candy_cost;

int dfs(int node, int parent, int money)
{
    int candies = 0;
    if (money >= candy_cost[node])
    {
        candies = 1;
        money -= candy_cost[node];

        for (int child : tree[node])
        {
            if (child != parent)
            {
                candies += dfs(child, node, money);
            }
        }
    }
    return candies;
}

int solve(int N, int K, vector<int> &A, vector<vector<int>> &Edges)
{
    tree.resize(N + 1);
    candy_cost = A;

    for (const auto &edge : Edges)
    {
        int u = edge[0], v = edge[1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int max_candies = 0;
    for (int i = 1; i <= N; i++)
    {
        max_candies = max(max_candies, dfs(i, 0, K));
    }

    return max_candies;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, K;
        cin >> N >> K;

        vector<int> A(N + 1);
        for (int i = 1; i <= N; i++)
        {
            cin >> A[i];
        }

        vector<vector<int>> Edges(N - 1, vector<int>(2));
        for (int i = 0; i < N - 1; i++)
        {
            cin >> Edges[i][0] >> Edges[i][1];
        }

        cout << solve(N, K, A, Edges) << endl;

        // Clear the tree for the next test case
        tree.clear();
    }

    return 0;
}