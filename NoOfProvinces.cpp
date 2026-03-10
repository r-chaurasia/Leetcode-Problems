class Solution {
public:
    void bfs(int x, vector<int>& vis, vector<int>adj[]) {
        queue<int>q;
        q.push(x);
        
        while(!q.empty()) {
            int ele = q.front();
            q.pop();
            vis[ele] = 1;

            for(auto a: adj[ele]){
                if(vis[a] == 0) {
                    vis[a] == 1;
                    q.push(a);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n+1];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }

        int count = 0;
        vector<int>vis(n+1, 0);

        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                bfs(i, vis, adj);
                count++;
            }
        }

        return count;
    }
};