#include<bits/stdc++.h>
using namespace std;
int countpaths(int i,int j,int n,int m,vector<vector<int>>&dp){
    if(i==(n-1) && j==(m-1)) return 1;
    if(i>=n || j>=m ) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    else return dp[i][j]=countpaths(i+1, j, n, m,dp) + countpaths(i, j+1, n, m,dp);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<countpaths(0,0,n,m,dp);
    return 0;
}