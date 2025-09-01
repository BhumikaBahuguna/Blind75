#include<bits/stdc++.h>
using namespace std;
long long mincoins(int * denominations,int n,int values){
    const long long INF = 1e9;
    //vector<vector<long long>>dp(n,vector<long long>(values+1,INF));
    vector<long>prev(values+1,INF),curr(values+1,INF);
    for(int i=0;i<=values;i++){
       if(i%denominations[0]==0)
        prev[i]=i/denominations[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int j=0;j<=values;j++){
            long nottake=prev[j];
            long take=INF;
            if(denominations[ind]<=j ){
                take=1+curr[j-denominations[ind]];
            }
            curr[j]=min(take,nottake);
        }
        prev=curr;
    }
    return prev[values];
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
    long long ans=mincoins(a,n,t);
    if(ans>=1e9) cout<<"Not possible to make change"<<endl;
    else cout<<"Fewest coins to make change: "<<ans<<endl;
}