/**
  * This question is asked by Facebook. Given a string and the ability to delete at most one character, return whether or not it can form a palindrome.
  * Note: a palindrome is a sequence of characters that reads the same forwards and backwards.
  *
  * Ex: Given the following strings...
  *
  * "abcba", return true
  * "foobof", return true (remove the first 'o', the second 'o', or 'b')
  * "abccab", return false
  */

// Question: https://leetcode.com/problems/valid-palindrome-ii/
//  Solutions

#include <iostream>

using namespace std;

#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

// to check recursively given string is palindrome.
bool checkCharacters(string &a, int i ,int j){
    if(i>=j)
        return true;
    if(a[i]==a[j])
         return checkCharacters(a,i+1,j-1);
    return false;
}
    
bool validPalindrome(string s) {
    int len = s.length();
    int i = 0,j = len-1;
    // to check for the first character erase 
    int flag = false;
  
    while(i<j){
        if(s[i]==s[j]){
          i++,j--;
          continue;
        }
      // check whether we erased the character or not      
        if(!flag){
        // checking by erasing from start
          if(s[i+1]==s[j]){
            if(checkCharacters(s,i+1,j))
              return true;
            flag = true;
          }
          // checking by erasing from end
          if(s[i]==s[j-1]){
              if(checkCharacters(s,i,j-1))
                return true;
            flag = true;
          }
        }
        return false;
    }
    return true;
}

int main() {
  string str;
  cin >> str;
  
  cout << validPalindrome(str);
  cout << endl;
}
