class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        int n = rooms.size();
        vector<int>vis(n+1,0);

        for(auto a:rooms[0])
            q.push(a);
        
        while(!q.empty()) {
            int node = q.front();
            vis[node] = 1;
            q.pop();

            for(auto a:rooms[node]) {
                if(vis[a] == 0) {
                    q.push(a);
                    vis[a] = 1;
                }
            }
        }

        for(int i=1; i<n; i++) {
            if(vis[i] == 0)
                return 0;
        }

        return 1;
    }
};