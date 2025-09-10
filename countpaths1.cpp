#include<bits/stdc++.h>
using namespace std;
int countpaths(int i,int j,int n,int m){
    if(i==(n-1) && j==(m-1)) return 1;
    if(i>=n || j>=m ) return 0;
    else return countpaths(i+1, j, n, m) + countpaths(i, j+1, n, m);
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<countpaths(0,0,n,m);
    return 0;
}