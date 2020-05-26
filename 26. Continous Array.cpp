class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) nums[i]=-1;
        }
        for(int i=1;i<nums.size();i++){
           nums[i]+=nums[i-1];
        }
        unordered_map<int,int>save;
        save[0]=-1;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(save.find(nums[i])!=save.end()){
                maxi=max(maxi,i-save[nums[i]]);
            }
            else
            save[nums[i]]=i;
        }
        
        
        return maxi;
    }
};