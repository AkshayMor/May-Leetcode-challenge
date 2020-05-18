class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1=s1.length();
        int l2=s2.length();
        if(l1>l2) return false;
        vector<int>arr1(26,0);
        for(int i=0;i<l1;i++) arr1[s1[i]-'a']++;
        vector<int>arr2(26,0);
        for(int i=0;i<l1;i++) arr2[s2[i]-'a']++;
        bool flag=true;
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                flag=false;
                break;
            }
        }
        if(flag) return true;
        for(int i=l1;i<l2;i++){
            flag=true;
            arr2[s2[i-l1]-'a']--;
            arr2[s2[i]-'a']++;
            for(int i=0;i<26;i++){
                if(arr1[i]!=arr2[i]){
                    flag=false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};