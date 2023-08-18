class Solution {
public:
    vector<int> l{0,-1,0,1,0};
    void dfs(int i,int j, int c,int o,vector<vector<int>>& image)
    {
        image[i][j]=c;
        for(int x=0;x<4;x++)
        {  
            int a=i+l[x];
            int b=j+l[x+1];
            if(a>=0&&b>=0&&a<image.size()&&b<image[0].size()&&image[a][b]==o)
            { 
                dfs(a,b,c,o,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]==color)
            return image;
        dfs(sr,sc,color,image[sr][sc],image);
        return image;
    }
};