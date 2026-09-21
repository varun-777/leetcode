class Solution {
public:
    vector<int>ans;
    vector<bool>marked;
    void solve(vector<int>&nums,string temp,vector<bool>&vis){
        if(temp.size()==3){
            if(temp[0]!='0'&&(temp[2]-'0')%2==0) 
            {
                if(!marked[stoi(temp)]) ans.push_back(stoi(temp));
                marked[stoi(temp)] = true;
            }
            return; 
        }

        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i] = true;
                temp.push_back(nums[i]+'0');
                solve(nums,temp,vis);
                vis[i] = false;
                temp.pop_back();
            }
        }

    }
    vector<int> findEvenNumbers(vector<int>& nums) {
        int n = nums.size();
        marked.assign(1000,false);
        vector<bool>vis(n,false);
        solve(nums,"",vis);
        sort(ans.begin(),ans.end());
        return ans;
    }
};