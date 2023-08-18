class Solution {
public:
    bool isoddcycle(int i,int p,vector<vector<int>>& graph,vector<int> &v,vector<int> &clr,int cl)
    {
        v[i]=1;
        clr[i]=cl;
       bool ans=false;
        for(auto c:graph[i])
        {
            if(v[c]==0)
            {  
               ans= ans|isoddcycle(c,i,graph,v,clr,cl^1);
            }
            else
            {
                if(c!=p)
                {
                    if(clr[i]==clr[c])
                        return true;
                   
                }
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& g) {
        
        
        vector<int> v(g.size(),0);
        vector<int> clr(g.size(),-1);
        for(int i=0;i<g.size();i++)
        {
            if(v[i]==0)
            {
             if(isoddcycle(i,-1,g,v,clr,0))
             {
                 return false;
             }
            }
        }
        return true;
    }
};