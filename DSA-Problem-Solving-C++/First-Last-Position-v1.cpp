#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    // Initialize the result vector as -1
    vector<int> result{-1, -1};
    
    // Check for first position
    int low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) {
            result[0] = mid;
            // Search for leftmost index
            high = mid - 1;
        } 
        else if(nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    // Check for last position
    low = 0, high = nums.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) {
            result[1] = mid;
            // Search for rightmost index
            low = mid + 1;
        }
        else if(nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return result;
}

int main() {
    vector<int> v{5,7,7,8,8,10};
    for (int x : searchRange(v, 8))
        cout << x << " ";
    cout << endl;

    return 0;
}