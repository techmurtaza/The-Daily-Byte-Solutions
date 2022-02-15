/**
  * This question is asked by Google. Given two integer arrays, return their intersection.
  * Note: the intersection is the set of elements that are common to both arrays.
  *
  * Ex: Given the following arrays...
  *
  * nums1 = [2, 4, 4, 2], nums2 = [2, 4], return [2, 4]
  * nums1 = [1, 2, 3, 3], nums2 = [3, 3], return [3]
  * nums1 = [2, 4, 6, 8], nums2 = [1, 3, 5, 7], return []
  */

// Question: https://leetcode.com/problems/intersection-of-two-arrays/
// Solution:


#include <iostream>

using namespace std;

#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int, int> num_map;
    vector<int>result;

    int len_num1 = nums1.size();
    int len_num2 = nums2.size();

    for(int i = 0; i < len_num1; i++){
        num_map[nums1[i]]++;
    }

    for(int i = 0; i < len_num2; i++){
        if(num_map[nums2[i]]){
            result.push_back(nums2[i]);
            num_map[nums2[i]] = 0;
        }
    }

    return result;
}

int main() {
  int size_nums1, size_nums2;
  cin >> size_nums1 >> size_nums2;
  vector<int> nums1(size_nums1), nums2(size_nums2);
  
  for(int i = 0; i < size_nums1; i++){
    cin >> nums1[i];
  }
  
  for(int i = 0; i < size_nums2; i++){
    cin >> nums2[i];
  }
  
  vector<int> result = intersection(nums1, nums2);
  int result_len = result.size();
  for(int i = 0; i < result_len; i++){
    cout << result[i] << " ";
  }
  
  cout << endl;
}
