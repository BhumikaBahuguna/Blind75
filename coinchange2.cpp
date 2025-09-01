#include<bits/stdc++.h>
using namespace std;
long f(int ind,int t,int *a,vector<vector<long>>&dp){
    if(ind==0){
        if(t%a[0]==0) return t/a[0];
        return 1e9;
    }
    if(dp[ind][t]!=-1) return dp[ind][t];
    long nottake=f(ind-1,t,a,dp);
    long take=1e9;
    if(a[ind]<=t) take=1+f(ind,t-a[ind],a,dp);
    return dp[ind][t]=min(take,nottake);
}
int main(){
    int n;
    cout<<"Enter number of coins: ";
    cin>>n;
    int a[n];
    cout<<"Enter coin denominations: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t;
    cout<<"Enter target amount: ";
    cin>>t;
    vector<vector<long>>dp(n,vector<long>(t+1,-1));
    int ans=f(n-1,t,a,dp);
    if(ans>=1e9) cout<<"Not possible to make change"<<endl;
    else cout<<"Fewest ways to make change: "<<ans<<endl;
    return 0;
}