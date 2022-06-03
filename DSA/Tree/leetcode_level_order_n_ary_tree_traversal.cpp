#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
         vector<vector<int>> v;
        
        if(root == nullptr)
            return v;
        
        
        queue<Node*> q;
        
        q.push(root);
        
        
        while(q.empty() == false)
        {
            vector<int> level;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                Node* curr = q.front();
                level.push_back(curr->val);
                q.pop();
                
                int k = curr->children.size();
                
                for(int i = 0; i < k; i++)
                {
                    q.push(curr->children[i]);
                }
                
            }   
            v.push_back(level);
        }
        
        
        return v;
        
        
    }
};