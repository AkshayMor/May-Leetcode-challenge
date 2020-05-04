class Solution {
public:
    int findComplement(int num) {
        vector<int>arr(32,0);
        int i=0;
        while(i<32){
            if(num&(1<<i))
                arr[i]=1;
            i++;
        }
        i=31;
        while(arr[i]!=1){
            i--;
        }
        int l=i;
        int n=0;
        for(i=0;i<=l;i++){
            arr[i]=arr[i]^1;
            n+=arr[i]*pow(2,i);
        }
         return n;
    }
   
};