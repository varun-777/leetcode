class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int i =0;
        while(i<n&&s[i]!='b') i++;

        for(int j=i;j<n;j++) if(s[j]=='a') return false;
        return true;
    }
};