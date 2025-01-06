class Solution {
public:

vector<int>dx={-1,0,1,0};
vector<int>dy={0,1,0,-1};


void dfs(int row,int col, vector<vector<bool>>&vis,vector<vector<int>>& heights){
    vis[row][col]=true;
    for(int i=0;i<dx.size();i++){
        int nr = row+dx[i];
        int nc = col+dy[i];
    if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && !vis[nr][nc] && heights[nr][nc]>=heights[row][col] ){
        dfs(nr,nc,vis,heights);
    }
    }


}



    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>>result;

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>>visp(rows,vector<bool>(cols,false));
        vector<vector<bool>>visa(rows,vector<bool>(cols,false));

        for(int col=0;col<cols;col++){
            dfs(0,col,visp,heights);
        }

         for(int row=0;row<rows;row++){
            dfs(row,0,visp,heights);
        }

         for(int col=0;col<cols;col++){
            dfs(rows-1,col,visa,heights);
        }

         for(int row=0;row<rows;row++){
            dfs(row,cols-1,visa,heights);
        }


        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(visa[i][j] && visp[i][j]){
                    result.push_back({i,j});
                }
            }
        }

























        return result;
        
    }
};