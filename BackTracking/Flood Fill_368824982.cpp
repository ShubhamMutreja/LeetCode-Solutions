class Solution {
public:
    vector<vector<int>> v{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int old)
    {
        image[sr][sc] = newColor;
        for(int d=0;d<4;d++)
        {
            int r = sr + v[d][0];
            int c = sc + v[d][1];
            
            if(r<image.size() && c<image[0].size() && r>=0 && c>=0 && image[r][c] == old)
                dfs(image,r,c,newColor,old);
                
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size() == 0 || image[0].size()==0 || image[sr][sc] == newColor)
            return image;
        
        dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
        
        
    }
};
