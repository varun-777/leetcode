class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if (num1 < 100 && num2 < 100)
            return 0;
        int count = 0;
        for (int k = num1; k <= num2; k++) {
            string s1 = to_string(k);
            for (int i = 1; i < s1.size() - 1; i++) {
                if (((s1[i] - '0') > (s1[i - 1] - '0')) &&
                    ((s1[i] - '0') > (s1[i + 1] - '0'))||((s1[i] - '0') < (s1[i - 1] - '0')) &&
                    ((s1[i] - '0') < (s1[i + 1] - '0'))) count++;
            }
        }
        return count;
    }
};