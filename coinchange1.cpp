#include<bits/stdc++.h>
using namespace std;
long f(int ind,int t,int *a){
    if(ind==0){
        if(t%a[0]==0) return t/a[0];
        return 1e9;
    }
    long nottake=f(ind-1,t,a);
    long take=1e9;
    if(a[ind]<=t) take=1+f(ind,t-a[ind],a);
    return min(take,nottake);
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
    int ans=f(n-1,t,a);
    if(ans>=1e9) cout<<"Not possible to make change"<<endl;
    else cout<<"Number of ways to make change: "<<ans<<endl;
    return 0;
}