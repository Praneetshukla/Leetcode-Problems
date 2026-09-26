class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l =0 ;
        int len = 0;
        int count = 0;
        int n = fruits.size();
        vector<int> mp(n,0);
        for(int r=0;r<fruits.size();r++){
            if(mp[fruits[r]] == 0 ){
                count++;
            }
            mp[fruits[r]]++;
            while(count>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    count--;
                }
                l++;
            }
            len = max(len,r-l+1);
        }
        return len;
    }
};