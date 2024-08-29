#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class AuthenticationManager
{
public:
    AuthenticationManager(int timeToLive)
    {
        ttl = timeToLive;
    }

    void generate(string tokenId, int currentTime)
    {
        tokenExpiry[tokenId] = currentTime + ttl;
    }

    void renew(string tokenId, int currentTime)
    {
        if (tokenExpiry.find(tokenId) != tokenExpiry.end() && tokenExpiry[tokenId] > currentTime)
        {
            tokenExpiry[tokenId] = currentTime + ttl;
        }
    }

    int count(int currentTime)
    {
        int unexpiredCount = 0;
        for (auto it = tokenExpiry.begin(); it != tokenExpiry.end();)
        {
            if (it->second > currentTime)
            {
                unexpiredCount++;
                ++it;
            }
            else
            {
                it = tokenExpiry.erase(it);
            }
        }
        return unexpiredCount;
    }

private:
    int ttl;
    unordered_map<string, int> tokenExpiry;
};

vector<int> getUnexpiredTokens(int timeToLive, vector<string> queries)
{
    AuthenticationManager manager(timeToLive);
    vector<int> results;

    for (const string &query : queries)
    {
        stringstream ss(query);
        string action, tokenId;
        int currentTime;

        ss >> action;

        if (action == "generate")
        {
            ss >> tokenId >> currentTime;
            manager.generate(tokenId, currentTime);
        }
        else if (action == "renew")
        {
            ss >> tokenId >> currentTime;
            manager.renew(tokenId, currentTime);
        }
        else if (action == "count")
        {
            ss >> currentTime;
            results.push_back(manager.count(currentTime));
        }
    }

    return results;
}

int main()
{
    int timeToLive = 5;
    vector<string> queries = {
        "generate aaa 1",
        "renew aaa 2",
        "count 6",
        "generate bbb 7",
        "renew aaa 8",
        "renew bbb 10",
        "count 15"};

    vector<int> results = getUnexpiredTokens(timeToLive, queries);

    for (int result : results)
    {
        cout << result << endl; // Output: 1, 0
    }

    return 0;
}
