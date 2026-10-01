class Solution {
public:
    int maxRepeating(string s, string word) {
        int n = s.size(), count = 0, j = 0, split = word.size(), i = 0,
            maxx = INT_MIN;
        string temp, prev;
        while (i < n - split + 1) {
            j = i, count = 0;
            prev = s.substr(j, split);
            while (j < n) {
                temp = s.substr(j, split);
                j += split;
                cout << temp << " ";
                if (count == 0 && temp == word)
                    count++;
                else if (temp == word && prev == word)
                    count++;
                else
                    count = 0;
                maxx = max(maxx, count);
                prev = temp;
            }
            i++;
        }
        if (maxx != INT_MIN)
            return maxx;
        if (s == word)
            return 1;
        return 0;
    }
};