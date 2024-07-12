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
    node *kth;

    node(int _val)
    {
        val = _val;
        next = NULL;
        prev = NULL;
        kth = NULL;
    }

    node *insert(int _val)
    {
        node *temp = new node(_val);
        this->kth = NULL;

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

    node *insert(int _val, node *kthval)
    {
        node *temp = new node(_val);
        this->kth = kthval;

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

    void deletenode(int k)
    {
        node *temp = this;
        temp->prev->next = temp->next;
        node *newtemp = temp;

        while (k--)
        {
            if (newtemp->prev->kth != NULL)
            {
                if (newtemp->kth != NULL)
                    newtemp->prev->kth = newtemp->kth;
                else
                    newtemp->prev->kth = NULL;
            }
        }

        temp->next->prev = temp->prev;
    }
};

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    node *head = new node(1);
    node *insert = head;
    priority_queue<pair<int, int>> pq;
    int i;

    list<int> li;

    fr(i, 1, n + 1) li.push_back(i);
    int count = 0;
    int carry;

    while (!li.empty())
    {
        for (auto u = li.begin(); u != li.end(); u++)
        {
            if (count == k)
            {
                cout << *u << " ";
                li.erase(u);
                count = 0;
            }
            else
                count++;

            if (u == --li.end())
            {
                carry = count;
            }
        }
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

// fr(i, 2, n + 1)
// {
//     if (count == k)
//     {
//         node *newval = head->insert(i);
//         insert->kth = newval;
//         insert = insert->next;
//     }
//     else
//     {
//         node *newval = head->insert(i);
//         count++;
//     }
// }

// cout << "nodes inserted" << endl;

// int loop;

// fr(i, 1, n + 1)
// {
//     if (head->kth != NULL)
//     {
//         head = head->kth;
//         cout << head->val << " ";
//     }
//     else
//     {
//         loop = k;
//         while (loop--)
//             head = head->next;
//         cout << head->val << " ";
//     }
//     head = head->next;
//     head->prev->deletenode(k);
//     // node *tempnode = head->next;
//     // if(head->next->next!=head)
//     // head = head->next->next;
//     // else head = head->next;
//     // tempnode->deletenode();
// }