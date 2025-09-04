#include<bits/stdc++.h>
using namespace std;
int longestincsubseq(int arr[],int n){
vector<int>dp(n,1);
int maxi=1;
for(int i=0;i<n;i++){
    for(int prev=0;prev<i;prev++){
        if(arr[prev]<arr[i]){
            dp[i]=max(dp[i],1+dp[prev]);
        }
    }
    maxi=max(maxi,dp[i]);
}
return maxi;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"length of LIS is: "<<
    longestincsubseq(arr,n);
return 0;

}