#include <iostream>
#include <queue>
#include <vector>
#include "one/63-UniquePathsII.h"
using namespace std;



int main() {
    vector<vector<int>> in(1,vector<int>(1,0));
    Solution solution;
    int res = solution.uniquePathsWithObstacles(in);
    cout<<res;
    return 0;
}