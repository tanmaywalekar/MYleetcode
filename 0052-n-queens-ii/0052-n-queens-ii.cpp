class Solution {
public:
    vector<vector<int>> ans;
bool check(int i,int j, vector<vector<int>>&g)
{
    
    for(int k=0;k<g.size();k++)
    {
        if(g[i][k])
        return false;
        if(g[k][j])
        return false;
    }
    int x=i;
    int y=j;
    while(x<g.size()&&y<g.size())
    {
        if(g[x][y])
        return false;
        x++;
        y++;
    }
    x=i;
    y=j;
    while(x>=0&&y>=0)
    {
        if(g[x][y])
        return false;
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0&&y<g.size())
    {
        if(g[x][y])
        return false;
        x--;
        y++;
    }
    return true;
    x=i;
    y=j;
    while(x<g.size()&&y>=0)
    {
        if(g[x][y])
        return false;
        x++;
        y--;
    }
}
 
 void rec(int i,vector<vector<int>>&g,vector<int> &v)
 {  
     if(i>g.size())
     {
         ans.push_back(v);
         return;
     }
     for(int j=1;j<=g.size();j++)
     {
         if(check(i-1,j-1,g))
         {   g[i-1][j-1]=1;
             v.push_back(j);
             rec(i+1,g,v);
             g[i-1][j-1]=0;
             v.pop_back();
         }
     }
 }
    int totalNQueens(int n) {
        vector<vector<int>> g(n,vector<int>(n,0));
        vector<int> v;
        rec(1,g,v);
        return ans.size();
    }
};