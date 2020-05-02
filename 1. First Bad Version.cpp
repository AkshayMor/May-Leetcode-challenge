  
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int start=1,end=n,mid;
        // using binary search to find the first true value
        while(start<=end){
            mid=(start+end)/2;
            if(isBadVersion(mid)==false){
                if(isBadVersion(mid+1)==true)
                    return mid+1;
                else
                    start=mid+1;
            }
            else{
                if(isBadVersion(mid-1)==false)
                    return mid;
                else
                    end=mid-1;       
            }
             
        }
        return -1;
    }
};