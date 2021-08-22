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

string succ_alien(string num, string alphabets){
    int base = alphabets.size();
    auto bidirectionalMaps = getBidirectionalMaps(alphabets);
    auto alphabetToDigitMap = bidirectionalMaps.first;
    auto digitToAlphabetMap = bidirectionalMaps.second;
    string numericNum = "";
    for(int i = 0 ; i < num.size(); i++){
        numericNum += alphabetToDigitMap[num[i]];
    }
    string numericAns = "";
    int carry = 1;
    int i = numericNum.size()-1;
    while(i > -1){
        int digit = numericNum[i] - '0' + carry;
        int unitDigit = digit % base;
        numericAns = string(1, unitDigit + '0') + numericAns;
        carry = digit / base;
        i--;
    }
    if(carry) numericAns = string(1, carry + '0') + numericAns;
    string ans = "";
    for(int i = 0 ; i < numericAns.size(); i++){
        ans += digitToAlphabetMap[numericAns[i]];
    }
    cout<<num<<" -> "<<numericNum<<" -> "<<numericAns<<" -> "<<ans<<endl;
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