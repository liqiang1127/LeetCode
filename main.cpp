#include <iostream>
#include <queue>
#include <vector>
#include "four/322-CoinChange.h"
using namespace std;



int main() {
    Solution solution ;
    vector<int> in = {2};
    int res = solution.coinChange(in,1);
    cout<<res;
    return 0;
}