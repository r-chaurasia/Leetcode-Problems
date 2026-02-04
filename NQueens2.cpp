class Solution {
public:
    vector<vector<string>> ans;
    int N;
    bool safe(vector<string>&grid , int row , int col) {
        for(int i=row-1 ; i>=0 ; i--) {
            if(grid[i][col] == 'Q')
                return false;
        }

        for(int i=row-1 , j=col-1 ; i>=0 && j>=0 ; i-- , j--) {
            if(grid[i][j] == 'Q')
                return false;
        }

        for(int i=row-1 , j=col+1 ; i>=0 && j<N ; i-- , j++) {
            if(grid[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void board(vector<string>&grid , int row) {
        if(row >= N) {
            ans.push_back(grid);
            return;
        }

        for(int col=0 ; col<N ; col++) {
            if(safe(grid , row , col)) {
                grid[row][col] = 'Q';
                board(grid , row+1);
                grid[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        N = n;
        vector<string> grid(n , string(n , '.'));
        board(grid , 0);
        return ans.size();
    }
};