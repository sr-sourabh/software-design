#include <bits/stdc++.h>
using namespace std;

string succ_alien(string num, string alphabets){
    int base = alphabets.size();
    unordered_map<char, char> alphabetToDigitMap, digitToAlphabetMap;
    for(int i = 0 ; i < alphabets.size(); i++){
        alphabetToDigitMap[alphabets[i]] = i + '0';
        digitToAlphabetMap[i+'0'] = alphabets[i];
    }
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