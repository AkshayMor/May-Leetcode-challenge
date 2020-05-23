class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>vect;
        int a=A.size();
        int b=B.size();
        int i=0,j=0;
        while(i<a && j<b){
            int low=max(A[i][0],B[j][0]);
            int high=min(A[i][1],B[j][1]);
            if(low<=high)
                vect.push_back({low,high});
            if(A[i][1]<B[j][1])
                i++;
            else
                j++;
        }
        return vect;
    }
};