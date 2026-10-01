class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string repeat = word;
        int count = 0;
        while(sequence.find(repeat)!=string::npos){
            count++;
            repeat+=word;
        }
        return count;
    }
};