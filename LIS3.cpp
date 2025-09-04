#include<bits/stdc++.h>
using namespace std;
int longestincsubseq(int arr[],int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int len=0+dp[ind+1][prev_ind+1];
            if(prev_ind==-1 ||arr[ind]>arr[prev_ind]){
                len=max(len,1+dp[ind+1][ind+1]);
            }
            dp[ind][prev_ind+1]=len;
        }
    }
    return dp[0][-1+1];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<longestincsubseq(arr,n)<<endl;
    return 0;
}