class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k) return "0";
        while(k>0){
            int i;
            bool flag=false;
            for(i=1;i<num.length();i++){
                if(num[i]<num[i-1]){
                    num.erase(num.begin()+i-1);
                    k--;
                    flag=true;
                    break;
                }
            }
                if(i==num.length() && flag==false) break;
        }
            while(k>0){
                num.erase(num.end()-1);
                k--;
            }
        int first=0;
        for(int i=0;i<num.length();i++){
            if(int(num[i]-48)!=0) break;
            else first++;
        }
        if(first==0) return num;
        else if(first==num.length()) return "0";
        else{
        string str;A
        for(int i=first;i<num.length();i++)
            str+=num[i];
        return str;
        }
    }
};