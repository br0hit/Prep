#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& values) {
    long long max_odd = -1; 
    vector<long long> evens; 
    for (int i = 0; i < n; i++) {
        if (values[i] % 2 == 0) {
            evens.push_back(values[i]);
        } else if (values[i] > max_odd) {
            max_odd = values[i];
        }
    }

    sort(evens.begin(), evens.end());

    if (max_odd == -1 || evens.empty()) {
        cout << 0 << endl;
        return;
    }

    int ans = evens.size();
    for(int i =0 ; i<evens.size()  ; i++){
        if(max_odd > evens[i]){
            continue ;
        }
        else{
            max_odd = max_odd + evens[i-1] ;
        }
    }
    cout << "Current max_odd is " << max_odd << endl ;
    if(max_odd < evens[ans-1]){
        ans ++ ;
    }

    int ans = evens.size();
    for (int i = 0; i < evens.size(); i++)
    {
        if (max_odd > evens[i])
        {
            max_odd = max_odd + evens[i];
            continue;
        }
        else
        {
            ans++;
            break;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> values(n);
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }
        solve(n, values);
    }

    return 0;
}