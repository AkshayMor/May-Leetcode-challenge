class Solution {
public:
    typedef long long ll;
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        if(coordinates.size()==2) return true;
        ll y=coordinates[1][1]-coordinates[0][1];
        ll x=coordinates[1][0]-coordinates[0][0];
        ll dx,dy;

        for(int i=1;i<coordinates.size()-1;i++){
            dy=coordinates[i+1][1]-coordinates[0][1];
            dx=coordinates[i+1][0]-coordinates[0][0];
// instead of using slope slope by x/y we can check through cross multiplication to avoid zero division
            if(x*dy!=y*dx)
                return false;
        }
        return true;
    }
};