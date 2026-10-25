class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthToDays = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int arriveMonthOfA = stoi(arriveAlice.substr(0,2));
        int arriveDateOfA = stoi(arriveAlice.substr(3,2));
        int arriveMonthOfB = stoi(arriveBob.substr(0,2));
        int arriveDateOfB = stoi(arriveBob.substr(3,2));

        int leaveMonthOfA = stoi(leaveAlice.substr(0,2));
        int leaveDateOfA = stoi(leaveAlice.substr(3,2));
        int leaveMonthOfB = stoi(leaveBob.substr(0,2));
        int leaveDateOfB = stoi(leaveBob.substr(3,2));

        int arriveDayOfA = monthToDays[arriveMonthOfA-1] + arriveDateOfA;
        int leaveDayOfA = monthToDays[leaveMonthOfA-1] + leaveDateOfA;
        int arriveDayOfB = monthToDays[arriveMonthOfB-1] + arriveDateOfB;
        int leaveDayOfB = monthToDays[leaveMonthOfB-1] + leaveDateOfB;

        int overlap = min(leaveDayOfA, leaveDayOfB) - max(arriveDayOfA, arriveDayOfB) + 1;
        return overlap>0 ? overlap : 0;
        
    }
};