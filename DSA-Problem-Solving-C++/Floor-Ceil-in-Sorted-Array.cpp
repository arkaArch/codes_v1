#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/* Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'. 
Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'. */

pair<int, int> getFloorAndCeil(vector<int> &a, int x) {
	int low = 0, high = a.size() - 1;
	int floor = -1, ceil = -1;
	while(low <= high) {
		int mid = low + (high-low)/2;
		if(x == a[mid])
			// Floor and ceil is the number itself
			return make_pair(x, x);
		else if(x < a[mid]) {
			// It may be ceil
			ceil = a[mid];
			high = mid - 1;
		}
        else { 		// x > a[mid]
            // It may be floor
            floor = a[mid];
            low = mid + 1;
        }
    }
	return make_pair(floor, ceil);
}

int main() {
	vector<int>v {3, 4, 4, 7, 8, 10};
	pair<int, int>res = getFloorAndCeil(v, 5);
	cout << "floor: " << res.first << " ceil: " << res.second << "\n";	// 4, 7

	res = getFloorAndCeil(v, 8);
	cout << "floor: " << res.first << " ceil: " << res.second << "\n"; 	// 8, 8

	res = getFloorAndCeil(v, 11);
	cout << "floor: " << res.first << " ceil: " << res.second << "\n"; 	// 10, -1
}