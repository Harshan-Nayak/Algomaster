class Solution {
public:

vector<int>dx={-1,0,1,0};
vector<int>dy={0, 1, 0, -1};

void dfs(vector<vector<char>>& grid, vector<vector<bool>>&vis,int row, int col,int r,int c){
    vis[row][col]=true;

for(int i=0;i<dx.size();i++){
    int nr = row+dx[i];
    int nc = col+dy[i];

    if(nr>=0 && nr<r && nc>=0 && nc<c && grid[nr][nc]=='1' && !vis[nr][nc] ){
         dfs(grid,vis,nr,nc,r,c);
    }
}


}




    int numIslands(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<bool>>vis(r,vector<bool>(c,false));

        int ans = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid,vis,i,j,r,c);
                    ans ++;
                }
            }
        }
        

        return ans;


    }
};