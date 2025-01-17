class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp; // Use unordered_map for O(1) average time complexity
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                ans.push_back(mp[complement]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i; // Store number as key and index as value
        }
        return ans; // Return empty vector if no solution found
    }
};
