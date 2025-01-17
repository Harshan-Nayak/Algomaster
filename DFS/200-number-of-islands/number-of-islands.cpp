class Solution {
public:
vector<int>dx={-1,0,1,0};
vector<int>dy={0,1,0,-1};

void dfs(int row,int col,vector<vector<char>>& grid, vector<vector<bool>>&vis,int n,int m){
    vis[row][col]=true;
    for(int i=0;i<dx.size();i++){
        int nr = row+dx[i];
        int nc = col+dy[i];
           if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1') {
                dfs(nr, nc, grid, vis, n, m);
            }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;
        vector<vector<bool>>vis(n,vector<bool>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,vis,n,m);
                    islands++;
                }
            }
        }


        return islands;
        
    }
};