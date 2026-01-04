class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n = nums.size();
        for(int i =0; i<n; i++){
            freq[nums[i]]++;

            if(freq[nums[i]] >1){
                return nums[i];
            }
        }
        return 0;
        
    }
};