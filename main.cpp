#include <iostream>
#include <vector>
#include "ListHelper.h"
#include "82-RemoveDuplicates.h"

using namespace std;

int main() {
    int arr1[] = {1,1};
//    int arr2[] = {9,9};
    ListNode* head1 = ListHelper::createList(arr1,2);
//    ListNode* head2 = ListHelper::createList(arr2,2);
    Solution so;
    ListNode* res = so.deleteDuplicates(head1);
    ListHelper::printList(res);
    return 0;
}