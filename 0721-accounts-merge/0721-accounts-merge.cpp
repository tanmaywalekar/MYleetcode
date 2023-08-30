class Solution {
public:
       int find(int i,vector<int> &v)
{
    while(1)
    {
        if(v[i]<0)
        {
            break;
        }
        i=v[i];
    }
    return i;
}
void uni(int i,int j,vector<int>&v)
{
    int x=find(i,v);
    int y=find(j,v);
    if(x==y)
    return;
    if(v[x]<v[y])
    {
        v[x]+=v[y];
        v[y]=x;
    }
    else
    {
        v[y]+=v[x];
        v[x]=y;
    }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<int,string> st;
        map<string,int> in;
        map<string,string>p;
        int c=0;
        for(auto v:accounts)
        {  
            
            for(int i=1;i<v.size();i++)
            {   
                p[v[i]]=v[0];
                if(in.find(v[i])==in.end()){
                st[c]=v[i];
                in[v[i]]=c;
                c++;}
            }
        }
        vector<int> g(c,-1);
        for(auto v:accounts)
        {
            for(int i=2;i<v.size();i++)
            {
                uni(in[v[i]],in[v[i-1]],g);
            }
        }
        
        
        vector<vector<string>> ans;
        map<int,vector<string>> m;
        for(int i=0;i<g.size();i++)
        {
            int x=find(i,g);
            m[x].push_back(st[i]);
        }
        for(auto &i:m)
        {  
            sort(i.second.begin(),i.second.end());
            vector<string> v;
            v.push_back(p[st[i.first]]);
            for(auto &s:i.second)
                v.push_back(s);
            ans.push_back(v);
            
            
        }
        return ans;
    }
};