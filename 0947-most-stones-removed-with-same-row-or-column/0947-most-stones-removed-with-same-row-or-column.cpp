class Solution {
public:
    int finddsu(int a,vector<int> &p)
{  
	while(p[a]>=0)
	{
		
		
		{  
			a=p[a];
		}
	}
        return a;
}
void uni(int a,int b,vector<int> &p)
{if(a==b)
		return;
	a=finddsu(a,p);
	b=finddsu(b,p);
	if(a==b)
		return;
	else
	{   
	    if(p[b]>p[a])
	    {
	    	p[a]+=p[b];
	    	
		p[b]=a;
	    }
	    else
	    {
	    	p[b]+=p[a];
		p[a]=b;
	    }
		
	}
}
    int removeStones(vector<vector<int>>& s) {
        int n=s.size();
        vector<int> v(n,-1);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i][0]==s[j][0]||s[j][1]==s[i][1])
                {
                    uni(i,j,v);
                }
            }
        }
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<0)
            {
                int z=-1*v[i];
                z--;
                ans+=z;
            }
        }
        return ans;
    }
};