#include<bits/stdc++.h>
using namespace std;
long long mincoins(int * denominations,int n,int values){
    const long long INF = 1e9;
    vector<vector<long long>>dp(n,vector<long long>(values+1,INF));
    for(int i=0;i<=values;i++){
        if(i%denominations[0]==0) dp[0][i]=i/denominations[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=values;j++){
            long long nottake=dp[i-1][j];
            long long take=1e9;
            if(denominations[i]<=j) take= 1+dp[i][j-denominations[i]];
            dp[i][j]=min(take,nottake);
        }
    }
    return dp[n-1][values];
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
    int ans=mincoins(a,n,t);
    if(ans>=1e9) cout<<"Not possible to make change"<<endl;
    else cout<<"Fewest ways to make change: "<<ans<<endl;
}