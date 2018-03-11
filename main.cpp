#include <iostream>
#include <queue>
#include <vector>
#include "ListHelper.h"
#include "23-MergeKSortedLists.h"

using namespace std;
int main() {
    vector<ListNode*> vec;
    Solution solution;
    ListNode* res = solution.mergeKLists(vec);
    ListHelper::printList(res);

//    priority_queue<int,vector<int>,com> q;
//    for (int i = 0; i <10 ; ++i) {
//        q.push(i);
//    }
//    while (q.size()){
//        cout<<q.top()<<"\t";
//        q.pop();
//    }
    return 0;
}