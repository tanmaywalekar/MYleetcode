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
    map<int,vector<TreeNode*>> m;
     vector<TreeNode*> solve(int n)
     {
          if(m.find(n)!=m.end())
             return m[n];
        if(n==0)
            return {NULL};
         if(n==1)
         { TreeNode* z= new TreeNode(0);
             return{ z};
         }
        
          vector<TreeNode*> ans;
         for(int i=1;i<n;i+=2)
         {
             vector<TreeNode*> l=solve(i);
             vector<TreeNode*> r=solve((n-i-1));
             for(auto x:l)
             {
                 for(auto y:r)
                 {
                    TreeNode* z= new TreeNode(0);
                     z->left=x;
                     z->right=y;
                     ans.push_back(z);
                 }
             }
         }
           return m[n]=ans;  
     }
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if(n%2==0)
        {
           vector<TreeNode*> v;
            return v;
        };
        return solve(n);
    }
};