class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>dp(num+1,0);
        for(int i=1;i<=num;i++){
            dp[i]=dp[i/2];
            if(i%2) dp[i]++;
        }
        return dp;
        
    }
};