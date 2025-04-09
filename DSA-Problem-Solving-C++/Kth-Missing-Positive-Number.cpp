#include <iostream>
#include <vector>
using namespace std;

// BruteForce: O(N)
int findKthPositive_v1(vector<int>& arr, int k) {
    int missingCount = 0, lastElement = 0;
    for (int i = 0; i < arr.size(); i++) {
        // No missing element if: arr[i] == i+1
        int currentMissing = arr[i] - (i + 1);
        if (currentMissing >= k) {
            if (i == 0)
                return k;
            return lastElement + k - missingCount;
        }
        missingCount = currentMissing;
        lastElement = arr[i];
    }
    return lastElement + k - missingCount;
}

// Binary Search: O(log n)
int findKthPositive_v2(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        // Missing item from low to mid
        int missingCount = arr[mid] - (mid + 1);
        if(missingCount < k)
            // Search for more missing element
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + k;
}

int main() {
    vector<int> v1{2,3,4,7,11};
    cout << findKthPositive_v1(v1, 5) << endl;      // 9
    // Missing elements: [1, 5, 6, 8, 9, 10, 12, 13, ....]
    // 5th element from above: 9

    vector<int>v2{1, 2, 3, 4};
    cout << findKthPositive_v2(v2, 2) << endl;      // 6
    // Missing elements: [5, 6, 7, ....]
    // 2nd element from above: 6
}