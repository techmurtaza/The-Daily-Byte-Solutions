/**
  * This question is asked by Microsoft. Given a string, return the index of its first unique character. If a unique character does not exist, return -1.
  *
  * Ex: Given the following strings...
  *
  * "abcabd", return 2
  * "thedailybyte", return 1
  * "developer", return 0
  */

// Question: https://leetcode.com/problems/first-unique-character-in-a-string
// Solution:

#include <iostream>

using namespace std;

#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

int firstUniqChar(string s) {
    int unique_char_array[26] = {0};

    int len = s.length();
    // calculating all occurence    
    for(int i = 0; i < len; i++ )
        unique_char_array[s[i] - 'a']++;
  
    // first character which comes once will be returned!     
    for(int i = 0; i < len; i++ )
        if(unique_char_array[s[i] - 'a'] == 1)
            return i;
  
    return -1;
}

int main() {
  string s;
  cin >> s;
  cout << firstUniqChar(s);
  cout << endl;
}
