class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourDegreeHand = hour*30%360+minutes*0.5;
        double MinuteDegree = minutes*6 ; 
        
        double answer = abs(MinuteDegree - hourDegreeHand);
        return min(answer , 360-answer);
    }
};