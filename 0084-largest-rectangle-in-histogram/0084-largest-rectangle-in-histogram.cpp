class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int h = heights.size();
        vector <int> prev(h);
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> next(h);
        for(int i=h-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            next[i]=st.empty() ? h : st.top();
            st.push(i);
        }

        int maxarea = 0;
        for(int i =0 ; i<h ; i++){
            int width = next[i] - prev[i] -1;
            maxarea = max(maxarea,width*heights[i]);
        }
        return maxarea;
    }
};