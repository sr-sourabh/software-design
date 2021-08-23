#include <bits/stdc++.h>
using namespace std;

/*
Returns a char representation for an int n.
Useful in situations when the base is more than 10.
Eg: n = 12 returns C
*/
char getCharDigitFromInteger(int n){
    if(n < 10) return n + '0';
    else return 'A' + n - 10;
}

/*
Returns a int representation for char n.
Useful in situations when the base is more than 10.
Eg: n = C returns 12
*/
int getIntegerDigitFromChar(char n){
    if(n <= '9') return n - '0';
    else return n - 'A' + 10;
}

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
        char digit = getCharDigitFromInteger(i);
        alphabetToDigitMap[alphabets[i]] = digit;
        digitToAlphabetMap[digit] = alphabets[i];
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
        int digit = getIntegerDigitFromChar(num[i]) + carry;
        int unitDigit = digit % base;
        ans = string(1, getCharDigitFromInteger(unitDigit)) + ans;
        carry = digit / base;
        i--;
    }
    if(carry) ans = string(1, getCharDigitFromInteger(carry)) + ans;
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
    // {alphabets of alien representation, strings numbers to be tested in alient representation}
    vector<pair<string, vector<string>>> testCases = {
        {"!@^&*", {"!@^&*", "****", "!!!!", "!", "@", "^", "&", "*", "@*"}},
        {"0123456789", {"123", "345", "99", "19"}},
        {"0123456789ABCDEF", {"8AB", "F", "FFF", "8FF", "88"}}
    };
    for(auto &e : testCases){
        string alphabets = e.first;
        cout<<"For alphabets = "<<alphabets<<endl;
        for(auto &ee : e.second){
            succ_alien(ee, alphabets);
        }
        cout<<endl;
    }
}