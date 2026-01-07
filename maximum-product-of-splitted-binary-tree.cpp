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
int mod = 1e9 +7;
long long maxp = 0;
long long totalsum = 0;
    long long helper2(TreeNode* root){
          if(root == NULL){
            return 0;
          }
          
          long long left = helper2(root-> left);
          long long right = helper2(root-> right);
          long long subtreesum = root -> val + left + right;
          maxp = max(maxp ,subtreesum * (totalsum - subtreesum));
          return subtreesum;
    }
    long long helper(TreeNode* root){

        if(root == NULL){
            return 0;
        }
        return root -> val + helper(root-> left) + helper(root -> right);
       
    }
    int maxProduct(TreeNode* root) {
        totalsum = helper(root);
        helper2(root);
        return maxp % mod;
    }
};