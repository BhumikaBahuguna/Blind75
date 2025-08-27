class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && arr[i] == arr[i - 1]) continue; 
            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && arr[j] == arr[j - 1]) continue; 
                for (int k = j + 1; k < n; ++k) {
                    if (k > j + 1 && arr[k] == arr[k - 1]) continue;
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        ans.push_back({arr[i], arr[j], arr[k]});
                    }
                }
            }
        }
        return ans;
    }
};
