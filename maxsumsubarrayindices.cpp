class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int sum = nums[0];
        int start = 0, end = 0, tempStart = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] > sum + nums[i]) {
                sum = nums[i];
                tempStart = i;
            } else {
                sum += nums[i];
            }

            if (sum > maxi) {
                maxi = sum;
                start = tempStart;
                end = i;
            }
        }

        // Now maxi = max sum, and subarray is nums[start...end]
        return maxi;
    }
};
