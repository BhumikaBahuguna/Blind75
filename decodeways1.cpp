#include<bits/stdc++.H>
using namespace std;
int numdecodings(string s){
    int n=s.length();
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=(s[0]=='0')?0:1;
    for(int i=2;i<=n;i++){
        int one_digit=stoi(s.substr(i-1,1));
        int two_digit=stoi(s.substr(i-2,2));
        if(one_digit>=1){
            dp[i]+=dp[i-1];
        }
        if(two_digit>=10 && two_digit<=26){
            dp[i]+=dp[i-2];
        }
    }
    return dp[n];
}
int main(){
    string s;
    cin>>s;
    cout<<numdecodings(s);
    return 0;
}