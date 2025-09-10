#include<bits/stdc++.h>
using namespace std;
int uniquepaths(int m,int n){
    int N=n+m-2;
    int r=m-1;
    double res=1;
    for(int i=1;i<=r;i++){
        res=res*(N-r+i)/i;
    }
    return (int) res;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<uniquepaths(n,m);
    return 0;
}