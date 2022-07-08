#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

/**
 * @brief solution to leetcode problem #85
 * 
 * @param matrix 2d vector of input boolean grid
 * @return area of largest rectangle of 1s
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> grid(0);
        for(int i = 0; i < row; i++){
            grid.push_back(vector<int>(0));
            for(int j = 0; j < col; j++){
                grid[i].push_back(matrix[i][j] - '0');
            }
        }
        int res = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i != 0 && grid[i][j] != 0){
                    grid[i][j] += grid[i-1][j];
                }
            }
            for(int j = 0; j < col; j++){
                pair<int, int> area (0, INT_MAX);
                for(int k = j; k < col; k++)
                {
                    if(grid[i][k] == 0){
                        break;
                    }
                    area.first++;
                    area.second = (area.second < grid[i][k] ? area.second : grid[i][k]);
                    res = (area.first*area.second > res ? area.first*area.second : res);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> input1{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'}, 
        {'1', '0', '0', '1', '0'}
    };
    vector<vector<char>> input2{
        {'1', '0'},
        {'0', '1'}
    };
    cout<<solution.maximalRectangle(input1);
    return 0;
}