class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,curSum,num1,num2;
        vector<int> ans;
        ans=nums;
        sort(ans.begin(),ans.end());
        while(i<j){
            curSum=ans[i]+ans[j];
            if(curSum<target) i++;
            else if(curSum>target) j--;
            else{
                num1=ans[i];
                num2=ans[j];
                break;
            } 
        }
        ans.clear();
        curSum=0;
        for(int k=0;k<nums.size();k++){
            if(nums[k]==num1 || nums[k]==num2){
                ans.push_back(k);
                curSum++;
                if(curSum==2) break;
            }
        }
        return ans;    
    }
};
