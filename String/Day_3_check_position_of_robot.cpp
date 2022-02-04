 /**
  * This question is asked by Amazon. Given a string representing the sequence of moves a robot vacuum makes, return whether or not it will return to its original position. The string will only contain L, R, U, and D characters, representing left, right, up, and down respectively.
  *
  * Ex: Given the following strings...
  * "LR", return true
  * "URURD", return false
  * "RUULLDRD", return true
  */

// Solutions
#include <iostream>

using namespace std;

string checkPosition(string str){
  int left_right, upper_down;
  left_right = upper_down = 0; 
  int len = str.length();
  
  for(int i = 0; i < len; i++ ){
    switch(str[i]){
      case 'L': left_right++;
        break;
      case 'R': left_right--;
        break;
      case 'U': upper_down++;
        break;
      case 'D': upper_down--;
    }
  }
  if(left_right == 0 && upper_down == 0)
    return "true";
  return "false";
}

int main() {
  string str;
  // input
  cin >> str;
  cout << checkPosition(str);
}
