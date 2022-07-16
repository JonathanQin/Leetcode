#include <iostream>

using namespace std;

class Solution {
public:
    int MOD = 1000000007;
    long long memory[51][51][51];
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int res = 0;
        for(int i = 0; i < 51; i++){
            for(int j = 0; j < 51; j++){
                for(int k = 0; k < 51; k++){
                    memory[i][j][k] = -1;
                }
            }
        }
        return recurse(m, n, maxMove, startRow, startColumn, 0);
    }

    long long recurse(int m, int n, int maxMove, int row, int col, int cnt){
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
        memory[row][col][maxMove-cnt] = (recurse(m, n, maxMove, row-1, col, cnt+1) + recurse(m, n, maxMove, row+1, col, cnt+1) + recurse(m, n, maxMove, row, col+1, cnt+1) + recurse(m, n, maxMove, row, col-1, cnt+1))%MOD;
        return memory[row][col][maxMove-cnt]; 
    }
};

int main(){
    Solution solution;
    cout<<solution.findPaths(2, 2, 2, 0, 0);
    return 0;
}