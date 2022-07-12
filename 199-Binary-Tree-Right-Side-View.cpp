#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public: 
    vector<int> rightSideView(TreeNode* root){
        vector<int>* res = new vector<int>();
        traverse(root, 0, *res);
        return *res;
    }
    void traverse(TreeNode* node, int level, vector<int>& res){
        if(node == nullptr){
            return;
        }
        if(res.size() == level){
            res.push_back(node->val);
        }
        traverse(node->right, level+1, res);
        traverse(node->left, level+1, res);
        return;
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    vector<int> res = solution.rightSideView(root);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] <<"\n";
    }
    return 0;
}