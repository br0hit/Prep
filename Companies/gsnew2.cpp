#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    vector<string> channels(N);
    for (int i = 0; i < N; ++i)
    {
        getline(cin, channels[i]);
    }

    string operations;
    getline(cin, operations);

    int currentIndex = 0;

    for (char op : operations)
    {
        if (op == '1')
        {
            if (currentIndex < N - 1)
            {
                currentIndex++;
            }
        }
        else if (op == '2')
        {
            if (currentIndex > 0)
            {
                currentIndex--;
            }
        }
        else if (op == '3')
        {
            if (currentIndex < N - 1)
            {
                swap(channels[currentIndex], channels[currentIndex + 1]);
                currentIndex++;
            }
        }
        else if (op == '4')
        {
            if (currentIndex > 0)
            {
                swap(channels[currentIndex], channels[currentIndex - 1]);
                currentIndex--;
            }
        }
    }

    for (const string &channel : channels)
    {
        cout << channel << endl;
    }

    return 0;
}