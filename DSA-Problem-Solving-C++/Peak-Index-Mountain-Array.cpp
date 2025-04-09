#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    // If there is one element
    if (arr.size() == 1)
        return 0;
    // To handle first and last index
    // Check if the first element is peek
    else if (arr[0] > arr[1])
        return 0;
    // Check if the last element is peek
    else if (arr[arr.size() - 1] > arr[arr.size() - 2])
        return arr.size() - 1;

    int low = 1, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            return mid;
        else if (arr[mid] > arr[mid - 1])
            // The element is in inclined slope
            low = mid + 1;
        else // arr[mid] > arr[mid + 1]
            // The element is in declined slope
            high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> v{0, 3, 5, 6, 7, 10, 5, 2};
    cout << "Peak index: " << peakIndexInMountainArray(v) << endl;  // 5
    return 0;
}