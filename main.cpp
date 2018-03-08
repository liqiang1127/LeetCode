#include <iostream>
#include <vector>
#include "ListHelper.h"
#include "61-RotateList.h"

using namespace std;

int main() {
    int arr1[] = {1,2,3,4,5};
    ListNode* head1 = ListHelper::createList(arr1,5);
    Solution so;
    ListNode* res = so.rotateRight(head1,2);
    ListHelper::printList(res);
    return 0;
}