class Solution {
public:

    bool bfs(int node, vector<int>&col,vector<vector<int>>& graph ){
        queue<int> q;  // Queue to store nodes for BFS
        q.push(node);  // Start BFS from the given node
        col[node] = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                 for (int neighbor : graph[node]) {
                if (col[neighbor] == -1) {  // If the neighbor is uncolored
                    col[neighbor] = 1 - col[node];  // Color it with the opposite color
                    q.push(neighbor);  // Add it to the queue for further exploration
                } else if (col[neighbor] == col[node]) {  // If the neighbor has the same color as the current node
                    return false;  // This means the graph is not bipartite
                }
            }
            }
        }

return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int>col(n,-1);

        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!bfs(i,col,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};