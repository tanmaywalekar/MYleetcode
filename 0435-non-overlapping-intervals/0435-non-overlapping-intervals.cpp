class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& iv) {
        sort(iv.begin(),iv.end());
        int e=iv[0][1];
  
        int c=0;
        for(int i=1;i<iv.size();i++)
        {
            if(e<=iv[i][0])
            {   // f=iv[i][0];
                e=iv[i][1];
            }
            else
            {  c++;
             e=min(e,iv[i][1]);
            }
        }
        return c;
    }
};