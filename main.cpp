#include <iostream>
#include <queue>
#include <vector>
#include "one/93-RestoreIPAddresses.h"
using namespace std;

int main() {
    Solution solution;
    vector<string> vec = solution.restoreIpAddresses("25525511135");
    cout<<vec.size()<<endl;
    for(auto s : vec){
        cout<<s<<endl;
    }
//    string a = "1234";
//    string b = a.substr(1,3);
//    cout<<b<<endl;
    return 0;
}