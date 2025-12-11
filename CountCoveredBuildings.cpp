class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        // r2c -> row to sorted set of columns
        // c2r -> column to sorted set of rows
        map<int, set<int>> r2c;
        map<int, set<int>> c2r;

        // Build maps
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            r2c[x].insert(y);
            c2r[y].insert(x);
        }

        int count = 0;

        // Check each building
        for (auto& b : buildings) {
            int x = b[0], y = b[1];

            auto& rowSet = r2c[x];
            auto& colSet = c2r[y];

            // LEFT = element < y
            auto it = rowSet.lower_bound(y);
            bool hasLeft = (it != rowSet.begin());

            // RIGHT = element > y
            bool hasRight = false;
            if (it != rowSet.end()) {
                auto it2 = next(it);
                hasRight = (it2 != rowSet.end());
            }

            // UP = element < x
            auto it2 = colSet.lower_bound(x);
            bool hasUp = (it2 != colSet.begin());

            // DOWN = element > x
            bool hasDown = false;
            if (it2 != colSet.end()) {
                auto it3 = next(it2);
                hasDown = (it3 != colSet.end());
            }

            if (hasLeft && hasRight && hasUp && hasDown) {
                count++;
            }
        }

        return count;
    }
};