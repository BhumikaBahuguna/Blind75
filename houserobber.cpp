#include<bits/stdc++.h>
using namespace std;
int maxSumNonAdjacent(vector<int>&nums){
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+=prev2;
        int nontake=0+prev;
        int curi=max(take,nontake);
        prev2=prev;
        prev=curi;
    }
    return prev;
}
long long int houseRobber(vector<int>&valueinhouse){
    vector<int> temp1,temp2;
    int n=valueinhouse.size();
    if(n==1) return valueinhouse[0];
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(valueinhouse[i]);
        if(i!=n-1) temp2.push_back(valueinhouse[i]);
    }
    return max(maxSumNonAdjacent(temp1),maxSumNonAdjacent(temp2));
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<maxSumNonAdjacent(nums)<<endl;
    return 0;
}