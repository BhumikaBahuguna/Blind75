#include<bits/stdc++.h>
using namespace std;
int f(int i,int j ,string &s,string &t){
    if(i<0 ||j<0) return 0;
    if(s[i]==t[j]) return 1+f(i-1,j-1,s,t);
    return max(f(i-1,j,s,t),f(i,j-1,s,t));
}
int lcs(string s,string t){
    int n=s.size();
    int m=t.size();
    return f(n-1,m-1,s,t);
}
int main(){
    string s,t;
    cout<<"Enter first string: ";
    cin>>s;
    cout<<"Enter second string: ";
    cin>>t;
    cout<<"Length of Longest Common Subsequence: "<<lcs(s,t)<<endl;
    return 0;
}
