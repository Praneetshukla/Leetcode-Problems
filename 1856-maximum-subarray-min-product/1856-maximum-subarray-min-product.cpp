class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

       const long long MOD = 1e9 + 7;

       //prefix sum
       vector<long long> prefix( n+1, 0 );

       for(int i = 0; i<n;i++){
        prefix[i+1] = prefix[i] + nums[i];
       }

       //calculate prev smaller
       vector<int> prev(n,0);
       stack<int> st;
       
       for(int i = 0;i<n;i++){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        prev[i] = st.empty() ? -1 : st.top();
        st.push(i);
       }
       
       while(!st.empty()){
        st.pop();
       }

       //calculate next smaller
       vector<int> next(n,0);
       
        for(int i = n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        next[i] = st.empty() ? n : st.top();
        st.push(i);
       }

       //calculate ans

       long long ans = 0;

       for(int i = 0; i<n;i++){
       int left = prev[i] + 1; // we got the index'es of a subarray
       int right = next[i] - 1;

       long long subsum = prefix[right + 1] - prefix[left];
       long long product = subsum * nums[i];

        ans = max(ans,product);

       }
       return ans % MOD;
       
    }
};