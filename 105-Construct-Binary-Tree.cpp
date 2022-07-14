#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int len = preorder.size();
        TreeNode* res = new TreeNode(preorder[0]);
        map<int, int>* order = new map<int, int>();
        for(int i = 0; i < len; i++){
            order->insert(make_pair(inorder[i], i));
        }
        int *pos = new int(1);
        makeTree(res, preorder, *order, *pos, nullptr);
        return res;
    }
    void makeTree(TreeNode* node, vector<int>& preorder, map<int, int>& order, int& i, TreeNode* parent){
        if(i == preorder.size()){
            return;
        }
        if(node->left == nullptr){
            if(order[node->val] > order[preorder[i]]){
                node->left = new TreeNode(preorder[i]);
                i+=1;
                makeTree(node->left, preorder, order, i, node);
            }
            else{
                node->left = nullptr;
            }
        }
        if(i == preorder.size()){
            return;
        }
        if(node->right == nullptr){
            if(order[node->val] < order[preorder[i]]){
                if(parent == nullptr) {
                    node->right = new TreeNode(preorder[i]);
                    i+=1;
                    makeTree(node->right, preorder, order, i, node);
                }
                else if(order[parent->val] > order[preorder[i]] && parent->left == node){
                    node->right = new TreeNode(preorder[i]);
                    i+=1;
                    makeTree(node->right, preorder, order, i, node);
                }
                else if(order[parent->val] < order[preorder[i]] && parent->right == node){
                    node->right = new TreeNode(preorder[i]);
                    i+=1;
                    makeTree(node->right, preorder, order, i, node);
                }
                else{
                    node->right = nullptr;
                }
            }
        }
        return; 
    }
};

int main(){
    Solution solution;
    vector<int>* preorder = new vector {3, 9, 20, 15, 7};
    vector<int>* inorder = new vector {9, 3, 15, 20, 7};
    TreeNode *ans = solution.buildTree(*preorder, *inorder);
    return 0;
}