#include<bits/stdc++.h>
using namespace std;



  //Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> v;
        
        if(root == nullptr)
            return v;
        
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        
        while(q.empty() == false)
        {
            vector<int> level;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* curr = q.front();
                level.push_back(curr->val);
                q.pop();
                
                if(curr->left != nullptr)
                    q.push(curr->left);
                
                if(curr->right != nullptr)
                    q.push(curr->right);
            }   
            v.push_back(level);
        }
        
        return v;
        
    }
};