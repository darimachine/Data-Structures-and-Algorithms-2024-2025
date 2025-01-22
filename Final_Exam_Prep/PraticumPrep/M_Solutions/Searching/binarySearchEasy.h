#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void binarySearch(std::vector<int>& arr, int numToSearch, int low, int high, std::vector<std::pair<int, int>>& toPrint)
{
    int numIterations = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        numIterations++;
        if (arr[mid] == numToSearch)
        {
            toPrint.push_back({ mid,numIterations });
            return;
        }
        else if (arr[mid] < numToSearch) //search right
        {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    toPrint.push_back({ -1, numIterations });
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int numElements;
    std::cin >> numElements;
    std::vector<int>arr(numElements);
    for (int i = 0; i < numElements; i++)
        std::cin >> arr[i];


    int q;
    std::cin >> q;
    int numToSearch;
    std::vector<std::pair<int, int>>toPrint;
    for (int i = 0; i < q; i++)
    {
        std::cin >> numToSearch;
        binarySearch(arr, numToSearch, 0, numElements - 1, toPrint);
    }
    for (const std::pair<int, int>& currPair : toPrint)
    {
        std::cout << currPair.first << ' ';
    }
    std::cout << '\n';
    for (const std::pair<int, int>& currPair : toPrint)
    {
        std::cout << currPair.second << ' ';
    }
}
