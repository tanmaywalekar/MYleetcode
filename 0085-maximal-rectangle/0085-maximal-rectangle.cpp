class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nxts(n,n),prvs(n,-1);
        stack<int> f,s;
        for(int i=n-1;i>=0;i--)
        {
            while(f.size())
            {
                if(heights[f.top()]>=heights[i])
                    f.pop();
                else
                    break;
            }
            if(f.size())
                nxts[i]=f.top();
            f.push(i);
        }
        for(int i=0;i<n;i++)
        {
            while(s.size())
            {
                if(heights[s.top()]>=heights[i])
                    s.pop();
                else
                    break;
            }
            if(s.size())
                prvs[i]=s.top();
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=i-(prvs[i]+1);
            int y=nxts[i]-1-i;
            ans=max(heights[i]*(y+x+1),ans);
        }
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>h(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i=0;i<matrix[0].size();i++)
        {
            h[0][i]=matrix[0][i]-'0';
        }
         for(int i=1;i<matrix.size();i++)
         {
             for(int j=0;j<matrix[0].size();j++ )
             {
                 if(matrix[i][j]=='0')
                 {
                     h[i][j]=0;
                 }
                 else
                 {
                     h[i][j]=h[i-1][j]+1;
                 }
             }
         }
        for(int i=0;i<matrix.size();i++)
         {
             for(int j=0;j<matrix[0].size();j++ )
             {
                 cout<<h[i][j]<<" ";
             }
            cout<<endl;
        }
        
        int ans=0;
         for(int i=0;i<matrix.size();i++)
         {
             ans=max(ans,largestRectangleArea(h[i]));
         }
        return ans;
    }
};