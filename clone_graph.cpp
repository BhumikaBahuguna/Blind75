#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors() {}
    Node(int _val) : val(_val), neighbors() {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp) {
        if (!cur) return nullptr;
        Node* clone = new Node(cur->val);
        mp[cur] = clone;
        for (Node* nb : cur->neighbors) {
            if (mp.count(nb)) clone->neighbors.push_back(mp[nb]);
            else clone->neighbors.push_back(dfs(nb, mp));
        }
        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> adjList(n);
    string line;
    getline(cin, line); // consume endline after n

    // read n lines of neighbors (space-separated)
    for (int i = 0; i < n; ++i) {
        getline(cin >> ws, line);
        stringstream ss(line);
        int x;
        while (ss >> x) adjList[i].push_back(x);
    }

    // build original graph nodes (1-based values)
    vector<Node*> nodes(n + 1, nullptr);
    for (int i = 1; i <= n; ++i) nodes[i] = new Node(i);
    for (int i = 0; i < n; ++i) {
        for (int nb : adjList[i]) {
            if (nb >= 1 && nb <= n) nodes[i + 1]->neighbors.push_back(nodes[nb]);
        }
    }

    // clone
    Solution sol;
    Node* clonedRoot = nullptr;
    if (n >= 1) clonedRoot = sol.cloneGraph(nodes[1]);

    // print original in index order
    cout << "\nOriginal Graph:\n";
    for (int i = 1; i <= n; ++i) {
        cout << i << ":";
        for (Node* nb : nodes[i]->neighbors) cout << " " << nb->val;
        cout << "\n";
    }

    // collect cloned nodes by value (val preserved in clone)
    vector<Node*> clonedNodes(n + 1, nullptr);
    if (clonedRoot) {
        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(clonedRoot);
        visited.insert(clonedRoot);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            if (cur->val >= 1 && cur->val <= n) clonedNodes[cur->val] = cur;
            for (Node* nb : cur->neighbors) {
                if (!visited.count(nb)) {
                    visited.insert(nb);
                    q.push(nb);
                }
            }
        }
    }

    // print cloned in index order
    cout << "\nCloned Graph:\n";
    for (int i = 1; i <= n; ++i) {
        cout << i << ":";
        if (clonedNodes[i]) {
            for (Node* nb : clonedNodes[i]->neighbors) cout << " " << nb->val;
        }
        cout << "\n";
    }

    return 0;
}
