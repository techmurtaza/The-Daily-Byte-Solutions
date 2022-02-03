/**
 * This question is asked by Google. Given a string, reverse all of its characters and return the resulting string.
 * Ex: Given the following strings...
 * “Cat”, return “taC”
 * “The Daily Byte”, return "etyB yliaD ehT”
 * “civic”, return “civic”
 */

// Solutions
#include <iostream>

using namespace std;

void swap(char *a, char * b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
  string str;
  // input
  getline(cin,str);
  int len = str.length() - 1;
  
  for(int i = 0; i < (len/2); i++ ) swap(str[i],str[len - i]);
  
  cout << str << endl;
}
