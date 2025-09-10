#include<bits/stdc++.h>
using namespace std;
bool jumpgame(vector<int>&nums){
    int n=nums.size();
    int maxind=0;
    for(int i=0;i<n;i++){
        if(i>maxind) return false;
        maxind=max(maxind,i+nums[i]);
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout << boolalpha  <<jumpgame(arr);
    return 0;
}