#include <bits/stdc++.h>
using namespace std;

/*
Given alphabets of a number system this function returns both way maps.
i.e alphabet to digit and digit to alphabet maps
Digits start with 0,1,2 etc for corresponding alphabet positions in alpbhabet string
Params : alphabets of a number system as string
Return : pair of {alphabetToDigitMap, digitToAlphabetMap}
*/
pair<unordered_map<char, char>, unordered_map<char, char>> getBidirectionalMaps(string alphabets){
    unordered_map<char, char> alphabetToDigitMap, digitToAlphabetMap;
    for(int i = 0 ; i < alphabets.size(); i++){
        alphabetToDigitMap[alphabets[i]] = i + '0';
        digitToAlphabetMap[i+'0'] = alphabets[i];
    }
    return {alphabetToDigitMap, digitToAlphabetMap};
}

/*
Converts a num from one form to another using the given map
Params: 1. a string num to be converted
        2. map used for convertion
Return: converted num as a string 
*/
string convertNumUsingMap(string num, unordered_map<char, char> map){
    string convertedNum = "";
    for(int i = 0 ; i < num.size(); i++){
        convertedNum += map[num[i]];
    }
    return convertedNum;
}

string incrementNum(string num, int base){
    string ans = "";
    int carry = 1;
    int i = num.size()-1;
    while(i > -1){
        int digit = num[i] - '0' + carry;
        int unitDigit = digit % base;
        ans = string(1, unitDigit + '0') + ans;
        carry = digit / base;
        i--;
    }
    if(carry) ans = string(1, carry + '0') + ans;
    return ans;
}

void displayResult(string num, string numericNum, string numericAns, string ans){
    cout<<num<<" -> "<<numericNum<<" -> "<<numericAns<<" -> "<<ans<<endl;
}

string succ_alien(string num, string alphabets){
    int base = alphabets.size();
    auto bidirectionalMaps = getBidirectionalMaps(alphabets);
    auto alphabetToDigitMap = bidirectionalMaps.first;
    auto digitToAlphabetMap = bidirectionalMaps.second;
    string numericNum = convertNumUsingMap(num, alphabetToDigitMap);
    string numericAns = incrementNum(numericNum, base);
    string ans = convertNumUsingMap(numericAns, digitToAlphabetMap);
    displayResult(num, numericNum, numericAns, ans);
    return ans;
}

int main() {
    string alphabets = "!@^&*";
    vector<string> testCases = {"!@^&*", "!@^*!", "!@^*@", "!@^*^", "!@^*&",
    "!@^**", "*********", "!!!!", "!", "@", "^", "&", "*", "@*"};
    for(auto &e : testCases){
        succ_alien(e, alphabets);
    }
}