class Solution {
public:
    vector<string> ans;

    void solve(int idx, string s, int n, string temp) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        if (isalpha(s[idx])) {
            temp.push_back(tolower(s[idx]));
            solve(idx + 1, s, n, temp);
            temp.pop_back();
            temp.push_back(toupper(s[idx]));
            solve(idx + 1, s, n, temp);
        } 
        else
         solve(idx + 1, s, n, temp + s[idx]);
    }

        vector<string> letterCasePermutation(string s) {
            int n = s.size();
            solve(0, s, n, "");
            return ans;
        }
    };