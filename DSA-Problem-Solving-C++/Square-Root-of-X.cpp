#include <iostream>
using namespace std;

int mySqrt(int x) {
    int ans = 0; // Since sqrt(0) = 0
    // Take search space from 1 to x then do binary search on it
    int low = 1, high = x;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // mid*mid can exceed INT_MAX, so we can write
        // mid*mid = x as mid = x/mid
        if (mid == x / mid)
            return mid;
        else if (mid > x / mid)
            high = mid - 1;
        else {
            // It'll be potential answer
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    cout << "Sqrt(0) = " << mySqrt(0) << endl;    // 0
    cout << "Sqrt(64) = " << mySqrt(64) << endl;    // 8
    cout << "Sqrt(80) = " << mySqrt(80) << endl;    // 8
    cout << "Sqrt(2147395599) = " << mySqrt(2147395599) << endl;    // 46339
    return 0;
}

