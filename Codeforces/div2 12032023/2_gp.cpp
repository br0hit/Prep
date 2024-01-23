#include<iostream>
using namespace std;

int main()
{
    int ts;
    long long int n, p, l, t;
    cin >> ts;

    while (ts--)
    {
        cin >> n >> p >> l >> t;

        long long int no_tasks = ((n - 1) / 7) + 1;
        long long int total_points = l * n + no_tasks * t;

        if (total_points >= p)
        {
            cout << "0\n";
            continue;
        }

        long long int rest_days = (p - total_points) / (l + t);
        long long int remaining_tasks = (p - total_points) % (l + t);

        if (remaining_tasks > l)
        {
            rest_days += 2; // If there are enough points to complete 2 tasks, then add 2 days.
        }
        else if (remaining_tasks > 0)
        {
            rest_days += 1; // If there are points to complete only 1 task, then add 1 day.
        }

        cout << n - rest_days << "\n";
    }

    return 0;
}
