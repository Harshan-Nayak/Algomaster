#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
            }
            if (board[rows - 1][i] == 'O') {
                q.push({rows - 1, i});
            }
        }
            
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
            }
            if (board[i][cols - 1] == 'O') {
                q.push({i, cols - 1});
            }
        }

        vector<vector<int>> safe(rows, vector<int>(cols, 0));
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while (!q.empty()) {

            int sz = q.size();
            while(sz--){


            int r = q.front().first;
            int c = q.front().second;
            safe[r][c] = 1;
            q.pop();

            for (int i = 0; i < dx.size(); i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'O' && !safe[nr][nc]) {
                    safe[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
            }


        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!safe[i][j]) {
                    if (board[i][j] == 'O') {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};