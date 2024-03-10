#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[0m"

/*
    Given an array A of N elements. Find the majority element in the array.
    A majority element in an array A of size N is an element
    that appears strictly more than N/2 times in the array.
    Link: https://www.geeksforgeeks.org/problems/majority-element-1587115620/1
*/

int majorityElement(vector<int> arr)
{
    int size = arr.size();
    int count = 0, posentialElement = 0;
    for (int i = 0; i < size; i++) {
        if (count == 0) {
            posentialElement = arr[i];
        }
        count += (arr[i] == posentialElement? 1: -1);
    }
    count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == posentialElement) {count++;}
    }
    if (count > size/2) {return posentialElement;}
    return -1;
}

int main() {
    int numTc;
    vector<tuple<vector<int>, int>> testCases;
    testCases.push_back({{1, 2, 3}, -1});
    testCases.push_back({{3, 1, 3, 3, 2}, 3});
    testCases.push_back({{1,1,1,1,2,3,5}, 1});
    for (int tc = 0; tc < testCases.size(); tc++) {
        vector<int> arr = get<0>(testCases[tc]);
        int actual = majorityElement(arr);
        int expected = get<1>(testCases[tc]);
         if ( actual != expected) {
            cout << "[Failed]";
        } else {
            cout << BOLD_ON << "[Passed]" << BOLD_OFF;
        }
        cout << " Test case " << tc + 1 << ": ";
        cout << "expected=" << expected << " vs "
            << "actual=" << actual << "\n";
    }
    
    return 0;
}

