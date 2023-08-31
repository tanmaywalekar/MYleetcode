class Solution {
public:
    map<pair<int,int>,int>m;
    int rec(int i,int e, vector<pair<int,int>>&v)
    {  
        
        if(i==v.size())
        {  
            
            if(e==v.size()-1)
            {//cout<<e<<" "<<v.size()-1<<",";
                return m[{i,e}]=0;
            }
            else
                return m[{i,e}]=1e7;
        }
        if(m.find({i,e})!=m.end())
            return m[{i,e}];
        if(e==-1)
        {
            if(v[i].first>0)
                return m[{i,e}]=1e7;
            else
            {
                
                return m[{i,e}]=min(rec(i+1,e,v),1+rec(i+1,v[i].second,v));
            }
        }
        else
        {
            if(v[i].first>e)
                return m[{i,e}]=1e7;
            else
            {  if(v[i].second<=e)
                return m[{i,e}]=rec(i+1,e,v);
             else
                return m[{i,e}]=min(rec(i+1,e,v),1+rec(i+1,max(v[i].second,e),v));
            }
        }
    }
    int minTaps(int n, vector<int>& ranges) {
        
       vector<pair<int,int>>v;
        for(int i=0;i<ranges.size();i++)
        {
            v.push_back({max(0,i-ranges[i]),min(i+ranges[i],n)});
            
        }
       
        sort(v.begin(),v.end());
       
        if(v[0].first>0)
            return -1;
       int x= rec(0,-1,v);
        if(x==1e7)
            return -1;
        else
            return x;
    }
};