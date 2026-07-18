class Solution {
public:
    int findGCD(vector<int>& nums) {
        int low = INT_MAX;
        int high = INT_MIN;
        for(int num:nums){
            low=min(low,num);
            high=max(high,num);
        }
        int ans = 1 ;
        for(int i = high ; i>=1 ; i--){
            if(low%i==0 && high%i==0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};