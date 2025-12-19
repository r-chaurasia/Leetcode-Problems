class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<bool> hasSecret(n, false);
        hasSecret[0] = hasSecret[firstPerson] = true;

        int m = meetings.size();
        int i = 0;

        while (i < m) {
            int time = meetings[i][2];
            unordered_map<int, vector<int>> graph;
            unordered_set<int> people;

            // Collect all meetings at the same time
            while (i < m && meetings[i][2] == time) {
                int x = meetings[i][0], y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.insert(x);
                people.insert(y);
                i++;
            }

            queue<int> q;
            unordered_set<int> visited;

            // Start BFS from people who already know the secret
            for (int p : people) {
                if (hasSecret[p]) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            // Spread the secret within this time frame
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }

            // Mark all visited people as having the secret
            for (int p : visited) {
                hasSecret[p] = true;
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (hasSecret[i])
                result.push_back(i);
        }

        return result;
    }
};
