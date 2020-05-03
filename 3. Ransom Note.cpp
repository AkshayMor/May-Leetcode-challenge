class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>dict(26,0);
       //Check if ransomNote length is gretaer than magazine 
        // then return false         
        if(magazine.length()<ransomNote.length())
            return false;
    // Create a dictionay of alphabets (counts of each alphabets)
        for(int i=0;i<magazine.length();i++)
            dict[magazine[i]-'a']++;
        for(int i=0;i<ransomNote.length();i++){
            dict[ransomNote[i]-'a']--; 
            if(dict[ransomNote[i]-'a']<0)
                return false;
        }
        return true;
    }
};