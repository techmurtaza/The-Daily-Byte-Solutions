 /**
  * This question is asked by Facebook. Given a string, return whether or not it forms a palindrome ignoring case and non-alphabetical characters.
  * Note: a palindrome is a sequence of characters that reads the same forwards and backwards.
  * Ex: Given the following strings...
  * "level", return true
  * "algorithm", return false
  * "A man, a plan, a canal: Panama.", return true
  */
// Question: https://leetcode.com/problems/valid-palindrome
// Solutions
#include <iostream>

using namespace std;

string lowercaseString(string str){
  int len = str.length();
  for(int i = 0; i < len; i++ ) if(str[i] >= 'A' && str[i] <= 'Z')  str[i] += 32;
  return str;
}

int main() {
  string str;
  
  // input
  getline(cin,str);
  int len = str.length() - 1;
  int i=0, j=len;

  str = lowercaseString(str);

  bool flag = true;
  while(i < j){
    if((str[i] >= 'a' && str[i] <= 'z'  || str[i] >= '0' && str[i] <= '9')
       && (str[j] >= 'a' && str[j] <= 'z'  || str[j] >= '0' && str[j] <= '9')){
      if(str[i] == str[j]){
        i++,j--;
        continue;
      }
      flag = false;
      break;
    }
   if(!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= '0' && str[i] <= '9' )) i++;
   if(!(str[j] >= 'a' && str[j] <= 'z' || str[j] >= '0' && str[j] <= '9' )) j--;
  }

  if(flag)  cout << "True" << endl;
  else cout << "False" << endl;
}
