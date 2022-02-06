 /**
  * This question is asked by Google. Given a string, return whether or not it uses capitalization correctly. A string correctly uses capitalization if all letters are capitalized, no letters are capitalized, or only the first letter is capitalized.
  *
  * Ex: Given the following strings...
  * "USA", return true
  * "Calvin", return true
  * "compUter", return false
  * "coding", return true
  */


// Question: https://leetcode.com/problems/detect-capital/
// Solutions
#include <iostream>

using namespace std;

// to check the word except first char, is either all character capital or lower  
bool wordCheck(string str){
  int len = str.length();
  int flag_capital = 0, flag_lower = 0;
  for(int i = 1; i < len; i++ ){
    if(str[i] >= 'A' && str[i] <= 'Z'){
      if(flag_lower) return false;
      flag_capital = 1;
    }else{
      if(flag_capital) return false;
      flag_lower= 1;
    }
  }
  return "true";
}

// to check the first letter with any character
bool charCheck(string str){
  char first_character = str[0];
  char any_character = str[str.length()-1];
  if(first_character >= 'A' && first_character <= 'Z')
    return true;
  else
    if(any_character >= 'a' && any_character <= 'z')
      return true;
  return false;
}


int main() {
  string str;
  // input
  cin >> str;

  if(wordCheck(str)){
    if(charCheck(str))  cout << "true";
    else cout << "false";

  }
  else cout << "false";
}
