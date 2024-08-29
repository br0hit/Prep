#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

struct SegmentTree
{
    vector<long long> tree, lazy;
    int size;

    SegmentTree(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(2 * size, 0LL);
        lazy.assign(2 * size, 0LL);
    }

    void push(int node)
    {
        tree[node * 2] += lazy[node];
        lazy[node * 2] += lazy[node];
        tree[node * 2 + 1] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }

    void update(int l, int r, long long value, int node, int nl, int nr)
    {
        if (l > nr || r < nl)
            return;
        if (l <= nl && nr <= r)
        {
            tree[node] += value;
            lazy[node] += value;
            return;
        }
        push(node);
        int mid = (nl + nr) / 2;
        update(l, r, value, node * 2, nl, mid);
        update(l, r, value, node * 2 + 1, mid + 1, nr);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    long long query(int l, int r, int node, int nl, int nr)
    {
        if (l > nr || r < nl)
            return LLONG_MIN;
        if (l <= nl && nr <= r)
            return tree[node];
        push(node);
        int mid = (nl + nr) / 2;
        return max(query(l, r, node * 2, nl, mid), query(l, r, node * 2 + 1, mid + 1, nr));
    }

    void update(int l, int r, long long value)
    {
        update(l, r, value, 1, 0, size - 1);
    }

    long long query(int l, int r)
    {
        return query(l, r, 1, 0, size - 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    SegmentTree st(MAXN);

    for (int i = 0; i < N; i++)
    {
        int L, R, X;
        cin >> L >> R >> X;
        st.update(L, R, X);
    }

    vector<int> result;
    int current = 0;
    long long prev_value = -1;

    while (current < MAXN)
    {
        long long max_value = st.query(current, MAXN - 1);
        if (max_value <= prev_value)
            break;

        result.push_back(current);
        prev_value = max_value;
        current += K;
    }

    cout << result.size() << " " << result[0] << " " << result.back() << endl;

    return 0;
}