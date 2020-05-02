class Solution {
public:
    int numJewelsInStones(string J, string S) {
      //create a set map for jewel(distinct elements are present in jewel)     
       set<char>jewel;
        for(int i=0;i<J.length();i++){
            jewel.insert(J[i]);
        }
        int count=0;
       //check for every stone present it or not         
        for(int i=0;i<S.length();i++){
            if(jewel.find(S[i])!=jewel.end())
                count++;
        }
        return count;
    }
};