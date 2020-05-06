class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ind=0,count=0;
//         cancel the pair of two different value so that remains only majority element
        for(int i=0;i<nums.size();i++){
            if(nums[ind]==nums[i])
                count++;
            else
                count--;
            if(count==0){
                ind=i;
                count=1;
            }
        }
        return nums[ind];
    }
};