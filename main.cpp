#include <iostream>
#include <vector>

#include "219-ContainsDuplicate.h"

using namespace std;

int main() {
    Solution so;
    vector<int> in{1,2,1};
    cout<<so.containsNearbyDuplicate(in,1)<<endl;


    return 0;
}