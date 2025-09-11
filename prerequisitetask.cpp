#include<bits/stdc++.h>
using namespace std;
class Solution{
public :
bool ispossible(int v,vector<pair<int,int>>& prerequisites){
    vector<int> adj[v];
    for(auto it: prerequisites){
        adj[it.first].push_back(it.second);
    }
    int indegree[v]={0};
    for(int i=0;i<v;i++){
        for(auto it :adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    if(topo.size()==v) return true;
    return false;
}
};
int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> prerequisites;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        prerequisites.push_back({u,v});
    }
    Solution obj;
    if(obj.ispossible(n,prerequisites)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}