/**
  * This question is asked by Google. Given an array of integers, return whether or not two numbers sum to a given target, k.
  * Note: you may not sum a number with itself.
  *
  * Ex: Given the following...
  *
  * [1, 3, 8, 2], k = 10, return true (8 + 2)
  * [3, 9, 13, 7], k = 8, return false
  * [4, 2, 6, 5, 2], k = 4, return true (2 + 2)    
  */
// Question: https://leetcode.com/problems/two-sum/

// Solution

#include <iostream>

using namespace std;

bool twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> valueMap;
  
    for(int i = 0; i < nums.size(); i++){
        auto itr = valueMap.find(target - nums[i]);
        if(itr != valueMap.end())
          return true;
        valueMap[nums[i]] = i;
    }
  return false;
}

int main() {
  int size, target;
  cin >> size;
  vector<int> nums(size);
  
  for(int i = 0; i < size; i++)
      cin >> nums[i];
  cin >> target;
  
  cout << validPalindrome(nums,target);
  cout << endl;
}
