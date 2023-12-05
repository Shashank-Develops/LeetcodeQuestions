class Solution {
public:
    int b_Search(vector<int>& nums, int target, int low, int high) {
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int i = 0;
        for(; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) break;
        }
        int ans = b_Search(nums, target, 0, i);
        if(ans != -1 || i == nums.size() - 1) return ans; 
        ans = b_Search(nums, target, i+1, nums.size() - 1);
        return ans;
    }
};