class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int total = 0;
        for(int i=0;i<apple.size();i++) total+=apple[i];
        int count = 0;
        for(int i=0;i<capacity.size();i++){
            total-=capacity[i];
            count++;
            if(total<=0) break;
        }
        return count;
    }
};