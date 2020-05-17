class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>idx;  
        int sl=s.length();
        int pl=p.length()
//     return null if pattern lengthis greater than string length
        if(sl<pl)return {};
//         create a count array for pattern
        vector<int>pat(26,0);
        for(auto w:p){
            pat[w-'a']++;
        }
//         create a count array of first pl char of string 
        vector<int>par(26,0);
        for(int i=0;i<pl;i++){
            par[s[i]-'a']++;
        }
        
        bool flag=false;
        for(int i=0;i<26;i++){
            if(pat[i]!=par[i]){
                flag=true;
                break;
            }
        }
        if(!flag) idx.push_back(0);
        
// update the count array by removing first and adding last with respect to movement 
        for(int i=pl;i<sl;i++){
                par[s[i-pl]-'a']--;
                par[s[i]-'a']++;
                flag=false;
                for(int i=0;i<26;i++){
                     if(pat[i]!=par[i]){
                        flag=true;
                        break;
                     }
                }
                if(!flag) idx.push_back(i-pl+1);
        }
        return idx;
    }
};