#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, pos = -1;
    // If element is greater than last position of array
    if(target > nums[high])
        return high + 1;
    // Else target >= arr[low]
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(target == nums[mid])
            return mid;
        else if(target < nums[mid])
            high = mid - 1;
        else
            low = mid + 1;  
    }
    return low;
}

int main() {
    vector<int> v{1,4,6,8,10,14,16,18};
    cout << searchInsert(v, 7) << endl;    // 3    
    cout << searchInsert(v, 20) << endl;   // 8
    cout << searchInsert(v, 17) << endl;   // 7
    return 0;
}