/**
  * This question is asked by Amazon. Given two strings representing sentences, return the words that are not common to both strings (i.e. the words that only appear in one of the sentences). You may assume that each sentence is a sequence of words (without punctuation) correctly separated using space characters.
  * Note: the intersection is the set of elements that are common to both arrays.
  *
  * Ex: given the following strings...
  *
  * sentence1 = "the quick", sentence2 = "brown fox", return ["the", "quick", "brown", "fox"]
  * sentence1 = "the tortoise beat the haire", sentence2 = "the tortoise lost to the haire", return ["beat", "to", "lost"]
  * sentence1 = "copper coffee pot", sentence2 = "hot coffee pot", return ["copper", "hot"]
  */

// Question: https://leetcode.com/problems/uncommon-words-from-two-sentences/
// Solution:

#include <iostream>

using namespace std;

#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

vector<string> uncommonFromSentences(string s1, string s2) {
  vector<string> str1, str2, rslt;
  
  int len_s1 = s1.length();
  int i = 0;
  string tmp = "";
  
  while(i < len_s1){
      if(s1[i] == ' '){
          str1.push_back(tmp);
          tmp = "";
          i++;
          continue;
      }
      tmp += s1[i];
      i++;
  }
  str1.push_back(tmp);

  tmp = "";
  i = 0;
  int len_s2 = s2.length();
  
  while(i < len_s2){
      if(s2[i] == ' '){
          str2.push_back(tmp);
          tmp = "";
          i++;
          continue;
      }
      tmp += s2[i];
      i++;
  }
  str2.push_back(tmp);

  sort(str1.begin(),str1.end());
  sort(str2.begin(),str2.end());

  int len_str1 = str1.size();
  int len_str2 = str2.size();
  int first = 0, scnd = 0;

  while(first < len_str1 && scnd < len_str2){

    if(str1[first] == str2[scnd]){
          first++, scnd++;
          continue;
      }else if(str1[first] > str2[scnd]){
          if(len_str2 > (scnd + 1)){
              if(str2[scnd] == str2[scnd+1]){
                  scnd++;
              }
          }
      
          if((scnd - 1) >= 0){
              if(str2[scnd] == str2[scnd-1]){
                  scnd++;
                  continue;
              }
          }
          rslt.push_back(str2[scnd]);
          scnd++;
      }else{
      
          if(len_str1 > (first + 1)){
              if(str1[first] == str1[first+1]){
                  first++;
                  continue;
              }
          }
      
          if((first - 1) >= 0){
              if(str1[first] == str1[first-1]){
                  first++;
                  continue;
              }
          }
          rslt.push_back(str1[first]);
          first++;
      }
  }

   while(first < len_str1){
          if(len_str1 > (first + 1)){
              if(str1[first] == str1[first+1]){
                  first++;
                  continue;
              }
          }
     
          if((first - 1) >= 0){
              if(str1[first] == str1[first-1]){
                  first++;
                  continue;
              }
          }
          rslt.push_back(str1[first]);
          first++;
      }
  
     while(scnd < len_str2){
        if(len_str2 > (scnd + 1)){
            if(str2[scnd] == str2[scnd+1]){
                scnd++;
                continue;
            }
        }
       
        if((scnd - 1) >= 0){
            if(str2[scnd] == str2[scnd-1]){
                scnd++;
                continue;
            }
        }
        rslt.push_back(str2[scnd]);
        scnd++;
    }
  return rslt;
}

int main() {
  string a, b;
  getline(cin,a);
  getline(cin,b);
  
  vector<string> result = uncommonFromSentences(a, b);
  int result_len = result.size();
  for(int i = 0; i < result_len; i++){
    cout << result[i] << " ";
  }
  
  cout << endl;
}
