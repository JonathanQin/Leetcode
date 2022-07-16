#include <iostream>

using namespace std;

class Solution {
public:
    int MOD = 1000000007;
    int dp[51][51][51];
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long long memory[51][51][51];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k <= maxMove; k++){
                    memory[i][j][k] = -1;
                    dp[i][j][k] = 0;
                }
            }
        }
        int recursive_solution = recurse(m, n, maxMove, startRow, startColumn, 0, memory);
        int dp_solution = dpSolution(m, n, maxMove, startRow, startColumn);
        return dp_solution;
    }


    int dpSolution(int m, int n, int maxMove, int row, int col){
        int res = 0;
        dp[row][col][0] = 1;
        for(int k = 1; k <= maxMove; k++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(i != 0){
                        dp[i][j][k] = (dp[i][j][k]+dp[i-1][j][k-1])%MOD;
                    }
                    if(i != m-1){
                        dp[i][j][k] = (dp[i][j][k]+dp[i+1][j][k-1])%MOD;
                    }
                    if(j != 0){
                        dp[i][j][k] = (dp[i][j][k]+dp[i][j-1][k-1])%MOD;
                    }
                    if(j != n-1){
                        dp[i][j][k] = (dp[i][j][k]+dp[i][j+1][k-1])%MOD;
                    }
                }
            }
        }
        for(int k = 0; k < maxMove; k++){
            for(int i = 0; i < m; i++){
                res = (res+dp[i][0][k])%MOD;
                res = (res+dp[i][n-1][k])%MOD;
            }
            for(int j = 0; j < n; j++){
                res = (res+dp[0][j][k])%MOD;
                res = (res+dp[m-1][j][k])%MOD;
            }
        }
        return res;
    }

    template<int R, int C, int move>
    long long recurse(int m, int n, int maxMove, int row, int col, int cnt, long long(&memory)[R][C][move]){
        if(cnt > maxMove){
            return 0;
        }
        if(row < 0 || col < 0 || row == m || col == n){
            return 1;
        }
        if(memory[row][col][maxMove-cnt] >= 0)
        {
            return memory[row][col][maxMove-cnt];
        }
        memory[row][col][maxMove-cnt] = (recurse(m, n, maxMove, row-1, col, cnt+1, memory) + recurse(m, n, maxMove, row+1, col, cnt+1, memory) + recurse(m, n, maxMove, row, col+1, cnt+1, memory) + recurse(m, n, maxMove, row, col-1, cnt+1, memory))%MOD;
        return memory[row][col][maxMove-cnt]; 
    }
};

int main(){
    Solution solution;
    cout<<solution.findPaths(2, 2, 2, 0, 0);
    return 0;
}