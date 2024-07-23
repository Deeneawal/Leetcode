class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        if (nums.empty()) {
            return nums; // Return empty vector if input is empty
        }
        
        // Step 1: Find the minimum and maximum elements in nums to determine range
        int minEle = *min_element(nums.begin(), nums.end());
        int maxEle = *max_element(nums.begin(), nums.end());
        
        // Step 2: Determine the size of count array and adjust nums to positive indices
        int range = maxEle - minEle + 1;
        for (int& num : nums) {
            num -= minEle;
        }
        
        // Step 3: Count frequencies using a count array
        vector<int> count(range, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 4: Prepare output based on frequency
        vector<vector<int>> bucket(nums.size() + 1); // Using a bucket approach
        
        for (int i = 0; i < range; ++i) {
            if (count[i] > 0) {
                int num = i + minEle;
                bucket[count[i]].push_back(num); // Place number 'num' in bucket at index 'count[i]'
            }
        }
        
        // Step 5: Form the sorted result
        vector<int> sortedResult;
        for (int i = nums.size(); i > 0; --i) {
            for (int num : bucket[i]) {
                sortedResult.insert(sortedResult.end(), i, num); // Add 'num' 'i' times to sortedResult
            }
        }
        
        // Reverse the sortedResult before returning
        reverse(sortedResult.begin(), sortedResult.end());
        
        return sortedResult;
    }
};
