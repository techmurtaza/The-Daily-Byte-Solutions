 /**
  * This question is asked by Apple. Given two binary strings (strings containing only 1s and 0s) return their sum (also as a binary string).
  * Note: neither binary string will contain leading 0s unless the string itself is 0
  *
  * Ex: Given the following strings...
  *
  * "100" + "1", return "101"
  * "Calvin", return true
  * "11" + "1", return "100"
  * "1" + "0", return  "1"
  */


// Question: https://leetcode.com/problems/add-binary
// Solutions

#include <iostream>

using namespace std;

string result;
bool carry;

// Reverse of given string
string reverseTheString(string str){
  int len = str.length() - 1;
  int i = 0;
  while(i <= (len/2)){
    char tmp = str[i];
    str[i] = str[len-i];
    str[len-i] =  tmp;
      i++;
  }
  return str;
}
    
// Adding two binary char and pusshing in string        
void additionOfBinaryChar(char a, char b){
    if(carry){
        if(a == '0' && b == '0'){
            carry = false;    
            result.push_back('1');
        }
        else if(((a == '1' && b == '0') || (a == '0' && b == '1')))
            result.push_back('0');
        else
            result.push_back('1');
    }else{
        if(a == '0' && b == '0')
            result.push_back('0');
        else if(((a == '1' && b == '0') || (a == '0' && b == '1')))
            result.push_back('1');
        else{
          result.push_back('0');
          carry = true;
      }
    }
}

string addBinary(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();

    if(len_a == 1 && a[0] == '0')   return b;
    else if(len_b == 1 && b[0] == '0') return a;           

    a = reverseTheString(a);
    b = reverseTheString(b);

    int i = 0, j = 0;
    while(i < len_a && j < len_b)   additionOfBinaryChar(a[i++],b[j++]);
    while(i < len_a )   additionOfBinaryChar(a[i++],'0');
    while(j < len_b )   additionOfBinaryChar(b[j++],'0');
  
    // if carry is there than it will be added
    if(carry) result.push_back('1');

    return reverseTheString(result);
}

int main() {
  //global variable initialization
  result = "";
  carry = false;
  
  string a, b;
  // input
  cin >> a >> b;
  cout << addBinary(a,b);
}
