#include<bits/stdc++.h>
using namespace std;
class Solution{
public :
vector<int> findOrder(int v,vector<vector<int>>& prerequisites){
    vector<int> adj[v];
    for(auto it: prerequisites){
        adj[it[1]].push_back(it[0]);
    }
    vector<int> indegree(v, 0);
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
    if((int)topo.size()==v) return topo;
    return {};
}
};
int main() {
    int numCourses, e;
    cin >> numCourses >> e;

    vector<vector<int>> prerequisites(e, vector<int>(2));
    for (int i = 0; i < e; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    Solution obj;
    vector<int> order = obj.findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "Output: []\n";
    } else {
        cout << "Output: [";
        for (int i = 0; i < order.size(); i++) {
            cout << order[i];
            if (i != order.size() - 1) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}