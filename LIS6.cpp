#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& arr, int n) {
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;

    for (int i = 0; i < n; i++) {
        hash[i] = i;  // initially, each element points to itself
        for (int prev = 0; prev < i; prev++) {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    // Reconstruct LIS sequence
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());

    cout << "Longest Increasing Subsequence: ";
    for (auto it : temp) cout << it << " ";
    cout << endl;

    return maxi;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Length of LIS: " << lis(arr, n) << endl;
    return 0;
}
