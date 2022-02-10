/**
  * This question is asked by Amazon. Given a string representing your stones and another string representing a list of jewels, return the number of stones that you have that are also jewels.
  *
  * Ex: Given the following jewels and stones...
  *
  * jewels = "abc", stones = "ac", return 2
  * jewels = "Af", stones = "AaaddfFf", return 3
  * jewels = "AYOPD", stones = "ayopd", return 0
  */
// Question: https://leetcode.com/problems/jewels-and-stones/
// Solution:
#include <iostream>
#include<unordered_map>

using namespace std;

int numJewelsInStones(string jewels, string stones) {
     unordered_map<char,int> jewel_info;

    int jewel_len = jewels.length();
    for(int i = 0; i < jewel_len; i++)
        jewel_info[jewels[i]]++;

    int stones_len = stones.length(), count=0; 
    for(int i = 0; i < stones_len; i++)
        if(jewel_info.find(stones[i]) != jewel_info.end())
            count++;

    return count;
}


int main() {
  string jewels, stones;
  cin >> jewels >> stones;

  cout << numJewelsInStones(jewels,stones);
  cout << endl;
}
