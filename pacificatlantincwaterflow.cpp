#include<bits/stdc++.h>
using namespace std;
class Solution{
    public :
vector<vector<int>>pacificatlantic(vector<vector<int>>&heights){
    int ROWS=heights.size();
    int COLS =heights[0].size();
    vector<vector<int>>res;
    set<pair<int,int>>pac,atl;
    function<void(int,int,set<pair<int,int>>&,int)> dfs=[&](int r,int c,set<pair<int,int>>&visit,int prevheight){
        if(visit.count({r,c}) || r<0 || c<0 ||r==ROWS ||c==COLS|| heights[r][c]<prevheight)
            return;
        visit.insert({r,c});
        dfs(r+1,c,visit,heights[r][c]);
        dfs(r-1,c,visit,heights[r][c]);
        dfs(r,c+1,visit,heights[r][c]);
        dfs(r,c-1,visit,heights[r][c]);
    };
     // Pacific & Atlantic borders
        for (int c = 0; c < COLS; c++) {
            dfs(0, c, pac, heights[0][c]);
            dfs(ROWS-1, c, atl, heights[ROWS-1][c]);
        }
        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, pac, heights[r][0]);
            dfs(r, COLS-1, atl, heights[r][COLS-1]);
        }
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac.count({r,c}) && atl.count({r,c})) {
                    res.push_back({r,c});
                }
            }
        }
    return res;

}
};
int main() {
    Solution sol;
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    vector<vector<int>> heights(rows, vector<int>(cols));
    cout << "Enter the matrix values:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> heights[i][j];
        }
    }
    // Call function
    vector<vector<int>> output = sol.pacificatlantic(heights);
    // Print output in required format
    cout << "Output: [";
    for (int i = 0; i < output.size(); i++) {
        cout << "[" << output[i][0] << "," << output[i][1] << "]";
        if (i != output.size()-1) cout << ",";
    }
    cout << "]" << endl;
    return 0;
}