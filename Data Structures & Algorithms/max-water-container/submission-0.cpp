class Solution {
public:
    int maxArea(vector<int>& heights) {
          int i = 0;
    int j = heights.size() - 1;

    int maxi = 0;

    while(i < j){

        int width = j - i;
        int height = min(heights[i], heights[j]);

        maxi = max(maxi, width * height);

        if(heights[i] < heights[j])
            i++;
        else
            j--;
    }

    return maxi;
    }
};
