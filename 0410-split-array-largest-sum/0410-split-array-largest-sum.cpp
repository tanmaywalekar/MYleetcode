class Solution {
public:
    int f(vector<int>& arr, int p)
{
    int s=1;
    int c=0;
    for(int i=0;i<arr.size();i++)
    {
        if(c+arr[i]<=p)
        c+=arr[i];
        else
        {
            s++;
            c=arr[i];
        }
    }
    return s;
}
    int splitArray(vector<int>& arr, int m) {
        int n=arr.size();
        int l=0;
    int h=0;
    if(n<m)
    return -1;
    for(auto i:arr)
    {
        h+=i;
        l=max(l,i);
    }
    int ans=INT_MAX;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        int s=f(arr,mid);
       // cout<<mid<<"  "<<s<<",,";
        if(s<=m)
        {
            ans=min(ans,mid);
            h=mid-1;
        }
        else
        l=mid+1;
    }
    return ans;
    }
};