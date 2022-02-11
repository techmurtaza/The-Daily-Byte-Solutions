/**
  * This question is asked by Facebook. Given two strings s and t return whether or not s is an anagram of t.
  * Note: An anagram is a word formed by reordering the letters of another word.
  *
  * Ex: Given the following strings...
  *
  * s = "cat", t = "tac", return true
  * s = "listen", t = "silent", return true
  * s = "program", t = "function", return false
  */

// Question: https://leetcode.com/problems/valid-anagram/
// Solution:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
bool isAnagram(string s, string t) {
    int arr[26] = {0};

    if(s.length() != t.length())
        return false;

    int len = s.length();
    for(int i = 0; i < len; i++){
        arr[s[i]-'a']++;
        arr[t[i]-'a']--;
    }

    for(int i = 0; i < 26; i++)
        if(arr[i] != 0)
            return false;

    return true;
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << isAnagram(a,b);
  cout << endl;
}
