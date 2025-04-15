class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int top = st.top(); st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                int area = heights[top] * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int top = st.top(); st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            int area = heights[top] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
