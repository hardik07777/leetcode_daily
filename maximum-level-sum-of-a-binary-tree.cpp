/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int sum = INT_MIN;
        int currlevel = 1;
        int ans = 0;
        queue<TreeNode*> levelorder;
        levelorder.push(root);
        while(!levelorder.empty()){
            int n = levelorder.size();
            int currsum = 0;
            while(n--){
                auto curr = levelorder.front();
                levelorder.pop();
                currsum += curr->val;
                if(curr -> left != NULL){
                    levelorder.push(curr->left);
                }
                if(curr -> right != NULL){
                    levelorder.push(curr->right);
                }
            }
            if(sum < currsum){
                sum = currsum;
                ans = currlevel;

            }
            currlevel ++;

        }
        return ans;
        
    }
};