class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc,int color, int newColor){
        if(sr-1>=0 && image[sr-1][sc]==color){
            image[sr-1][sc]=newColor;
            fill(image,sr-1,sc,color,newColor);
        }
        if(sr+1<image.size() && image[sr+1][sc]==color){
            image[sr+1][sc]=newColor;
            fill(image,sr+1,sc,color,newColor);
        }
        if(sc-1>=0 && image[sr][sc-1]==color){
            image[sr][sc-1]=newColor;
            fill(image,sr,sc-1,color,newColor);
        }
        if(sc+1<image[0].size() && image[sr][sc+1]==color){
            image[sr][sc+1]=newColor;
            fill(image,sr,sc+1,color,newColor);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color=image[sr][sc];
//    If newColor is same as starting previous color of starting pixels than input image is the answer 
        if(color==newColor) return image;
        image[sr][sc]=newColor;
//         Recursive Call
        fill(image,sr,sc,color,newColor);
        return image;
    }
};