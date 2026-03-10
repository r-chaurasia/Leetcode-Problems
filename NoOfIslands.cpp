class Solution {
public:
    vector<vector<int>>dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j] = 1;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto a: dir){
                int nx = x+a[0];
                int ny = y+a[1];
                
                if(nx>=0 && ny>=0 && nx<m && ny<n) {
                    if(grid[nx][ny] == '1' && vis[nx][ny] == 0) {
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(302, vector<int>(302, 0));
        int cnt = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    bfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};