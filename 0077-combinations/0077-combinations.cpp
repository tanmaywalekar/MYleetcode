class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void rec(int i,vector<int>& v,int k)
    {   
        if(i==n+2)
            return;
        if(v.size()==k)
        {
            ans.push_back(v);
            return;
        }
        rec(i+1,v,k);
        v.push_back(i);
        rec(i+1,v,k);
        v.pop_back();
    }
    vector<vector<int>> combine(int c, int k) {
        n=c;
        vector<int>v;
        rec(1,v,k);
        return ans;
    }
};