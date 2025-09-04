#include<bits/stdc++.h>
using namespace std;
int f(int ind,int prev_ind,int arr[],int n){
    if(ind==n) return 0;
    int len=0+f(ind+1,prev_ind,arr,n);
    if(prev_ind==-1 ||arr[ind]>arr[prev_ind]){
        len=max(len,1+f(ind+1,ind,arr,n));
    }
    return len;
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Length of Longest Increasing Subsequence: "<<f(0,-1,arr,n)<<endl;
    return 0;
}