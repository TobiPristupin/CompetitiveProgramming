#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

long long string_to_binary_mod(string bin, long long mod){
    long long sum = 0;
    reverse(bin.begin(), bin.end());
    for(int i = 0; i < bin.length(); i++){
        sum += fmod((stoll(bin.substr(i, 1)) * pow(2, i)), mod);
    }

    return sum;
}

int main(){
    unordered_map<string, string> conversion = {
        {">", "1000"},
        {"<", "1001"},
        {"+", "1010"},
        {"-", "1011"},
        {".", "1100"},
        {",", "1101"},
        {"[", "1110"},
        {"]", "1111"},
    };
    
    string program;
    cin >> program;
    string bin;
    for (int i = 0; i < program.length(); i++){
        bin += conversion[program.substr(i, 1)];       
    }

    cout << string_to_binary_mod(bin, 1000003LL) % 1000003LL << endl;
}