#include <iostream>

using namespace std;

class Solution {
public: 
    int numTrees(int n){
        if(n == 0 || n == 1){
            return 1;
        }
        int arr[n+1];
        arr[0] = 1; arr[1] = 1;
        for(int i = 2; i <= n; i++){
            arr[i] = 0;
            for(int j = 0; j < i; j++){
                arr[i] += arr[j]*arr[i-j-1];
            }
        }
        return arr[n];
    }
};

int main(){
    Solution solution;
    cout << solution.numTrees(4);
    return 0;
}