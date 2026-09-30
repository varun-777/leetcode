class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& nums) {
        vector<string>ans;
        int prev = nums[0],n = nums.size();
        ans.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(prev==0){
                if(nums[i]==1) ans.push_back(words[i]);
                else{
                    prev = nums[i];
                    continue;
                }
            }
            else{
                if(nums[i]==0) ans.push_back(words[i]);
                else 
                {
                   prev = nums[i];
                    continue;
                }
            }
            prev = nums[i];
        }
        return ans;
    }
};