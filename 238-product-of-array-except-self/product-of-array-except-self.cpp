class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_prod(n);
        vector<int> right_prod(n);

        left_prod[0] = 1;
        for(int i = 1; i < n; i++)
        {
            left_prod[i] = left_prod[i-1] * nums[i-1];
        }

        right_prod[n-1] = 1;
        for(int i = n-2; i >= 0; i--)
        {
            right_prod[i] = right_prod[i+1] * nums[i+1];
        }

        for(int i = 0; i < n; i++)
        {
            ans[i] = left_prod[i] * right_prod[i];
        }

        return ans;
    }
};