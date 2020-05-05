class Solution {
public:
    int firstUniqChar(string s) {
        int l=s.length();
        vector<int>character(26,l);
//         Traverse a string to save a index of its occurence 
//         If its not unique then change its occurence to INT_MAX
        for(int i=0;i<s.length();i++){
            if(character[s[i]-'a']==l)
                character[s[i]-'a']=i;
            else
                character[s[i]-'a']=INT_MAX;
        }
        int mini=INT_MAX;
//         Now we only have to traverse a constant size 26 vector to get the minimum
        for(int i=0;i<26;i++){
            mini=min(mini,character[i]);
        }
        if(mini!=INT_MAX && mini!=l) return mini;
        else return -1;
    }
};