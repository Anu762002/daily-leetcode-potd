#include<bits/stdc++.h>
using namespace std;
#define db double
class Solution {
public:
    double angleClock(int hour, int minu) {
        db def= ((db)minu/2); // deflection in hr angle due to min angel 
        db minang=((db)minu*6);
        db hrang=def+hour*30;
        db angle1 = abs(hrang -minang);
        db angle2 = 360-angle1;
        return min(angle1,angle2);
    }
};