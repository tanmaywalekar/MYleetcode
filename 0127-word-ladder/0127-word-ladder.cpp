class Solution {
public:
    int ladderLength(string a, string e, vector<string>& w) {
        unordered_map<string,int>m;
        for(auto i:w)
        {
            m[i]=0;
        }
        if(m.find(a)!=m.end())
            m[a]=1;
        int d=0;
        queue<string> q;
        q.push(a);
        while(q.size())
        {  
            
            int s=q.size();
            while(s--)
            {
                string z=q.front();
                if(z==e)
                    return d+1;
                q.pop();
                for(int i=0;i<z.size();i++)
                {  char x=z[i];
                    for(char c='a';c<='z';c++)
                    {
                        z[i]=c;
                        if(m.find(z)!=m.end()&&m[z]==0)
                        {
                            m[z]=1;
                            q.push(z);
                        }
                        
                    }
                 z[i]=x;
                }
            }
            d++;
        }
        return 0;
    }
};