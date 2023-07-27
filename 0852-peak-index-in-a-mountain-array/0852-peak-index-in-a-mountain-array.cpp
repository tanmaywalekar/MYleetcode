class Solution {
public:
    int peakIndexInMountainArray(vector<int> n) {
           int s=n.size();
        if(n.size()==1)
            return 0;
      
        int l=1;
        int h=s-1;
        while(h>=l)
        {
            int m=l+(h-l)/2;
            if(n[m]>n[m+1]&&n[m]>n[m-1])
                return m;
            else if(n[m]>n[m-1]&&n[m]<n[m+1])
            {
                l=m+1;
            }
            else
                h=m-1;
        }
        return -1;
        
    }
};