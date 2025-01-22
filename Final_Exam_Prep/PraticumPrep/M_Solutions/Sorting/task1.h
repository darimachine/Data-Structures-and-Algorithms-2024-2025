#pragma once
//ttps://www.hackerrank.com/contests/test-1697304732/challenges/1-6-6/submissions/code/1387419148

#include <unordered_map>
#include<string>
#include<iostream>
using namespace std;


int main() {
 
    std::string s;
    std::cin >> s;
    std::unordered_map<char, int>myMap;
    for (char c : s)
    {
        myMap[c]++;
    }

    int currInd = 0;
    for (char c : s)
    {
        if (myMap[c] == 1)
            std::cout << currInd << ' ';

        currInd++;
    }
}