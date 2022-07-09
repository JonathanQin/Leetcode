#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief solves for the maximum score
     * 
     * @param nums array of numbers
     * @param k maximum step amount
     * @return int maximum score
     */
    int maxResult(vector<int>& nums, int k)
    {
        int len = nums.size();
        vector<int> res (len, 0);
        res[len-1] = nums[len-1];
        priority_queue<pair<int, int>> best;
        best.push(make_pair(res[len-1], len-1));
        for(int i = len - 2; i >= 0; i--){
            while(best.top().second > i + k){
                best.pop();
            }
            res[i] = nums[i] + best.top().first;
            best.push(make_pair(res[i], i));
        }
        return res[0];
    }
};

int main()
{
    Solution solution;
    vector<int> input = {1, -1, -2, 4, -7, 3};
    cout << solution.maxResult(input, 2) << "\n";
    return 0;
}