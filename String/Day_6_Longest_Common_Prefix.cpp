/**
  * This question is asked by Microsoft. Given an array of strings, return the longest common prefix that is shared amongst all strings.
  * Note: you may assume all strings only contain lowercase alphabetical characters.
  *
  * Ex: Given the following arrays...
  *
  * ["colorado", "color", "cold"], return "col"
  * ["a", "b", "c"], return ""
  * ["spot", "spotty", "spotted"], return "spot"
*/

// Questions https://leetcode.com/problems/longest-common-prefix
// Solutions
#include <iostream>

using namespace std;

string findThePrefix(string prefix, string b){
    string newPreFix = "";
    int pre_len = prefix.length(), b_len = b.length();
    int i=0,j=0;
    while(i < pre_len && j < b_len ){
        if(prefix[i]==b[j]){
            newPreFix += prefix[i]; 
            i++,j++;
        }
        else
            break;
    }
    return newPreFix;
}
    
string longestCommonPrefix(vector<string>& strs) {

    int len = strs.size();
    string preFix = strs[0];
    for(int i = 1; i<len; i++){
        preFix = findThePrefix(preFix,strs[i]);
    }
    return preFix;
}

int main() {
  vector<string> strs;
  int size;
  cin >> size;
  
  // input String Array
  for(int i = 0; i < size; i++){
    string s;
    cin>>s;
    strs.push_back(s)
    }
  
  cout << longestCommonPrefix(strs);
  cout << endl;
}
