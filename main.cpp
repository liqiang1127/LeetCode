#include <iostream>
#include <queue>
#include <vector>
#include "one/64-MinimumPathSum.h"
using namespace std;



int main() {
    vector<vector<int>> in;
    vector<int> a = {1,3,1};
    vector<int> b = {1,5,1};
    vector<int> c = {4,2,1};
    in.push_back(a);
    in.push_back(b);
    in.push_back(c);

    Solution solution;
    int res = solution.minPathSum(in);
    cout<<res;
    return 0;
}