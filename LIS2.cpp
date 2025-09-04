#include<bits/stdc++.h>
using namespace std;
int f(int ind,int prev_ind,int arr[],int n,vector<vector<int>>&dp){
    if(ind==n) return 0;
    if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    int len=0+f(ind+1,prev_ind,arr,n,dp);
    if(prev_ind==-1 ||arr[ind]>arr[prev_ind]){
        len=max(len,1+f(ind+1,ind,arr,n,dp));
    }
    return dp[ind][prev_ind+1]=len;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    cout<<f(0,-1,arr,n,dp)<<endl;
    return 0;
}