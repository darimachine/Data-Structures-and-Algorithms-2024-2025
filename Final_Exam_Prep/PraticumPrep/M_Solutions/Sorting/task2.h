#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_set>
using namespace std;


int main() {
    long long n;
    std::cin >> n;
    std::unordered_set<long long>mySet;

    long long currNum;
    for (long long i = 0; i < n; i++)
    {
        std::cin >> currNum;
        mySet.insert(currNum);
    }
    long long m;
    std::cin >> m;
    long long sumToReturn = 0;
    for (long long i = 0; i < m; i++)
    {
        std::cin >> currNum;
        if (mySet.count(currNum))
        {
            sumToReturn += currNum;
            mySet.erase(currNum);   //!!!! ������ ������������ �� �� erase-��, ������ �� ��-����� ���� ���� ��� �� 
                                   //�� ����� ���� ����� ��� ������ ����� � �� ����, �� �� ��� � ������ � �� �� �� 
                                  //������, � ������ �� �� ������ ���� ������
        }
    }
    std::cout << sumToReturn;
}
