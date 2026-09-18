class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<vector<int>>vec;
        for(auto it:mp){
            int i = 0, s = it.second.size();
            while(i<s){
                int t = it.first;
                vector<int>temp;
                while(t--){
                    temp.push_back(it.second[i]);
                    i++;
                }
            vec.push_back(temp);
            }
        }
        return vec;
    }
};