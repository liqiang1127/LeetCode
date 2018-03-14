#include <iostream>
#include <queue>
#include <vector>
#include "one/51-N-Queens.h"
using namespace std;

int main() {
    Solution solution;
    vector<vector<string>> res = solution.solveNQueens(4);
    for(auto vec : res){
        for(auto s : vec){
            cout<<s<<endl;
        }
        cout<<endl;
    }
}