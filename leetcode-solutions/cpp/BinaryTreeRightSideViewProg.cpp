// BINARY TREE RIGHT SIDE VIEW (LEETCODE 199) SOLUTION 
// Question : https://leetcode.com/problems/binary-tree-right-side-view/

//--------------------------------------------------------------------------

/*
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
    vector<int> ans;
    
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return ans;
        
		queue<TreeNode*>q;
        q.push(root);
        
		// Level order transversal
		while(!q.empty()){
            int s=q.size();
            int dat=0;
			
            while(s){
                TreeNode*temp=q.front();
                q.pop();
                dat=temp->val;
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
                s--;
            }
			
			// Simply push ush the last value
            ans.push_back(dat);
        }
        return ans;
    }
};
