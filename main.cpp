#include <iostream>
#include <vector>

#include "149-MaxPoints.h"

using namespace std;

int main() {
    Solution so;
    vector<Solution::Point> points;
    Solution::Point p1(1,1);
    Solution::Point p2(1,1);
    Solution::Point p3(1,1);
//    Solution::Point p4(2,2);
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
//    points.push_back(p4);
    cout<<so.maxPoints(points)<<endl;


    return 0;
}