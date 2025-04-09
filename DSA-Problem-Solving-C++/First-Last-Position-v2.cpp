#include <iostream>
#include <vector>
using namespace std;

void explain_lower_bound() {
    //  In C++ lower_bound() returns the pointer to the first occurring element, which is greater than 
    // or equal to the value passed. It uses Binary Search to do the process. so it works for sorted search spaces.
    vector<int> v{2, 4, 4, 7, 7, 7, 9, 11};
    
    vector<int>::iterator pos = lower_bound(v.begin(), v.end(), 7);
    // Now, you can't print an iterator since it's not defined to have a value. 
    // But you can perform arithematic operations on them and that helps you to print the value
    cout << "First occurrence of 7: " << pos - v.begin() << endl;     // 3

    // If we pass a value in lower_bound which is not present in vector, but it's greater value is present inside
    // the vector, then it returns the index of this greater value as iterator
    pos = lower_bound(v.begin(), v.end(), 8);
    cout << "First occurrence of the value >= 8: " << pos - v.begin() << endl;    // 6

    // If we pass a value in lower_bound which is not present in vector, and it's greater value is also 
    // not present inside the vector, then it returns the (last index + 1) of this vector as iterator
    pos = lower_bound(v.begin(), v.end(), 12);
    cout << "First occurrence of the value >= 12: " << pos - v.begin() << endl;    // 8

    // So we can get last occurrence of 7 as (first_occurrence of value > 7) - 1
    cout << "Last occurrence of 7: " << lower_bound(v.begin(), v.end(), 7+1) - v.begin() - 1 << endl;     // 5
}

vector<int> searchRange(vector<int>& nums, int target) {
    // If target is present then it return it's first ocuurance
    int first_occurrence = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    // If target is present then return it's last occurrence
    int last_occurrence = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin() - 1;

    if(first_occurrence < nums.size() && nums[first_occurrence] == target)
        return {first_occurrence, last_occurrence};
    return {-1, -1};
}


int main() {

    explain_lower_bound();

    vector<int> v{5,7,7,8,8,10};
    for (int x : searchRange(v, 8))
        cout << x << " ";
    cout << endl;

    return 0;
}