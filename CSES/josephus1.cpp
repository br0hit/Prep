#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define ll long long
#define endl "\n"
#define fr(i, a, n) for (i = a; i < n; i++)
#define fr1(i, n) for (i = n; i >= 0; i--)
#define F first
#define S second

int modval = 1e9 + 7;

class node
{

public:
    int val;

    node *next;
    node *prev;

    node(int _val)
    {
        val = _val;
        next = NULL;
        prev = NULL;
    }

    node * insert(int _val)
    {
        node *temp = new node(_val);

        if (this->next != NULL)
        {
            this->prev->next = temp;
            temp->prev = this->prev;
            temp->next = this;
            this->prev = temp;
        }
        else
        {
            this->next = temp;
            this->prev = temp;
            temp->next = this;
            temp->prev = this;
        }

        return temp;
    }

    void deletenode()
    {
        node *temp = this;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
};

void solve()
{
    int n;
    cin >> n;
    node *head = new node(1);
    int i;

    if (n == 1)
    {
        cout << 1;
        return;
    }
    if (n == 2)
    {
        cout << 2 << " " << 1;
        return;
    }

    fr(i, 2, n + 1)
    {
        head->insert(i);
    }

    fr(i, 1, n + 1)
    {
        head= head->next;
        cout << head->val << " ";
        head = head->next;
        head->prev->deletenode();
        node *tempnode = head->next;
        // if (head->next->next != head)
        //     head = head->next->next;
        // else
        //     head = head->next;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t; cin >> t; while (t--)
    solve();
    return 0;
}