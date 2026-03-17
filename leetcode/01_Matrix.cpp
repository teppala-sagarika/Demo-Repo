// ────────────────────────────────────────────────────────────
// Problem : 01 Matrix
// Platform: LeetCode
// URL     : https://leetcode.com/problems/01-matrix/submissions/1951219041/?utm=codolio
// Language: cpp
// Date    : 3/17/2026, 8:48:29 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(m*n)
// Space Complexity: O(n)
// Notes           : bfs
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});//{{row,col},step}
                    vis[i][j]=1;
                }
            }
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dis[r][c]=steps;
            for(int i=0;i<4;i++){
                int nr=r+delRow[i];
                int nc=c+delCol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},steps+1});
                }
            }
        }
        return dis;
    }
};