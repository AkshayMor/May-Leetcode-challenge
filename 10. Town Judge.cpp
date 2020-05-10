class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
// create a set of people which trust others
        set<int>people;
        for(int i=0;i<trust.size();i++){
            people.insert(trust[i][0]);
        }
//    if size of unique  set people of people is not equal to (total-1) 
//    than no judge is present
        if(people.size()!=(N-1)) return -1;
        else{
            int judge,k=1;
            // find the judge by finding missing value in set
            for(auto i:people){
                if(i!=k){
                    judge=k;
                    break;
                }
                k++;
            }
            int count=0;
            // count of people whom trust judge  
            for(int i=0;i<trust.size();i++){
                if(trust[i][1]==judge)
                    count++;
            }
            // if count is equal to (total-1) return judge
            if(count==(N-1)) return judge;
            else return -1;
        }
        return -1;
    }
};