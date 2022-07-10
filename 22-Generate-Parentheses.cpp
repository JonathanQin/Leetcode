#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n){
        string res = "";
        vector<string>* ans = new vector<string>();
        recurse(res, n, *ans, 0, 0);
        return *ans;
    }
    void recurse(string res, int n, vector<string> &ans, int left, int right){
        int len = res.length();
        if(len == n*2){
            ans.push_back(res);
            return;
        }
        if(left > right){
            recurse(res + ')', n, ans, left, right+1);
            if(left != n){
                recurse(res + '(', n, ans, left+1, right);
            }
            return;
        }
        else if(left == right){
            recurse(res + '(', n, ans, left+1, right);
            return;
        }
    }
};

int main(){
    Solution solution;
    vector<string> res = solution.generateParenthesis(5);
    for(auto& val:res){
        cout<<val<<" ";
    }
    cout<<"\n";
    return 0;
}