class Solution {
public:

    int getday(string s){
        int a = stoi(s.substr(0,2));
        int rem = stoi(s.substr(3));
        int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int ans = 0;
        for(int i=0;i<a-1;i++) ans+=months[i];
        return ans+rem;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<bool>days(366,false);
        int SA = getday(arriveAlice);
        int LA = getday(leaveAlice);
        int SB = getday(arriveBob);
        int LB = getday(leaveBob);
        int count = 0;
        for(int i=SA;i<=LA;i++) days[i] = true;
        for(int i=SB;i<=LB;i++) if(days[i]) count++;
        return count;
    }
};