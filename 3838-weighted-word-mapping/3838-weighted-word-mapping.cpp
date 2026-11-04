class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        int sum;
        for(string s : words){
            sum = 0;
            for(char ch:s) sum+=weights[ch-'a'];
            sum = sum%26;
            ans+='z'-('a'+sum)+97;
        }
        return ans;
    }
};