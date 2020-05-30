class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<float,int>>dis;
        int i=0;
        for(auto p:points){
            float dist= (float)sqrt(p[0]*p[0]+p[1]*p[1]);
            dis.push_back({dist,i});
            i++;
        }
        sort(dis.begin(),dis.end());
        vector<vector<int>> pairs;
        auto it=dis.begin();
        while(K--){
            pairs.push_back(points[it->second]);
            it++;
        }
        return pairs;
    }
};